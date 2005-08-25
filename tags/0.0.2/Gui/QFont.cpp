
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <QtGui/QFont>
#include <QtCore/QStringList>
// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(QFont_setStyleHint_overloads_1_2, setStyleHint, 1, 2)


}// namespace 


// Module ======================================================================
void export_QFont()
{
    scope* QFont_scope = new scope(
    class_< QFont >("QFont", init<>())
        .def(init< const QString&, optional< int, int, bool > >())
        //.def(init< const QFont&, QPaintDevice* >())
        .def(init< const QFont& >())
        .def("family", &QFont::family)
        .def("setFamily", &QFont::setFamily)
        .def("pointSize", &QFont::pointSize)
        .def("setPointSize", &QFont::setPointSize)
        .def("pointSizeF", &QFont::pointSizeF)
        .def("setPointSizeF", &QFont::setPointSizeF)
        .def("pixelSize", &QFont::pixelSize)
        .def("setPixelSize", &QFont::setPixelSize)
        .def("weight", &QFont::weight)
        .def("setWeight", &QFont::setWeight)
        .def("bold", &QFont::bold)
        .def("setBold", &QFont::setBold)
        .def("setStyle", &QFont::setStyle)
        .def("style", &QFont::style)
        .def("italic", &QFont::italic)
        .def("setItalic", &QFont::setItalic)
        .def("underline", &QFont::underline)
        .def("setUnderline", &QFont::setUnderline)
        .def("overline", &QFont::overline)
        .def("setOverline", &QFont::setOverline)
        .def("strikeOut", &QFont::strikeOut)
        .def("setStrikeOut", &QFont::setStrikeOut)
        .def("fixedPitch", &QFont::fixedPitch)
        .def("setFixedPitch", &QFont::setFixedPitch)
        .def("kerning", &QFont::kerning)
        .def("setKerning", &QFont::setKerning)
        .def("styleHint", &QFont::styleHint)
        .def("styleStrategy", &QFont::styleStrategy)
        .def("setStyleHint", &QFont::setStyleHint, QFont_setStyleHint_overloads_1_2())
        .def("setStyleStrategy", &QFont::setStyleStrategy)
        .def("stretch", &QFont::stretch)
        .def("setStretch", &QFont::setStretch)
        .def("rawMode", &QFont::rawMode)
        .def("setRawMode", &QFont::setRawMode)
        .def("exactMatch", &QFont::exactMatch)
        .def("isCopyOf", &QFont::isCopyOf)
        .def("handle", &QFont::handle)
        .def("setRawName", &QFont::setRawName)
        .def("rawName", &QFont::rawName)
        .def("key", &QFont::key)
        .def("toString", &QFont::toString)
        .def("fromString", &QFont::fromString)
        .def("substitute", &QFont::substitute)
        .def("substitutes", &QFont::substitutes)
        .def("substitutions", &QFont::substitutions)
        .def("insertSubstitution", &QFont::insertSubstitution)
        .def("insertSubstitutions", &QFont::insertSubstitutions)
        .def("removeSubstitution", &QFont::removeSubstitution)
        .def("initialize", &QFont::initialize)
        .def("cleanup", &QFont::cleanup)
        .def("cacheStatistics", &QFont::cacheStatistics)
        .def("defaultFamily", &QFont::defaultFamily)
        .def("lastResortFamily", &QFont::lastResortFamily)
        .def("lastResortFont", &QFont::lastResortFont)
        .def("resolve", (QFont (QFont::*)(const QFont&) const)&QFont::resolve)
        .def("resolve", (uint (QFont::*)() const)&QFont::resolve)
        .def("resolve", (void (QFont::*)(uint) )&QFont::resolve)
        .staticmethod("cacheStatistics")
        .staticmethod("insertSubstitution")
        .staticmethod("substitutes")
        .staticmethod("substitutions")
        .staticmethod("insertSubstitutions")
        .staticmethod("removeSubstitution")
        .staticmethod("cleanup")
        .staticmethod("initialize")
        .staticmethod("substitute")
        //.def( other< QDataStream >() << self )
        //.def( other< QDataStream >() >> self )
        .def( self == self )
        .def( self != self )
        .def( self < self )
        //.def("to_QVariant", &QFont::operator QVariant)
    );

    enum_< QFont::StyleHint >("StyleHint")
        .value("Decorative", QFont::Decorative)
        .value("SansSerif", QFont::SansSerif)
        .value("Courier", QFont::Courier)
        .value("Helvetica", QFont::Helvetica)
        .value("System", QFont::System)
        .value("Times", QFont::Times)
        .value("Serif", QFont::Serif)
        .value("OldEnglish", QFont::OldEnglish)
        .value("AnyStyle", QFont::AnyStyle)
        .value("TypeWriter", QFont::TypeWriter)
        .export_values();
    ;


    enum_< QFont::StyleStrategy >("StyleStrategy")
        .value("PreferQuality", QFont::PreferQuality)
        .value("PreferMatch", QFont::PreferMatch)
        .value("PreferDefault", QFont::PreferDefault)
        .value("PreferOutline", QFont::PreferOutline)
        .value("ForceOutline", QFont::ForceOutline)
        .value("NoAntialias", QFont::NoAntialias)
        .value("PreferBitmap", QFont::PreferBitmap)
        .value("PreferDevice", QFont::PreferDevice)
        .value("PreferAntialias", QFont::PreferAntialias)
        .value("OpenGLCompatible", QFont::OpenGLCompatible)
        .export_values();
    ;


    enum_< QFont::Weight >("Weight")
        .value("Light", QFont::Light)
        .value("Black", QFont::Black)
        .value("Bold", QFont::Bold)
        .value("DemiBold", QFont::DemiBold)
        .value("Normal", QFont::Normal)
        .export_values();
    ;


    enum_< QFont::Style >("Style")
        .value("StyleOblique", QFont::StyleOblique)
        .value("StyleItalic", QFont::StyleItalic)
        .value("StyleNormal", QFont::StyleNormal)
        .export_values();
    ;


    enum_< QFont::Stretch >("Stretch")
        .value("Condensed", QFont::Condensed)
        .value("Expanded", QFont::Expanded)
        .value("SemiCondensed", QFont::SemiCondensed)
        .value("ExtraCondensed", QFont::ExtraCondensed)
        .value("ExtraExpanded", QFont::ExtraExpanded)
        .value("SemiExpanded", QFont::SemiExpanded)
        .value("UltraCondensed", QFont::UltraCondensed)
        .value("Unstretched", QFont::Unstretched)
        .value("UltraExpanded", QFont::UltraExpanded)
        .export_values();
    ;

    delete QFont_scope;

}

