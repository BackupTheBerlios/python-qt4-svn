# simple push button

from Qt.Gui import QApplication, QPushButton

app = QApplication()
button = QPushButton('Push me', None)
button.show()
print (button.x, button.y)
app.run()

