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

#include <boost/python/module.hpp>
#include <boost/python/enum.hpp>

#include <QtCore/Qt>
#include <QtCore/QEvent>
#include <PythonQt.h>

//void export_QFlags();
void export_QByteArray();
void export_QString();
void export_QEvent();
void export_QChildEvent();
void export_QObject();
void export_QTime();
void export_QTimer();
void export_QCoreApplication();

using namespace boost::python;

BOOST_PYTHON_MODULE(Core)
{
//    export_QFlags();
    export_QByteArray();
    export_QString();
    export_QTime();
    export_QEvent();    
    export_QChildEvent();
    export_QObject();
        export_QTimer();
        export_QCoreApplication();

    Q_PYTHON_ARG(bool);
    Q_PYTHON_ARG(int);
    Q_PYTHON_ARG(double);
    Q_PYTHON_ARG(QString);
    //Q_PYTHON_ARG(QStringList);
    Q_PYTHON_ARG_POINTER(QEvent*);
    Q_PYTHON_ARG_POINTER(QObject*);
    //Q_PYTHON_ARG_POINTER(QAction*); // this should stay on Gui module
}
