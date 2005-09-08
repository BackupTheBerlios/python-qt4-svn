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

#include <boost/python/scope.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/reference_existing_object.hpp>

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtCore/QChildEvent>

using namespace boost::python;


void export_QChildEvent()
{
   class_<QChildEvent,
          bases<QEvent>,
          boost::shared_ptr<QChildEvent>,
          boost::noncopyable>
   ("QChildEvent", init<QEvent::Type, QObject*>())
        .def("added", &QChildEvent::added)
        .def("child", &QChildEvent::child, return_value_policy<reference_existing_object>())
        .def("polished", &QChildEvent::polished)
        .def("removed", &QChildEvent::removed)
    ;
}

