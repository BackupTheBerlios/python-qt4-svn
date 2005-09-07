/****************************************************************************
**
** Copyright (C) 1992-2005 Trolltech AS. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QPython.h>
#include <QPythonWidget.h>

#include <QPushButton>
//#include <QLibrary>
#include "customwidgetplugin.h"


AnalogClockPlugin::AnalogClockPlugin(QObject *parent)
    : QObject(parent)
{
    QPython::init();
    qDebug("AnalogClockPlugin::AnalogClockPlugin");
    initialized = false;
}

void AnalogClockPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    qDebug("AnalogClockPlugin::initialize(before)");
    if (initialized)
        return;

    qDebug("AnalogClockPlugin::initialize(after)");
    initialized = true;
}

bool AnalogClockPlugin::isInitialized() const
{
    qDebug("AnalogClockPlugin::isInitialized?");
    return initialized;
}

QWidget *AnalogClockPlugin::createWidget(QWidget *parent)
{
    qDebug("AnalogClockPlugin::createWidget");
    //return new AnalogClock(parent);
    return new QPythonWidget(parent, "Qt.Gui", "QPushButton");
}

QString AnalogClockPlugin::name() const
{
    return QLatin1String("QPython");
}

QString AnalogClockPlugin::group() const
{
    return QLatin1String("Display Widgets [Examples]");
}

QIcon AnalogClockPlugin::icon() const
{
    return QIcon();
}

QString AnalogClockPlugin::toolTip() const
{
    return QString();
}

QString AnalogClockPlugin::whatsThis() const
{
    return QString();
}

bool AnalogClockPlugin::isContainer() const
{
    return false;
}

QString AnalogClockPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QPython\" name=\"analogClock\">\n"
                         " <property name=\"geometry\">\n"
                         "  <rect>\n"
                         "   <x>0</x>\n"
                         "   <y>0</y>\n"
                         "   <width>100</width>\n"
                         "   <height>100</height>\n"
                         "  </rect>\n"
                         " </property>\n"
                         " <property name=\"toolTip\" >\n"
                         "  <string>The current time</string>\n"
                         " </property>\n"
                         " <property name=\"whatsThis\" >\n"
                         "  <string>The analog clock widget displays "
                         "the current time.</string>\n"
                         " </property>\n"
                         "</widget>\n");
}

QString AnalogClockPlugin::includeFile() const
{
    return QLatin1String("QPython.h");
}

QString AnalogClockPlugin::codeTemplate() const
{
    return QString();
}

Q_EXPORT_PLUGIN(AnalogClockPlugin)
