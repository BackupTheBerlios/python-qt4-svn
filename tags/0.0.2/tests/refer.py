# reference

import Qt
from Qt.Core import QCoreApplication, QObject
from Qt.Gui import QApplication, QWidget

#app = QCoreApplication('refer')
app = QApplication('refer')

#Klass = QObject
Klass = QWidget

def create():
    a = Klass()
    a.name = 'a'
    print 'a:', a

    print
    b = Klass(a)
    b.name = 'b'
    print 'b:', b
    
    print
    c = Klass(b)
    c.name = 'c'
    print 'c:', c

    print
    print a, b, c
    print 'in create:', a.children(), b.children()
    return a, b

a, b = create()
#w = QWidget()
#w.show()
print
print 'pos create:', a.children(), b.children()

#app.run()
#del app
