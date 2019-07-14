// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_REGULAREXPRESSION_H
#define YASL_CORE_REGULAREXPRESSION_H

#include "yasl/common/types.h"

#include <QRegularExpression>

namespace script {
template<> struct make_type_helper<QRegularExpression> { inline static script::Type get() { return script::Type::QRegularExpression; } };
template<> struct make_type_helper<QRegularExpression::MatchOption> { inline static script::Type get() { return script::Type::QRegularExpressionMatchOption; } };
template<> struct make_type_helper<QRegularExpression::MatchOptions> { inline static script::Type get() { return script::Type::QRegularExpressionMatchOptions; } };
template<> struct make_type_helper<QRegularExpression::MatchType> { inline static script::Type get() { return script::Type::QRegularExpressionMatchType; } };
template<> struct make_type_helper<QRegularExpression::PatternOption> { inline static script::Type get() { return script::Type::QRegularExpressionPatternOption; } };
template<> struct make_type_helper<QRegularExpression::PatternOptions> { inline static script::Type get() { return script::Type::QRegularExpressionPatternOptions; } };
template<> struct make_type_helper<QRegularExpressionMatch> { inline static script::Type get() { return script::Type::QRegularExpressionMatch; } };
template<> struct make_type_helper<QRegularExpressionMatchIterator> { inline static script::Type get() { return script::Type::QRegularExpressionMatchIterator; } };
} // namespace script

#endif // YASL_CORE_REGULAREXPRESSION_H
