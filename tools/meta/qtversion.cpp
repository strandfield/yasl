// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "qtversion.h"

#include <QStringList>

QString QtVersion::toString() const
{
  if (isNull())
    return QString{};
  return QString("%1.%2.%3").arg(int(major)).arg(int(minor)).arg(int(patch));
}

QtVersion QtVersion::fromString(const QString & str)
{
  if (str.isEmpty())
    return QtVersion{};

  QStringList list = str.split('.');
  return QtVersion{ list.front().toInt(), list.size() > 1 ? list.at(1).toInt() : 0, list.size() > 2 ? list.back().toInt() : 0 };
}
