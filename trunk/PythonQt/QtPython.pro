TEMPLATE = app
TARGET = embedded
CONFIG += debug warn_off
include ( ../setup.pri )
LIBS += -lutil \ 
       -L$$PYTHONDIR/lib \
       -lpython$$PYTHONVER \
       -L$$BOOSTDIR/lib \
       -lboost_python$${BOOSTTOOLSET}$${BOOSTTHREADING}$${BOOSTRUNTIME}$${BOOSTVER}
       
INCLUDEPATH += $$BOOSTDIR/include/boost$$BOOSTVER \
               $$PYTHONDIR/include/python$$PYTHONVER

HEADERS += QPython.h \
           QPythonWidget.h \
           QPythonObject.h
SOURCES += main.cpp \
           QPython.cpp \
           QPythonWidget.cpp  
           
