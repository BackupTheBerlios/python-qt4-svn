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
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/str.hpp>
#include <boost/shared_ptr.hpp>

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <PythonQObject.h>

#include <QLineEdit>
#include <QEvent>
//#include <QString>
//#include <memory>
//#include <iostream>
//#include <string>

using namespace boost::python;

struct PythonQLineEdit: QLineEdit, 
                        wrapper<QLineEdit>,
                        qtwrapper<QLineEdit, PythonQLineEdit>
{
    PYTHON_QOBJECT;
    
    PythonQLineEdit(QWidget* p0=0):
        QLineEdit(p0)
    {
    }

    PythonQLineEdit(const QString& p0, QWidget* p1=0):
        QLineEdit(p0, p1)
    {
    }
};


void
export_QLineEdit()
{
    class_< PythonQLineEdit,
            bases<QWidget>,
            boost::shared_ptr<PythonQLineEdit>,
            boost::noncopyable>
    ("QLineEdit")
        .def(init<QWidget*>() [with_custodian_and_ward<1,2>()] )
        .def(init<const QString&, QWidget*>() [with_custodian_and_ward<1,3>()] )        
        .add_property("text", &QLineEdit::text, &QLineEdit::setText)

        //.add_property("autoDefault", &QLineEdit::autoDefault, &QLineEdit::setAutoDefault)
        //.add_property("default", &QLineEdit::isDefault, &QLineEdit::setDefault)
        //.add_property("flat", &QLineEdit::isFlat, &QLineEdit::setFlat)
        //.def("parent", &QObject::parent, return_internal_reference<>() )
        //.def("parent", &QObject::parent, return_value_policy<manage_new_object>())
        //.def("parent", &QObject::parent, return_value_policy<reference_existing_object>())
        //.def("parent", &QObject::parent, return_value_policy<copy_const_reference>())
        //.add_property("objectName", &QObject::objectName, &QObject::setObjectName)
    ;
}