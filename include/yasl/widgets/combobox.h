// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_COMBOBOX_H
#define YASL_WIDGETS_COMBOBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QComboBox>

namespace script {
template<> struct make_type_helper<QComboBox> { inline static script::Type get() { return script::Type::QComboBox; } };
template<> struct details::tag_resolver<QComboBox> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QComboBox::InsertPolicy> { inline static script::Type get() { return script::Type::QComboBoxInsertPolicy; } };
template<> struct make_type_helper<QComboBox::SizeAdjustPolicy> { inline static script::Type get() { return script::Type::QComboBoxSizeAdjustPolicy; } };
} // namespace script

#endif // YASL_WIDGETS_COMBOBOX_H
