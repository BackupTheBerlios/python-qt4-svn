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
#include <boost/python/enum.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/shared_ptr.hpp>

#include <QtGui/QPaintDevice>
#include <QtGui/QPaintEngine>
#include <QString>
#include <memory>

using namespace boost::python;

struct QPaintDevice_Wrapper: QPaintDevice, wrapper<QPaintDevice>
{
    QPaintDevice_Wrapper():
        QPaintDevice()
    {
    }

    QPaintEngine*
    paintEngine() const
    {
        return this->get_override("paintEngine")();
    }
        
    int
    devType() const
    {
        if (override devType = this->get_override("devType"))
        {
            return devType();
        }
        return QPaintDevice::devType();
    }

    int
    default_devType() const
    {
        return this->QPaintDevice::devType();
    }

    int
    metric(QPaintDevice::PaintDeviceMetric p0) const
    {
        if (override metric = this->get_override("metric"))
        {
            return metric( p0 );
        }
        return QPaintDevice::metric(p0);
    }

    int
    default_metric(QPaintDevice::PaintDeviceMetric p0) const
    {
        return this->QPaintDevice::metric(p0);
    }
    
};

void
export_QPaintDevice()
{
    scope* QPaintDevice_scope = new scope(
    class_< QPaintDevice_Wrapper,
            boost::shared_ptr<QPaintDevice_Wrapper>,
            boost::noncopyable>
            ("QPaintDevice", init<>() )
            
        //.def("devType", &QPaintDevice::devType, &QPaintDevice_Wrapper::default_devType)
        //.def("paintEngine", pure_virtual(&QPaintDevice::paintEngine))
        .def("paintingActive", &QPaintDevice::paintingActive)
        .def("width", &QPaintDevice::width)
        .def("height", &QPaintDevice::height)
        .def("widthMM", &QPaintDevice::widthMM)
        .def("heightMM", &QPaintDevice::heightMM)
        .def("logicalDpiX", &QPaintDevice::logicalDpiX)
        .def("logicalDpiY", &QPaintDevice::logicalDpiY)
        .def("physicalDpiX", &QPaintDevice::physicalDpiX)
        .def("physicalDpiY", &QPaintDevice::physicalDpiY)
        .def("numColors", &QPaintDevice::numColors)
        .def("depth", &QPaintDevice::depth)
    //;
    );

    enum_<QPaintDevice::PaintDeviceMetric>("PaintDeviceMetric")
        .value("PdmWidth", QPaintDevice::PdmWidth)
        .value("PdmPhysicalDpiX", QPaintDevice::PdmPhysicalDpiX)
        .value("PdmPhysicalDpiY", QPaintDevice::PdmPhysicalDpiY)
        .value("PdmDepth", QPaintDevice::PdmDepth)
        .value("PdmDpiX", QPaintDevice::PdmDpiX)
        .value("PdmHeightMM", QPaintDevice::PdmHeightMM)
        .value("PdmNumColors", QPaintDevice::PdmNumColors)
        .value("PdmDpiY", QPaintDevice::PdmDpiY)
        .value("PdmHeight", QPaintDevice::PdmHeight)
        .value("PdmWidthMM", QPaintDevice::PdmWidthMM)
    ;

    delete QPaintDevice_scope;
}
    