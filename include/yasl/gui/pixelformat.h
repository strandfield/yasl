// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PIXELFORMAT_H
#define YASL_GUI_PIXELFORMAT_H

#include "yasl/binding2/types.h"

#include <QPixelFormat>

namespace script { namespace bind {
template<> struct make_type_t<QPixelFormat> { inline static script::Type get() { return script::Type::QPixelFormat; } };
template<> struct make_type_t<QPixelFormat::AlphaPosition> { inline static script::Type get() { return script::Type::QPixelFormatAlphaPosition; } };
template<> struct make_type_t<QPixelFormat::AlphaPremultiplied> { inline static script::Type get() { return script::Type::QPixelFormatAlphaPremultiplied; } };
template<> struct make_type_t<QPixelFormat::AlphaUsage> { inline static script::Type get() { return script::Type::QPixelFormatAlphaUsage; } };
template<> struct make_type_t<QPixelFormat::ByteOrder> { inline static script::Type get() { return script::Type::QPixelFormatByteOrder; } };
template<> struct make_type_t<QPixelFormat::ColorModel> { inline static script::Type get() { return script::Type::QPixelFormatColorModel; } };
template<> struct make_type_t<QPixelFormat::TypeInterpretation> { inline static script::Type get() { return script::Type::QPixelFormatTypeInterpretation; } };
template<> struct make_type_t<QPixelFormat::YUVLayout> { inline static script::Type get() { return script::Type::QPixelFormatYUVLayout; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_PIXELFORMAT_H
