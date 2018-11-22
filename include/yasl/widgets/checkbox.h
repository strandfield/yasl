// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_CHECKBOX_H
#define YASL_WIDGETS_CHECKBOX_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QCheckBox>

namespace script { namespace bind {
template<> struct make_type_t<QCheckBox> { inline static script::Type get() { return script::Type::QCheckBox; } };
template<> struct tag_resolver<QCheckBox> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_CHECKBOX_H
