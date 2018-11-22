// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FONTCOMBOBOX_H
#define YASL_WIDGETS_FONTCOMBOBOX_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QFontComboBox>

namespace script { namespace bind {
template<> struct make_type_t<QFontComboBox> { inline static script::Type get() { return script::Type::QFontComboBox; } };
template<> struct tag_resolver<QFontComboBox> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFontComboBox::FontFilter> { inline static script::Type get() { return script::Type::QFontComboBoxFontFilter; } };
template<> struct make_type_t<QFontComboBox::FontFilters> { inline static script::Type get() { return script::Type::QFontComboBoxFontFilters; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_FONTCOMBOBOX_H
