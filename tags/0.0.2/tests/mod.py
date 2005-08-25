from sys import argv, exit
from Qt.Gui import QApplication, QWidget

app = QApplication('')
w1 = QWidget(None)
w2 = QWidget(w1)
w1.show()
print dir(w1)
code = app.run()
exit(code)
