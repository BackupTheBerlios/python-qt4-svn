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

//#include <boost/python/module.hpp>
#include <boost/python/to_python_converter.hpp>
#include <boost/python/enum.hpp>

#include <QtCore/Qt>
#include <QtCore/QFlags>

using namespace boost::python;

struct QFlags_MouseButton_to_python_str
{
    static PyObject*
    convert(QFlags<Qt::MouseButton> _flags)
    {
        int flags = _flags;
        return boost::python::incref(boost::python::object(flags).ptr());
    }
};

void
export_QFlags()
{
    to_python_converter<QFlags<Qt::MouseButton>, QFlags_MouseButton_to_python_str>();

    enum_<Qt::AlignmentFlag>("AlignmentFlag")
        .value("AlignLeft", Qt::AlignLeft)
        .value("AlignRight", Qt::AlignRight)
        .value("AlignHCenter", Qt::AlignHCenter)
        .value("AlignJustify", Qt::AlignJustify)
        .value("AlignTop", Qt::AlignTop)
        .value("AlignBottom", Qt::AlignBottom)
        .value("AlignVCenter", Qt::AlignVCenter)
        .value("AlignCenter", Qt::AlignCenter)
        .value("AlignAbsolute", Qt::AlignAbsolute)
        .value("AlignLeading", Qt::AlignLeading)
        .value("AlignTrailing", Qt::AlignTrailing)
        .value("AlignHorizontal_Mask", Qt::AlignHorizontal_Mask)
        .value("AlignVertical_Mask", Qt::AlignVertical_Mask)
        //.export_values()
        ;

    enum_<Qt::KeyboardModifier>("KeyboardModifier")
        .value("NoModifier", Qt::NoModifier)
        .value("ShiftModifier", Qt::ShiftModifier)
        .value("ControlModifier", Qt::ControlModifier)
        .value("AltModifier", Qt::AltModifier)
        .value("MetaModifier", Qt::MetaModifier)
        .value("KeypadModifier", Qt::KeypadModifier)
    ;
    
    enum_<Qt::MouseButton>("MouseButton")
        .value("NoButton", Qt::NoButton)
        .value("LeftButton", Qt::LeftButton)
        .value("RightButton", Qt::RightButton)
        .value("MidButton", Qt::MidButton)
        .value("XButton1", Qt::XButton1)
        .value("XButton2", Qt::XButton2)
    ;
}
