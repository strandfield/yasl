// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_ABSTRACTBUTTON_H
#define YASL_GUI_ABSTRACTBUTTON_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QAbstractButton>

namespace binding {
template<> struct make_type_t<QAbstractButton> { inline static script::Type get() { return script::Type::QAbstractButton; } };
template<> struct tag_resolver<QAbstractButton> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_GUI_ABSTRACTBUTTON_H
