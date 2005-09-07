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
#include <QByteArray>

struct QByteArray_to_python_str
{
    static PyObject*
    convert(QByteArray const& s)
    {
        // FIXME: NULLs
        return PyString_FromStringAndSize(s.data(), s.size());
    }
};

struct QByteArray_from_python_str
{
    QByteArray_from_python_str()
    {
        boost::python::converter::registry::push_back(  &convertible,
                                                        &construct,
                                                        boost::python::type_id<QByteArray>() );
    }
    
    static void*
    convertible(PyObject* obj_ptr)
    {
        if (!PyString_Check(obj_ptr)) return 0;
        return obj_ptr;
    }
    
    static void
    construct(  PyObject* obj_ptr,
                boost::python::converter::rvalue_from_python_stage1_data* data)
    {
        const char* value = PyString_AsString(obj_ptr);
        if (value == 0) boost::python::throw_error_already_set();
        void* storage = ((boost::python::converter::rvalue_from_python_storage<QByteArray>*) data)->storage.bytes;
        new (storage) QByteArray(value, PyString_GET_SIZE(obj_ptr));
        data->convertible = storage;
    }
};

void
export_QByteArray()
{
    boost::python::to_python_converter<QByteArray, QByteArray_to_python_str>();
    QByteArray_from_python_str();
}

