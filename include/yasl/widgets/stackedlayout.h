// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_STACKEDLAYOUT_H
#define YASL_WIDGETS_STACKEDLAYOUT_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QStackedLayout>

namespace script { namespace bind {
template<> struct make_type_t<QStackedLayout> { inline static script::Type get() { return script::Type::QStackedLayout; } };
template<> struct tag_resolver<QStackedLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QStackedLayout::StackingMode> { inline static script::Type get() { return script::Type::QStackedLayoutStackingMode; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_STACKEDLAYOUT_H
