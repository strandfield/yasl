// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_RESIZE_EVENT_H
#define YASL_GUI_RESIZE_EVENT_H

#include "yasl/core/event.h"

#include <QResizeEvent>

void register_qresizeevent(script::Namespace n);
script::Type get_qresizeevent_type();

namespace binding
{

template<> struct make_type_t<QResizeEvent> { inline static script::Type get() { return get_qresizeevent_type(); } };

template<> inline script::Value make_value<QResizeEvent>(QResizeEvent *event, script::Engine *engine) { return make_event(event, get_qresizeevent_type(), engine); }

template<> inline QResizeEvent* value_cast<QResizeEvent*>(const script::Value & val) { return static_cast<QResizeEvent*>(get_event(val)); }
template<> inline QResizeEvent& value_cast<QResizeEvent&>(const script::Value & val) { return *static_cast<QResizeEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_RESIZE_EVENT_H
