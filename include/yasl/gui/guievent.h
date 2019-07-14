// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_GUIEVENT_H
#define YASL_GUI_GUIEVENT_H

#include "yasl/common/types.h"
#include "yasl/core/qevent-binding.h"

#include <qevent.h>
#include "yasl/core/event.h"

namespace script {
template<> struct make_type_helper<QCloseEvent> { inline static script::Type get() { return script::Type::QCloseEvent; } };
template<> struct details::tag_resolver<QCloseEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QHideEvent> { inline static script::Type get() { return script::Type::QHideEvent; } };
template<> struct details::tag_resolver<QHideEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QKeyEvent> { inline static script::Type get() { return script::Type::QKeyEvent; } };
template<> struct details::tag_resolver<QKeyEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QMouseEvent> { inline static script::Type get() { return script::Type::QMouseEvent; } };
template<> struct details::tag_resolver<QMouseEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QMoveEvent> { inline static script::Type get() { return script::Type::QMoveEvent; } };
template<> struct details::tag_resolver<QMoveEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QPaintEvent> { inline static script::Type get() { return script::Type::QPaintEvent; } };
template<> struct details::tag_resolver<QPaintEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QResizeEvent> { inline static script::Type get() { return script::Type::QResizeEvent; } };
template<> struct details::tag_resolver<QResizeEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QShowEvent> { inline static script::Type get() { return script::Type::QShowEvent; } };
template<> struct details::tag_resolver<QShowEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QWheelEvent> { inline static script::Type get() { return script::Type::QWheelEvent; } };
template<> struct details::tag_resolver<QWheelEvent> { typedef qevent_tag tag_type; };
} // namespace script

#endif // YASL_GUI_GUIEVENT_H
