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
#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <string>
#include <memory>


static int one = 1;

static char**
AppName(std::string name)
{
    char** v = new char* [1];
    v[0] = new char[strlen(name.c_str())];
    strcpy(v[0], name.c_str());
    return v;
}

using namespace boost::python;

struct QApplication_Wrapper: QApplication, wrapper<QApplication>
{
    QApplication_Wrapper(std::string name):
        QApplication(one, AppName(name))
    {
    }

    int
    QApplication_Wrapper::run()
    {
        return QApplication::exec();
    }

};

void
export_QApplication()
{
    class_< QApplication_Wrapper,
            bases<QCoreApplication>,
            boost::shared_ptr<QApplication_Wrapper>,
            boost::noncopyable>
            ("QApplication", init<std::string>())
            
        .def("sessionId", &QApplication::sessionId)
        .def("notify", &QApplication::notify)  

    ;

}


