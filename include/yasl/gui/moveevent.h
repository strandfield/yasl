// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_MOVE_EVENT_H
#define YASL_GUI_MOVE_EVENT_H

#include "yasl/core/event.h"

#include <QMoveEvent>

void register_qmoveevent(script::Namespace n);

namespace binding
{

template<> struct make_type_t<QMoveEvent> { inline static script::Type get() { return script::Type::QMoveEvent; } };

template<> inline script::Value make_value<QMoveEvent>(QMoveEvent *event, script::Engine *engine) { return make_event(event, script::Type::QMoveEvent, engine); }

template<> inline QMoveEvent* value_cast<QMoveEvent*>(const script::Value & val) { return static_cast<QMoveEvent*>(get_event(val)); }
template<> inline QMoveEvent& value_cast<QMoveEvent&>(const script::Value & val) { return *static_cast<QMoveEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_MOVE_EVENT_H
