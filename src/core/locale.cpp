// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/locale.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"
#include "yasl/core/listspecializations.h"

#include "yasl/core/char.h"
#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/locale.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_locale_language_enum(script::Class locale)
{
  using namespace script;

  Enum language = locale.Enum("Language").setId(script::Type::QLocaleLanguage).get();

  language.addValue("AnyLanguage", QLocale::AnyLanguage);
  language.addValue("C", QLocale::C);
  language.addValue("Abkhazian", QLocale::Abkhazian);
  language.addValue("Oromo", QLocale::Oromo);
  language.addValue("Afar", QLocale::Afar);
  language.addValue("Afrikaans", QLocale::Afrikaans);
  language.addValue("Albanian", QLocale::Albanian);
  language.addValue("Amharic", QLocale::Amharic);
  language.addValue("Arabic", QLocale::Arabic);
  language.addValue("Armenian", QLocale::Armenian);
  language.addValue("Assamese", QLocale::Assamese);
  language.addValue("Aymara", QLocale::Aymara);
  language.addValue("Azerbaijani", QLocale::Azerbaijani);
  language.addValue("Bashkir", QLocale::Bashkir);
  language.addValue("Basque", QLocale::Basque);
  language.addValue("Bengali", QLocale::Bengali);
  language.addValue("Dzongkha", QLocale::Dzongkha);
  language.addValue("Bihari", QLocale::Bihari);
  language.addValue("Bislama", QLocale::Bislama);
  language.addValue("Breton", QLocale::Breton);
  language.addValue("Bulgarian", QLocale::Bulgarian);
  language.addValue("Burmese", QLocale::Burmese);
  language.addValue("Belarusian", QLocale::Belarusian);
  language.addValue("Khmer", QLocale::Khmer);
  language.addValue("Catalan", QLocale::Catalan);
  language.addValue("Chinese", QLocale::Chinese);
  language.addValue("Corsican", QLocale::Corsican);
  language.addValue("Croatian", QLocale::Croatian);
  language.addValue("Czech", QLocale::Czech);
  language.addValue("Danish", QLocale::Danish);
  language.addValue("Dutch", QLocale::Dutch);
  language.addValue("English", QLocale::English);
  language.addValue("Esperanto", QLocale::Esperanto);
  language.addValue("Estonian", QLocale::Estonian);
  language.addValue("Faroese", QLocale::Faroese);
  language.addValue("Fijian", QLocale::Fijian);
  language.addValue("Finnish", QLocale::Finnish);
  language.addValue("French", QLocale::French);
  language.addValue("WesternFrisian", QLocale::WesternFrisian);
  language.addValue("Gaelic", QLocale::Gaelic);
  language.addValue("Galician", QLocale::Galician);
  language.addValue("Georgian", QLocale::Georgian);
  language.addValue("German", QLocale::German);
  language.addValue("Greek", QLocale::Greek);
  language.addValue("Greenlandic", QLocale::Greenlandic);
  language.addValue("Guarani", QLocale::Guarani);
  language.addValue("Gujarati", QLocale::Gujarati);
  language.addValue("Hausa", QLocale::Hausa);
  language.addValue("Hebrew", QLocale::Hebrew);
  language.addValue("Hindi", QLocale::Hindi);
  language.addValue("Hungarian", QLocale::Hungarian);
  language.addValue("Icelandic", QLocale::Icelandic);
  language.addValue("Indonesian", QLocale::Indonesian);
  language.addValue("Interlingua", QLocale::Interlingua);
  language.addValue("Interlingue", QLocale::Interlingue);
  language.addValue("Inuktitut", QLocale::Inuktitut);
  language.addValue("Inupiak", QLocale::Inupiak);
  language.addValue("Irish", QLocale::Irish);
  language.addValue("Italian", QLocale::Italian);
  language.addValue("Japanese", QLocale::Japanese);
  language.addValue("Javanese", QLocale::Javanese);
  language.addValue("Kannada", QLocale::Kannada);
  language.addValue("Kashmiri", QLocale::Kashmiri);
  language.addValue("Kazakh", QLocale::Kazakh);
  language.addValue("Kinyarwanda", QLocale::Kinyarwanda);
  language.addValue("Kirghiz", QLocale::Kirghiz);
  language.addValue("Korean", QLocale::Korean);
  language.addValue("Kurdish", QLocale::Kurdish);
  language.addValue("Rundi", QLocale::Rundi);
  language.addValue("Lao", QLocale::Lao);
  language.addValue("Latin", QLocale::Latin);
  language.addValue("Latvian", QLocale::Latvian);
  language.addValue("Lingala", QLocale::Lingala);
  language.addValue("Lithuanian", QLocale::Lithuanian);
  language.addValue("Macedonian", QLocale::Macedonian);
  language.addValue("Malagasy", QLocale::Malagasy);
  language.addValue("Malay", QLocale::Malay);
  language.addValue("Malayalam", QLocale::Malayalam);
  language.addValue("Maltese", QLocale::Maltese);
  language.addValue("Maori", QLocale::Maori);
  language.addValue("Marathi", QLocale::Marathi);
  language.addValue("Marshallese", QLocale::Marshallese);
  language.addValue("Mongolian", QLocale::Mongolian);
  language.addValue("NauruLanguage", QLocale::NauruLanguage);
  language.addValue("Nepali", QLocale::Nepali);
  language.addValue("NorwegianBokmal", QLocale::NorwegianBokmal);
  language.addValue("Occitan", QLocale::Occitan);
  language.addValue("Oriya", QLocale::Oriya);
  language.addValue("Pashto", QLocale::Pashto);
  language.addValue("Persian", QLocale::Persian);
  language.addValue("Polish", QLocale::Polish);
  language.addValue("Portuguese", QLocale::Portuguese);
  language.addValue("Punjabi", QLocale::Punjabi);
  language.addValue("Quechua", QLocale::Quechua);
  language.addValue("Romansh", QLocale::Romansh);
  language.addValue("Romanian", QLocale::Romanian);
  language.addValue("Russian", QLocale::Russian);
  language.addValue("Samoan", QLocale::Samoan);
  language.addValue("Sango", QLocale::Sango);
  language.addValue("Sanskrit", QLocale::Sanskrit);
  language.addValue("Serbian", QLocale::Serbian);
  language.addValue("Ossetic", QLocale::Ossetic);
  language.addValue("SouthernSotho", QLocale::SouthernSotho);
  language.addValue("Tswana", QLocale::Tswana);
  language.addValue("Shona", QLocale::Shona);
  language.addValue("Sindhi", QLocale::Sindhi);
  language.addValue("Sinhala", QLocale::Sinhala);
  language.addValue("Swati", QLocale::Swati);
  language.addValue("Slovak", QLocale::Slovak);
  language.addValue("Slovenian", QLocale::Slovenian);
  language.addValue("Somali", QLocale::Somali);
  language.addValue("Spanish", QLocale::Spanish);
  language.addValue("Sundanese", QLocale::Sundanese);
  language.addValue("Swahili", QLocale::Swahili);
  language.addValue("Swedish", QLocale::Swedish);
  language.addValue("Sardinian", QLocale::Sardinian);
  language.addValue("Tajik", QLocale::Tajik);
  language.addValue("Tamil", QLocale::Tamil);
  language.addValue("Tatar", QLocale::Tatar);
  language.addValue("Telugu", QLocale::Telugu);
  language.addValue("Thai", QLocale::Thai);
  language.addValue("Tibetan", QLocale::Tibetan);
  language.addValue("Tigrinya", QLocale::Tigrinya);
  language.addValue("Tongan", QLocale::Tongan);
  language.addValue("Tsonga", QLocale::Tsonga);
  language.addValue("Turkish", QLocale::Turkish);
  language.addValue("Turkmen", QLocale::Turkmen);
  language.addValue("Tahitian", QLocale::Tahitian);
  language.addValue("Uighur", QLocale::Uighur);
  language.addValue("Ukrainian", QLocale::Ukrainian);
  language.addValue("Urdu", QLocale::Urdu);
  language.addValue("Uzbek", QLocale::Uzbek);
  language.addValue("Vietnamese", QLocale::Vietnamese);
  language.addValue("Volapuk", QLocale::Volapuk);
  language.addValue("Welsh", QLocale::Welsh);
  language.addValue("Wolof", QLocale::Wolof);
  language.addValue("Xhosa", QLocale::Xhosa);
  language.addValue("Yiddish", QLocale::Yiddish);
  language.addValue("Yoruba", QLocale::Yoruba);
  language.addValue("Zhuang", QLocale::Zhuang);
  language.addValue("Zulu", QLocale::Zulu);
  language.addValue("NorwegianNynorsk", QLocale::NorwegianNynorsk);
  language.addValue("Bosnian", QLocale::Bosnian);
  language.addValue("Divehi", QLocale::Divehi);
  language.addValue("Manx", QLocale::Manx);
  language.addValue("Cornish", QLocale::Cornish);
  language.addValue("Akan", QLocale::Akan);
  language.addValue("Konkani", QLocale::Konkani);
  language.addValue("Ga", QLocale::Ga);
  language.addValue("Igbo", QLocale::Igbo);
  language.addValue("Kamba", QLocale::Kamba);
  language.addValue("Syriac", QLocale::Syriac);
  language.addValue("Blin", QLocale::Blin);
  language.addValue("Geez", QLocale::Geez);
  language.addValue("Koro", QLocale::Koro);
  language.addValue("Sidamo", QLocale::Sidamo);
  language.addValue("Atsam", QLocale::Atsam);
  language.addValue("Tigre", QLocale::Tigre);
  language.addValue("Jju", QLocale::Jju);
  language.addValue("Friulian", QLocale::Friulian);
  language.addValue("Venda", QLocale::Venda);
  language.addValue("Ewe", QLocale::Ewe);
  language.addValue("Walamo", QLocale::Walamo);
  language.addValue("Hawaiian", QLocale::Hawaiian);
  language.addValue("Tyap", QLocale::Tyap);
  language.addValue("Nyanja", QLocale::Nyanja);
  language.addValue("Filipino", QLocale::Filipino);
  language.addValue("SwissGerman", QLocale::SwissGerman);
  language.addValue("SichuanYi", QLocale::SichuanYi);
  language.addValue("Kpelle", QLocale::Kpelle);
  language.addValue("LowGerman", QLocale::LowGerman);
  language.addValue("SouthNdebele", QLocale::SouthNdebele);
  language.addValue("NorthernSotho", QLocale::NorthernSotho);
  language.addValue("NorthernSami", QLocale::NorthernSami);
  language.addValue("Taroko", QLocale::Taroko);
  language.addValue("Gusii", QLocale::Gusii);
  language.addValue("Taita", QLocale::Taita);
  language.addValue("Fulah", QLocale::Fulah);
  language.addValue("Kikuyu", QLocale::Kikuyu);
  language.addValue("Samburu", QLocale::Samburu);
  language.addValue("Sena", QLocale::Sena);
  language.addValue("NorthNdebele", QLocale::NorthNdebele);
  language.addValue("Rombo", QLocale::Rombo);
  language.addValue("Tachelhit", QLocale::Tachelhit);
  language.addValue("Kabyle", QLocale::Kabyle);
  language.addValue("Nyankole", QLocale::Nyankole);
  language.addValue("Bena", QLocale::Bena);
  language.addValue("Vunjo", QLocale::Vunjo);
  language.addValue("Bambara", QLocale::Bambara);
  language.addValue("Embu", QLocale::Embu);
  language.addValue("Cherokee", QLocale::Cherokee);
  language.addValue("Morisyen", QLocale::Morisyen);
  language.addValue("Makonde", QLocale::Makonde);
  language.addValue("Langi", QLocale::Langi);
  language.addValue("Ganda", QLocale::Ganda);
  language.addValue("Bemba", QLocale::Bemba);
  language.addValue("Kabuverdianu", QLocale::Kabuverdianu);
  language.addValue("Meru", QLocale::Meru);
  language.addValue("Kalenjin", QLocale::Kalenjin);
  language.addValue("Nama", QLocale::Nama);
  language.addValue("Machame", QLocale::Machame);
  language.addValue("Colognian", QLocale::Colognian);
  language.addValue("Masai", QLocale::Masai);
  language.addValue("Soga", QLocale::Soga);
  language.addValue("Luyia", QLocale::Luyia);
  language.addValue("Asu", QLocale::Asu);
  language.addValue("Teso", QLocale::Teso);
  language.addValue("Saho", QLocale::Saho);
  language.addValue("KoyraChiini", QLocale::KoyraChiini);
  language.addValue("Rwa", QLocale::Rwa);
  language.addValue("Luo", QLocale::Luo);
  language.addValue("Chiga", QLocale::Chiga);
  language.addValue("CentralMoroccoTamazight", QLocale::CentralMoroccoTamazight);
  language.addValue("KoyraboroSenni", QLocale::KoyraboroSenni);
  language.addValue("Shambala", QLocale::Shambala);
  language.addValue("Bodo", QLocale::Bodo);
  language.addValue("Avaric", QLocale::Avaric);
  language.addValue("Chamorro", QLocale::Chamorro);
  language.addValue("Chechen", QLocale::Chechen);
  language.addValue("Church", QLocale::Church);
  language.addValue("Chuvash", QLocale::Chuvash);
  language.addValue("Cree", QLocale::Cree);
  language.addValue("Haitian", QLocale::Haitian);
  language.addValue("Herero", QLocale::Herero);
  language.addValue("HiriMotu", QLocale::HiriMotu);
  language.addValue("Kanuri", QLocale::Kanuri);
  language.addValue("Komi", QLocale::Komi);
  language.addValue("Kongo", QLocale::Kongo);
  language.addValue("Kwanyama", QLocale::Kwanyama);
  language.addValue("Limburgish", QLocale::Limburgish);
  language.addValue("LubaKatanga", QLocale::LubaKatanga);
  language.addValue("Luxembourgish", QLocale::Luxembourgish);
  language.addValue("Navaho", QLocale::Navaho);
  language.addValue("Ndonga", QLocale::Ndonga);
  language.addValue("Ojibwa", QLocale::Ojibwa);
  language.addValue("Pali", QLocale::Pali);
  language.addValue("Walloon", QLocale::Walloon);
  language.addValue("Aghem", QLocale::Aghem);
  language.addValue("Basaa", QLocale::Basaa);
  language.addValue("Zarma", QLocale::Zarma);
  language.addValue("Duala", QLocale::Duala);
  language.addValue("JolaFonyi", QLocale::JolaFonyi);
  language.addValue("Ewondo", QLocale::Ewondo);
  language.addValue("Bafia", QLocale::Bafia);
  language.addValue("MakhuwaMeetto", QLocale::MakhuwaMeetto);
  language.addValue("Mundang", QLocale::Mundang);
  language.addValue("Kwasio", QLocale::Kwasio);
  language.addValue("Nuer", QLocale::Nuer);
  language.addValue("Sakha", QLocale::Sakha);
  language.addValue("Sangu", QLocale::Sangu);
  language.addValue("CongoSwahili", QLocale::CongoSwahili);
  language.addValue("Tasawaq", QLocale::Tasawaq);
  language.addValue("Vai", QLocale::Vai);
  language.addValue("Walser", QLocale::Walser);
  language.addValue("Yangben", QLocale::Yangben);
  language.addValue("Avestan", QLocale::Avestan);
  language.addValue("Asturian", QLocale::Asturian);
  language.addValue("Ngomba", QLocale::Ngomba);
  language.addValue("Kako", QLocale::Kako);
  language.addValue("Meta", QLocale::Meta);
  language.addValue("Ngiemboon", QLocale::Ngiemboon);
  language.addValue("Aragonese", QLocale::Aragonese);
  language.addValue("Akkadian", QLocale::Akkadian);
  language.addValue("AncientEgyptian", QLocale::AncientEgyptian);
  language.addValue("AncientGreek", QLocale::AncientGreek);
  language.addValue("Aramaic", QLocale::Aramaic);
  language.addValue("Balinese", QLocale::Balinese);
  language.addValue("Bamun", QLocale::Bamun);
  language.addValue("BatakToba", QLocale::BatakToba);
  language.addValue("Buginese", QLocale::Buginese);
  language.addValue("Buhid", QLocale::Buhid);
  language.addValue("Carian", QLocale::Carian);
  language.addValue("Chakma", QLocale::Chakma);
  language.addValue("ClassicalMandaic", QLocale::ClassicalMandaic);
  language.addValue("Coptic", QLocale::Coptic);
  language.addValue("Dogri", QLocale::Dogri);
  language.addValue("EasternCham", QLocale::EasternCham);
  language.addValue("EasternKayah", QLocale::EasternKayah);
  language.addValue("Etruscan", QLocale::Etruscan);
  language.addValue("Gothic", QLocale::Gothic);
  language.addValue("Hanunoo", QLocale::Hanunoo);
  language.addValue("Ingush", QLocale::Ingush);
  language.addValue("LargeFloweryMiao", QLocale::LargeFloweryMiao);
  language.addValue("Lepcha", QLocale::Lepcha);
  language.addValue("Limbu", QLocale::Limbu);
  language.addValue("Lisu", QLocale::Lisu);
  language.addValue("Lu", QLocale::Lu);
  language.addValue("Lycian", QLocale::Lycian);
  language.addValue("Lydian", QLocale::Lydian);
  language.addValue("Mandingo", QLocale::Mandingo);
  language.addValue("Manipuri", QLocale::Manipuri);
  language.addValue("Meroitic", QLocale::Meroitic);
  language.addValue("NorthernThai", QLocale::NorthernThai);
  language.addValue("OldIrish", QLocale::OldIrish);
  language.addValue("OldNorse", QLocale::OldNorse);
  language.addValue("OldPersian", QLocale::OldPersian);
  language.addValue("OldTurkish", QLocale::OldTurkish);
  language.addValue("Pahlavi", QLocale::Pahlavi);
  language.addValue("Parthian", QLocale::Parthian);
  language.addValue("Phoenician", QLocale::Phoenician);
  language.addValue("PrakritLanguage", QLocale::PrakritLanguage);
  language.addValue("Rejang", QLocale::Rejang);
  language.addValue("Sabaean", QLocale::Sabaean);
  language.addValue("Samaritan", QLocale::Samaritan);
  language.addValue("Santali", QLocale::Santali);
  language.addValue("Saurashtra", QLocale::Saurashtra);
  language.addValue("Sora", QLocale::Sora);
  language.addValue("Sylheti", QLocale::Sylheti);
  language.addValue("Tagbanwa", QLocale::Tagbanwa);
  language.addValue("TaiDam", QLocale::TaiDam);
  language.addValue("TaiNua", QLocale::TaiNua);
  language.addValue("Ugaritic", QLocale::Ugaritic);
  language.addValue("Akoose", QLocale::Akoose);
  language.addValue("Lakota", QLocale::Lakota);
  language.addValue("StandardMoroccanTamazight", QLocale::StandardMoroccanTamazight);
  language.addValue("Mapuche", QLocale::Mapuche);
  language.addValue("CentralKurdish", QLocale::CentralKurdish);
  language.addValue("LowerSorbian", QLocale::LowerSorbian);
  language.addValue("UpperSorbian", QLocale::UpperSorbian);
  language.addValue("Kenyang", QLocale::Kenyang);
  language.addValue("Mohawk", QLocale::Mohawk);
  language.addValue("Nko", QLocale::Nko);
  language.addValue("Prussian", QLocale::Prussian);
  language.addValue("Kiche", QLocale::Kiche);
  language.addValue("SouthernSami", QLocale::SouthernSami);
  language.addValue("LuleSami", QLocale::LuleSami);
  language.addValue("InariSami", QLocale::InariSami);
  language.addValue("SkoltSami", QLocale::SkoltSami);
  language.addValue("Warlpiri", QLocale::Warlpiri);
  language.addValue("ManichaeanMiddlePersian", QLocale::ManichaeanMiddlePersian);
  language.addValue("Mende", QLocale::Mende);
  language.addValue("AncientNorthArabian", QLocale::AncientNorthArabian);
  language.addValue("LinearA", QLocale::LinearA);
  language.addValue("HmongNjua", QLocale::HmongNjua);
  language.addValue("Ho", QLocale::Ho);
  language.addValue("Lezghian", QLocale::Lezghian);
  language.addValue("Bassa", QLocale::Bassa);
  language.addValue("Mono", QLocale::Mono);
  language.addValue("TedimChin", QLocale::TedimChin);
  language.addValue("Maithili", QLocale::Maithili);
  language.addValue("Ahom", QLocale::Ahom);
  language.addValue("AmericanSignLanguage", QLocale::AmericanSignLanguage);
  language.addValue("ArdhamagadhiPrakrit", QLocale::ArdhamagadhiPrakrit);
  language.addValue("Bhojpuri", QLocale::Bhojpuri);
  language.addValue("HieroglyphicLuwian", QLocale::HieroglyphicLuwian);
  language.addValue("LiteraryChinese", QLocale::LiteraryChinese);
  language.addValue("Mazanderani", QLocale::Mazanderani);
  language.addValue("Mru", QLocale::Mru);
  language.addValue("Newari", QLocale::Newari);
  language.addValue("NorthernLuri", QLocale::NorthernLuri);
  language.addValue("Palauan", QLocale::Palauan);
  language.addValue("Papiamento", QLocale::Papiamento);
  language.addValue("Saraiki", QLocale::Saraiki);
  language.addValue("TokelauLanguage", QLocale::TokelauLanguage);
  language.addValue("TokPisin", QLocale::TokPisin);
  language.addValue("TuvaluLanguage", QLocale::TuvaluLanguage);
  language.addValue("UncodedLanguages", QLocale::UncodedLanguages);
  language.addValue("Cantonese", QLocale::Cantonese);
  language.addValue("Osage", QLocale::Osage);
  language.addValue("Tangut", QLocale::Tangut);
  language.addValue("Norwegian", QLocale::Norwegian);
  language.addValue("Moldavian", QLocale::Moldavian);
  language.addValue("SerboCroatian", QLocale::SerboCroatian);
  language.addValue("Tagalog", QLocale::Tagalog);
  language.addValue("Twi", QLocale::Twi);
  language.addValue("Afan", QLocale::Afan);
  language.addValue("Byelorussian", QLocale::Byelorussian);
  language.addValue("Bhutani", QLocale::Bhutani);
  language.addValue("Cambodian", QLocale::Cambodian);
  language.addValue("Kurundi", QLocale::Kurundi);
  language.addValue("RhaetoRomance", QLocale::RhaetoRomance);
  language.addValue("Chewa", QLocale::Chewa);
  language.addValue("Frisian", QLocale::Frisian);
  language.addValue("Uigur", QLocale::Uigur);
  language.addValue("LastLanguage", QLocale::LastLanguage);
}


static void register_locale_script_enum(script::Class locale)
{
  using namespace script;

  Enum script = locale.Enum("Script").setId(script::Type::QLocaleScript).get();

  script.addValue("AnyScript", QLocale::AnyScript);
  script.addValue("ArabicScript", QLocale::ArabicScript);
  script.addValue("CyrillicScript", QLocale::CyrillicScript);
  script.addValue("DeseretScript", QLocale::DeseretScript);
  script.addValue("GurmukhiScript", QLocale::GurmukhiScript);
  script.addValue("SimplifiedHanScript", QLocale::SimplifiedHanScript);
  script.addValue("TraditionalHanScript", QLocale::TraditionalHanScript);
  script.addValue("LatinScript", QLocale::LatinScript);
  script.addValue("MongolianScript", QLocale::MongolianScript);
  script.addValue("TifinaghScript", QLocale::TifinaghScript);
  script.addValue("ArmenianScript", QLocale::ArmenianScript);
  script.addValue("BengaliScript", QLocale::BengaliScript);
  script.addValue("CherokeeScript", QLocale::CherokeeScript);
  script.addValue("DevanagariScript", QLocale::DevanagariScript);
  script.addValue("EthiopicScript", QLocale::EthiopicScript);
  script.addValue("GeorgianScript", QLocale::GeorgianScript);
  script.addValue("GreekScript", QLocale::GreekScript);
  script.addValue("GujaratiScript", QLocale::GujaratiScript);
  script.addValue("HebrewScript", QLocale::HebrewScript);
  script.addValue("JapaneseScript", QLocale::JapaneseScript);
  script.addValue("KhmerScript", QLocale::KhmerScript);
  script.addValue("KannadaScript", QLocale::KannadaScript);
  script.addValue("KoreanScript", QLocale::KoreanScript);
  script.addValue("LaoScript", QLocale::LaoScript);
  script.addValue("MalayalamScript", QLocale::MalayalamScript);
  script.addValue("MyanmarScript", QLocale::MyanmarScript);
  script.addValue("OriyaScript", QLocale::OriyaScript);
  script.addValue("TamilScript", QLocale::TamilScript);
  script.addValue("TeluguScript", QLocale::TeluguScript);
  script.addValue("ThaanaScript", QLocale::ThaanaScript);
  script.addValue("ThaiScript", QLocale::ThaiScript);
  script.addValue("TibetanScript", QLocale::TibetanScript);
  script.addValue("SinhalaScript", QLocale::SinhalaScript);
  script.addValue("SyriacScript", QLocale::SyriacScript);
  script.addValue("YiScript", QLocale::YiScript);
  script.addValue("VaiScript", QLocale::VaiScript);
  script.addValue("AvestanScript", QLocale::AvestanScript);
  script.addValue("BalineseScript", QLocale::BalineseScript);
  script.addValue("BamumScript", QLocale::BamumScript);
  script.addValue("BatakScript", QLocale::BatakScript);
  script.addValue("BopomofoScript", QLocale::BopomofoScript);
  script.addValue("BrahmiScript", QLocale::BrahmiScript);
  script.addValue("BugineseScript", QLocale::BugineseScript);
  script.addValue("BuhidScript", QLocale::BuhidScript);
  script.addValue("CanadianAboriginalScript", QLocale::CanadianAboriginalScript);
  script.addValue("CarianScript", QLocale::CarianScript);
  script.addValue("ChakmaScript", QLocale::ChakmaScript);
  script.addValue("ChamScript", QLocale::ChamScript);
  script.addValue("CopticScript", QLocale::CopticScript);
  script.addValue("CypriotScript", QLocale::CypriotScript);
  script.addValue("EgyptianHieroglyphsScript", QLocale::EgyptianHieroglyphsScript);
  script.addValue("FraserScript", QLocale::FraserScript);
  script.addValue("GlagoliticScript", QLocale::GlagoliticScript);
  script.addValue("GothicScript", QLocale::GothicScript);
  script.addValue("HanScript", QLocale::HanScript);
  script.addValue("HangulScript", QLocale::HangulScript);
  script.addValue("HanunooScript", QLocale::HanunooScript);
  script.addValue("ImperialAramaicScript", QLocale::ImperialAramaicScript);
  script.addValue("InscriptionalPahlaviScript", QLocale::InscriptionalPahlaviScript);
  script.addValue("InscriptionalParthianScript", QLocale::InscriptionalParthianScript);
  script.addValue("JavaneseScript", QLocale::JavaneseScript);
  script.addValue("KaithiScript", QLocale::KaithiScript);
  script.addValue("KatakanaScript", QLocale::KatakanaScript);
  script.addValue("KayahLiScript", QLocale::KayahLiScript);
  script.addValue("KharoshthiScript", QLocale::KharoshthiScript);
  script.addValue("LannaScript", QLocale::LannaScript);
  script.addValue("LepchaScript", QLocale::LepchaScript);
  script.addValue("LimbuScript", QLocale::LimbuScript);
  script.addValue("LinearBScript", QLocale::LinearBScript);
  script.addValue("LycianScript", QLocale::LycianScript);
  script.addValue("LydianScript", QLocale::LydianScript);
  script.addValue("MandaeanScript", QLocale::MandaeanScript);
  script.addValue("MeiteiMayekScript", QLocale::MeiteiMayekScript);
  script.addValue("MeroiticScript", QLocale::MeroiticScript);
  script.addValue("MeroiticCursiveScript", QLocale::MeroiticCursiveScript);
  script.addValue("NkoScript", QLocale::NkoScript);
  script.addValue("NewTaiLueScript", QLocale::NewTaiLueScript);
  script.addValue("OghamScript", QLocale::OghamScript);
  script.addValue("OlChikiScript", QLocale::OlChikiScript);
  script.addValue("OldItalicScript", QLocale::OldItalicScript);
  script.addValue("OldPersianScript", QLocale::OldPersianScript);
  script.addValue("OldSouthArabianScript", QLocale::OldSouthArabianScript);
  script.addValue("OrkhonScript", QLocale::OrkhonScript);
  script.addValue("OsmanyaScript", QLocale::OsmanyaScript);
  script.addValue("PhagsPaScript", QLocale::PhagsPaScript);
  script.addValue("PhoenicianScript", QLocale::PhoenicianScript);
  script.addValue("PollardPhoneticScript", QLocale::PollardPhoneticScript);
  script.addValue("RejangScript", QLocale::RejangScript);
  script.addValue("RunicScript", QLocale::RunicScript);
  script.addValue("SamaritanScript", QLocale::SamaritanScript);
  script.addValue("SaurashtraScript", QLocale::SaurashtraScript);
  script.addValue("SharadaScript", QLocale::SharadaScript);
  script.addValue("ShavianScript", QLocale::ShavianScript);
  script.addValue("SoraSompengScript", QLocale::SoraSompengScript);
  script.addValue("CuneiformScript", QLocale::CuneiformScript);
  script.addValue("SundaneseScript", QLocale::SundaneseScript);
  script.addValue("SylotiNagriScript", QLocale::SylotiNagriScript);
  script.addValue("TagalogScript", QLocale::TagalogScript);
  script.addValue("TagbanwaScript", QLocale::TagbanwaScript);
  script.addValue("TaiLeScript", QLocale::TaiLeScript);
  script.addValue("TaiVietScript", QLocale::TaiVietScript);
  script.addValue("TakriScript", QLocale::TakriScript);
  script.addValue("UgariticScript", QLocale::UgariticScript);
  script.addValue("BrailleScript", QLocale::BrailleScript);
  script.addValue("HiraganaScript", QLocale::HiraganaScript);
  script.addValue("CaucasianAlbanianScript", QLocale::CaucasianAlbanianScript);
  script.addValue("BassaVahScript", QLocale::BassaVahScript);
  script.addValue("DuployanScript", QLocale::DuployanScript);
  script.addValue("ElbasanScript", QLocale::ElbasanScript);
  script.addValue("GranthaScript", QLocale::GranthaScript);
  script.addValue("PahawhHmongScript", QLocale::PahawhHmongScript);
  script.addValue("KhojkiScript", QLocale::KhojkiScript);
  script.addValue("LinearAScript", QLocale::LinearAScript);
  script.addValue("MahajaniScript", QLocale::MahajaniScript);
  script.addValue("ManichaeanScript", QLocale::ManichaeanScript);
  script.addValue("MendeKikakuiScript", QLocale::MendeKikakuiScript);
  script.addValue("ModiScript", QLocale::ModiScript);
  script.addValue("MroScript", QLocale::MroScript);
  script.addValue("OldNorthArabianScript", QLocale::OldNorthArabianScript);
  script.addValue("NabataeanScript", QLocale::NabataeanScript);
  script.addValue("PalmyreneScript", QLocale::PalmyreneScript);
  script.addValue("PauCinHauScript", QLocale::PauCinHauScript);
  script.addValue("OldPermicScript", QLocale::OldPermicScript);
  script.addValue("PsalterPahlaviScript", QLocale::PsalterPahlaviScript);
  script.addValue("SiddhamScript", QLocale::SiddhamScript);
  script.addValue("KhudawadiScript", QLocale::KhudawadiScript);
  script.addValue("TirhutaScript", QLocale::TirhutaScript);
  script.addValue("VarangKshitiScript", QLocale::VarangKshitiScript);
  script.addValue("AhomScript", QLocale::AhomScript);
  script.addValue("AnatolianHieroglyphsScript", QLocale::AnatolianHieroglyphsScript);
  script.addValue("HatranScript", QLocale::HatranScript);
  script.addValue("MultaniScript", QLocale::MultaniScript);
  script.addValue("OldHungarianScript", QLocale::OldHungarianScript);
  script.addValue("SignWritingScript", QLocale::SignWritingScript);
  script.addValue("AdlamScript", QLocale::AdlamScript);
  script.addValue("BhaiksukiScript", QLocale::BhaiksukiScript);
  script.addValue("MarchenScript", QLocale::MarchenScript);
  script.addValue("NewaScript", QLocale::NewaScript);
  script.addValue("OsageScript", QLocale::OsageScript);
  script.addValue("TangutScript", QLocale::TangutScript);
  script.addValue("HanWithBopomofoScript", QLocale::HanWithBopomofoScript);
  script.addValue("JamoScript", QLocale::JamoScript);
  script.addValue("SimplifiedChineseScript", QLocale::SimplifiedChineseScript);
  script.addValue("TraditionalChineseScript", QLocale::TraditionalChineseScript);
  script.addValue("LastScript", QLocale::LastScript);
}


static void register_locale_country_enum(script::Class locale)
{
  using namespace script;

  Enum country = locale.Enum("Country").setId(script::Type::QLocaleCountry).get();

  country.addValue("AnyCountry", QLocale::AnyCountry);
  country.addValue("Afghanistan", QLocale::Afghanistan);
  country.addValue("Albania", QLocale::Albania);
  country.addValue("Algeria", QLocale::Algeria);
  country.addValue("AmericanSamoa", QLocale::AmericanSamoa);
  country.addValue("Andorra", QLocale::Andorra);
  country.addValue("Angola", QLocale::Angola);
  country.addValue("Anguilla", QLocale::Anguilla);
  country.addValue("Antarctica", QLocale::Antarctica);
  country.addValue("AntiguaAndBarbuda", QLocale::AntiguaAndBarbuda);
  country.addValue("Argentina", QLocale::Argentina);
  country.addValue("Armenia", QLocale::Armenia);
  country.addValue("Aruba", QLocale::Aruba);
  country.addValue("Australia", QLocale::Australia);
  country.addValue("Austria", QLocale::Austria);
  country.addValue("Azerbaijan", QLocale::Azerbaijan);
  country.addValue("Bahamas", QLocale::Bahamas);
  country.addValue("Bahrain", QLocale::Bahrain);
  country.addValue("Bangladesh", QLocale::Bangladesh);
  country.addValue("Barbados", QLocale::Barbados);
  country.addValue("Belarus", QLocale::Belarus);
  country.addValue("Belgium", QLocale::Belgium);
  country.addValue("Belize", QLocale::Belize);
  country.addValue("Benin", QLocale::Benin);
  country.addValue("Bermuda", QLocale::Bermuda);
  country.addValue("Bhutan", QLocale::Bhutan);
  country.addValue("Bolivia", QLocale::Bolivia);
  country.addValue("BosniaAndHerzegowina", QLocale::BosniaAndHerzegowina);
  country.addValue("Botswana", QLocale::Botswana);
  country.addValue("BouvetIsland", QLocale::BouvetIsland);
  country.addValue("Brazil", QLocale::Brazil);
  country.addValue("BritishIndianOceanTerritory", QLocale::BritishIndianOceanTerritory);
  country.addValue("Brunei", QLocale::Brunei);
  country.addValue("Bulgaria", QLocale::Bulgaria);
  country.addValue("BurkinaFaso", QLocale::BurkinaFaso);
  country.addValue("Burundi", QLocale::Burundi);
  country.addValue("Cambodia", QLocale::Cambodia);
  country.addValue("Cameroon", QLocale::Cameroon);
  country.addValue("Canada", QLocale::Canada);
  country.addValue("CapeVerde", QLocale::CapeVerde);
  country.addValue("CaymanIslands", QLocale::CaymanIslands);
  country.addValue("CentralAfricanRepublic", QLocale::CentralAfricanRepublic);
  country.addValue("Chad", QLocale::Chad);
  country.addValue("Chile", QLocale::Chile);
  country.addValue("China", QLocale::China);
  country.addValue("ChristmasIsland", QLocale::ChristmasIsland);
  country.addValue("CocosIslands", QLocale::CocosIslands);
  country.addValue("Colombia", QLocale::Colombia);
  country.addValue("Comoros", QLocale::Comoros);
  country.addValue("CongoKinshasa", QLocale::CongoKinshasa);
  country.addValue("CongoBrazzaville", QLocale::CongoBrazzaville);
  country.addValue("CookIslands", QLocale::CookIslands);
  country.addValue("CostaRica", QLocale::CostaRica);
  country.addValue("IvoryCoast", QLocale::IvoryCoast);
  country.addValue("Croatia", QLocale::Croatia);
  country.addValue("Cuba", QLocale::Cuba);
  country.addValue("Cyprus", QLocale::Cyprus);
  country.addValue("CzechRepublic", QLocale::CzechRepublic);
  country.addValue("Denmark", QLocale::Denmark);
  country.addValue("Djibouti", QLocale::Djibouti);
  country.addValue("Dominica", QLocale::Dominica);
  country.addValue("DominicanRepublic", QLocale::DominicanRepublic);
  country.addValue("EastTimor", QLocale::EastTimor);
  country.addValue("Ecuador", QLocale::Ecuador);
  country.addValue("Egypt", QLocale::Egypt);
  country.addValue("ElSalvador", QLocale::ElSalvador);
  country.addValue("EquatorialGuinea", QLocale::EquatorialGuinea);
  country.addValue("Eritrea", QLocale::Eritrea);
  country.addValue("Estonia", QLocale::Estonia);
  country.addValue("Ethiopia", QLocale::Ethiopia);
  country.addValue("FalklandIslands", QLocale::FalklandIslands);
  country.addValue("FaroeIslands", QLocale::FaroeIslands);
  country.addValue("Fiji", QLocale::Fiji);
  country.addValue("Finland", QLocale::Finland);
  country.addValue("France", QLocale::France);
  country.addValue("Guernsey", QLocale::Guernsey);
  country.addValue("FrenchGuiana", QLocale::FrenchGuiana);
  country.addValue("FrenchPolynesia", QLocale::FrenchPolynesia);
  country.addValue("FrenchSouthernTerritories", QLocale::FrenchSouthernTerritories);
  country.addValue("Gabon", QLocale::Gabon);
  country.addValue("Gambia", QLocale::Gambia);
  country.addValue("Georgia", QLocale::Georgia);
  country.addValue("Germany", QLocale::Germany);
  country.addValue("Ghana", QLocale::Ghana);
  country.addValue("Gibraltar", QLocale::Gibraltar);
  country.addValue("Greece", QLocale::Greece);
  country.addValue("Greenland", QLocale::Greenland);
  country.addValue("Grenada", QLocale::Grenada);
  country.addValue("Guadeloupe", QLocale::Guadeloupe);
  country.addValue("Guam", QLocale::Guam);
  country.addValue("Guatemala", QLocale::Guatemala);
  country.addValue("Guinea", QLocale::Guinea);
  country.addValue("GuineaBissau", QLocale::GuineaBissau);
  country.addValue("Guyana", QLocale::Guyana);
  country.addValue("Haiti", QLocale::Haiti);
  country.addValue("HeardAndMcDonaldIslands", QLocale::HeardAndMcDonaldIslands);
  country.addValue("Honduras", QLocale::Honduras);
  country.addValue("HongKong", QLocale::HongKong);
  country.addValue("Hungary", QLocale::Hungary);
  country.addValue("Iceland", QLocale::Iceland);
  country.addValue("India", QLocale::India);
  country.addValue("Indonesia", QLocale::Indonesia);
  country.addValue("Iran", QLocale::Iran);
  country.addValue("Iraq", QLocale::Iraq);
  country.addValue("Ireland", QLocale::Ireland);
  country.addValue("Israel", QLocale::Israel);
  country.addValue("Italy", QLocale::Italy);
  country.addValue("Jamaica", QLocale::Jamaica);
  country.addValue("Japan", QLocale::Japan);
  country.addValue("Jordan", QLocale::Jordan);
  country.addValue("Kazakhstan", QLocale::Kazakhstan);
  country.addValue("Kenya", QLocale::Kenya);
  country.addValue("Kiribati", QLocale::Kiribati);
  country.addValue("NorthKorea", QLocale::NorthKorea);
  country.addValue("SouthKorea", QLocale::SouthKorea);
  country.addValue("Kuwait", QLocale::Kuwait);
  country.addValue("Kyrgyzstan", QLocale::Kyrgyzstan);
  country.addValue("Laos", QLocale::Laos);
  country.addValue("Latvia", QLocale::Latvia);
  country.addValue("Lebanon", QLocale::Lebanon);
  country.addValue("Lesotho", QLocale::Lesotho);
  country.addValue("Liberia", QLocale::Liberia);
  country.addValue("Libya", QLocale::Libya);
  country.addValue("Liechtenstein", QLocale::Liechtenstein);
  country.addValue("Lithuania", QLocale::Lithuania);
  country.addValue("Luxembourg", QLocale::Luxembourg);
  country.addValue("Macau", QLocale::Macau);
  country.addValue("Macedonia", QLocale::Macedonia);
  country.addValue("Madagascar", QLocale::Madagascar);
  country.addValue("Malawi", QLocale::Malawi);
  country.addValue("Malaysia", QLocale::Malaysia);
  country.addValue("Maldives", QLocale::Maldives);
  country.addValue("Mali", QLocale::Mali);
  country.addValue("Malta", QLocale::Malta);
  country.addValue("MarshallIslands", QLocale::MarshallIslands);
  country.addValue("Martinique", QLocale::Martinique);
  country.addValue("Mauritania", QLocale::Mauritania);
  country.addValue("Mauritius", QLocale::Mauritius);
  country.addValue("Mayotte", QLocale::Mayotte);
  country.addValue("Mexico", QLocale::Mexico);
  country.addValue("Micronesia", QLocale::Micronesia);
  country.addValue("Moldova", QLocale::Moldova);
  country.addValue("Monaco", QLocale::Monaco);
  country.addValue("Mongolia", QLocale::Mongolia);
  country.addValue("Montserrat", QLocale::Montserrat);
  country.addValue("Morocco", QLocale::Morocco);
  country.addValue("Mozambique", QLocale::Mozambique);
  country.addValue("Myanmar", QLocale::Myanmar);
  country.addValue("Namibia", QLocale::Namibia);
  country.addValue("NauruCountry", QLocale::NauruCountry);
  country.addValue("Nepal", QLocale::Nepal);
  country.addValue("Netherlands", QLocale::Netherlands);
  country.addValue("CuraSao", QLocale::CuraSao);
  country.addValue("NewCaledonia", QLocale::NewCaledonia);
  country.addValue("NewZealand", QLocale::NewZealand);
  country.addValue("Nicaragua", QLocale::Nicaragua);
  country.addValue("Niger", QLocale::Niger);
  country.addValue("Nigeria", QLocale::Nigeria);
  country.addValue("Niue", QLocale::Niue);
  country.addValue("NorfolkIsland", QLocale::NorfolkIsland);
  country.addValue("NorthernMarianaIslands", QLocale::NorthernMarianaIslands);
  country.addValue("Norway", QLocale::Norway);
  country.addValue("Oman", QLocale::Oman);
  country.addValue("Pakistan", QLocale::Pakistan);
  country.addValue("Palau", QLocale::Palau);
  country.addValue("PalestinianTerritories", QLocale::PalestinianTerritories);
  country.addValue("Panama", QLocale::Panama);
  country.addValue("PapuaNewGuinea", QLocale::PapuaNewGuinea);
  country.addValue("Paraguay", QLocale::Paraguay);
  country.addValue("Peru", QLocale::Peru);
  country.addValue("Philippines", QLocale::Philippines);
  country.addValue("Pitcairn", QLocale::Pitcairn);
  country.addValue("Poland", QLocale::Poland);
  country.addValue("Portugal", QLocale::Portugal);
  country.addValue("PuertoRico", QLocale::PuertoRico);
  country.addValue("Qatar", QLocale::Qatar);
  country.addValue("Reunion", QLocale::Reunion);
  country.addValue("Romania", QLocale::Romania);
  country.addValue("Russia", QLocale::Russia);
  country.addValue("Rwanda", QLocale::Rwanda);
  country.addValue("SaintKittsAndNevis", QLocale::SaintKittsAndNevis);
  country.addValue("SaintLucia", QLocale::SaintLucia);
  country.addValue("SaintVincentAndTheGrenadines", QLocale::SaintVincentAndTheGrenadines);
  country.addValue("Samoa", QLocale::Samoa);
  country.addValue("SanMarino", QLocale::SanMarino);
  country.addValue("SaoTomeAndPrincipe", QLocale::SaoTomeAndPrincipe);
  country.addValue("SaudiArabia", QLocale::SaudiArabia);
  country.addValue("Senegal", QLocale::Senegal);
  country.addValue("Seychelles", QLocale::Seychelles);
  country.addValue("SierraLeone", QLocale::SierraLeone);
  country.addValue("Singapore", QLocale::Singapore);
  country.addValue("Slovakia", QLocale::Slovakia);
  country.addValue("Slovenia", QLocale::Slovenia);
  country.addValue("SolomonIslands", QLocale::SolomonIslands);
  country.addValue("Somalia", QLocale::Somalia);
  country.addValue("SouthAfrica", QLocale::SouthAfrica);
  country.addValue("SouthGeorgiaAndTheSouthSandwichIslands", QLocale::SouthGeorgiaAndTheSouthSandwichIslands);
  country.addValue("Spain", QLocale::Spain);
  country.addValue("SriLanka", QLocale::SriLanka);
  country.addValue("SaintHelena", QLocale::SaintHelena);
  country.addValue("SaintPierreAndMiquelon", QLocale::SaintPierreAndMiquelon);
  country.addValue("Sudan", QLocale::Sudan);
  country.addValue("Suriname", QLocale::Suriname);
  country.addValue("SvalbardAndJanMayenIslands", QLocale::SvalbardAndJanMayenIslands);
  country.addValue("Swaziland", QLocale::Swaziland);
  country.addValue("Sweden", QLocale::Sweden);
  country.addValue("Switzerland", QLocale::Switzerland);
  country.addValue("Syria", QLocale::Syria);
  country.addValue("Taiwan", QLocale::Taiwan);
  country.addValue("Tajikistan", QLocale::Tajikistan);
  country.addValue("Tanzania", QLocale::Tanzania);
  country.addValue("Thailand", QLocale::Thailand);
  country.addValue("Togo", QLocale::Togo);
  country.addValue("TokelauCountry", QLocale::TokelauCountry);
  country.addValue("Tonga", QLocale::Tonga);
  country.addValue("TrinidadAndTobago", QLocale::TrinidadAndTobago);
  country.addValue("Tunisia", QLocale::Tunisia);
  country.addValue("Turkey", QLocale::Turkey);
  country.addValue("Turkmenistan", QLocale::Turkmenistan);
  country.addValue("TurksAndCaicosIslands", QLocale::TurksAndCaicosIslands);
  country.addValue("TuvaluCountry", QLocale::TuvaluCountry);
  country.addValue("Uganda", QLocale::Uganda);
  country.addValue("Ukraine", QLocale::Ukraine);
  country.addValue("UnitedArabEmirates", QLocale::UnitedArabEmirates);
  country.addValue("UnitedKingdom", QLocale::UnitedKingdom);
  country.addValue("UnitedStates", QLocale::UnitedStates);
  country.addValue("UnitedStatesMinorOutlyingIslands", QLocale::UnitedStatesMinorOutlyingIslands);
  country.addValue("Uruguay", QLocale::Uruguay);
  country.addValue("Uzbekistan", QLocale::Uzbekistan);
  country.addValue("Vanuatu", QLocale::Vanuatu);
  country.addValue("VaticanCityState", QLocale::VaticanCityState);
  country.addValue("Venezuela", QLocale::Venezuela);
  country.addValue("Vietnam", QLocale::Vietnam);
  country.addValue("BritishVirginIslands", QLocale::BritishVirginIslands);
  country.addValue("UnitedStatesVirginIslands", QLocale::UnitedStatesVirginIslands);
  country.addValue("WallisAndFutunaIslands", QLocale::WallisAndFutunaIslands);
  country.addValue("WesternSahara", QLocale::WesternSahara);
  country.addValue("Yemen", QLocale::Yemen);
  country.addValue("CanaryIslands", QLocale::CanaryIslands);
  country.addValue("Zambia", QLocale::Zambia);
  country.addValue("Zimbabwe", QLocale::Zimbabwe);
  country.addValue("ClippertonIsland", QLocale::ClippertonIsland);
  country.addValue("Montenegro", QLocale::Montenegro);
  country.addValue("Serbia", QLocale::Serbia);
  country.addValue("SaintBarthelemy", QLocale::SaintBarthelemy);
  country.addValue("SaintMartin", QLocale::SaintMartin);
  country.addValue("LatinAmericaAndTheCaribbean", QLocale::LatinAmericaAndTheCaribbean);
  country.addValue("AscensionIsland", QLocale::AscensionIsland);
  country.addValue("AlandIslands", QLocale::AlandIslands);
  country.addValue("DiegoGarcia", QLocale::DiegoGarcia);
  country.addValue("CeutaAndMelilla", QLocale::CeutaAndMelilla);
  country.addValue("IsleOfMan", QLocale::IsleOfMan);
  country.addValue("Jersey", QLocale::Jersey);
  country.addValue("TristanDaCunha", QLocale::TristanDaCunha);
  country.addValue("SouthSudan", QLocale::SouthSudan);
  country.addValue("Bonaire", QLocale::Bonaire);
  country.addValue("SintMaarten", QLocale::SintMaarten);
  country.addValue("Kosovo", QLocale::Kosovo);
  country.addValue("EuropeanUnion", QLocale::EuropeanUnion);
  country.addValue("OutlyingOceania", QLocale::OutlyingOceania);
  country.addValue("Tokelau", QLocale::Tokelau);
  country.addValue("Tuvalu", QLocale::Tuvalu);
  country.addValue("DemocraticRepublicOfCongo", QLocale::DemocraticRepublicOfCongo);
  country.addValue("PeoplesRepublicOfCongo", QLocale::PeoplesRepublicOfCongo);
  country.addValue("DemocraticRepublicOfKorea", QLocale::DemocraticRepublicOfKorea);
  country.addValue("RepublicOfKorea", QLocale::RepublicOfKorea);
  country.addValue("RussianFederation", QLocale::RussianFederation);
  country.addValue("SyrianArabRepublic", QLocale::SyrianArabRepublic);
  country.addValue("LastCountry", QLocale::LastCountry);
}


static void register_locale_measurement_system_enum(script::Class locale)
{
  using namespace script;

  Enum measurement_system = locale.Enum("MeasurementSystem").setId(script::Type::QLocaleMeasurementSystem).get();

  measurement_system.addValue("MetricSystem", QLocale::MetricSystem);
  measurement_system.addValue("ImperialUSSystem", QLocale::ImperialUSSystem);
  measurement_system.addValue("ImperialUKSystem", QLocale::ImperialUKSystem);
  measurement_system.addValue("ImperialSystem", QLocale::ImperialSystem);
}


static void register_locale_format_type_enum(script::Class locale)
{
  using namespace script;

  Enum format_type = locale.Enum("FormatType").setId(script::Type::QLocaleFormatType).get();

  format_type.addValue("LongFormat", QLocale::LongFormat);
  format_type.addValue("ShortFormat", QLocale::ShortFormat);
  format_type.addValue("NarrowFormat", QLocale::NarrowFormat);
}


static void register_locale_number_option_enum(script::Class locale)
{
  using namespace script;

  Enum number_option = locale.Enum("NumberOption").setId(script::Type::QLocaleNumberOption).get();

  register_qflags_type<QLocale::NumberOption>(locale, "NumberOptions", script::Type::QLocaleNumberOptions);
  number_option.addValue("DefaultNumberOptions", QLocale::DefaultNumberOptions);
  number_option.addValue("OmitGroupSeparator", QLocale::OmitGroupSeparator);
  number_option.addValue("RejectGroupSeparator", QLocale::RejectGroupSeparator);
  number_option.addValue("OmitLeadingZeroInExponent", QLocale::OmitLeadingZeroInExponent);
  number_option.addValue("RejectLeadingZeroInExponent", QLocale::RejectLeadingZeroInExponent);
  number_option.addValue("IncludeTrailingZeroesAfterDot", QLocale::IncludeTrailingZeroesAfterDot);
  number_option.addValue("RejectTrailingZeroesAfterDot", QLocale::RejectTrailingZeroesAfterDot);
}


static void register_locale_floating_point_precision_option_enum(script::Class locale)
{
  using namespace script;

  Enum floating_point_precision_option = locale.Enum("FloatingPointPrecisionOption").setId(script::Type::QLocaleFloatingPointPrecisionOption).get();

  floating_point_precision_option.addValue("FloatingPointShortest", QLocale::FloatingPointShortest);
}


static void register_locale_currency_symbol_format_enum(script::Class locale)
{
  using namespace script;

  Enum currency_symbol_format = locale.Enum("CurrencySymbolFormat").setId(script::Type::QLocaleCurrencySymbolFormat).get();

  currency_symbol_format.addValue("CurrencyIsoCode", QLocale::CurrencyIsoCode);
  currency_symbol_format.addValue("CurrencySymbol", QLocale::CurrencySymbol);
  currency_symbol_format.addValue("CurrencyDisplayName", QLocale::CurrencyDisplayName);
}


static void register_locale_data_size_format_enum(script::Class locale)
{
  using namespace script;

  Enum data_size_format = locale.Enum("DataSizeFormat").setId(script::Type::QLocaleDataSizeFormat).get();

  register_qflags_type<QLocale::DataSizeFormat>(locale, "DataSizeFormats", script::Type::QLocaleDataSizeFormats);
  data_size_format.addValue("DataSizeBase1000", QLocale::DataSizeBase1000);
  data_size_format.addValue("DataSizeSIQuantifiers", QLocale::DataSizeSIQuantifiers);
  data_size_format.addValue("DataSizeIecFormat", QLocale::DataSizeIecFormat);
  data_size_format.addValue("DataSizeTraditionalFormat", QLocale::DataSizeTraditionalFormat);
  data_size_format.addValue("DataSizeSIFormat", QLocale::DataSizeSIFormat);
}


static void register_locale_quotation_style_enum(script::Class locale)
{
  using namespace script;

  Enum quotation_style = locale.Enum("QuotationStyle").setId(script::Type::QLocaleQuotationStyle).get();

  quotation_style.addValue("StandardQuotation", QLocale::StandardQuotation);
  quotation_style.addValue("AlternateQuotation", QLocale::AlternateQuotation);
}


static void register_locale_class(script::Namespace ns)
{
  using namespace script;

  Class locale = ns.Class("Locale").setId(script::Type::QLocale).get();

  register_ptr_specialization<QLocale>(locale.engine()->getTemplate(Engine::PtrTemplate), script::Type::PtrQLocale);
  register_list_specialization<QLocale>(locale.engine(), script::Type::QListQLocale);
  register_locale_language_enum(locale);
  register_locale_script_enum(locale);
  register_locale_country_enum(locale);
  register_locale_measurement_system_enum(locale);
  register_locale_format_type_enum(locale);
  register_locale_number_option_enum(locale);
  register_locale_floating_point_precision_option_enum(locale);
  register_locale_currency_symbol_format_enum(locale);
  register_locale_data_size_format_enum(locale);
  register_locale_quotation_style_enum(locale);
  binding::Class<QLocale> binder{ locale };

  // QLocale();
  binder.ctors().default_ctor().create();
  // QLocale(const QString &);
  binder.ctors().ctor<const QString &>().create();
  // QLocale(QLocale::Language, QLocale::Country);
  binder.ctors().ctor<QLocale::Language, QLocale::Country>()
    .apply(binding::default_arguments(QLocale::AnyCountry)).create();
  // QLocale(QLocale::Language, QLocale::Script, QLocale::Country);
  binder.ctors().ctor<QLocale::Language, QLocale::Script, QLocale::Country>().create();
  // QLocale(const QLocale &);
  binder.ctors().ctor<const QLocale &>().create();
  // QLocale & operator=(QLocale &&);
  binder.operators().assign<QLocale &&>();
  // QLocale & operator=(const QLocale &);
  binder.operators().assign<const QLocale &>();
  // ~QLocale();
  binder.add_dtor();
  // void swap(QLocale &);
  binder.void_fun<QLocale &, &QLocale::swap>("swap").create();
  // QLocale::Language language() const;
  binder.fun<QLocale::Language, &QLocale::language>("language").create();
  // QLocale::Script script() const;
  binder.fun<QLocale::Script, &QLocale::script>("script").create();
  // QLocale::Country country() const;
  binder.fun<QLocale::Country, &QLocale::country>("country").create();
  // QString name() const;
  binder.fun<QString, &QLocale::name>("name").create();
  // QString bcp47Name() const;
  binder.fun<QString, &QLocale::bcp47Name>("bcp47Name").create();
  // QString nativeLanguageName() const;
  binder.fun<QString, &QLocale::nativeLanguageName>("nativeLanguageName").create();
  // QString nativeCountryName() const;
  binder.fun<QString, &QLocale::nativeCountryName>("nativeCountryName").create();
  // short toShort(const QString &, bool *) const;
  /// TODO: short toShort(const QString &, bool *) const;
  // ushort toUShort(const QString &, bool *) const;
  /// TODO: ushort toUShort(const QString &, bool *) const;
  // int toInt(const QString &, bool *) const;
  /// TODO: int toInt(const QString &, bool *) const;
  // uint toUInt(const QString &, bool *) const;
  /// TODO: uint toUInt(const QString &, bool *) const;
  // qlonglong toLongLong(const QString &, bool *) const;
  /// TODO: qlonglong toLongLong(const QString &, bool *) const;
  // qulonglong toULongLong(const QString &, bool *) const;
  /// TODO: qulonglong toULongLong(const QString &, bool *) const;
  // float toFloat(const QString &, bool *) const;
  /// TODO: float toFloat(const QString &, bool *) const;
  // double toDouble(const QString &, bool *) const;
  /// TODO: double toDouble(const QString &, bool *) const;
  // short toShort(const QStringRef &, bool *) const;
  /// TODO: short toShort(const QStringRef &, bool *) const;
  // ushort toUShort(const QStringRef &, bool *) const;
  /// TODO: ushort toUShort(const QStringRef &, bool *) const;
  // int toInt(const QStringRef &, bool *) const;
  /// TODO: int toInt(const QStringRef &, bool *) const;
  // uint toUInt(const QStringRef &, bool *) const;
  /// TODO: uint toUInt(const QStringRef &, bool *) const;
  // qlonglong toLongLong(const QStringRef &, bool *) const;
  /// TODO: qlonglong toLongLong(const QStringRef &, bool *) const;
  // qulonglong toULongLong(const QStringRef &, bool *) const;
  /// TODO: qulonglong toULongLong(const QStringRef &, bool *) const;
  // float toFloat(const QStringRef &, bool *) const;
  /// TODO: float toFloat(const QStringRef &, bool *) const;
  // double toDouble(const QStringRef &, bool *) const;
  /// TODO: double toDouble(const QStringRef &, bool *) const;
  // short toShort(QStringView, bool *) const;
  /// TODO: short toShort(QStringView, bool *) const;
  // ushort toUShort(QStringView, bool *) const;
  /// TODO: ushort toUShort(QStringView, bool *) const;
  // int toInt(QStringView, bool *) const;
  /// TODO: int toInt(QStringView, bool *) const;
  // uint toUInt(QStringView, bool *) const;
  /// TODO: uint toUInt(QStringView, bool *) const;
  // qlonglong toLongLong(QStringView, bool *) const;
  /// TODO: qlonglong toLongLong(QStringView, bool *) const;
  // qulonglong toULongLong(QStringView, bool *) const;
  /// TODO: qulonglong toULongLong(QStringView, bool *) const;
  // float toFloat(QStringView, bool *) const;
  /// TODO: float toFloat(QStringView, bool *) const;
  // double toDouble(QStringView, bool *) const;
  /// TODO: double toDouble(QStringView, bool *) const;
  // QString toString(qlonglong) const;
  /// TODO: QString toString(qlonglong) const;
  // QString toString(qulonglong) const;
  /// TODO: QString toString(qulonglong) const;
  // QString toString(short) const;
  /// TODO: QString toString(short) const;
  // QString toString(ushort) const;
  /// TODO: QString toString(ushort) const;
  // QString toString(int) const;
  binder.fun<QString, int, &QLocale::toString>("toString").create();
  // QString toString(uint) const;
  binder.fun<QString, uint, &QLocale::toString>("toString").create();
  // QString toString(double, char, int) const;
  binder.fun<QString, double, char, int, &QLocale::toString>("toString")
    .apply(binding::default_arguments(6, 'g')).create();
  // QString toString(float, char, int) const;
  binder.fun<QString, float, char, int, &QLocale::toString>("toString")
    .apply(binding::default_arguments(6, 'g')).create();
  // QString toString(const QDate &, const QString &) const;
  binder.fun<QString, const QDate &, const QString &, &QLocale::toString>("toString").create();
  // QString toString(const QTime &, const QString &) const;
  binder.fun<QString, const QTime &, const QString &, &QLocale::toString>("toString").create();
  // QString toString(const QDateTime &, const QString &) const;
  binder.fun<QString, const QDateTime &, const QString &, &QLocale::toString>("toString").create();
  // QString toString(const QDate &, QStringView) const;
  /// TODO: QString toString(const QDate &, QStringView) const;
  // QString toString(const QTime &, QStringView) const;
  /// TODO: QString toString(const QTime &, QStringView) const;
  // QString toString(const QDateTime &, QStringView) const;
  /// TODO: QString toString(const QDateTime &, QStringView) const;
  // QString toString(const QDate &, QLocale::FormatType) const;
  binder.fun<QString, const QDate &, QLocale::FormatType, &QLocale::toString>("toString").create();
  // QString toString(const QTime &, QLocale::FormatType) const;
  binder.fun<QString, const QTime &, QLocale::FormatType, &QLocale::toString>("toString").create();
  // QString toString(const QDateTime &, QLocale::FormatType) const;
  binder.fun<QString, const QDateTime &, QLocale::FormatType, &QLocale::toString>("toString").create();
  // QString dateFormat(QLocale::FormatType) const;
  binder.fun<QString, QLocale::FormatType, &QLocale::dateFormat>("dateFormat")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QString timeFormat(QLocale::FormatType) const;
  binder.fun<QString, QLocale::FormatType, &QLocale::timeFormat>("timeFormat")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QString dateTimeFormat(QLocale::FormatType) const;
  binder.fun<QString, QLocale::FormatType, &QLocale::dateTimeFormat>("dateTimeFormat")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QDate toDate(const QString &, QLocale::FormatType) const;
  binder.fun<QDate, const QString &, QLocale::FormatType, &QLocale::toDate>("toDate")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QTime toTime(const QString &, QLocale::FormatType) const;
  binder.fun<QTime, const QString &, QLocale::FormatType, &QLocale::toTime>("toTime")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QDateTime toDateTime(const QString &, QLocale::FormatType) const;
  binder.fun<QDateTime, const QString &, QLocale::FormatType, &QLocale::toDateTime>("toDateTime")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QDate toDate(const QString &, const QString &) const;
  binder.fun<QDate, const QString &, const QString &, &QLocale::toDate>("toDate").create();
  // QTime toTime(const QString &, const QString &) const;
  binder.fun<QTime, const QString &, const QString &, &QLocale::toTime>("toTime").create();
  // QDateTime toDateTime(const QString &, const QString &) const;
  binder.fun<QDateTime, const QString &, const QString &, &QLocale::toDateTime>("toDateTime").create();
  // QChar decimalPoint() const;
  binder.fun<QChar, &QLocale::decimalPoint>("decimalPoint").create();
  // QChar groupSeparator() const;
  binder.fun<QChar, &QLocale::groupSeparator>("groupSeparator").create();
  // QChar percent() const;
  binder.fun<QChar, &QLocale::percent>("percent").create();
  // QChar zeroDigit() const;
  binder.fun<QChar, &QLocale::zeroDigit>("zeroDigit").create();
  // QChar negativeSign() const;
  binder.fun<QChar, &QLocale::negativeSign>("negativeSign").create();
  // QChar positiveSign() const;
  binder.fun<QChar, &QLocale::positiveSign>("positiveSign").create();
  // QChar exponential() const;
  binder.fun<QChar, &QLocale::exponential>("exponential").create();
  // QString monthName(int, QLocale::FormatType) const;
  binder.fun<QString, int, QLocale::FormatType, &QLocale::monthName>("monthName")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QString standaloneMonthName(int, QLocale::FormatType) const;
  binder.fun<QString, int, QLocale::FormatType, &QLocale::standaloneMonthName>("standaloneMonthName")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QString dayName(int, QLocale::FormatType) const;
  binder.fun<QString, int, QLocale::FormatType, &QLocale::dayName>("dayName")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // QString standaloneDayName(int, QLocale::FormatType) const;
  binder.fun<QString, int, QLocale::FormatType, &QLocale::standaloneDayName>("standaloneDayName")
    .apply(binding::default_arguments(QLocale::LongFormat)).create();
  // Qt::DayOfWeek firstDayOfWeek() const;
  binder.fun<Qt::DayOfWeek, &QLocale::firstDayOfWeek>("firstDayOfWeek").create();
  // QList<Qt::DayOfWeek> weekdays() const;
  /// TODO: QList<Qt::DayOfWeek> weekdays() const;
  // QString amText() const;
  binder.fun<QString, &QLocale::amText>("amText").create();
  // QString pmText() const;
  binder.fun<QString, &QLocale::pmText>("pmText").create();
  // QLocale::MeasurementSystem measurementSystem() const;
  binder.fun<QLocale::MeasurementSystem, &QLocale::measurementSystem>("measurementSystem").create();
  // Qt::LayoutDirection textDirection() const;
  binder.fun<Qt::LayoutDirection, &QLocale::textDirection>("textDirection").create();
  // QString toUpper(const QString &) const;
  binder.fun<QString, const QString &, &QLocale::toUpper>("toUpper").create();
  // QString toLower(const QString &) const;
  binder.fun<QString, const QString &, &QLocale::toLower>("toLower").create();
  // QString currencySymbol(QLocale::CurrencySymbolFormat) const;
  binder.fun<QString, QLocale::CurrencySymbolFormat, &QLocale::currencySymbol>("currencySymbol").create();
  // QString toCurrencyString(qlonglong, const QString &) const;
  /// TODO: QString toCurrencyString(qlonglong, const QString &) const;
  // QString toCurrencyString(qulonglong, const QString &) const;
  /// TODO: QString toCurrencyString(qulonglong, const QString &) const;
  // QString toCurrencyString(short, const QString &) const;
  /// TODO: QString toCurrencyString(short, const QString &) const;
  // QString toCurrencyString(ushort, const QString &) const;
  /// TODO: QString toCurrencyString(ushort, const QString &) const;
  // QString toCurrencyString(int, const QString &) const;
  binder.fun<QString, int, const QString &, &QLocale::toCurrencyString>("toCurrencyString")
    .apply(binding::default_arguments(QString())).create();
  // QString toCurrencyString(uint, const QString &) const;
  binder.fun<QString, uint, const QString &, &QLocale::toCurrencyString>("toCurrencyString").create();
  // QString toCurrencyString(double, const QString &) const;
  binder.fun<QString, double, const QString &, &QLocale::toCurrencyString>("toCurrencyString")
    .apply(binding::default_arguments(QString())).create();
  // QString toCurrencyString(double, const QString &, int) const;
  binder.fun<QString, double, const QString &, int, &QLocale::toCurrencyString>("toCurrencyString").create();
  // QString toCurrencyString(float, const QString &) const;
  binder.fun<QString, float, const QString &, &QLocale::toCurrencyString>("toCurrencyString")
    .apply(binding::default_arguments(QString())).create();
  // QString toCurrencyString(float, const QString &, int) const;
  binder.fun<QString, float, const QString &, int, &QLocale::toCurrencyString>("toCurrencyString").create();
  // QString formattedDataSize(qint64, int, QLocale::DataSizeFormats);
  /// TODO: QString formattedDataSize(qint64, int, QLocale::DataSizeFormats);
  // QStringList uiLanguages() const;
  /// TODO: QStringList uiLanguages() const;
  // bool operator==(const QLocale &) const;
  binder.operators().eq<const QLocale &>();
  // bool operator!=(const QLocale &) const;
  binder.operators().neq<const QLocale &>();
  // static QString languageToString(QLocale::Language);
  binder.static_fun<QString, QLocale::Language, &QLocale::languageToString>("languageToString").create();
  // static QString countryToString(QLocale::Country);
  binder.static_fun<QString, QLocale::Country, &QLocale::countryToString>("countryToString").create();
  // static QString scriptToString(QLocale::Script);
  binder.static_fun<QString, QLocale::Script, &QLocale::scriptToString>("scriptToString").create();
  // static void setDefault(const QLocale &);
  binder.static_void_fun<const QLocale &, &QLocale::setDefault>("setDefault").create();
  // static QLocale c();
  binder.static_fun<QLocale, &QLocale::c>("c").create();
  // static QLocale system();
  binder.static_fun<QLocale, &QLocale::system>("system").create();
  // static QList<QLocale> matchingLocales(QLocale::Language, QLocale::Script, QLocale::Country);
  binder.static_fun<QList<QLocale>, QLocale::Language, QLocale::Script, QLocale::Country, &QLocale::matchingLocales>("matchingLocales").create();
  // static QList<QLocale::Country> countriesForLanguage(QLocale::Language);
  /// TODO: static QList<QLocale::Country> countriesForLanguage(QLocale::Language);
  // void setNumberOptions(QLocale::NumberOptions);
  binder.void_fun<QLocale::NumberOptions, &QLocale::setNumberOptions>("setNumberOptions").create();
  // QLocale::NumberOptions numberOptions() const;
  binder.fun<QLocale::NumberOptions, &QLocale::numberOptions>("numberOptions").create();
  // QString quoteString(const QString &, QLocale::QuotationStyle) const;
  binder.fun<QString, const QString &, QLocale::QuotationStyle, &QLocale::quoteString>("quoteString")
    .apply(binding::default_arguments(QLocale::StandardQuotation)).create();
  // QString quoteString(const QStringRef &, QLocale::QuotationStyle) const;
  /// TODO: QString quoteString(const QStringRef &, QLocale::QuotationStyle) const;
  // QString createSeparatedList(const QStringList &) const;
  /// TODO: QString createSeparatedList(const QStringList &) const;
}


void register_locale_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_locale_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QLocale &, uint);
  binder.fun<uint, const QLocale &, uint, &qHash>("qHash").create();
  // void swap(QLocale &, QLocale &);
  binder.void_fun<QLocale &, QLocale &, &swap>("swap").create();
  // QLocale::NumberOptions operator|(QLocale::NumberOption, QLocale::NumberOption);
  binder.operators().or<QLocale::NumberOptions, QLocale::NumberOption, QLocale::NumberOption>();
  // QLocale::NumberOptions operator|(QLocale::NumberOption, QLocale::NumberOptions);
  binder.operators().or<QLocale::NumberOptions, QLocale::NumberOption, QLocale::NumberOptions>();
  // QIncompatibleFlag operator|(QLocale::NumberOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QLocale::NumberOptions::enum_type, int);
  // QDataStream & operator<<(QDataStream &, const QLocale &);
  binder.operators().put_to<QDataStream &, const QLocale &>();
  // QDataStream & operator>>(QDataStream &, QLocale &);
  binder.operators().read_from<QDataStream &, QLocale &>();
  // QDebug operator<<(QDebug, const QLocale &);
  /// TODO: QDebug operator<<(QDebug, const QLocale &);
}

