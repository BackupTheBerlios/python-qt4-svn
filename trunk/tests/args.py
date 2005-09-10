from sys import argv
from Qt.Gui import QApplication, QPushButton

app = QApplication(argv)
print dir(app)
button = QPushButton('Quit')
button.show()
#button.connect('clicked()', app.quit)
app.run()

