// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_MOVE_EVENT_H
#define YASL_GUI_MOVE_EVENT_H

#include "yasl/core/event.h"

#include <QMoveEvent>

void register_qmoveevent(script::Namespace n);
script::Type get_qmoveevent_type();

namespace binding
{

template<> struct make_type_t<QMoveEvent> { inline static script::Type get() { return get_qmoveevent_type(); } };

template<> inline script::Value make_value<QMoveEvent>(QMoveEvent *event, script::Engine *engine) { return make_event(event, get_qmoveevent_type(), engine); }

template<> inline QMoveEvent* value_cast<QMoveEvent*>(const script::Value & val) { return static_cast<QMoveEvent*>(get_event(val)); }
template<> inline QMoveEvent& value_cast<QMoveEvent&>(const script::Value & val) { return *static_cast<QMoveEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_MOVE_EVENT_H
