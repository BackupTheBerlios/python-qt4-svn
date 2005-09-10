# parent test

from Qt.Core import QObject
from Qt.Gui import QApplication, QPushButton

app = QApplication()
button = QPushButton('Push me', None)
a = QObject(button)
a.objectName = 'a'
button.objectName = 'button'

print button, a, a.parent()
print type(button), type(a), type(a.parent())
print button == a.parent()
for obj in [a, button, a.parent()]:
    print obj.objectName, obj
