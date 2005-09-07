#include "QPython.h"
//#include <boost/python.hpp>

#include <QObject>
#include <QWidget>

bool QPython::_started = false;
bool QPython::_stopped = false;

namespace python = boost::python;

void
test_main()
{
    using namespace boost::python;

    object main_module((
         handle<>(borrowed(PyImport_AddModule("__main__")))));

    object main_namespace = main_module.attr("__dict__");

    handle<> ignored((PyRun_String(

        "result = 5 ** 2"

        , Py_file_input
        , main_namespace.ptr()
        , main_namespace.ptr())
    ));

    int five_squared = extract<int>(main_namespace["result"]);
    assert(five_squared == 25);

    object result((handle<>(
        PyRun_String("5 ** 2"
            , Py_eval_input
            , main_namespace.ptr()
            , main_namespace.ptr()))
    ));

    int five_squared2 = extract<int>(result);
    assert(five_squared2 == 25);
}

extern "C" {
    void initdl();
};

python::object global_button;

void
test_qt(QWidget* parent)
{
    using namespace boost::python;
    
    object main_module((
         handle<>(borrowed(PyImport_AddModule("__main__")))));

    object main_namespace = main_module.attr("__dict__");

    // Define the derived class in Python.
    // (You'll normally want to put this in a .py file.)
    python::handle<> result(
        PyRun_String(
        "import sys\n"
        "print sys.path\n"
        "import Qt\n"
        "from Qt.Gui import QPushButton\n"
        "print QPushButton\n",
        //"class PythonDerived(Base):          \n"
        //"    def hello(self):                \n"
        //"        return 'Hello from Python!' \n",
        Py_file_input, main_namespace.ptr(), main_namespace.ptr())
        );
    // Result is not needed
    result.reset();

    // Extract the raw Python object representing the just defined derived class
    python::handle<> class_ptr(
        PyRun_String("QPushButton('Eric Jardim', None)\n", Py_eval_input,
                     main_namespace.ptr(), main_namespace.ptr()) );
    
                     
    // Wrap the raw Python object in a Boost.Python object
    //python::object PythonQPushButton(class_ptr);
    global_button = object(class_ptr);
    QWidget* button = python::extract<QWidget*>(global_button);
    button->setParent(parent);
    button->show();
}


void
QPython::init()
{
    qDebug("Py_Initialize");
    Py_Initialize();    
}


void
QPython::test(QWidget* parent)
{
    qDebug("test");
    if (python::handle_exception(test_main))
    {
        if (PyErr_Occurred()) PyErr_Print();            
    }
    
    qDebug("test_qt");
    try  {
        test_qt(parent);
    }   
    catch(python::error_already_set) {
        if (PyErr_Occurred()) PyErr_Print();
    }
}

void
QPython::finalize()
{
    // Boost.Python doesn't support Py_Finalize yet.
    qDebug("Py_Finalize");
    //Py_Finalize();
}




