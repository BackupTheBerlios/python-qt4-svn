#ifndef PYTHONQOBJECT_H
#define PYTHONQOBJECT_H

#include <QObject>

/// @macro: PYTHON_QOBJECT
/// This macro is similiar to Q_OBJECT macro, but is intended for creating
/// PythonQObject, instead of regular QObject. PythonQObjects are QObjects
/// exposed to Python with Boost, and with special "meta"-functions.
/// With this, we can make a Python object reflect its features like
/// Signals, Slots and Properties to the Qt MetaObject system.
/// 
#define PYTHON_QOBJECT \
public: \
    virtual int \
    qt_metacall(QMetaObject::Call c, int i, void** a) \
    { return _qt_metacall(this, c, i, a); } \
    /*virtual const QMetaObject* metaObject() const; \
    virtual void* qt_metacast(const char*);*/  

    
/// This is a vector of integers. Each int can mean the address 
/// of a information on qt_meta_stringdata_PythonQObject or can
/// an address(offset) in the of an informarion adress on this
/// same vector
///
static const uint qt_meta_data_PythonQObject[] = {    
    // content:
    1,       // revision
    0,       // classname
    0,    0, // classinfo
    0,    0, // methods
    0,    0, // properties
    0,    0, // enums/sets
    0        // eod
};


///  this string means
static const char qt_meta_stringdata_PythonQObject[] = {
    "PythonQObject\0\0"
};
        

//            
template <typename QParent>
struct PythonQObject
{
    PythonQObject()
    {
        qDebug("-----------------------------------------------------");
    }

    int 
    _qt_metacall(QParent* obj, QMetaObject::Call c, int i, void** a)
    {
        qDebug("PythonQObject::qt_metacall: (%d,%d)", c, i);
        return obj->QParent::qt_metacall(c, i, a);
    }
};




#endif