#include <boost/python.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits.hpp>
#include <iostream> 

namespace mpl = boost::mpl;
namespace python = boost::python;

template<typename T>
struct instance_param {
    static const T& 
    call(const T& t)
    {
        return t;
    }
};

template<typename T>
struct pointer_param {
    static python::object 
    call(T t)
    {
        return python::object(python::ptr(t));
    }
};

template<>
struct pointer_param<const char*> {
    static const char*
    call(const char* t)
    {
        return t;
    }
};
                        
template<>
struct pointer_param<char*> {
    static char*
    call(char* t)
    {
        return t;
    }
};

template<typename T>
python::object 
param(T t)
{
    return python::object(mpl::if_<boost::is_pointer<T>,
                          pointer_param<T>,
                          instance_param<T> >::type::call(t))
    ;
};

#define WRAPPER(Parent_, Wrapper_) \
    struct Wrapper_: Parent_, \
                     wrapper<Parent_> \

#define QOBJECT_WRAPPER(Parent_, Wrapper_) \
    struct Wrapper_: Parent_, \
                     wrapper<Parent_>, \
                     qtwrapper<Parent_, Wrapper_> \

#define DARGS_0
#define DARGS_1(T1) T1 p1
#define DARGS_2(T1,T2) T1 p1,T2 p2
#define DARGS_3(T1,T2,T3) T1 p1,T2 p2,T3 p3

#define OARGS_0
#define OARGS_1 param(p1)
#define OARGS_2 param(p1),param(p2)
#define OARGS_3 param(p1),param(p2),param(p3)

#define CARGS_0
#define CARGS_1 p1
#define CARGS_2 p1,p2
#define CARGS_3 p1,p2,p3

                     
#define PURE_VIRTUAL_COMMON(RT, method, dargs, oargs, const_) \
    inline RT \
    method( dargs ) const_ \
    { \
        return (RT) this->get_override(#method)( oargs ); \
    } \

#define VIRTUAL_COMMON(RT, method, dargs, oargs, cargs, const_) \
    inline RT \
    method( dargs ) const_ \
    { \
        if (python::override ovr = this->get_override(#method))  \
            return (RT) ovr( oargs ); \
        else \
            return (RT) this->Parent::method( cargs ); \
    } \
    \
    inline RT \
    __##method( dargs ) const_ \
    { \
        return (RT) this->Parent::method( cargs ); \
    } \ 

#define PROTECTED_VIRTUAL_COMMON(RT, method, dargs, oargs, cargs, const_) \
    inline RT \
    method( dargs ) const_ \
    { \
        if (python::override ovr = this->get_override(#method))  \
            return (RT) ovr( oargs )); \
        else \
            return (RT) this->Parent::method( cargs ); \
    } \
    \
    inline RT \
    __##method( dargs ) const_ \
    { \
        return (RT) this->Parent::method( cargs ); \
    } \
    \
    
    
    

#define PROTECTED_COMMON(RT, method, dargs, oargs, cargs, const_) \
    inline RT \
    method( dargs ) const_ \
    { \
        if (python::override ovr = this->get_override(#method))  \
            return (RT) ovr( oargs )); \
        else \
            return (RT) this->Parent::method( cargs ); \
    } \
    \
    inline RT \
    __##method( dargs ) const_ \
    { \
        return (RT) this->Parent::method( cargs ); \
    } \ 
    
    
#define PURE_VIRTUAL_0(RT,method)           PURE_VIRTUAL_COMMON(RT,method,DARGS_0,OARGS_0,)
#define PURE_VIRTUAL_1(RT,method,T1)        PURE_VIRTUAL_COMMON(RT,method,DARGS_1(T1),OARGS_1,)
#define PURE_VIRTUAL_2(RT,method,T1,T2)     PURE_VIRTUAL_COMMON(RT,method,DARGS_2(T1,T2),OARGS_2,)
#define PURE_VIRTUAL_3(RT,method,T1,T2,T3)  PURE_VIRTUAL_COMMON(RT,method,DARGS_3(T1,T2,T3),OARGS_3,)

#define PURE_VIRTUAL_CONST_0(RT,method)           PURE_VIRTUAL_COMMON(RT,method,DARGS_0,OARGS_0,const)
#define PURE_VIRTUAL_CONST_1(RT,method,T1)        PURE_VIRTUAL_COMMON(RT,method,DARGS_1(T1),OARGS_1,const)
#define PURE_VIRTUAL_CONST_2(RT,method,T1,T2)     PURE_VIRTUAL_COMMON(RT,method,DARGS_2(T1,T2),OARGS_2,const)
#define PURE_VIRTUAL_CONST_3(RT,method,T1,T2,T3)  PURE_VIRTUAL_COMMON(RT,method,DARGS_3(T1,T2,T3),OARGS_3,const)

#define VIRTUAL_0(RT,method) VIRTUAL_COMMON(RT,method,DARGS_0,OARGS_0,CARGS_0,)
#define VIRTUAL_1(RT,method,T1) VIRTUAL_COMMON(RT,method,DARGS_1(T1),OARGS_1,CARGS_1,)
#define VIRTUAL_2(RT,method,T1,T2) VIRTUAL_COMMON(RT,method,DARGS_2(T1,T2),OARGS_2,CARGS_2,)
#define VIRTUAL_3(RT,method,T1,T2,T3) VIRTUAL_COMMON(RT,method,DARGS_3(T1,T2,T3),OARGS_3,CARGS_3,)

#define VIRTUAL_CONST_0(RT,method) VIRTUAL_COMMON(RT,method,DARGS_0,OARGS_0,CARGS_0,const)
#define VIRTUAL_CONST_1(RT,method,T1) VIRTUAL_COMMON(RT,method,DARGS_1(T1),OARGS_1,CARGS_1,const)
#define VIRTUAL_CONST_2(RT,method,T1,T2) VIRTUAL_COMMON(RT,method,DARGS_2(T1,T2),OARGS_2,CARGS_2,const)
#define VIRTUAL_CONST_3(RT,method,T1,T2,T3) VIRTUAL_COMMON(RT,method,DARGS_3(T1,T2,T3),OARGS_3,CARGS_3,const)


        