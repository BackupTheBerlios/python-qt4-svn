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

AbstractPythonSlot::AbstractPythonSlot(object* method)
{
    _method = new object(*method);
}


AbstractPythonSlot::~AbstractPythonSlot()
{
    delete _method; 
}

// ----------------------------------------------------------------------------

QObject*
PythonSlotFactory::create(object* method)
{
    return new PythonSlot(method);
}

PythonSlot::PythonSlot(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot::callback()
{
    (*_method)();
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_bool_Factory::create(object* method)
{
    return new PythonSlot_bool(method);
}

PythonSlot_bool::PythonSlot_bool(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_bool::callback(bool p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_int_Factory::create(object* method)
{
    return new PythonSlot_int(method);
}

PythonSlot_int::PythonSlot_int(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_int::callback(int p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_double_Factory::create(object* method)
{
    return new PythonSlot_double(method);
}

PythonSlot_double::PythonSlot_double(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_double::callback(double p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QString_Factory::create(object* method)
{
    return new PythonSlot_QString(method);
}

PythonSlot_QString::PythonSlot_QString(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QString::callback(QString p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QSize_Factory::create(object* method)
{
    return new PythonSlot_QSize(method);
}

PythonSlot_QSize::PythonSlot_QSize(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QSize::callback(QSize p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QRect_Factory::create(object* method)
{
    return new PythonSlot_QRect(method);
}

PythonSlot_QRect::PythonSlot_QRect(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QRect::callback(QRect p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QPoint_Factory::create(object* method)
{
    return new PythonSlot_QPoint(method);
}

PythonSlot_QPoint::PythonSlot_QPoint(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QPoint::callback(QPoint p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QTextCursor_Factory::create(object* method)
{
    return new PythonSlot_QTextCursor(method);
}

PythonSlot_QTextCursor::PythonSlot_QTextCursor(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QTextCursor::callback(QTextCursor p0)
{
    (*_method)(p0);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_QObject_Factory::create(object* method)
{
    return new PythonSlot_QObject(method);
}

PythonSlot_QObject::PythonSlot_QObject(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_QObject::callback(QObject* p0)
{
    (*_method)(ptr(p0));
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_int_int_Factory::create(object* method)
{
    return new PythonSlot_int_int(method);
}

PythonSlot_int_int::PythonSlot_int_int(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_int_int::callback(int p0,int p1)
{
    (*_method)(p0,p1);
}

// ----------------------------------------------------------------------------


QObject*
PythonSlot_int_int_int_Factory::create(object* method)
{
    return new PythonSlot_int_int_int(method);
}

PythonSlot_int_int_int::PythonSlot_int_int_int(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot_int_int_int::callback(int p0,int p1,int p2)
{
    (*_method)(p0,p1,p2);
}

// ----------------------------------------------------------------------------

