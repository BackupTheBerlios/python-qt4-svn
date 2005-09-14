#ifndef CUSTOM_CALL_POLICY_H
#define CUSTOM_CALL_POLICY_H
/*# include <boost/python/detail/prefix.hpp>
# include <boost/mpl/if.hpp>
# include <boost/python/to_python_value.hpp>
# include <boost/python/detail/value_arg.hpp>
# include <boost/type_traits/transform_traits.hpp>
# include <boost/type_traits/is_pointer.hpp>
# include <boost/type_traits/is_reference.hpp>
# include <boost/mpl/or.hpp>*/
#include <boost/python/default_call_policies.hpp>
#include <boost/python/reference_existing_object.hpp>
#include <boost/python/object.hpp>
#include <boost/python/handle.hpp>



//extern QMap<QObject*, boost::python::object> pythonqt_reference_map;



namespace boost { namespace python { 

/*template <class T> struct to_python_value;*/

/*namespace detail
{
// for "readable" error messages
  template <class T> struct specify_a_return_value_policy_to_wrap_functions_returning
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
  {}
# endif 
  ;
}*/


struct custom_call_policy: default_call_policies
{
    // Ownership of this argument tuple will ultimately be adopted by
    // the caller.
    template <class ArgumentPackage>
    static bool precall(ArgumentPackage const& _args)
    {
        return PyTuple_Check(_args);
        //return true;
    }

    // Pass the result through
    template <class ArgumentPackage>
    static PyObject* postcall(ArgumentPackage const& _args, PyObject* result)
    {     
        PyObject* arg_0 = PyTuple_GetItem(_args, 0);
        
        object _self (( handle<>(borrowed(arg_0)) ));
        QObject* _this = extract<QObject*>( _self );
        
        QObject* _res = extract<QObject*>(
            object(( handle<>(borrowed(result)) ))
        );
        
        /*QObject* _parent = _this->parent();
        if (_parent) {
            qDebug("parent:%p", _parent);
            pythonqt_reference_map[_this] = self_;
        } */       
        qDebug("this:%p, result:%p", _this, _res);
        return result;
    }

    typedef reference_existing_object result_converter;
    typedef PyObject* argument_package;
};


}} // namespace boost::python

#endif // CUSTOM_CALL_POLICY_H
