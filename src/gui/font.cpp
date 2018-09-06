// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/font.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/gui/font.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_style_hint_enum(script::Class font)
{
  using namespace script;

  Enum style_hint = font.Enum("StyleHint").setId(script::Type::QFontStyleHint).get();

  style_hint.addValue("Helvetica", QFont::Helvetica);
  style_hint.addValue("SansSerif", QFont::SansSerif);
  style_hint.addValue("Times", QFont::Times);
  style_hint.addValue("Serif", QFont::Serif);
  style_hint.addValue("Courier", QFont::Courier);
  style_hint.addValue("TypeWriter", QFont::TypeWriter);
  style_hint.addValue("OldEnglish", QFont::OldEnglish);
  style_hint.addValue("Decorative", QFont::Decorative);
  style_hint.addValue("System", QFont::System);
  style_hint.addValue("AnyStyle", QFont::AnyStyle);
  style_hint.addValue("Cursive", QFont::Cursive);
  style_hint.addValue("Monospace", QFont::Monospace);
  style_hint.addValue("Fantasy", QFont::Fantasy);
}


static void register_font_style_strategy_enum(script::Class font)
{
  using namespace script;

  Enum style_strategy = font.Enum("StyleStrategy").setId(script::Type::QFontStyleStrategy).get();

  style_strategy.addValue("PreferDefault", QFont::PreferDefault);
  style_strategy.addValue("PreferBitmap", QFont::PreferBitmap);
  style_strategy.addValue("PreferDevice", QFont::PreferDevice);
  style_strategy.addValue("PreferOutline", QFont::PreferOutline);
  style_strategy.addValue("ForceOutline", QFont::ForceOutline);
  style_strategy.addValue("PreferMatch", QFont::PreferMatch);
  style_strategy.addValue("PreferQuality", QFont::PreferQuality);
  style_strategy.addValue("PreferAntialias", QFont::PreferAntialias);
  style_strategy.addValue("NoAntialias", QFont::NoAntialias);
  style_strategy.addValue("OpenGLCompatible", QFont::OpenGLCompatible);
  style_strategy.addValue("ForceIntegerMetrics", QFont::ForceIntegerMetrics);
  style_strategy.addValue("NoSubpixelAntialias", QFont::NoSubpixelAntialias);
  style_strategy.addValue("PreferNoShaping", QFont::PreferNoShaping);
  style_strategy.addValue("NoFontMerging", QFont::NoFontMerging);
}


static void register_font_hinting_preference_enum(script::Class font)
{
  using namespace script;

  Enum hinting_preference = font.Enum("HintingPreference").setId(script::Type::QFontHintingPreference).get();

  hinting_preference.addValue("PreferDefaultHinting", QFont::PreferDefaultHinting);
  hinting_preference.addValue("PreferNoHinting", QFont::PreferNoHinting);
  hinting_preference.addValue("PreferVerticalHinting", QFont::PreferVerticalHinting);
  hinting_preference.addValue("PreferFullHinting", QFont::PreferFullHinting);
}


static void register_font_weight_enum(script::Class font)
{
  using namespace script;

  Enum weight = font.Enum("Weight").setId(script::Type::QFontWeight).get();

  weight.addValue("Thin", QFont::Thin);
  weight.addValue("ExtraLight", QFont::ExtraLight);
  weight.addValue("Light", QFont::Light);
  weight.addValue("Normal", QFont::Normal);
  weight.addValue("Medium", QFont::Medium);
  weight.addValue("DemiBold", QFont::DemiBold);
  weight.addValue("Bold", QFont::Bold);
  weight.addValue("ExtraBold", QFont::ExtraBold);
  weight.addValue("Black", QFont::Black);
}


static void register_font_style_enum(script::Class font)
{
  using namespace script;

  Enum style = font.Enum("Style").setId(script::Type::QFontStyle).get();

  style.addValue("StyleNormal", QFont::StyleNormal);
  style.addValue("StyleItalic", QFont::StyleItalic);
  style.addValue("StyleOblique", QFont::StyleOblique);
}


static void register_font_stretch_enum(script::Class font)
{
  using namespace script;

  Enum stretch = font.Enum("Stretch").setId(script::Type::QFontStretch).get();

  stretch.addValue("AnyStretch", QFont::AnyStretch);
  stretch.addValue("UltraCondensed", QFont::UltraCondensed);
  stretch.addValue("ExtraCondensed", QFont::ExtraCondensed);
  stretch.addValue("Condensed", QFont::Condensed);
  stretch.addValue("SemiCondensed", QFont::SemiCondensed);
  stretch.addValue("Unstretched", QFont::Unstretched);
  stretch.addValue("SemiExpanded", QFont::SemiExpanded);
  stretch.addValue("Expanded", QFont::Expanded);
  stretch.addValue("ExtraExpanded", QFont::ExtraExpanded);
  stretch.addValue("UltraExpanded", QFont::UltraExpanded);
}


static void register_font_capitalization_enum(script::Class font)
{
  using namespace script;

  Enum capitalization = font.Enum("Capitalization").setId(script::Type::QFontCapitalization).get();

  capitalization.addValue("MixedCase", QFont::MixedCase);
  capitalization.addValue("AllUppercase", QFont::AllUppercase);
  capitalization.addValue("AllLowercase", QFont::AllLowercase);
  capitalization.addValue("SmallCaps", QFont::SmallCaps);
  capitalization.addValue("Capitalize", QFont::Capitalize);
}


static void register_font_spacing_type_enum(script::Class font)
{
  using namespace script;

  Enum spacing_type = font.Enum("SpacingType").setId(script::Type::QFontSpacingType).get();

  spacing_type.addValue("PercentageSpacing", QFont::PercentageSpacing);
  spacing_type.addValue("AbsoluteSpacing", QFont::AbsoluteSpacing);
}


static void register_font_resolve_properties_enum(script::Class font)
{
  using namespace script;

  Enum resolve_properties = font.Enum("ResolveProperties").setId(script::Type::QFontResolveProperties).get();

  resolve_properties.addValue("FamilyResolved", QFont::FamilyResolved);
  resolve_properties.addValue("SizeResolved", QFont::SizeResolved);
  resolve_properties.addValue("StyleHintResolved", QFont::StyleHintResolved);
  resolve_properties.addValue("StyleStrategyResolved", QFont::StyleStrategyResolved);
  resolve_properties.addValue("WeightResolved", QFont::WeightResolved);
  resolve_properties.addValue("StyleResolved", QFont::StyleResolved);
  resolve_properties.addValue("UnderlineResolved", QFont::UnderlineResolved);
  resolve_properties.addValue("OverlineResolved", QFont::OverlineResolved);
  resolve_properties.addValue("StrikeOutResolved", QFont::StrikeOutResolved);
  resolve_properties.addValue("FixedPitchResolved", QFont::FixedPitchResolved);
  resolve_properties.addValue("StretchResolved", QFont::StretchResolved);
  resolve_properties.addValue("KerningResolved", QFont::KerningResolved);
  resolve_properties.addValue("CapitalizationResolved", QFont::CapitalizationResolved);
  resolve_properties.addValue("LetterSpacingResolved", QFont::LetterSpacingResolved);
  resolve_properties.addValue("WordSpacingResolved", QFont::WordSpacingResolved);
  resolve_properties.addValue("HintingPreferenceResolved", QFont::HintingPreferenceResolved);
  resolve_properties.addValue("StyleNameResolved", QFont::StyleNameResolved);
  resolve_properties.addValue("AllPropertiesResolved", QFont::AllPropertiesResolved);
}


static void register_font_class(script::Namespace ns)
{
  using namespace script;

  Class font = ns.Class("Font").setId(script::Type::QFont).get();

  register_font_style_hint_enum(font);
  register_font_style_strategy_enum(font);
  register_font_hinting_preference_enum(font);
  register_font_weight_enum(font);
  register_font_style_enum(font);
  register_font_stretch_enum(font);
  register_font_capitalization_enum(font);
  register_font_spacing_type_enum(font);
  register_font_resolve_properties_enum(font);
  binding::Class<QFont> binder{ font };

  // QFont();
  binder.ctors().add_default();
  // QFont(const QString &, int, int, bool);
  binder.ctors().add<const QString &, int, int, bool>();
  // QFont(const QFont &, QPaintDevice *);
  /// TODO: QFont(const QFont &, QPaintDevice *);
  // QFont(const QFont &);
  binder.ctors().add<const QFont &>();
  // ~QFont();
  binder.add_dtor();
  // void swap(QFont &);
  binder.add_void_fun<QFont &, &QFont::swap>("swap");
  // QString family() const;
  binder.add_fun<QString, &QFont::family>("family");
  // void setFamily(const QString &);
  binder.add_void_fun<const QString &, &QFont::setFamily>("setFamily");
  // QString styleName() const;
  binder.add_fun<QString, &QFont::styleName>("styleName");
  // void setStyleName(const QString &);
  binder.add_void_fun<const QString &, &QFont::setStyleName>("setStyleName");
  // int pointSize() const;
  binder.add_fun<int, &QFont::pointSize>("pointSize");
  // void setPointSize(int);
  binder.add_void_fun<int, &QFont::setPointSize>("setPointSize");
  // qreal pointSizeF() const;
  binder.add_fun<qreal, &QFont::pointSizeF>("pointSizeF");
  // void setPointSizeF(qreal);
  binder.add_void_fun<qreal, &QFont::setPointSizeF>("setPointSizeF");
  // int pixelSize() const;
  binder.add_fun<int, &QFont::pixelSize>("pixelSize");
  // void setPixelSize(int);
  binder.add_void_fun<int, &QFont::setPixelSize>("setPixelSize");
  // int weight() const;
  binder.add_fun<int, &QFont::weight>("weight");
  // void setWeight(int);
  binder.add_void_fun<int, &QFont::setWeight>("setWeight");
  // bool bold() const;
  binder.add_fun<bool, &QFont::bold>("bold");
  // void setBold(bool);
  binder.add_void_fun<bool, &QFont::setBold>("setBold");
  // void setStyle(QFont::Style);
  binder.add_void_fun<QFont::Style, &QFont::setStyle>("setStyle");
  // QFont::Style style() const;
  binder.add_fun<QFont::Style, &QFont::style>("style");
  // bool italic() const;
  binder.add_fun<bool, &QFont::italic>("italic");
  // void setItalic(bool);
  binder.add_void_fun<bool, &QFont::setItalic>("setItalic");
  // bool underline() const;
  binder.add_fun<bool, &QFont::underline>("underline");
  // void setUnderline(bool);
  binder.add_void_fun<bool, &QFont::setUnderline>("setUnderline");
  // bool overline() const;
  binder.add_fun<bool, &QFont::overline>("overline");
  // void setOverline(bool);
  binder.add_void_fun<bool, &QFont::setOverline>("setOverline");
  // bool strikeOut() const;
  binder.add_fun<bool, &QFont::strikeOut>("strikeOut");
  // void setStrikeOut(bool);
  binder.add_void_fun<bool, &QFont::setStrikeOut>("setStrikeOut");
  // bool fixedPitch() const;
  binder.add_fun<bool, &QFont::fixedPitch>("fixedPitch");
  // void setFixedPitch(bool);
  binder.add_void_fun<bool, &QFont::setFixedPitch>("setFixedPitch");
  // bool kerning() const;
  binder.add_fun<bool, &QFont::kerning>("kerning");
  // void setKerning(bool);
  binder.add_void_fun<bool, &QFont::setKerning>("setKerning");
  // QFont::StyleHint styleHint() const;
  binder.add_fun<QFont::StyleHint, &QFont::styleHint>("styleHint");
  // QFont::StyleStrategy styleStrategy() const;
  binder.add_fun<QFont::StyleStrategy, &QFont::styleStrategy>("styleStrategy");
  // void setStyleHint(QFont::StyleHint, QFont::StyleStrategy);
  binder.add_void_fun<QFont::StyleHint, QFont::StyleStrategy, &QFont::setStyleHint>("setStyleHint");
  // void setStyleStrategy(QFont::StyleStrategy);
  binder.add_void_fun<QFont::StyleStrategy, &QFont::setStyleStrategy>("setStyleStrategy");
  // int stretch() const;
  binder.add_fun<int, &QFont::stretch>("stretch");
  // void setStretch(int);
  binder.add_void_fun<int, &QFont::setStretch>("setStretch");
  // qreal letterSpacing() const;
  binder.add_fun<qreal, &QFont::letterSpacing>("letterSpacing");
  // QFont::SpacingType letterSpacingType() const;
  binder.add_fun<QFont::SpacingType, &QFont::letterSpacingType>("letterSpacingType");
  // void setLetterSpacing(QFont::SpacingType, qreal);
  binder.add_void_fun<QFont::SpacingType, qreal, &QFont::setLetterSpacing>("setLetterSpacing");
  // qreal wordSpacing() const;
  binder.add_fun<qreal, &QFont::wordSpacing>("wordSpacing");
  // void setWordSpacing(qreal);
  binder.add_void_fun<qreal, &QFont::setWordSpacing>("setWordSpacing");
  // void setCapitalization(QFont::Capitalization);
  binder.add_void_fun<QFont::Capitalization, &QFont::setCapitalization>("setCapitalization");
  // QFont::Capitalization capitalization() const;
  binder.add_fun<QFont::Capitalization, &QFont::capitalization>("capitalization");
  // void setHintingPreference(QFont::HintingPreference);
  binder.add_void_fun<QFont::HintingPreference, &QFont::setHintingPreference>("setHintingPreference");
  // QFont::HintingPreference hintingPreference() const;
  binder.add_fun<QFont::HintingPreference, &QFont::hintingPreference>("hintingPreference");
  // bool rawMode() const;
  binder.add_fun<bool, &QFont::rawMode>("rawMode");
  // void setRawMode(bool);
  binder.add_void_fun<bool, &QFont::setRawMode>("setRawMode");
  // bool exactMatch() const;
  binder.add_fun<bool, &QFont::exactMatch>("exactMatch");
  // QFont & operator=(const QFont &);
  binder.operators().assign<const QFont &>();
  // bool operator==(const QFont &) const;
  binder.operators().eq<const QFont &>();
  // bool operator!=(const QFont &) const;
  binder.operators().neq<const QFont &>();
  // bool operator<(const QFont &) const;
  binder.operators().less<const QFont &>();
  // bool isCopyOf(const QFont &) const;
  binder.add_fun<bool, const QFont &, &QFont::isCopyOf>("isCopyOf");
  // QFont & operator=(QFont &&);
  binder.operators().assign<QFont &&>();
  // void setRawName(const QString &);
  binder.add_void_fun<const QString &, &QFont::setRawName>("setRawName");
  // QString rawName() const;
  binder.add_fun<QString, &QFont::rawName>("rawName");
  // QString key() const;
  binder.add_fun<QString, &QFont::key>("key");
  // QString toString() const;
  binder.add_fun<QString, &QFont::toString>("toString");
  // bool fromString(const QString &);
  binder.add_fun<bool, const QString &, &QFont::fromString>("fromString");
  // static QString substitute(const QString &);
  binder.add_static<QString, const QString &, &QFont::substitute>("substitute");
  // static QStringList substitutes(const QString &);
  /// TODO: static QStringList substitutes(const QString &);
  // static QStringList substitutions();
  /// TODO: static QStringList substitutions();
  // static void insertSubstitution(const QString &, const QString &);
  binder.add_static_void_fun<const QString &, const QString &, &QFont::insertSubstitution>("insertSubstitution");
  // static void insertSubstitutions(const QString &, const QStringList &);
  /// TODO: static void insertSubstitutions(const QString &, const QStringList &);
  // static void removeSubstitutions(const QString &);
  binder.add_static_void_fun<const QString &, &QFont::removeSubstitutions>("removeSubstitutions");
  // static void initialize();
  binder.add_static_void_fun<&QFont::initialize>("initialize");
  // static void cleanup();
  binder.add_static_void_fun<&QFont::cleanup>("cleanup");
  // static void cacheStatistics();
  binder.add_static_void_fun<&QFont::cacheStatistics>("cacheStatistics");
  // QString defaultFamily() const;
  binder.add_fun<QString, &QFont::defaultFamily>("defaultFamily");
  // QString lastResortFamily() const;
  binder.add_fun<QString, &QFont::lastResortFamily>("lastResortFamily");
  // QString lastResortFont() const;
  binder.add_fun<QString, &QFont::lastResortFont>("lastResortFont");
  // QFont resolve(const QFont &) const;
  binder.add_fun<QFont, const QFont &, &QFont::resolve>("resolve");
  // uint resolve() const;
  binder.add_fun<uint, &QFont::resolve>("resolve");
  // void resolve(uint);
  binder.add_void_fun<uint, &QFont::resolve>("resolve");
}


void register_font_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFont &, QFont &);
  binder.add_void_fun<QFont &, QFont &, &swap>("swap");
  // uint qHash(const QFont &, uint);
  binder.add_fun<uint, const QFont &, uint, &qHash>("qHash");
  // QDataStream & operator<<(QDataStream &, const QFont &);
  binder.operators().put_to<QDataStream &, const QFont &>();
  // QDataStream & operator>>(QDataStream &, QFont &);
  binder.operators().read_from<QDataStream &, QFont &>();
  // QDebug operator<<(QDebug, const QFont &);
  /// TODO: QDebug operator<<(QDebug, const QFont &);
}

