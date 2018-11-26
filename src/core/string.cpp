// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/string.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/genericvarianthandler.h"
#include "yasl/common/listspecializations.h"

#include "yasl/core/enums.h"

#include <script/namespace.h>

QStringList filter(const QStringList & list, const QString & filter, Qt::CaseSensitivity cs)
{
  return list.filter(filter, cs);
}

QString join(const QStringList & list, const QString & sep)
{
  return list.join(sep);
}

int removeDuplicates(QStringList & list)
{
  return list.removeDuplicates();
}

void replaceInStrings(QStringList & list, const QString & before, const QString & after, Qt::CaseSensitivity cs)
{
  list.replaceInStrings(before, after, cs);
}

void sort(QStringList & list, Qt::CaseSensitivity cs)
{
  list.sort(cs);
}


void register_stringlist_class(script::Namespace n)
{
  using namespace script;

  register_proxy_specialization<QString>(n.engine()->getTemplate(Engine::ProxyTemplate), Type::ProxyQString);
  register_list_specialization<QString>(n.engine(), Type::QListQString);

  Class stringlist = n.newClass("StringList").setId(Type::QStringList).setBase(Type::QListQString).get();

  bind::default_constructor<QStringList>(stringlist).get();
  bind::copy_constructor<QStringList>(stringlist).get();
  bind::constructor<QStringList, const QString &>(stringlist).get();
  bind::constructor<QStringList, const QList<QString> &>(stringlist).get();
  bind::destructor<QStringList>(stringlist).get();

  // bool contains(const QString & str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
  bind::member_function<QStringList, bool, const QString &, Qt::CaseSensitivity, &QStringList::contains>(stringlist, "contains")
    .apply(bind::default_arguments(Qt::CaseSensitive)).get();
  // QStringList filter(const QString & filter, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
  bind::fn_as_memfn<QStringList, QStringList, const QString &, Qt::CaseSensitivity, &filter>(stringlist, "filter")
    .apply(bind::default_arguments(Qt::CaseSensitive)).get();
  // QString join(const QString & sep) const;
  bind::fn_as_memfn<QStringList, QString, const QString &, &join>(stringlist, "join").get();
  // int removeDuplicates()
  bind::fn_as_memfn<QStringList, int, &removeDuplicates>(stringlist, "removeDuplicates").get();
  // void replaceInStrings(const QString & before, const QString & after, Qt::CaseSensitivity cs = Qt::CaseSensitive)
  bind::void_fn_as_memfn<QStringList, const QString &, const QString &, Qt::CaseSensitivity, &replaceInStrings>(stringlist, "replaceInStrings")
    .apply(bind::default_arguments(Qt::CaseSensitive)).get();
  // void sort(Qt::CaseSensitivity cs = Qt::CaseSensitive);
  bind::void_fn_as_memfn<QStringList, Qt::CaseSensitivity, &sort>(stringlist, "sort")
    .apply(bind::default_arguments(Qt::CaseSensitive)).get();
}
