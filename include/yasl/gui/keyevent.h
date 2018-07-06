// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_KEY_EVENT_H
#define YASL_GUI_KEY_EVENT_H

#include "yasl/core/event.h"

#include <QKeyEvent>

void register_qkeyevent(script::Namespace n);
script::Type get_qkeyevent_type();

namespace binding
{

template<> struct make_type_t<QKeyEvent> { inline static script::Type get() { return get_qkeyevent_type(); } };

template<> inline script::Value make_value<QKeyEvent>(QKeyEvent *event, script::Engine *engine) { return make_event(event, get_qkeyevent_type(), engine); }

template<> inline QKeyEvent* value_cast<QKeyEvent*>(const script::Value & val) { return static_cast<QKeyEvent*>(get_event(val)); }
template<> inline QKeyEvent& value_cast<QKeyEvent&>(const script::Value & val) { return *static_cast<QKeyEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_KEY_EVENT_H
