# parental test

from Qt import QObject

a = QObject(None)
b = QObject(a)

print 'a:', a
print 'b:', b
print 'a.parent():', a.parent()
print 'b.parent():', b.parent()

assert a == a
assert b == b
assert not (a == b)
assert not (b == a)
assert a.parent() == None
assert b.parent() == a
assert a == b.parent()
assert b.parent() == b.parent()

