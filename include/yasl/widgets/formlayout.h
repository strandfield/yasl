// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FORMLAYOUT_H
#define YASL_WIDGETS_FORMLAYOUT_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QFormLayout>

namespace script { namespace bind {
template<> struct make_type_t<QFormLayout> { inline static script::Type get() { return script::Type::QFormLayout; } };
template<> struct tag_resolver<QFormLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFormLayout::FieldGrowthPolicy> { inline static script::Type get() { return script::Type::QFormLayoutFieldGrowthPolicy; } };
template<> struct make_type_t<QFormLayout::ItemRole> { inline static script::Type get() { return script::Type::QFormLayoutItemRole; } };
template<> struct make_type_t<QFormLayout::RowWrapPolicy> { inline static script::Type get() { return script::Type::QFormLayoutRowWrapPolicy; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_FORMLAYOUT_H
