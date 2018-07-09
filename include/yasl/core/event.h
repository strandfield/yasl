// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_EVENT_H
#define YASL_CORE_EVENT_H

#include "yasl/binding/values.h"
#include "yasl/binding/enum.h"

#include <QEvent>

script::Value make_event(QEvent *event, script::Engine *engine);
script::Value make_event(QEvent *event, const script::Type & event_type, script::Engine *engine);
void clear_event(script::Value & value);
QEvent * get_event(const script::Value & val);

namespace binding
{

template<> struct make_type_t<QEvent> { inline static script::Type get() { return script::Type::QEvent; } };
template<> struct make_type_t<QEvent::Type> { inline static script::Type get() { return script::Type::QEventType; } };

template<> inline script::Value make_value<QEvent>(QEvent *event, script::Engine *engine) { return make_event(event, engine); }

template<> inline QEvent* value_cast<QEvent*>(const script::Value & val) { return get_event(val); }
template<> inline QEvent& value_cast<QEvent&>(const script::Value & val) { return *get_event(val); }

} // namespace binding

#endif // YASL_CORE_EVENT_H
