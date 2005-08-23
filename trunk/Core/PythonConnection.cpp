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

#include "PythonConnection.h"
#include <boost/python/object.hpp>

using namespace boost::python;

// ----------------------------------------------------------------------------

PythonSlot::PythonSlot(object* method)
{
    _method = new object(*method);
}


PythonSlot::~PythonSlot()
{
    delete _method; 
}

// ----------------------------------------------------------------------------

QObject*
PythonSlot0Factory::create(object* method)
{
    return new PythonSlot0(method);
}

PythonSlot0::PythonSlot0(object* method):
    QObject(0), PythonSlot(method)
{
}

void
PythonSlot0::callback()
{
    (*_method)();
}

// ----------------------------------------------------------------------------

QObject*
PythonSlot1_bool_Factory::create(object* method)
{
    return new PythonSlot1_bool(method);
}

PythonSlot1_bool::PythonSlot1_bool(object* method):
    QObject(0), PythonSlot(method)
{
}

void
PythonSlot1_bool::callback(bool p0)
{
    (*_method)(p0);
}

