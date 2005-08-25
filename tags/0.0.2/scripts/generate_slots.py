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

# def alias(s):
#     if __alias__.has_key(s):
#         return __alias__[s]
#     else:
#         return s

__headers__ = [ 
    'QString', 'QSize', 'QRect', 'QPoint', 'QTextCursor', 'QObject'
]

__signatures__ = [ 
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


for sig in __signatures__:
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
license = license.strip()


inc_tmpl = """
#include <%s>
"""
inc_tmpl = inc_tmpl.lstrip()

includes = ''
for klass in __headers__:
        includes += inc_tmpl%(klass)

    
h_pre = """
#ifndef PYTHONCONNECTION_H
#define PYTHONCONNECTION_H

#include <boost/python/object_fwd.hpp>

#include <QMap>
%s

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

"""
h_pre = h_pre%(includes)


h_tmpl = """
struct PythonSlot%sFactory: AbstractPythonSlotFactory
{
    virtual QObject* create(object* method);
};

class PythonSlot%s: public QObject, public AbstractPythonSlot
{
    Q_OBJECT
public:
    PythonSlot%s(object* slot);

public slots:
    void callback(%s);
};

// ----------------------------------------------------------------------------

"""

h_pos = """
#endif
"""


cpp_pre = """
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
"""

cpp_tmpl = """
QObject*
PythonSlot%sFactory::create(object* method)
{
    return new PythonSlot%s(method);
}

PythonSlot%s::PythonSlot%s(object* method):
    QObject(0), AbstractPythonSlot(method)
{
}

void
PythonSlot%s::callback(%s)
{
    (*_method)(%s);
}

// ----------------------------------------------------------------------------
"""


reg_pre = """
#include "PythonConnection.h"

void 
register_slot_factories(FactoryMap& slot_registry)
{
    slot_registry["()"] = new PythonSlotFactory;
"""
reg_pre = reg_pre.rstrip()

reg_tmpl = """
    slot_registry["(%s)"] = new PythonSlot%sFactory;
"""    
reg_tmpl = reg_tmpl.rstrip()    

reg_pos = """
}
"""



########################################################33#####################

def pod_ptr(arg, ptr=False):
    if arg[-1] == '*' and not ptr:
        return arg[:-1]
    else:
        return arg

def arguments(args):
    ret = ''
    for i in range(len(args)):
        ret += 'p%d'%(i)
        if (args[i]).endswith('*'): ret = 'ptr('+ret+')'
        ret += ','
    return ret[:-1]
                
def signature(args, sep=',', pre='', pos='', ptr=False, param=False):
    ret = ''
    for i in range(len(args)):
        arg = pod_ptr(args[i], ptr)
        ret += arg
        if param: ret += (' p%d'%(i))
        ret += sep
    ret = ret[:-1]    
    return pre+ret+pos
  
### open all files (overwrite if necessary)     
h_file = open('PythonConnection.h','w')
cpp_file = open('PythonConnection.cpp','w')
reg_file = open('Register.cpp','w')

### GPL license
print >>h_file, license
print >>cpp_file, license
print >>reg_file, license

### headers
print >>h_file, h_pre
print >>cpp_file, cpp_pre
print >>reg_file, reg_pre

#### middle
for s in __signatures__:
    cb = signature(s, ptr=True)
    ps = signature(s, '_', '_')
    psf = signature(s, '_', '_', '_')
    cal = arguments(s)
    par = signature(s, ptr=True, param=True)    
    print >>h_file, h_tmpl % (psf,ps,ps,cb)
    print >>cpp_file, cpp_tmpl % (psf,ps,ps,ps,ps,par,cal)    
    print >>reg_file, reg_tmpl % (cb,psf)

#### footers
print >>h_file, h_pos
print >>reg_file, reg_pos

### close all files
h_file.close()
cpp_file.close()
reg_file.close()

