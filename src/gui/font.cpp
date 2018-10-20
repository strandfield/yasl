// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/font.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
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
  binder.ctors().ctor<const QString &, int, int, bool>()
    .addDefaultArgument(binding::default_argument(font.engine(), false))
    .addDefaultArgument(binding::default_argument(font.engine(), -1))
    .addDefaultArgument(binding::default_argument(font.engine(), -1)).create();
  // QFont(const QFont &, QPaintDevice *);
  /// TODO: QFont(const QFont &, QPaintDevice *);
  // QFont(const QFont &);
  binder.ctors().ctor<const QFont &>().create();
  // ~QFont();
  binder.add_dtor();
  // void swap(QFont &);
  binder.void_fun<QFont &, &QFont::swap>("swap").create();
  // QString family() const;
  binder.fun<QString, &QFont::family>("family").create();
  // void setFamily(const QString &);
  binder.void_fun<const QString &, &QFont::setFamily>("setFamily").create();
  // QString styleName() const;
  binder.fun<QString, &QFont::styleName>("styleName").create();
  // void setStyleName(const QString &);
  binder.void_fun<const QString &, &QFont::setStyleName>("setStyleName").create();
  // int pointSize() const;
  binder.fun<int, &QFont::pointSize>("pointSize").create();
  // void setPointSize(int);
  binder.void_fun<int, &QFont::setPointSize>("setPointSize").create();
  // qreal pointSizeF() const;
  binder.fun<qreal, &QFont::pointSizeF>("pointSizeF").create();
  // void setPointSizeF(qreal);
  binder.void_fun<qreal, &QFont::setPointSizeF>("setPointSizeF").create();
  // int pixelSize() const;
  binder.fun<int, &QFont::pixelSize>("pixelSize").create();
  // void setPixelSize(int);
  binder.void_fun<int, &QFont::setPixelSize>("setPixelSize").create();
  // int weight() const;
  binder.fun<int, &QFont::weight>("weight").create();
  // void setWeight(int);
  binder.void_fun<int, &QFont::setWeight>("setWeight").create();
  // bool bold() const;
  binder.fun<bool, &QFont::bold>("bold").create();
  // void setBold(bool);
  binder.void_fun<bool, &QFont::setBold>("setBold").create();
  // void setStyle(QFont::Style);
  binder.void_fun<QFont::Style, &QFont::setStyle>("setStyle").create();
  // QFont::Style style() const;
  binder.fun<QFont::Style, &QFont::style>("style").create();
  // bool italic() const;
  binder.fun<bool, &QFont::italic>("italic").create();
  // void setItalic(bool);
  binder.void_fun<bool, &QFont::setItalic>("setItalic").create();
  // bool underline() const;
  binder.fun<bool, &QFont::underline>("underline").create();
  // void setUnderline(bool);
  binder.void_fun<bool, &QFont::setUnderline>("setUnderline").create();
  // bool overline() const;
  binder.fun<bool, &QFont::overline>("overline").create();
  // void setOverline(bool);
  binder.void_fun<bool, &QFont::setOverline>("setOverline").create();
  // bool strikeOut() const;
  binder.fun<bool, &QFont::strikeOut>("strikeOut").create();
  // void setStrikeOut(bool);
  binder.void_fun<bool, &QFont::setStrikeOut>("setStrikeOut").create();
  // bool fixedPitch() const;
  binder.fun<bool, &QFont::fixedPitch>("fixedPitch").create();
  // void setFixedPitch(bool);
  binder.void_fun<bool, &QFont::setFixedPitch>("setFixedPitch").create();
  // bool kerning() const;
  binder.fun<bool, &QFont::kerning>("kerning").create();
  // void setKerning(bool);
  binder.void_fun<bool, &QFont::setKerning>("setKerning").create();
  // QFont::StyleHint styleHint() const;
  binder.fun<QFont::StyleHint, &QFont::styleHint>("styleHint").create();
  // QFont::StyleStrategy styleStrategy() const;
  binder.fun<QFont::StyleStrategy, &QFont::styleStrategy>("styleStrategy").create();
  // void setStyleHint(QFont::StyleHint, QFont::StyleStrategy);
  binder.void_fun<QFont::StyleHint, QFont::StyleStrategy, &QFont::setStyleHint>("setStyleHint")
    .addDefaultArgument(binding::default_argument(font.engine(), QFont::PreferDefault)).create();
  // void setStyleStrategy(QFont::StyleStrategy);
  binder.void_fun<QFont::StyleStrategy, &QFont::setStyleStrategy>("setStyleStrategy").create();
  // int stretch() const;
  binder.fun<int, &QFont::stretch>("stretch").create();
  // void setStretch(int);
  binder.void_fun<int, &QFont::setStretch>("setStretch").create();
  // qreal letterSpacing() const;
  binder.fun<qreal, &QFont::letterSpacing>("letterSpacing").create();
  // QFont::SpacingType letterSpacingType() const;
  binder.fun<QFont::SpacingType, &QFont::letterSpacingType>("letterSpacingType").create();
  // void setLetterSpacing(QFont::SpacingType, qreal);
  binder.void_fun<QFont::SpacingType, qreal, &QFont::setLetterSpacing>("setLetterSpacing").create();
  // qreal wordSpacing() const;
  binder.fun<qreal, &QFont::wordSpacing>("wordSpacing").create();
  // void setWordSpacing(qreal);
  binder.void_fun<qreal, &QFont::setWordSpacing>("setWordSpacing").create();
  // void setCapitalization(QFont::Capitalization);
  binder.void_fun<QFont::Capitalization, &QFont::setCapitalization>("setCapitalization").create();
  // QFont::Capitalization capitalization() const;
  binder.fun<QFont::Capitalization, &QFont::capitalization>("capitalization").create();
  // void setHintingPreference(QFont::HintingPreference);
  binder.void_fun<QFont::HintingPreference, &QFont::setHintingPreference>("setHintingPreference").create();
  // QFont::HintingPreference hintingPreference() const;
  binder.fun<QFont::HintingPreference, &QFont::hintingPreference>("hintingPreference").create();
  // bool rawMode() const;
  binder.fun<bool, &QFont::rawMode>("rawMode").create();
  // void setRawMode(bool);
  binder.void_fun<bool, &QFont::setRawMode>("setRawMode").create();
  // bool exactMatch() const;
  binder.fun<bool, &QFont::exactMatch>("exactMatch").create();
  // QFont & operator=(const QFont &);
  binder.operators().assign<const QFont &>();
  // bool operator==(const QFont &) const;
  binder.operators().eq<const QFont &>();
  // bool operator!=(const QFont &) const;
  binder.operators().neq<const QFont &>();
  // bool operator<(const QFont &) const;
  binder.operators().less<const QFont &>();
  // bool isCopyOf(const QFont &) const;
  binder.fun<bool, const QFont &, &QFont::isCopyOf>("isCopyOf").create();
  // QFont & operator=(QFont &&);
  binder.operators().assign<QFont &&>();
  // void setRawName(const QString &);
  binder.void_fun<const QString &, &QFont::setRawName>("setRawName").create();
  // QString rawName() const;
  binder.fun<QString, &QFont::rawName>("rawName").create();
  // QString key() const;
  binder.fun<QString, &QFont::key>("key").create();
  // QString toString() const;
  binder.fun<QString, &QFont::toString>("toString").create();
  // bool fromString(const QString &);
  binder.fun<bool, const QString &, &QFont::fromString>("fromString").create();
  // static QString substitute(const QString &);
  binder.static_fun<QString, const QString &, &QFont::substitute>("substitute").create();
  // static QStringList substitutes(const QString &);
  /// TODO: static QStringList substitutes(const QString &);
  // static QStringList substitutions();
  /// TODO: static QStringList substitutions();
  // static void insertSubstitution(const QString &, const QString &);
  binder.static_void_fun<const QString &, const QString &, &QFont::insertSubstitution>("insertSubstitution").create();
  // static void insertSubstitutions(const QString &, const QStringList &);
  /// TODO: static void insertSubstitutions(const QString &, const QStringList &);
  // static void removeSubstitutions(const QString &);
  binder.static_void_fun<const QString &, &QFont::removeSubstitutions>("removeSubstitutions").create();
  // static void initialize();
  binder.static_void_fun<&QFont::initialize>("initialize").create();
  // static void cleanup();
  binder.static_void_fun<&QFont::cleanup>("cleanup").create();
  // static void cacheStatistics();
  binder.static_void_fun<&QFont::cacheStatistics>("cacheStatistics").create();
  // QString defaultFamily() const;
  binder.fun<QString, &QFont::defaultFamily>("defaultFamily").create();
  // QString lastResortFamily() const;
  binder.fun<QString, &QFont::lastResortFamily>("lastResortFamily").create();
  // QString lastResortFont() const;
  binder.fun<QString, &QFont::lastResortFont>("lastResortFont").create();
  // QFont resolve(const QFont &) const;
  binder.fun<QFont, const QFont &, &QFont::resolve>("resolve").create();
  // uint resolve() const;
  binder.fun<uint, &QFont::resolve>("resolve").create();
  // void resolve(uint);
  binder.void_fun<uint, &QFont::resolve>("resolve").create();
}


void register_font_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFont &, QFont &);
  binder.void_fun<QFont &, QFont &, &swap>("swap").create();
  // uint qHash(const QFont &, uint);
  binder.fun<uint, const QFont &, uint, &qHash>("qHash").create();
  // QDataStream & operator<<(QDataStream &, const QFont &);
  binder.operators().put_to<QDataStream &, const QFont &>();
  // QDataStream & operator>>(QDataStream &, QFont &);
  binder.operators().read_from<QDataStream &, QFont &>();
  // QDebug operator<<(QDebug, const QFont &);
  /// TODO: QDebug operator<<(QDebug, const QFont &);
}

