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

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include "PythonConnection.h"


#include <QList>
#include <QString>
#include <QEvent>
#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>
#include <memory>
#include <iostream>
//#include <string>


void
qprint(const QString& s)
{
    std::cout << s.toStdString() << std::endl;
}

std::string
to_str(const QString& s)
{
    return s.toStdString();
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


// void
// QObject_del(QObject* obj)
// {
//     std::cout << "__del__: " << obj->objectName().toStdString() << " at " << obj << std::endl;
//     //qDebug("__del__:%s at %p", obj);
// }

void
QObject_del(object self)
{
    QObject* obj = extract<QObject*>(self);
    std::string name = extract<std::string>( self.attr("objectName") );
    std::cout << "__del__: " << name << " @ " << obj  << std::endl;
    //extract<std::string>( obj.attr('__name__') ) << " at " << obj.ptr() << std::endl;
    //qDebug("__del__:%s at %p", self->objectName().toStdString(), self);
}


void
QObject_connect(object self, const QString& name, object method)
//QObject_connect(QObject* self, const QString& name, object method)
{
    QObject* sender = extract<QObject*>( self );
    std::string self_ = extract<std::string>( self.attr("objectName") );
    //object im_self = method.attr("im_self");
    //std::string im_self_ = extract<std::string>( str(im_self) );
    
    //boost::python::incref(method.ptr());
    qDebug("method: %p", method.ptr());
    PythonConnection* conn = new PythonConnection(sender, &method);
    QObject::connect(sender, name.toStdString().c_str(), conn, SLOT(callback()) );
    method();
    
    //call_method<void>(im_self.ptr(), "on_button_clicked");
    
    //std::string name_ = extract<std::string>(str);
    std::cout << "connect: " << sender << " " << name.toStdString() << std::endl;
}

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
    
static QMap<QObject*, list> __children__;
// static QMap<QObject*, boost::shared_ptr<QObject> > _refs;
// 
// struct QtWrapper {
//     QtWrapper(QObject*)
//     {
//     }
// };

list
childrens(QObject* obj)
{
    //list ret;
    return __children__[obj];
}

struct QObject_Wrapper: QObject, wrapper<QObject>
{
//    list children;

    QObject_Wrapper():
        QObject()
    {
        qDebug("new QObject_Wrapper: %p", this);
    }
    
    //QObject_Wrapper(QObject* parent):
    QObject_Wrapper(object parent):
        QObject( extract<QObject*>(parent) )
    {
        qDebug("new QObject_Wrapper(parent): %p", this);
        //list children = list( parent.attr("__children__") );
        //object item = object( ptr(this) );
        //children.append(item);
        //parent.attr("__children__") = children;
        //if ()
        //{
//             list& children = __children__[parent];
//             object item = object( ptr(this) );
//             children.append(item);
//             incref( item.ptr() );
//             qDebug("new %p", this);
        //}
    }
    
//     QObject_Wrapper(boost::shared_ptr<QObject> parent):
//     //QObject_Wrapper(std::auto_ptr <QObject> parent):
//         QObject(parent.get()), QtWrapper(parent.get())
//     {
//         //qDebug("parent: %p", this->parent());
//         //_refs[parent.get()] = parent;
//         //qDebug("use_count: %ld", parent.use_count());
//         //qDebug("use_count: %ld", parent.use_count());
//     }

    virtual ~QObject_Wrapper()
    {
        qDebug("del: %p", this);
        //_refs.remove(parent());
        //qDebug("~QObject_Wrapper: %s @ %p", this->objectName().toStdString(), this);
    } 
           
    bool
    event(QEvent* p0)
    {
        //qDebug("QObject_Wrapper::event");
        if (override event = this->get_override("event"))
        {
            return event( ptr( p0 ) );
        }
        else
        {
            return QObject::event(p0);
        }
    }

    bool
    default_event(QEvent* p0)
    {
        //qDebug("QObject_Wrapper::default_event");
        return this->QObject::event(p0);
    }

    void
    childEvent(QChildEvent* event)
    {
        qDebug("QObject_Wrapper::childEvent");
        QObject* obj = event->child();
        object child( ptr(obj) );
        qDebug("child %p:%p", obj, child.ptr());
        
        list& children = __children__[this];
        children.append( child );
    }
};

QObject* 
factory(QObject* parent)
{
    return new QObject(parent);
}

// // QObject* 
// // __bypass__(QObject* obj)
// // {
// //     object pyobj( ptr(obj) );
// //     qDebug("__bypass__: (%p, %p)", obj, pyobj.ptr());
// //     return obj;
// // }

// object
// QObject___init__(object self, object parent)
// {
//     qDebug("__init__");
//     object oldinit = QObject_class.attr("__oldinit__");
//     oldinit(self, parent);
// }

// object
// QObject___new__(object self)
// {
//     qDebug("__new__");
//     object oldnew = QObject_class.attr("__oldnew__");
//     oldnew(self);
// }

void
export_QObject()
{
    to_python_converter<QList<QObject*>, QObjectList_to_python_object>();

    //def("connect", &Qt_connect, with_custodian_and_ward<1,3>() );
    //def("__bypass__", __bypass__, return_value_policy<reference_existing_object>() );
    def("childrens", childrens, default_call_policies() );
    def("factory", factory, return_value_policy<reference_existing_object, with_custodian_and_ward_postcall<0,1> >() );
    def("qprint", qprint);
    def("to_str", to_str);
    def("display", display, return_internal_reference<>() );
    def("compare", compare);
    
    // static methods
    def("tr", &QObject::tr);
    def("trUtf8", &QObject::trUtf8);

    QObject_class = class_<QObject_Wrapper,
        //std::auto_ptr<QObject_Wrapper>,
        boost::shared_ptr<QObject_Wrapper>,
        boost::noncopyable>
        ("QObject", init<>())
        //("QObject", no_init)

        //.def("__init__", QObject__call__)
        // constructor with QObject parent
        .def(init<object>(args("parent"))
        //.def(init<QObject*>(args("parent"))
        //.def(init< std::auto_ptr<QObject> >(args("parent"))
        //.def(init< boost::shared_ptr<QObject> >(args("parent")) 
            //[default_call_policies()])
            //[with_custodian_and_ward_postcall<1,2>()])
            [with_custodian_and_ward<1,2>()])
            //[with_custodian_and_ward<1,2,with_custodian_and_ward<2,1> >()])
                                            
        //.def(init<QObject*>(args("parent")) [with_custodian_and_ward<1,2/*,
        //                                    with_custodian_and_ward<2,1>*/ >()])

        .def("connect", QObject_connect)
        .def("event", &QObject::event, &QObject_Wrapper::default_event)
        //.def("eventFilter", &QObject::eventFilter, &QObject_Wrapper::default_eventFilter)
        //.def("installEventFilter", &QObject::installEventFilter)
        //.def("removeEventFilter", &QObject::removeEventFilter)
        
        //.def("children", &QObject::children, with_custodian_and_ward_postcall<0,1>())
        //.def("children", &QObject::children, return_internal_reference<>() )
        .def("children", &QObject::children, return_value_policy<return_by_value>())
        //.def("children", &QObject::children, return_value_policy<reference_existing_object>() )

        //.def("findChild", &QObject::findChild<QObject*>, ,<>() )
        //.def("findChild", &QObject::findChild<QObject*>, return_value_policy<manage_new_object>() )
        //.def("findChild", &QObject::findChild<QObject*>, return_value_policy<reference_existing_object>())
        .def("findChild", &QObject::findChild<QObject*>, return_value_policy<reference_existing_object, with_custodian_and_ward_postcall<0,1> >())
        //.def(init<QObject*>()[with_custodian_and_ward<2,1>()])
        //.def("parent", &QObject::parent)
        //.def("__eq__", compare)
        //.def("parent", &QObject::parent, return_internal_reference<>() )
        .def("parent", &QObject::parent, return_value_policy<reference_existing_object>() )
        .def("setParent", &QObject::setParent, with_custodian_and_ward<2,1>() )
        //.def("parent", &QObject::parent, return_value_policy<manage_new_object>())
        //.def("parent", &QObject::parent, return_value_policy<reference_existing_object>())
        //.def("parent", &QObject::parent, return_value_policy<copy_const_reference>())
        .add_property("objectName", &QObject::objectName, &QObject::setObjectName)

        //.def_readwrite("__children__", &QObject_Wrapper::children)
        
        .def("__signals__", QObject___signals__)
        
        //.def("__del__", QObject_del)
    ;

/*   QObject_class.attr("__oldinit__") = QObject_class.attr("__init__");
   QObject_class.attr("__init__") = make_function(QObject___init__);*/
    //QObject_class.attr("__oldnew__") = QObject_class.attr("__new__");
    //QObject_class.attr("__new__") = make_function(QObject___new__);
    
//     class_<PythonConnection,
//         bases<QObject>,
//         boost::shared_ptr<PythonConnection>,
//         boost::noncopyable>
//     ("PythonConnection", no_init)
//         .def("callback", &PythonConnection::callback)
//     ;
}





