// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_SHOW_EVENT_H
#define YASL_GUI_SHOW_EVENT_H

#include "yasl/core/event.h"

#include <QShowEvent>

void register_qshowevent(script::Namespace n);
script::Type get_qshowevent_type();

namespace binding
{

template<> struct make_type_t<QShowEvent> { inline static script::Type get() { return get_qshowevent_type(); } };

template<> inline script::Value make_value<QShowEvent>(QShowEvent *event, script::Engine *engine) { return make_event(event, get_qshowevent_type(), engine); }

template<> inline QShowEvent* value_cast<QShowEvent*>(const script::Value & val) { return static_cast<QShowEvent*>(get_event(val)); }
template<> inline QShowEvent& value_cast<QShowEvent&>(const script::Value & val) { return *static_cast<QShowEvent*>(get_event(val)); }


} // namespace binding

#endif // YASL_GUI_SHOW_EVENT_H
