// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_IMAGE_H
#define YASL_GUI_IMAGE_H

#include "yasl/common/types.h"

#include <QImage>

namespace script {
template<> struct make_type_helper<QImage> { inline static script::Type get() { return script::Type::QImage; } };
template<> struct make_type_helper<QImage::Format> { inline static script::Type get() { return script::Type::QImageFormat; } };
template<> struct make_type_helper<QImage::InvertMode> { inline static script::Type get() { return script::Type::QImageInvertMode; } };
} // namespace script

#endif // YASL_GUI_IMAGE_H
