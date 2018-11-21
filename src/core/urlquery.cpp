// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/urlquery.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/url.h"
#include "yasl/core/urlquery.h"

#include <script/classbuilder.h>

static void register_url_query_class(script::Namespace ns)
{
  using namespace script;

  Class url_query = ns.newClass("UrlQuery").setId(script::Type::QUrlQuery).get();

  binding::ClassBinder<QUrlQuery> binder{ url_query };

  // QUrlQuery();
  binder.default_ctor().create();
  // QUrlQuery(const QUrl &);
  binder.ctor<const QUrl &>().create();
  // QUrlQuery(const QString &);
  binder.ctor<const QString &>().create();
  // QUrlQuery(const QUrlQuery &);
  binder.ctor<const QUrlQuery &>().create();
  // QUrlQuery & operator=(const QUrlQuery &);
  binder.operators().assign<const QUrlQuery &>();
  // QUrlQuery & operator=(QUrlQuery &&);
  binder.operators().assign<QUrlQuery &&>();
  // ~QUrlQuery();
  binder.dtor().create();
  // bool operator==(const QUrlQuery &) const;
  binder.operators().eq<const QUrlQuery &>();
  // bool operator!=(const QUrlQuery &) const;
  binder.operators().neq<const QUrlQuery &>();
  // void swap(QUrlQuery &);
  binder.void_fun<QUrlQuery &, &QUrlQuery::swap>("swap").create();
  // bool isEmpty() const;
  binder.fun<bool, &QUrlQuery::isEmpty>("isEmpty").create();
  // bool isDetached() const;
  binder.fun<bool, &QUrlQuery::isDetached>("isDetached").create();
  // void clear();
  binder.void_fun<&QUrlQuery::clear>("clear").create();
  // QString query(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrlQuery::query>("query")
    .apply(binding::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setQuery(const QString &);
  binder.void_fun<const QString &, &QUrlQuery::setQuery>("setQuery").create();
  // QString toString(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrlQuery::toString>("toString")
    .apply(binding::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setQueryDelimiters(QChar, QChar);
  binder.void_fun<QChar, QChar, &QUrlQuery::setQueryDelimiters>("setQueryDelimiters").create();
  // QChar queryValueDelimiter() const;
  binder.fun<QChar, &QUrlQuery::queryValueDelimiter>("queryValueDelimiter").create();
  // QChar queryPairDelimiter() const;
  binder.fun<QChar, &QUrlQuery::queryPairDelimiter>("queryPairDelimiter").create();
  // void setQueryItems(const QList<QPair<QString, QString> > &);
  /// TODO: void setQueryItems(const QList<QPair<QString, QString> > &);
  // QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions) const;
  /// TODO: QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions) const;
  // bool hasQueryItem(const QString &) const;
  binder.fun<bool, const QString &, &QUrlQuery::hasQueryItem>("hasQueryItem").create();
  // void addQueryItem(const QString &, const QString &);
  binder.void_fun<const QString &, const QString &, &QUrlQuery::addQueryItem>("addQueryItem").create();
  // void removeQueryItem(const QString &);
  binder.void_fun<const QString &, &QUrlQuery::removeQueryItem>("removeQueryItem").create();
  // QString queryItemValue(const QString &, QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, const QString &, QUrl::ComponentFormattingOptions, &QUrlQuery::queryItemValue>("queryItemValue")
    .apply(binding::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions) const;
  /// TODO: QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions) const;
  // void removeAllQueryItems(const QString &);
  binder.void_fun<const QString &, &QUrlQuery::removeAllQueryItems>("removeAllQueryItems").create();
  // static QChar defaultQueryValueDelimiter();
  binder.static_fun<QChar, &QUrlQuery::defaultQueryValueDelimiter>("defaultQueryValueDelimiter").create();
  // static QChar defaultQueryPairDelimiter();
  binder.static_fun<QChar, &QUrlQuery::defaultQueryPairDelimiter>("defaultQueryPairDelimiter").create();
  // QUrlQuery::DataPtr & data_ptr();
  /// TODO: QUrlQuery::DataPtr & data_ptr();
}


void register_urlquery_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_url_query_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QUrlQuery &, uint);
  binder.fun<uint, const QUrlQuery &, uint, &qHash>("qHash").create();
  // void swap(QUrlQuery &, QUrlQuery &);
  binder.void_fun<QUrlQuery &, QUrlQuery &, &swap>("swap").create();
}

