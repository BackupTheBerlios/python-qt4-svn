#ifndef QPYTHONOBJECT_H
#define QPYTHONOBJECT_H

#include <boost/python/object_fwd.hpp>
//#include <boost/python/extract.hpp>

#include <QObject>

namespace python = boost::python;

class QPythonObject
{    
public:
    //template<typename T> 
    
    static python::object create(QObject* parent, QString module, QString klass);
    //QObject* create(QObject* parent);
    
protected:
    QPythonObject(){};
};

//template<typename T>
//T*
python::object
QPythonObject::create(QObject* parent, QString module, QString klass)
{
    namespace python = boost::python;
    try 
    {
        // using namespace boost::python;
        python::object main_module((
            python::handle<> (python::borrowed(PyImport_AddModule("__main__")))));
        python::object main_namespace = main_module.attr("__dict__");    
    
        // import the desired class from its module    
        QString cmd = QString("from ")+module+
                    QString(" import ")+klass+
                    QString("\n__parent_QObject__ = None\n");
        qDebug(">>> %s", cmd.toStdString().c_str());
                        
        // Define the derived class in Python.
        {
            python::handle<> ignored(PyRun_String(cmd.toStdString().c_str(), 
                                Py_file_input, 
                                main_namespace.ptr(), 
                                main_namespace.ptr() ));
        }   
    
        // set this object as the parent
        main_module.attr("__parent_QObject__") = python::object( python::ptr(parent) );
        //_parent = new python::object(main_module.attr("__parent_QObject__"));     
        
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
        //QObject* obj = python::extract<QObject*>(pyobj);
        
        // delete the reference to the parent
        {
            python::handle<> ignored(PyRun_String(//"print obj\n"
                                                  "del __parent_QObject__\n"
                                                  "print dir()\n",
                            Py_file_input,
                            main_namespace.ptr(),
                            main_namespace.ptr() ));
        }
                           
        python::object self(pyobj);    
        return self;
        //qDebug("extract") ;
        //return python::extract<T*>(self);
    }
    catch(python::error_already_set) 
    {
        if (PyErr_Occurred()) PyErr_Print();
    }    
    return python::object();
}

#endif