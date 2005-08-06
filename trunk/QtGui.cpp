#include <boost/python.hpp>

#include <string>
#include <QApplication>
#include <QMainWindow>
#include <QString>




static int one = 1;

class QApplication_Wrap: public QApplication
{
public:
//     QApplication_Wrap(std::string name):
//     QApplication(one, AppName(name))
//     {
//     }
    
    QApplication_Wrap(PyObject* self_, std::string name):
    QApplication(one, AppName(name)), self(self_)
    {
    }
    PyObject* self;
    
    std::string 
    sessionId()
    {
        QString id = QApplication::sessionId();
        return id.toStdString(); 
    }
    
    int
    run()
    {
        return QApplication::exec();
    }
};

using namespace boost::python;

BOOST_PYTHON_MODULE(qt4)
{
    class_<QApplication, QApplication_Wrap, boost::noncopyable>("QApplication", init<std::string>())
        .def("sessionId", &QApplication_Wrap::sessionId)
        .def("run", &QApplication_Wrap::run);
    ;
}
