from Qt import QPushButton

class MainForm(QPushButton):
    def __init__(self, parent=None):
        QPushButton.__init__(self, parent)
        #print Qt.connect(self, '2clicked()', Qt.App, '1quit()')
        
    def on_MainForm__clicked(self):
        print 'clicked'
