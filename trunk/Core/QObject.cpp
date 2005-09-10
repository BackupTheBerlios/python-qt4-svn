/***************************************************************************
*    Copyright (C) 2005 by Eric Jardim                                     *
*    ericjardim@gmail.com                                                  *
*                                                                          *
*    This program is free software; you can redistribute it and/or modify  *
*    it under the terms of the GNU General Public License as published by  *
*    the Free Software Foundation; either version 2 of the License, or     *
*    (at your option) any later version.                                   *
*                                                                          *
*    This program is distributed in the hope that it will be useful,       *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*    GNU General Public License for more details.                          *
*                                                                          *
*    You should have received a copy of the GNU General Public License     *
*    along with this program; if not, write to the                         *
*    Free Software Foundation, Inc.,                                       *
*    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
****************************************************************************/

//#include <boost/python.hpp>
// #include <boost/python/module.hpp>
#include <Python.h>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/str.hpp>
#include <boost/python/ptr.hpp>
#include <boost/python/call_method.hpp>
#include <boost/python/override.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <PythonQt.h>
#include <QtWrapper.h>

#include <QThread>
#include <QList>
#include <QString>
#include <QEvent>
#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>
#include <memory>
#include <iostream>
//#include <string>

//#include <qobjectdefs.h>

void
to_stdout(const QString& s)
{
    std::cout << s.toLocal8Bit().data() << std::endl;
}

// Return a QByteArray as a str
std::string
to_str(const QByteArray& s)
{
    return std::string(s.data(), s.size());
}

// Return a str containing the utf-8 encoded bytes to represent
// the passed QString.
std::string
to_utf8_str(const QString& s)
{
    QByteArray d(s.toUtf8());
    return std::string(d.data(), d.size());
}

// Return a str containing the latin-1 encoded bytes to represent
// the passed QString. Characters that cannot be represented in
// latin-1 are replaced with `?' .
std::string
to_latin1_str(const QString& s)
{
    QByteArray d(s.toLatin1());
    return std::string(d.data(), d.size());
}

QString
to_unicode(const QString& s)
{
    return QString(s);
}

///////////////////////////////

QObject*
factory(QObject* parent)
{
    return new QObject(parent);
}

QObject*
display(QObject* obj)
{
    qDebug("%p", obj);
    //qDebug() << "name:" << obj->objectName() << std::endl;
    return obj;
}

bool
compare(const QObject* a, const QObject* b)
{
    qDebug("compare");
    return a == b;
}

using namespace boost::python;

static object QObject_class;

struct
QObjectList_to_python_object
{
    static PyObject*
    convert(QList<QObject*> const& objectList)
    {
        list pythonList;
        for(int i = 0; i < objectList.size(); ++i)
        {
            //QObject* _item = objectList.at(i);
            //object item = object(ptr( _item ));
            pythonList.append( ptr( objectList.at(i)  )  );
            //incref( item.ptr() );
        }
        
        return incref( pythonList.ptr() );
    }
};

void
QObject_del(object self)
{
    QObject* obj = extract<QObject*>(self);
    std::string name = extract<std::string>( self.attr("objectName") );
    std::cout << "__del__: " << name << " @ " << obj  << std::endl;
    //extract<std::string>( obj.attr('__name__') ) << " at " << obj.ptr() << std::endl;
    //qDebug("__del__:%s at %p", self->objectName().toStdString(), self);
}


/*void
QObject_connect(object self, const QString& signal, object method)
//QObject_connect(QObject* self, const QString& name, object method)
{
    QObject* sender = extract<QObject*>( self );
    std::string self_ = extract<std::string>( self.attr("objectName") );
    //object im_self = method.attr("im_self");
    //std::string im_self_ = extract<std::string>( str(im_self) );
    
    //boost::python::incref(method.ptr());
    qDebug("method: %p", method.ptr());
    PythonConnection* conn = new PythonConnection(sender, &method);
    QObject::connect(sender, signal.toStdString().c_str(), conn, SLOT(callback()) );
    method();
    
    //call_method<void>(im_self.ptr(), "on_button_clicked");
    
    //std::string name_ = extract<std::string>(str);
    std::cout << "connect: " << sender << " " << signal.toStdString() << std::endl;
}*/

// void
// QObject_connect(object self, const QString& name, object method)
// //QObject_connect(QObject* self, const QString& name, object method)
// {
//     QObject* sender = extract<QObject*>( self );
//     std::string self_ = extract<std::string>( self.attr("objectName") );
//     //object im_self = method.attr("im_self");
//     //std::string im_self_ = extract<std::string>( str(im_self) );
//     
//     //boost::python::incref(method.ptr());
//     qDebug("method: %p", method.ptr());
//     PythonConnection* conn = new PythonConnection(sender, &method);
//     QObject::connect(sender, name.toStdString().c_str(), conn, SLOT(callback()) );
//     method();
//     
//     //call_method<void>(im_self.ptr(), "on_button_clicked");
//     
//     //std::string name_ = extract<std::string>(str);
//     std::cout << "connect: " << sender << " " << name.toStdString() << std::endl;
// }


list
QObject___signals__(QObject* self)
{
    const QMetaObject* mo = self->metaObject();

    list _signals;
    
    for(int i=0; i < mo->methodCount(); i++)
    {
        std::string name = mo->method(i).signature();
        _signals.append(name);
    }
    
    return _signals;
}


QOBJECT_WRAPPER(QObject, PythonQObject)
{
    PYTHON_QOBJECT;
    
    PythonQObject(QObject* parent=0): QObject(parent) {}
    virtual ~PythonQObject() { qDebug("del: %p", this); }

    // QObject virtual methods
    VIRTUAL_1(bool,, event, QEvent*,);
    VIRTUAL_2(bool,, eventFilter, QObject*, QEvent*,);
    
    // QObject protected virtual methods
    VIRTUAL_1(void, (void), childEvent, QChildEvent*, );
    VIRTUAL_1(void, (void), connectNotify, const char*, );
    VIRTUAL_1(void, (void), customEvent, QEvent*, );
    VIRTUAL_1(void, (void), disconnectNotify, const char*, );
    VIRTUAL_1(void, (void), timerEvent, QTimerEvent*, );

    // QObject protected methods
    PROTECTED_1(int,, receivers, const char*, const);
    PROTECTED_0(QObject*,, sender, const);
};

//BOOST_PYTHON_FUNCTION_OVERLOADS(QObject_connect_overloads_4_5, QObject::connect, 4, 5);


static void
__addDynamicMethod__(QObject* obj, QString signature, QString name, list params, object method)
{
    abstractwrapper* wrapper = dynamic_cast<abstractwrapper*>(obj);
    QList<QString> params_;
    int n = extract<int>( (params.attr("__len__"))() );
    for(int i=0; i<n; i++)
    {
        params_.append( extract<QString>( params[i] ) );
    }
    wrapper->addDynamicMethod(signature, name, params_, method);
}

static bool
__connectSlot__(QObject* sender, QString signal, QObject* reciever, QString slot)
{
    QString _signal = QString::number(QSIGNAL_CODE)+signal;
    QString _slot = QString::number(QSLOT_CODE)+slot;
    QObject::connect(sender, _signal.toStdString().c_str(), reciever, _slot.toStdString().c_str());
}


void
export_QObject()
{
    //qDebug(">>> ...");
    
    // this should be on other file
    to_python_converter<QList<QObject*>, QObjectList_to_python_object>();
   
    def("factory", factory,
                   return_value_policy<reference_existing_object,
                   with_custodian_and_ward_postcall<0,1> >() );
    def("to_stdout", to_stdout);
    def("to_str", to_str);
    def("to_utf8_str", to_utf8_str);
    def("to_latin1_str", to_latin1_str);
    def("to_unicode", to_unicode);
        
    def("display", display, return_internal_reference<>() );
    def("compare", compare);
    def("__addDynamicMethod__", __addDynamicMethod__);
    def("__connectSlot__", __connectSlot__);

    // static methods
    def("tr", ( QString (*)(const char*) ) &QObject::tr);
    def("tr", ( QString (*)(const char*, const char*) ) &QObject::tr);
    def("trUtf8", &QObject::trUtf8);

    QObject_class = class_<PythonQObject,
        boost::shared_ptr<PythonQObject>,
        boost::noncopyable>
        ("QObject", init<>())
        .def(init<QObject*>(args("parent")) [with_custodian_and_ward<1,2>()])

        // properties                                    
        .add_property("objectName", &QObject::objectName, &QObject::setObjectName)

        // methods         
        .def("blockSignals", &QObject::blockSignals)
        .def("signalsBlocked", &QObject::signalsBlocked)
        .def("dumpObjectTree", &QObject::dumpObjectTree)
        .def("dumpObjectInfo", &QObject::dumpObjectInfo)
        .def("event", &QObject::event, &PythonQObject::__event)
        .def("eventFilter", &QObject::eventFilter, &PythonQObject::__eventFilter)
        //.def("children", &QObject::children, return_value_policy<copy_const_reference>())
        .def("children", &QObject::children, return_value_policy<return_by_value>() )
        .def("findChild", &QObject::findChild<QObject*>,
                          return_value_policy<reference_existing_object,
                          with_custodian_and_ward_postcall<0,1> >())
        .def("inherits", &QObject::inherits)
        .def("installEventFilter", &QObject::installEventFilter)
        .def("removeEventFilter", &QObject::removeEventFilter)
        .def("isWidgetType", &QObject::isWidgetType)
        .def("startTimer", &QObject::startTimer)
        .def("killTimer", &QObject::killTimer)
        //.def("thread", &QObject::thread,
        //               return_value_policy<reference_existing_object>() )
        //.def("moveToThread", &QObject::moveToThread)
        //.def("parent", &QObject::parent, return_internal_reference<>() )
        .def("parent", &QObject::parent,
                       return_value_policy<reference_existing_object>() )
        .def("setParent", &QObject::setParent,
                       with_custodian_and_ward<1,2>() )
        //.def("registerUserData", &QObject::registerUserData)
        //.def("setUserData", &QObject::setUserData)
        //.def("userData", &QObject::userData)
        
        // slots
        .def("deleteLater", &QObject::deleteLater)

        // protected methods
        .def("childEvent", &PythonQObject::__childEvent)
        .def("connectNotify", &PythonQObject::__connectNotify)
        .def("customEvent", &PythonQObject::__customEvent)
        .def("disconnectNotify", &PythonQObject::__disconnectNotify)
        .def("timerEvent", &PythonQObject::__timerEvent)
        .def("receivers", &PythonQObject::__receivers)
        .def("sender", &PythonQObject::__sender, return_value_policy<reference_existing_object>() )
        
        // custom
        .def("__signals__", QObject___signals__)
        
        
        //.def("eventFilter", &QObject::eventFilter, &PythonQObject::__eventFilter)
        //.def("installEventFilter", &QObject::installEventFilter)
        //.def("removeEventFilter", &QObject::removeEventFilter)
        
        //.def("children", &QObject::children, with_custodian_and_ward_postcall<0,1>())
        //.def("children", &QObject::children, return_internal_reference<>() )
        //.def("children", &QObject::children, return_value_policy<reference_existing_object>() )

        //.def("findChild", &QObject::findChild<QObject*>, ,<>() )
        //.def("findChild", &QObject::findChild<QObject*>, return_value_policy<manage_new_object>() )
        //.def("findChild", &QObject::findChild<QObject*>, return_value_policy<reference_existing_object>())
        //.def(init<QObject*>()[with_custodian_and_ward<2,1>()])
        //.def("parent", &QObject::parent)
        //.def("__eq__", compare)
        //.def("parent", &QObject::parent, return_internal_reference<>() )
        //.def("parent", &QObject::parent, return_value_policy<manage_new_object>())
        //.def("parent", &QObject::parent, return_value_policy<reference_existing_object>())
        //.def("parent", &QObject::parent, return_value_policy<copy_const_reference>())
    ;
}





