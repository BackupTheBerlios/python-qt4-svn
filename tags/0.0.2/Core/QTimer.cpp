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
#include <boost/python/class.hpp>
#include <boost/python/with_custodian_and_ward.hpp>
#include <boost/shared_ptr.hpp>

#include <QtCore/QTimer>

using namespace boost::python;

void
export_QTimer()
{
    class_< QTimer,
            bases<QObject>,
            boost::shared_ptr<QTimer>,
            boost::noncopyable>
            ("QTimer", init<>() )
        // constructor
        .def(init<QObject*>()[with_custodian_and_ward<1,2>()])
        
        // properties
        .add_property("interval", &QTimer::interval, &QTimer::setInterval)
        .add_property("singleShot", &QTimer::isSingleShot, &QTimer::setSingleShot)        
        
        // methods
        .def("isActive", &QTimer::isActive)
        .def("timerId", &QTimer::timerId)        
        .def("start", (void (QTimer::*)(int)) &QTimer::start)
        .def("start", (void (QTimer::*)()) &QTimer::start)
        .def("stop", &QTimer::stop)
        
        //.def("singleShot", &QTimer::singleShot)
        //.staticmethod("singleShot")
    ;
}

