// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/locale.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/date.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/flags.h"
#include "yasl/core/list.h"
#include "yasl/core/string.h"
#include "yasl/core/time.h"

#include <script/classtemplate.h>
#include <script/engine.h>

static int locale_type_id = 0;
static int ptr_locale_type_id = 0;
static int list_locale_type_id = 0;
static int country_type_id = 0;
static int currency_symbol_format_type_id = 0;
static int data_size_format_type_id = 0;
static int data_size_formats_type_id = 0;
static int floating_point_precision_option_type_id = 0;
static int format_type_type_id = 0;
static int language_type_id = 0;
static int measurement_system_type_id = 0;
static int number_option_type_id = 0;
static int number_options_type_id = 0;
static int quotation_style_type_id = 0;
static int script_type_id = 0;

script::Type get_country_type()
{
  return country_type_id;
}

static void register_country_enum(script::Class locale)
{
  using namespace script;

  Enum country = locale.newEnum("Country");
  country_type_id = country.id();

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
  country.addValue("CanaryIslands", QLocale::CanaryIslands);
  country.addValue("CapeVerde", QLocale::CapeVerde);
  country.addValue("CaymanIslands", QLocale::CaymanIslands);
  country.addValue("CentralAfricanRepublic", QLocale::CentralAfricanRepublic);
  country.addValue("Chad", QLocale::Chad);
  country.addValue("Chile", QLocale::Chile);
  country.addValue("China", QLocale::China);
  country.addValue("ChristmasIsland", QLocale::ChristmasIsland);
  country.addValue("ClippertonIsland", QLocale::ClippertonIsland);
  country.addValue("CocosIslands", QLocale::CocosIslands);
  country.addValue("Colombia", QLocale::Colombia);
  country.addValue("Comoros", QLocale::Comoros);
  country.addValue("CongoKinshasa", QLocale::CongoKinshasa);
  country.addValue("CongoBrazzaville", QLocale::CongoBrazzaville);
  country.addValue("DemocraticRepublicOfCongo", QLocale::DemocraticRepublicOfCongo);
  country.addValue("PeoplesRepublicOfCongo", QLocale::PeoplesRepublicOfCongo);
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
  country.addValue("EuropeanUnion", QLocale::EuropeanUnion);
  country.addValue("FalklandIslands", QLocale::FalklandIslands);
  country.addValue("FaroeIslands", QLocale::FaroeIslands);
  country.addValue("Fiji", QLocale::Fiji);
  country.addValue("Finland", QLocale::Finland);
  country.addValue("France", QLocale::France);
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
  country.addValue("Guernsey", QLocale::Guernsey);
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
  country.addValue("DemocraticRepublicOfKorea", QLocale::DemocraticRepublicOfKorea);
  country.addValue("RepublicOfKorea", QLocale::RepublicOfKorea);
  country.addValue("Kosovo", QLocale::Kosovo);
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
  country.addValue("OutlyingOceania", QLocale::OutlyingOceania);
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
  country.addValue("RussianFederation", QLocale::RussianFederation);
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
  country.addValue("SyrianArabRepublic", QLocale::SyrianArabRepublic);
  country.addValue("Taiwan", QLocale::Taiwan);
  country.addValue("Tajikistan", QLocale::Tajikistan);
  country.addValue("Tanzania", QLocale::Tanzania);
  country.addValue("Thailand", QLocale::Thailand);
  country.addValue("Togo", QLocale::Togo);
  country.addValue("TokelauCountry", QLocale::TokelauCountry);
  country.addValue("Tokelau", QLocale::Tokelau);
  country.addValue("Tonga", QLocale::Tonga);
  country.addValue("TrinidadAndTobago", QLocale::TrinidadAndTobago);
  country.addValue("Tunisia", QLocale::Tunisia);
  country.addValue("Turkey", QLocale::Turkey);
  country.addValue("Turkmenistan", QLocale::Turkmenistan);
  country.addValue("TurksAndCaicosIslands", QLocale::TurksAndCaicosIslands);
  country.addValue("TuvaluCountry", QLocale::TuvaluCountry);
  country.addValue("Tuvalu", QLocale::Tuvalu);
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
  country.addValue("Zambia", QLocale::Zambia);
  country.addValue("Zimbabwe", QLocale::Zimbabwe);
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
  country.addValue("CuraSao", QLocale::CuraSao);
  country.addValue("Bonaire", QLocale::Bonaire);
  country.addValue("SintMaarten", QLocale::SintMaarten);
}

script::Type get_currency_symbol_format_type()
{
  return currency_symbol_format_type_id;
}

static void register_currency_symbol_format_enum(script::Class locale)
{
  using namespace script;

  Enum currency_symbol_format = locale.newEnum("CurrencySymbolFormat");
  currency_symbol_format_type_id = currency_symbol_format.id();

  currency_symbol_format.addValue("CurrencyIsoCode", QLocale::CurrencyIsoCode);
  currency_symbol_format.addValue("CurrencySymbol", QLocale::CurrencySymbol);
  currency_symbol_format.addValue("CurrencyDisplayName", QLocale::CurrencyDisplayName);
}

script::Type get_data_size_format_type()
{
  return data_size_format_type_id;
}

script::Type get_data_size_formats_type()
{
  return data_size_formats_type_id;
}


static void register_data_size_format_enum(script::Class locale)
{
  using namespace script;

  Enum data_size_format = locale.newEnum("DataSizeFormat");
  data_size_format_type_id = data_size_format.id();

  data_size_format.addValue("DataSizeIecFormat", QLocale::DataSizeIecFormat);
  data_size_format.addValue("DataSizeTraditionalFormat", QLocale::DataSizeTraditionalFormat);
  data_size_format.addValue("DataSizeSIFormat", QLocale::DataSizeSIFormat);

  Class data_size_formats = register_qflags_type<QLocale::DataSizeFormat>(locale, "DataSizeFormats");
  data_size_formats_type_id = data_size_formats.id();
}


script::Type get_floating_point_precision_option_type()
{
  return floating_point_precision_option_type_id;
}

static void register_floating_point_precision_option_enum(script::Class locale)
{
  using namespace script;

  Enum floating_point_precision_option = locale.newEnum("FloatingPointPrecisionOption");
  floating_point_precision_option_type_id = floating_point_precision_option.id();

  floating_point_precision_option.addValue("FloatingPointShortest", QLocale::FloatingPointShortest);
}

script::Type get_format_type_type()
{
  return format_type_type_id;
}

static void register_format_type_enum(script::Class locale)
{
  using namespace script;

  Enum format_type = locale.newEnum("FormatType");
  format_type_type_id = format_type.id();

  format_type.addValue("LongFormat", QLocale::LongFormat);
  format_type.addValue("ShortFormat", QLocale::ShortFormat);
  format_type.addValue("NarrowFormat", QLocale::NarrowFormat);
}

script::Type get_language_type()
{
  return language_type_id;
}

static void register_language_enum(script::Class locale)
{
  using namespace script;

  Enum language = locale.newEnum("Language");
  language_type_id = language.id();

  language.addValue("AnyLanguage", QLocale::AnyLanguage);
  language.addValue("C", QLocale::C);
  language.addValue("Abkhazian", QLocale::Abkhazian);
  language.addValue("Oromo", QLocale::Oromo);
  language.addValue("Afan", QLocale::Afan);
  language.addValue("Afar", QLocale::Afar);
  language.addValue("Afrikaans", QLocale::Afrikaans);
  language.addValue("Akoose", QLocale::Akoose);
  language.addValue("Albanian", QLocale::Albanian);
  language.addValue("Amharic", QLocale::Amharic);
  language.addValue("Arabic", QLocale::Arabic);
  language.addValue("Armenian", QLocale::Armenian);
  language.addValue("Assamese", QLocale::Assamese);
  language.addValue("Avaric", QLocale::Avaric);
  language.addValue("Aymara", QLocale::Aymara);
  language.addValue("Azerbaijani", QLocale::Azerbaijani);
  language.addValue("Bashkir", QLocale::Bashkir);
  language.addValue("Basque", QLocale::Basque);
  language.addValue("Bengali", QLocale::Bengali);
  language.addValue("Dzongkha", QLocale::Dzongkha);
  language.addValue("Bhutani", QLocale::Bhutani);
  language.addValue("Bihari", QLocale::Bihari);
  language.addValue("Bislama", QLocale::Bislama);
  language.addValue("Bosnian", QLocale::Bosnian);
  language.addValue("Bodo", QLocale::Bodo);
  language.addValue("Breton", QLocale::Breton);
  language.addValue("Bulgarian", QLocale::Bulgarian);
  language.addValue("Burmese", QLocale::Burmese);
  language.addValue("Belarusian", QLocale::Belarusian);
  language.addValue("Byelorussian", QLocale::Byelorussian);
  language.addValue("Khmer", QLocale::Khmer);
  language.addValue("Cambodian", QLocale::Cambodian);
  language.addValue("Catalan", QLocale::Catalan);
  language.addValue("Chamorro", QLocale::Chamorro);
  language.addValue("Chechen", QLocale::Chechen);
  language.addValue("Chinese", QLocale::Chinese);
  language.addValue("Church", QLocale::Church);
  language.addValue("Chuvash", QLocale::Chuvash);
  language.addValue("Cornish", QLocale::Cornish);
  language.addValue("Corsican", QLocale::Corsican);
  language.addValue("Cree", QLocale::Cree);
  language.addValue("Croatian", QLocale::Croatian);
  language.addValue("Czech", QLocale::Czech);
  language.addValue("Danish", QLocale::Danish);
  language.addValue("Divehi", QLocale::Divehi);
  language.addValue("Dutch", QLocale::Dutch);
  language.addValue("English", QLocale::English);
  language.addValue("Esperanto", QLocale::Esperanto);
  language.addValue("Estonian", QLocale::Estonian);
  language.addValue("Faroese", QLocale::Faroese);
  language.addValue("Fijian", QLocale::Fijian);
  language.addValue("Finnish", QLocale::Finnish);
  language.addValue("French", QLocale::French);
  language.addValue("WesternFrisian", QLocale::WesternFrisian);
  language.addValue("Frisian", QLocale::Frisian);
  language.addValue("Gaelic", QLocale::Gaelic);
  language.addValue("Galician", QLocale::Galician);
  language.addValue("Georgian", QLocale::Georgian);
  language.addValue("German", QLocale::German);
  language.addValue("Greek", QLocale::Greek);
  language.addValue("Greenlandic", QLocale::Greenlandic);
  language.addValue("Guarani", QLocale::Guarani);
  language.addValue("Gujarati", QLocale::Gujarati);
  language.addValue("Haitian", QLocale::Haitian);
  language.addValue("Hausa", QLocale::Hausa);
  language.addValue("Hebrew", QLocale::Hebrew);
  language.addValue("Herero", QLocale::Herero);
  language.addValue("Hindi", QLocale::Hindi);
  language.addValue("HiriMotu", QLocale::HiriMotu);
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
  language.addValue("Kanuri", QLocale::Kanuri);
  language.addValue("Kashmiri", QLocale::Kashmiri);
  language.addValue("Kazakh", QLocale::Kazakh);
  language.addValue("Kinyarwanda", QLocale::Kinyarwanda);
  language.addValue("Kirghiz", QLocale::Kirghiz);
  language.addValue("Komi", QLocale::Komi);
  language.addValue("Kongo", QLocale::Kongo);
  language.addValue("Korean", QLocale::Korean);
  language.addValue("Kurdish", QLocale::Kurdish);
  language.addValue("Rundi", QLocale::Rundi);
  language.addValue("Kurundi", QLocale::Kurundi);
  language.addValue("Kwanyama", QLocale::Kwanyama);
  language.addValue("Lakota", QLocale::Lakota);
  language.addValue("Lao", QLocale::Lao);
  language.addValue("Latin", QLocale::Latin);
  language.addValue("Latvian", QLocale::Latvian);
  language.addValue("Limburgish", QLocale::Limburgish);
  language.addValue("Lingala", QLocale::Lingala);
  language.addValue("Lithuanian", QLocale::Lithuanian);
  language.addValue("LubaKatanga", QLocale::LubaKatanga);
  language.addValue("Luxembourgish", QLocale::Luxembourgish);
  language.addValue("Marshallese", QLocale::Marshallese);
  language.addValue("Macedonian", QLocale::Macedonian);
  language.addValue("Malagasy", QLocale::Malagasy);
  language.addValue("Malay", QLocale::Malay);
  language.addValue("Malayalam", QLocale::Malayalam);
  language.addValue("Maltese", QLocale::Maltese);
  language.addValue("Manx", QLocale::Manx);
  language.addValue("Maori", QLocale::Maori);
  language.addValue("Marathi", QLocale::Marathi);
  language.addValue("Moldavian", QLocale::Moldavian);
  language.addValue("Mongolian", QLocale::Mongolian);
  language.addValue("NauruLanguage", QLocale::NauruLanguage);
  language.addValue("Navaho", QLocale::Navaho);
  language.addValue("Ndonga", QLocale::Ndonga);
  language.addValue("Nepali", QLocale::Nepali);
  language.addValue("Norwegian", QLocale::Norwegian);
  language.addValue("NorwegianBokmal", QLocale::NorwegianBokmal);
  language.addValue("NorwegianNynorsk", QLocale::NorwegianNynorsk);
  language.addValue("Occitan", QLocale::Occitan);
  language.addValue("Ojibwa", QLocale::Ojibwa);
  language.addValue("Oriya", QLocale::Oriya);
  language.addValue("Ossetic", QLocale::Ossetic);
  language.addValue("Pali", QLocale::Pali);
  language.addValue("Pashto", QLocale::Pashto);
  language.addValue("Persian", QLocale::Persian);
  language.addValue("Polish", QLocale::Polish);
  language.addValue("Portuguese", QLocale::Portuguese);
  language.addValue("Punjabi", QLocale::Punjabi);
  language.addValue("Quechua", QLocale::Quechua);
  language.addValue("Romansh", QLocale::Romansh);
  language.addValue("RhaetoRomance", QLocale::RhaetoRomance);
  language.addValue("Romanian", QLocale::Romanian);
  language.addValue("Russian", QLocale::Russian);
  language.addValue("Samoan", QLocale::Samoan);
  language.addValue("Sango", QLocale::Sango);
  language.addValue("Sanskrit", QLocale::Sanskrit);
  language.addValue("Sardinian", QLocale::Sardinian);
  language.addValue("Serbian", QLocale::Serbian);
  language.addValue("SerboCroatian", QLocale::SerboCroatian);
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
  language.addValue("StandardMoroccanTamazight", QLocale::StandardMoroccanTamazight);
  language.addValue("Sundanese", QLocale::Sundanese);
  language.addValue("Swahili", QLocale::Swahili);
  language.addValue("Swedish", QLocale::Swedish);
  language.addValue("Tagalog", QLocale::Tagalog);
  language.addValue("Tahitian", QLocale::Tahitian);
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
  language.addValue("Twi", QLocale::Twi);
  language.addValue("Uighur", QLocale::Uighur);
  language.addValue("Uigur", QLocale::Uigur);
  language.addValue("Ukrainian", QLocale::Ukrainian);
  language.addValue("Urdu", QLocale::Urdu);
  language.addValue("Uzbek", QLocale::Uzbek);
  language.addValue("Vietnamese", QLocale::Vietnamese);
  language.addValue("Volapuk", QLocale::Volapuk);
  language.addValue("Walloon", QLocale::Walloon);
  language.addValue("Welsh", QLocale::Welsh);
  language.addValue("Wolof", QLocale::Wolof);
  language.addValue("Xhosa", QLocale::Xhosa);
  language.addValue("Yiddish", QLocale::Yiddish);
  language.addValue("Yoruba", QLocale::Yoruba);
  language.addValue("Zhuang", QLocale::Zhuang);
  language.addValue("Zulu", QLocale::Zulu);
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
  language.addValue("Chewa", QLocale::Chewa);
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
  language.addValue("LowerSorbian", QLocale::LowerSorbian);
  language.addValue("UpperSorbian", QLocale::UpperSorbian);
  language.addValue("Ahom", QLocale::Ahom);
  language.addValue("AmericanSignLanguage", QLocale::AmericanSignLanguage);
  language.addValue("ArdhamagadhiPrakrit", QLocale::ArdhamagadhiPrakrit);
  language.addValue("Bhojpuri", QLocale::Bhojpuri);
  language.addValue("Cantonese", QLocale::Cantonese);
  language.addValue("HieroglyphicLuwian", QLocale::HieroglyphicLuwian);
  language.addValue("LiteraryChinese", QLocale::LiteraryChinese);
  language.addValue("Mazanderani", QLocale::Mazanderani);
  language.addValue("Mru", QLocale::Mru);
  language.addValue("Newari", QLocale::Newari);
  language.addValue("NorthernLuri", QLocale::NorthernLuri);
  language.addValue("Osage", QLocale::Osage);
  language.addValue("Palauan", QLocale::Palauan);
  language.addValue("Papiamento", QLocale::Papiamento);
  language.addValue("Saraiki", QLocale::Saraiki);
  language.addValue("Tangut", QLocale::Tangut);
  language.addValue("TokelauLanguage", QLocale::TokelauLanguage);
  language.addValue("TokPisin", QLocale::TokPisin);
  language.addValue("TuvaluLanguage", QLocale::TuvaluLanguage);
  language.addValue("UncodedLanguages", QLocale::UncodedLanguages);
}

script::Type get_measurement_system_type()
{
  return measurement_system_type_id;
}

static void register_measurement_system_enum(script::Class locale)
{
  using namespace script;

  Enum measurement_system = locale.newEnum("MeasurementSystem");
  measurement_system_type_id = measurement_system.id();

  measurement_system.addValue("MetricSystem", QLocale::MetricSystem);
  measurement_system.addValue("ImperialUSSystem", QLocale::ImperialUSSystem);
  measurement_system.addValue("ImperialUKSystem", QLocale::ImperialUKSystem);
  measurement_system.addValue("ImperialSystem", QLocale::ImperialSystem);
}

script::Type get_number_option_type()
{
  return number_option_type_id;
}

script::Type get_number_options_type()
{
  return number_options_type_id;
}

static void register_number_option_enum(script::Class locale)
{
  using namespace script;

  Enum number_option = locale.newEnum("NumberOption");
  number_option_type_id = number_option.id();

  number_option.addValue("DefaultNumberOptions", QLocale::DefaultNumberOptions);
  number_option.addValue("OmitGroupSeparator", QLocale::OmitGroupSeparator);
  number_option.addValue("RejectGroupSeparator", QLocale::RejectGroupSeparator);
  number_option.addValue("OmitLeadingZeroInExponent", QLocale::OmitLeadingZeroInExponent);
  number_option.addValue("RejectLeadingZeroInExponent", QLocale::RejectLeadingZeroInExponent);
  number_option.addValue("IncludeTrailingZeroesAfterDot", QLocale::IncludeTrailingZeroesAfterDot);
  number_option.addValue("RejectTrailingZeroesAfterDot", QLocale::RejectTrailingZeroesAfterDot);

  Class number_options = register_qflags_type<QLocale::NumberOption>(locale, "NumberOptions");
  number_options_type_id = number_options.id();
}


script::Type get_quotation_style_type()
{
  return quotation_style_type_id;
}

static void register_quotation_style_enum(script::Class locale)
{
  using namespace script;

  Enum quotation_style = locale.newEnum("QuotationStyle");
  quotation_style_type_id = quotation_style.id();

  quotation_style.addValue("StandardQuotation", QLocale::StandardQuotation);
  quotation_style.addValue("AlternateQuotation", QLocale::AlternateQuotation);
}

script::Type get_script_type()
{
  return script_type_id;
}

static void register_script_enum(script::Class locale)
{
  using namespace script;

  Enum script = locale.newEnum("Script");
  script_type_id = script.id();

  script.addValue("AnyScript", QLocale::AnyScript);
  script.addValue("AdlamScript", QLocale::AdlamScript);
  script.addValue("AhomScript", QLocale::AhomScript);
  script.addValue("AnatolianHieroglyphsScript", QLocale::AnatolianHieroglyphsScript);
  script.addValue("ArabicScript", QLocale::ArabicScript);
  script.addValue("ArmenianScript", QLocale::ArmenianScript);
  script.addValue("AvestanScript", QLocale::AvestanScript);
  script.addValue("BalineseScript", QLocale::BalineseScript);
  script.addValue("BamumScript", QLocale::BamumScript);
  script.addValue("BassaVahScript", QLocale::BassaVahScript);
  script.addValue("BatakScript", QLocale::BatakScript);
  script.addValue("BengaliScript", QLocale::BengaliScript);
  script.addValue("BhaiksukiScript", QLocale::BhaiksukiScript);
  script.addValue("BopomofoScript", QLocale::BopomofoScript);
  script.addValue("BrahmiScript", QLocale::BrahmiScript);
  script.addValue("BrailleScript", QLocale::BrailleScript);
  script.addValue("BugineseScript", QLocale::BugineseScript);
  script.addValue("BuhidScript", QLocale::BuhidScript);
  script.addValue("CanadianAboriginalScript", QLocale::CanadianAboriginalScript);
  script.addValue("CarianScript", QLocale::CarianScript);
  script.addValue("CaucasianAlbanianScript", QLocale::CaucasianAlbanianScript);
  script.addValue("ChakmaScript", QLocale::ChakmaScript);
  script.addValue("ChamScript", QLocale::ChamScript);
  script.addValue("CherokeeScript", QLocale::CherokeeScript);
  script.addValue("CopticScript", QLocale::CopticScript);
  script.addValue("CypriotScript", QLocale::CypriotScript);
  script.addValue("CyrillicScript", QLocale::CyrillicScript);
  script.addValue("DeseretScript", QLocale::DeseretScript);
  script.addValue("DevanagariScript", QLocale::DevanagariScript);
  script.addValue("DuployanScript", QLocale::DuployanScript);
  script.addValue("EgyptianHieroglyphsScript", QLocale::EgyptianHieroglyphsScript);
  script.addValue("ElbasanScript", QLocale::ElbasanScript);
  script.addValue("EthiopicScript", QLocale::EthiopicScript);
  script.addValue("FraserScript", QLocale::FraserScript);
  script.addValue("GeorgianScript", QLocale::GeorgianScript);
  script.addValue("GlagoliticScript", QLocale::GlagoliticScript);
  script.addValue("GothicScript", QLocale::GothicScript);
  script.addValue("GranthaScript", QLocale::GranthaScript);
  script.addValue("GreekScript", QLocale::GreekScript);
  script.addValue("GujaratiScript", QLocale::GujaratiScript);
  script.addValue("GurmukhiScript", QLocale::GurmukhiScript);
  script.addValue("HanScript", QLocale::HanScript);
  script.addValue("HangulScript", QLocale::HangulScript);
  script.addValue("HanunooScript", QLocale::HanunooScript);
  script.addValue("HanWithBopomofoScript", QLocale::HanWithBopomofoScript);
  script.addValue("HatranScript", QLocale::HatranScript);
  script.addValue("HebrewScript", QLocale::HebrewScript);
  script.addValue("HiraganaScript", QLocale::HiraganaScript);
  script.addValue("ImperialAramaicScript", QLocale::ImperialAramaicScript);
  script.addValue("InscriptionalPahlaviScript", QLocale::InscriptionalPahlaviScript);
  script.addValue("InscriptionalParthianScript", QLocale::InscriptionalParthianScript);
  script.addValue("JamoScript", QLocale::JamoScript);
  script.addValue("JapaneseScript", QLocale::JapaneseScript);
  script.addValue("JavaneseScript", QLocale::JavaneseScript);
  script.addValue("KaithiScript", QLocale::KaithiScript);
  script.addValue("KannadaScript", QLocale::KannadaScript);
  script.addValue("KatakanaScript", QLocale::KatakanaScript);
  script.addValue("KayahLiScript", QLocale::KayahLiScript);
  script.addValue("KharoshthiScript", QLocale::KharoshthiScript);
  script.addValue("KhmerScript", QLocale::KhmerScript);
  script.addValue("KhojkiScript", QLocale::KhojkiScript);
  script.addValue("KhudawadiScript", QLocale::KhudawadiScript);
  script.addValue("KoreanScript", QLocale::KoreanScript);
  script.addValue("LannaScript", QLocale::LannaScript);
  script.addValue("LaoScript", QLocale::LaoScript);
  script.addValue("LatinScript", QLocale::LatinScript);
  script.addValue("LepchaScript", QLocale::LepchaScript);
  script.addValue("LimbuScript", QLocale::LimbuScript);
  script.addValue("LinearAScript", QLocale::LinearAScript);
  script.addValue("LinearBScript", QLocale::LinearBScript);
  script.addValue("LycianScript", QLocale::LycianScript);
  script.addValue("LydianScript", QLocale::LydianScript);
  script.addValue("MahajaniScript", QLocale::MahajaniScript);
  script.addValue("MalayalamScript", QLocale::MalayalamScript);
  script.addValue("MandaeanScript", QLocale::MandaeanScript);
  script.addValue("ManichaeanScript", QLocale::ManichaeanScript);
  script.addValue("MarchenScript", QLocale::MarchenScript);
  script.addValue("MeiteiMayekScript", QLocale::MeiteiMayekScript);
  script.addValue("MendeKikakuiScript", QLocale::MendeKikakuiScript);
  script.addValue("MeroiticScript", QLocale::MeroiticScript);
  script.addValue("MeroiticCursiveScript", QLocale::MeroiticCursiveScript);
  script.addValue("ModiScript", QLocale::ModiScript);
  script.addValue("MongolianScript", QLocale::MongolianScript);
  script.addValue("MroScript", QLocale::MroScript);
  script.addValue("MultaniScript", QLocale::MultaniScript);
  script.addValue("MyanmarScript", QLocale::MyanmarScript);
  script.addValue("NabataeanScript", QLocale::NabataeanScript);
  script.addValue("NkoScript", QLocale::NkoScript);
  script.addValue("NewaScript", QLocale::NewaScript);
  script.addValue("NewTaiLueScript", QLocale::NewTaiLueScript);
  script.addValue("OghamScript", QLocale::OghamScript);
  script.addValue("OlChikiScript", QLocale::OlChikiScript);
  script.addValue("OldItalicScript", QLocale::OldItalicScript);
  script.addValue("OldHungarianScript", QLocale::OldHungarianScript);
  script.addValue("OldNorthArabianScript", QLocale::OldNorthArabianScript);
  script.addValue("OldPermicScript", QLocale::OldPermicScript);
  script.addValue("OldPersianScript", QLocale::OldPersianScript);
  script.addValue("OldSouthArabianScript", QLocale::OldSouthArabianScript);
  script.addValue("OriyaScript", QLocale::OriyaScript);
  script.addValue("OrkhonScript", QLocale::OrkhonScript);
  script.addValue("OsageScript", QLocale::OsageScript);
  script.addValue("OsmanyaScript", QLocale::OsmanyaScript);
  script.addValue("PahawhHmongScript", QLocale::PahawhHmongScript);
  script.addValue("PalmyreneScript", QLocale::PalmyreneScript);
  script.addValue("PauCinHauScript", QLocale::PauCinHauScript);
  script.addValue("PhagsPaScript", QLocale::PhagsPaScript);
  script.addValue("PhoenicianScript", QLocale::PhoenicianScript);
  script.addValue("PollardPhoneticScript", QLocale::PollardPhoneticScript);
  script.addValue("PsalterPahlaviScript", QLocale::PsalterPahlaviScript);
  script.addValue("RejangScript", QLocale::RejangScript);
  script.addValue("RunicScript", QLocale::RunicScript);
  script.addValue("SamaritanScript", QLocale::SamaritanScript);
  script.addValue("SaurashtraScript", QLocale::SaurashtraScript);
  script.addValue("SharadaScript", QLocale::SharadaScript);
  script.addValue("ShavianScript", QLocale::ShavianScript);
  script.addValue("SiddhamScript", QLocale::SiddhamScript);
  script.addValue("SignWritingScript", QLocale::SignWritingScript);
  script.addValue("SimplifiedHanScript", QLocale::SimplifiedHanScript);
  script.addValue("SimplifiedChineseScript", QLocale::SimplifiedChineseScript);
  script.addValue("SinhalaScript", QLocale::SinhalaScript);
  script.addValue("SoraSompengScript", QLocale::SoraSompengScript);
  script.addValue("CuneiformScript", QLocale::CuneiformScript);
  script.addValue("SundaneseScript", QLocale::SundaneseScript);
  script.addValue("SylotiNagriScript", QLocale::SylotiNagriScript);
  script.addValue("SyriacScript", QLocale::SyriacScript);
  script.addValue("TagalogScript", QLocale::TagalogScript);
  script.addValue("TagbanwaScript", QLocale::TagbanwaScript);
  script.addValue("TaiLeScript", QLocale::TaiLeScript);
  script.addValue("TaiVietScript", QLocale::TaiVietScript);
  script.addValue("TakriScript", QLocale::TakriScript);
  script.addValue("TamilScript", QLocale::TamilScript);
  script.addValue("TangutScript", QLocale::TangutScript);
  script.addValue("TeluguScript", QLocale::TeluguScript);
  script.addValue("ThaanaScript", QLocale::ThaanaScript);
  script.addValue("ThaiScript", QLocale::ThaiScript);
  script.addValue("TibetanScript", QLocale::TibetanScript);
  script.addValue("TifinaghScript", QLocale::TifinaghScript);
  script.addValue("TirhutaScript", QLocale::TirhutaScript);
  script.addValue("TraditionalHanScript", QLocale::TraditionalHanScript);
  script.addValue("TraditionalChineseScript", QLocale::TraditionalChineseScript);
  script.addValue("UgariticScript", QLocale::UgariticScript);
  script.addValue("VaiScript", QLocale::VaiScript);
  script.addValue("VarangKshitiScript", QLocale::VarangKshitiScript);
  script.addValue("YiScript", QLocale::YiScript);
}



script::Type get_locale_type()
{
  return script::Type{ locale_type_id };
}

script::Type get_ptr_locale_type()
{
  return ptr_locale_type_id;
}

script::Type get_list_locale_type()
{
  return list_locale_type_id;
}

void register_locale_class(script::Namespace ns)
{
  using namespace script;

  Class locale = ns.newClass(ClassBuilder::New("Locale").setFinal());
  locale_type_id = locale.id();

  register_ptr_specialization<QLocale>(get_ptr_template(), &ptr_locale_type_id);
  register_list_specialization<QLocale>(get_qlist_template(), &list_locale_type_id);

  register_country_enum(locale);
  register_currency_symbol_format_enum(locale);
  register_data_size_format_enum(locale);
  register_floating_point_precision_option_enum(locale);
  register_format_type_enum(locale);
  register_language_enum(locale);
  register_measurement_system_enum(locale);
  register_number_option_enum(locale);
  register_quotation_style_enum(locale);
  register_script_enum(locale);

  binding::Class<QLocale> binder{ locale };

  // QLocale(const QLocale &);
  binder.ctors().add<const QLocale &>();

  // ~QLocale();
  binder.add_dtor();


  /* Public member functions */

  // QString amText() const
  binder.add_fun<QString, &QLocale::amText>("amText");
  // QString bcp47Name() const
  binder.add_fun<QString, &QLocale::bcp47Name>("bcp47Name");
  // QLocale::Country country() const
  binder.add_fun<QLocale::Country, &QLocale::country>("country");
  // QString createSeparatedList(const QStringList &list) const
  binder.add_fun<QString, const QStringList &, &QLocale::createSeparatedList>("createSeparatedList");
  // QString currencySymbol(QLocale::CurrencySymbolFormat format = CurrencySymbol) const
  binder.add_fun<QString, QLocale::CurrencySymbolFormat, &QLocale::currencySymbol>("currencySymbol");
  // QString dateFormat(QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, QLocale::FormatType, &QLocale::dateFormat>("dateFormat");
  // QString dateTimeFormat(QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, QLocale::FormatType, &QLocale::dateTimeFormat>("dateTimeFormat");
  // QString dayName(int day, QLocale::FormatType type = LongFormat) const
  binder.add_fun<QString, int, QLocale::FormatType, &QLocale::dayName>("dayName");
  // QChar decimalPoint() const
  /// binder.add_fun<QChar, &QLocale::decimalPoint>("decimalPoint");
  // QChar exponential() const
  /// binder.add_fun<QChar, &QLocale::exponential>("exponential");
  // Qt::DayOfWeek firstDayOfWeek() const
  binder.add_fun<Qt::DayOfWeek, &QLocale::firstDayOfWeek>("firstDayOfWeek");
  // QString formattedDataSize(qint64 bytes, int precision = 2, QLocale::DataSizeFormats format = DataSizeIecFormat)
  binder.add_fun<QString, qint64, int, QLocale::DataSizeFormats, &QLocale::formattedDataSize>("formattedDataSize");
  // QChar groupSeparator() const
  /// binder.add_fun<QChar, &QLocale::groupSeparator>("groupSeparator");
  // QLocale::Language language() const
  binder.add_fun<QLocale::Language, &QLocale::language>("language");
  // QLocale::MeasurementSystem measurementSystem() const
  binder.add_fun<QLocale::MeasurementSystem, &QLocale::measurementSystem>("measurementSystem");
  // QString monthName(int month, QLocale::FormatType type = LongFormat) const
  binder.add_fun<QString, int, QLocale::FormatType, &QLocale::monthName>("monthName");
  // QString name() const
  binder.add_fun<QString, &QLocale::name>("name");
  // QString nativeCountryName() const
  binder.add_fun<QString, &QLocale::nativeCountryName>("nativeCountryName");
  // QString nativeLanguageName() const
  binder.add_fun<QString, &QLocale::nativeLanguageName>("nativeLanguageName");
  // QChar negativeSign() const
  /// binder.add_fun<QChar, &QLocale::negativeSign>("negativeSign");
  // QLocale::NumberOptions numberOptions() const
  binder.add_fun<QLocale::NumberOptions, &QLocale::numberOptions>("numberOptions");
  // QChar percent() const
  /// binder.add_fun<QChar, &QLocale::percent>("percent");
  // QString pmText() const
  binder.add_fun<QString, &QLocale::pmText>("pmText");
  // QChar positiveSign() const
  /// binder.add_fun<QChar, &QLocale::positiveSign>("positiveSign");
  // QString quoteString(const QString &str, QLocale::QuotationStyle style = StandardQuotation) const
  binder.add_fun<QString, const QString &, QLocale::QuotationStyle, &QLocale::quoteString>("quoteString");
  // QString quoteString(const QStringRef &str, QLocale::QuotationStyle style = StandardQuotation) const
  /// binder.add_fun<QString, const QStringRef &, QLocale::QuotationStyle, &QLocale::quoteString>("quoteString");
  // QLocale::Script script() const
  binder.add_fun<QLocale::Script, &QLocale::script>("script");
  // void setNumberOptions(QLocale::NumberOptions options)
  binder.add_void_fun<QLocale::NumberOptions, &QLocale::setNumberOptions>("setNumberOptions");
  // QString standaloneDayName(int day, QLocale::FormatType type = LongFormat) const
  binder.add_fun<QString, int, QLocale::FormatType, &QLocale::standaloneDayName>("standaloneDayName");
  // QString standaloneMonthName(int month, QLocale::FormatType type = LongFormat) const
  binder.add_fun<QString, int, QLocale::FormatType, &QLocale::standaloneMonthName>("standaloneMonthName");
  // void swap(QLocale &other)
  binder.add_void_fun<QLocale &, &QLocale::swap>("swap");
  // Qt::LayoutDirection textDirection() const
  binder.add_fun<Qt::LayoutDirection, &QLocale::textDirection>("textDirection");
  // QString timeFormat(QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, QLocale::FormatType, &QLocale::timeFormat>("timeFormat");
  // QString toCurrencyString(qlonglong value, const QString &symbol = QString()) const
  binder.add_fun<QString, qlonglong, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(qulonglong value, const QString &symbol = QString()) const
  binder.add_fun<QString, qulonglong, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(short value, const QString &symbol = QString()) const
  binder.add_fun<QString, short, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(ushort value, const QString &symbol = QString()) const
  binder.add_fun<QString, ushort, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(int value, const QString &symbol = QString()) const
  binder.add_fun<QString, int, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(uint value, const QString &symbol = QString()) const
  binder.add_fun<QString, uint, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(double value, const QString &symbol = QString()) const
  binder.add_fun<QString, double, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(double value, const QString &symbol, int precision) const
  binder.add_fun<QString, double, const QString &, int, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(float value, const QString &symbol = QString()) const
  binder.add_fun<QString, float, const QString &, &QLocale::toCurrencyString>("toCurrencyString");
  // QString toCurrencyString(float i, const QString &symbol, int precision) const
  binder.add_fun<QString, float, const QString &, int, &QLocale::toCurrencyString>("toCurrencyString");
  // QDate toDate(const QString &string, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QDate, const QString &, QLocale::FormatType, &QLocale::toDate>("toDate");
  // QDate toDate(const QString &string, const QString &format) const
  binder.add_fun<QDate, const QString &, const QString &, &QLocale::toDate>("toDate");
  // QDateTime toDateTime(const QString &string, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QDateTime, const QString &, QLocale::FormatType, &QLocale::toDateTime>("toDateTime");
  // QDateTime toDateTime(const QString &string, const QString &format) const
  binder.add_fun<QDateTime, const QString &, const QString &, &QLocale::toDateTime>("toDateTime");
  // double toDouble(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // double toDouble(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // double toDouble(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // float toFloat(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // float toFloat(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // float toFloat(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // int toInt(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // int toInt(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // int toInt(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // qlonglong toLongLong(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // qlonglong toLongLong(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // qlonglong toLongLong(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // QString toLower(const QString &str) const
  binder.add_fun<QString, const QString &, &QLocale::toLower>("toLower");
  // short toShort(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // short toShort(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // short toShort(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // QString toString(qlonglong i) const
  binder.add_fun<QString, qlonglong, &QLocale::toString>("toString");
  // QString toString(qulonglong i) const
  binder.add_fun<QString, qulonglong, &QLocale::toString>("toString");
  // QString toString(short i) const
  binder.add_fun<QString, short, &QLocale::toString>("toString");
  // QString toString(ushort i) const
  binder.add_fun<QString, ushort, &QLocale::toString>("toString");
  // QString toString(int i) const
  binder.add_fun<QString, int, &QLocale::toString>("toString");
  // QString toString(uint i) const
  binder.add_fun<QString, uint, &QLocale::toString>("toString");
  // QString toString(double i, char f = 'g', int prec = 6) const
  binder.add_fun<QString, double, char, int, &QLocale::toString>("toString");
  // QString toString(float i, char f = ..., int prec = ...) const
  /// TODO !!!
  // QString toString(const QDate &date, const QString &format) const
  binder.add_fun<QString, const QDate &, const QString &, &QLocale::toString>("toString");
  // QString toString(const QTime &time, const QString &format) const
  binder.add_fun<QString, const QTime &, const QString &, &QLocale::toString>("toString");
  // QString toString(const QDateTime &dateTime, const QString &format) const
  binder.add_fun<QString, const QDateTime &, const QString &, &QLocale::toString>("toString");
  // QString toString(const QDate &date, QStringView format) const
  /// binder.add_fun<QString, const QDate &, QStringView, &QLocale::toString>("toString");
  // QString toString(const QTime &time, QStringView format) const
  /// binder.add_fun<QString, const QTime &, QStringView, &QLocale::toString>("toString");
  // QString toString(const QDateTime &dateTime, QStringView format) const
  /// binder.add_fun<QString, const QDateTime &, QStringView, &QLocale::toString>("toString");
  // QString toString(const QDate &date, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, const QDate &, QLocale::FormatType, &QLocale::toString>("toString");
  // QString toString(const QTime &time, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, const QTime &, QLocale::FormatType, &QLocale::toString>("toString");
  // QString toString(const QDateTime &dateTime, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QString, const QDateTime &, QLocale::FormatType, &QLocale::toString>("toString");
  // QTime toTime(const QString &string, QLocale::FormatType format = LongFormat) const
  binder.add_fun<QTime, const QString &, QLocale::FormatType, &QLocale::toTime>("toTime");
  // QTime toTime(const QString &string, const QString &format) const
  binder.add_fun<QTime, const QString &, const QString &, &QLocale::toTime>("toTime");
  // uint toUInt(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // uint toUInt(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // uint toUInt(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // qulonglong toULongLong(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // qulonglong toULongLong(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // qulonglong toULongLong(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // ushort toUShort(const QString &s, bool *ok = nullptr) const
  /// TODO !!!
  // ushort toUShort(const QStringRef &s, bool *ok = nullptr) const
  /// TODO !!!
  // ushort toUShort(QStringView s, bool *ok = nullptr) const
  /// TODO !!!
  // QString toUpper(const QString &str) const
  binder.add_fun<QString, const QString &, &QLocale::toUpper>("toUpper");
  // QStringList uiLanguages() const
  binder.add_fun<QStringList, &QLocale::uiLanguages>("uiLanguages");
  // QList<Qt::DayOfWeek> weekdays() const
  /// binder.add_fun<QList<Qt::DayOfWeek>, &QLocale::weekdays>("weekdays");
  // QChar zeroDigit() const
  /// binder.add_fun<QChar, &QLocale::zeroDigit>("zeroDigit");
  // bool operator!=(const QLocale &other) const
  /// TODO !!!
  // QLocale & operator=(QLocale &&other)
  /// TODO !!!
  // QLocale & operator=(const QLocale &other)
  /// TODO !!!
  // bool operator==(const QLocale &other) const
  /// TODO !!!



  /* Static public members */

  // static QLocale c()
  binder.add_static<QLocale, &QLocale::c>("c");
  // static QString countryToString(QLocale::Country country)
  binder.add_static<QString, QLocale::Country, &QLocale::countryToString>("countryToString");
  // static QString languageToString(QLocale::Language language)
  binder.add_static<QString, QLocale::Language, &QLocale::languageToString>("languageToString");
  // static QList<QLocale> matchingLocales(QLocale::Language language, QLocale::Script script, QLocale::Country country)
  binder.add_static<QList<QLocale>, QLocale::Language, QLocale::Script, QLocale::Country, &QLocale::matchingLocales>("matchingLocales");
  // static QString scriptToString(QLocale::Script script)
  binder.add_static<QString, QLocale::Script, &QLocale::scriptToString>("scriptToString");
  // static void setDefault(const QLocale &locale)
  /// TODO !!!
  // static QLocale system()
  binder.add_static<QLocale, &QLocale::system>("system");



  /* Related non-members */
  binding::Namespace related{ ns };
  // uint qHash(const QLocale &key, uint seed = 0)
  /// TODO !!!
}
