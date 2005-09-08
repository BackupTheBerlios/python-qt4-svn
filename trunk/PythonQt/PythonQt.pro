# Arquivo gerado pelo gerenciador qmake do kdevelop. 
# ------------------------------------------- 
# O subdir relativo ao diretório principal do projeto: ./PythonQt
# O alvo é um aplicativo: embedded

HEADERS += QPython.h \
           PythonQObject.h \
           PyMoc.h \
           QPythonWidget.h \
           QPythonObject.h \
           PythonQtWrapper.h 
SOURCES += main.cpp \
           QPython.cpp \
           QPythonWidget.cpp 
TEMPLATE = app
TARGET = embedded
CONFIG += debug warn_off
include ( ../setup.pri )
include ( ../embedded.pri )
