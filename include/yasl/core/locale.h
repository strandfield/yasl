// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LOCALE_H
#define YASL_CORE_LOCALE_H

#include "yasl/binding/utils.h"

#include "yasl/utils/ptr.h"

#include <script/namespace.h>

#include <QLocale>

void register_locale_class(script::Namespace n);
script::Type get_locale_type();
script::Type get_ptr_locale_type();
script::Type get_list_locale_type();

script::Type get_country_type();
script::Type get_currency_symbol_format_type();
script::Type get_data_size_format_type();
script::Type get_data_size_formats_type();
script::Type get_floating_point_precision_option_type();
script::Type get_format_type_type();
script::Type get_language_type();
script::Type get_measurement_system_type();
script::Type get_number_option_type();
script::Type get_number_options_type();
script::Type get_quotation_style_type();
script::Type get_script_type();

namespace binding
{
template<> struct make_type_t<QLocale> { inline static script::Type get() { return get_locale_type(); } };
template<> struct make_type_t<Ptr<QLocale>> { inline static script::Type get() { return get_ptr_locale_type(); } };
template<> struct make_type_t<QList<QLocale>> { inline static script::Type get() { return get_list_locale_type(); } };

template<> struct make_type_t<QLocale::Country> { inline static script::Type get() { return get_country_type(); } };
template<> struct make_type_t<QLocale::CurrencySymbolFormat> { inline static script::Type get() { return get_currency_symbol_format_type(); } };
template<> struct make_type_t<QLocale::DataSizeFormat> { inline static script::Type get() { return get_data_size_format_type(); } };
template<> struct make_type_t<QLocale::DataSizeFormats> { inline static script::Type get() { return get_data_size_formats_type(); } };
template<> struct make_type_t<QLocale::FloatingPointPrecisionOption> { inline static script::Type get() { return get_floating_point_precision_option_type(); } };
template<> struct make_type_t<QLocale::FormatType> { inline static script::Type get() { return get_format_type_type(); } };
template<> struct make_type_t<QLocale::Language> { inline static script::Type get() { return get_language_type(); } };
template<> struct make_type_t<QLocale::MeasurementSystem> { inline static script::Type get() { return get_measurement_system_type(); } };
template<> struct make_type_t<QLocale::NumberOption> { inline static script::Type get() { return get_number_option_type(); } };
template<> struct make_type_t<QLocale::NumberOptions> { inline static script::Type get() { return get_number_options_type(); } };
template<> struct make_type_t<QLocale::QuotationStyle> { inline static script::Type get() { return get_quotation_style_type(); } };
template<> struct make_type_t<QLocale::Script> { inline static script::Type get() { return get_script_type(); } };

} // namespace binding

#endif // YASL_CORE_LOCALE_H
