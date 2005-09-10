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

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>
//#include <boost/python/return_value_policy.hpp>

#include <QtWrapper.h>

#include <QLayout>
#include <QWidget>
#include <QAbstractItemView>
#include <QListView>
#include <QListWidget>
//#include <QString>
#include <memory>
//#include <iostream>
//#include <string>

using namespace boost::python;

QOBJECT_WRAPPER(QBoxLayout, PythonQBoxLayout)
{
    PYTHON_QOBJECT;
    PythonQBoxLayout(Direction p1, QWidget* p2=0):QBoxLayout(p1, p2) {}

    // defined in QLayout
    VIRTUAL_1(void,(void),addItem, QLayoutItem*,);
    VIRTUAL_0(int,, count, const);
    VIRTUAL_1(QLayoutItem*,, itemAt, int, const);
    VIRTUAL_1(QLayoutItem*,, takeAt, int, );

    // protected in QBoxLayout
    PROTECTED_2(void,(void),insertItem , int, QLayoutItem*, )
};

QOBJECT_WRAPPER(QHBoxLayout, PythonQHBoxLayout)
{
    PYTHON_QOBJECT;
    PythonQHBoxLayout():QHBoxLayout() {}
    PythonQHBoxLayout(QWidget* p1):QHBoxLayout(p1) {}
};

QOBJECT_WRAPPER(QVBoxLayout, PythonQVBoxLayout)
{
    PYTHON_QOBJECT;
    PythonQVBoxLayout():QVBoxLayout() {}
    PythonQVBoxLayout(QWidget* p1):QVBoxLayout(p1) {}
};


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_addStretch_overloads_0_1, addStretch, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_addWidget_overloads_1_3, addWidget, 1, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_addLayout_overloads_1_2, addLayout, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_insertStretch_overloads_1_2, insertStretch, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_insertWidget_overloads_2_4, insertWidget, 2, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QBoxLayout_insertLayout_overloads_2_3, insertLayout, 2, 3)

/*
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QGridLayout_addWidget_overloads_3_4, addWidget, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QGridLayout_addWidget_overloads_5_6, addWidget, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QGridLayout_addLayout_overloads_3_4, addLayout, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QGridLayout_addLayout_overloads_5_6, addLayout, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QGridLayout_addItem_overloads_3_6, addItem, 3, 6)
*/


void
export_QBoxLayout()
{
    scope* QBoxLayout_scope = new scope(
    class_< PythonQBoxLayout,
            bases<QLayout>,
            boost::shared_ptr<PythonQBoxLayout>,
            boost::noncopyable>
    ("QBoxLayout", init<QBoxLayout::Direction>() )
        .def(init<QBoxLayout::Direction, QWidget*>()[with_custodian_and_ward<1,3>()])
        
/*
        .def("sizeHint", (QSize (QBoxLayout::*)() const)&QBoxLayout::sizeHint, (QSize (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__sizeHint)
        .def("minimumSize", (QSize (QBoxLayout::*)() const)&QBoxLayout::minimumSize, (QSize (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__minimumSize)
        .def("maximumSize", (QSize (QBoxLayout::*)() const)&QBoxLayout::maximumSize, (QSize (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__maximumSize)
        .def("hasHeightForWidth", (bool (QBoxLayout::*)() const)&QBoxLayout::hasHeightForWidth, (bool (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__hasHeightForWidth)
        .def("heightForWidth", (int (QBoxLayout::*)(int) const)&QBoxLayout::heightForWidth, (int (PythonQBoxLayout::*)(int) const)&PythonQBoxLayout::__heightForWidth)
        .def("minimumHeightForWidth", (int (QBoxLayout::*)(int) const)&QBoxLayout::minimumHeightForWidth, (int (PythonQBoxLayout::*)(int) const)&PythonQBoxLayout::__minimumHeightForWidth)
        .def("expandingDirections", (Qt::Orientations (QBoxLayout::*)() const)&QBoxLayout::expandingDirections, (Qt::Orientations (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__expandingDirections)
        .def("setGeometry", (void (QBoxLayout::*)(const QRect&) )&QBoxLayout::setGeometry, (void (PythonQBoxLayout::*)(const QRect&))&PythonQBoxLayout::__setGeometry)
        .def("geometry", (QRect (QLayout::*)() const)&QLayout::geometry, (QRect (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__geometry)
        .def("indexOf", &QLayout::indexOf, &PythonQBoxLayout::__indexOf)
        .def("isEmpty", (bool (QLayout::*)() const)&QLayout::isEmpty, (bool (PythonQBoxLayout::*)() const)&PythonQBoxLayout::__isEmpty)
        .def("layout", (QLayout* (QLayout::*)() )&QLayout::layout, (QLayout* (PythonQBoxLayout::*)())&PythonQBoxLayout::__layout)
        .def("widget", &QLayoutItem::widget, &PythonQBoxLayout::__widget)
        .def("spacerItem", &QLayoutItem::spacerItem, &PythonQBoxLayout::__spacerItem)*/
        //.def("invalidate", (void (QBoxLayout::*)() )&QBoxLayout::invalidate)
        
        .def("addItem", &QBoxLayout::addItem, &PythonQBoxLayout::__addItem)
        .def("count", &QBoxLayout::count, &PythonQBoxLayout::__count)
        .def("itemAt", &QBoxLayout::itemAt, &PythonQBoxLayout::__itemAt,
                       return_value_policy<reference_existing_object>() )
        .def("takeAt", &QBoxLayout::takeAt,
                       &PythonQBoxLayout::__takeAt,
                       return_value_policy<reference_existing_object>() )
        
        .def("direction", &QBoxLayout::direction)
        .def("setDirection", &QBoxLayout::setDirection)
        .def("addSpacing", &QBoxLayout::addSpacing)
        .def("addStretch", &QBoxLayout::addStretch, QBoxLayout_addStretch_overloads_0_1())
        .def("addWidget", &QBoxLayout::addWidget, QBoxLayout_addWidget_overloads_1_3())
        .def("addLayout", &QBoxLayout::addLayout, QBoxLayout_addLayout_overloads_1_2())
        .def("addStrut", &QBoxLayout::addStrut)
        .def("insertSpacing", &QBoxLayout::insertSpacing)
        .def("insertStretch", &QBoxLayout::insertStretch, QBoxLayout_insertStretch_overloads_1_2())
        .def("insertWidget", &QBoxLayout::insertWidget, QBoxLayout_insertWidget_overloads_2_4())
        .def("insertLayout", &QBoxLayout::insertLayout, QBoxLayout_insertLayout_overloads_2_3())
        .def("setStretchFactor", (bool (QBoxLayout::*)(QWidget*, int) )&QBoxLayout::setStretchFactor)
        .def("setStretchFactor", (bool (QBoxLayout::*)(QLayout*, int) )&QBoxLayout::setStretchFactor)        
    );
    
    enum_< QBoxLayout::Direction >("Direction")
        .value("BottomToTop", QBoxLayout::BottomToTop)
        .value("LeftToRight", QBoxLayout::LeftToRight)
        .value("Up", QBoxLayout::Up)
        .value("Down", QBoxLayout::Down)
        .value("RightToLeft", QBoxLayout::RightToLeft)
        .value("TopToBottom", QBoxLayout::TopToBottom)
        .export_values()
    ;

    delete QBoxLayout_scope;
    
    class_< PythonQHBoxLayout,
            bases<QBoxLayout>,
            boost::shared_ptr<PythonQHBoxLayout>,
            boost::noncopyable>
    ("QHBoxLayout",  init<QWidget*>()[with_custodian_and_ward<1,2>()])
        .def(init<>())
    ;

    class_< PythonQVBoxLayout,
            bases<QBoxLayout>,
            boost::shared_ptr<PythonQVBoxLayout>,
            boost::noncopyable>
    ("QVBoxLayout",  init<QWidget*>()[with_custodian_and_ward<1,2>()])
        .def(init<>())
    ;
}
