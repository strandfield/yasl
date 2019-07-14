// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PIXMAP_H
#define YASL_GUI_PIXMAP_H

#include "yasl/common/types.h"

#include <QPixmap>

namespace script {
template<> struct make_type_helper<QPixmap> { inline static script::Type get() { return script::Type::QPixmap; } };
} // namespace script

#endif // YASL_GUI_PIXMAP_H
