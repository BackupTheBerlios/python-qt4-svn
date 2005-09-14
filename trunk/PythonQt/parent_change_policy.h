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

#ifndef PARENT_CHANGE_POLICY_H
#define PARENT_CHANGE_POLICY_H
#include <boost/python/default_call_policies.hpp>
#include <boost/python/reference_existing_object.hpp>
#include <boost/python/object.hpp>
#include <boost/python/handle.hpp>

#include <QObject>
#include <QPair>
#include <QMap>

extern QMap<QObject*, boost::python::object> pythonqt_reference_holder;

namespace boost { namespace python { 

template <class BasePolicy_=default_call_policies>
struct parent_change_policy: BasePolicy_
{
    // Nothing to do here. Call the base policy.
    template <class ArgumentPackage>
    static bool precall(ArgumentPackage const& _args)
    {
        return BasePolicy_::precall(_args);
    }

    // Make an invisible reference to the child object. It acts like if the
    // parent holds a refence to the child. 
    template <class ArgumentPackage>
    static PyObject* postcall(ArgumentPackage const& _args, PyObject* result)
    {
        // FIXME: Should I call postcall here or at the end?
        result = BasePolicy_::postcall(_args, result);

        // the 0-argument is the self object
        object _self (( handle<>(borrowed(PyTuple_GetItem(_args, 0))) ));
        QObject* _this = extract<QObject*>( _self );

        // get the parent
        QObject* _parent = _this->parent();
        if (_parent)
        {
            incref( _self.ptr() );
            pythonqt_reference_holder[_this] = _self;
        }
        else // if parent is Null
        {
            if ( pythonqt_reference_holder.contains(_this) ) 
            {
                decref( pythonqt_reference_holder[_this].ptr() );
                pythonqt_reference_holder.remove(_this);
            }
        }
        //qDebug("this:%p, parent:%p", _this, _parent);
        
        return result;
    }

    typedef reference_existing_object result_converter;
    typedef PyObject* argument_package;
};

}} // namespace boost::python

#endif // PARENT_CHANGE_POLICY_H
