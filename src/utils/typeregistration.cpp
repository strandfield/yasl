// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/typeregistration.h"

#include "yasl/application.h"

void register_object_type(const QMetaObject *obj, const script::Type & type)
{
  qApp->registerObjectType(obj, type);
}
