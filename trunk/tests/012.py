# -*- encoding:utf-8 -*-
from Qt.Core import to_unicode

s1 = u'Eric Jardim'
s2 = 'Eric Jardim'
s3 = u'日本語のpython-qt4'
s4 = u'\0Eric\0 Jardim\0'
s5 = u'\0日本\0語の\0python-qt4\0'

assert(to_unicode(s1) == s1)
assert(to_unicode(s2) == unicode(s2))
assert(to_unicode(s3) == s3)
assert(to_unicode(s4) == s4)
assert(to_unicode(s5) == s5)

