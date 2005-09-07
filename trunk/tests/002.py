# -*- encoding:utf-8 -*-
from Qt.Core import to_stdout

s1 = 'Eric Jardim'
s2 = u'日本語のpython-qt4'
s3 = '日本語のpython-qt4'
s4 = "\0fr\0ed\0"
s5 = u"\0日本\0語の\0"

print 'to_stdout:'
to_stdout(s1)
to_stdout(s2)
try:
    to_stdout(s3)
except UnicodeDecodeError:
    pass
to_stdout(s3.decode("utf-8"))
to_stdout(s4) # expected to print blank
to_stdout(s5) # expected to print blank

