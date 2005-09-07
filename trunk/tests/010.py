# -*- encoding:utf-8 -*-
from Qt.Core import to_latin1_str

s1 = u'Eric Jardim'
s2 = 'Eric Jardim'
s3 = u'日本語のpython-qt4'
s4 = u'\0Eric\0 Jardim\0'
s5 = u'\0日本\0語の\0python-qt4\0'

assert(to_latin1_str(s1) == s1.encode("latin-1"))
assert(to_latin1_str(s2) == s1)
assert(to_latin1_str(s3) == "????python-qt4")
assert(to_latin1_str(s4) == s4.encode("latin-1"))
assert(to_latin1_str(s5) == "\0??\0??\0python-qt4\0")

