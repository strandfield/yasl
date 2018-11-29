// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_YAML_PARSER_H
#define YASL_META_YAML_PARSER_H

#include "yaml/value.h"

#include <QTextStream>

namespace yaml
{

class Parser
{
private:
  QTextStream *stream;
  QString currentline;
  int currentindent;
  bool done;

public:
  Parser();

  yaml::Value parse(QTextStream & stream);

private:
  bool hasNext() const;
  QString getNext();
  void nextOrDone();

  yaml::Value parseValue(const int indent);

  static QStringList extractFields(const QString & str);
  static yaml::Object parseObject(QString str);
  static yaml::Array parseArray(QString str);
  static yaml::Value parseString(QString str);

  static int computeIndent(const QString & str);
  static int readPropertyName(const QString & str, int indent);
};

} // namespace yaml

#endif // YASL_META_YAML_PARSER_H