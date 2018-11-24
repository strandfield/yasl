// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VALIDATOR_H
#define YASL_GUI_VALIDATOR_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QValidator>

namespace script {
template<> struct make_type_t<QDoubleValidator> { inline static script::Type get() { return script::Type::QDoubleValidator; } };
template<> struct tag_resolver<QDoubleValidator> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QDoubleValidator::Notation> { inline static script::Type get() { return script::Type::QDoubleValidatorNotation; } };
template<> struct make_type_t<QIntValidator> { inline static script::Type get() { return script::Type::QIntValidator; } };
template<> struct tag_resolver<QIntValidator> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QRegularExpressionValidator> { inline static script::Type get() { return script::Type::QRegularExpressionValidator; } };
template<> struct tag_resolver<QRegularExpressionValidator> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QValidator> { inline static script::Type get() { return script::Type::QValidator; } };
template<> struct tag_resolver<QValidator> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QValidator::State> { inline static script::Type get() { return script::Type::QValidatorState; } };
} // namespace script

#endif // YASL_GUI_VALIDATOR_H
