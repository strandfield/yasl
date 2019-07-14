// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_EVENT_H
#define YASL_CORE_EVENT_H

#include "yasl/common/types.h"
#include "yasl/core/qevent-binding.h"

#include <QEvent>

namespace script {
template<> struct make_type_helper<QChildEvent> { inline static script::Type get() { return script::Type::QChildEvent; } };
template<> struct details::tag_resolver<QChildEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QDeferredDeleteEvent> { inline static script::Type get() { return script::Type::QDeferredDeleteEvent; } };
template<> struct details::tag_resolver<QDeferredDeleteEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QDynamicPropertyChangeEvent> { inline static script::Type get() { return script::Type::QDynamicPropertyChangeEvent; } };
template<> struct details::tag_resolver<QDynamicPropertyChangeEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QEvent> { inline static script::Type get() { return script::Type::QEvent; } };
template<> struct details::tag_resolver<QEvent> { typedef qevent_tag tag_type; };
template<> struct make_type_helper<QEvent::Type> { inline static script::Type get() { return script::Type::QEventType; } };
template<> struct make_type_helper<QTimerEvent> { inline static script::Type get() { return script::Type::QTimerEvent; } };
template<> struct details::tag_resolver<QTimerEvent> { typedef qevent_tag tag_type; };
} // namespace script

#endif // YASL_CORE_EVENT_H
