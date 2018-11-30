// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_CHAR_H
#define YASL_CORE_CHAR_H

#include "yasl/common/types.h"

#include <QChar>

namespace script {
template<> struct make_type_t<QChar> { inline static script::Type get() { return script::Type::QChar; } };
template<> struct make_type_t<QChar::Category> { inline static script::Type get() { return script::Type::QCharCategory; } };
template<> struct make_type_t<QChar::CombiningClass> { inline static script::Type get() { return script::Type::QCharCombiningClass; } };
template<> struct make_type_t<QChar::Decomposition> { inline static script::Type get() { return script::Type::QCharDecomposition; } };
template<> struct make_type_t<QChar::Direction> { inline static script::Type get() { return script::Type::QCharDirection; } };
template<> struct make_type_t<QChar::Joining> { inline static script::Type get() { return script::Type::QCharJoining; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
template<> struct make_type_t<QChar::JoiningType> { inline static script::Type get() { return script::Type::QCharJoiningType; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_t<QChar::Script> { inline static script::Type get() { return script::Type::QCharScript; } };
#endif
template<> struct make_type_t<QChar::SpecialCharacter> { inline static script::Type get() { return script::Type::QCharSpecialCharacter; } };
template<> struct make_type_t<QChar::UnicodeVersion> { inline static script::Type get() { return script::Type::QCharUnicodeVersion; } };
} // namespace script

#endif // YASL_CORE_CHAR_H
