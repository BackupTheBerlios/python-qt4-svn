//
// C++ Interface: PythonSlot
//
// Description: 
//
//
// Author: Eric Jardim <ericjardim@gmail.com>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PYTHONSLOT_H
#define PYTHONSLOT_H

// namespace boost { namespace python {
// class object;
// }; };
//class _object_;

/**
@author Eric Jardim
*/
class PythonSlot
{
    void* _slot;
    
public:
    PythonSlot(void* slot);
    //~PythonSlot();
};

#endif
