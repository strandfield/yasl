// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FORMLAYOUT_H
#define YASL_WIDGETS_FORMLAYOUT_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFormLayout>

namespace script {
template<> struct make_type_helper<QFormLayout> { inline static script::Type get() { return script::Type::QFormLayout; } };
namespace details { template<> struct tag_resolver<QFormLayout> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QFormLayout::FieldGrowthPolicy> { inline static script::Type get() { return script::Type::QFormLayoutFieldGrowthPolicy; } };
template<> struct make_type_helper<QFormLayout::ItemRole> { inline static script::Type get() { return script::Type::QFormLayoutItemRole; } };
template<> struct make_type_helper<QFormLayout::RowWrapPolicy> { inline static script::Type get() { return script::Type::QFormLayoutRowWrapPolicy; } };
} // namespace script

#endif // YASL_WIDGETS_FORMLAYOUT_H
