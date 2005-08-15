# reference

from Qt import QCoreApplication, QApplication, QObject, QWidget

#app = QCoreApplication('refer')
app = QApplication('refer')

def create():
    a = QObject()
    print a

    print
    b = QObject(a)
    print b
    
    print
    c = QObject(b)
    print c

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