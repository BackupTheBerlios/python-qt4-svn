LIBS += -Xlinker -export-dynamic \ 
       -L$${PYTHONDIR}/lib/python$${PYTHONVER}/config \
       -lpython$${PYTHONVER} -ldl -lpthread -lutil -lm \
       -L$$BOOSTDIR/lib \
       -lboost_python$${BOOSTTOOLSET}$${BOOSTTHREADING}$${BOOSTRUNTIME}$${BOOSTVER} \ 
       $${PYTHONDIR}/lib/python$${PYTHONVER}/lib-dynload/dl.so

#QMAKE_LFLAGS_PLUGIN += -Xlinker -export-dynamic -ldl 
        
INCLUDEPATH += $$BOOSTDIR/include/boost$$BOOSTVER \
               $$PYTHONDIR/include/python$$PYTHONVER

