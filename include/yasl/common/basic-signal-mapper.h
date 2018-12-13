// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_BASIC_SIGNAL_MAPPER_H
#define YASL_COMMONS_BASIC_SIGNAL_MAPPER_H

#include "yasl/common/signal-utils.h"

namespace yasl
{

class BasicSignalMapper : public SignalMapper
{
  Q_OBJECT
public:
  BasicSignalMapper() = default;
  BasicSignalMapper(QObject *r, const script::Function & slot);
  ~BasicSignalMapper();

  SignalMapper* clone(QObject *r, const script::Function & slot) const override;

public Q_SLOTS:
  void activate();
  void activate(bool);
  void activate(int);
  void activate(int, qint64);
  void activate(const QString &);
  void activate(qint64);
};

} // namespace yasl

#endif // YASL_COMMONS_BASIC_SIGNAL_MAPPER_H
