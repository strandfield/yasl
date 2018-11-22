// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_PUSHBUTTON_H
#define YASL_WIDGETS_PUSHBUTTON_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QPushButton>

namespace script { namespace bind {
template<> struct make_type_t<QPushButton> { inline static script::Type get() { return script::Type::QPushButton; } };
template<> struct tag_resolver<QPushButton> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_PUSHBUTTON_H
