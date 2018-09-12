// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_COMBOBOX_H
#define YASL_WIDGETS_COMBOBOX_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QComboBox>

namespace binding {
template<> struct make_type_t<QComboBox> { inline static script::Type get() { return script::Type::QComboBox; } };
template<> struct tag_resolver<QComboBox> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QComboBox::InsertPolicy> { inline static script::Type get() { return script::Type::QComboBoxInsertPolicy; } };
template<> struct make_type_t<QComboBox::SizeAdjustPolicy> { inline static script::Type get() { return script::Type::QComboBoxSizeAdjustPolicy; } };
} // namespace binding

#endif // YASL_WIDGETS_COMBOBOX_H
