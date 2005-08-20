LIBS += -L$$BOOSTDIR/lib -lboost_python 
INCLUDEPATH += $$BOOSTDIR/include $$PYTHONDIR/include/python$$PYTHONVER
DESTDIR = ../Qt
unix {
    QMAKE_POST_LINK = ln -sf $$DESTDIR/$(TARGET) $$DESTDIR/$(QMAKE_TARGET).so
}
TEMPLATE = lib
CONFIG += debug warn_off qt plugin
