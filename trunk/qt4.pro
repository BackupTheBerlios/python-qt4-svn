# Arquivo gerado pelo gerenciador qmake do kdevelop. 
# ------------------------------------------- 
# O subdir relativo ao diretório principal do projeto: .
# O alvo é uma biblioteca: Qt

HEADERS += PythonConnection.h 
SOURCES += Qt.cpp \
           QObject.cpp \
           QApplication.cpp \
           QPushButton.cpp \
           QWidget.cpp \
           QString.cpp \
           QLineEdit.cpp \
           QListView.cpp \
           QLayout.cpp \
           PythonConnection.cpp \
           QEvent.cpp \
           QPaintDevice.cpp \
           QFlags.cpp \
           QCoreApplication.cpp 
include ( path.pri )
LIBS += -L$$BOOSTDIR/lib \
-lboost_python
INCLUDEPATH += $$BOOSTDIR/include \
$$PYTHONDIR/include/python$$PYTHONVER
TARGET = Qt
CONFIG += debug \
warn_off \
qt \
plugin \
designer
TEMPLATE = lib
