// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_REGULAREXPRESSION_H
#define YASL_CORE_REGULAREXPRESSION_H

#include "yasl/binding/types.h"

#include <QRegularExpression>

namespace binding {
template<> struct make_type_t<QRegularExpression> { inline static script::Type get() { return script::Type::QRegularExpression; } };
template<> struct make_type_t<QRegularExpression::MatchOption> { inline static script::Type get() { return script::Type::QRegularExpressionMatchOption; } };
template<> struct make_type_t<QRegularExpression::MatchOptions> { inline static script::Type get() { return script::Type::QRegularExpressionMatchOptions; } };
template<> struct make_type_t<QRegularExpression::MatchType> { inline static script::Type get() { return script::Type::QRegularExpressionMatchType; } };
template<> struct make_type_t<QRegularExpression::PatternOption> { inline static script::Type get() { return script::Type::QRegularExpressionPatternOption; } };
template<> struct make_type_t<QRegularExpression::PatternOptions> { inline static script::Type get() { return script::Type::QRegularExpressionPatternOptions; } };
template<> struct make_type_t<QRegularExpressionMatch> { inline static script::Type get() { return script::Type::QRegularExpressionMatch; } };
template<> struct make_type_t<QRegularExpressionMatchIterator> { inline static script::Type get() { return script::Type::QRegularExpressionMatchIterator; } };
} // namespace binding

#endif // YASL_CORE_REGULAREXPRESSION_H
