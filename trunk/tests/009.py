# -*- encoding:utf-8 -*-
from Qt.Core import to_utf8_str

s1 = u'Eric Jardim'
s2 = 'Eric Jardim'
s3 = u'日本語のpython-qt4'
s4 = u'\0Eric\0 Jardim\0'
s5 = u'\0日本\0語の\0python-qt4\0'

assert(to_utf8_str(s1) == s1.encode("utf-8"))
assert(to_utf8_str(s2) == s2)
assert(to_utf8_str(s3) == s3.encode("utf-8"))
assert(to_utf8_str(s4) == s4.encode("utf-8"))
assert(to_utf8_str(s5) == s5.encode("utf-8"))

