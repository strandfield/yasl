// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/font.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"

#include "yasl/core/datastream.h"
#include "yasl/gui/font.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_style_hint_enum(script::Class font)
{
  using namespace script;

  Enum style_hint = font.newEnum("StyleHint").setId(script::Type::QFontStyleHint).get();

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

  Enum style_strategy = font.newEnum("StyleStrategy").setId(script::Type::QFontStyleStrategy).get();

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
  style_strategy.addValue("NoFontMerging", QFont::NoFontMerging);
}


static void register_font_hinting_preference_enum(script::Class font)
{
  using namespace script;

  Enum hinting_preference = font.newEnum("HintingPreference").setId(script::Type::QFontHintingPreference).get();

  hinting_preference.addValue("PreferDefaultHinting", QFont::PreferDefaultHinting);
  hinting_preference.addValue("PreferNoHinting", QFont::PreferNoHinting);
  hinting_preference.addValue("PreferVerticalHinting", QFont::PreferVerticalHinting);
  hinting_preference.addValue("PreferFullHinting", QFont::PreferFullHinting);
}


static void register_font_weight_enum(script::Class font)
{
  using namespace script;

  Enum weight = font.newEnum("Weight").setId(script::Type::QFontWeight).get();

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

  Enum style = font.newEnum("Style").setId(script::Type::QFontStyle).get();

  style.addValue("StyleNormal", QFont::StyleNormal);
  style.addValue("StyleItalic", QFont::StyleItalic);
  style.addValue("StyleOblique", QFont::StyleOblique);
}


static void register_font_stretch_enum(script::Class font)
{
  using namespace script;

  Enum stretch = font.newEnum("Stretch").setId(script::Type::QFontStretch).get();

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

  Enum capitalization = font.newEnum("Capitalization").setId(script::Type::QFontCapitalization).get();

  capitalization.addValue("MixedCase", QFont::MixedCase);
  capitalization.addValue("AllUppercase", QFont::AllUppercase);
  capitalization.addValue("AllLowercase", QFont::AllLowercase);
  capitalization.addValue("SmallCaps", QFont::SmallCaps);
  capitalization.addValue("Capitalize", QFont::Capitalize);
}


static void register_font_spacing_type_enum(script::Class font)
{
  using namespace script;

  Enum spacing_type = font.newEnum("SpacingType").setId(script::Type::QFontSpacingType).get();

  spacing_type.addValue("PercentageSpacing", QFont::PercentageSpacing);
  spacing_type.addValue("AbsoluteSpacing", QFont::AbsoluteSpacing);
}


static void register_font_resolve_properties_enum(script::Class font)
{
  using namespace script;

  Enum resolve_properties = font.newEnum("ResolveProperties").setId(script::Type::QFontResolveProperties).get();

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

  Class font = ns.newClass("Font").setId(script::Type::QFont).get();

  register_font_style_hint_enum(font);
  register_font_style_strategy_enum(font);
  register_font_hinting_preference_enum(font);
  register_font_weight_enum(font);
  register_font_style_enum(font);
  register_font_stretch_enum(font);
  register_font_capitalization_enum(font);
  register_font_spacing_type_enum(font);
  register_font_resolve_properties_enum(font);

  // QFont();
  bind::default_constructor<QFont>(font).create();
  // QFont(const QString &, int, int, bool);
  bind::constructor<QFont, const QString &, int, int, bool>(font)
    .apply(bind::default_arguments(false, -1, -1)).create();
  // QFont(const QFont &, QPaintDevice *);
  /// TODO: QFont(const QFont &, QPaintDevice *);
  // QFont(const QFont &);
  bind::constructor<QFont, const QFont &>(font).create();
  // ~QFont();
  bind::destructor<QFont>(font).create();
  // void swap(QFont &);
  bind::void_member_function<QFont, QFont &, &QFont::swap>(font, "swap").create();
  // QString family() const;
  bind::member_function<QFont, QString, &QFont::family>(font, "family").create();
  // void setFamily(const QString &);
  bind::void_member_function<QFont, const QString &, &QFont::setFamily>(font, "setFamily").create();
  // QString styleName() const;
  bind::member_function<QFont, QString, &QFont::styleName>(font, "styleName").create();
  // void setStyleName(const QString &);
  bind::void_member_function<QFont, const QString &, &QFont::setStyleName>(font, "setStyleName").create();
  // int pointSize() const;
  bind::member_function<QFont, int, &QFont::pointSize>(font, "pointSize").create();
  // void setPointSize(int);
  bind::void_member_function<QFont, int, &QFont::setPointSize>(font, "setPointSize").create();
  // qreal pointSizeF() const;
  bind::member_function<QFont, qreal, &QFont::pointSizeF>(font, "pointSizeF").create();
  // void setPointSizeF(qreal);
  bind::void_member_function<QFont, qreal, &QFont::setPointSizeF>(font, "setPointSizeF").create();
  // int pixelSize() const;
  bind::member_function<QFont, int, &QFont::pixelSize>(font, "pixelSize").create();
  // void setPixelSize(int);
  bind::void_member_function<QFont, int, &QFont::setPixelSize>(font, "setPixelSize").create();
  // int weight() const;
  bind::member_function<QFont, int, &QFont::weight>(font, "weight").create();
  // void setWeight(int);
  bind::void_member_function<QFont, int, &QFont::setWeight>(font, "setWeight").create();
  // bool bold() const;
  bind::member_function<QFont, bool, &QFont::bold>(font, "bold").create();
  // void setBold(bool);
  bind::void_member_function<QFont, bool, &QFont::setBold>(font, "setBold").create();
  // void setStyle(QFont::Style);
  bind::void_member_function<QFont, QFont::Style, &QFont::setStyle>(font, "setStyle").create();
  // QFont::Style style() const;
  bind::member_function<QFont, QFont::Style, &QFont::style>(font, "style").create();
  // bool italic() const;
  bind::member_function<QFont, bool, &QFont::italic>(font, "italic").create();
  // void setItalic(bool);
  bind::void_member_function<QFont, bool, &QFont::setItalic>(font, "setItalic").create();
  // bool underline() const;
  bind::member_function<QFont, bool, &QFont::underline>(font, "underline").create();
  // void setUnderline(bool);
  bind::void_member_function<QFont, bool, &QFont::setUnderline>(font, "setUnderline").create();
  // bool overline() const;
  bind::member_function<QFont, bool, &QFont::overline>(font, "overline").create();
  // void setOverline(bool);
  bind::void_member_function<QFont, bool, &QFont::setOverline>(font, "setOverline").create();
  // bool strikeOut() const;
  bind::member_function<QFont, bool, &QFont::strikeOut>(font, "strikeOut").create();
  // void setStrikeOut(bool);
  bind::void_member_function<QFont, bool, &QFont::setStrikeOut>(font, "setStrikeOut").create();
  // bool fixedPitch() const;
  bind::member_function<QFont, bool, &QFont::fixedPitch>(font, "fixedPitch").create();
  // void setFixedPitch(bool);
  bind::void_member_function<QFont, bool, &QFont::setFixedPitch>(font, "setFixedPitch").create();
  // bool kerning() const;
  bind::member_function<QFont, bool, &QFont::kerning>(font, "kerning").create();
  // void setKerning(bool);
  bind::void_member_function<QFont, bool, &QFont::setKerning>(font, "setKerning").create();
  // QFont::StyleHint styleHint() const;
  bind::member_function<QFont, QFont::StyleHint, &QFont::styleHint>(font, "styleHint").create();
  // QFont::StyleStrategy styleStrategy() const;
  bind::member_function<QFont, QFont::StyleStrategy, &QFont::styleStrategy>(font, "styleStrategy").create();
  // void setStyleHint(QFont::StyleHint, QFont::StyleStrategy);
  bind::void_member_function<QFont, QFont::StyleHint, QFont::StyleStrategy, &QFont::setStyleHint>(font, "setStyleHint")
    .apply(bind::default_arguments(QFont::PreferDefault)).create();
  // void setStyleStrategy(QFont::StyleStrategy);
  bind::void_member_function<QFont, QFont::StyleStrategy, &QFont::setStyleStrategy>(font, "setStyleStrategy").create();
  // int stretch() const;
  bind::member_function<QFont, int, &QFont::stretch>(font, "stretch").create();
  // void setStretch(int);
  bind::void_member_function<QFont, int, &QFont::setStretch>(font, "setStretch").create();
  // qreal letterSpacing() const;
  bind::member_function<QFont, qreal, &QFont::letterSpacing>(font, "letterSpacing").create();
  // QFont::SpacingType letterSpacingType() const;
  bind::member_function<QFont, QFont::SpacingType, &QFont::letterSpacingType>(font, "letterSpacingType").create();
  // void setLetterSpacing(QFont::SpacingType, qreal);
  bind::void_member_function<QFont, QFont::SpacingType, qreal, &QFont::setLetterSpacing>(font, "setLetterSpacing").create();
  // qreal wordSpacing() const;
  bind::member_function<QFont, qreal, &QFont::wordSpacing>(font, "wordSpacing").create();
  // void setWordSpacing(qreal);
  bind::void_member_function<QFont, qreal, &QFont::setWordSpacing>(font, "setWordSpacing").create();
  // void setCapitalization(QFont::Capitalization);
  bind::void_member_function<QFont, QFont::Capitalization, &QFont::setCapitalization>(font, "setCapitalization").create();
  // QFont::Capitalization capitalization() const;
  bind::member_function<QFont, QFont::Capitalization, &QFont::capitalization>(font, "capitalization").create();
  // void setHintingPreference(QFont::HintingPreference);
  bind::void_member_function<QFont, QFont::HintingPreference, &QFont::setHintingPreference>(font, "setHintingPreference").create();
  // QFont::HintingPreference hintingPreference() const;
  bind::member_function<QFont, QFont::HintingPreference, &QFont::hintingPreference>(font, "hintingPreference").create();
  // bool rawMode() const;
  bind::member_function<QFont, bool, &QFont::rawMode>(font, "rawMode").create();
  // void setRawMode(bool);
  bind::void_member_function<QFont, bool, &QFont::setRawMode>(font, "setRawMode").create();
  // bool exactMatch() const;
  bind::member_function<QFont, bool, &QFont::exactMatch>(font, "exactMatch").create();
  // QFont & operator=(const QFont &);
  bind::memop_assign<QFont, const QFont &>(font);
  // bool operator==(const QFont &) const;
  bind::memop_eq<QFont, const QFont &>(font);
  // bool operator!=(const QFont &) const;
  bind::memop_neq<QFont, const QFont &>(font);
  // bool operator<(const QFont &) const;
  bind::memop_less<QFont, const QFont &>(font);
  // bool isCopyOf(const QFont &) const;
  bind::member_function<QFont, bool, const QFont &, &QFont::isCopyOf>(font, "isCopyOf").create();
  // QFont & operator=(QFont &&);
  bind::memop_assign<QFont, QFont &&>(font);
  // void setRawName(const QString &);
  bind::void_member_function<QFont, const QString &, &QFont::setRawName>(font, "setRawName").create();
  // QString rawName() const;
  bind::member_function<QFont, QString, &QFont::rawName>(font, "rawName").create();
  // QString key() const;
  bind::member_function<QFont, QString, &QFont::key>(font, "key").create();
  // QString toString() const;
  bind::member_function<QFont, QString, &QFont::toString>(font, "toString").create();
  // bool fromString(const QString &);
  bind::member_function<QFont, bool, const QString &, &QFont::fromString>(font, "fromString").create();
  // static QString substitute(const QString &);
  bind::static_member_function<QFont, QString, const QString &, &QFont::substitute>(font, "substitute").create();
  // static QStringList substitutes(const QString &);
  /// TODO: static QStringList substitutes(const QString &);
  // static QStringList substitutions();
  /// TODO: static QStringList substitutions();
  // static void insertSubstitution(const QString &, const QString &);
  bind::static_void_member_function<QFont, const QString &, const QString &, &QFont::insertSubstitution>(font, "insertSubstitution").create();
  // static void insertSubstitutions(const QString &, const QStringList &);
  /// TODO: static void insertSubstitutions(const QString &, const QStringList &);
  // static void removeSubstitutions(const QString &);
  bind::static_void_member_function<QFont, const QString &, &QFont::removeSubstitutions>(font, "removeSubstitutions").create();
  // static void initialize();
  bind::static_void_member_function<QFont, &QFont::initialize>(font, "initialize").create();
  // static void cleanup();
  bind::static_void_member_function<QFont, &QFont::cleanup>(font, "cleanup").create();
  // static void cacheStatistics();
  bind::static_void_member_function<QFont, &QFont::cacheStatistics>(font, "cacheStatistics").create();
  // QString defaultFamily() const;
  bind::member_function<QFont, QString, &QFont::defaultFamily>(font, "defaultFamily").create();
  // QString lastResortFamily() const;
  bind::member_function<QFont, QString, &QFont::lastResortFamily>(font, "lastResortFamily").create();
  // QString lastResortFont() const;
  bind::member_function<QFont, QString, &QFont::lastResortFont>(font, "lastResortFont").create();
  // QFont resolve(const QFont &) const;
  bind::member_function<QFont, QFont, const QFont &, &QFont::resolve>(font, "resolve").create();
  // uint resolve() const;
  bind::member_function<QFont, uint, &QFont::resolve>(font, "resolve").create();
  // void resolve(uint);
  bind::void_member_function<QFont, uint, &QFont::resolve>(font, "resolve").create();
}


void register_font_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_class(ns);

  // void swap(QFont &, QFont &);
  bind::void_function<QFont &, QFont &, &swap>(ns, "swap").create();
  // uint qHash(const QFont &, uint);
  bind::function<uint, const QFont &, uint, &qHash>(ns, "qHash").create();
  // QDataStream & operator<<(QDataStream &, const QFont &);
  bind::op_put_to<QDataStream &, const QFont &>(ns);
  // QDataStream & operator>>(QDataStream &, QFont &);
  bind::op_read_from<QDataStream &, QFont &>(ns);
  // QDebug operator<<(QDebug, const QFont &);
  /// TODO: QDebug operator<<(QDebug, const QFont &);
}

