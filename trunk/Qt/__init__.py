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

__qt_connections__ = {}

def __link_parent__(obj):
    parent = obj.parent()
    print '(%s -> %s)'%(obj, parent)
    if parent is not None:
        if not hasattr(parent, '__children__'):
            parent.__children__ = []
        children = parent.__children__
        children.append(obj)

def __init__(self, *args, **kw):
    self.__default_init__(*args, **kw)
    self.__qt_slots__ = []
    self.__python_native__ = True
    if isinstance(self, Core.QCoreApplication):
        Core.__app__ = self
    #print '__init__:', self, self.parent()
    #__link_parent__(self)

    
def __setLayout__(self, layout):
    # remove the previous layout
    oldLayout = self.layout()
    if oldLayout is not None:
        self.__dispose__(oldLayout)
    del oldLayout    
    
    # call the default setLayout method
    print '__default_setLayout__'
    self.__default_setLayout__(layout)
    #layout.setParent(self)
    
    # reparent all the child    
    for i in range(0, layout.count()):
        widget = layout.itemAt(i).widget()
        if widget is not None:
            print '(%s -> %s)'%(widget, self)
            widget.setParent(self)
Gui.QWidget.__default_setLayout__ = Gui.QWidget.setLayout;
Gui.QWidget.setLayout = __setLayout__;
    

def __del__(self):
    print 'del(%s):'%self.className(), self.objectName, self
    
    if self.inherits("QWidget"): #isinstance(self, Gui.QWidget): 
        try:
            layout = self.layout()
            if layout is not None:
                print '   managing layout'                            
                for i in range(0, layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget is not None:
                        self.__release_reference__(widget)
                        layout.removeWidget(widget)
                self.__release_reference__(layout)
                #self.__dispose__(layout)
            del layout     
        except:
            pass
    
    children = self.children();
    for child in children:        
        print '   releasing:(%s)'%child.className() , child
        self.__release_reference__(child)
        #if hasattr(child, '__python_native__'):
        #child.setParent(None)
        
        
    #if hasattr(self, '__children__'):
    #    print '__del__(*):', self
    #    for child in self.__children__():
    #        child.setParent(None)
        #while len(self.__children__) > 0:
            #print 'del %s' % (self.__children__[0])
            #del self.__children__[0]
        #del self.__children__
    #else:
    #    print '__del__:', self
  
    #if hasattr(self, '__qt_slots__'):
    #    del self.__qt_slots__
    
    
def __replace_constructor__(klass):
    klass.__default_init__ = klass.__init__
    klass.__init__ = __init__

    
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

    
def __addDynamicMethod(signal, reciever, callback):
    signature = (signal.split('(')[1])[:-1]
    #print '|',signature, '|'
    if signature == '':
        params = []
    else:
        params = list(signature.split(','))

    slot = callback.__name__+'('+signature+')'
    Core.__addDynamicMethod__(reciever,
                              slot,
                              callback.__name__,
                              params ,
                              callback)
    #print '__addDynamicMethod:', reciever, slot, callback.__name__, params, callback
    return slot
    
def __connect__(self, signal, callback):
    if callable(callback):
        if isinstance(callback, types.MethodType) and \
           isinstance(callback.im_self, Core.QObject) and \
           hasattr(callback.im_self, '__python_native__'):
            reciever = callback.im_self
            #print 'reciever:', reciever, callback
            slot = __addDynamicMethod(signal, reciever, callback)
            Core.__connectSlot__(self, signal, reciever, slot)
        else:
            raise AttributeError, 'for a while, callback must be method of a native QObject'
    else:
        raise AttributeError, 'The callback must be a callable (function, method, lambda, etc.)'

_addDynamicMethod = __addDynamicMethod
    
def __connect2__(self, signal, callback):
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
    klass.__del__ = __del__


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
    
print 'done'
