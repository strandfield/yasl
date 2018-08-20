// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_EVENT_H
#define YASL_CORE_EVENT_H

#include "yasl/binding/types.h"
#include "yasl/core/qevent-binding.h"

#include <QEvent>

namespace binding {
template<> struct make_type_t<QChildEvent> { inline static script::Type get() { return script::Type::QChildEvent; } };
template<> struct tag_resolver<QChildEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QDeferredDeleteEvent> { inline static script::Type get() { return script::Type::QDeferredDeleteEvent; } };
template<> struct tag_resolver<QDeferredDeleteEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QDynamicPropertyChangeEvent> { inline static script::Type get() { return script::Type::QDynamicPropertyChangeEvent; } };
template<> struct tag_resolver<QDynamicPropertyChangeEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QEvent> { inline static script::Type get() { return script::Type::QEvent; } };
template<> struct tag_resolver<QEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_t<QEvent::Type> { inline static script::Type get() { return script::Type::QEventType; } };
template<> struct make_type_t<QTimerEvent> { inline static script::Type get() { return script::Type::QTimerEvent; } };
template<> struct tag_resolver<QTimerEvent> { typedef qevent_tag tag_type; };
} // namespace binding

#endif // YASL_CORE_EVENT_H
