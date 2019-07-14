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

  script::Value ret = engine->allocate(event_type);

  script::ThisObject self{ ret };
  self.init<script::QEventWrapper>(event);

  return ret;
}

void clear_event(script::Value & value)
{
  script::get<script::QEventWrapper>(value).p = nullptr;
}

QEvent* get_event(const script::Value & val)
{
  return script::get<script::QEventWrapper>(val).p;
}