from Qt import QEvent, QObject, QWidget, QApplication, QPushButton


class MyObject(QObject):
    def __init__(self, parent=None):
        QObject.__init__(self, parent)
    
    def event(self, e):
        print e, e.type()
        return QObject.event(self, e)

class MyWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
    
    def event(self, e):
        print e, e.type()
        return QWidget.event(self, e)

        
class MyButton(QPushButton):
    def __init__(self, text, parent=None):
        QPushButton.__init__(self, text, parent)
    
    def event(self, e):
        print e, e.type()
        return QPushButton.event(self, e)

                    
app = QApplication()
#button = QPushButton('Click me', None)
button = QWidget(None)
#button = MyButton('Click me', None)

#a = MyObject(None)
#b = MyObject(a)
# print a
# print b
# print b.parent()
# print a is b.parent()
#app.notify(b, QEvent(QEvent.Type.KeyPress))

button.show() 
app.run()
