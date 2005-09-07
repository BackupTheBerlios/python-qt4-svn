#ifndef QPYTHON_H
#define QPYTHON_H

#include <boost/python.hpp>

#include <QWidget>

class QPython
{
public:
    static void init();    
    static void finalize();
    static void test(QWidget* parent);
    
protected:
    QPython(){};

private:
    static bool _started;
    static bool _stopped;    
};

#endif
