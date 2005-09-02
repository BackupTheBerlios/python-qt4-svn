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

#ifndef PYTHONQT_H
#define PYTHONQT_H

#include <boost/python.hpp>

#include <QMap>
#include <QObject>

#define Q_PYTHON_ARG(T) \
    PythonQt::register_converter(#T, convert_arg_to_python<T>);

#define Q_PYTHON_ARG_POINTER(T) \
    PythonQt::register_converter(#T, convert_arg_pointer_to_python<T>);

class PythonQt
{
public:
    static inline void
    register_converter(const QString& argtype, boost::python::object (*convert)(void*))
    {
        arg_convert_map[argtype] = convert;
    }

    static inline boost::python::object
    convert(const QString& argtype, void* arg)
    {
        if ( arg_convert_map.contains(argtype) )
        {
            boost::python::object (*convert)(void*) = arg_convert_map[argtype];
            return convert(arg);
        }
        else
        {
            qWarning("Argument type '%s' not registered");
            return boost::python::object();
        }
    }
    
private:
    static QMap<QString, boost::python::object (*)(void*)> arg_convert_map;

protected:
    PythonQt(){};
};

enum PythonArgType {
    instance = 0,
    pointer = 1
};

template<typename T>
boost::python::object
convert_arg_to_python(void* param)
{
    return boost::python::object( *(T*)param );
}

template<typename T>
boost::python::object
convert_arg_pointer_to_python(void* param)
{
    return boost::python::object( boost::python::ptr( *(T*)param ) );
}



#endif // PYTHONQT_H


