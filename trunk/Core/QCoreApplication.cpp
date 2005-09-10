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

#include <boost/python.hpp>
#include <boost/python/wrapper.hpp>
#include <QCoreApplication>
#include <QString>
#include <string>
//#include <memory>
#include <stdlib.h>

#include <QtWrapper.h>
#include <Util.h>

using namespace boost::python;

static int _value;

QOBJECT_WRAPPER(QCoreApplication, PythonQCoreApplication)
{
    PYTHON_QOBJECT;
    PythonQCoreApplication(): QCoreApplication(Util::one(_value), Util::single_string("python-qt4")) {}
    PythonQCoreApplication(list _args): QCoreApplication(Util::list_size(_args, _value), Util::list_values(_args)) {}
};

void
export_QCoreApplication()
{
    class_< PythonQCoreApplication,
            bases<QObject>,
            boost::shared_ptr<PythonQCoreApplication>,
            boost::noncopyable>
            ("QCoreApplication", init<>())
        .def(init<list>(args("args")))

        .add_property("applicationName", &QCoreApplication::applicationName)
        .add_property("organizationDomain", &QCoreApplication::organizationDomain)
        .add_property("organizationName", &QCoreApplication::organizationName)

        .def("notify", &QCoreApplication::notify)

        .def("run", &QCoreApplication::exec)
        .staticmethod("run")
     
    .def("instance", &QCoreApplication::instance, 
            return_value_policy<reference_existing_object>())
        .staticmethod("instance")
   
        .def("exit", (void(*)()) &QCoreApplication::exit)
        .def("exit", (void(*)(int)) &QCoreApplication::exit)
        .staticmethod("exit")
        
        .def("quit", &QCoreApplication::quit)
        .staticmethod("quit")        
    ;

}
