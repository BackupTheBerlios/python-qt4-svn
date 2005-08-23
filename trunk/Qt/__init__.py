# python-qt4 setup

print 'starting python-qt4...'

# workaround for cross-module inheritance
import sys, dl
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
        print 'is app'
        Core.__app__ = self
    #print '__newinit__:', self, self.parent()
    __link_parent__(self)

def __newdel__(self):
    print '__del__:', self
    #if hasattr(self, '__children__'):
    #    del self.__children__
    #if hasattr(self, '__qt_slots__'):
    #    del self.__qt_slots__
    
    
def __replace_constructor__(klass):
    klass.__oldinit__ = klass.__init__
    klass.__init__ = __newinit__

    
##############################################################################

import types

def _parse_signal(signal):
    name, sig = signal.split('(')
    sig = '('+sig
    return name, sig
    
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
    #if isinstance(callback, types.MethodType) or \
    #   isinstance(callback, types.FunctionType):        
        reciever = None
        if isinstance(callback, types.MethodType):
            reciever = callback.im_self       
            print 'reciever:', reciever
        #if not isinstance(reciever, Core.QObject): 
        #    raise AttributeError, 'reciever must be a QObject'
        name, sig = _parse_signal(signal)
        pyslot = Core.__connect_method__(self, name, sig, callback)
        if pyslot is not None:
            # hold reference of the python slot
            __qt_connections__[(self, signal, callback)] = pyslot
            self.__qt_slots__.append(pyslot)
            #if reciever is not None:
            #    if isinstance(reciever, Core.QObject): 
            #        reciever.__qt_slots__.append(pyslot)
    else:
        raise AttributeError, 'callback must be a function or method'
    
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
sys.setdlopenflags(__dlopenflags__)
print 'done\n'
