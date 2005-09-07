from Qt.Core import QTimer
from Qt.Gui import QPushButton, QLineEdit, QLCDNumber

class MyButton(QPushButton):
    def __init__(self, parent=None):
        QPushButton.__init__(self, parent)
        self.text = 'MyButton'
        #for s in self.__signals__():
        #    print s

#     #@signal('')
#     def valueChanged(): pass
#     #valueChanged = signal('')(valueChanged)
#     
#     #@signal('int')
#     def valueChanged(newValue): pass
#     #valueChanged = signal('int')(valueChanged)

class MyEdit(QLineEdit):
    def __init__(self, parent=None):
        QLineEdit.__init__(self, parent)
        self.text = 'MyEdit'
        #for s in self.__signals__():
        #    print s
     
# class MyEdit(QLCDNumber):
#     def __init__(self, parent=None):        
#         QLCDNumber.__init__(self, parent)

class MyTimer(QTimer):
    pass
