// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/expose.h"

#include "yasl/application.h"


binding::BindingData binding::BindingData::get(QObject *obj)
{
  return obj->property("_yasl_data_").value<binding::BindingData>();
}

void binding::BindingData::set(QObject *obj, const BindingData & d)
{
  obj->setProperty("_yasl_data_", QVariant::fromValue(d));
}

void expose(QObject *obj, script::Value val)
{
  obj->setProperty("_yasl_data_", QVariant::fromValue(binding::BindingData{ val }));
}

script::Value expose(QObject *obj)
{
  return qApp->expose(obj);
}

