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

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/str.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/manage_new_object.hpp>
//#include <boost/python/return_value_policy.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/with_custodian_and_ward.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <PythonQObject.h>
#include <PythonQtWrapper.h>

#include <QLayout>
#include <QWidget>


using namespace boost::python;


QOBJECT_WRAPPER(QLayout, PythonQLayout)
{
    PYTHON_QOBJECT;    
    
    PythonQLayout(QWidget* parent): QLayout(parent) {}
    
    // defined in QLayoutItem
    PURE_VIRTUAL_1(void, addItem, QLayoutItem*);
    PURE_VIRTUAL_CONST_0(QSize, sizeHint);
    PURE_VIRTUAL_1(void, setGeometry, const QRect&);
    PURE_VIRTUAL_CONST_1(QLayoutItem*, itemAt, int);
    PURE_VIRTUAL_1(QLayoutItem*, takeAt, int);
    PURE_VIRTUAL_CONST_0(int, count);
};


void
export_QLayout()
{
    scope* QLayout_scope = new scope(
    
    class_< PythonQLayout,
            bases<QObject, QLayoutItem>,
            boost::shared_ptr<PythonQLayout>,
            boost::noncopyable>
    ("QLayout", init<QWidget*>(args("parent"))[with_custodian_and_ward<1,2>()] )
        .def("isEnabled", &QLayout::isEnabled)
        .def("setEnabled", &QLayout::isEnabled)
        
    );

    enum_< QLayout::SizeConstraint >("SizeConstraint")
        .value("SetMinAndMaxSize", QLayout::SetMinAndMaxSize)
        .value("SetMinimumSize", QLayout::SetMinimumSize)
        .value("SetFixedSize", QLayout::SetFixedSize)
        .value("SetDefaultConstraint", QLayout::SetDefaultConstraint)
        .value("SetNoConstraint", QLayout::SetNoConstraint)
        .value("SetMaximumSize", QLayout::SetMaximumSize)
    ;

    delete QLayout_scope;
    
}
