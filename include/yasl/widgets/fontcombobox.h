// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FONTCOMBOBOX_H
#define YASL_WIDGETS_FONTCOMBOBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFontComboBox>

namespace script {
template<> struct make_type_helper<QFontComboBox> { inline static script::Type get() { return script::Type::QFontComboBox; } };
namespace details { template<> struct tag_resolver<QFontComboBox> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QFontComboBox::FontFilter> { inline static script::Type get() { return script::Type::QFontComboBoxFontFilter; } };
template<> struct make_type_helper<QFontComboBox::FontFilters> { inline static script::Type get() { return script::Type::QFontComboBoxFontFilters; } };
} // namespace script

#endif // YASL_WIDGETS_FONTCOMBOBOX_H
