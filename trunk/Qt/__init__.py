# python-qt4 setup

print 'starting python-qt4...'

from Namespace import *
import Core
import Gui
#from Core import *
#from Gui import *

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
    print '__newinit__:', self, self.parent()
    __link_parent__(self)

def __newdel__(self):
    #print '__del__:', self
    if hasattr(self, '__children__'):
        del self.__children__
    
    
def __replace_constructor__(klass):
    klass.__oldinit__ = klass.__init__
    klass.__init__ = __newinit__

def search_qobjects(module):
    klasses = []
    for name in dir(module):
        attr = getattr(module, name)
        if name.startswith('Q'):
            if issubclass(attr, Core.QObject):
                __klasses__.append(attr)
    return klasses
                
__klasses__ = []
#__klasses__ = [Core.QObject]
__klasses__ += search_qobjects(Core)
__klasses__ += search_qobjects(Gui)

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