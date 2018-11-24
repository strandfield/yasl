// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LOCALE_H
#define YASL_CORE_LOCALE_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include <QLocale>

namespace script {
template<> struct make_type_t<Proxy<QLocale>> { inline static script::Type get() { return script::Type::ProxyQLocale; } };
template<> struct make_type_t<QList<QLocale>> { inline static script::Type get() { return script::Type::QListQLocale; } };
template<> struct make_type_t<QLocale> { inline static script::Type get() { return script::Type::QLocale; } };
template<> struct make_type_t<QLocale::Country> { inline static script::Type get() { return script::Type::QLocaleCountry; } };
template<> struct make_type_t<QLocale::CurrencySymbolFormat> { inline static script::Type get() { return script::Type::QLocaleCurrencySymbolFormat; } };
template<> struct make_type_t<QLocale::FloatingPointPrecisionOption> { inline static script::Type get() { return script::Type::QLocaleFloatingPointPrecisionOption; } };
template<> struct make_type_t<QLocale::FormatType> { inline static script::Type get() { return script::Type::QLocaleFormatType; } };
template<> struct make_type_t<QLocale::Language> { inline static script::Type get() { return script::Type::QLocaleLanguage; } };
template<> struct make_type_t<QLocale::MeasurementSystem> { inline static script::Type get() { return script::Type::QLocaleMeasurementSystem; } };
template<> struct make_type_t<QLocale::NumberOption> { inline static script::Type get() { return script::Type::QLocaleNumberOption; } };
template<> struct make_type_t<QLocale::NumberOptions> { inline static script::Type get() { return script::Type::QLocaleNumberOptions; } };
template<> struct make_type_t<QLocale::QuotationStyle> { inline static script::Type get() { return script::Type::QLocaleQuotationStyle; } };
template<> struct make_type_t<QLocale::Script> { inline static script::Type get() { return script::Type::QLocaleScript; } };
} // namespace script

#endif // YASL_CORE_LOCALE_H
