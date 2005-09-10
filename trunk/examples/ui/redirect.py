from Qt.Gui import QApplication, QPushButton

class MyButton(QPushButton):
    def on_clicked(self):
        print 'on_clicked'

app = QApplication()

a = QPushButton('A', None)
b = MyButton('B', None)

a.connect('clicked()', b.clicked)
b.connect('clicked()', b.on_clicked)

a.show()
b.show()

app.run()

