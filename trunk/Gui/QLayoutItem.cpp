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

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
//#include <memory>

#include <QWidget>
#include <QLayout>
#include <QLayoutItem>
//#include <string>
#include <Wrapper.h>

using namespace boost::python;

WRAPPER(QLayoutItem, PythonQLayoutItem)
{
    PythonQLayoutItem(Qt::Alignment p1=0): QLayoutItem(p1) {}

    // virtual in QLayoutItem
    PURE_VIRTUAL_0(QFlags<Qt::Orientation>,, expandingDirections, const);
    PURE_VIRTUAL_0(QRect,, geometry, const);
    PURE_VIRTUAL_1(void, (void), setGeometry, const QRect&,);
    PURE_VIRTUAL_0(bool,, isEmpty, const);
    PURE_VIRTUAL_0(QSize,, maximumSize, const);
    PURE_VIRTUAL_0(QSize,, minimumSize, const);
    PURE_VIRTUAL_0(QSize,, sizeHint, const);
    VIRTUAL_0(bool,, hasHeightForWidth, const);
    VIRTUAL_1(int,, heightForWidth, int, const);
    VIRTUAL_1(int,, minimumHeightForWidth, int, const);
    VIRTUAL_0(void, (void), invalidate,);
    VIRTUAL_0(QLayout*,, layout,);
    VIRTUAL_0(QSpacerItem*,, spacerItem,);
    VIRTUAL_0(QWidget*,, widget,);
};

void
export_QLayoutItem()
{
    class_< PythonQLayoutItem,
            boost::shared_ptr<PythonQLayoutItem>,
            boost::noncopyable >
            ("QLayoutItem",
                init<>() )
        .def(init<Qt::Alignment>())
                
        // pure virtual methods
        .def("sizeHint", pure_virtual(&QLayoutItem::sizeHint))
        .def("minimumSize", pure_virtual(&QLayoutItem::minimumSize))
        .def("maximumSize", pure_virtual(&QLayoutItem::maximumSize))
        .def("expandingDirections", pure_virtual(&QLayoutItem::expandingDirections))
        .def("setGeometry", pure_virtual(&QLayoutItem::setGeometry))
        .def("geometry", pure_virtual(&QLayoutItem::geometry))
        .def("isEmpty", pure_virtual(&QLayoutItem::isEmpty))

        // virtual methods
        .def("hasHeightForWidth", &QLayoutItem::hasHeightForWidth, &PythonQLayoutItem::__hasHeightForWidth)
        .def("heightForWidth", &QLayoutItem::heightForWidth, &PythonQLayoutItem::__heightForWidth)
        .def("minimumHeightForWidth", &QLayoutItem::minimumHeightForWidth, &PythonQLayoutItem::__minimumHeightForWidth)
        .def("invalidate", &QLayoutItem::invalidate, &PythonQLayoutItem::__invalidate)
        .def("widget", &QLayoutItem::widget, &PythonQLayoutItem::__widget, return_value_policy<reference_existing_object>() )
        .def("layout", &QLayoutItem::layout, &PythonQLayoutItem::__layout, return_value_policy<reference_existing_object>() )
        .def("spacerItem", &QLayoutItem::spacerItem, &PythonQLayoutItem::__spacerItem, return_value_policy<reference_existing_object>())

        // methods
        .def("alignment", &QLayoutItem::alignment)
        .def("setAlignment", &QLayoutItem::setAlignment)
    ;
}
