// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_PROJECT_H
#define YASL_META_PROJECT_H

#include <QSharedPointer>

#include "project/module.h"
#include "project/type.h"

namespace yaml
{
class Array;
} // namespace yaml

class Project
{
public:
  struct Types
  {
    QList<Type> fundamentals;
    QList<Type> enums;
    QList<Type> classes;
  };

public:
  QList<ModuleRef> modules;
  QMap<QString, QtVersion> includes;
  Types types;

  QJsonObject toJson() const;
  static QSharedPointer<Project> fromJson(const QJsonObject & obj);
  static QSharedPointer<Project> load(const QString & filename);

  QString toYaml() const;
  static QList<Type> typelistFromYaml(yaml::Array list);
  static QSharedPointer<Project> fromYaml(const yaml::Object & obj);

  void save(const QString & filename);

  void importSymbols(const QSharedPointer<Project> symbols);
  void removeUncheckedSymbols();
  void fetchTypes();

  bool hasEnumType(const QString & name) const;
  bool hasClassType(const QString & name) const;
  Type & getType(const QString & name);

  template<typename T>
  QSharedPointer<T> get(const QString & name)
  {
    for (const auto & e : modules)
    {
      if (e->is<T>() && e->name == name)
        return QSharedPointer<T>{e};
    }

    auto ret = QSharedPointer<T>::create(name);
    modules.append(ret);
    return ret;
  }

  static void sort(QList<Type> & types);

  int fileCount() const;
};

typedef QSharedPointer<Project> ProjectRef;

Q_DECLARE_METATYPE(QSharedPointer<Project>);

#endif // YASL_METAPROJECT_H
