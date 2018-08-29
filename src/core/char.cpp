// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/char.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/char-functions.h"
#include "yasl/core/char.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_char__special_character_enum(script::Class char_)
{
  using namespace script;

  Enum special_character = char_.Enum("SpecialCharacter").setId(script::Type::QCharSpecialCharacter).get();

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

  Enum category = char_.Enum("Category").setId(script::Type::QCharCategory).get();

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

  Enum script = char_.Enum("Script").setId(script::Type::QCharScript).get();

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

  Enum direction = char_.Enum("Direction").setId(script::Type::QCharDirection).get();

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

  Enum decomposition = char_.Enum("Decomposition").setId(script::Type::QCharDecomposition).get();

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

  Enum joining_type = char_.Enum("JoiningType").setId(script::Type::QCharJoiningType).get();

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

  Enum joining = char_.Enum("Joining").setId(script::Type::QCharJoining).get();

  joining.addValue("OtherJoining", QChar::OtherJoining);
  joining.addValue("Dual", QChar::Dual);
  joining.addValue("Right", QChar::Right);
  joining.addValue("Center", QChar::Center);
}


static void register_char__combining_class_enum(script::Class char_)
{
  using namespace script;

  Enum combining_class = char_.Enum("CombiningClass").setId(script::Type::QCharCombiningClass).get();

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

  Enum unicode_version = char_.Enum("UnicodeVersion").setId(script::Type::QCharUnicodeVersion).get();

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

  Class char_ = ns.Class("Char").setId(script::Type::QChar).get();

  register_char__special_character_enum(char_);
  register_char__category_enum(char_);
  register_char__script_enum(char_);
  register_char__direction_enum(char_);
  register_char__decomposition_enum(char_);
  register_char__joining_type_enum(char_);
  register_char__joining_enum(char_);
  register_char__combining_class_enum(char_);
  register_char__unicode_version_enum(char_);
  binding::Class<QChar> binder{ char_ };

  // ~QChar();
  binder.add_dtor();
  // QChar();
  binder.ctors().add_default();
  // QChar(ushort);
  /// TODO: QChar(ushort);
  // QChar(uchar, uchar);
  /// TODO: QChar(uchar, uchar);
  // QChar(short);
  /// TODO: QChar(short);
  // QChar(uint);
  binder.ctors().add<uint>();
  // QChar(int);
  binder.ctors().add<int>();
  // QChar(QChar::SpecialCharacter);
  binder.ctors().add<QChar::SpecialCharacter>();
  // QChar(QLatin1Char);
  /// TODO: QChar(QLatin1Char);
  // QChar(char16_t);
  /// TODO: QChar(char16_t);
  // QChar(wchar_t);
  /// TODO: QChar(wchar_t);
  // QChar(char);
  binder.ctors().add<char>();
  // QChar(uchar);
  /// TODO: QChar(uchar);
  // QChar::Category category() const;
  binder.add_fun<QChar::Category, &QChar::category>("category");
  // QChar::Direction direction() const;
  binder.add_fun<QChar::Direction, &QChar::direction>("direction");
  // QChar::JoiningType joiningType() const;
  binder.add_fun<QChar::JoiningType, &QChar::joiningType>("joiningType");
  // QChar::Joining joining() const;
  binder.add_fun<QChar::Joining, &QChar::joining>("joining");
  // unsigned char combiningClass() const;
  /// TODO: unsigned char combiningClass() const;
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
  /// TODO: ushort unicode() const;
  // ushort & unicode();
  /// TODO: ushort & unicode();
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
  /// TODO: uchar cell() const;
  // uchar row() const;
  /// TODO: uchar row() const;
  // void setCell(uchar);
  /// TODO: void setCell(uchar);
  // void setRow(uchar);
  /// TODO: void setRow(uchar);
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
  /// TODO: static uint surrogateToUcs4(ushort, ushort);
  // static uint surrogateToUcs4(QChar, QChar);
  binder.add_static<uint, QChar, QChar, &QChar::surrogateToUcs4>("surrogateToUcs4");
  // static ushort highSurrogate(uint);
  /// TODO: static ushort highSurrogate(uint);
  // static ushort lowSurrogate(uint);
  /// TODO: static ushort lowSurrogate(uint);
  // QChar::Category qchar_category(uint);
  binder.add_static<QChar::Category, uint, &qchar_category>("category");
  // QChar::Direction qchar_direction(uint);
  binder.add_static<QChar::Direction, uint, &qchar_direction>("direction");
  // QChar::JoiningType qchar_joiningType(uint);
  binder.add_static<QChar::JoiningType, uint, &qchar_joiningType>("joiningType");
  // QChar::Joining qchar_joining(uint);
  binder.add_static<QChar::Joining, uint, &qchar_joining>("joining");
  // unsigned char qchar_combiningClass(uint);
  /// TODO: unsigned char qchar_combiningClass(uint);
  // uint qchar_mirroredChar(uint);
  binder.add_static<uint, uint, &qchar_mirroredChar>("mirroredChar");
  // bool qchar_hasMirrored(uint);
  binder.add_static<bool, uint, &qchar_hasMirrored>("hasMirrored");
  // static QString qchar_decomposition(uint);
  binder.add_static<QString, uint, &qchar_decomposition>("decomposition");
  // QChar::Decomposition qchar_decompositionTag(uint);
  binder.add_static<QChar::Decomposition, uint, &qchar_decompositionTag>("decompositionTag");
  // int qchar_digitValue(uint);
  binder.add_static<int, uint, &qchar_digitValue>("digitValue");
  // uint qchar_toLower(uint);
  binder.add_static<uint, uint, &qchar_toLower>("toLower");
  // uint qchar_toUpper(uint);
  binder.add_static<uint, uint, &qchar_toUpper>("toUpper");
  // uint qchar_toTitleCase(uint);
  binder.add_static<uint, uint, &qchar_toTitleCase>("toTitleCase");
  // uint qchar_toCaseFolded(uint);
  binder.add_static<uint, uint, &qchar_toCaseFolded>("toCaseFolded");
  // QChar::Script qchar_script(uint);
  binder.add_static<QChar::Script, uint, &qchar_script>("script");
  // QChar::UnicodeVersion qchar_unicodeVersion(uint);
  binder.add_static<QChar::UnicodeVersion, uint, &qchar_unicodeVersion>("unicodeVersion");
  // QChar::UnicodeVersion qchar_currentUnicodeVersion();
  binder.add_static<QChar::UnicodeVersion, &qchar_currentUnicodeVersion>("currentUnicodeVersion");
  // bool qchar_isPrint(uint);
  binder.add_static<bool, uint, &qchar_isPrint>("isPrint");
  // static bool isSpace(uint);
  binder.add_static<bool, uint, &QChar::isSpace>("isSpace");
  // bool qchar_isMark(uint);
  binder.add_static<bool, uint, &qchar_isMark>("isMark");
  // bool qchar_isPunct(uint);
  binder.add_static<bool, uint, &qchar_isPunct>("isPunct");
  // bool qchar_isSymbol(uint);
  binder.add_static<bool, uint, &qchar_isSymbol>("isSymbol");
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


void register_char__file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_char__class(ns);
  binding::Namespace binder{ ns };

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
  /// TODO: QDataStream & operator<<(QDataStream &, QChar);
  // QDataStream & operator>>(QDataStream &, QChar &);
  /// TODO: QDataStream & operator>>(QDataStream &, QChar &);
}

