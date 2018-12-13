// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/basic-signal-mapper.h"

#include <script/engine.h>

namespace yasl
{

BasicSignalMapper::BasicSignalMapper(QObject *r, const script::Function & slot)
  : SignalMapper(r, slot)
{

}

BasicSignalMapper::~BasicSignalMapper()
{

}

SignalMapper* BasicSignalMapper::clone(QObject *r, const script::Function & slot) const
{
  return new BasicSignalMapper{ r, slot };
}

void BasicSignalMapper::activate()
{
  invoke({});
}

void BasicSignalMapper::activate(bool arg)
{
  script::Value v = engine()->newBool(arg);
  invoke({ v });
  engine()->destroy(v);
}

void BasicSignalMapper::activate(int n)
{
  script::Value v = engine()->newInt(n);
  invoke({ v });
  engine()->destroy(v);
}

void BasicSignalMapper::activate(int arg1, qint64 arg2)
{
  script::Value v1 = engine()->newInt(arg1);
  script::Value v2 = engine()->newInt(arg2);

  invoke({ v1, v2 });

  engine()->destroy(v2);
  engine()->destroy(v1);
}

void BasicSignalMapper::activate(const QString & arg1)
{
  script::Value v1 = engine()->newString(arg1);

  invoke({ v1 });

  engine()->destroy(v1);
}

void BasicSignalMapper::activate(qint64 arg1)
{
  script::Value v1 = engine()->newInt(arg1);

  invoke({ v1 });

  engine()->destroy(v1);
}

} // namespace yasl
