// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_DATETIMEEDIT_H
#define YASL_WIDGETS_DATETIMEEDIT_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QDateTimeEdit>

namespace script {
template<> struct make_type_helper<QDateEdit> { inline static script::Type get() { return script::Type::QDateEdit; } };
namespace details { template<> struct tag_resolver<QDateEdit> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QDateTimeEdit> { inline static script::Type get() { return script::Type::QDateTimeEdit; } };
namespace details { template<> struct tag_resolver<QDateTimeEdit> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QDateTimeEdit::Section> { inline static script::Type get() { return script::Type::QDateTimeEditSection; } };
template<> struct make_type_helper<QDateTimeEdit::Sections> { inline static script::Type get() { return script::Type::QDateTimeEditSections; } };
template<> struct make_type_helper<QTimeEdit> { inline static script::Type get() { return script::Type::QTimeEdit; } };
namespace details { template<> struct tag_resolver<QTimeEdit> { typedef qobject_tag tag_type; }; }
} // namespace script

#endif // YASL_WIDGETS_DATETIMEEDIT_H
