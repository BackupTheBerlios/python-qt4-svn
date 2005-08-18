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
#include <boost/python/enum.hpp>
#include <boost/python/def.hpp>

#include <QSysInfo>

using namespace boost::python;

void
export_QSysInfo()
{
//     enum_<QSysInfo::Endian>("Endian")
//         .value("BigEndian", QSysInfo::BigEndian)
//         .value("LittleEndian", QSysInfo::LittleEndian)
//         .value("ByteOrder", QSysInfo::ByteOrder)
//         .export_values()
//     ;

//     enum_<QSysInfo::MacVersion>("MacVersion")
//         .value("MV_9", QSysInfo::MV_9)
//         .value("MV_10_0", QSysInfo::MV_10_0)
//         .value("MV_10_1", QSysInfo::MV_10_1)
//         .value("MV_10_2", QSysInfo::MV_10_2)
//         .value("MV_10_3", QSysInfo::MV_10_3)
//         .value("MV_10_4", QSysInfo::MV_10_4)
//         .value("MV_Unknown", QSysInfo::MV_Unknown)
//         .export_values()
//     ;

    //.def("MacintoshVersion", &QSysInfo::MacintoshVersion)
        
//     class_<QSysInfo, boost::noncopyable>("QSysInfo", no_init)
//         .def_readonly("MacintoshVersion", &QSysInfo::MacintoshVersion)
//     ;
}
