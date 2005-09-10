from Qt import MouseButton
from Qt.Core import QObject
from Qt.Gui import QEvent, QWidget, QApplication, QPushButton

class MyObject(QObject):
    def __init__(self, parent=None):
        QObject.__init__(self, parent)
    
    def event(self, e):
        print e, e.type()
        return QObject.event(self, e)

        
class MyWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
    
    def mousePressEvent(self, e):
        print e, e.type()
        QWidget.mousePressEvent(self, e)
#        print e.buttons()
#        if e.buttons() == MouseButton.LeftButton | MouseButton.MidButton:
#            print 'LeftButton & MidButton'
    
#     def after_mousePressEvent(self, e):
#         print 'after'
#         print e, e.type()

#     def mouseReleaseEvent(self, e):
#         print e, e.type()
# 
#     def mouseDoubleClickEvent(self, e):
#         print e, e.type()
#     
#     def mouseMoveEvent(self, e):
#         print e, e.type(), e.x(), e.y()
        
app = QApplication()
widget = MyWidget(None)
print widget
widget.show()
app.run()
