// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_URL_H
#define YASL_CORE_URL_H

#include "yasl/common/types.h"

#include <QUrl>

namespace script {
template<> struct make_type_helper<QUrl> { inline static script::Type get() { return script::Type::QUrl; } };
template<> struct make_type_helper<QUrl::ComponentFormattingOption> { inline static script::Type get() { return script::Type::QUrlComponentFormattingOption; } };
template<> struct make_type_helper<QUrl::ComponentFormattingOptions> { inline static script::Type get() { return script::Type::QUrlComponentFormattingOptions; } };
template<> struct make_type_helper<QUrl::ParsingMode> { inline static script::Type get() { return script::Type::QUrlParsingMode; } };
template<> struct make_type_helper<QUrl::UrlFormattingOption> { inline static script::Type get() { return script::Type::QUrlUrlFormattingOption; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_helper<QUrl::UserInputResolutionOption> { inline static script::Type get() { return script::Type::QUrlUserInputResolutionOption; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_helper<QUrl::UserInputResolutionOptions> { inline static script::Type get() { return script::Type::QUrlUserInputResolutionOptions; } };
#endif
} // namespace script

#endif // YASL_CORE_URL_H
