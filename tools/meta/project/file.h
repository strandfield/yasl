// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_FILE_H
#define YASL_META_FILE_H

#include "project/namespace.h"

class File : public Namespace
{
public:
  File(const QString & n, Qt::CheckState c = Qt::Checked);
  ~File() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & obj);

  QString typeCode() const override { return staticTypeCode; }

};
typedef QSharedPointer<File> FileRef;

#endif // YASL_META_FILE_H
