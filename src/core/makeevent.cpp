// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/makeevent.h"

#include <script/engine.h>

script::Value make_event(QEvent *event, script::Engine *engine)
{
  return make_event(event, script::Type::QEvent, engine);
}

script::Value make_event(QEvent *event, const script::Type & event_type, script::Engine *engine)
{
  using namespace script;

  return engine->construct(event_type, [event](script::Value & val) {
    val.setPtr(event);
  });
}

void clear_event(script::Value & value)
{
  value.setPtr(nullptr);
}

QEvent * get_event(const script::Value & val)
{
  return static_cast<QEvent*>(val.getPtr());
}