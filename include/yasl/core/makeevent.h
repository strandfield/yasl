// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MAKEEVENT_H
#define YASL_CORE_MAKEEVENT_H

#include <script/value.h>

#include <QEvent>

script::Value make_event(QEvent *event, script::Engine *engine);
script::Value make_event(QEvent *event, const script::Type & event_type, script::Engine *engine);
void clear_event(script::Value & value);
QEvent * get_event(const script::Value & val);

#endif // YASL_CORE_MAKEEVENT_H
