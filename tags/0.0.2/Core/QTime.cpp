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
#include <boost/python/class.hpp>
#include <boost/python/with_custodian_and_ward.hpp>
#include <boost/shared_ptr.hpp>

#include <QtCore/QTime>

using namespace boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QTime_toString_overloads_0_1, toString, 0, 1);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QTime_setHMS_overloads_3_4, setHMS, 3, 4);
BOOST_PYTHON_FUNCTION_OVERLOADS(QTime_fromString_overloads_1_2, QTime::fromString, 1, 2);
BOOST_PYTHON_FUNCTION_OVERLOADS(QTime_isValid_overloads_3_4, QTime::isValid, 3, 4);

void
export_QTime()
{
    class_< QTime,
            boost::shared_ptr<QTime> >
            ("QTime", init<>() )
        .def(init<int,int,optional<int,int> >() )
        
        .def("isNull", &QTime::isNull)
        .def("isValid", (bool (QTime::*)() const)&QTime::isValid)
        .def("hour", &QTime::hour)
        .def("minute", &QTime::minute)
        .def("second", &QTime::second)
        .def("msec", &QTime::msec)
        .def("toString", (QString (QTime::*)(Qt::DateFormat) const)&QTime::toString, QTime_toString_overloads_0_1())
        .def("toString", (QString (QTime::*)(const QString&) const)&QTime::toString)
        .def("setHMS", &QTime::setHMS, QTime_setHMS_overloads_3_4())
        .def("addSecs", &QTime::addSecs)
        .def("secsTo", &QTime::secsTo)
        .def("addMSecs", &QTime::addMSecs)
        .def("msecsTo", &QTime::msecsTo)
        .def("start", &QTime::start)
        .def("restart", &QTime::restart)
        .def("elapsed", &QTime::elapsed)

        // static methods
        .def("fromString", (QTime (*)(const QString&, Qt::DateFormat))&QTime::fromString, QTime_fromString_overloads_1_2())
        .def("fromString", (QTime (*)(const QString&, const QString&))&QTime::fromString)
        .staticmethod("fromString")
        
        .def("isValid", (bool (*)(int, int, int, int))&QTime::isValid, QTime_isValid_overloads_3_4())
        .staticmethod("isValid")
        
        .def("currentTime", &QTime::currentTime)
        .staticmethod("currentTime")
        
        //.def( other< QDataStream >() >> self )
        //.def( other< QDebug >() << self )
        //.def( other< QDataStream >() << self )

        // operators
        .def( self == self )
        .def( self != self )
        .def( self < self )
        .def( self <= self )
        .def( self > self )
        .def( self >= self )
    ;
}
