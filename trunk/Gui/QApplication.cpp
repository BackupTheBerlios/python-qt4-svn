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

#include <PythonQObject.h>

#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <string>
#include <stdlib.h>

static int one = 1;

static char**
AppName(std::string name)
{
    char** v = (char**) malloc(sizeof(char*));
    v[0] = (char*) malloc(strlen(name.c_str())+1);
    strcpy(v[0], name.c_str());
    return v;
}


using namespace boost::python;


struct PythonQApplication: QApplication, 
                           wrapper<QApplication>, 
                           qtwrapper<QApplication, PythonQApplication>
{
    PYTHON_QOBJECT;
    PythonQApplication(std::string name): QApplication(one, AppName(name)) {}
};

void
export_QApplication()
{
    class_< PythonQApplication,
            bases<QCoreApplication>,
            boost::shared_ptr<PythonQApplication>,
            boost::noncopyable>
            ("QApplication", init<std::string>())
            
        .def("sessionId", &QApplication::sessionId)
        .def("notify", &QApplication::notify)  

    ;

}


