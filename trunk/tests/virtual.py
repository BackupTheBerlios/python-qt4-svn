from Qt.Core import QObject, QEvent, factory
from Qt.Gui import QApplication, QWidget

class MyObject(QObject):
    def event(self, e):
        print 'event()', self, e
        return QObject.event(self, e)

    def connectNotify(self, signal):
        print 'connectNotify()', self, signal
        QObject.protected_connectNotify(self, signal)

    def func(self):
        print 'func'
        
    #def childEvent(self, e):
    #    print 'childEvent', e
    #    return QObject.__protected__childEvent(self, e)
    
class MyWidget(QWidget):
    def event(self, e):
        print 'event', e
        return QObject.event(self, e)

    def connectNotify(self, signal):
        print self, signal
        QObject.protected_connectNotify(self, signal)

    def func(self):
        print 'func'

app = QApplication('')
e = QEvent(QEvent.Type.Show)
#a = factory(None)
b = QObject(None)
c = MyObject(None)
d = MyObject(c)

#b = QWidget(None)
#c = MyWidget(None)
#d = MyWidget(c)

c.connect('destroyed()', d.func)

#print dir(a)
#print dir(b)
print dir(c)

#a.event(e)
#b.event(e)
#c.event(e)

#c.__childEvent(e)