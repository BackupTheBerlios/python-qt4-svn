from Qt.Gui import QApplication
from Qt.Core import QObject

def on_destroy(self=None):
    print 'on_destroy:', self

def f():     
    a = QObject(None)
    print 'a:',a
    a.connect('destroyed(QObject*)', on_destroy)
    del a


app = QApplication('del')
print 'before'
f()
print 'after'

