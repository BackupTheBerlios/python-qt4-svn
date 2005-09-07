TARGET      = pythonwidgetplugin
CONFIG      += release designer plugin
TEMPLATE    = lib
#DESTDIR     = $(QTDIR)/plugins/designer
HEADERS     = QPython.h QPythonWidget.h customwidgetplugin.h
SOURCES     = QPython.cpp QPythonWidget.cpp customwidgetplugin.cpp

include ( ../../../setup.pri )
include ( embedded.pri )
              

