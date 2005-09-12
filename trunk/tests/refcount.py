# try to leak memory
from Qt.Core import QObject, factory

def create1():
    a = QObject()
    b = QObject(a)
    c = QObject(a)
    d = QObject(b)
    print 'a.children:', a.children()
    return a

def create2():
    a = factory(None)
    b = factory(a)
    c = factory(b)
    print 'a.children:', a.children()
    return a

def test1():
    a = create1()
    print 'a.children:', a.children()

def test2():
    a = create2()
    print 'a.children:', a.children()

print '--------------- Test 1 --------------------'
test1()
print '--------------- Test 2 --------------------'
test2()
print '-------------------------------------------'

