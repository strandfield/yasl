// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_QTVERSION_H
#define YASL_META_QTVERSION_H

#include <QString>

class QtVersion
{
public:
  QtVersion()
    : major(0), minor(0), patch(0)
  { }

  QtVersion(const QtVersion &) = default;

  QtVersion(int ma, int mi, int pa = 0)
    : major(ma), minor(mi), patch(pa) {}

  char major;
  char minor;
  char patch;

  QString toString() const;
  static QtVersion fromString(const QString & str);

  inline bool isNull() const { return major == 0 && minor == 0 && patch == 0; }
};

#endif // YASL_META_QTVERSION_H
