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
#include <PythonQt.h>

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
    typedef QParent Parent;
    typedef struct {
        QString name;
        QList<QString> params;
        python::object method;
    } DynamicMethod;

    qtwrapper():
        python_qt_meta_data(0),
        python_qt_meta_stringdata(0)
    {
        className = QString("Python")+QString(QParent::staticMetaObject.className());
        updateDynamicMetaObject();
    }
  
    void
    addDynamicMethod(QString signature, QString name, QList<QString> params, boost::python::object method)
    {
        DynamicMethod dynamicMethod;
        dynamicMethod.name = name;
        dynamicMethod.params = params;
        dynamicMethod.method = method;
        dynamicMethodMap[signature] = dynamicMethod;
        //qDebug("added: %s", signature.toStdString().c_str());
        updateDynamicMetaObject();
    }
    
    void
    updateDynamicMetaObject()
    {
        delete[] python_qt_meta_data;
        buffer.clear();
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
            idSignatureMap[id] = i.key();
            buffer.append(i.key());
            buffer.append('\0');
            id++;
            offset += 5;
        }        
        
        // eod (end of data)
        data[offset] = 0;
        
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
        //qDebug("python_qt_metacall: (%d, %d)", _c, _id);
        int id = obj->QParent::qt_metacall(_c, _id, _a);
        if ( id < 0 ) {
            return id;
        }
        else if ( id < idSignatureMap.size() ) {
            QString signature = idSignatureMap[id];
            //qDebug("invoked: %d -> %s", id, signature.toStdString().c_str() );
            DynamicMethod dynamicMethod = dynamicMethodMap[signature];
            QList<python::object> pyparams;
            for (int i=0; i<dynamicMethod.params.size(); i++)
            {
                pyparams.append( PythonQt::convert(dynamicMethod.params[i], _a[i+1]) );
            }
            switch(dynamicMethod.params.size())
            {
                case 0: dynamicMethod.method(); break;
                case 1: dynamicMethod.method(pyparams[0]); break;
                default: dynamicMethod.method(pyparams[0], pyparams[1]); break;
            }
            
        }
        id -= idSignatureMap.size();
        return id;
    }

    void*
    python_qt_metacast(QWrapper* obj, const char *_clname)
    {
        //qDebug("python_qt_metacast: (%p, %s)", obj, _clname);
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
        //qDebug("python_metaObject");
        return &dynamicMetaObject;
    }    
    
private:
    // signature -> {name, [arg0, arg1, ...] }
    QMap<QString, DynamicMethod> dynamicMethodMap;    
    // id -> signature
    QMap<int, QString> idSignatureMap;    
    QMetaObject dynamicMetaObject;
    QString className;
    const uint *python_qt_meta_data;
    const char *python_qt_meta_stringdata;
    QByteArray buffer;
};

#endif
