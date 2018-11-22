// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ABSTRACTBUTTON_H
#define YASL_WIDGETS_ABSTRACTBUTTON_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QAbstractButton>

namespace script { namespace bind {
template<> struct make_type_t<QAbstractButton> { inline static script::Type get() { return script::Type::QAbstractButton; } };
template<> struct tag_resolver<QAbstractButton> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_ABSTRACTBUTTON_H
