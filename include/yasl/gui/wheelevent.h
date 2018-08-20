// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WHEEL_EVENT_H
#define YASL_GUI_WHEEL_EVENT_H

#include "yasl/core/event.h"

#include <QWheelEvent>

namespace binding
{

template<> struct make_type_t<QWheelEvent> { inline static script::Type get() { return script::Type::QWheelEvent; } };
template<> struct tag_resolver<QWheelEvent> { typedef qevent_tag tag_type; };

} // namespace binding

#endif // YASL_GUI_WHEEL_EVENT_H
