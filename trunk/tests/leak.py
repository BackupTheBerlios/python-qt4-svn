# try to leak memory
from Qt import QObject, childrens, factory



print
print 'Test #1: parentless QObjects'
for i in range(3):
    a = QObject()
    a.objectName = 'a'+str(i)
    print 'creating a'+str(i), a

    
a = QObject()
a.objectName = 'a'
c = QObject(a)
#a.__children__ = []

print
print 'Test #2: parented QObjects'
print a, c
for i in range(3):
    b = QObject(a)
    #a.__children__.append(b)
    b.objectName = 'b'+str(i)
    print 'creating b'+str(i), b
    #c = factory(a)
    #print c
#del b
c.setParent(None)

print 'a:', a
#print a.__children__
#print a.children()
#print childrens(b)



#print
#l = []
#for i in range(5):
#    l += [QObject()]
#
#print l


