from Qt.Core import QObject, factory
from Qt.Gui import QApplication

def classtype(obj):
    if hasattr(obj, '__python_native__'):
        print str(obj), 'is a python native object'
    else:    
        print str(obj), 'is a cpp native object'


app = QApplication()

# python 'native' object
a = QObject(None)

# c++ 'native' object
b = factory(None)

classtype(a)
classtype(b)

