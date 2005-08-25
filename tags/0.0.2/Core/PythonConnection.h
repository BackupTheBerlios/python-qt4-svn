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

#include <QMap>
#include <QString>
#include <QSize>
#include <QRect>
#include <QPoint>
#include <QTextCursor>
#include <QObject>


using boost::python::object;

class AbstractPythonSlot
{
protected:
    object* _method;
public:
    AbstractPythonSlot(object* method);
    virtual ~AbstractPythonSlot();
};

struct AbstractPythonSlotFactory
{
    virtual QObject* create(object* method) = 0;
    virtual ~AbstractPythonSlotFactory() {}
};

typedef QMap<QString, AbstractPythonSlotFactory*> FactoryMap;
void register_slot_factories(FactoryMap& slot_registry);

// ----------------------------------------------------------------------------

struct PythonSlotFactory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot(object* slot);

public slots:
    void callback();
};

// ----------------------------------------------------------------------------



struct PythonSlot_bool_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_bool: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_bool(object* slot);

public slots:
    void callback(bool);
};

// ----------------------------------------------------------------------------



struct PythonSlot_int_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_int: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_int(object* slot);

public slots:
    void callback(int);
};

// ----------------------------------------------------------------------------



struct PythonSlot_double_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_double: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_double(object* slot);

public slots:
    void callback(double);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QString_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QString: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QString(object* slot);

public slots:
    void callback(QString);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QSize_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QSize: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QSize(object* slot);

public slots:
    void callback(QSize);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QRect_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QRect: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QRect(object* slot);

public slots:
    void callback(QRect);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QPoint_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QPoint: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QPoint(object* slot);

public slots:
    void callback(QPoint);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QTextCursor_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QTextCursor: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QTextCursor(object* slot);

public slots:
    void callback(QTextCursor);
};

// ----------------------------------------------------------------------------



struct PythonSlot_QObject_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_QObject: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_QObject(object* slot);

public slots:
    void callback(QObject*);
};

// ----------------------------------------------------------------------------



struct PythonSlot_int_int_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_int_int: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_int_int(object* slot);

public slots:
    void callback(int,int);
};

// ----------------------------------------------------------------------------



struct PythonSlot_int_int_int_Factory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot_int_int_int: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot_int_int_int(object* slot);

public slots:
    void callback(int,int,int);
};

// ----------------------------------------------------------------------------



#endif

