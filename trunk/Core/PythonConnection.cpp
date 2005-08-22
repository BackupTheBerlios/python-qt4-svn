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

PythonSlot::PythonSlot(object* method)
{
    _method = new object(*method);
}


QObject*
PythonSlot0Factory::create(QObject* reciever, object* method)
{
    return new PythonSlot0(reciever, method);
}

PythonSlot0::PythonSlot0(QObject* reciever, object* method):
    QObject(reciever), PythonSlot(method)
{
}

void
PythonSlot0::callback()
{
    (*_method)();
}





// ---------------------------------------------------------------------------
PythonConnection::PythonConnection(QObject* sender, object* slot):
    //PythonSlot* slot): //, boost::python::object slot):
    QObject(sender) //, _slot(slot)
{
    _slot = new boost::python::object(*slot);
    qDebug("_slot: %p", _slot->ptr());
    //boost::python::incref(_slot.ptr());
}


// PythonConnection::~PythonConnection()
// {
//     qDebug("Connection deleted");
// }


void
PythonConnection::callback()
{
    qDebug("Callback %d", sizeof(PythonConnection));
    qDebug("_slot: %p", _slot->ptr());
    //boost::python::object slot = *_slot;
    (*_slot)();
}


