from Qt import QApplication, QPushButton

class MyButton(QPushButton):
    def __init__(self,  text=None, parent=None):
       QPushButton.__init__(self, text, parent)
       self.objectName = 'button'
       self.connect("2clicked()", self.on_button_clicked)
       #print self.on_button_clicked, type(self.on_button_clicked)

    def event(self, event):
        print event
        
    def eventFilter(self, obj, event):
        print obj, event
       
    def on_button_clicked(self):
        print 'Hello, World!'