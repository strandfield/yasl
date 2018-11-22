// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_DATETIMEEDIT_H
#define YASL_WIDGETS_DATETIMEEDIT_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QDateTimeEdit>

namespace script { namespace bind {
template<> struct make_type_t<QDateEdit> { inline static script::Type get() { return script::Type::QDateEdit; } };
template<> struct tag_resolver<QDateEdit> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QDateTimeEdit> { inline static script::Type get() { return script::Type::QDateTimeEdit; } };
template<> struct tag_resolver<QDateTimeEdit> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QDateTimeEdit::Section> { inline static script::Type get() { return script::Type::QDateTimeEditSection; } };
template<> struct make_type_t<QDateTimeEdit::Sections> { inline static script::Type get() { return script::Type::QDateTimeEditSections; } };
template<> struct make_type_t<QTimeEdit> { inline static script::Type get() { return script::Type::QTimeEdit; } };
template<> struct tag_resolver<QTimeEdit> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_DATETIMEEDIT_H
