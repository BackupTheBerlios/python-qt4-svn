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
#include <boost/python/detail/api_placeholder.hpp>
#include <iostream>
#include "Utility.h"



//using namespace boost::python;

//char**
void
ListToCharPP(const boost::python::list& args)
{
    int size = boost::python::len(args);
    //shared_array<char*> out = new char*[size];
    char** out = new char*[size];
    for(int i=0; i<size; i++)
    {
        out[i] = boost::python::extract<char*>(args[i]);
        std::cout << out[i] << std::endl;
    }
    delete[] out;
    //return out;
}


