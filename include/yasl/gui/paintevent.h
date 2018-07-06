// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PAINT_EVENT_H
#define YASL_GUI_PAINT_EVENT_H

#include "yasl/core/event.h"

#include <QPaintEvent>

void register_qpaintevent(script::Namespace n);
script::Type get_qpaintevent_type();

namespace binding
{

template<> struct make_type_t<QPaintEvent> { inline static script::Type get() { return get_qpaintevent_type(); } };

template<> inline script::Value make_value<QPaintEvent>(QPaintEvent *event, script::Engine *engine) { return make_event(event, get_qpaintevent_type(), engine); }

template<> inline QPaintEvent* value_cast<QPaintEvent*>(const script::Value & val) { return static_cast<QPaintEvent*>(get_event(val)); }
template<> inline QPaintEvent& value_cast<QPaintEvent&>(const script::Value & val) { return *static_cast<QPaintEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_PAINT_EVENT_H
