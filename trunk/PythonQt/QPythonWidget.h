#ifndef QPYTHONWIDGET_H
#define QPYTHONWIDGET_H

#include <boost/python/object_fwd.hpp>
//#include <boost/python/extract.hpp>

#include <QWidget>

class QPythonWidget: public QWidget
{
    Q_OBJECT
    
public:
    QPythonWidget(QWidget* parent, QString module, QString klass);
    virtual ~QPythonWidget();
    //template<typename T> inline T* getWidget();
    
protected:
    boost::python::object* _self;
    boost::python::object* _parent;
    
    void createWidget(QString module, QString klass);  
    
//private:

};

/*template<typename T>
T*
QPythonWidget::getWidget()
{
    return boost::python::extract<T*>(*_self);
}*/

#endif
