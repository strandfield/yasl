// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_TYPE_REGISTRATION_H
#define YASL_UTILS_TYPE_REGISTRATION_H

#include <script/types.h>

struct QMetaObject;

void register_object_type(const QMetaObject *obj, const script::Type & type);

#endif // YASL_UTILS_TYPE_REGISTRATION_H
