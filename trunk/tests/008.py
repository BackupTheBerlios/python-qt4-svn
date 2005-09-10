from Qt.Gui import QApplication, QWidget, QPushButton

class MyWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(200, 120)
        quit = QPushButton('Quit', self)
        quit.setGeometry(62, 40, 75, 30);
        quit.connect('clicked(bool)', self.on_clicked)

    def on_clicked(self, checked):
        print 'clicked:', checked

app = QApplication()
widget = MyWidget()
widget.show()
app.run()