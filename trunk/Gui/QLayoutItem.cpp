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

#include <QLayoutItem>
//#include <string>

using namespace boost::python;


struct QLayoutItem_Wrapper: QLayoutItem, wrapper<QLayoutItem>
{
    QLayoutItem_Wrapper(Qt::Alignment p0=0): QLayoutItem(p0) {}

    QSize
    sizeHint() const
    {
        return this->get_override("sizeHint")();
    }

    QSize
    minimumSize() const
    {
        return this->get_override("minimumSize")();
    }

    QSize
    maximumSize() const
    {
        return this->get_override("maximumSize")();
    }

    Qt::Orientations
    expandingDirections() const
    {
        return this->get_override("expandingDirections")();
    }

    void
    setGeometry(const QRect& p0)
    {
        this->get_override("setGeometry")(p0);
    }

    QRect
    geometry() const
    {
        return this->get_override("geometry")();
    }

    bool
    isEmpty() const
    {
        return this->get_override("isEmpty")();
    }

/*    bool
    hasHeightForWidth() const
    {
        return call_method< bool >(py_self, "hasHeightForWidth");
        return this->get_override("minimumSize")();
    }

    bool
    default_hasHeightForWidth() const
    {
        return QLayoutItem::hasHeightForWidth();
        return this->get_override("minimumSize")();
    }

    int
    heightForWidth(int p0) const
    {
        return call_method< int >(py_self, "heightForWidth", p0);
        return this->get_override("minimumSize")();
    }

    int
    default_heightForWidth(int p0) const
    {
        return QLayoutItem::heightForWidth(p0);
        return this->get_override("minimumSize")();
    }*/

/*    int
    minimumHeightForWidth(int p0) const
    {
        return call_method< int >(py_self, "minimumHeightForWidth", p0);
        return this->get_override("minimumSize")();
    }

    int
    default_minimumHeightForWidth(int p0) const
    {
        return QLayoutItem::minimumHeightForWidth(p0);
        return this->get_override("minimumSize")();
    }*/

/*    void
    invalidate()
    {
        call_method< void >(py_self, "invalidate");
    }

    void
    default_invalidate()
    {
        QLayoutItem::invalidate();
    }
*/

/*    QWidget*
    widget()
    {
        return call_method< QWidget* >(py_self, "widget");
        return this->get_override("minimumSize")();
    }

    QWidget*
    default_widget()
    {
        return QLayoutItem::widget();
        return this->get_override("minimumSize")();
    }

    QLayout*
    layout()
    {
        return call_method< QLayout* >(py_self, "layout");
        return this->get_override("minimumSize")();
    }

    QLayout*
    default_layout()
    {
        return QLayoutItem::layout();
        return this->get_override("minimumSize")();
    }

    QSpacerItem*
    spacerItem()
    {
        return call_method< QSpacerItem* >(py_self, "spacerItem");
        return this->get_override("minimumSize")();
    }

    QSpacerItem*
    default_spacerItem()
    {
        return QLayoutItem::spacerItem();
        return this->get_override("spacerItem")();
    }*/
};

void
export_QLayoutItem()
{
    class_< QLayoutItem_Wrapper,
            boost::shared_ptr<QLayoutItem_Wrapper>,
            boost::noncopyable >
            ("QLayoutItem",
                init< optional< Qt::Alignment > >() )
        .def("sizeHint", pure_virtual(&QLayoutItem::sizeHint))
        .def("minimumSize", pure_virtual(&QLayoutItem::minimumSize))
        .def("maximumSize", pure_virtual(&QLayoutItem::maximumSize))
        .def("expandingDirections", pure_virtual(&QLayoutItem::expandingDirections))
        .def("setGeometry", pure_virtual(&QLayoutItem::setGeometry))
        .def("geometry", pure_virtual(&QLayoutItem::geometry))
        .def("isEmpty", pure_virtual(&QLayoutItem::isEmpty))
        /*.def("hasHeightForWidth", &QLayoutItem::hasHeightForWidth, &QLayoutItem_Wrapper::default_hasHeightForWidth)
        .def("heightForWidth", &QLayoutItem::heightForWidth, &QLayoutItem_Wrapper::default_heightForWidth)
        .def("minimumHeightForWidth", &QLayoutItem::minimumHeightForWidth, &QLayoutItem_Wrapper::default_minimumHeightForWidth)
        .def("invalidate", &QLayoutItem::invalidate, &QLayoutItem_Wrapper::default_invalidate)
        .def("widget", &QLayoutItem::widget, &QLayoutItem_Wrapper::default_widget)
        .def("layout", &QLayoutItem::layout, &QLayoutItem_Wrapper::default_layout)
        .def("spacerItem", &QLayoutItem::spacerItem, &QLayoutItem_Wrapper::default_spacerItem)
        .def("alignment", &QLayoutItem::alignment)
        .def("setAlignment", &QLayoutItem::setAlignment)
        */
    ;
}
