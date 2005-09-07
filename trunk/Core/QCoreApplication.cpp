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

#include <PythonQObject.h>


static int one = 1;

static char**
AppName(std::string name)
{
    char** v = (char**) malloc(sizeof(char*));
    v[0] = new char[strlen(name.c_str())];
    v[0] = (char*) malloc(strlen(name.c_str())+1);
    strcpy(v[0], name.c_str());
    return v;
}

using namespace boost::python;

struct PythonQCoreApplication: QCoreApplication, 
                               wrapper<QCoreApplication>, 
                               qtwrapper<QCoreApplication, PythonQCoreApplication>
{
    PYTHON_QOBJECT;

    PythonQCoreApplication(std::string name):
        QCoreApplication(one, AppName(name))
    {
    }
};

void
export_QCoreApplication()
{
    class_< PythonQCoreApplication,
            bases<QObject>,
            boost::shared_ptr<PythonQCoreApplication>,
            boost::noncopyable>
            ("QCoreApplication", init<std::string>())

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
