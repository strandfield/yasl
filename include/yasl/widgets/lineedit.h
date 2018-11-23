// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_LINEEDIT_H
#define YASL_WIDGETS_LINEEDIT_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QLineEdit>

namespace script { namespace bind {
template<> struct make_type_t<QLineEdit> { inline static script::Type get() { return script::Type::QLineEdit; } };
template<> struct tag_resolver<QLineEdit> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QLineEdit::ActionPosition> { inline static script::Type get() { return script::Type::QLineEditActionPosition; } };
template<> struct make_type_t<QLineEdit::EchoMode> { inline static script::Type get() { return script::Type::QLineEditEchoMode; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_LINEEDIT_H
