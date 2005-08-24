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

#include "PythonConnection.h"

void 
register_slot_factories(FactoryMap& slot_registry)
{
    slot_registry["()"] = new PythonSlotFactory;

    slot_registry["(bool)"] = new PythonSlot_bool_Factory;

    slot_registry["(int)"] = new PythonSlot_int_Factory;

    slot_registry["(double)"] = new PythonSlot_double_Factory;

    slot_registry["(QString)"] = new PythonSlot_QString_Factory;

    slot_registry["(QSize)"] = new PythonSlot_QSize_Factory;

    slot_registry["(QRect)"] = new PythonSlot_QRect_Factory;

    slot_registry["(QPoint)"] = new PythonSlot_QPoint_Factory;

    slot_registry["(QTextCursor)"] = new PythonSlot_QTextCursor_Factory;

    slot_registry["(QObject*)"] = new PythonSlot_QObject_Factory;

    slot_registry["(int,int)"] = new PythonSlot_int_int_Factory;

    slot_registry["(int,int,int)"] = new PythonSlot_int_int_int_Factory;

}

