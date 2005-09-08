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

#include <boost/python/scope.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/copy_const_reference.hpp>

#include <QtCore/QEvent>
#include <QtGui/QInputEvent>
#include <QtGui/QMouseEvent>

using namespace boost::python;


void export_QEvent()
{
    scope* QEvent_scope = new scope(
    class_<QEvent, boost::shared_ptr<QEvent>, boost::noncopyable>
        ("QEvent", init<QEvent::Type>())
        .add_property("accepted", &QEvent::isAccepted, &QEvent::setAccepted)
        .def("type", &QEvent::type)
        .def("spontaneous", &QEvent::spontaneous)
        .def("accept", &QEvent::accept)
        .def("ignore", &QEvent::ignore)
    );

    enum_< QEvent::Type >("Type")
        .value("ChildPolished", QEvent::ChildPolished)
        .value("Hide", QEvent::Hide)
        .value("WindowIconChange", QEvent::WindowIconChange)
        .value("ChildRemoved", QEvent::ChildRemoved)
        .value("ShowWindowRequest", QEvent::ShowWindowRequest)
        .value("FocusOut", QEvent::FocusOut)
        .value("WinEventAct", QEvent::WinEventAct)
        .value("FileOpen", QEvent::FileOpen)
        .value("FontChange", QEvent::FontChange)
        .value("MouseButtonPress", QEvent::MouseButtonPress)
        .value("PaletteChange", QEvent::PaletteChange)
        .value("Polish", QEvent::Polish)
        .value("AccessibilityPrepare", QEvent::AccessibilityPrepare)
        .value("LocaleChange", QEvent::LocaleChange)
        .value("ApplicationPaletteChange", QEvent::ApplicationPaletteChange)
        .value("MouseButtonDblClick", QEvent::MouseButtonDblClick)
        .value("WindowUnblocked", QEvent::WindowUnblocked)
        .value("WindowTitleChange", QEvent::WindowTitleChange)
        .value("Leave", QEvent::Leave)
        .value("MouseButtonRelease", QEvent::MouseButtonRelease)
        .value("StyleChange", QEvent::StyleChange)
        .value("ActionRemoved", QEvent::ActionRemoved)
        .value("WhatsThisClicked", QEvent::WhatsThisClicked)
        .value("DragEnter", QEvent::DragEnter)
        .value("LeaveWhatsThisMode", QEvent::LeaveWhatsThisMode)
        .value("TabletMove", QEvent::TabletMove)
        .value("Show", QEvent::Show)
        .value("StatusTip", QEvent::StatusTip)
        .value("Move", QEvent::Move)
        .value("ApplicationFontChange", QEvent::ApplicationFontChange)
        .value("DeactivateControl", QEvent::DeactivateControl)
        .value("Speech", QEvent::Speech)
        .value("Quit", QEvent::Quit)
        .value("ActivationChange", QEvent::ActivationChange)
        .value("Create", QEvent::Create)
        .value("Shortcut", QEvent::Shortcut)
        .value("EmbeddingControl", QEvent::EmbeddingControl)
        .value("Clipboard", QEvent::Clipboard)
        .value("ToolBarChange", QEvent::ToolBarChange)
        .value("Destroy", QEvent::Destroy)
        .value("WindowStateChange", QEvent::WindowStateChange)
        .value("IconDrag", QEvent::IconDrag)
        .value("DragResponse", QEvent::DragResponse)
        .value("HoverMove", QEvent::HoverMove)
        .value("Close", QEvent::Close)
        .value("TabletPress", QEvent::TabletPress)
        .value("DragLeave", QEvent::DragLeave)
        .value("QueryWhatsThis", QEvent::QueryWhatsThis)
        .value("ChildAdded", QEvent::ChildAdded)
        .value("None", QEvent::None)
        .value("PolishRequest", QEvent::PolishRequest)
        .value("Timer", QEvent::Timer)
        .value("TabletRelease", QEvent::TabletRelease)
        .value("ApplicationLayoutDirectionChange", QEvent::ApplicationLayoutDirectionChange)
        .value("LanguageChange", QEvent::LanguageChange)
        .value("AccessibilityDescription", QEvent::AccessibilityDescription)
        .value("ActionChanged", QEvent::ActionChanged)
        .value("MetaCall", QEvent::MetaCall)
        .value("ApplicationDeactivated", QEvent::ApplicationDeactivated)
        .value("ActivateControl", QEvent::ActivateControl)
        .value("ApplicationActivated", QEvent::ApplicationActivated)
        .value("ContextMenu", QEvent::ContextMenu)
        .value("ThreadChange", QEvent::ThreadChange)
        .value("EnabledChange", QEvent::EnabledChange)
        .value("IconTextChange", QEvent::IconTextChange)
        .value("Style", QEvent::Style)
        .value("AccessibilityHelp", QEvent::AccessibilityHelp)
        .value("Paint", QEvent::Paint)
        .value("ParentChange", QEvent::ParentChange)
        .value("OkRequest", QEvent::OkRequest)
        .value("DragMove", QEvent::DragMove)
        .value("ShortcutOverride", QEvent::ShortcutOverride)
        .value("UpdateRequest", QEvent::UpdateRequest)
        .value("User", QEvent::User)
        .value("ZOrderChange", QEvent::ZOrderChange)
        .value("ShowToParent", QEvent::ShowToParent)
        .value("WhatsThis", QEvent::WhatsThis)
        .value("MouseTrackingChange", QEvent::MouseTrackingChange)
        .value("ModifiedChange", QEvent::ModifiedChange)
        .value("MaxUser", QEvent::MaxUser)
        .value("ToolTip", QEvent::ToolTip)
        .value("HelpRequest", QEvent::HelpRequest)
        .value("WindowActivate", QEvent::WindowActivate)
        .value("WindowBlocked", QEvent::WindowBlocked)
        .value("FocusIn", QEvent::FocusIn)
        .value("ParentAboutToChange", QEvent::ParentAboutToChange)
        .value("KeyRelease", QEvent::KeyRelease)
        .value("SockAct", QEvent::SockAct)
        .value("ApplicationWindowIconChange", QEvent::ApplicationWindowIconChange)
        .value("Wheel", QEvent::Wheel)
        .value("HoverLeave", QEvent::HoverLeave)
        .value("LayoutRequest", QEvent::LayoutRequest)
        .value("HoverEnter", QEvent::HoverEnter)
        .value("Resize", QEvent::Resize)
        .value("EnterWhatsThisMode", QEvent::EnterWhatsThisMode)
        .value("DeferredDelete", QEvent::DeferredDelete)
        .value("Drop", QEvent::Drop)
        .value("MouseMove", QEvent::MouseMove)
        .value("ActionAdded", QEvent::ActionAdded)
        .value("WindowDeactivate", QEvent::WindowDeactivate)
        .value("Enter", QEvent::Enter)
        .value("LayoutDirectionChange", QEvent::LayoutDirectionChange)
        .value("InputMethod", QEvent::InputMethod)
        .value("KeyPress", QEvent::KeyPress)
        .value("HideToParent", QEvent::HideToParent)
        .export_values()
    ;

    delete QEvent_scope;
    
    class_< QInputEvent,
            bases< QEvent >,
            boost::noncopyable >
            ("QInputEvent", init< QEvent::Type, optional< Qt::KeyboardModifiers > >())
        .def("modifiers", &QInputEvent::modifiers)
    ;

    class_< QMouseEvent,
            bases< QInputEvent >,
            boost::noncopyable >
            ("QMouseEvent", init< QEvent::Type, const QPoint&, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers >())
        .def(init< QEvent::Type, const QPoint&, const QPoint&, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers >())
        .def("pos", &QMouseEvent::pos, return_value_policy< copy_const_reference >())
        .def("globalPos", &QMouseEvent::globalPos, return_value_policy< copy_const_reference >())
        .def("x", &QMouseEvent::x)
        .def("y", &QMouseEvent::y)
        .def("globalX", &QMouseEvent::globalX)
        .def("globalY", &QMouseEvent::globalY)
        .def("button", &QMouseEvent::button)
        .def("buttons", &QMouseEvent::buttons)
    ;
}

