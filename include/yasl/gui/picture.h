// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PICTURE_H
#define YASL_GUI_PICTURE_H

#include "yasl/binding2/types.h"

#include <QPicture>

namespace script { namespace bind {
template<> struct make_type_t<QPicture> { inline static script::Type get() { return script::Type::QPicture; } };
template<> struct make_type_t<QPictureIO> { inline static script::Type get() { return script::Type::QPictureIO; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_PICTURE_H
