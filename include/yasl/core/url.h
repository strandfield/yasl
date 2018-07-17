// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_URL_H
#define YASL_CORE_URL_H

#include "yasl/binding/types.h"

#include <QUrl>

namespace binding {
template<> struct make_type_t<QUrl> { inline static script::Type get() { return script::Type::QUrl; } };
template<> struct make_type_t<QUrl::ComponentFormattingOption> { inline static script::Type get() { return script::Type::QUrlComponentFormattingOption; } };
template<> struct make_type_t<QUrl::ComponentFormattingOptions> { inline static script::Type get() { return script::Type::QUrlComponentFormattingOptions; } };
template<> struct make_type_t<QUrl::ParsingMode> { inline static script::Type get() { return script::Type::QUrlParsingMode; } };
template<> struct make_type_t<QUrl::UrlFormattingOption> { inline static script::Type get() { return script::Type::QUrlUrlFormattingOption; } };
template<> struct make_type_t<QFlags<QUrl::UrlFormattingOption>> { inline static script::Type get() { return script::Type::QUrlFormattingOptions; } };
template<> struct make_type_t<QUrl::UserInputResolutionOption> { inline static script::Type get() { return script::Type::QUrlUserInputResolutionOption; } };
template<> struct make_type_t<QUrl::UserInputResolutionOptions> { inline static script::Type get() { return script::Type::QUrlUserInputResolutionOptions; } };
} // namespace binding

#endif // YASL_CORE_URL_H
