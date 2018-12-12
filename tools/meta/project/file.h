// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_FILE_H
#define YASL_META_FILE_H

#include "project/namespace.h"

class File : public Namespace
{
public:
  QStringList hincludes;
  QStringList cppincludes;

public:
  File(const QString & n, Qt::CheckState c = Qt::Checked);
  ~File() = default;

  QString typeName() const override { return "file"; }
  static const NodeType staticTypeCode = NodeType::File;
  NodeType typeCode() const override { return staticTypeCode; }

  QString display() const override;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & obj);

  yaml::Value toYaml() const override;
  static QSharedPointer<Node> fromYaml(const yaml::Object & inputobj);

};
typedef QSharedPointer<File> FileRef;

#endif // YASL_META_FILE_H
