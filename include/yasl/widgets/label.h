// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_LABEL_H
#define YASL_WIDGETS_LABEL_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QLabel>

namespace script {
template<> struct make_type_helper<QLabel> { inline static script::Type get() { return script::Type::QLabel; } };
template<> struct details::tag_resolver<QLabel> { typedef qobject_tag tag_type; };
} // namespace script

#endif // YASL_WIDGETS_LABEL_H
