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

#include <QtWrapper.h>
#include <parent_change_policy.h>

#include <QtGui/QLCDNumber>

using namespace boost::python;

QOBJECT_WRAPPER(QLCDNumber, PythonQLCDNumber)
{
    PYTHON_QOBJECT;
    PythonQLCDNumber(QWidget* parent=0): QLCDNumber(parent) {}
    PythonQLCDNumber(uint numDigits, QWidget* parent=0): QLCDNumber(numDigits, parent) {}    
};

void
export_QLCDNumber()
{
    scope* QLCDNumber_scope = new scope(
    class_< PythonQLCDNumber,
            bases<QFrame> ,
            boost::shared_ptr<PythonQLCDNumber>,
            boost::noncopyable>
            ("QLCDNumber", init< optional<QWidget*> >(args("parent")) [parent_change_policy<>()] )
        .def(init<uint, optional<QWidget*> >(args("numDigits","parent"))[parent_change_policy<>()] )

        // properties
        .add_property("intValue", &QLCDNumber::intValue, (void (QLCDNumber::*)(int) )&QLCDNumber::display)
        .add_property("mode", &QLCDNumber::mode, &QLCDNumber::setMode)
        .add_property("numDigits", &QLCDNumber::numDigits, &QLCDNumber::setNumDigits)
        .add_property("segmentStyle", &QLCDNumber::segmentStyle, &QLCDNumber::setSegmentStyle)
        .add_property("smallDecimalPoint", &QLCDNumber::smallDecimalPoint, &QLCDNumber::setSmallDecimalPoint)
        .add_property("value", &QLCDNumber::value, (void (QLCDNumber::*)(double) )&QLCDNumber::display)

        // methods
        .def("checkOverflow", (bool (QLCDNumber::*)(double) const)&QLCDNumber::checkOverflow)
        .def("checkOverflow", (bool (QLCDNumber::*)(int) const)&QLCDNumber::checkOverflow)
        .def("display", (void (QLCDNumber::*)(const QString&) )&QLCDNumber::display)
        .def("display", (void (QLCDNumber::*)(int) )&QLCDNumber::display)
        .def("display", (void (QLCDNumber::*)(double) )&QLCDNumber::display)
        .def("setHexMode", &QLCDNumber::setHexMode)
        .def("setDecMode", &QLCDNumber::setDecMode)
        .def("setOctMode", &QLCDNumber::setOctMode)
        .def("setBinMode", &QLCDNumber::setBinMode)
    );

    enum_<QLCDNumber::Mode>("Mode")
        .value("Bin", QLCDNumber::Bin)
        .value("Dec", QLCDNumber::Dec)
        .value("Hex", QLCDNumber::Hex)
        .value("Oct", QLCDNumber::Oct)
        .export_values()
    ;

    enum_<QLCDNumber::SegmentStyle>("SegmentStyle")
        .value("Flat", QLCDNumber::Flat)
        .value("Outline", QLCDNumber::Outline)
        .value("Filled", QLCDNumber::Filled)
        .export_values()
    ;

    delete QLCDNumber_scope;
}