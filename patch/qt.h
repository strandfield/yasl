// Copyright (C) 2019 Vincent Chambrin
// This file is part of the libscript library
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef LIBSCRIPT_QT_H
#define LIBSCRIPT_QT_H

#include "script/function.h"

#include <QMetaType>
#include <QPointer>

#include <memory>
#include <vector>

class QEvent;
struct QMetaObject;
class QObject;

namespace script
{

namespace qt
{

struct LIBSCRIPT_API Connection
{
  script::Function signal;
  QPointer<QObject> receiver;
  script::Function slot;
};

struct LIBSCRIPT_API BindingData
{
  script::Value value;
  std::vector<Connection> connections;

  BindingData() = default;
  BindingData(const BindingData&) = default;
  ~BindingData() = default;

  static std::shared_ptr<BindingData> get(const QObject* obj);

  BindingData& operator=(const BindingData&) = default;
};

typedef std::shared_ptr<BindingData> BindingDataPtr;

struct LIBSCRIPT_API QObjectStar
{
  QObject* p;

  QObjectStar(QObject *obj = nullptr) : p(obj) {}
};

} // namespace qt

} // namespace script

Q_DECLARE_METATYPE(script::qt::BindingDataPtr);

#endif // !LIBSCRIPT_QT_H
