// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_GUIEVENT_H
#define YASL_GUI_GUIEVENT_H

#include "yasl/binding/types.h"
#include "yasl/core/qevent-binding.h"

#include <qevent.h>
#include "yasl/core/event.h"

namespace script { namespace bind {
template<> struct make_type_t<QCloseEvent> { inline static script::Type get() { return script::Type::QCloseEvent; } };
template<> struct tag_resolver<QCloseEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QHideEvent> { inline static script::Type get() { return script::Type::QHideEvent; } };
template<> struct tag_resolver<QHideEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QKeyEvent> { inline static script::Type get() { return script::Type::QKeyEvent; } };
template<> struct tag_resolver<QKeyEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QMouseEvent> { inline static script::Type get() { return script::Type::QMouseEvent; } };
template<> struct tag_resolver<QMouseEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QMoveEvent> { inline static script::Type get() { return script::Type::QMoveEvent; } };
template<> struct tag_resolver<QMoveEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QPaintEvent> { inline static script::Type get() { return script::Type::QPaintEvent; } };
template<> struct tag_resolver<QPaintEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QResizeEvent> { inline static script::Type get() { return script::Type::QResizeEvent; } };
template<> struct tag_resolver<QResizeEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QShowEvent> { inline static script::Type get() { return script::Type::QShowEvent; } };
template<> struct tag_resolver<QShowEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QWheelEvent> { inline static script::Type get() { return script::Type::QWheelEvent; } };
template<> struct tag_resolver<QWheelEvent> { typedef qevent_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_GUIEVENT_H
