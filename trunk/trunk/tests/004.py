# simple push button

from Qt import QApplication, QPushButton

app = QApplication('sample app')
button = QPushButton('Push me', None)
button.show()
print (button.x, button.y)
app.run()

