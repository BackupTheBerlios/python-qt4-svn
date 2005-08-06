# try to leak memory
from Qt import QObject

print 'Test #1: parentless QObjects'
for i in range(1000):
    print '1'
    a = QObject()

a = QObject()
print 'Test #2: parneted QObjects'
for i in range(1000):
    print '2'
    b = QObject(a)

l = []
for i in range(1000):
    l += [QObject()]

print l


