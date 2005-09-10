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

#ifndef UTIL_H
#define UTIL_H

#include <boost/python.hpp>

namespace python = boost::python;

namespace Util
{
    inline int&
    one(int& value)
    {
        value  = 1;
        return value;
    }
    
    inline int&
    list_size(python::list _args, int& value)
    {
        value = python::extract<int>( _args.attr("__len__")() );
        return value;
    }
    
    inline char**
    list_values(python::list _args)
    {
        int n = python::extract<int>( _args.attr("__len__")() );
        char** v = 0;
        for(int i=0; i<n; i++)
        {
            std::string arg = python::extract<std::string>( _args[i] );
            v = (char**) malloc( (n+1) * sizeof(char*));
            int len = strlen( arg.c_str() );
            v[i] = (char*) malloc(len + 1);
            strcpy(v[i], arg.c_str());
            v[i][len] = '\0';
        }
        v[n] = 0;
        return v;
    }

    inline char**
    single_string(std::string name)
    {
        python::str _arg(name);
        python::list _args;
        _args.append(_arg);
        return list_values(_args);
    }
};

#endif

