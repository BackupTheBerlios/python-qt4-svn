
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <QtCore/QObject>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

struct QObject_Wrapper: QObject
{
    QObject_Wrapper(PyObject* py_self_):
        QObject(), py_self(py_self_) {}

    QObject_Wrapper(PyObject* py_self_, QObject* p0):
        QObject(p0), py_self(py_self_) {}

    const QMetaObject* metaObject() const {
        return call_method< const QMetaObject* >(py_self, "metaObject");
    }

    const QMetaObject* default_metaObject() const {
        return QObject::metaObject();
    }

    void* qt_metacast(const char* p0) {
        return call_method< void* >(py_self, "qt_metacast", p0);
    }

    void* default_qt_metacast(const char* p0) {
        return QObject::qt_metacast(p0);
    }

    int qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return call_method< int >(py_self, "qt_metacall", p0, p1, p2);
    }

    int default_qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return QObject::qt_metacall(p0, p1, p2);
    }

    bool event(QEvent* p0) {
        return call_method< bool >(py_self, "event", p0);
    }

    bool default_event(QEvent* p0) {
        return QObject::event(p0);
    }

    bool eventFilter(QObject* p0, QEvent* p1) {
        return call_method< bool >(py_self, "eventFilter", p0, p1);
    }

    bool default_eventFilter(QObject* p0, QEvent* p1) {
        return QObject::eventFilter(p0, p1);
    }

    void timerEvent(QTimerEvent* p0) {
        call_method< void >(py_self, "timerEvent", p0);
    }

    void default_timerEvent(QTimerEvent* p0) {
        QObject::timerEvent(p0);
    }

    void childEvent(QChildEvent* p0) {
        call_method< void >(py_self, "childEvent", p0);
    }

    void default_childEvent(QChildEvent* p0) {
        QObject::childEvent(p0);
    }

    void customEvent(QEvent* p0) {
        call_method< void >(py_self, "customEvent", p0);
    }

    void default_customEvent(QEvent* p0) {
        QObject::customEvent(p0);
    }

    void connectNotify(const char* p0) {
        call_method< void >(py_self, "connectNotify", p0);
    }

    void default_connectNotify(const char* p0) {
        QObject::connectNotify(p0);
    }

    void disconnectNotify(const char* p0) {
        call_method< void >(py_self, "disconnectNotify", p0);
    }

    void default_disconnectNotify(const char* p0) {
        QObject::disconnectNotify(p0);
    }

    PyObject* py_self;
};

BOOST_PYTHON_FUNCTION_OVERLOADS(QObject_tr_overloads_1_2, QObject::tr, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QObject_trUtf8_overloads_1_2, QObject::trUtf8, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QObject_connect_overloads_4_5, QObject::connect, 4, 5)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QObject_connect_overloads_3_4, connect, 3, 4)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QObject_disconnect_overloads_0_3, disconnect, 0, 3)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QObject_disconnect_overloads_1_2, disconnect, 1, 2)


}// namespace 


// Module ======================================================================
void Export_QObject()
{
    class_< QObject, boost::noncopyable, QObject_Wrapper >("QObject", init< optional< QObject* > >())
        .def_readonly("staticMetaObject", &QObject::staticMetaObject)
        .def("metaObject", &QObject::metaObject, &QObject_Wrapper::default_metaObject)
        .def("qt_metacast", &QObject::qt_metacast, &QObject_Wrapper::default_qt_metacast)
        .def("qt_metacall", &QObject::qt_metacall, &QObject_Wrapper::default_qt_metacall)
        .def("event", &QObject::event, &QObject_Wrapper::default_event)
        .def("eventFilter", &QObject::eventFilter, &QObject_Wrapper::default_eventFilter)
        .def("tr", &QObject::tr, QObject_tr_overloads_1_2())
        .def("trUtf8", &QObject::trUtf8, QObject_trUtf8_overloads_1_2())
        .def("objectName", &QObject::objectName)
        .def("setObjectName", &QObject::setObjectName)
        .def("isWidgetType", &QObject::isWidgetType)
        .def("signalsBlocked", &QObject::signalsBlocked)
        .def("blockSignals", &QObject::blockSignals)
        .def("thread", &QObject::thread)
        .def("moveToThread", &QObject::moveToThread)
        .def("startTimer", &QObject::startTimer)
        .def("killTimer", &QObject::killTimer)
        .def("children", &QObject::children, return_value_policy< copy_const_reference >())
        .def("setParent", &QObject::setParent)
        .def("installEventFilter", &QObject::installEventFilter)
        .def("removeEventFilter", &QObject::removeEventFilter)
        .def("connect", (bool (*)(const QObject*, const char*, const QObject*, const char*, Qt::ConnectionType))&QObject::connect, QObject_connect_overloads_4_5())
        .def("connect", (bool (QObject::*)(const QObject*, const char*, const char*, Qt::ConnectionType) const)&QObject::connect, QObject_connect_overloads_3_4())
        .def("disconnect", (bool (*)(const QObject*, const char*, const QObject*, const char*))&QObject::disconnect)
        .def("disconnect", (bool (QObject::*)(const char*, const QObject*, const char*) )&QObject::disconnect, QObject_disconnect_overloads_0_3())
        .def("disconnect", (bool (QObject::*)(const QObject*, const char*) )&QObject::disconnect, QObject_disconnect_overloads_1_2())
        .def("dumpObjectTree", &QObject::dumpObjectTree)
        .def("dumpObjectInfo", &QObject::dumpObjectInfo)
        .def("setProperty", &QObject::setProperty)
        .def("property", &QObject::property)
        .def("registerUserData", &QObject::registerUserData)
        .def("setUserData", &QObject::setUserData)
        .def("userData", &QObject::userData)
        .def("parent", &QObject::parent)
        .def("inherits", &QObject::inherits)
        .def("deleteLater", &QObject::deleteLater)
        .staticmethod("trUtf8")
        .staticmethod("registerUserData")
        .staticmethod("tr")
        .staticmethod("connect")
        .staticmethod("disconnect")
        .def( other< QDebug >() << self )
    ;

}

