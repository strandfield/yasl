// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_RADIOBUTTON_H
#define YASL_WIDGETS_RADIOBUTTON_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QRadioButton>

namespace script {
template<> struct make_type_helper<QRadioButton> { inline static script::Type get() { return script::Type::QRadioButton; } };
namespace details { template<> struct tag_resolver<QRadioButton> { typedef qobject_tag tag_type; }; }
} // namespace script

#endif // YASL_WIDGETS_RADIOBUTTON_H
