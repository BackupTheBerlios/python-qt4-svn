from Qt.Gui import QApplication, QFont, QWidget, QPushButton

class MyWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(200, 120)
        quit = QPushButton('Quit', self)
        quit.setGeometry(62, 40, 75, 30);
        quit.setFont(QFont('Times', 18, QFont.Bold))
        quit.connect('clicked()', QApplication.instance().quit)

app = QApplication()
widget = MyWidget()
widget.show()
app.run()
