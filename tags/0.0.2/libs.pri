LIBS += -L$$BOOSTDIR/lib \
        -lboost_python$${BOOSTTOOLSET}$${BOOSTTHREADING}$${BOOSTRUNTIME}$${BOOSTVER}
INCLUDEPATH += $$BOOSTDIR/include/boost$$BOOSTVER \
               $$PYTHONDIR/include/python$$PYTHONVER
DESTDIR = ../Qt
unix {
    QMAKE_POST_LINK = ln -sf $$DESTDIR/$(TARGET) $$DESTDIR/$(QMAKE_TARGET).so
}
TEMPLATE = lib
CONFIG += $$RUNTIME warn_off qt plugin
