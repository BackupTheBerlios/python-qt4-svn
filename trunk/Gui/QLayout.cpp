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
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <QtWrapper.h>
#include <parent_change_policy.h>

#include <QLayout>
#include <QWidget>


using namespace boost::python;


QOBJECT_WRAPPER(QLayout, PythonQLayout)
{
    PYTHON_QOBJECT;
    PythonQLayout(QWidget* parent): QLayout(parent) {}
    
    // defined in QLayoutItem
    PURE_VIRTUAL_0(QSize,, sizeHint, const);
    PURE_VIRTUAL_1(void,(void),setGeometry, const QRect&,);
    VIRTUAL_0(QFlags<Qt::Orientation>,, expandingDirections, const);
    VIRTUAL_0(bool,, hasHeightForWidth, const);
    VIRTUAL_1(int,, heightForWidth, int, const);
    VIRTUAL_1(int,, minimumHeightForWidth, int, const);
    VIRTUAL_0(QSpacerItem*,, spacerItem,);
    VIRTUAL_0(QWidget*,, widget,);
        
    // defined in QLayout
    PURE_VIRTUAL_1(void,(void),addItem, QLayoutItem*,);
    PURE_VIRTUAL_0(int,, count, const);
    PURE_VIRTUAL_1(QLayoutItem*,, itemAt, int, const);
    PURE_VIRTUAL_1(QLayoutItem*,, takeAt, int, );
    VIRTUAL_1(int,, indexOf, QWidget*, const);
    VIRTUAL_0(QSize,, maximumSize, const);
    VIRTUAL_0(QSize,, minimumSize, const);

    
    // protected in QLayout
    PROTECTED_1(void,(void),addChildLayout, QLayout*, );
    PROTECTED_1(void,(void),addChildWidget, QWidget*, )
    PROTECTED_1(QRect,,alignmentRect, const QRect&, const);
};


void
export_QLayout()
{
    scope* QLayout_scope = new scope(
    
    class_< PythonQLayout,
            bases<QObject, QLayoutItem>,
            boost::shared_ptr<PythonQLayout>,
            boost::noncopyable>
    ("QLayout", init<QWidget*>(args("parent"))[parent_change_policy<>()] )

        // properties
        .add_property("margin", &QLayout::margin, &QLayout::setMargin)
        .add_property("sizeConstraint", &QLayout::sizeConstraint, &QLayout::setSizeConstraint)
        .add_property("spacing", &QLayout::spacing, &QLayout::setSpacing)
        .add_property("enabled", &QLayout::isEnabled, &QLayout::isEnabled)

        // methods
        .def("isEnabled", &QLayout::isEnabled)
        .def("setEnabled", &QLayout::isEnabled)
        .def("geometry", (QRect (QLayout::*)() const)&QLayout::geometry)
        .def("addItem", pure_virtual(&QLayout::addItem))
        .def("expandingDirections", (Qt::Orientations (QLayout::*)() const) &QLayout::expandingDirections,
                                    (Qt::Orientations (PythonQLayout::*)() const)&PythonQLayout::__expandingDirections)
        .def("minimumSize", (QSize (QLayout::*)() const)&QLayout::minimumSize,
                            (QSize (PythonQLayout::*)() const)&PythonQLayout::__minimumSize)
        .def("maximumSize", (QSize (QLayout::*)() const)&QLayout::maximumSize,
                            (QSize (PythonQLayout::*)() const)&PythonQLayout::__maximumSize)
        .def("setGeometry", pure_virtual((void (QLayout::*)(const QRect&) )&QLayout::setGeometry))
        .def("itemAt", pure_virtual(&QLayout::itemAt), return_value_policy<reference_existing_object>() )
        .def("takeAt", pure_virtual(&QLayout::takeAt), return_value_policy<reference_existing_object>() )
        .def("indexOf", &QLayout::indexOf, &PythonQLayout::__indexOf)
        .def("count", pure_virtual(&QLayout::count))
        .def("sizeHint", pure_virtual(&QLayoutItem::sizeHint))
        .def("isEmpty", (bool (QLayout::*)() const)&QLayout::isEmpty)
        .def("layout", (QLayout* (QLayout::*)() )&QLayout::layout, return_value_policy<reference_existing_object>() )
        .def("hasHeightForWidth", &QLayoutItem::hasHeightForWidth, &PythonQLayout::__hasHeightForWidth)
        .def("heightForWidth", &QLayoutItem::heightForWidth, &PythonQLayout::__heightForWidth)
        .def("minimumHeightForWidth", &QLayoutItem::minimumHeightForWidth, &PythonQLayout::__minimumHeightForWidth)
        .def("widget", &QLayoutItem::widget, &PythonQLayout::__widget, return_value_policy<reference_existing_object>() )
        .def("spacerItem", &QLayoutItem::spacerItem, &PythonQLayout::__spacerItem, return_value_policy<reference_existing_object>() )
        .def("setAlignment", (bool (QLayout::*)(QWidget*, Qt::Alignment) )&QLayout::setAlignment)
        .def("setAlignment", (bool (QLayout::*)(QLayout*, Qt::Alignment) )&QLayout::setAlignment)
        .def("setMenuBar", &QLayout::setMenuBar)
        .def("menuBar", &QLayout::menuBar, return_value_policy<reference_existing_object>() )
        .def("parentWidget", &QLayout::parentWidget, return_value_policy<reference_existing_object>() )
        .def("activate", &QLayout::activate)
        .def("update", &QLayout::update)
        .def("addWidget", &QLayout::addWidget)
        .def("removeWidget", &QLayout::removeWidget)
        .def("removeItem", &QLayout::removeItem)
        .def("totalHeightForWidth", &QLayout::totalHeightForWidth)
        .def("totalMinimumSize", &QLayout::totalMinimumSize)
        .def("totalMaximumSize", &QLayout::totalMaximumSize)
        .def("totalSizeHint", &QLayout::totalSizeHint)

        // protected in QLayout
        .def("addChildLayout", &PythonQLayout::__addChildLayout)
        .def("addChildWidget", &PythonQLayout::__addChildWidget)
        .def("alignmentRect", &PythonQLayout::__alignmentRect)

        // static methods
        .def("closestAcceptableSize", &QLayout::closestAcceptableSize)
        .staticmethod("closestAcceptableSize")
    );

    enum_< QLayout::SizeConstraint >("SizeConstraint")
        .value("SetMinAndMaxSize", QLayout::SetMinAndMaxSize)
        .value("SetMinimumSize", QLayout::SetMinimumSize)
        .value("SetFixedSize", QLayout::SetFixedSize)
        .value("SetDefaultConstraint", QLayout::SetDefaultConstraint)
        .value("SetNoConstraint", QLayout::SetNoConstraint)
        .value("SetMaximumSize", QLayout::SetMaximumSize)
        .export_values()
    ;

    delete QLayout_scope;
    
}
