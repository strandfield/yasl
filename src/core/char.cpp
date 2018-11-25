// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/char.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/char-functions.h"
#include "yasl/core/char.h"
#include "yasl/core/datastream.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_char__special_character_enum(script::Class char_)
{
  using namespace script;

  Enum special_character = char_.newEnum("SpecialCharacter").setId(script::Type::QCharSpecialCharacter).get();

  special_character.addValue("Null", QChar::Null);
  special_character.addValue("Tabulation", QChar::Tabulation);
  special_character.addValue("LineFeed", QChar::LineFeed);
  special_character.addValue("CarriageReturn", QChar::CarriageReturn);
  special_character.addValue("Space", QChar::Space);
  special_character.addValue("Nbsp", QChar::Nbsp);
  special_character.addValue("SoftHyphen", QChar::SoftHyphen);
  special_character.addValue("ReplacementCharacter", QChar::ReplacementCharacter);
  special_character.addValue("ObjectReplacementCharacter", QChar::ObjectReplacementCharacter);
  special_character.addValue("ByteOrderMark", QChar::ByteOrderMark);
  special_character.addValue("ByteOrderSwapped", QChar::ByteOrderSwapped);
  special_character.addValue("ParagraphSeparator", QChar::ParagraphSeparator);
  special_character.addValue("LineSeparator", QChar::LineSeparator);
  special_character.addValue("LastValidCodePoint", QChar::LastValidCodePoint);
}


static void register_char__category_enum(script::Class char_)
{
  using namespace script;

  Enum category = char_.newEnum("Category").setId(script::Type::QCharCategory).get();

  category.addValue("Mark_NonSpacing", QChar::Mark_NonSpacing);
  category.addValue("Mark_SpacingCombining", QChar::Mark_SpacingCombining);
  category.addValue("Mark_Enclosing", QChar::Mark_Enclosing);
  category.addValue("Number_DecimalDigit", QChar::Number_DecimalDigit);
  category.addValue("Number_Letter", QChar::Number_Letter);
  category.addValue("Number_Other", QChar::Number_Other);
  category.addValue("Separator_Space", QChar::Separator_Space);
  category.addValue("Separator_Line", QChar::Separator_Line);
  category.addValue("Separator_Paragraph", QChar::Separator_Paragraph);
  category.addValue("Other_Control", QChar::Other_Control);
  category.addValue("Other_Format", QChar::Other_Format);
  category.addValue("Other_Surrogate", QChar::Other_Surrogate);
  category.addValue("Other_PrivateUse", QChar::Other_PrivateUse);
  category.addValue("Other_NotAssigned", QChar::Other_NotAssigned);
  category.addValue("Letter_Uppercase", QChar::Letter_Uppercase);
  category.addValue("Letter_Lowercase", QChar::Letter_Lowercase);
  category.addValue("Letter_Titlecase", QChar::Letter_Titlecase);
  category.addValue("Letter_Modifier", QChar::Letter_Modifier);
  category.addValue("Letter_Other", QChar::Letter_Other);
  category.addValue("Punctuation_Connector", QChar::Punctuation_Connector);
  category.addValue("Punctuation_Dash", QChar::Punctuation_Dash);
  category.addValue("Punctuation_Open", QChar::Punctuation_Open);
  category.addValue("Punctuation_Close", QChar::Punctuation_Close);
  category.addValue("Punctuation_InitialQuote", QChar::Punctuation_InitialQuote);
  category.addValue("Punctuation_FinalQuote", QChar::Punctuation_FinalQuote);
  category.addValue("Punctuation_Other", QChar::Punctuation_Other);
  category.addValue("Symbol_Math", QChar::Symbol_Math);
  category.addValue("Symbol_Currency", QChar::Symbol_Currency);
  category.addValue("Symbol_Modifier", QChar::Symbol_Modifier);
  category.addValue("Symbol_Other", QChar::Symbol_Other);
}


static void register_char__script_enum(script::Class char_)
{
  using namespace script;

  Enum script = char_.newEnum("Script").setId(script::Type::QCharScript).get();

  script.addValue("Script_Unknown", QChar::Script_Unknown);
  script.addValue("Script_Inherited", QChar::Script_Inherited);
  script.addValue("Script_Common", QChar::Script_Common);
  script.addValue("Script_Latin", QChar::Script_Latin);
  script.addValue("Script_Greek", QChar::Script_Greek);
  script.addValue("Script_Cyrillic", QChar::Script_Cyrillic);
  script.addValue("Script_Armenian", QChar::Script_Armenian);
  script.addValue("Script_Hebrew", QChar::Script_Hebrew);
  script.addValue("Script_Arabic", QChar::Script_Arabic);
  script.addValue("Script_Syriac", QChar::Script_Syriac);
  script.addValue("Script_Thaana", QChar::Script_Thaana);
  script.addValue("Script_Devanagari", QChar::Script_Devanagari);
  script.addValue("Script_Bengali", QChar::Script_Bengali);
  script.addValue("Script_Gurmukhi", QChar::Script_Gurmukhi);
  script.addValue("Script_Gujarati", QChar::Script_Gujarati);
  script.addValue("Script_Oriya", QChar::Script_Oriya);
  script.addValue("Script_Tamil", QChar::Script_Tamil);
  script.addValue("Script_Telugu", QChar::Script_Telugu);
  script.addValue("Script_Kannada", QChar::Script_Kannada);
  script.addValue("Script_Malayalam", QChar::Script_Malayalam);
  script.addValue("Script_Sinhala", QChar::Script_Sinhala);
  script.addValue("Script_Thai", QChar::Script_Thai);
  script.addValue("Script_Lao", QChar::Script_Lao);
  script.addValue("Script_Tibetan", QChar::Script_Tibetan);
  script.addValue("Script_Myanmar", QChar::Script_Myanmar);
  script.addValue("Script_Georgian", QChar::Script_Georgian);
  script.addValue("Script_Hangul", QChar::Script_Hangul);
  script.addValue("Script_Ethiopic", QChar::Script_Ethiopic);
  script.addValue("Script_Cherokee", QChar::Script_Cherokee);
  script.addValue("Script_CanadianAboriginal", QChar::Script_CanadianAboriginal);
  script.addValue("Script_Ogham", QChar::Script_Ogham);
  script.addValue("Script_Runic", QChar::Script_Runic);
  script.addValue("Script_Khmer", QChar::Script_Khmer);
  script.addValue("Script_Mongolian", QChar::Script_Mongolian);
  script.addValue("Script_Hiragana", QChar::Script_Hiragana);
  script.addValue("Script_Katakana", QChar::Script_Katakana);
  script.addValue("Script_Bopomofo", QChar::Script_Bopomofo);
  script.addValue("Script_Han", QChar::Script_Han);
  script.addValue("Script_Yi", QChar::Script_Yi);
  script.addValue("Script_OldItalic", QChar::Script_OldItalic);
  script.addValue("Script_Gothic", QChar::Script_Gothic);
  script.addValue("Script_Deseret", QChar::Script_Deseret);
  script.addValue("Script_Tagalog", QChar::Script_Tagalog);
  script.addValue("Script_Hanunoo", QChar::Script_Hanunoo);
  script.addValue("Script_Buhid", QChar::Script_Buhid);
  script.addValue("Script_Tagbanwa", QChar::Script_Tagbanwa);
  script.addValue("Script_Coptic", QChar::Script_Coptic);
  script.addValue("Script_Limbu", QChar::Script_Limbu);
  script.addValue("Script_TaiLe", QChar::Script_TaiLe);
  script.addValue("Script_LinearB", QChar::Script_LinearB);
  script.addValue("Script_Ugaritic", QChar::Script_Ugaritic);
  script.addValue("Script_Shavian", QChar::Script_Shavian);
  script.addValue("Script_Osmanya", QChar::Script_Osmanya);
  script.addValue("Script_Cypriot", QChar::Script_Cypriot);
  script.addValue("Script_Braille", QChar::Script_Braille);
  script.addValue("Script_Buginese", QChar::Script_Buginese);
  script.addValue("Script_NewTaiLue", QChar::Script_NewTaiLue);
  script.addValue("Script_Glagolitic", QChar::Script_Glagolitic);
  script.addValue("Script_Tifinagh", QChar::Script_Tifinagh);
  script.addValue("Script_SylotiNagri", QChar::Script_SylotiNagri);
  script.addValue("Script_OldPersian", QChar::Script_OldPersian);
  script.addValue("Script_Kharoshthi", QChar::Script_Kharoshthi);
  script.addValue("Script_Balinese", QChar::Script_Balinese);
  script.addValue("Script_Cuneiform", QChar::Script_Cuneiform);
  script.addValue("Script_Phoenician", QChar::Script_Phoenician);
  script.addValue("Script_PhagsPa", QChar::Script_PhagsPa);
  script.addValue("Script_Nko", QChar::Script_Nko);
  script.addValue("Script_Sundanese", QChar::Script_Sundanese);
  script.addValue("Script_Lepcha", QChar::Script_Lepcha);
  script.addValue("Script_OlChiki", QChar::Script_OlChiki);
  script.addValue("Script_Vai", QChar::Script_Vai);
  script.addValue("Script_Saurashtra", QChar::Script_Saurashtra);
  script.addValue("Script_KayahLi", QChar::Script_KayahLi);
  script.addValue("Script_Rejang", QChar::Script_Rejang);
  script.addValue("Script_Lycian", QChar::Script_Lycian);
  script.addValue("Script_Carian", QChar::Script_Carian);
  script.addValue("Script_Lydian", QChar::Script_Lydian);
  script.addValue("Script_Cham", QChar::Script_Cham);
  script.addValue("Script_TaiTham", QChar::Script_TaiTham);
  script.addValue("Script_TaiViet", QChar::Script_TaiViet);
  script.addValue("Script_Avestan", QChar::Script_Avestan);
  script.addValue("Script_EgyptianHieroglyphs", QChar::Script_EgyptianHieroglyphs);
  script.addValue("Script_Samaritan", QChar::Script_Samaritan);
  script.addValue("Script_Lisu", QChar::Script_Lisu);
  script.addValue("Script_Bamum", QChar::Script_Bamum);
  script.addValue("Script_Javanese", QChar::Script_Javanese);
  script.addValue("Script_MeeteiMayek", QChar::Script_MeeteiMayek);
  script.addValue("Script_ImperialAramaic", QChar::Script_ImperialAramaic);
  script.addValue("Script_OldSouthArabian", QChar::Script_OldSouthArabian);
  script.addValue("Script_InscriptionalParthian", QChar::Script_InscriptionalParthian);
  script.addValue("Script_InscriptionalPahlavi", QChar::Script_InscriptionalPahlavi);
  script.addValue("Script_OldTurkic", QChar::Script_OldTurkic);
  script.addValue("Script_Kaithi", QChar::Script_Kaithi);
  script.addValue("Script_Batak", QChar::Script_Batak);
  script.addValue("Script_Brahmi", QChar::Script_Brahmi);
  script.addValue("Script_Mandaic", QChar::Script_Mandaic);
  script.addValue("Script_Chakma", QChar::Script_Chakma);
  script.addValue("Script_MeroiticCursive", QChar::Script_MeroiticCursive);
  script.addValue("Script_MeroiticHieroglyphs", QChar::Script_MeroiticHieroglyphs);
  script.addValue("Script_Miao", QChar::Script_Miao);
  script.addValue("Script_Sharada", QChar::Script_Sharada);
  script.addValue("Script_SoraSompeng", QChar::Script_SoraSompeng);
  script.addValue("Script_Takri", QChar::Script_Takri);
  script.addValue("Script_CaucasianAlbanian", QChar::Script_CaucasianAlbanian);
  script.addValue("Script_BassaVah", QChar::Script_BassaVah);
  script.addValue("Script_Duployan", QChar::Script_Duployan);
  script.addValue("Script_Elbasan", QChar::Script_Elbasan);
  script.addValue("Script_Grantha", QChar::Script_Grantha);
  script.addValue("Script_PahawhHmong", QChar::Script_PahawhHmong);
  script.addValue("Script_Khojki", QChar::Script_Khojki);
  script.addValue("Script_LinearA", QChar::Script_LinearA);
  script.addValue("Script_Mahajani", QChar::Script_Mahajani);
  script.addValue("Script_Manichaean", QChar::Script_Manichaean);
  script.addValue("Script_MendeKikakui", QChar::Script_MendeKikakui);
  script.addValue("Script_Modi", QChar::Script_Modi);
  script.addValue("Script_Mro", QChar::Script_Mro);
  script.addValue("Script_OldNorthArabian", QChar::Script_OldNorthArabian);
  script.addValue("Script_Nabataean", QChar::Script_Nabataean);
  script.addValue("Script_Palmyrene", QChar::Script_Palmyrene);
  script.addValue("Script_PauCinHau", QChar::Script_PauCinHau);
  script.addValue("Script_OldPermic", QChar::Script_OldPermic);
  script.addValue("Script_PsalterPahlavi", QChar::Script_PsalterPahlavi);
  script.addValue("Script_Siddham", QChar::Script_Siddham);
  script.addValue("Script_Khudawadi", QChar::Script_Khudawadi);
  script.addValue("Script_Tirhuta", QChar::Script_Tirhuta);
  script.addValue("Script_WarangCiti", QChar::Script_WarangCiti);
  script.addValue("Script_Ahom", QChar::Script_Ahom);
  script.addValue("Script_AnatolianHieroglyphs", QChar::Script_AnatolianHieroglyphs);
  script.addValue("Script_Hatran", QChar::Script_Hatran);
  script.addValue("Script_Multani", QChar::Script_Multani);
  script.addValue("Script_OldHungarian", QChar::Script_OldHungarian);
  script.addValue("Script_SignWriting", QChar::Script_SignWriting);
  script.addValue("ScriptCount", QChar::ScriptCount);
}


static void register_char__direction_enum(script::Class char_)
{
  using namespace script;

  Enum direction = char_.newEnum("Direction").setId(script::Type::QCharDirection).get();

  direction.addValue("DirL", QChar::DirL);
  direction.addValue("DirR", QChar::DirR);
  direction.addValue("DirEN", QChar::DirEN);
  direction.addValue("DirES", QChar::DirES);
  direction.addValue("DirET", QChar::DirET);
  direction.addValue("DirAN", QChar::DirAN);
  direction.addValue("DirCS", QChar::DirCS);
  direction.addValue("DirB", QChar::DirB);
  direction.addValue("DirS", QChar::DirS);
  direction.addValue("DirWS", QChar::DirWS);
  direction.addValue("DirON", QChar::DirON);
  direction.addValue("DirLRE", QChar::DirLRE);
  direction.addValue("DirLRO", QChar::DirLRO);
  direction.addValue("DirAL", QChar::DirAL);
  direction.addValue("DirRLE", QChar::DirRLE);
  direction.addValue("DirRLO", QChar::DirRLO);
  direction.addValue("DirPDF", QChar::DirPDF);
  direction.addValue("DirNSM", QChar::DirNSM);
  direction.addValue("DirBN", QChar::DirBN);
  direction.addValue("DirLRI", QChar::DirLRI);
  direction.addValue("DirRLI", QChar::DirRLI);
  direction.addValue("DirFSI", QChar::DirFSI);
  direction.addValue("DirPDI", QChar::DirPDI);
}


static void register_char__decomposition_enum(script::Class char_)
{
  using namespace script;

  Enum decomposition = char_.newEnum("Decomposition").setId(script::Type::QCharDecomposition).get();

  decomposition.addValue("NoDecomposition", QChar::NoDecomposition);
  decomposition.addValue("Canonical", QChar::Canonical);
  decomposition.addValue("Font", QChar::Font);
  decomposition.addValue("NoBreak", QChar::NoBreak);
  decomposition.addValue("Initial", QChar::Initial);
  decomposition.addValue("Medial", QChar::Medial);
  decomposition.addValue("Final", QChar::Final);
  decomposition.addValue("Isolated", QChar::Isolated);
  decomposition.addValue("Circle", QChar::Circle);
  decomposition.addValue("Super", QChar::Super);
  decomposition.addValue("Sub", QChar::Sub);
  decomposition.addValue("Vertical", QChar::Vertical);
  decomposition.addValue("Wide", QChar::Wide);
  decomposition.addValue("Narrow", QChar::Narrow);
  decomposition.addValue("Small", QChar::Small);
  decomposition.addValue("Square", QChar::Square);
  decomposition.addValue("Compat", QChar::Compat);
  decomposition.addValue("Fraction", QChar::Fraction);
}


static void register_char__joining_type_enum(script::Class char_)
{
  using namespace script;

  Enum joining_type = char_.newEnum("JoiningType").setId(script::Type::QCharJoiningType).get();

  joining_type.addValue("Joining_None", QChar::Joining_None);
  joining_type.addValue("Joining_Causing", QChar::Joining_Causing);
  joining_type.addValue("Joining_Dual", QChar::Joining_Dual);
  joining_type.addValue("Joining_Right", QChar::Joining_Right);
  joining_type.addValue("Joining_Left", QChar::Joining_Left);
  joining_type.addValue("Joining_Transparent", QChar::Joining_Transparent);
}


static void register_char__joining_enum(script::Class char_)
{
  using namespace script;

  Enum joining = char_.newEnum("Joining").setId(script::Type::QCharJoining).get();

  joining.addValue("OtherJoining", QChar::OtherJoining);
  joining.addValue("Dual", QChar::Dual);
  joining.addValue("Right", QChar::Right);
  joining.addValue("Center", QChar::Center);
}


static void register_char__combining_class_enum(script::Class char_)
{
  using namespace script;

  Enum combining_class = char_.newEnum("CombiningClass").setId(script::Type::QCharCombiningClass).get();

  combining_class.addValue("Combining_BelowLeftAttached", QChar::Combining_BelowLeftAttached);
  combining_class.addValue("Combining_BelowAttached", QChar::Combining_BelowAttached);
  combining_class.addValue("Combining_BelowRightAttached", QChar::Combining_BelowRightAttached);
  combining_class.addValue("Combining_LeftAttached", QChar::Combining_LeftAttached);
  combining_class.addValue("Combining_RightAttached", QChar::Combining_RightAttached);
  combining_class.addValue("Combining_AboveLeftAttached", QChar::Combining_AboveLeftAttached);
  combining_class.addValue("Combining_AboveAttached", QChar::Combining_AboveAttached);
  combining_class.addValue("Combining_AboveRightAttached", QChar::Combining_AboveRightAttached);
  combining_class.addValue("Combining_BelowLeft", QChar::Combining_BelowLeft);
  combining_class.addValue("Combining_Below", QChar::Combining_Below);
  combining_class.addValue("Combining_BelowRight", QChar::Combining_BelowRight);
  combining_class.addValue("Combining_Left", QChar::Combining_Left);
  combining_class.addValue("Combining_Right", QChar::Combining_Right);
  combining_class.addValue("Combining_AboveLeft", QChar::Combining_AboveLeft);
  combining_class.addValue("Combining_Above", QChar::Combining_Above);
  combining_class.addValue("Combining_AboveRight", QChar::Combining_AboveRight);
  combining_class.addValue("Combining_DoubleBelow", QChar::Combining_DoubleBelow);
  combining_class.addValue("Combining_DoubleAbove", QChar::Combining_DoubleAbove);
  combining_class.addValue("Combining_IotaSubscript", QChar::Combining_IotaSubscript);
}


static void register_char__unicode_version_enum(script::Class char_)
{
  using namespace script;

  Enum unicode_version = char_.newEnum("UnicodeVersion").setId(script::Type::QCharUnicodeVersion).get();

  unicode_version.addValue("Unicode_Unassigned", QChar::Unicode_Unassigned);
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
}


static void register_char__class(script::Namespace ns)
{
  using namespace script;

  Class char_ = ns.newClass("Char").setId(script::Type::QChar).get();

  register_char__special_character_enum(char_);
  register_char__category_enum(char_);
  register_char__script_enum(char_);
  register_char__direction_enum(char_);
  register_char__decomposition_enum(char_);
  register_char__joining_type_enum(char_);
  register_char__joining_enum(char_);
  register_char__combining_class_enum(char_);
  register_char__unicode_version_enum(char_);

  // ~QChar();
  bind::destructor<QChar>(char_).create();
  // QChar();
  bind::default_constructor<QChar>(char_).create();
  // QChar(ushort);
  /// TODO: QChar(ushort);
  // QChar(uchar, uchar);
  /// TODO: QChar(uchar, uchar);
  // QChar(short);
  /// TODO: QChar(short);
  // QChar(uint);
  bind::constructor<QChar, uint>(char_).create();
  // QChar(int);
  bind::constructor<QChar, int>(char_).create();
  // QChar(QChar::SpecialCharacter);
  bind::constructor<QChar, QChar::SpecialCharacter>(char_).create();
  // QChar(QLatin1Char);
  /// TODO: QChar(QLatin1Char);
  // QChar(char16_t);
  /// TODO: QChar(char16_t);
  // QChar(wchar_t);
  /// TODO: QChar(wchar_t);
  // QChar(char);
  bind::constructor<QChar, char>(char_).create();
  // QChar(uchar);
  /// TODO: QChar(uchar);
  // QChar::Category category() const;
  bind::member_function<QChar, QChar::Category, &QChar::category>(char_, "category").create();
  // QChar::Direction direction() const;
  bind::member_function<QChar, QChar::Direction, &QChar::direction>(char_, "direction").create();
  // QChar::JoiningType joiningType() const;
  bind::member_function<QChar, QChar::JoiningType, &QChar::joiningType>(char_, "joiningType").create();
  // QChar::Joining joining() const;
  bind::member_function<QChar, QChar::Joining, &QChar::joining>(char_, "joining").create();
  // unsigned char combiningClass() const;
  /// TODO: unsigned char combiningClass() const;
  // QChar mirroredChar() const;
  bind::member_function<QChar, QChar, &QChar::mirroredChar>(char_, "mirroredChar").create();
  // bool hasMirrored() const;
  bind::member_function<QChar, bool, &QChar::hasMirrored>(char_, "hasMirrored").create();
  // QString decomposition() const;
  bind::member_function<QChar, QString, &QChar::decomposition>(char_, "decomposition").create();
  // QChar::Decomposition decompositionTag() const;
  bind::member_function<QChar, QChar::Decomposition, &QChar::decompositionTag>(char_, "decompositionTag").create();
  // int digitValue() const;
  bind::member_function<QChar, int, &QChar::digitValue>(char_, "digitValue").create();
  // QChar toLower() const;
  bind::member_function<QChar, QChar, &QChar::toLower>(char_, "toLower").create();
  // QChar toUpper() const;
  bind::member_function<QChar, QChar, &QChar::toUpper>(char_, "toUpper").create();
  // QChar toTitleCase() const;
  bind::member_function<QChar, QChar, &QChar::toTitleCase>(char_, "toTitleCase").create();
  // QChar toCaseFolded() const;
  bind::member_function<QChar, QChar, &QChar::toCaseFolded>(char_, "toCaseFolded").create();
  // QChar::Script script() const;
  bind::member_function<QChar, QChar::Script, &QChar::script>(char_, "script").create();
  // QChar::UnicodeVersion unicodeVersion() const;
  bind::member_function<QChar, QChar::UnicodeVersion, &QChar::unicodeVersion>(char_, "unicodeVersion").create();
  // char toLatin1() const;
  bind::member_function<QChar, char, &QChar::toLatin1>(char_, "toLatin1").create();
  // ushort unicode() const;
  /// TODO: ushort unicode() const;
  // ushort & unicode();
  /// TODO: ushort & unicode();
  // static QChar fromLatin1(char);
  bind::static_member_function<QChar, QChar, char, &QChar::fromLatin1>(char_, "fromLatin1").create();
  // bool isNull() const;
  bind::member_function<QChar, bool, &QChar::isNull>(char_, "isNull").create();
  // bool isPrint() const;
  bind::member_function<QChar, bool, &QChar::isPrint>(char_, "isPrint").create();
  // bool isSpace() const;
  bind::member_function<QChar, bool, &QChar::isSpace>(char_, "isSpace").create();
  // bool isMark() const;
  bind::member_function<QChar, bool, &QChar::isMark>(char_, "isMark").create();
  // bool isPunct() const;
  bind::member_function<QChar, bool, &QChar::isPunct>(char_, "isPunct").create();
  // bool isSymbol() const;
  bind::member_function<QChar, bool, &QChar::isSymbol>(char_, "isSymbol").create();
  // bool isLetter() const;
  bind::member_function<QChar, bool, &QChar::isLetter>(char_, "isLetter").create();
  // bool isNumber() const;
  bind::member_function<QChar, bool, &QChar::isNumber>(char_, "isNumber").create();
  // bool isLetterOrNumber() const;
  bind::member_function<QChar, bool, &QChar::isLetterOrNumber>(char_, "isLetterOrNumber").create();
  // bool isDigit() const;
  bind::member_function<QChar, bool, &QChar::isDigit>(char_, "isDigit").create();
  // bool isLower() const;
  bind::member_function<QChar, bool, &QChar::isLower>(char_, "isLower").create();
  // bool isUpper() const;
  bind::member_function<QChar, bool, &QChar::isUpper>(char_, "isUpper").create();
  // bool isTitleCase() const;
  bind::member_function<QChar, bool, &QChar::isTitleCase>(char_, "isTitleCase").create();
  // bool isNonCharacter() const;
  bind::member_function<QChar, bool, &QChar::isNonCharacter>(char_, "isNonCharacter").create();
  // bool isHighSurrogate() const;
  bind::member_function<QChar, bool, &QChar::isHighSurrogate>(char_, "isHighSurrogate").create();
  // bool isLowSurrogate() const;
  bind::member_function<QChar, bool, &QChar::isLowSurrogate>(char_, "isLowSurrogate").create();
  // bool isSurrogate() const;
  bind::member_function<QChar, bool, &QChar::isSurrogate>(char_, "isSurrogate").create();
  // uchar cell() const;
  /// TODO: uchar cell() const;
  // uchar row() const;
  /// TODO: uchar row() const;
  // void setCell(uchar);
  /// TODO: void setCell(uchar);
  // void setRow(uchar);
  /// TODO: void setRow(uchar);
  // static bool isNonCharacter(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isNonCharacter>(char_, "isNonCharacter").create();
  // static bool isHighSurrogate(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isHighSurrogate>(char_, "isHighSurrogate").create();
  // static bool isLowSurrogate(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isLowSurrogate>(char_, "isLowSurrogate").create();
  // static bool isSurrogate(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isSurrogate>(char_, "isSurrogate").create();
  // static bool requiresSurrogates(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::requiresSurrogates>(char_, "requiresSurrogates").create();
  // static uint surrogateToUcs4(ushort, ushort);
  /// TODO: static uint surrogateToUcs4(ushort, ushort);
  // static uint surrogateToUcs4(QChar, QChar);
  bind::static_member_function<QChar, uint, QChar, QChar, &QChar::surrogateToUcs4>(char_, "surrogateToUcs4").create();
  // static ushort highSurrogate(uint);
  /// TODO: static ushort highSurrogate(uint);
  // static ushort lowSurrogate(uint);
  /// TODO: static ushort lowSurrogate(uint);
  // QChar::Category qchar_category(uint);
  bind::static_member_function<QChar, QChar::Category, uint, &qchar_category>(char_, "category").create();
  // QChar::Direction qchar_direction(uint);
  bind::static_member_function<QChar, QChar::Direction, uint, &qchar_direction>(char_, "direction").create();
  // QChar::JoiningType qchar_joiningType(uint);
  bind::static_member_function<QChar, QChar::JoiningType, uint, &qchar_joiningType>(char_, "joiningType").create();
  // QChar::Joining qchar_joining(uint);
  bind::static_member_function<QChar, QChar::Joining, uint, &qchar_joining>(char_, "joining").create();
  // unsigned char qchar_combiningClass(uint);
  /// TODO: unsigned char qchar_combiningClass(uint);
  // uint qchar_mirroredChar(uint);
  bind::static_member_function<QChar, uint, uint, &qchar_mirroredChar>(char_, "mirroredChar").create();
  // bool qchar_hasMirrored(uint);
  bind::static_member_function<QChar, bool, uint, &qchar_hasMirrored>(char_, "hasMirrored").create();
  // static QString qchar_decomposition(uint);
  bind::static_member_function<QChar, QString, uint, &qchar_decomposition>(char_, "decomposition").create();
  // QChar::Decomposition qchar_decompositionTag(uint);
  bind::static_member_function<QChar, QChar::Decomposition, uint, &qchar_decompositionTag>(char_, "decompositionTag").create();
  // int qchar_digitValue(uint);
  bind::static_member_function<QChar, int, uint, &qchar_digitValue>(char_, "digitValue").create();
  // uint qchar_toLower(uint);
  bind::static_member_function<QChar, uint, uint, &qchar_toLower>(char_, "toLower").create();
  // uint qchar_toUpper(uint);
  bind::static_member_function<QChar, uint, uint, &qchar_toUpper>(char_, "toUpper").create();
  // uint qchar_toTitleCase(uint);
  bind::static_member_function<QChar, uint, uint, &qchar_toTitleCase>(char_, "toTitleCase").create();
  // uint qchar_toCaseFolded(uint);
  bind::static_member_function<QChar, uint, uint, &qchar_toCaseFolded>(char_, "toCaseFolded").create();
  // QChar::Script qchar_script(uint);
  bind::static_member_function<QChar, QChar::Script, uint, &qchar_script>(char_, "script").create();
  // QChar::UnicodeVersion qchar_unicodeVersion(uint);
  bind::static_member_function<QChar, QChar::UnicodeVersion, uint, &qchar_unicodeVersion>(char_, "unicodeVersion").create();
  // QChar::UnicodeVersion qchar_currentUnicodeVersion();
  bind::static_member_function<QChar, QChar::UnicodeVersion, &qchar_currentUnicodeVersion>(char_, "currentUnicodeVersion").create();
  // bool qchar_isPrint(uint);
  bind::static_member_function<QChar, bool, uint, &qchar_isPrint>(char_, "isPrint").create();
  // static bool isSpace(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isSpace>(char_, "isSpace").create();
  // bool qchar_isMark(uint);
  bind::static_member_function<QChar, bool, uint, &qchar_isMark>(char_, "isMark").create();
  // bool qchar_isPunct(uint);
  bind::static_member_function<QChar, bool, uint, &qchar_isPunct>(char_, "isPunct").create();
  // bool qchar_isSymbol(uint);
  bind::static_member_function<QChar, bool, uint, &qchar_isSymbol>(char_, "isSymbol").create();
  // static bool isLetter(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isLetter>(char_, "isLetter").create();
  // static bool isNumber(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isNumber>(char_, "isNumber").create();
  // static bool isLetterOrNumber(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isLetterOrNumber>(char_, "isLetterOrNumber").create();
  // static bool isDigit(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isDigit>(char_, "isDigit").create();
  // static bool isLower(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isLower>(char_, "isLower").create();
  // static bool isUpper(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isUpper>(char_, "isUpper").create();
  // static bool isTitleCase(uint);
  bind::static_member_function<QChar, bool, uint, &QChar::isTitleCase>(char_, "isTitleCase").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QChar, QMetaType::QChar>>();
}


void register_char__file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_char__class(ns);

  // bool operator==(QChar, QChar);
  bind::op_eq<QChar, QChar>(ns);
  // bool operator<(QChar, QChar);
  bind::op_less<QChar, QChar>(ns);
  // bool operator!=(QChar, QChar);
  bind::op_neq<QChar, QChar>(ns);
  // bool operator>=(QChar, QChar);
  bind::op_geq<QChar, QChar>(ns);
  // bool operator>(QChar, QChar);
  bind::op_greater<QChar, QChar>(ns);
  // bool operator<=(QChar, QChar);
  bind::op_leq<QChar, QChar>(ns);
  // bool operator==(QChar, std::nullptr_t);
  /// TODO: bool operator==(QChar, std::nullptr_t);
  // bool operator<(QChar, std::nullptr_t);
  /// TODO: bool operator<(QChar, std::nullptr_t);
  // bool operator==(std::nullptr_t, QChar);
  /// TODO: bool operator==(std::nullptr_t, QChar);
  // bool operator<(std::nullptr_t, QChar);
  /// TODO: bool operator<(std::nullptr_t, QChar);
  // bool operator!=(QChar, std::nullptr_t);
  /// TODO: bool operator!=(QChar, std::nullptr_t);
  // bool operator>=(QChar, std::nullptr_t);
  /// TODO: bool operator>=(QChar, std::nullptr_t);
  // bool operator>(QChar, std::nullptr_t);
  /// TODO: bool operator>(QChar, std::nullptr_t);
  // bool operator<=(QChar, std::nullptr_t);
  /// TODO: bool operator<=(QChar, std::nullptr_t);
  // bool operator!=(std::nullptr_t, QChar);
  /// TODO: bool operator!=(std::nullptr_t, QChar);
  // bool operator>=(std::nullptr_t, QChar);
  /// TODO: bool operator>=(std::nullptr_t, QChar);
  // bool operator>(std::nullptr_t, QChar);
  /// TODO: bool operator>(std::nullptr_t, QChar);
  // bool operator<=(std::nullptr_t, QChar);
  /// TODO: bool operator<=(std::nullptr_t, QChar);
  // QDataStream & operator<<(QDataStream &, QChar);
  bind::op_put_to<QDataStream &, QChar>(ns);
  // QDataStream & operator>>(QDataStream &, QChar &);
  bind::op_read_from<QDataStream &, QChar &>(ns);
}

