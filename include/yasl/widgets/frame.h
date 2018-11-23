// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FRAME_H
#define YASL_WIDGETS_FRAME_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QFrame>

namespace script { namespace bind {
template<> struct make_type_t<QFrame> { inline static script::Type get() { return script::Type::QFrame; } };
template<> struct tag_resolver<QFrame> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFrame::Shadow> { inline static script::Type get() { return script::Type::QFrameShadow; } };
template<> struct make_type_t<QFrame::Shape> { inline static script::Type get() { return script::Type::QFrameShape; } };
template<> struct make_type_t<QFrame::StyleMask> { inline static script::Type get() { return script::Type::QFrameStyleMask; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_FRAME_H
