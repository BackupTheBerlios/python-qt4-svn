from Qt.Core import QObject
from Qt.Gui import QApplication, QLineEdit

def slot(*args):
    print args

app = QApplication()

a = QLineEdit(None)
b = QLineEdit(None)
c = QLineEdit(None)
d = QLineEdit(None)
e = QLineEdit(None)
f = QLineEdit(None)

a.connect('bogus', slot)
a.connect('destroyed(()', slot)
b.connect('destroyed', slot)
c.connect('destroyed()', slot)
d.connect('destroyed(QObject)', slot)
e.connect('destroyed(bogus)', slot)
e.connect('cursorPositionChanged(int,int)', slot)
f.connect('destroyed(object)', slot)

print a,b,c,d,e
#app.run()
