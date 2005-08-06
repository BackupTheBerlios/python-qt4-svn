# Arquivo gerado pelo gerenciador qmake do kdevelop. 
# ------------------------------------------- 
# O subdir relativo ao diretório principal do projeto: .
# O alvo é uma biblioteca: Qt

include ( path.pri )

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
           QFlags.cpp 
TEMPLATE = lib
TARGET = Qt
CONFIG += qt designer debug warn_off plugin
INCLUDEPATH += $$BOOSTDIR/include $$PYTHONDIR/include/python$$PYTHONVER
LIBS += -L$$BOOSTDIR/lib -lboost_python
