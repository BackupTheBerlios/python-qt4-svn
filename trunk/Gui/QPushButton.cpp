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
#include <boost/shared_ptr.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/str.hpp>
#include <boost/python/wrapper.hpp>

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <QtWrapper.h>
#include <parent_change_policy.h>


#include <QEvent>
#include <QWidget>
#include <QPushButton>
//#include <QString>
#include <memory>
//#include <iostream>
//#include <string>


using namespace boost::python;

QOBJECT_WRAPPER(QPushButton, PythonQPushButton)
{
    PYTHON_QOBJECT;
    
    PythonQPushButton(QWidget* p0=0):QPushButton(p0) {}
    PythonQPushButton(const QString& p0, QWidget* p1=0):QPushButton(p0, p1) {}

    // signals
    void
    clicked(bool checked=false)
    {
        this->QPushButton::clicked(checked);
    }

//protected:
//     bool
//     event(QEvent* p0)
//     {
//         qDebug("PythonQPushButton::event");
//         if (override event = this->get_override("event"))
//         {
//             return event( ptr( p0 ) );
//         }
//         return QPushButton::event(p0);
//     }
// 
//     bool
//     default_event(QEvent* p0)
//     {
//         qDebug("PythonQPushButton::default_event");
//         return this->QPushButton::event(p0);
//     }
};

void
export_QPushButton()
{
    class_< PythonQPushButton,
            bases<QWidget>,
            boost::shared_ptr<PythonQPushButton>,
            boost::noncopyable>
            ("QPushButton", init< optional<QWidget*> >(args("parent"))[parent_change_policy<>()] )
        .def(init<const QString&, optional<QWidget*> >(args("text", "parent"))[parent_change_policy<>()] )
        
        //.def("event", &QObject::event, &QObject_Wrapper::default_event)
        //.def("event", &QPushButton::event, &PythonQPushButton::default_event)
        .add_property("autoDefault", &QPushButton::autoDefault, &QPushButton::setAutoDefault)
        .add_property("default", &QPushButton::isDefault, &QPushButton::setDefault)
        .add_property("flat", &QPushButton::isFlat, &QPushButton::setFlat)
        .add_property("text", &QPushButton::text, &QPushButton::setText)

        
        // signals
        .def("clicked", (void (PythonQPushButton::*)() ) &PythonQPushButton::clicked)
        .def("clicked", (void (PythonQPushButton::*)(bool) ) &PythonQPushButton::clicked)
        
        //.def("parent", &QObject::parent, return_internal_reference<>() )
        //.def("parent", &QObject::parent, return_value_policy<manage_new_object>())
        //.def("parent", &QObject::parent, return_value_policy<reference_existing_object>())
        //.def("parent", &QObject::parent, return_value_policy<copy_const_reference>())
        //.add_property("objectName", &QObject::objectName, &QObject::setObjectName)
    ;
}
