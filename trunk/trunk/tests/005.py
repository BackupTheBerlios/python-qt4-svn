# parent test

from Qt import QApplication, QPushButton, QObject
app = QApplication('app')
button = QPushButton('Push me', None)
a = QObject(button)
a.objectName = 'a'
button.objectName = 'button'

print button, a, a.parent()
print type(button), type(a), type(a.parent())
print button == a.parent()
for obj in [a, button, a.parent()]:
    print obj.objectName, obj
