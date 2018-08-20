// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_SHOW_EVENT_H
#define YASL_GUI_SHOW_EVENT_H

#include "yasl/core/event.h"

#include <QShowEvent>

namespace binding
{

template<> struct make_type_t<QShowEvent> { inline static script::Type get() { return script::Type::QShowEvent; } };
template<> struct tag_resolver<QShowEvent> { typedef qevent_tag tag_type; };

} // namespace binding

#endif // YASL_GUI_SHOW_EVENT_H
