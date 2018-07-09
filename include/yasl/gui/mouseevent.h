// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_MOUSE_EVENT_H
#define YASL_GUI_MOUSE_EVENT_H

#include "yasl/core/event.h"

#include <QMouseEvent>

namespace binding
{

template<> struct make_type_t<QMouseEvent> { inline static script::Type get() { return script::Type::QMouseEvent; } };

template<> inline script::Value make_value<QMouseEvent>(QMouseEvent *event, script::Engine *engine) { return make_event(event, script::Type::QMouseEvent, engine); }

template<> inline QMouseEvent* value_cast<QMouseEvent*>(const script::Value & val) { return static_cast<QMouseEvent*>(get_event(val)); }
template<> inline QMouseEvent& value_cast<QMouseEvent&>(const script::Value & val) { return *static_cast<QMouseEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_MOUSE_EVENT_H
