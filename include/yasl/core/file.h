// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILE_H
#define YASL_CORE_FILE_H

#include "yasl/core/filedevice.h"

#include <QFile>

namespace binding
{

template<> struct tag_resolver<QFile> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFile> { inline static script::Type get() { return script::Type::QFile; } };
//template<> struct storage_type<QFile> { typedef QFile* type; };
//template<> inline QFile* get<QFile>(const script::Value & val) { return qobject_cast<QFile*>(val.toQObject()); }
template<> inline script::Value make_value(QFile *f, script::Engine *e) = delete;

} // namespace binding

#endif // YASL_CORE_FILE_H
