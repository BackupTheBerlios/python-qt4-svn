# -*- encoding: utf-8 -*-
from Qt.Core import to_str

s1 = 'Eric Jardim'
s2 = '日本語のpython-qt4'
s3 = '\0日本語の\0python-qt4\0'

assert(to_str(s1) == s1)
assert(to_str(s2) == s2)
try:
    to_str(s2.decode("utf-8"))
    assert(False)
except: # Should check for Boost.Python.ArgumentError
    pass
assert(to_str(s3) == s3)

