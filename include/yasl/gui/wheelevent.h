// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WHEEL_EVENT_H
#define YASL_GUI_WHEEL_EVENT_H

#include "yasl/core/event.h"

#include <QWheelEvent>

void register_qwheelevent(script::Namespace n);
script::Type get_qwheelevent_type();

namespace binding
{

template<> struct make_type_t<QWheelEvent> { inline static script::Type get() { return get_qwheelevent_type(); } };

template<> inline script::Value make_value<QWheelEvent>(QWheelEvent *event, script::Engine *engine) { return make_event(event, get_qwheelevent_type(), engine); }

template<> inline QWheelEvent* value_cast<QWheelEvent*>(const script::Value & val) { return static_cast<QWheelEvent*>(get_event(val)); }
template<> inline QWheelEvent& value_cast<QWheelEvent&>(const script::Value & val) { return *static_cast<QWheelEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_WHEEL_EVENT_H
