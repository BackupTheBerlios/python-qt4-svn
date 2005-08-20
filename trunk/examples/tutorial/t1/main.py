from Qt.Gui import QApplication, QPushButton
from sys import argv

app = QApplication('t1')
hello = QPushButton("Hello world!", None)
hello.resize(100, 30)
hello.show()
app.run()

