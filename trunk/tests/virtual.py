from Qt.Core import QObject, QEvent, factory
from Qt.Gui import QApplication, QWidget

class MyObject(QObject):
    def event(self, e):
        print 'event()', self, e
        return QObject.event(self, e)
    
    def eventFilter(self, watched, event):
         print 'eventFilter()', watched, event
         return QObject.eventFilter(self, watched, event)
    
    def connectNotify(self, signal):
        print 'connectNotify()', self, signal
        QObject.connectNotify(self, signal)

    def func(self):
        print 'func'
        
    def childEvent(self, e):
        print 'childEvent', e
        #return QObject.__protected__childEvent(self, e)
        return QObject.childEvent(self, e)
    
class MyWidget(QWidget):
    def eventFilter(self, watched, event):
         print 'eventFilter()', watched, event
         return QWidget.eventFilter(self, watched, event)

    def connectNotify(self, signal):
        print 'connectNotify()', self, signal
        QWidget.connectNotify(self, signal)

    def childEvent(self, e):
        print 'childEvent()', e
        #return QObject.__protected__childEvent(self, e)
        return QWidget.childEvent(self, e)
    
    def func(self):
        print 'func'

        
app = QApplication('')
e = QEvent(QEvent.Type.Show)
#a = factory(None)
b = QObject(None)
c = MyObject(None)
d = MyObject(None)

#b = QWidget(None)
#c = MyWidget(None)
#d = MyWidget(None)

c.installEventFilter(d)
d.setParent(c)
c.connect('destroyed()', d.func)

#print dir(a)
#print dir(b)
#print dir(c)

#a.event(e)
#b.event(e)
#c.event(e)

#c.__childEvent(e)