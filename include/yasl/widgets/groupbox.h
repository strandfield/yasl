// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_GROUPBOX_H
#define YASL_WIDGETS_GROUPBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QGroupBox>

namespace script {
template<> struct make_type_helper<QGroupBox> { inline static script::Type get() { return script::Type::QGroupBox; } };
template<> struct details::tag_resolver<QGroupBox> { typedef qobject_tag tag_type; };
} // namespace script

#endif // YASL_WIDGETS_GROUPBOX_H
