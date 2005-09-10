from Qt.Core import QObject, QEvent, factory
from Qt.Gui import QApplication, QWidget

app = QApplication()

a = QObject(None)
b = QObject(None)
c = QObject(None)

print a, b, c
print a.parent(), b.parent(), c.parent()

a.setParent(b)
b.setParent(c)
#c.setParent(a)

print a.parent(), b.parent(), c.parent()
