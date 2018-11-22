// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MIMEDATA_H
#define YASL_CORE_MIMEDATA_H

#include "yasl/binding2/values.h"

#include <QMimeData>

namespace script
{

namespace bind
{
template<> inline script::Value make_value(const QMimeData *obj, script::Engine *e)
{
  throw std::runtime_error{ "Not implemented" };
}
} // namespace bind
} // namespace script

#endif // YASL_CORE_MIMEDATA_H
