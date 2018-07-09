// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_HIDE_EVENT_H
#define YASL_GUI_HIDE_EVENT_H

#include "yasl/core/event.h"

#include <QHideEvent>

namespace binding
{

template<> struct make_type_t<QHideEvent> { inline static script::Type get() { return script::Type::QHideEvent; } };

template<> inline script::Value make_value<QHideEvent>(QHideEvent *event, script::Engine *engine) { return make_event(event, script::Type::QHideEvent, engine); }

template<> inline QHideEvent* value_cast<QHideEvent*>(const script::Value & val) { return static_cast<QHideEvent*>(get_event(val)); }
template<> inline QHideEvent& value_cast<QHideEvent&>(const script::Value & val) { return *static_cast<QHideEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_HIDE_EVENT_H
