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

#include <QtWrapper.h>
#include <Util.h>

#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <string>
#include <stdlib.h>

static int _value = 1;

using namespace boost::python;


QOBJECT_WRAPPER(QApplication, PythonQApplication)
{
    PYTHON_QOBJECT;
    PythonQApplication(): QApplication(Util::one(_value), Util::single_string("python-qt4")) {}
    PythonQApplication(list _args): QApplication(Util::list_size(_args, _value), Util::list_values(_args)) {}
};

void
export_QApplication()
{
    class_< PythonQApplication,
            bases<QCoreApplication>,
            boost::shared_ptr<PythonQApplication>,
            boost::noncopyable>
            ("QApplication", init<>())
        .def(init<list>(args("args")))
            
        .def("sessionId", &QApplication::sessionId)
        .def("notify", &QApplication::notify)  

    ;

}


