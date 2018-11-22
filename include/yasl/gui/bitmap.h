// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_BITMAP_H
#define YASL_GUI_BITMAP_H

#include "yasl/binding2/types.h"

#include <QBitmap>

namespace script { namespace bind {
template<> struct make_type_t<QBitmap> { inline static script::Type get() { return script::Type::QBitmap; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_BITMAP_H
