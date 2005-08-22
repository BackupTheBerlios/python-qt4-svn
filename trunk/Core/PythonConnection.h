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

#ifndef PYTHONCONNECTION_H
#define PYTHONCONNECTION_H

#include <boost/python/object_fwd.hpp>

#include <QObject>

/**
@author Eric Jardim
*/

using boost::python::object;

class PythonSlot
{
protected:
    object* _method;
public:
    PythonSlot(object* method);
    virtual ~PythonSlot() { delete _method; }
};


struct PythonSlotFactory
{
    virtual QObject* create(QObject* reciever, object* method) = 0;
    virtual ~PythonSlotFactory() {}
};


struct PythonSlot0Factory: PythonSlotFactory
{
    virtual QObject* create(QObject* reciever, object* method);
};


class PythonSlot0: public QObject, public PythonSlot
{
    Q_OBJECT
public:
    PythonSlot0(QObject* reciever, object* slot);

public slots:
    void callback();
};


template<typename T1>
class PythonSlot1
{
    PythonSlot1(QObject* sender, object* slot)
    {
    }
};

class PythonConnection: public QObject
{
    Q_OBJECT

public:
    //boost::python::object _slot;
    boost::python::object* _slot;
    
public:
    PythonConnection(QObject* sender, object* slot); //PythonSlot* slot); //, boost::python::object slot);
    //virtual ~PythonConnection();

public slots:
    void callback();
    
};

#endif
