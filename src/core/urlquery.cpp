// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/urlquery.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/url.h"
#include "yasl/core/urlquery.h"

#include <script/classbuilder.h>

static void register_url_query_class(script::Namespace ns)
{
  using namespace script;

  Class url_query = ns.newClass("UrlQuery").setId(script::Type::QUrlQuery).get();


  // QUrlQuery();
  bind::default_constructor<QUrlQuery>(url_query).create();
  // QUrlQuery(const QUrl &);
  bind::constructor<QUrlQuery, const QUrl &>(url_query).create();
  // QUrlQuery(const QString &);
  bind::constructor<QUrlQuery, const QString &>(url_query).create();
  // QUrlQuery(const QUrlQuery &);
  bind::constructor<QUrlQuery, const QUrlQuery &>(url_query).create();
  // QUrlQuery & operator=(const QUrlQuery &);
  bind::memop_assign<QUrlQuery, const QUrlQuery &>(url_query);
  // QUrlQuery & operator=(QUrlQuery &&);
  bind::memop_assign<QUrlQuery, QUrlQuery &&>(url_query);
  // ~QUrlQuery();
  bind::destructor<QUrlQuery>(url_query).create();
  // bool operator==(const QUrlQuery &) const;
  bind::memop_eq<QUrlQuery, const QUrlQuery &>(url_query);
  // bool operator!=(const QUrlQuery &) const;
  bind::memop_neq<QUrlQuery, const QUrlQuery &>(url_query);
  // void swap(QUrlQuery &);
  bind::void_member_function<QUrlQuery, QUrlQuery &, &QUrlQuery::swap>(url_query, "swap").create();
  // bool isEmpty() const;
  bind::member_function<QUrlQuery, bool, &QUrlQuery::isEmpty>(url_query, "isEmpty").create();
  // bool isDetached() const;
  bind::member_function<QUrlQuery, bool, &QUrlQuery::isDetached>(url_query, "isDetached").create();
  // void clear();
  bind::void_member_function<QUrlQuery, &QUrlQuery::clear>(url_query, "clear").create();
  // QString query(QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  bind::member_function<QUrlQuery, QString, QUrl::ComponentFormattingOptions, &QUrlQuery::query>(url_query, "query")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setQuery(const QString &);
  bind::void_member_function<QUrlQuery, const QString &, &QUrlQuery::setQuery>(url_query, "setQuery").create();
  // QString toString(QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  bind::member_function<QUrlQuery, QString, QUrl::ComponentFormattingOptions, &QUrlQuery::toString>(url_query, "toString")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setQueryDelimiters(QChar, QChar);
  bind::void_member_function<QUrlQuery, QChar, QChar, &QUrlQuery::setQueryDelimiters>(url_query, "setQueryDelimiters").create();
  // QChar queryValueDelimiter() const;
  bind::member_function<QUrlQuery, QChar, &QUrlQuery::queryValueDelimiter>(url_query, "queryValueDelimiter").create();
  // QChar queryPairDelimiter() const;
  bind::member_function<QUrlQuery, QChar, &QUrlQuery::queryPairDelimiter>(url_query, "queryPairDelimiter").create();
  // void setQueryItems(const QList<QPair<QString, QString> > &);
  /// TODO: void setQueryItems(const QList<QPair<QString, QString> > &);
  // QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  /// TODO: QList<QPair<QString, QString> > queryItems(QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  // bool hasQueryItem(const QString &) const;
  bind::member_function<QUrlQuery, bool, const QString &, &QUrlQuery::hasQueryItem>(url_query, "hasQueryItem").create();
  // void addQueryItem(const QString &, const QString &);
  bind::void_member_function<QUrlQuery, const QString &, const QString &, &QUrlQuery::addQueryItem>(url_query, "addQueryItem").create();
  // void removeQueryItem(const QString &);
  bind::void_member_function<QUrlQuery, const QString &, &QUrlQuery::removeQueryItem>(url_query, "removeQueryItem").create();
  // QString queryItemValue(const QString &, QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  bind::member_function<QUrlQuery, QString, const QString &, QUrl::ComponentFormattingOptions, &QUrlQuery::queryItemValue>(url_query, "queryItemValue")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  /// TODO: QStringList allQueryItemValues(const QString &, QUrl::ComponentFormattingOptions = QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded)) const;
  // void removeAllQueryItems(const QString &);
  bind::void_member_function<QUrlQuery, const QString &, &QUrlQuery::removeAllQueryItems>(url_query, "removeAllQueryItems").create();
  // static QChar defaultQueryValueDelimiter();
  bind::static_member_function<QUrlQuery, QChar, &QUrlQuery::defaultQueryValueDelimiter>(url_query, "defaultQueryValueDelimiter").create();
  // static QChar defaultQueryPairDelimiter();
  bind::static_member_function<QUrlQuery, QChar, &QUrlQuery::defaultQueryPairDelimiter>(url_query, "defaultQueryPairDelimiter").create();
  // QUrlQuery::DataPtr & data_ptr();
  /// TODO: QUrlQuery::DataPtr & data_ptr();
}


void register_urlquery_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_url_query_class(ns);

  // uint qHash(const QUrlQuery &, uint);
  bind::function<uint, const QUrlQuery &, uint, &qHash>(ns, "qHash").create();
  // void swap(QUrlQuery &, QUrlQuery &);
  bind::void_function<QUrlQuery &, QUrlQuery &, &swap>(ns, "swap").create();
}

