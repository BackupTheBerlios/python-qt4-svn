#import Qt
from Qt.Core import QObject

def test1():
    a = QObject(None)
    b = QObject(None)
    return a
print '--- test1 --------------------------------------------------------------'
z = test1()
print z, z.children()
del z
print '------------------------------------------------------------------------'

def test2():
    a = QObject(None)
    b = QObject(a)
    return a
print '--- test2 --------------------------------------------------------------'
z = test2()
print z, z.children()
del z
print '------------------------------------------------------------------------'




def test3():
    a = QObject(None)
    b = QObject(a)
    del b
    del a
print '--- test3 --------------------------------------------------------------'
test3()
print '------------------------------------------------------------------------'

def test4():
    a = QObject(None)
    b = QObject(None)
    b.setParent(a)
    del b
    del a

print '--- test4 --------------------------------------------------------------'
test4()
print '------------------------------------------------------------------------'




def test5():
    a = QObject()
    b = QObject(a)
    del a
    del b
print '--- test5 --------------------------------------------------------------'
test5()
print '------------------------------------------------------------------------'

def test6():
    a = QObject()
    b = QObject()
    b.setParent(a)
    del a
    del b
print '--- test6 --------------------------------------------------------------'
test6()
print '------------------------------------------------------------------------'




def test7():
    a = QObject()
    b = QObject(a)
    b.setParent(None)
    del a
    del b
print '--- test7 --------------------------------------------------------------'
test7()
print '------------------------------------------------------------------------'

def test8():
    a = QObject()
    b = QObject()
    b.setParent(a)
    b.setParent(None)
    del a
    del b

print '--- test8 --------------------------------------------------------------'
test8()
print '------------------------------------------------------------------------'



def test9():
    a = QObject()
    b = QObject(a)
    b.setParent(None)
    del b
    del a
print '--- test9 --------------------------------------------------------------'
test9()
print '------------------------------------------------------------------------'

def test10():
    a = QObject()
    b = QObject()
    b.setParent(a)
    b.setParent(None)
    del b
    del a

print '--- test10 -------------------------------------------------------------'
test10()
print '------------------------------------------------------------------------'