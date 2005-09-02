# Arquivo gerado pelo gerenciador qmake do kdevelop. 
# ------------------------------------------- 
# O subdir relativo ao diretório principal do projeto: ./Core
# O alvo é um aplicativo: Core

HEADERS += PythonConnection.h \
           PythonQObject.h \
           PythonQt.h 
SOURCES += Core.cpp \
           QObject.cpp \
           QString.cpp \
           Register.cpp \
           PythonConnection.cpp \
           QTimer.cpp \
           QCoreApplication.cpp \
           QTime.cpp \
           PythonQt.cpp 
TARGET = Core
include ( ../setup.pri )
include ( ../libs.pri )
