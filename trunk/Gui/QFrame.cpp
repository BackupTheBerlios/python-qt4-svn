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
#include <boost/shared_ptr.hpp>
#include <boost/python/class.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/scope.hpp>

#include <PythonQObject.h>

#include <QtGui/QFrame>

using namespace boost::python;

struct PythonQFrame: QFrame, 
                     wrapper<QFrame>,
                     qtwrapper<QFrame, PythonQFrame>
{
    PYTHON_QOBJECT;
    
    PythonQFrame(QWidget* parent=0, Qt::WFlags f=0): QFrame(parent, f) {}
};

void
export_QFrame()
{
    scope* QFrame_scope = new scope(
    class_< PythonQFrame,
            bases<QWidget>,
            boost::shared_ptr<PythonQFrame>,
            boost::noncopyable>
            ("QFrame", init<>() )
        .def(init<QWidget*>()[with_custodian_and_ward<1,2>()] )
        .def(init<QWidget*, Qt::WFlags>()[with_custodian_and_ward<1,2>()] )

        // properties
        .add_property("frameRect", &QFrame::frameRect, &QFrame::setFrameRect)
        .add_property("frameShadow", &QFrame::frameShadow, &QFrame::setFrameShadow)
        .add_property("frameShape", &QFrame::frameShape, &QFrame::setFrameShape)
        .add_property("frameWidth", &QFrame::frameWidth)
        .add_property("lineWidth", &QFrame::lineWidth, &QFrame::setLineWidth)
        .add_property("midLineWidth", &QFrame::midLineWidth, &QFrame::setMidLineWidth)

        // methods
        .def("frameStyle", &QFrame::frameStyle)
        .def("setFrameStyle", &QFrame::setFrameStyle)
    ); 

    enum_<QFrame::Shape>("Shape")
        .value("Box", QFrame::Box)
        .value("NoFrame", QFrame::NoFrame)
        .value("StyledPanel", QFrame::StyledPanel)
        .value("HLine", QFrame::HLine)
        .value("VLine", QFrame::VLine)
        .value("WinPanel", QFrame::WinPanel)
        .value("Panel", QFrame::Panel)
        .export_values()
    ;

    enum_<QFrame::Shadow>("Shadow")
        .value("Plain", QFrame::Plain)
        .value("Raised", QFrame::Raised)
        .value("Sunken", QFrame::Sunken)
        .export_values()
    ;

    scope().attr("Shape_Mask") = (int)QFrame::Shape_Mask;
    scope().attr("Shadow_Mask") = (int)QFrame::Shadow_Mask;

    delete QFrame_scope;
}