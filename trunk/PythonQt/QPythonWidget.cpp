#include "QPython.h"
#include "QPythonWidget.h"
#include <boost/python.hpp>
#include <boost/python/object.hpp>

#include <QGridLayout>

namespace python = boost::python;

QPythonWidget::QPythonWidget(QWidget* parent, QString module, QString klass): 
    QWidget(parent), _self(0), _parent(0)
{     
    QLayout* layout = new QGridLayout(this);
    layout->setMargin(0);
    
    try {       
        createWidget(module, klass);
    }
    catch(python::error_already_set) {
        if (PyErr_Occurred()) PyErr_Print();
    }
}

void
QPythonWidget::createWidget(QString module, QString klass)
{
    // using namespace boost::python;
    python::object main_module((
        python::handle<> (python::borrowed(PyImport_AddModule("__main__")))));
    python::object main_namespace = main_module.attr("__dict__");    

    // import the desired class from its module    
    QString cmd = QString("from ")+module+
                  QString(" import ")+klass+
                  QString("\n__parent_QWidget__ = None\n");
    qDebug(">>> %s", cmd.toStdString().c_str());
                     
    // Define the derived class in Python.
    {
        python::handle<> ignored(PyRun_String(cmd.toStdString().c_str(), 
                            Py_file_input, 
                            main_namespace.ptr(), 
                            main_namespace.ptr() ));
    }   

    // set this object as the parent
    main_module.attr("__parent_QWidget__") = python::object(python::ptr((QWidget*)this));
    _parent = new python::object(main_module.attr("__parent_QWidget__"));     
    
    // create the new QWidget
    //cmd = klass+QString("(__parent_QWidget__)\n");
    cmd = klass+QString("(None)\n");
    qDebug(">>> %s", cmd.toStdString().c_str());
    python::object pyobj((
        python::handle<> ( PyRun_String(cmd.toStdString().c_str(), 
                   Py_eval_input,
                   main_namespace.ptr(), 
                   main_namespace.ptr() )) 
    ));        
    QWidget* widget = python::extract<QWidget*>(pyobj);
    layout()->addWidget(widget);
    
    // delete the reference to the parent
    {
        python::handle<> ignored(PyRun_String("print __parent_QWidget__\n"
                                              "del __parent_QWidget__\n"
                                              "print dir()\n",
                         Py_file_input,
                         main_namespace.ptr(),
                         main_namespace.ptr() ));
    }
                         
    _self = new python::object(pyobj);
}

QPythonWidget::~QPythonWidget()
{
    delete _self, _parent;
}
