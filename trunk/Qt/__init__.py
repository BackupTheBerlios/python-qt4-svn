# python-qt4 setup

print 'starting python-qt4...'

import Qt
from Qt import *

def __link_parent__(obj):
    parent = obj.parent()
    if parent is not None:
        if not hasattr(parent, '__children__'):
            parent.__children__ = []
        children = parent.__children__
        children.append(obj)

def __newinit__(self, *args, **kw):
    self.__oldinit__(*args, **kw)
    __link_parent__(self)

def __newdel__(self):
    #print '__del__:', self
    if hasattr(self, '__children__'):
        del self.__children__
    
    
def __replace_constructor__(klass):
    klass.__oldinit__ = klass.__init__
    klass.__init__ = __newinit__

__klasses__ = []
for name in dir(Qt):
    attr = getattr(Qt, name)
    if name.startswith('Q'):
        if issubclass(attr, QObject):
            __klasses__.append(attr)
    
#QObject.__del__ = __newdel__

#print __klasses__
for klass in __klasses__:
    __replace_constructor__(klass)
    #klass.__del__ = __newdel__


# Proxy class
# class Proxy(object):
#    def __init__(self, widget):
#        self.widget = widget
# 
#     def __getattr__(self, attr):
#         return(self.widget, attr)

    
print 'done\n'