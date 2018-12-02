// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PIXELFORMAT_H
#define YASL_GUI_PIXELFORMAT_H

#include "yasl/common/types.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
#include <QPixelFormat>
#endif

namespace script {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat> { inline static script::Type get() { return script::Type::QPixelFormat; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::AlphaPosition> { inline static script::Type get() { return script::Type::QPixelFormatAlphaPosition; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::AlphaPremultiplied> { inline static script::Type get() { return script::Type::QPixelFormatAlphaPremultiplied; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::AlphaUsage> { inline static script::Type get() { return script::Type::QPixelFormatAlphaUsage; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::ByteOrder> { inline static script::Type get() { return script::Type::QPixelFormatByteOrder; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::ColorModel> { inline static script::Type get() { return script::Type::QPixelFormatColorModel; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::TypeInterpretation> { inline static script::Type get() { return script::Type::QPixelFormatTypeInterpretation; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
template<> struct make_type_t<QPixelFormat::YUVLayout> { inline static script::Type get() { return script::Type::QPixelFormatYUVLayout; } };
#endif
} // namespace script

#endif // YASL_GUI_PIXELFORMAT_H
