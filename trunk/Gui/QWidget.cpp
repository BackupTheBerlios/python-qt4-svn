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

#include <boost/shared_ptr.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/str.hpp>
#include <boost/python/wrapper.hpp>

// #include <boost/python/object.hpp>
// #include <boost/python/list.hpp>
#include <boost/python/manage_new_object.hpp>
// #include <boost/python/return_value_policy.hpp>
// #include <boost/utility.hpp>
//#include <boost/python/copy_non_const_reference.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/return_value_policy.hpp>

#include <QtWrapper.h>

#include <Qt>
#include <QFlags>
#include <QObject>
#include <QPaintDevice>
#include <QWidget>
#include <QLayout>
#include <QEvent>
#include <QMouseEvent>
//#include <QFormBuilder>
#include <QtDesigner/QFormBuilder>
#include <QFile>
//#include <QString>
#include <memory>
//#include <iostream>
//#include <string>



using namespace boost::python;

object
loadUi(str _filename, object _parent)
{
    QString filename = extract<QString>(_filename);
    QWidget* parent = extract<QWidget*>(_parent);

    QFormBuilder builder;
    QFile file(filename);
    file.open(QFile::ReadOnly);
    object widget = object( ptr( builder.load(&file, parent) ) );
    file.close();
    return widget;
}

QOBJECT_WRAPPER(QWidget, PythonQWidget)
{
    PYTHON_QOBJECT;
    PythonQWidget():QWidget() {}
    PythonQWidget(QWidget* p0):QWidget(p0) {}
    PythonQWidget(QWidget* p0, Qt::WFlags p1):QWidget(p0, p1){}

    // QObject virtual methods
    VIRTUAL_2(bool,, eventFilter, QObject*, QEvent*, );
    
    // QObject protected virtual methods
    VIRTUAL_1(void, (void), childEvent, QChildEvent*, );
    VIRTUAL_1(void, (void), connectNotify, const char*, );
    VIRTUAL_1(void, (void), customEvent, QEvent*, );
    VIRTUAL_1(void, (void), disconnectNotify, const char*, );
    VIRTUAL_1(void, (void), timerEvent, QTimerEvent*, );
    
/*    int devType() const {
        return call_method< int >(py_self, "devType");
    }

    int default_devType() const {
        return QWidget::devType();
    }

    void setVisible(bool p0) {
        call_method< void >(py_self, "setVisible", p0);
    }

    void default_setVisible(bool p0) {
        QWidget::setVisible(p0);
    }

    QSize sizeHint() const {
        return call_method< QSize >(py_self, "sizeHint");
    }

    QSize default_sizeHint() const {
        return QWidget::sizeHint();
    }

    QSize minimumSizeHint() const {
        return call_method< QSize >(py_self, "minimumSizeHint");
    }

    QSize default_minimumSizeHint() const {
        return QWidget::minimumSizeHint();
    }

    int heightForWidth(int p0) const {
        return call_method< int >(py_self, "heightForWidth", p0);
    }

    int default_heightForWidth(int p0) const {
        return QWidget::heightForWidth(p0);
    }

    QPaintEngine* paintEngine() const {
        return call_method< QPaintEngine* >(py_self, "paintEngine");
    }

    QPaintEngine* default_paintEngine() const {
        return QWidget::paintEngine();
    }
*/

/* base for other events
    bool event(QEvent* p0)
    {
        if (override event = this->get_override("event"))
        {
            return event( ptr( p0 ) );
        }
        return QWidget::event(p0);
            
    }

    bool default_event(QEvent* p0)
    {
        return this->QWidget::event(p0);
    }
*/

    // Warning: This is not definitive yet
    // Note: Those event handlers function are protected on the QWidget class
    // scope, and it is not possible to call it default implementation.
    // As an alternative way, we wrap it and call the overriden (if exists)
    // before the default implementation.
    // So if you need to get hook after the default implementation was called
    // define a Python function with name "after_<original method name>"
    // example: def after_mousePressEvent(self, event):

    virtual void
    mousePressEvent(QMouseEvent* p0)
    {
        if (override mousePressEvent = this->get_override("mousePressEvent"))
        {
            qDebug("PythonQWidget::mousePressEvent (overriden)");
            mousePressEvent( ptr( p0 ) );
        }
        else
        {
            qDebug("PythonQWidget::mousePressEvent (not overriden)");
            QWidget::mousePressEvent(p0);
        }
    }

    void
    _mousePressEvent(QMouseEvent* p0)
    {
        qDebug("PythonQWidget::_mousePressEvent (default)");
        this->QWidget::mousePressEvent(p0);
    }
    
    void
    mouseReleaseEvent(QMouseEvent* p0)
    {
        if (override mouseReleaseEvent = this->get_override("mouseReleaseEvent"))
        {
            mouseReleaseEvent( object(ptr(p0)) );
        }
        QWidget::mouseReleaseEvent(p0);
    }

//     void
//     default_mouseReleaseEvent(QMouseEvent* p0)
//     {
//         QWidget::mouseReleaseEvent(p0);
//     }

    void
    mouseDoubleClickEvent(QMouseEvent* p0)
    {
        if (override mouseDoubleClickEvent = this->get_override("mouseDoubleClickEvent"))
        {
            mouseDoubleClickEvent( ptr( p0 ) );
        }
        QWidget::mouseDoubleClickEvent(p0);
    }

//     void
//     default_mouseDoubleClickEvent(QMouseEvent* p0)
//     {
//         QWidget::mouseDoubleClickEvent(p0);
//     }

    void
    mouseMoveEvent(QMouseEvent* p0)
    {
        if (override mouseMoveEvent = this->get_override("mouseMoveEvent"))
        {
            mouseMoveEvent( ptr( p0 ) );
        }
        QWidget::mouseMoveEvent(p0);
    }

//     void
//     default_mouseMoveEvent(QMouseEvent* p0)
//     {
//         QWidget::mouseMoveEvent(p0);
//     }

/*    void wheelEvent(QWheelEvent* p0) {
        call_method< void >(py_self, "wheelEvent", p0);
    }

    void default_wheelEvent(QWheelEvent* p0) {
        QWidget::wheelEvent(p0);
    }

    void keyPressEvent(QKeyEvent* p0) {
        call_method< void >(py_self, "keyPressEvent", p0);
    }

    void default_keyPressEvent(QKeyEvent* p0) {
        QWidget::keyPressEvent(p0);
    }

    void keyReleaseEvent(QKeyEvent* p0) {
        call_method< void >(py_self, "keyReleaseEvent", p0);
    }

    void default_keyReleaseEvent(QKeyEvent* p0) {
        QWidget::keyReleaseEvent(p0);
    }

    void focusInEvent(QFocusEvent* p0) {
        call_method< void >(py_self, "focusInEvent", p0);
    }

    void default_focusInEvent(QFocusEvent* p0) {
        QWidget::focusInEvent(p0);
    }

    void focusOutEvent(QFocusEvent* p0) {
        call_method< void >(py_self, "focusOutEvent", p0);
    }

    void default_focusOutEvent(QFocusEvent* p0) {
        QWidget::focusOutEvent(p0);
    }

    void enterEvent(QEvent* p0) {
        call_method< void >(py_self, "enterEvent", p0);
    }

    void default_enterEvent(QEvent* p0) {
        QWidget::enterEvent(p0);
    }

    void leaveEvent(QEvent* p0) {
        call_method< void >(py_self, "leaveEvent", p0);
    }

    void default_leaveEvent(QEvent* p0) {
        QWidget::leaveEvent(p0);
    }

    void paintEvent(QPaintEvent* p0) {
        call_method< void >(py_self, "paintEvent", p0);
    }

    void default_paintEvent(QPaintEvent* p0) {
        QWidget::paintEvent(p0);
    }

    void moveEvent(QMoveEvent* p0) {
        call_method< void >(py_self, "moveEvent", p0);
    }

    void default_moveEvent(QMoveEvent* p0) {
        QWidget::moveEvent(p0);
    }

    void resizeEvent(QResizeEvent* p0) {
        call_method< void >(py_self, "resizeEvent", p0);
    }

    void default_resizeEvent(QResizeEvent* p0) {
        QWidget::resizeEvent(p0);
    }

    void closeEvent(QCloseEvent* p0) {
        call_method< void >(py_self, "closeEvent", p0);
    }

    void default_closeEvent(QCloseEvent* p0) {
        QWidget::closeEvent(p0);
    }

    void contextMenuEvent(QContextMenuEvent* p0) {
        call_method< void >(py_self, "contextMenuEvent", p0);
    }

    void default_contextMenuEvent(QContextMenuEvent* p0) {
        QWidget::contextMenuEvent(p0);
    }

    void tabletEvent(QTabletEvent* p0) {
        call_method< void >(py_self, "tabletEvent", p0);
    }

    void default_tabletEvent(QTabletEvent* p0) {
        QWidget::tabletEvent(p0);
    }

    void actionEvent(QActionEvent* p0) {
        call_method< void >(py_self, "actionEvent", p0);
    }

    void default_actionEvent(QActionEvent* p0) {
        QWidget::actionEvent(p0);
    }

    void dragEnterEvent(QDragEnterEvent* p0) {
        call_method< void >(py_self, "dragEnterEvent", p0);
    }

    void default_dragEnterEvent(QDragEnterEvent* p0) {
        QWidget::dragEnterEvent(p0);
    }

    void dragMoveEvent(QDragMoveEvent* p0) {
        call_method< void >(py_self, "dragMoveEvent", p0);
    }

    void default_dragMoveEvent(QDragMoveEvent* p0) {
        QWidget::dragMoveEvent(p0);
    }

    void dragLeaveEvent(QDragLeaveEvent* p0) {
        call_method< void >(py_self, "dragLeaveEvent", p0);
    }

    void default_dragLeaveEvent(QDragLeaveEvent* p0) {
        QWidget::dragLeaveEvent(p0);
    }

    void dropEvent(QDropEvent* p0) {
        call_method< void >(py_self, "dropEvent", p0);
    }

    void default_dropEvent(QDropEvent* p0) {
        QWidget::dropEvent(p0);
    }

    void showEvent(QShowEvent* p0) {
        call_method< void >(py_self, "showEvent", p0);
    }

    void default_showEvent(QShowEvent* p0) {
        QWidget::showEvent(p0);
    }

    void hideEvent(QHideEvent* p0) {
        call_method< void >(py_self, "hideEvent", p0);
    }

    void default_hideEvent(QHideEvent* p0) {
        QWidget::hideEvent(p0);
    }

    bool x11Event(XEvent* p0) {
        return call_method< bool >(py_self, "x11Event", p0);
    }

    bool default_x11Event(XEvent* p0) {
        return QWidget::x11Event(p0);
    }

    void changeEvent(QEvent* p0) {
        call_method< void >(py_self, "changeEvent", p0);
    }

    void default_changeEvent(QEvent* p0) {
        QWidget::changeEvent(p0);
    }

    int metric(QPaintDevice::PaintDeviceMetric p0) const {
        return call_method< int >(py_self, "metric", p0);
    }

    int default_metric(QPaintDevice::PaintDeviceMetric p0) const {
        return QWidget::metric(p0);
    }

    void inputMethodEvent(QInputMethodEvent* p0) {
        call_method< void >(py_self, "inputMethodEvent", p0);
    }

    void default_inputMethodEvent(QInputMethodEvent* p0) {
        QWidget::inputMethodEvent(p0);
    }

    QVariant inputMethodQuery(Qt::InputMethodQuery p0) const {
        return call_method< QVariant >(py_self, "inputMethodQuery", p0);
    }

    QVariant default_inputMethodQuery(Qt::InputMethodQuery p0) const {
        return QWidget::inputMethodQuery(p0);
    }

    bool focusNextPrevChild(bool p0) {
        return call_method< bool >(py_self, "focusNextPrevChild", p0);
    }

    bool default_focusNextPrevChild(bool p0) {
        return QWidget::focusNextPrevChild(p0);
    }

    void styleChange(QStyle& p0) {
        call_method< void >(py_self, "styleChange", p0);
    }

    void default_styleChange(QStyle& p0) {
        QWidget::styleChange(p0);
    }

    void enabledChange(bool p0) {
        call_method< void >(py_self, "enabledChange", p0);
    }

    void default_enabledChange(bool p0) {
        QWidget::enabledChange(p0);
    }

    void paletteChange(const QPalette& p0) {
        call_method< void >(py_self, "paletteChange", p0);
    }

    void default_paletteChange(const QPalette& p0) {
        QWidget::paletteChange(p0);
    }

    void fontChange(const QFont& p0) {
        call_method< void >(py_self, "fontChange", p0);
    }

    void default_fontChange(const QFont& p0) {
        QWidget::fontChange(p0);
    }

    void windowActivationChange(bool p0) {
        call_method< void >(py_self, "windowActivationChange", p0);
    }

    void default_windowActivationChange(bool p0) {
        QWidget::windowActivationChange(p0);
    }

    void languageChange() {
        call_method< void >(py_self, "languageChange");
    }

    void default_languageChange() {
        QWidget::languageChange();
    }

    bool eventFilter(QObject* p0, QEvent* p1) {
        return call_method< bool >(py_self, "eventFilter", p0, p1);
    }

    bool default_eventFilter(QObject* p0, QEvent* p1) {
        return QObject::eventFilter(p0, p1);
    }

*/
};

void
export_QWidget()
{
    def("loadUi", loadUi);

    class_< PythonQWidget,
            bases<QObject, QPaintDevice>,
            boost::shared_ptr<PythonQWidget>,
            //std::auto_ptr<QWidget>,
            boost::noncopyable>
        ("QWidget", init<>() )
        .def(init<QWidget*>(args("parent"))[with_custodian_and_ward<2,1>()] )
        //.def(init<QWidget*,Qt::WFlags>() )
        .def("close", &QWidget::close)
        .def("hide", &QWidget::hide)
        .def("lower", &QWidget::lower)
        .def("raise", &QWidget::raise)
        //.def("repaint", &QWidget::repaint)

        .add_property("enabled", &QWidget::isEnabled, &QWidget::setEnabled)
        .def("setDisabled", &QWidget::setDisabled)
        
        .add_property("visible", &QWidget::isVisible, &QWidget::setVisible)
        .def("show", &QWidget::show)
        //.def("setFocus", &QWidget::setFocus)
        .def("setHidden", &QWidget::setHidden)
        .def("setWindowModified", &QWidget::setWindowModified)
        .def("showFullScreen", &QWidget::showFullScreen)
        .def("showMaximized", &QWidget::showMaximized)
        .def("showMinimized", &QWidget::showMinimized)
        .def("showNormal", &QWidget::showNormal)
        .add_property("x", &QWidget::x)
        .add_property("y", &QWidget::y)

        .def("eventFilter", &QWidget::eventFilter, &PythonQWidget::__eventFilter)
        // protected methods (from QObject)
        //.def("protected_childEvent", &PythonQObject::__childEvent)
        .def("childEvent", &PythonQWidget::__childEvent)
        .def("connectNotify", &PythonQWidget::__connectNotify)
        .def("customEvent", &PythonQWidget::__customEvent)
        .def("disconnectNotify", &PythonQWidget::__disconnectNotify)
        .def("timerEvent", &PythonQWidget::__timerEvent)
        
        // events -------------------------------------------------------------
        //.def("mousePressEvent", &PythonQWidget::mousePressEvent) //, &PythonQWidget::default_mousePressEvent)
        .def("mousePressEvent", &PythonQWidget::_mousePressEvent)
        .def("mouseReleaseEvent", &PythonQWidget::mouseReleaseEvent)
        .def("mouseDoubleClickEvent", &PythonQWidget::mouseDoubleClickEvent)
        .def("mouseMoveEvent", &PythonQWidget::mouseMoveEvent)
        
        //.def("update", &QWidget::update)

        /* to be released
       .def_readonly("staticMetaObject", &QWidget::staticMetaObject)
        .def("metaObject", (const QMetaObject* (QWidget::*)() const)&QWidget::metaObject, (const QMetaObject* (PythonQWidget::*)() const)&PythonQWidget::default_metaObject)
        .def("qt_metacast", (void* (QWidget::*)(const char*) )&QWidget::qt_metacast, (void* (PythonQWidget::*)(const char*))&PythonQWidget::default_qt_metacast)
        .def("qt_metacall", (int (QWidget::*)(QMetaObject::Call, int, void**) )&QWidget::qt_metacall, (int (PythonQWidget::*)(QMetaObject::Call, int, void**))&PythonQWidget::default_qt_metacall)
        .def("devType", (int (QWidget::*)() const)&QWidget::devType, (int (PythonQWidget::*)() const)&PythonQWidget::default_devType)
        .def("setVisible", &QWidget::setVisible, &PythonQWidget::default_setVisible)
        .def("sizeHint", &QWidget::sizeHint, &PythonQWidget::default_sizeHint)
        .def("minimumSizeHint", &QWidget::minimumSizeHint, &PythonQWidget::default_minimumSizeHint)
        .def("heightForWidth", &QWidget::heightForWidth, &PythonQWidget::default_heightForWidth)
        .def("paintEngine", (QPaintEngine* (QWidget::*)() const)&QWidget::paintEngine, (QPaintEngine* (PythonQWidget::*)() const)&PythonQWidget::default_paintEngine)
        .def("inputMethodQuery", &QWidget::inputMethodQuery, &PythonQWidget::default_inputMethodQuery)
        .def("eventFilter", &QObject::eventFilter, &PythonQWidget::default_eventFilter)
        .def("tr", &QWidget::tr, QWidget_tr_overloads_1_2())
        .def("trUtf8", &QWidget::trUtf8, QWidget_trUtf8_overloads_1_2())
        .def("winId", &QWidget::winId)
        .def("style", &QWidget::style)
        .def("setStyle", &QWidget::setStyle)
        .def("isTopLevel", &QWidget::isTopLevel)
        .def("isWindow", &QWidget::isWindow)
        .def("isModal", &QWidget::isModal)
        .def("isEnabled", &QWidget::isEnabled)
        .def("isEnabledTo", &QWidget::isEnabledTo)
        .def("isEnabledToTLW", &QWidget::isEnabledToTLW)
        .def("setEnabled", &QWidget::setEnabled)
        .def("setDisabled", &QWidget::setDisabled)
        .def("setWindowModified", &QWidget::setWindowModified)
        .def("frameGeometry", &QWidget::frameGeometry)
        .def("geometry", &QWidget::geometry, return_value_policy< copy_const_reference >())
        .def("normalGeometry", &QWidget::normalGeometry)
        .def("pos", &QWidget::pos)
        .def("frameSize", &QWidget::frameSize)
        .def("size", &QWidget::size)
        .def("width", &QWidget::width)
        .def("height", &QWidget::height)
        .def("rect", &QWidget::rect)
        .def("childrenRect", &QWidget::childrenRect)
        .def("childrenRegion", &QWidget::childrenRegion)
        .def("minimumSize", &QWidget::minimumSize)
        .def("maximumSize", &QWidget::maximumSize)
        .def("minimumWidth", &QWidget::minimumWidth)
        .def("minimumHeight", &QWidget::minimumHeight)
        .def("maximumWidth", &QWidget::maximumWidth)
        .def("maximumHeight", &QWidget::maximumHeight)
        .def("setMinimumSize", (void (QWidget::*)(const QSize&) )&QWidget::setMinimumSize)
        .def("setMinimumSize", (void (QWidget::*)(int, int) )&QWidget::setMinimumSize)
        .def("setMaximumSize", (void (QWidget::*)(const QSize&) )&QWidget::setMaximumSize)
        .def("setMaximumSize", (void (QWidget::*)(int, int) )&QWidget::setMaximumSize)
        .def("setMinimumWidth", &QWidget::setMinimumWidth)
        .def("setMinimumHeight", &QWidget::setMinimumHeight)
        .def("setMaximumWidth", &QWidget::setMaximumWidth)
        .def("setMaximumHeight", &QWidget::setMaximumHeight)
        .def("sizeIncrement", &QWidget::sizeIncrement)
        .def("setSizeIncrement", (void (QWidget::*)(const QSize&) )&QWidget::setSizeIncrement)
        .def("setSizeIncrement", (void (QWidget::*)(int, int) )&QWidget::setSizeIncrement)
        .def("baseSize", &QWidget::baseSize)
        .def("setBaseSize", (void (QWidget::*)(const QSize&) )&QWidget::setBaseSize)
        .def("setBaseSize", (void (QWidget::*)(int, int) )&QWidget::setBaseSize)
        .def("setFixedSize", (void (QWidget::*)(const QSize&) )&QWidget::setFixedSize)
	*/
        .def("setFixedSize", (void (QWidget::*)(int, int) )&QWidget::setFixedSize)
        .def("setFixedWidth", &QWidget::setFixedWidth)
        .def("setFixedHeight", &QWidget::setFixedHeight)
        /*
	.def("mapToGlobal", &QWidget::mapToGlobal)
        .def("mapFromGlobal", &QWidget::mapFromGlobal)
        .def("mapToParent", &QWidget::mapToParent)
        .def("mapFromParent", &QWidget::mapFromParent)
        .def("mapTo", &QWidget::mapTo)
        .def("mapFrom", &QWidget::mapFrom)
        .def("window", &QWidget::window)
        .def("topLevelWidget", &QWidget::topLevelWidget)
        .def("palette", &QWidget::palette, return_value_policy< copy_const_reference >())
        .def("setPalette", &QWidget::setPalette)
        .def("setBackgroundRole", &QWidget::setBackgroundRole)
        .def("backgroundRole", &QWidget::backgroundRole)
        .def("setForegroundRole", &QWidget::setForegroundRole)
        .def("foregroundRole", &QWidget::foregroundRole)
        */
        .def("font", &QWidget::font, return_value_policy< copy_const_reference >())
        .def("setFont", &QWidget::setFont)
        /*
        .def("fontMetrics", &QWidget::fontMetrics)
        .def("fontInfo", &QWidget::fontInfo)
        .def("cursor", &QWidget::cursor)
        .def("setCursor", &QWidget::setCursor)
        .def("unsetCursor", &QWidget::unsetCursor)
        .def("setMouseTracking", &QWidget::setMouseTracking)
        .def("hasMouseTracking", &QWidget::hasMouseTracking)
        .def("underMouse", &QWidget::underMouse)
        .def("setMask", (void (QWidget::*)(const QBitmap&) )&QWidget::setMask)
        .def("setMask", (void (QWidget::*)(const QRegion&) )&QWidget::setMask)
        .def("mask", &QWidget::mask)
        .def("clearMask", &QWidget::clearMask)*/

        .add_property("windowTitle", &QWidget::windowTitle, &QWidget::setWindowTitle)
        
        /*
        .def("setWindowIcon", &QWidget::setWindowIcon)
        .def("windowIcon", &QWidget::windowIcon)
        .def("setWindowIconText", &QWidget::setWindowIconText)
        .def("windowIconText", &QWidget::windowIconText)
        .def("setWindowRole", &QWidget::setWindowRole)
        .def("windowRole", &QWidget::windowRole)
        .def("setWindowOpacity", &QWidget::setWindowOpacity)
        .def("windowOpacity", &QWidget::windowOpacity)
        .def("isWindowModified", &QWidget::isWindowModified)
        .def("setToolTip", &QWidget::setToolTip)
        .def("toolTip", &QWidget::toolTip)
        .def("setStatusTip", &QWidget::setStatusTip)
        .def("statusTip", &QWidget::statusTip)
        .def("setWhatsThis", &QWidget::setWhatsThis)
        .def("whatsThis", &QWidget::whatsThis)
        .def("accessibleName", &QWidget::accessibleName)
        .def("setAccessibleName", &QWidget::setAccessibleName)
        .def("accessibleDescription", &QWidget::accessibleDescription)
        .def("setAccessibleDescription", &QWidget::setAccessibleDescription)
        .def("setLayoutDirection", &QWidget::setLayoutDirection)
        .def("layoutDirection", &QWidget::layoutDirection)
        .def("unsetLayoutDirection", &QWidget::unsetLayoutDirection)
        .def("isRightToLeft", &QWidget::isRightToLeft)
        .def("isLeftToRight", &QWidget::isLeftToRight)
        .def("setFocus", (void (QWidget::*)() )&QWidget::setFocus)
        .def("isActiveWindow", &QWidget::isActiveWindow)
        .def("activateWindow", &QWidget::activateWindow)
        .def("clearFocus", &QWidget::clearFocus)
        .def("setFocus", (void (QWidget::*)(Qt::FocusReason) )&QWidget::setFocus)
        .def("focusPolicy", &QWidget::focusPolicy)
        .def("setFocusPolicy", &QWidget::setFocusPolicy)
        .def("hasFocus", &QWidget::hasFocus)
        .def("setTabOrder", &QWidget::setTabOrder) */
        .def("setFocusProxy", &QWidget::setFocusProxy, with_custodian_and_ward<1,2>() )
        .def("focusProxy",
             &QWidget::focusProxy,
             return_value_policy<reference_existing_object>() )
        /*.def("contextMenuPolicy", &QWidget::contextMenuPolicy)
        .def("setContextMenuPolicy", &QWidget::setContextMenuPolicy)
        .def("grabMouse", (void (QWidget::*)() )&QWidget::grabMouse)
        .def("grabMouse", (void (QWidget::*)(const QCursor&) )&QWidget::grabMouse)
        .def("releaseMouse", &QWidget::releaseMouse)
        .def("grabKeyboard", &QWidget::grabKeyboard)
        .def("releaseKeyboard", &QWidget::releaseKeyboard)
        .def("grabShortcut", &QWidget::grabShortcut, QWidget_grabShortcut_overloads_1_2())
        .def("releaseShortcut", &QWidget::releaseShortcut)
        .def("setShortcutEnabled", &QWidget::setShortcutEnabled, QWidget_setShortcutEnabled_overloads_1_2())
        .def("mouseGrabber", &QWidget::mouseGrabber)
        .def("keyboardGrabber", &QWidget::keyboardGrabber)
        .def("updatesEnabled", &QWidget::updatesEnabled)
        .def("setUpdatesEnabled", &QWidget::setUpdatesEnabled)
        .def("update", (void (QWidget::*)() )&QWidget::update)
        .def("repaint", (void (QWidget::*)() )&QWidget::repaint)
        .def("update", (void (QWidget::*)(int, int, int, int) )&QWidget::update)
        .def("update", (void (QWidget::*)(const QRect&) )&QWidget::update)
        .def("update", (void (QWidget::*)(const QRegion&) )&QWidget::update)
        .def("repaint", (void (QWidget::*)(int, int, int, int) )&QWidget::repaint)
        .def("repaint", (void (QWidget::*)(const QRect&) )&QWidget::repaint)
        .def("repaint", (void (QWidget::*)(const QRegion&) )&QWidget::repaint)
        .def("setHidden", &QWidget::setHidden)
        .def("show", &QWidget::show)
        .def("hide", &QWidget::hide)
        .def("setShown", &QWidget::setShown)
        .def("showMinimized", &QWidget::showMinimized)
        .def("showMaximized", &QWidget::showMaximized)
        .def("showFullScreen", &QWidget::showFullScreen)
        .def("showNormal", &QWidget::showNormal)
        .def("close", &QWidget::close)
        .def("raise", &QWidget::raise)
        .def("lower", &QWidget::lower)
        .def("stackUnder", &QWidget::stackUnder)
        */
        .def("move", (void (QWidget::*)(int, int) )&QWidget::move)
        //.def("move", (void (QWidget::*)(const QPoint&) )&QWidget::move)
        .def("resize", (void (QWidget::*)(int, int) )&QWidget::resize)
        //.def("resize", (void (QWidget::*)(const QSize&) )&QWidget::resize)
        .def("setGeometry", (void (QWidget::*)(int, int, int, int) )&QWidget::setGeometry)
        //.def("setGeometry", (void (QWidget::*)(const QRect&) )&QWidget::setGeometry)
        /*
        .def("adjustSize", &QWidget::adjustSize)
        .def("isVisible", &QWidget::isVisible)
        .def("isVisibleTo", &QWidget::isVisibleTo)
        .def("isHidden", &QWidget::isHidden)
        .def("isMinimized", &QWidget::isMinimized)
        .def("isMaximized", &QWidget::isMaximized)
        .def("isFullScreen", &QWidget::isFullScreen)
        .def("windowState", &QWidget::windowState)
        .def("setWindowState", &QWidget::setWindowState)
        .def("overrideWindowState", &QWidget::overrideWindowState)
        .def("sizePolicy", &QWidget::sizePolicy)
        .def("setSizePolicy", (void (QWidget::*)(QSizePolicy) )&QWidget::setSizePolicy)
        .def("setSizePolicy", (void (QWidget::*)(QSizePolicy::Policy, QSizePolicy::Policy) )&QWidget::setSizePolicy)
        .def("visibleRegion", &QWidget::visibleRegion)
        .def("setContentsMargins", &QWidget::setContentsMargins)
        .def("getContentsMargins", &QWidget::getContentsMargins)
        .def("contentsRect", &QWidget::contentsRect)
        */
        
        //.def("layout", &QWidget::layout, return_internal_reference<>() )
        .def("layout", &QWidget::layout, return_value_policy<reference_existing_object>() )
        .def("setLayout", &QWidget::setLayout, with_custodian_and_ward<2,1>() )
        
        //.def("updateGeometry", &QWidget::updateGeometry)
        
        .def("setParent",
             (void (QWidget::*)(QWidget*) )&QWidget::setParent,
             with_custodian_and_ward<2,1>() )
        .def("setParent",
             (void (QWidget::*)(QWidget*, Qt::WFlags) )&QWidget::setParent,
             with_custodian_and_ward<2,1>())

        /*
        .def("scroll", (void (QWidget::*)(int, int) )&QWidget::scroll)
        .def("scroll", (void (QWidget::*)(int, int, const QRect&) )&QWidget::scroll)
        .def("focusWidget", &QWidget::focusWidget)
        .def("nextInFocusChain", &QWidget::nextInFocusChain)
        .def("acceptDrops", &QWidget::acceptDrops)
        .def("setAcceptDrops", &QWidget::setAcceptDrops)
        .def("addAction", &QWidget::addAction)
        .def("addActions", &QWidget::addActions)
        .def("insertAction", &QWidget::insertAction)
        .def("insertActions", &QWidget::insertActions)
        .def("removeAction", &QWidget::removeAction)
        .def("actions", &QWidget::actions)
        */
        .def("parentWidget", &QWidget::parentWidget, return_value_policy<reference_existing_object>() );
        //.def("parentWidget", &QWidget::parentWidget, return_internal_reference<>() );

        /*
        .def("setWindowFlags", &QWidget::setWindowFlags)
        .def("windowFlags", &QWidget::windowFlags)
        .def("overrideWindowFlags", &QWidget::overrideWindowFlags)
        .def("windowType", &QWidget::windowType)
        .def("find", &QWidget::find)
        .def("childAt", (QWidget* (QWidget::*)(int, int) const)&QWidget::childAt)
        .def("childAt", (QWidget* (QWidget::*)(const QPoint&) const)&QWidget::childAt)
        .def("x11Info", &QWidget::x11Info, return_value_policy< copy_const_reference >())
        .def("x11PictureHandle", &QWidget::x11PictureHandle)
        .def("handle", &QWidget::handle)
        .def("setAttribute", &QWidget::setAttribute, QWidget_setAttribute_overloads_1_2())
        .def("testAttribute", &QWidget::testAttribute)
        .def("ensurePolished", &QWidget::ensurePolished)
        .def("inputContext", &QWidget::inputContext)
        .def("setInputContext", &QWidget::setInputContext)
        .def("isAncestorOf", &QWidget::isAncestorOf)
        .staticmethod("setTabOrder")
        .staticmethod("keyboardGrabber")
        .staticmethod("mouseGrabber")
        .staticmethod("find")
        */
    ;

}
