// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_EXPOSE_H
#define YASL_UTILS_EXPOSE_H

#include <script/function.h>
#include <script/value.h>

#include <QPointer>
#include <QVariant>

namespace binding
{

struct Connection
{
  script::Function signal;
  QPointer<QObject> receiver;
  script::Function slot;
};

struct BindingData
{
  script::Value value;
  QList<Connection> connections;

  BindingData() = default;
  BindingData(const BindingData &) = default;
  ~BindingData() = default;

  static BindingData get(QObject *obj);
  static void set(QObject *obj, const BindingData & d);

  BindingData & operator=(const BindingData &) = default;
};

} // namespace binding

Q_DECLARE_METATYPE(binding::BindingData);

void expose(QObject *obj, script::Value val);
script::Value expose(QObject *obj);

#endif // YASL_UTILS_EXPOSE_H
