# python-qt4 setup

print 'starting python-qt4...'

# workaround for cross-module inheritance
import sys
if  sys.platform.startswith('linux'):
    import dl
    __dlopenflags__ = sys.getdlopenflags()
    sys.setdlopenflags(dl.RTLD_NOW|dl.RTLD_GLOBAL)

# import modules
from Namespace import *
import Core
import Gui
#from Core import *
#from Gui import *

__qt_connections__ = {}

def __link_parent__(obj):
    parent = obj.parent()
    #print '__link_parent__:',obj, parent
    if parent is not None:
        if not hasattr(parent, 'children__'):
            parent.children__ = []
        children = parent.children__
        children.append(obj)

def __newinit__(self, *args, **kw):
    self.__oldinit__(*args, **kw)
    self.__qt_slots__ = []
    if isinstance(self, Core.QCoreApplication):
        Core.__app__ = self
    #print '__newinit__:', self, self.parent()
    __link_parent__(self)

def __newdel__(self):
    print '__del__:', self
    if hasattr(self, '__children__'):
        del self.__children__
    #if hasattr(self, '__qt_slots__'):
    #    del self.__qt_slots__
    
    
def __replace_constructor__(klass):
    klass.__oldinit__ = klass.__init__
    klass.__init__ = __newinit__

    
##############################################################################

import types

__alias__ = {
    'QObject': 'object',
    'QString': 'str',
    'QStringList': 'list',
    'double': 'float'
}


def __rmptr(arg):
    if arg.endswith('*'):
        return arg[:-1]
    else:
        return arg

    
def __candidates(sender, name):
    lst = []
    for item in sender.__signals__():
        if item.startswith(name):
            lst.append(item)
    return lst


def __is(a, b):
    while True:
        print '%s == %s' % (a, b)
        if a == b:
            print 'FOUND'
            return True
        else:
            if __alias__.has_key(a):
                a = __alias__[a]
                continue
            else:
                return False
        
def __match(lsig, rsig):
    lsig = lsig[1:-1]
    rsig = rsig[1:-1]
    largs = lsig.split(',')
    rargs = rsig.split(',')

    if not len(largs) == len(largs):
        return False
    n =len(largs)
    for i in range(n):
        #largs[i] = __rmptr(largs[i])
        #rargs[i] = __rmptr(rargs[i])
        if __is(__rmptr(largs[i]), __rmptr(rargs[i])):
            return True
    return False
    
    
        
def __parse_signal(sender, signal):
    parts = signal.split('(')
    name = parts[0]
    
    candidates = __candidates(sender, name)
    print candidates

    if len(candidates) == 0:
        raise TypeError, 'no signal named "%s"' % name
        
    if len(parts) == 1:
        # case 1 - auto find signature (get first)
        cand = candidates[0]
        right = cand.split('(')[1]
        sig = '('+right
        return name, sig
    
    elif len(parts) == 2 and (parts[1]).endswith(')'):
        # case 2 - match signature
        sig = '('+parts[1]
        for candidate in candidates:
            left, right = candidate.split('(')
            right = '('+right
            if __match(right, sig):
                return left, right
        raise TypeError, ('signal named "%s" did not match any signature' % name)
        
    else:
        raise TypeError, 'signal "%s" parse error' % signal

    
def __connect__(self, signal, callback):
    """
    The connect function is one of the central aspects of the Qt toolkit.
    Every QObject must connect its events (signals) to other objects
    callback (slots), in order to capture the behaviour of the sender.
    
    Syntax:
    Automatic signature (generally the biggest)
    >>> sender.connect("signal", reciever.method) 
    
    Specific signature
    >>> sender.connect("signal(int, str)", reciever.method)
    
    Connect to normal functions or static methods
    >>> sender.connect("signal", function) 
    """
    if __qt_connections__.has_key((self, signal, callback)):
        print 'Warning! %s: %s -> %s is already connected!' % (signal, self, callback)        
        return # do nothing

    if callable(callback):
        reciever = None
        if isinstance(callback, types.MethodType):
            reciever = callback.im_self       
            print 'reciever:', reciever
        try:
            signal = signal.replace(' ','')
            name, sig = __parse_signal(self, signal)
            pyslot = Core.__connect_method__(self, name, sig, callback)
            if pyslot is not None:
                # hold reference of the python slot
                __qt_connections__[(self, signal, callback)] = pyslot
                self.__qt_slots__.append(pyslot)
                #if reciever is not None:
                #    if isinstance(reciever, Core.QObject): 
                #        reciever.__qt_slots__.append(pyslot)
        except TypeError, e:
            print 'Warning:', e, '- connection failed'
    else:
        raise AttributeError, 'callback must be a function, method or lambda expression'
    
Core.QObject.connect = __connect__

###############################################################################


def search_qobjects(module):
    klasses = []
    for name in dir(module):
        attr = getattr(module, name)
        if name.startswith('Q'):
            if issubclass(attr, Core.QObject):
                __klasses__.append(attr)
    return klasses
                
__klasses__ = []
__klasses__ += search_qobjects(Core)
__klasses__ += search_qobjects(Gui)



#print __klasses__
for klass in __klasses__:
    __replace_constructor__(klass)
    klass.__del__ = __newdel__


# Proxy class
# class Proxy(object):
#    def __init__(self, widget):
#        self.widget = widget
# 
#     def __getattr__(self, attr):
#         return(self.widget, attr)


# workaround for cross-module inheritance
if  sys.platform.startswith('linux') or sys.platform.startswith('sunos'):    
    sys.setdlopenflags(__dlopenflags__)
    
print 'done\n'
