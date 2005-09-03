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

#ifndef PYTHONQOBJECT_H
#define PYTHONQOBJECT_H

#include <boost/python.hpp>
#include <QMetaObject>
#include <QObject>
#include <QMap>
#include <QByteArray>
#include <string.h>
#include "PyMoc.h"

/// @macro: PYTHON_QOBJECT
/// This macro is similiar to Q_OBJECT macro, but is intended for creating a
/// Python QObject, instead of regular QObject. PythonQObjects are QObjects
/// exposed to Python with Boost, and with special "meta"-functions.
/// With this, we can make a Python object reflect its features like
/// Signals, Slots and Properties to the Qt MetaObject system.
/// 
#define PYTHON_QOBJECT \
public: \
    static const QMetaObject staticMetaObject;\
    virtual int \
    qt_metacall(QMetaObject::Call c, int i, void** a) \
    { return python_qt_metacall(this, c, i, a); } \
    virtual void* qt_metacast(const char* _clname) \
    { return python_qt_metacast(this, _clname); } \
    virtual const QMetaObject* metaObject() const \
    { return python_metaObject(); }  \

namespace python = boost::python;
    
struct abstractwrapper {
    virtual void addDynamicMethod(QString signature, QString name, QList<QString> params, python::object method) = 0;
};
    
template <typename QParent, typename QWrapper>
struct qtwrapper: abstractwrapper
{
    typedef struct {
        QString name;
        QList<QString> params;
    } DynamicMethod;

    qtwrapper():
        python_qt_meta_data(0),
        python_qt_meta_stringdata(0)
    {
        className = QString("Python")+QString(QParent::staticMetaObject.className());
        updateDynamicMetaObject();
        qDebug("-----------------------------------------------------");
        QList<QString> params1;
        QList<QString> params2;
        params2 << "int";
        QList<QString> params3;        
        params2 << "int" << "int";
        addDynamicMethod("changed()", "changed", params1, python::object());
        addDynamicMethod("valueChanged(int)", "valueChanged", params2, python::object());
        addDynamicMethod("textChanged(int,int)", "textChanged", params3, python::object());        
        qDebug("-----------------------------------------------------");
    }

    void
    addDynamicMethod(QString signature, QString name, QList<QString> params, boost::python::object method)
    {
        DynamicMethod dynamicMethod;
        dynamicMethod.name = name;
        dynamicMethod.params = params;
        dynamicMethodMap[signature] = dynamicMethod;
        qDebug("added: %s", signature.toStdString().c_str());
        updateDynamicMetaObject();
    }
    
    void
    updateDynamicMetaObject()
    {
        delete[] python_qt_meta_data;
        //delete[] python_qt_meta_stringdata;
        idSignatureMap.clear();
        
        int m = dynamicMethodMap.size();
        // 10(reserved) + 5*methods + 3*properties + 1(null)
        int size = 10 + 5*m /*+ 3*p */ + 1;
        uint* data = new uint[size];        
        // revision
        data[0] = 1;
        // class name offset
        data[1] = 0;
        // class info number and offset
        data[2] = 0;
        data[3] = 0;
        // method number and offset
        data[4] = m;
        data[5] = 10;
        // property number and offset
        data[6] = 0;
        data[7] = 0;
        // enums/set number and offset
        data[8] = 0;
        data[9] = 0;

        buffer.clear();
        buffer.append(className);
        buffer.append('\0');
        int offset = 10;
        int nil = className.size();
        //int string_offset = nil+1;

        // build the string
        int id=0;        
        QMapIterator<QString, DynamicMethod> i(dynamicMethodMap);
        while (i.hasNext()) 
        {
            i.next();
            data[offset] = buffer.size();
            data[offset+1] = nil;
            data[offset+2] = nil; 
            data[offset+3] = nil;
            data[offset+4] = MethodSlot|AccessPublic;
            idSignatureMap[id++] = i.key();
            buffer.append(i.key());
            buffer.append('\0');
            id++;
            offset += 5;
        }        
        
        // eod (end of data)
        data[id] = 0;
        
        // allocate the string
        python_qt_meta_stringdata = buffer.constData();
        python_qt_meta_data = data;
        
        QMetaObject auxMetaObject = { 
            { &QParent::staticMetaObject, python_qt_meta_stringdata,
            python_qt_meta_data, 0 } 
        };
        dynamicMetaObject = auxMetaObject;
    }
    
    int 
    python_qt_metacall(QParent* obj, QMetaObject::Call _c, int _id, void** _a)
    {
        qDebug("python_qt_metacall: (%d, %d)", _c, _id);
        int id = obj->QParent::qt_metacall(_c, _id, _a);
        if ( id < 0 ) {
            return id;
        }
        else if ( id < idSignatureMap.size() ) {
            qDebug("invoked: %d -> %s", id, idSignatureMap[id].toStdString().c_str() );
        }
        id -= idSignatureMap.size();
        return id;
    }

    void*
    python_qt_metacast(QWrapper* obj, const char *_clname)
    {
        qDebug("python_qt_metacast: (%p, %s)", obj, _clname);
        if (!_clname) {       
            return 0;
        }
        if (!strcmp(_clname, python_qt_meta_stringdata)) {
            return static_cast<void*>(const_cast<QWrapper*>(obj));
        }
        return obj->QParent::qt_metacast(_clname);
    }

    const QMetaObject*
    python_metaObject() const
    {
        qDebug("python_metaObject");
        return &dynamicMetaObject;
    }    

protected:
    // signature -> {name, [arg0, arg1, ...] }
    QMap<QString, DynamicMethod> dynamicMethodMap;
    
    // id -> signature
    QMap<int, QString> idSignatureMap;
    
private:
    QMetaObject dynamicMetaObject;
    QString className;
    const uint *python_qt_meta_data;
    const char *python_qt_meta_stringdata;
    QByteArray buffer;
};

#endif
