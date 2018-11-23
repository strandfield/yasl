// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_DIAL_H
#define YASL_WIDGETS_DIAL_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QDial>

namespace script { namespace bind {
template<> struct make_type_t<QDial> { inline static script::Type get() { return script::Type::QDial; } };
template<> struct tag_resolver<QDial> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_DIAL_H
