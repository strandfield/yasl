// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_EVENT_UTILS_H
#define YASL_CORE_EVENT_UTILS_H

#include <QEvent>
#include <QVariant>

#include <script/namespace.h>

namespace yasl
{

class UserEvent : public QEvent
{
public:
  UserEvent(int type);
  ~UserEvent();

  QVariant data;
};

void registerEventUtils(script::Namespace core);

} // namespace yasl

#endif // YASL_CORE_EVENT_UTILS_H
