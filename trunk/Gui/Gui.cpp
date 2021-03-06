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


void export_QFont();
void export_QPaintDevice();
void export_QApplication();
void export_QWidget();
void export_QPushButton();
void export_QLineEdit();
void export_QListView();
void export_QLayoutItem();
void export_QLayout();
void export_QBoxLayout();
//void export_QGridLayout();
void export_QFrame();
void export_QLCDNumber();

using namespace boost::python;

BOOST_PYTHON_MODULE(Gui)
{
    export_QFont();
    export_QPaintDevice();
    export_QLayoutItem();
    export_QLayout();
    export_QBoxLayout();
//    export_QGridLayout();
    export_QApplication();
    export_QWidget();
    export_QFrame();
    export_QLCDNumber();
    export_QPushButton();
    export_QLineEdit();
    export_QListView();
}
