// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILE_H
#define YASL_CORE_FILE_H

#include "yasl/core/filedevice.h"

#include <QFile>

void register_file_class(script::Namespace n);
script::Type get_file_type();

namespace binding
{

template<> struct make_type_t<QFile> { inline static script::Type get() { return get_file_type(); } };

template<> inline QFile* value_cast<QFile*>(const script::Value & val)
{
  return qobject_cast<QFile*>(value_cast<QObject*>(val));
}

template<> inline script::Value make_value(QFile *f, script::Engine *e) = delete;

} // namespace binding

#endif // YASL_CORE_FILE_H
