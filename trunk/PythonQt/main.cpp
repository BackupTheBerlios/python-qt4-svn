#include "QPython.h"
#include "QPythonWidget.h"
#include "QPythonObject.h"

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>

using namespace boost::python;


int
main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QPython::init();
    
    QWidget* widget = new QWidget(0);        
    //QFrame* widget = new QFrame(0);
    widget->resize(200,100);
    QVBoxLayout* layout = new QVBoxLayout;    
    layout->setMargin(4);
    
    //QWidget* button1 = new QPythonWidget(widget, "Qt.Gui", "QPushButton");
    QWidget* button1 = new QPythonWidget(widget, "mybutton", "MyButton");
    QWidget* button2 = new QPythonWidget(widget, "mybutton", "MyEdit");
    QWidget* button3 = new QPushButton("Button", widget);
    QWidget* button4 = new QLineEdit("LineEdit", widget);
    //QPythonWidget* pywidget = new QPythonWidget(0, "mybutton", "MyButton");
    //QPushButton* button = pywidget->getWidget<QPushButton>();
    
    object pytimer = QPythonObject::create(widget, "mybutton", "MyTimer");
    QTimer* timer = extract<QTimer*>(pytimer);
    qDebug("timer: %p", timer);    
    QObject::connect(button3, SIGNAL(clicked()), timer, SLOT(start()));
    
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    widget->setLayout(layout);
    
    widget->show();
    app.exec();    
    
    QPython::finalize();
    return 0;
}
