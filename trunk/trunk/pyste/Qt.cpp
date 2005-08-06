
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <QtCore/QCoreApplication>
#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QApplication>
#include <QtGui/QPaintDevice>
#include <QtGui/QWidget>

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

struct QCoreApplication_Wrapper: QCoreApplication
{
    QCoreApplication_Wrapper(PyObject* py_self_, int& p0, char** p1):
        QCoreApplication(p0, p1), py_self(py_self_) {}

    const QMetaObject* metaObject() const {
        return call_method< const QMetaObject* >(py_self, "metaObject");
    }

    const QMetaObject* default_metaObject() const {
        return QCoreApplication::metaObject();
    }

    void* qt_metacast(const char* p0) {
        return call_method< void* >(py_self, "qt_metacast", p0);
    }

    void* default_qt_metacast(const char* p0) {
        return QCoreApplication::qt_metacast(p0);
    }

    int qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return call_method< int >(py_self, "qt_metacall", p0, p1, p2);
    }

    int default_qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return QCoreApplication::qt_metacall(p0, p1, p2);
    }

    bool notify(QObject* p0, QEvent* p1) {
        return call_method< bool >(py_self, "notify", p0, p1);
    }

    bool default_notify(QObject* p0, QEvent* p1) {
        return QCoreApplication::notify(p0, p1);
    }

    bool event(QEvent* p0) {
        return call_method< bool >(py_self, "event", p0);
    }

    bool default_event(QEvent* p0) {
        return QCoreApplication::event(p0);
    }

    bool compressEvent(QEvent* p0, QObject* p1, QPostEventList* p2) {
        return call_method< bool >(py_self, "compressEvent", p0, p1, p2);
    }

    bool default_compressEvent(QEvent* p0, QObject* p1, QPostEventList* p2) {
        return QCoreApplication::compressEvent(p0, p1, p2);
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

BOOST_PYTHON_FUNCTION_OVERLOADS(QCoreApplication_tr_overloads_1_2, QCoreApplication::tr, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QCoreApplication_trUtf8_overloads_1_2, QCoreApplication::trUtf8, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QCoreApplication_processEvents_overloads_0_1, QCoreApplication::processEvents, 0, 1)

BOOST_PYTHON_FUNCTION_OVERLOADS(QCoreApplication_exit_overloads_0_1, QCoreApplication::exit, 0, 1)

BOOST_PYTHON_FUNCTION_OVERLOADS(QCoreApplication_translate_overloads_2_4, QCoreApplication::translate, 2, 4)

struct QPaintDevice_Wrapper: QPaintDevice
{
    int devType() const {
        return call_method< int >(py_self, "devType");
    }

    int default_devType() const {
        return QPaintDevice::devType();
    }

    QPaintEngine* paintEngine() const {
        return call_method< QPaintEngine* >(py_self, "paintEngine");
    }

    int metric(QPaintDevice::PaintDeviceMetric p0) const {
        return call_method< int >(py_self, "metric", p0);
    }

    int default_metric(QPaintDevice::PaintDeviceMetric p0) const {
        return QPaintDevice::metric(p0);
    }

    PyObject* py_self;
};

struct QWidget_Wrapper: QWidget
{
    QWidget_Wrapper(PyObject* py_self_):
        QWidget(), py_self(py_self_) {}

    QWidget_Wrapper(PyObject* py_self_, QWidget* p0):
        QWidget(p0), py_self(py_self_) {}

    QWidget_Wrapper(PyObject* py_self_, QWidget* p0, Qt::WFlags p1):
        QWidget(p0, p1), py_self(py_self_) {}

    const QMetaObject* metaObject() const {
        return call_method< const QMetaObject* >(py_self, "metaObject");
    }

    const QMetaObject* default_metaObject() const {
        return QWidget::metaObject();
    }

    void* qt_metacast(const char* p0) {
        return call_method< void* >(py_self, "qt_metacast", p0);
    }

    void* default_qt_metacast(const char* p0) {
        return QWidget::qt_metacast(p0);
    }

    int qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return call_method< int >(py_self, "qt_metacall", p0, p1, p2);
    }

    int default_qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return QWidget::qt_metacall(p0, p1, p2);
    }

    int devType() const {
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

    bool event(QEvent* p0) {
        return call_method< bool >(py_self, "event", p0);
    }

    bool default_event(QEvent* p0) {
        return QWidget::event(p0);
    }

    void mousePressEvent(QMouseEvent* p0) {
        call_method< void >(py_self, "mousePressEvent", p0);
    }

    void default_mousePressEvent(QMouseEvent* p0) {
        QWidget::mousePressEvent(p0);
    }

    void mouseReleaseEvent(QMouseEvent* p0) {
        call_method< void >(py_self, "mouseReleaseEvent", p0);
    }

    void default_mouseReleaseEvent(QMouseEvent* p0) {
        QWidget::mouseReleaseEvent(p0);
    }

    void mouseDoubleClickEvent(QMouseEvent* p0) {
        call_method< void >(py_self, "mouseDoubleClickEvent", p0);
    }

    void default_mouseDoubleClickEvent(QMouseEvent* p0) {
        QWidget::mouseDoubleClickEvent(p0);
    }

    void mouseMoveEvent(QMouseEvent* p0) {
        call_method< void >(py_self, "mouseMoveEvent", p0);
    }

    void default_mouseMoveEvent(QMouseEvent* p0) {
        QWidget::mouseMoveEvent(p0);
    }

    void wheelEvent(QWheelEvent* p0) {
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

BOOST_PYTHON_FUNCTION_OVERLOADS(QWidget_tr_overloads_1_2, QWidget::tr, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QWidget_trUtf8_overloads_1_2, QWidget::trUtf8, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QWidget_grabShortcut_overloads_1_2, grabShortcut, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QWidget_setShortcutEnabled_overloads_1_2, setShortcutEnabled, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QWidget_setAttribute_overloads_1_2, setAttribute, 1, 2)

struct QApplication_Wrapper: QApplication
{
    QApplication_Wrapper(PyObject* py_self_, int& p0, char** p1):
        QApplication(p0, p1), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, int& p0, char** p1, bool p2):
        QApplication(p0, p1, p2), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, int& p0, char** p1, QApplication::Type p2):
        QApplication(p0, p1, p2), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0):
        QApplication(p0), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0, Qt::HANDLE p1):
        QApplication(p0, p1), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0, Qt::HANDLE p1, Qt::HANDLE p2):
        QApplication(p0, p1, p2), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0, int& p1, char** p2):
        QApplication(p0, p1, p2), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0, int& p1, char** p2, Qt::HANDLE p3):
        QApplication(p0, p1, p2, p3), py_self(py_self_) {}

    QApplication_Wrapper(PyObject* py_self_, Display* p0, int& p1, char** p2, Qt::HANDLE p3, Qt::HANDLE p4):
        QApplication(p0, p1, p2, p3, p4), py_self(py_self_) {}

    const QMetaObject* metaObject() const {
        return call_method< const QMetaObject* >(py_self, "metaObject");
    }

    const QMetaObject* default_metaObject() const {
        return QApplication::metaObject();
    }

    void* qt_metacast(const char* p0) {
        return call_method< void* >(py_self, "qt_metacast", p0);
    }

    void* default_qt_metacast(const char* p0) {
        return QApplication::qt_metacast(p0);
    }

    int qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return call_method< int >(py_self, "qt_metacall", p0, p1, p2);
    }

    int default_qt_metacall(QMetaObject::Call p0, int p1, void** p2) {
        return QApplication::qt_metacall(p0, p1, p2);
    }

    bool x11EventFilter(XEvent* p0) {
        return call_method< bool >(py_self, "x11EventFilter", p0);
    }

    bool default_x11EventFilter(XEvent* p0) {
        return QApplication::x11EventFilter(p0);
    }

    int x11ClientMessage(QWidget* p0, XEvent* p1, bool p2) {
        return call_method< int >(py_self, "x11ClientMessage", p0, p1, p2);
    }

    int default_x11ClientMessage(QWidget* p0, XEvent* p1, bool p2) {
        return QApplication::x11ClientMessage(p0, p1, p2);
    }

    void commitData(QSessionManager& p0) {
        call_method< void >(py_self, "commitData", p0);
    }

    void default_commitData(QSessionManager& p0) {
        QApplication::commitData(p0);
    }

    void saveState(QSessionManager& p0) {
        call_method< void >(py_self, "saveState", p0);
    }

    void default_saveState(QSessionManager& p0) {
        QApplication::saveState(p0);
    }

    bool notify(QObject* p0, QEvent* p1) {
        return call_method< bool >(py_self, "notify", p0, p1);
    }

    bool default_notify(QObject* p0, QEvent* p1) {
        return QApplication::notify(p0, p1);
    }

    bool event(QEvent* p0) {
        return call_method< bool >(py_self, "event", p0);
    }

    bool default_event(QEvent* p0) {
        return QApplication::event(p0);
    }

    bool compressEvent(QEvent* p0, QObject* p1, QPostEventList* p2) {
        return call_method< bool >(py_self, "compressEvent", p0, p1, p2);
    }

    bool default_compressEvent(QEvent* p0, QObject* p1, QPostEventList* p2) {
        return QApplication::compressEvent(p0, p1, p2);
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

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_tr_overloads_1_2, QApplication::tr, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_trUtf8_overloads_1_2, QApplication::trUtf8, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_setPalette_overloads_1_2, QApplication::setPalette, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_font_overloads_0_1, QApplication::font, 0, 1)

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_setFont_overloads_1_2, QApplication::setFont, 1, 2)

BOOST_PYTHON_FUNCTION_OVERLOADS(QApplication_setEffectEnabled_overloads_1_2, QApplication::setEffectEnabled, 1, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(Qt)
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

    scope* QCoreApplication_scope = new scope(
    class_< QCoreApplication, bases< QObject > , boost::noncopyable, QCoreApplication_Wrapper >("QCoreApplication", init< int&, char** >())
        .def_readonly("staticMetaObject", &QCoreApplication::staticMetaObject)
        .def("metaObject", (const QMetaObject* (QCoreApplication::*)() const)&QCoreApplication::metaObject, (const QMetaObject* (QCoreApplication_Wrapper::*)() const)&QCoreApplication_Wrapper::default_metaObject)
        .def("qt_metacast", (void* (QCoreApplication::*)(const char*) )&QCoreApplication::qt_metacast, (void* (QCoreApplication_Wrapper::*)(const char*))&QCoreApplication_Wrapper::default_qt_metacast)
        .def("qt_metacall", (int (QCoreApplication::*)(QMetaObject::Call, int, void**) )&QCoreApplication::qt_metacall, (int (QCoreApplication_Wrapper::*)(QMetaObject::Call, int, void**))&QCoreApplication_Wrapper::default_qt_metacall)
        .def("notify", &QCoreApplication::notify, &QCoreApplication_Wrapper::default_notify)
        .def("eventFilter", &QObject::eventFilter, &QCoreApplication_Wrapper::default_eventFilter)
        .def("tr", &QCoreApplication::tr, QCoreApplication_tr_overloads_1_2())
        .def("trUtf8", &QCoreApplication::trUtf8, QCoreApplication_trUtf8_overloads_1_2())
        .def("argc", &QCoreApplication::argc)
        .def("argv", &QCoreApplication::argv)
        .def("setOrganizationDomain", &QCoreApplication::setOrganizationDomain)
        .def("organizationDomain", &QCoreApplication::organizationDomain)
        .def("setOrganizationName", &QCoreApplication::setOrganizationName)
        .def("organizationName", &QCoreApplication::organizationName)
        .def("setApplicationName", &QCoreApplication::setApplicationName)
        .def("applicationName", &QCoreApplication::applicationName)
        .def("instance", &QCoreApplication::instance)
        .def("exec", &QCoreApplication::exec)
        .def("processEvents", (void (*)(QFlags<QEventLoop::ProcessEventsFlag>))&QCoreApplication::processEvents, QCoreApplication_processEvents_overloads_0_1())
        .def("processEvents", (void (*)(QFlags<QEventLoop::ProcessEventsFlag>, int))&QCoreApplication::processEvents)
        .def("exit", &QCoreApplication::exit, QCoreApplication_exit_overloads_0_1())
        .def("sendEvent", &QCoreApplication::sendEvent)
        .def("postEvent", &QCoreApplication::postEvent)
        .def("sendPostedEvents", (void (*)(QObject*, int))&QCoreApplication::sendPostedEvents)
        .def("sendPostedEvents", (void (*)())&QCoreApplication::sendPostedEvents)
        .def("removePostedEvents", &QCoreApplication::removePostedEvents)
        .def("hasPendingEvents", &QCoreApplication::hasPendingEvents)
        .def("startingUp", &QCoreApplication::startingUp)
        .def("closingDown", &QCoreApplication::closingDown)
        .def("applicationDirPath", &QCoreApplication::applicationDirPath)
        .def("applicationFilePath", &QCoreApplication::applicationFilePath)
        .def("setLibraryPaths", &QCoreApplication::setLibraryPaths)
        .def("libraryPaths", &QCoreApplication::libraryPaths)
        .def("addLibraryPath", &QCoreApplication::addLibraryPath)
        .def("removeLibraryPath", &QCoreApplication::removeLibraryPath)
        .def("installTranslator", &QCoreApplication::installTranslator)
        .def("removeTranslator", &QCoreApplication::removeTranslator)
        .def("translate", &QCoreApplication::translate, QCoreApplication_translate_overloads_2_4())
        .def("flush", &QCoreApplication::flush)
        .def("watchUnixSignal", &QCoreApplication::watchUnixSignal)
        .def("setEventFilter", &QCoreApplication::setEventFilter)
        .def("filterEvent", &QCoreApplication::filterEvent)
        .def("quit", &QCoreApplication::quit)
        .staticmethod("setLibraryPaths")
        .staticmethod("setOrganizationName")
        .staticmethod("applicationDirPath")
        .staticmethod("flush")
        .staticmethod("closingDown")
        .staticmethod("applicationName")
        .staticmethod("startingUp")
        .staticmethod("sendEvent")
        .staticmethod("tr")
        .staticmethod("instance")
        .staticmethod("organizationDomain")
        .staticmethod("exit")
        .staticmethod("applicationFilePath")
        .staticmethod("translate")
        .staticmethod("exec")
        .staticmethod("processEvents")
        .staticmethod("removeTranslator")
        .staticmethod("argv")
        .staticmethod("quit")
        .staticmethod("setOrganizationDomain")
        .staticmethod("argc")
        .staticmethod("setApplicationName")
        .staticmethod("addLibraryPath")
        .staticmethod("installTranslator")
        .staticmethod("libraryPaths")
        .staticmethod("organizationName")
        .staticmethod("sendPostedEvents")
        .staticmethod("trUtf8")
        .staticmethod("removePostedEvents")
        .staticmethod("hasPendingEvents")
        .staticmethod("postEvent")
        .staticmethod("watchUnixSignal")
        .staticmethod("removeLibraryPath")
    );

    enum_< QCoreApplication::Encoding >("Encoding")
        .value("DefaultCodec", QCoreApplication::DefaultCodec)
        .value("UnicodeUTF8", QCoreApplication::UnicodeUTF8)
    ;

    delete QCoreApplication_scope;


    class_< QWidget, bases< QObject, QPaintDevice > , boost::noncopyable, QWidget_Wrapper >("QWidget", init< optional< QWidget*, Qt::WFlags > >())
        .def_readonly("staticMetaObject", &QWidget::staticMetaObject)
        .def("metaObject", (const QMetaObject* (QWidget::*)() const)&QWidget::metaObject, (const QMetaObject* (QWidget_Wrapper::*)() const)&QWidget_Wrapper::default_metaObject)
        .def("qt_metacast", (void* (QWidget::*)(const char*) )&QWidget::qt_metacast, (void* (QWidget_Wrapper::*)(const char*))&QWidget_Wrapper::default_qt_metacast)
        .def("qt_metacall", (int (QWidget::*)(QMetaObject::Call, int, void**) )&QWidget::qt_metacall, (int (QWidget_Wrapper::*)(QMetaObject::Call, int, void**))&QWidget_Wrapper::default_qt_metacall)
        .def("devType", (int (QWidget::*)() const)&QWidget::devType, (int (QWidget_Wrapper::*)() const)&QWidget_Wrapper::default_devType)
        .def("setVisible", &QWidget::setVisible, &QWidget_Wrapper::default_setVisible)
        .def("sizeHint", &QWidget::sizeHint, &QWidget_Wrapper::default_sizeHint)
        .def("minimumSizeHint", &QWidget::minimumSizeHint, &QWidget_Wrapper::default_minimumSizeHint)
        .def("heightForWidth", &QWidget::heightForWidth, &QWidget_Wrapper::default_heightForWidth)
        .def("paintEngine", (QPaintEngine* (QWidget::*)() const)&QWidget::paintEngine, (QPaintEngine* (QWidget_Wrapper::*)() const)&QWidget_Wrapper::default_paintEngine)
        .def("inputMethodQuery", &QWidget::inputMethodQuery, &QWidget_Wrapper::default_inputMethodQuery)
        .def("eventFilter", &QObject::eventFilter, &QWidget_Wrapper::default_eventFilter)
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
        .def("x", &QWidget::x)
        .def("y", &QWidget::y)
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
        .def("setFixedSize", (void (QWidget::*)(int, int) )&QWidget::setFixedSize)
        .def("setFixedWidth", &QWidget::setFixedWidth)
        .def("setFixedHeight", &QWidget::setFixedHeight)
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
        .def("font", &QWidget::font, return_value_policy< copy_const_reference >())
        .def("setFont", &QWidget::setFont)
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
        .def("clearMask", &QWidget::clearMask)
        .def("setWindowTitle", &QWidget::setWindowTitle)
        .def("windowTitle", &QWidget::windowTitle)
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
        .def("setTabOrder", &QWidget::setTabOrder)
        .def("setFocusProxy", &QWidget::setFocusProxy)
        .def("focusProxy", &QWidget::focusProxy)
        .def("contextMenuPolicy", &QWidget::contextMenuPolicy)
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
        .def("move", (void (QWidget::*)(int, int) )&QWidget::move)
        .def("move", (void (QWidget::*)(const QPoint&) )&QWidget::move)
        .def("resize", (void (QWidget::*)(int, int) )&QWidget::resize)
        .def("resize", (void (QWidget::*)(const QSize&) )&QWidget::resize)
        .def("setGeometry", (void (QWidget::*)(int, int, int, int) )&QWidget::setGeometry)
        .def("setGeometry", (void (QWidget::*)(const QRect&) )&QWidget::setGeometry)
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
        .def("layout", &QWidget::layout)
        .def("setLayout", &QWidget::setLayout)
        .def("updateGeometry", &QWidget::updateGeometry)
        .def("setParent", (void (QWidget::*)(QWidget*) )&QWidget::setParent)
        .def("setParent", (void (QWidget::*)(QWidget*, Qt::WFlags) )&QWidget::setParent)
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
        .def("parentWidget", &QWidget::parentWidget)
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
        .staticmethod("trUtf8")
        .staticmethod("tr")
        .staticmethod("setTabOrder")
        .staticmethod("keyboardGrabber")
        .staticmethod("mouseGrabber")
        .staticmethod("find")
    ;

    scope* QApplication_scope = new scope(
    class_< QApplication, bases< QCoreApplication > , boost::noncopyable, QApplication_Wrapper >("QApplication", init< int&, char** >())
        .def(init< int&, char**, bool >())
        .def(init< int&, char**, QApplication::Type >())
        .def(init< Display*, optional< Qt::HANDLE, Qt::HANDLE > >())
        .def(init< Display*, int&, char**, optional< Qt::HANDLE, Qt::HANDLE > >())
        .def_readonly("staticMetaObject", &QApplication::staticMetaObject)
        .def("metaObject", (const QMetaObject* (QApplication::*)() const)&QApplication::metaObject, (const QMetaObject* (QApplication_Wrapper::*)() const)&QApplication_Wrapper::default_metaObject)
        .def("qt_metacast", (void* (QApplication::*)(const char*) )&QApplication::qt_metacast, (void* (QApplication_Wrapper::*)(const char*))&QApplication_Wrapper::default_qt_metacast)
        .def("qt_metacall", (int (QApplication::*)(QMetaObject::Call, int, void**) )&QApplication::qt_metacall, (int (QApplication_Wrapper::*)(QMetaObject::Call, int, void**))&QApplication_Wrapper::default_qt_metacall)
        .def("x11EventFilter", &QApplication::x11EventFilter, &QApplication_Wrapper::default_x11EventFilter)
        .def("x11ClientMessage", &QApplication::x11ClientMessage, &QApplication_Wrapper::default_x11ClientMessage)
        .def("commitData", &QApplication::commitData, &QApplication_Wrapper::default_commitData)
        .def("saveState", &QApplication::saveState, &QApplication_Wrapper::default_saveState)
        .def("notify", (bool (QApplication::*)(QObject*, QEvent*) )&QApplication::notify, (bool (QApplication_Wrapper::*)(QObject*, QEvent*))&QApplication_Wrapper::default_notify)
        .def("eventFilter", &QObject::eventFilter, &QApplication_Wrapper::default_eventFilter)
        .def("tr", &QApplication::tr, QApplication_tr_overloads_1_2())
        .def("trUtf8", &QApplication::trUtf8, QApplication_trUtf8_overloads_1_2())
        .def("type", &QApplication::type)
        .def("style", &QApplication::style)
        .def("setStyle", (void (*)(QStyle*))&QApplication::setStyle)
        .def("setStyle", (QStyle* (*)(const QString&))&QApplication::setStyle)
        .def("colorSpec", &QApplication::colorSpec)
        .def("setColorSpec", &QApplication::setColorSpec)
        .def("overrideCursor", &QApplication::overrideCursor)
        .def("setOverrideCursor", &QApplication::setOverrideCursor)
        .def("changeOverrideCursor", &QApplication::changeOverrideCursor)
        .def("restoreOverrideCursor", &QApplication::restoreOverrideCursor)
        .def("palette", (QPalette (*)())&QApplication::palette)
        .def("palette", (QPalette (*)(const QWidget*))&QApplication::palette)
        .def("palette", (QPalette (*)(const char*))&QApplication::palette)
        .def("setPalette", &QApplication::setPalette, QApplication_setPalette_overloads_1_2())
        .def("font", &QApplication::font, QApplication_font_overloads_0_1())
        .def("setFont", &QApplication::setFont, QApplication_setFont_overloads_1_2())
        .def("fontMetrics", &QApplication::fontMetrics)
        .def("setWindowIcon", &QApplication::setWindowIcon)
        .def("windowIcon", &QApplication::windowIcon)
        .def("allWidgets", &QApplication::allWidgets)
        .def("topLevelWidgets", &QApplication::topLevelWidgets)
        .def("desktop", &QApplication::desktop)
        .def("activePopupWidget", &QApplication::activePopupWidget)
        .def("activeModalWidget", &QApplication::activeModalWidget)
        .def("clipboard", &QApplication::clipboard)
        .def("focusWidget", &QApplication::focusWidget)
        .def("activeWindow", &QApplication::activeWindow)
        .def("setActiveWindow", &QApplication::setActiveWindow)
        .def("widgetAt", (QWidget* (*)(const QPoint&))&QApplication::widgetAt)
        .def("widgetAt", (QWidget* (*)(int, int))&QApplication::widgetAt)
        .def("topLevelAt", (QWidget* (*)(const QPoint&))&QApplication::topLevelAt)
        .def("topLevelAt", (QWidget* (*)(int, int))&QApplication::topLevelAt)
        .def("syncX", &QApplication::syncX)
        .def("beep", &QApplication::beep)
        .def("keyboardModifiers", &QApplication::keyboardModifiers)
        .def("mouseButtons", &QApplication::mouseButtons)
        .def("setDesktopSettingsAware", &QApplication::setDesktopSettingsAware)
        .def("desktopSettingsAware", &QApplication::desktopSettingsAware)
        .def("setCursorFlashTime", &QApplication::setCursorFlashTime)
        .def("cursorFlashTime", &QApplication::cursorFlashTime)
        .def("setDoubleClickInterval", &QApplication::setDoubleClickInterval)
        .def("doubleClickInterval", &QApplication::doubleClickInterval)
        .def("setKeyboardInputInterval", &QApplication::setKeyboardInputInterval)
        .def("keyboardInputInterval", &QApplication::keyboardInputInterval)
        .def("setWheelScrollLines", &QApplication::setWheelScrollLines)
        .def("wheelScrollLines", &QApplication::wheelScrollLines)
        .def("setGlobalStrut", &QApplication::setGlobalStrut)
        .def("globalStrut", &QApplication::globalStrut)
        .def("setStartDragTime", &QApplication::setStartDragTime)
        .def("startDragTime", &QApplication::startDragTime)
        .def("setStartDragDistance", &QApplication::setStartDragDistance)
        .def("startDragDistance", &QApplication::startDragDistance)
        .def("setLayoutDirection", &QApplication::setLayoutDirection)
        .def("layoutDirection", &QApplication::layoutDirection)
        .def("isRightToLeft", &QApplication::isRightToLeft)
        .def("isLeftToRight", &QApplication::isLeftToRight)
        .def("isEffectEnabled", &QApplication::isEffectEnabled)
        .def("setEffectEnabled", &QApplication::setEffectEnabled, QApplication_setEffectEnabled_overloads_1_2())
        .def("x11ProcessEvent", &QApplication::x11ProcessEvent)
        .def("isSessionRestored", &QApplication::isSessionRestored)
        .def("sessionId", &QApplication::sessionId)
        .def("sessionKey", &QApplication::sessionKey)
        .def("setInputContext", &QApplication::setInputContext)
        .def("inputContext", &QApplication::inputContext)
        .def("exec", &QApplication::exec)
        .def("setQuitOnLastWindowClosed", &QApplication::setQuitOnLastWindowClosed)
        .def("quitOnLastWindowClosed", &QApplication::quitOnLastWindowClosed)
        .def("closeAllWindows", &QApplication::closeAllWindows)
        .def("aboutQt", &QApplication::aboutQt)
        .staticmethod("activePopupWidget")
        .staticmethod("closeAllWindows")
        .staticmethod("syncX")
        .staticmethod("topLevelWidgets")
        .staticmethod("setEffectEnabled")
        .staticmethod("setStyle")
        .staticmethod("focusWidget")
        .staticmethod("allWidgets")
        .staticmethod("font")
        .staticmethod("quitOnLastWindowClosed")
        .staticmethod("changeOverrideCursor")
        .staticmethod("setLayoutDirection")
        .staticmethod("aboutQt")
        .staticmethod("style")
        .staticmethod("widgetAt")
        .staticmethod("setDoubleClickInterval")
        .staticmethod("startDragDistance")
        .staticmethod("layoutDirection")
        .staticmethod("wheelScrollLines")
        .staticmethod("tr")
        .staticmethod("setGlobalStrut")
        .staticmethod("desktop")
        .staticmethod("beep")
        .staticmethod("clipboard")
        .staticmethod("isEffectEnabled")
        .staticmethod("keyboardModifiers")
        .staticmethod("type")
        .staticmethod("setWheelScrollLines")
        .staticmethod("activeWindow")
        .staticmethod("isRightToLeft")
        .staticmethod("topLevelAt")
        .staticmethod("fontMetrics")
        .staticmethod("setKeyboardInputInterval")
        .staticmethod("exec")
        .staticmethod("overrideCursor")
        .staticmethod("colorSpec")
        .staticmethod("desktopSettingsAware")
        .staticmethod("palette")
        .staticmethod("setStartDragTime")
        .staticmethod("activeModalWidget")
        .staticmethod("setDesktopSettingsAware")
        .staticmethod("windowIcon")
        .staticmethod("setCursorFlashTime")
        .staticmethod("setPalette")
        .staticmethod("mouseButtons")
        .staticmethod("setActiveWindow")
        .staticmethod("setStartDragDistance")
        .staticmethod("cursorFlashTime")
        .staticmethod("trUtf8")
        .staticmethod("keyboardInputInterval")
        .staticmethod("setColorSpec")
        .staticmethod("setQuitOnLastWindowClosed")
        .staticmethod("startDragTime")
        .staticmethod("setWindowIcon")
        .staticmethod("isLeftToRight")
        .staticmethod("globalStrut")
        .staticmethod("setOverrideCursor")
        .staticmethod("setFont")
        .staticmethod("restoreOverrideCursor")
        .staticmethod("doubleClickInterval")
    );

    enum_< QApplication::Type >("Type")
        .value("GuiServer", QApplication::GuiServer)
        .value("Tty", QApplication::Tty)
        .value("GuiClient", QApplication::GuiClient)
    ;


    enum_< QApplication::ColorSpec >("ColorSpec")
        .value("ManyColor", QApplication::ManyColor)
        .value("NormalColor", QApplication::NormalColor)
        .value("CustomColor", QApplication::CustomColor)
    ;

    delete QApplication_scope;

}

