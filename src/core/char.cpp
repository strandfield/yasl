// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/char.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#include <QDataStream>

static void register_char_category_enum(script::Class qchar)
{
  using namespace script;

  Enum category = qchar.Enum("Category").setId(script::Type::QCharCategory).get();

  category.addValue("Letter_Lowercase", QChar::Letter_Lowercase);
  category.addValue("Letter_Modifier", QChar::Letter_Modifier);
  category.addValue("Letter_Other", QChar::Letter_Other);
  category.addValue("Letter_Titlecase", QChar::Letter_Titlecase);
  category.addValue("Letter_Uppercase", QChar::Letter_Uppercase);
  category.addValue("Mark_Enclosing", QChar::Mark_Enclosing);
  category.addValue("Mark_NonSpacing", QChar::Mark_NonSpacing);
  category.addValue("Mark_SpacingCombining", QChar::Mark_SpacingCombining);
  category.addValue("Number_DecimalDigit", QChar::Number_DecimalDigit);
  category.addValue("Number_Letter", QChar::Number_Letter);
  category.addValue("Number_Other", QChar::Number_Other);
  category.addValue("Other_Control", QChar::Other_Control);
  category.addValue("Other_Format", QChar::Other_Format);
  category.addValue("Other_NotAssigned", QChar::Other_NotAssigned);
  category.addValue("Other_PrivateUse", QChar::Other_PrivateUse);
  category.addValue("Other_Surrogate", QChar::Other_Surrogate);
  category.addValue("Punctuation_Close", QChar::Punctuation_Close);
  category.addValue("Punctuation_Connector", QChar::Punctuation_Connector);
  category.addValue("Punctuation_Dash", QChar::Punctuation_Dash);
  category.addValue("Punctuation_FinalQuote", QChar::Punctuation_FinalQuote);
  category.addValue("Punctuation_InitialQuote", QChar::Punctuation_InitialQuote);
  category.addValue("Punctuation_Open", QChar::Punctuation_Open);
  category.addValue("Punctuation_Other", QChar::Punctuation_Other);
  category.addValue("Separator_Line", QChar::Separator_Line);
  category.addValue("Separator_Paragraph", QChar::Separator_Paragraph);
  category.addValue("Separator_Space", QChar::Separator_Space);
  category.addValue("Symbol_Currency", QChar::Symbol_Currency);
  category.addValue("Symbol_Math", QChar::Symbol_Math);
  category.addValue("Symbol_Modifier", QChar::Symbol_Modifier);
  category.addValue("Symbol_Other", QChar::Symbol_Other);
}

static void register_char_combining_class_enum(script::Class qchar)
{
  using namespace script;

  Enum combining_class = qchar.Enum("CombiningClass").setId(script::Type::QCharCombiningClass).get();

  combining_class.addValue("Combining_Above", QChar::Combining_Above);
  combining_class.addValue("Combining_AboveAttached", QChar::Combining_AboveAttached);
  combining_class.addValue("Combining_AboveLeft", QChar::Combining_AboveLeft);
  combining_class.addValue("Combining_AboveLeftAttached", QChar::Combining_AboveLeftAttached);
  combining_class.addValue("Combining_AboveRight", QChar::Combining_AboveRight);
  combining_class.addValue("Combining_AboveRightAttached", QChar::Combining_AboveRightAttached);
  combining_class.addValue("Combining_Below", QChar::Combining_Below);
  combining_class.addValue("Combining_BelowAttached", QChar::Combining_BelowAttached);
  combining_class.addValue("Combining_BelowLeft", QChar::Combining_BelowLeft);
  combining_class.addValue("Combining_BelowLeftAttached", QChar::Combining_BelowLeftAttached);
  combining_class.addValue("Combining_BelowRight", QChar::Combining_BelowRight);
  combining_class.addValue("Combining_BelowRightAttached", QChar::Combining_BelowRightAttached);
  combining_class.addValue("Combining_DoubleAbove", QChar::Combining_DoubleAbove);
  combining_class.addValue("Combining_DoubleBelow", QChar::Combining_DoubleBelow);
  combining_class.addValue("Combining_IotaSubscript", QChar::Combining_IotaSubscript);
  combining_class.addValue("Combining_Left", QChar::Combining_Left);
  combining_class.addValue("Combining_LeftAttached", QChar::Combining_LeftAttached);
  combining_class.addValue("Combining_Right", QChar::Combining_Right);
  combining_class.addValue("Combining_RightAttached", QChar::Combining_RightAttached);
}

static void register_char_decomposition_enum(script::Class qchar)
{
  using namespace script;

  Enum decomposition = qchar.Enum("Decomposition").setId(script::Type::QCharDecomposition).get();

  decomposition.addValue("Canonical", QChar::Canonical);
  decomposition.addValue("Circle", QChar::Circle);
  decomposition.addValue("Compat", QChar::Compat);
  decomposition.addValue("Final", QChar::Final);
  decomposition.addValue("Font", QChar::Font);
  decomposition.addValue("Fraction", QChar::Fraction);
  decomposition.addValue("Initial", QChar::Initial);
  decomposition.addValue("Isolated", QChar::Isolated);
  decomposition.addValue("Medial", QChar::Medial);
  decomposition.addValue("Narrow", QChar::Narrow);
  decomposition.addValue("NoBreak", QChar::NoBreak);
  decomposition.addValue("NoDecomposition", QChar::NoDecomposition);
  decomposition.addValue("Small", QChar::Small);
  decomposition.addValue("Square", QChar::Square);
  decomposition.addValue("Sub", QChar::Sub);
  decomposition.addValue("Super", QChar::Super);
  decomposition.addValue("Vertical", QChar::Vertical);
  decomposition.addValue("Wide", QChar::Wide);
}

static void register_char_direction_enum(script::Class qchar)
{
  using namespace script;

  Enum direction = qchar.Enum("Direction").setId(script::Type::QCharDirection).get();

  direction.addValue("DirAL", QChar::DirAL);
  direction.addValue("DirAN", QChar::DirAN);
  direction.addValue("DirB", QChar::DirB);
  direction.addValue("DirBN", QChar::DirBN);
  direction.addValue("DirCS", QChar::DirCS);
  direction.addValue("DirEN", QChar::DirEN);
  direction.addValue("DirES", QChar::DirES);
  direction.addValue("DirET", QChar::DirET);
  direction.addValue("DirFSI", QChar::DirFSI);
  direction.addValue("DirL", QChar::DirL);
  direction.addValue("DirLRE", QChar::DirLRE);
  direction.addValue("DirLRI", QChar::DirLRI);
  direction.addValue("DirLRO", QChar::DirLRO);
  direction.addValue("DirNSM", QChar::DirNSM);
  direction.addValue("DirON", QChar::DirON);
  direction.addValue("DirPDF", QChar::DirPDF);
  direction.addValue("DirPDI", QChar::DirPDI);
  direction.addValue("DirR", QChar::DirR);
  direction.addValue("DirRLE", QChar::DirRLE);
  direction.addValue("DirRLI", QChar::DirRLI);
  direction.addValue("DirRLO", QChar::DirRLO);
  direction.addValue("DirS", QChar::DirS);
  direction.addValue("DirWS", QChar::DirWS);
}

static void register_char_joining_enum(script::Class qchar)
{
  using namespace script;

  Enum joining = qchar.Enum("Joining").setId(script::Type::QCharJoining).get();

  joining.addValue("Center", QChar::Center);
  joining.addValue("Dual", QChar::Dual);
  joining.addValue("OtherJoining", QChar::OtherJoining);
  joining.addValue("Right", QChar::Right);
}

static void register_char_joining_type_enum(script::Class qchar)
{
  using namespace script;

  Enum joining_type = qchar.Enum("JoiningType").setId(script::Type::QCharJoiningType).get();

  joining_type.addValue("Joining_Causing", QChar::Joining_Causing);
  joining_type.addValue("Joining_Dual", QChar::Joining_Dual);
  joining_type.addValue("Joining_Left", QChar::Joining_Left);
  joining_type.addValue("Joining_None", QChar::Joining_None);
  joining_type.addValue("Joining_Right", QChar::Joining_Right);
  joining_type.addValue("Joining_Transparent", QChar::Joining_Transparent);
}

static void register_char_script_enum(script::Class qchar)
{
  using namespace script;

  Enum script = qchar.Enum("Script").setId(script::Type::QCharScript).get();

  script.addValue("ScriptCount", QChar::ScriptCount);
  script.addValue("Script_Ahom", QChar::Script_Ahom);
  script.addValue("Script_AnatolianHieroglyphs", QChar::Script_AnatolianHieroglyphs);
  script.addValue("Script_Arabic", QChar::Script_Arabic);
  script.addValue("Script_Armenian", QChar::Script_Armenian);
  script.addValue("Script_Avestan", QChar::Script_Avestan);
  script.addValue("Script_Balinese", QChar::Script_Balinese);
  script.addValue("Script_Bamum", QChar::Script_Bamum);
  script.addValue("Script_BassaVah", QChar::Script_BassaVah);
  script.addValue("Script_Batak", QChar::Script_Batak);
  script.addValue("Script_Bengali", QChar::Script_Bengali);
  script.addValue("Script_Bopomofo", QChar::Script_Bopomofo);
  script.addValue("Script_Brahmi", QChar::Script_Brahmi);
  script.addValue("Script_Braille", QChar::Script_Braille);
  script.addValue("Script_Buginese", QChar::Script_Buginese);
  script.addValue("Script_Buhid", QChar::Script_Buhid);
  script.addValue("Script_CanadianAboriginal", QChar::Script_CanadianAboriginal);
  script.addValue("Script_Carian", QChar::Script_Carian);
  script.addValue("Script_CaucasianAlbanian", QChar::Script_CaucasianAlbanian);
  script.addValue("Script_Chakma", QChar::Script_Chakma);
  script.addValue("Script_Cham", QChar::Script_Cham);
  script.addValue("Script_Cherokee", QChar::Script_Cherokee);
  script.addValue("Script_Common", QChar::Script_Common);
  script.addValue("Script_Coptic", QChar::Script_Coptic);
  script.addValue("Script_Cuneiform", QChar::Script_Cuneiform);
  script.addValue("Script_Cypriot", QChar::Script_Cypriot);
  script.addValue("Script_Cyrillic", QChar::Script_Cyrillic);
  script.addValue("Script_Deseret", QChar::Script_Deseret);
  script.addValue("Script_Devanagari", QChar::Script_Devanagari);
  script.addValue("Script_Duployan", QChar::Script_Duployan);
  script.addValue("Script_EgyptianHieroglyphs", QChar::Script_EgyptianHieroglyphs);
  script.addValue("Script_Elbasan", QChar::Script_Elbasan);
  script.addValue("Script_Ethiopic", QChar::Script_Ethiopic);
  script.addValue("Script_Georgian", QChar::Script_Georgian);
  script.addValue("Script_Glagolitic", QChar::Script_Glagolitic);
  script.addValue("Script_Gothic", QChar::Script_Gothic);
  script.addValue("Script_Grantha", QChar::Script_Grantha);
  script.addValue("Script_Greek", QChar::Script_Greek);
  script.addValue("Script_Gujarati", QChar::Script_Gujarati);
  script.addValue("Script_Gurmukhi", QChar::Script_Gurmukhi);
  script.addValue("Script_Han", QChar::Script_Han);
  script.addValue("Script_Hangul", QChar::Script_Hangul);
  script.addValue("Script_Hanunoo", QChar::Script_Hanunoo);
  script.addValue("Script_Hatran", QChar::Script_Hatran);
  script.addValue("Script_Hebrew", QChar::Script_Hebrew);
  script.addValue("Script_Hiragana", QChar::Script_Hiragana);
  script.addValue("Script_ImperialAramaic", QChar::Script_ImperialAramaic);
  script.addValue("Script_Inherited", QChar::Script_Inherited);
  script.addValue("Script_InscriptionalPahlavi", QChar::Script_InscriptionalPahlavi);
  script.addValue("Script_InscriptionalParthian", QChar::Script_InscriptionalParthian);
  script.addValue("Script_Javanese", QChar::Script_Javanese);
  script.addValue("Script_Kaithi", QChar::Script_Kaithi);
  script.addValue("Script_Kannada", QChar::Script_Kannada);
  script.addValue("Script_Katakana", QChar::Script_Katakana);
  script.addValue("Script_KayahLi", QChar::Script_KayahLi);
  script.addValue("Script_Kharoshthi", QChar::Script_Kharoshthi);
  script.addValue("Script_Khmer", QChar::Script_Khmer);
  script.addValue("Script_Khojki", QChar::Script_Khojki);
  script.addValue("Script_Khudawadi", QChar::Script_Khudawadi);
  script.addValue("Script_Lao", QChar::Script_Lao);
  script.addValue("Script_Latin", QChar::Script_Latin);
  script.addValue("Script_Lepcha", QChar::Script_Lepcha);
  script.addValue("Script_Limbu", QChar::Script_Limbu);
  script.addValue("Script_LinearA", QChar::Script_LinearA);
  script.addValue("Script_LinearB", QChar::Script_LinearB);
  script.addValue("Script_Lisu", QChar::Script_Lisu);
  script.addValue("Script_Lycian", QChar::Script_Lycian);
  script.addValue("Script_Lydian", QChar::Script_Lydian);
  script.addValue("Script_Mahajani", QChar::Script_Mahajani);
  script.addValue("Script_Malayalam", QChar::Script_Malayalam);
  script.addValue("Script_Mandaic", QChar::Script_Mandaic);
  script.addValue("Script_Manichaean", QChar::Script_Manichaean);
  script.addValue("Script_MeeteiMayek", QChar::Script_MeeteiMayek);
  script.addValue("Script_MendeKikakui", QChar::Script_MendeKikakui);
  script.addValue("Script_MeroiticCursive", QChar::Script_MeroiticCursive);
  script.addValue("Script_MeroiticHieroglyphs", QChar::Script_MeroiticHieroglyphs);
  script.addValue("Script_Miao", QChar::Script_Miao);
  script.addValue("Script_Modi", QChar::Script_Modi);
  script.addValue("Script_Mongolian", QChar::Script_Mongolian);
  script.addValue("Script_Mro", QChar::Script_Mro);
  script.addValue("Script_Multani", QChar::Script_Multani);
  script.addValue("Script_Myanmar", QChar::Script_Myanmar);
  script.addValue("Script_Nabataean", QChar::Script_Nabataean);
  script.addValue("Script_NewTaiLue", QChar::Script_NewTaiLue);
  script.addValue("Script_Nko", QChar::Script_Nko);
  script.addValue("Script_Ogham", QChar::Script_Ogham);
  script.addValue("Script_OlChiki", QChar::Script_OlChiki);
  script.addValue("Script_OldHungarian", QChar::Script_OldHungarian);
  script.addValue("Script_OldItalic", QChar::Script_OldItalic);
  script.addValue("Script_OldNorthArabian", QChar::Script_OldNorthArabian);
  script.addValue("Script_OldPermic", QChar::Script_OldPermic);
  script.addValue("Script_OldPersian", QChar::Script_OldPersian);
  script.addValue("Script_OldSouthArabian", QChar::Script_OldSouthArabian);
  script.addValue("Script_OldTurkic", QChar::Script_OldTurkic);
  script.addValue("Script_Oriya", QChar::Script_Oriya);
  script.addValue("Script_Osmanya", QChar::Script_Osmanya);
  script.addValue("Script_PahawhHmong", QChar::Script_PahawhHmong);
  script.addValue("Script_Palmyrene", QChar::Script_Palmyrene);
  script.addValue("Script_PauCinHau", QChar::Script_PauCinHau);
  script.addValue("Script_PhagsPa", QChar::Script_PhagsPa);
  script.addValue("Script_Phoenician", QChar::Script_Phoenician);
  script.addValue("Script_PsalterPahlavi", QChar::Script_PsalterPahlavi);
  script.addValue("Script_Rejang", QChar::Script_Rejang);
  script.addValue("Script_Runic", QChar::Script_Runic);
  script.addValue("Script_Samaritan", QChar::Script_Samaritan);
  script.addValue("Script_Saurashtra", QChar::Script_Saurashtra);
  script.addValue("Script_Sharada", QChar::Script_Sharada);
  script.addValue("Script_Shavian", QChar::Script_Shavian);
  script.addValue("Script_Siddham", QChar::Script_Siddham);
  script.addValue("Script_SignWriting", QChar::Script_SignWriting);
  script.addValue("Script_Sinhala", QChar::Script_Sinhala);
  script.addValue("Script_SoraSompeng", QChar::Script_SoraSompeng);
  script.addValue("Script_Sundanese", QChar::Script_Sundanese);
  script.addValue("Script_SylotiNagri", QChar::Script_SylotiNagri);
  script.addValue("Script_Syriac", QChar::Script_Syriac);
  script.addValue("Script_Tagalog", QChar::Script_Tagalog);
  script.addValue("Script_Tagbanwa", QChar::Script_Tagbanwa);
  script.addValue("Script_TaiLe", QChar::Script_TaiLe);
  script.addValue("Script_TaiTham", QChar::Script_TaiTham);
  script.addValue("Script_TaiViet", QChar::Script_TaiViet);
  script.addValue("Script_Takri", QChar::Script_Takri);
  script.addValue("Script_Tamil", QChar::Script_Tamil);
  script.addValue("Script_Telugu", QChar::Script_Telugu);
  script.addValue("Script_Thaana", QChar::Script_Thaana);
  script.addValue("Script_Thai", QChar::Script_Thai);
  script.addValue("Script_Tibetan", QChar::Script_Tibetan);
  script.addValue("Script_Tifinagh", QChar::Script_Tifinagh);
  script.addValue("Script_Tirhuta", QChar::Script_Tirhuta);
  script.addValue("Script_Ugaritic", QChar::Script_Ugaritic);
  script.addValue("Script_Unknown", QChar::Script_Unknown);
  script.addValue("Script_Vai", QChar::Script_Vai);
  script.addValue("Script_WarangCiti", QChar::Script_WarangCiti);
  script.addValue("Script_Yi", QChar::Script_Yi);
}

static void register_char_special_character_enum(script::Class qchar)
{
  using namespace script;

  Enum special_character = qchar.Enum("SpecialCharacter").setId(script::Type::QCharSpecialCharacter).get();

  special_character.addValue("ByteOrderMark", QChar::ByteOrderMark);
  special_character.addValue("ByteOrderSwapped", QChar::ByteOrderSwapped);
  special_character.addValue("CarriageReturn", QChar::CarriageReturn);
  special_character.addValue("LastValidCodePoint", QChar::LastValidCodePoint);
  special_character.addValue("LineFeed", QChar::LineFeed);
  special_character.addValue("LineSeparator", QChar::LineSeparator);
  special_character.addValue("Nbsp", QChar::Nbsp);
  special_character.addValue("Null", QChar::Null);
  special_character.addValue("ObjectReplacementCharacter", QChar::ObjectReplacementCharacter);
  special_character.addValue("ParagraphSeparator", QChar::ParagraphSeparator);
  special_character.addValue("ReplacementCharacter", QChar::ReplacementCharacter);
  special_character.addValue("SoftHyphen", QChar::SoftHyphen);
  special_character.addValue("Space", QChar::Space);
  special_character.addValue("Tabulation", QChar::Tabulation);
}

static void register_char_unicode_version_enum(script::Class qchar)
{
  using namespace script;

  Enum unicode_version = qchar.Enum("UnicodeVersion").setId(script::Type::QCharUnicodeVersion).get();

  unicode_version.addValue("Unicode_1_1", QChar::Unicode_1_1);
  unicode_version.addValue("Unicode_2_0", QChar::Unicode_2_0);
  unicode_version.addValue("Unicode_2_1_2", QChar::Unicode_2_1_2);
  unicode_version.addValue("Unicode_3_0", QChar::Unicode_3_0);
  unicode_version.addValue("Unicode_3_1", QChar::Unicode_3_1);
  unicode_version.addValue("Unicode_3_2", QChar::Unicode_3_2);
  unicode_version.addValue("Unicode_4_0", QChar::Unicode_4_0);
  unicode_version.addValue("Unicode_4_1", QChar::Unicode_4_1);
  unicode_version.addValue("Unicode_5_0", QChar::Unicode_5_0);
  unicode_version.addValue("Unicode_5_1", QChar::Unicode_5_1);
  unicode_version.addValue("Unicode_5_2", QChar::Unicode_5_2);
  unicode_version.addValue("Unicode_6_0", QChar::Unicode_6_0);
  unicode_version.addValue("Unicode_6_1", QChar::Unicode_6_1);
  unicode_version.addValue("Unicode_6_2", QChar::Unicode_6_2);
  unicode_version.addValue("Unicode_6_3", QChar::Unicode_6_3);
  unicode_version.addValue("Unicode_7_0", QChar::Unicode_7_0);
  unicode_version.addValue("Unicode_8_0", QChar::Unicode_8_0);
  unicode_version.addValue("Unicode_Unassigned", QChar::Unicode_Unassigned);
}

static void register_char_class(script::Namespace ns)
{
  using namespace script;

  Class qchar = ns.Class("Char").setId(script::Type::QChar).get();

  register_char_category_enum(qchar);
  register_char_combining_class_enum(qchar);
  register_char_decomposition_enum(qchar);
  register_char_direction_enum(qchar);
  register_char_joining_enum(qchar);
  register_char_joining_type_enum(qchar);
  register_char_script_enum(qchar);
  register_char_special_character_enum(qchar);
  register_char_unicode_version_enum(qchar);
  binding::Class<QChar> binder{ qchar };

  // ~QChar();
  binder.add_dtor();
  // QChar();
  binder.ctors().add_default();
  // QChar(ushort);
  binder.ctors().add<ushort>();
  // QChar(uchar, uchar);
  binder.ctors().add<uchar, uchar>();
  // QChar(short);
  binder.ctors().add<short>();
  // QChar(uint);
  binder.ctors().add<uint>();
  // QChar(int);
  binder.ctors().add<int>();
  // QChar(QChar::SpecialCharacter);
  binder.ctors().add<QChar::SpecialCharacter>();
  // QChar(QLatin1Char);
  binder.ctors().add<QLatin1Char>();
  // QChar(char16_t);
  binder.ctors().add<char16_t>();
  // QChar(wchar_t);
  binder.ctors().add<wchar_t>();
  // QChar(char);
  binder.ctors().add<char>();
  // QChar(uchar);
  binder.ctors().add<uchar>();
  // QChar::Category category() const;
  binder.add_fun<QChar::Category, &QChar::category>("category");
  // QChar::Direction direction() const;
  binder.add_fun<QChar::Direction, &QChar::direction>("direction");
  // QChar::JoiningType joiningType() const;
  binder.add_fun<QChar::JoiningType, &QChar::joiningType>("joiningType");
  // QChar::Joining joining() const;
  binder.add_fun<QChar::Joining, &QChar::joining>("joining");
  // unsigned char combiningClass() const;
  binder.add_fun<unsigned char, &QChar::combiningClass>("combiningClass");
  // QChar mirroredChar() const;
  binder.add_fun<QChar, &QChar::mirroredChar>("mirroredChar");
  // bool hasMirrored() const;
  binder.add_fun<bool, &QChar::hasMirrored>("hasMirrored");
  // QString decomposition() const;
  binder.add_fun<QString, &QChar::decomposition>("decomposition");
  // QChar::Decomposition decompositionTag() const;
  binder.add_fun<QChar::Decomposition, &QChar::decompositionTag>("decompositionTag");
  // int digitValue() const;
  binder.add_fun<int, &QChar::digitValue>("digitValue");
  // QChar toLower() const;
  binder.add_fun<QChar, &QChar::toLower>("toLower");
  // QChar toUpper() const;
  binder.add_fun<QChar, &QChar::toUpper>("toUpper");
  // QChar toTitleCase() const;
  binder.add_fun<QChar, &QChar::toTitleCase>("toTitleCase");
  // QChar toCaseFolded() const;
  binder.add_fun<QChar, &QChar::toCaseFolded>("toCaseFolded");
  // QChar::Script script() const;
  binder.add_fun<QChar::Script, &QChar::script>("script");
  // QChar::UnicodeVersion unicodeVersion() const;
  binder.add_fun<QChar::UnicodeVersion, &QChar::unicodeVersion>("unicodeVersion");
  // char toLatin1() const;
  binder.add_fun<char, &QChar::toLatin1>("toLatin1");
  // ushort unicode() const;
  binder.add_fun<ushort, &QChar::unicode>("unicode");
  // ushort & unicode();
  /// binder.add_fun<ushort &, &QChar::unicode>("unicode");
  // static QChar fromLatin1(char);
  binder.add_static<QChar, char, &QChar::fromLatin1>("fromLatin1");
  // bool isNull() const;
  binder.add_fun<bool, &QChar::isNull>("isNull");
  // bool isPrint() const;
  binder.add_fun<bool, &QChar::isPrint>("isPrint");
  // bool isSpace() const;
  binder.add_fun<bool, &QChar::isSpace>("isSpace");
  // bool isMark() const;
  binder.add_fun<bool, &QChar::isMark>("isMark");
  // bool isPunct() const;
  binder.add_fun<bool, &QChar::isPunct>("isPunct");
  // bool isSymbol() const;
  binder.add_fun<bool, &QChar::isSymbol>("isSymbol");
  // bool isLetter() const;
  binder.add_fun<bool, &QChar::isLetter>("isLetter");
  // bool isNumber() const;
  binder.add_fun<bool, &QChar::isNumber>("isNumber");
  // bool isLetterOrNumber() const;
  binder.add_fun<bool, &QChar::isLetterOrNumber>("isLetterOrNumber");
  // bool isDigit() const;
  binder.add_fun<bool, &QChar::isDigit>("isDigit");
  // bool isLower() const;
  binder.add_fun<bool, &QChar::isLower>("isLower");
  // bool isUpper() const;
  binder.add_fun<bool, &QChar::isUpper>("isUpper");
  // bool isTitleCase() const;
  binder.add_fun<bool, &QChar::isTitleCase>("isTitleCase");
  // bool isNonCharacter() const;
  binder.add_fun<bool, &QChar::isNonCharacter>("isNonCharacter");
  // bool isHighSurrogate() const;
  binder.add_fun<bool, &QChar::isHighSurrogate>("isHighSurrogate");
  // bool isLowSurrogate() const;
  binder.add_fun<bool, &QChar::isLowSurrogate>("isLowSurrogate");
  // bool isSurrogate() const;
  binder.add_fun<bool, &QChar::isSurrogate>("isSurrogate");
  // uchar cell() const;
  binder.add_fun<uchar, &QChar::cell>("cell");
  // uchar row() const;
  binder.add_fun<uchar, &QChar::row>("row");
  // void setCell(uchar);
  binder.add_void_fun<uchar, &QChar::setCell>("setCell");
  // void setRow(uchar);
  binder.add_void_fun<uchar, &QChar::setRow>("setRow");
  // static bool isNonCharacter(uint);
  binder.add_static<bool, uint, &QChar::isNonCharacter>("isNonCharacter");
  // static bool isHighSurrogate(uint);
  binder.add_static<bool, uint, &QChar::isHighSurrogate>("isHighSurrogate");
  // static bool isLowSurrogate(uint);
  binder.add_static<bool, uint, &QChar::isLowSurrogate>("isLowSurrogate");
  // static bool isSurrogate(uint);
  binder.add_static<bool, uint, &QChar::isSurrogate>("isSurrogate");
  // static bool requiresSurrogates(uint);
  binder.add_static<bool, uint, &QChar::requiresSurrogates>("requiresSurrogates");
  // static uint surrogateToUcs4(ushort, ushort);
  binder.add_static<uint, ushort, ushort, &QChar::surrogateToUcs4>("surrogateToUcs4");
  // static uint surrogateToUcs4(QChar, QChar);
  binder.add_static<uint, QChar, QChar, &QChar::surrogateToUcs4>("surrogateToUcs4");
  // static ushort highSurrogate(uint);
  binder.add_static<ushort, uint, &QChar::highSurrogate>("highSurrogate");
  // static ushort lowSurrogate(uint);
  binder.add_static<ushort, uint, &QChar::lowSurrogate>("lowSurrogate");

  // The following functions have __fastcall calling convention (Microsoft specific) 
  // which prevents the use of templates...
  Symbol qcharsymbol{ qchar };
  // static QChar::Category category(uint);
  YASL_FUNCTION_1(qcharsymbol, "category", QChar::Category, QChar::category, uint).setStatic().create();
  // static QChar::Direction direction(uint);
  YASL_FUNCTION_1(qcharsymbol, "direction", QChar::Direction, QChar::direction, uint).setStatic().create();
  // static QChar::JoiningType joiningType(uint);
  YASL_FUNCTION_1(qcharsymbol, "joiningType", QChar::JoiningType, QChar::joiningType, uint).setStatic().create();
  // static QChar::Joining joining(uint);
  YASL_FUNCTION_1(qcharsymbol, "joining", QChar::Joining, QChar::joining, uint).setStatic().create();
  // static unsigned char combiningClass(uint);
  ///TODO YASL_FUNCTION_1(qcharsymbol, "combiningClass", unsigned char, QChar::combiningClass, uint).setStatic().create();
  // static uint mirroredChar(uint);
  YASL_FUNCTION_1(qcharsymbol, "mirroredChar", uint, QChar::mirroredChar, uint).setStatic().create();
  // static bool hasMirrored(uint);
  YASL_FUNCTION_1(qcharsymbol, "hasMirrored", bool, QChar::hasMirrored, uint).setStatic().create();
  // static QString decomposition(uint);
  YASL_FUNCTION_1(qcharsymbol, "decomposition", QString, QChar::decomposition, uint).setStatic().create();
  // static QChar::Decomposition decompositionTag(uint);
  YASL_FUNCTION_1(qcharsymbol, "decompositionTag", QChar::Decomposition, QChar::decompositionTag, uint).setStatic().create();
  // static int digitValue(uint);
  YASL_FUNCTION_1(qcharsymbol, "digitValue", int, QChar::digitValue, uint).setStatic().create();
  // static uint toLower(uint);
  YASL_FUNCTION_1(qcharsymbol, "toLower", uint, QChar::toLower, uint).setStatic().create();
  // static uint toUpper(uint);
  YASL_FUNCTION_1(qcharsymbol, "toUpper", uint, QChar::toUpper, uint).setStatic().create();
  // static uint toTitleCase(uint);
  YASL_FUNCTION_1(qcharsymbol, "toTitleCase", uint, QChar::toTitleCase, uint).setStatic().create();
  // static uint toCaseFolded(uint);
  YASL_FUNCTION_1(qcharsymbol, "toCaseFolded", uint, QChar::toCaseFolded, uint).setStatic().create();
  // static QChar::Script script(uint);
  YASL_FUNCTION_1(qcharsymbol, "toCaseFolded", QChar::Script, QChar::script, uint).setStatic().create();
  // static QChar::UnicodeVersion unicodeVersion(uint);
  YASL_FUNCTION_1(qcharsymbol, "unicodeVersion", QChar::UnicodeVersion, QChar::unicodeVersion, uint).setStatic().create();
  // static QChar::UnicodeVersion currentUnicodeVersion();
  YASL_FUNCTION_0(qcharsymbol, "currentUnicodeVersion", QChar::UnicodeVersion, QChar::currentUnicodeVersion).setStatic().create();
  // static bool isPrint(uint);
  YASL_FUNCTION_1(qcharsymbol, "isPrint", bool, QChar::isPrint, uint).setStatic().create();
  // static bool isSpace(uint);
  YASL_FUNCTION_1(qcharsymbol, "isSpace", bool, QChar::isSpace, uint).setStatic().create();
  // static bool isMark(uint);
  YASL_FUNCTION_1(qcharsymbol, "isMark", bool, QChar::isMark, uint).setStatic().create();
  // static bool isPunct(uint);
  YASL_FUNCTION_1(qcharsymbol, "isPunct", bool, QChar::isPunct, uint).setStatic().create();
  // static bool isSymbol(uint);
  YASL_FUNCTION_1(qcharsymbol, "isSymbol", bool, QChar::isSymbol, uint).setStatic().create();
  // static bool isLetter(uint);
  binder.add_static<bool, uint, &QChar::isLetter>("isLetter");
  // static bool isNumber(uint);
  binder.add_static<bool, uint, &QChar::isNumber>("isNumber");
  // static bool isLetterOrNumber(uint);
  binder.add_static<bool, uint, &QChar::isLetterOrNumber>("isLetterOrNumber");
  // static bool isDigit(uint);
  binder.add_static<bool, uint, &QChar::isDigit>("isDigit");
  // static bool isLower(uint);
  binder.add_static<bool, uint, &QChar::isLower>("isLower");
  // static bool isUpper(uint);
  binder.add_static<bool, uint, &QChar::isUpper>("isUpper");
  // static bool isTitleCase(uint);
  binder.add_static<bool, uint, &QChar::isTitleCase>("isTitleCase");
}

void register_qchar_file(script::Namespace root)
{
  using namespace script;

  register_char_class(root);
  binding::Namespace binder{ root };

  // bool operator==(QChar, QChar);
  binder.operators().eq<QChar, QChar>();
  // bool operator<(QChar, QChar);
  binder.operators().less<QChar, QChar>();
  // bool operator!=(QChar, QChar);
  binder.operators().neq<QChar, QChar>();
  // bool operator>=(QChar, QChar);
  binder.operators().geq<QChar, QChar>();
  // bool operator>(QChar, QChar);
  binder.operators().greater<QChar, QChar>();
  // bool operator<=(QChar, QChar);
  binder.operators().leq<QChar, QChar>();
  // bool operator==(QChar, std::nullptr_t);
  binder.operators().eq<QChar, std::nullptr_t>();
  // bool operator<(QChar, std::nullptr_t);
  binder.operators().less<QChar, std::nullptr_t>();
  // bool operator==(std::nullptr_t, QChar);
  binder.operators().eq<std::nullptr_t, QChar>();
  // bool operator<(std::nullptr_t, QChar);
  binder.operators().less<std::nullptr_t, QChar>();
  // bool operator!=(QChar, std::nullptr_t);
  binder.operators().neq<QChar, std::nullptr_t>();
  // bool operator>=(QChar, std::nullptr_t);
  binder.operators().geq<QChar, std::nullptr_t>();
  // bool operator>(QChar, std::nullptr_t);
  binder.operators().greater<QChar, std::nullptr_t>();
  // bool operator<=(QChar, std::nullptr_t);
  binder.operators().leq<QChar, std::nullptr_t>();
  // bool operator!=(std::nullptr_t, QChar);
  binder.operators().neq<std::nullptr_t, QChar>();
  // bool operator>=(std::nullptr_t, QChar);
  binder.operators().geq<std::nullptr_t, QChar>();
  // bool operator>(std::nullptr_t, QChar);
  binder.operators().greater<std::nullptr_t, QChar>();
  // bool operator<=(std::nullptr_t, QChar);
  binder.operators().leq<std::nullptr_t, QChar>();
  //// QDataStream & operator<<(QDataStream &, QChar);
  //binder.operators().left_shift<QDataStream &, QDataStream &, QChar>();
  //// QDataStream & operator>>(QDataStream &, QChar &);
  //binder.operators().right_shift<QDataStream &, QDataStream &, QChar &>();
}

