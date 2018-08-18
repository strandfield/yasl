// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/urlquery.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/url.h"
#include "yasl/core/urlquery.h"

#include <script/classbuilder.h>

static void register_url_query_class(script::Namespace ns)
{
  using namespace script;

  Class url_query = ns.Class("UrlQuery").setId(script::Type::QUrlQuery).get();

  binding::Class<QUrlQuery> binder{ url_query };

  // QUrlQuery();
  binder.ctors().add_default();
  // QUrlQuery(const QUrl &);
  binder.ctors().add<const QUrl &>();
  // QUrlQuery(const QString &);
  binder.ctors().add<const QString &>();
  // QUrlQuery(const QUrlQuery &);
  binder.ctors().add<const QUrlQuery &>();
  // QUrlQuery & operator=(const QUrlQuery &);
  binder.operators().assign<const QUrlQuery &>();
  // QUrlQuery & operator=(QUrlQuery &&);
  binder.operators().assign<QUrlQuery &&>();
  // ~QUrlQuery();
  binder.add_dtor();
  // bool operator==(const QUrlQuery &) const;
  binder.operators().eq<const QUrlQuery &>();
  // bool operator!=(const QUrlQuery &) const;
  binder.operators().neq<const QUrlQuery &>();
  // void swap(QUrlQuery &);
  binder.add_void_fun<QUrlQuery &, &QUrlQuery::swap>("swap");
  // bool isEmpty() const;
  binder.add_fun<bool, &QUrlQuery::isEmpty>("isEmpty");
  // bool isDetached() const;
  binder.add_fun<bool, &QUrlQuery::isDetached>("isDetached");
  // void clear();
  binder.add_void_fun<&QUrlQuery::clear>("clear");
  // QString query(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrlQuery::query>("query");
  // void setQuery(const QString &);
  binder.add_void_fun<const QString &, &QUrlQuery::setQuery>("setQuery");
  // QString toString(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrlQuery::toString>("toString");
  // void setQueryDelimiters(QChar, QChar);
  binder.add_void_fun<QChar, QChar, &QUrlQuery::setQueryDelimiters>("setQueryDelimiters");
  // QChar queryValueDelimiter() const;
  binder.add_fun<QChar, &QUrlQuery::queryValueDelimiter>("queryValueDelimiter");
  // QChar queryPairDelimiter() const;
  binder.add_fun<QChar, &QUrlQuery::queryPairDelimiter>("queryPairDelimiter");
  // void setQueryItems(const QList<QPair<QString, QString> > &);
  /// TODO: void setQueryItems(const QList<QPair<QString, QString> > &);
  // QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions) const;
  /// TODO: QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions) const;
  // bool hasQueryItem(const QString &) const;
  binder.add_fun<bool, const QString &, &QUrlQuery::hasQueryItem>("hasQueryItem");
  // void addQueryItem(const QString &, const QString &);
  binder.add_void_fun<const QString &, const QString &, &QUrlQuery::addQueryItem>("addQueryItem");
  // void removeQueryItem(const QString &);
  binder.add_void_fun<const QString &, &QUrlQuery::removeQueryItem>("removeQueryItem");
  // QString queryItemValue(const QString &, QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, const QString &, QUrl::ComponentFormattingOptions, &QUrlQuery::queryItemValue>("queryItemValue");
  // QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions) const;
  /// TODO: QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions) const;
  // void removeAllQueryItems(const QString &);
  binder.add_void_fun<const QString &, &QUrlQuery::removeAllQueryItems>("removeAllQueryItems");
  // static QChar defaultQueryValueDelimiter();
  binder.add_static<QChar, &QUrlQuery::defaultQueryValueDelimiter>("defaultQueryValueDelimiter");
  // static QChar defaultQueryPairDelimiter();
  binder.add_static<QChar, &QUrlQuery::defaultQueryPairDelimiter>("defaultQueryPairDelimiter");
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
  binder.add_fun<uint, const QUrlQuery &, uint, &qHash>("qHash");
  // void swap(QUrlQuery &, QUrlQuery &);
  binder.add_void_fun<QUrlQuery &, QUrlQuery &, &swap>("swap");
}

