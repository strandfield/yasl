// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_KEY_EVENT_H
#define YASL_GUI_KEY_EVENT_H

#include "yasl/core/event.h"

#include <QKeyEvent>

namespace binding
{

template<> struct make_type_t<QKeyEvent> { inline static script::Type get() { return script::Type::QKeyEvent; } };
template<> struct tag_resolver<QKeyEvent> { typedef qevent_tag tag_type; };

} // namespace binding

#endif // YASL_GUI_KEY_EVENT_H
