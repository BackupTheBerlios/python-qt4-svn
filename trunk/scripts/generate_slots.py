# this scripts generates the PythonConnection.h and PythonConnection.cpp 
# files based on a list of signatures

# __alias__ = {
#     'const QString &': 'QString',
#     'const QSize &': 'QSize',
#     'const QRect &': 'QRect',
#     'const QPoint &': 'QPoint',
#     'const QTextCursor &': 'QTextCursor',
#     'QObject*':'QObject'
# }

__signtures__ = [ 
    ['bool'],
    ['int'],
    ['double'],
    ['QString'],
    ['QSize'],
    ['QRect'],
    ['QPoint'],
    ['QTextCursor'],
    ['QObject*'],
    ['int', 'int'],
    ['int', 'int', 'int']
]

def alias(s):
    if __alias__.has_key(s):
        return __alias__[s]
    else:
        return s


for sig in __signtures__:
    print sig
    

license = """
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
"""
    
h_pre = """
#ifndef PYTHONCONNECTION_H
#define PYTHONCONNECTION_H

#include <boost/python/object_fwd.hpp>

#include <QObject>

using boost::python::object;

class PythonSlot
{
protected:
    object* _method;
public:
    PythonSlot(object* method);
    virtual ~PythonSlot();
};

struct PythonSlotFactory
{
    virtual QObject* create(object* method) = 0;
    virtual ~PythonSlotFactory() {}
};

// ----------------------------------------------------------------------------

struct PythonSlot0Factory: PythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot0: public QObject, public PythonSlot
{
    Q_OBJECT
public:
    PythonSlot0(object* slot);

public slots:
    void callback();
};

// ----------------------------------------------------------------------------

"""

h_tmpl = """
struct PythonSlot%sFactory: PythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot%s: public QObject, public PythonSlot
{
    Q_OBJECT
public:
    PythonSlot%s(object* slot);

public slots:
    void callback(%s);
};

// ----------------------------------------------------------------------------

"""


cpp_pre = """
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
"""

reg_pre = """
slot_registry["()"] = new PythonSlot0Factory;
"""
########################################################33#####################

def pod_ptr(arg, ptr=False):
    if arg[-1] == '*' and not ptr:
        return arg[:-1]
    else:
        return arg

def signature(args, sep=',', pre='', pos='', ptr=False):
    if len(args) == 1:
        ret = pod_ptr(args[0], ptr)
    else:
        ret = ''
        for i in range(len(args)):
            arg = pod_ptr(args[i], ptr)
            ret += arg+sep
        ret = ret[:-1]
    return pre+ret+pos
    
h_file = open('PythonConnection.h','w')
cpp_file = open('PythonConnection.cpp','w')
reg_file = open('register.cpp','w')

# GPL license
print >>h_file, license
print >>cpp_file, license

# headers
print >>h_file, h_pre
print >>cpp_file, cpp_pre
print >>reg_file, reg_pre

for s in __signtures__:
    cb = signature(s, ptr=True)
    ps = signature(s, '_', '_')
    psf = signature(s, '_', '_', '_')
    print >>h_file, h_tmpl % (psf,ps,ps,cb)
    

h_file.close()
cpp_file.close()
reg_file.close()




