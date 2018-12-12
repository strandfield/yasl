// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_MODULE_H
#define YASL_META_MODULE_H

#include "project/node.h"

class Module : public Node
{
public:
  QList<NodeRef> elements;

public:
  Module(const QString & n, Qt::CheckState c = Qt::Checked);
  ~Module() = default;

  QString typeName() const override { return "module"; }
  static const NodeType staticTypeCode = NodeType::Module;
  NodeType typeCode() const override { return staticTypeCode; }

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & obj);

  yaml::Value toYaml() const override;
  static QSharedPointer<Module> fromYaml(const yaml::Object & obj);

  template<typename T>
  QSharedPointer<T> get(const QString & name)
  {
    for (const auto & e : elements)
    {
      if (e->is<T>() && e->name == name)
        return qSharedPointerCast<T>(e);
    }

    auto ret = QSharedPointer<T>::create(name);
    elements.append(ret);
    return ret;
  }

};
typedef QSharedPointer<Module> ModuleRef;

#endif // YASL_META_MODULE_H
