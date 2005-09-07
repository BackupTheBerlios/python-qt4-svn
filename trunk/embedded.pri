LIBS += -lutil \ 
       -L$$PYTHONDIR/lib \
       -lpython$$PYTHONVER \
       -L$$BOOSTDIR/lib \
       -lboost_python$${BOOSTTOOLSET}$${BOOSTTHREADING}$${BOOSTRUNTIME}$${BOOSTVER}
       
INCLUDEPATH += $$BOOSTDIR/include/boost$$BOOSTVER \
               $$PYTHONDIR/include/python$$PYTHONVER

