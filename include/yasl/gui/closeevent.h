// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_CLOSE_EVENT_H
#define YASL_GUI_CLOSE_EVENT_H

#include "yasl/core/event.h"

#include <QCloseEvent>

void register_qcloseevent(script::Namespace n);
script::Type get_qcloseevent_type();

namespace binding
{

template<> struct make_type_t<QCloseEvent> { inline static script::Type get() { return get_qcloseevent_type(); } };

template<> inline script::Value make_value<QCloseEvent>(QCloseEvent *event, script::Engine *engine) { return make_event(event, get_qcloseevent_type(), engine); }

template<> inline QCloseEvent* value_cast<QCloseEvent*>(const script::Value & val) { return static_cast<QCloseEvent*>(get_event(val)); }
template<> inline QCloseEvent& value_cast<QCloseEvent&>(const script::Value & val) { return *static_cast<QCloseEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_CLOSE_EVENT_H
