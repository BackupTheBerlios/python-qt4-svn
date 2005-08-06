//
// C++ Implementation: PythonSlot
//
// Description: 
//
//
// Author: Eric Jardim <ericjardim@gmail.com>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "PythonSlot.h"

#include <boost/python/object.hpp>

//typedef boost::python::object _object_;

PythonSlot::PythonSlot(void* slot):
    _slot(slot)
{
}


// PythonSlot::~PythonSlot()
// {
// }


