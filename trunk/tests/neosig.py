#from Qt import signal, slot
from Qt.Core import QObject, QTimer
from Qt.Gui import QApplication 

class MyTimer(QTimer):
    #@signal('')
    def mySignal(self): pass
    #newSignal = signal('')(newSignal)

class MyObject(QObject):   
    def mySlot1(self):
        print 'mySlot1:', timer
        app.quit()
        
    def mySlot2(self, obj):
        print 'mySlot2:', obj

##########################################################

app = QApplication()

timer = MyTimer(None)
a = MyObject(None)

timer.connect('timeout()', a.mySlot1)
#timer.connect('timeout()', a.mySlot1)
timer.connect('destroyed(QObject*)', a.mySlot2)

print 'a', a.__signals__()
print 'timer', timer.__signals__()

timer.start(2000)

app.run()

