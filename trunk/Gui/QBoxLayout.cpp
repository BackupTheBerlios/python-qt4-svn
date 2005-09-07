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

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/str.hpp>
#include <boost/shared_ptr.hpp>

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>
//#include <boost/python/return_value_policy.hpp>

#include <QLayout>
#include <QWidget>
#include <QAbstractItemView>
#include <QListView>
#include <QListWidget>
//#include <QString>
#include <memory>
//#include <iostream>
//#include <string>

using namespace boost::python;


void
export_QBoxLayout()
{
    class_< QBoxLayout,
            bases<QLayout>,
            boost::shared_ptr<QBoxLayout>,
            boost::noncopyable>
    ("QBoxLayout", no_init)
        .def("addWidget",
             &QLayout::addWidget,
             default_call_policies() )
    ;
    
    class_< QHBoxLayout,
            bases<QBoxLayout>,
            boost::shared_ptr<QHBoxLayout>,
            boost::noncopyable>
    ("QHBoxLayout",  init<QWidget*>()[with_custodian_and_ward<1,2>()])
    ;

    class_< QVBoxLayout,
            bases<QBoxLayout>,
            boost::shared_ptr<QVBoxLayout>,
            boost::noncopyable>
    ("QVBoxLayout",  init<QWidget*>()[with_custodian_and_ward<1,2>()])
    ;
}
