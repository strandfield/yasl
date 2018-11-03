// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsondocument.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/jsonarray.h"
#include "yasl/core/jsondocument.h"
#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_json_document_data_validation_enum(script::Class json_document)
{
  using namespace script;

  Enum data_validation = json_document.Enum("DataValidation").setId(script::Type::QJsonDocumentDataValidation).get();

  data_validation.addValue("Validate", QJsonDocument::Validate);
  data_validation.addValue("BypassValidation", QJsonDocument::BypassValidation);
}


static void register_json_document_json_format_enum(script::Class json_document)
{
  using namespace script;

  Enum json_format = json_document.Enum("JsonFormat").setId(script::Type::QJsonDocumentJsonFormat).get();

  json_format.addValue("Indented", QJsonDocument::Indented);
  json_format.addValue("Compact", QJsonDocument::Compact);
}


static void register_json_document_class(script::Namespace ns)
{
  using namespace script;

  Class json_document = ns.Class("JsonDocument").setId(script::Type::QJsonDocument).get();

  register_json_document_data_validation_enum(json_document);
  register_json_document_json_format_enum(json_document);
  binding::ClassBinder<QJsonDocument> binder{ json_document };

  // QJsonDocument();
  binder.default_ctor().create();
  // QJsonDocument(const QJsonObject &);
  binder.ctor<const QJsonObject &>().create();
  // QJsonDocument(const QJsonArray &);
  binder.ctor<const QJsonArray &>().create();
  // ~QJsonDocument();
  binder.dtor().create();
  // QJsonDocument(const QJsonDocument &);
  binder.ctor<const QJsonDocument &>().create();
  // QJsonDocument & operator=(const QJsonDocument &);
  binder.operators().assign<const QJsonDocument &>();
  // QJsonDocument(QJsonDocument &&);
  binder.ctor<QJsonDocument &&>().create();
  // QJsonDocument & operator=(QJsonDocument &&);
  binder.operators().assign<QJsonDocument &&>();
  // void swap(QJsonDocument &);
  binder.void_fun<QJsonDocument &, &QJsonDocument::swap>("swap").create();
  // static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  /// TODO: static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  // const char * rawData(int *) const;
  /// TODO: const char * rawData(int *) const;
  // static QJsonDocument fromBinaryData(const QByteArray &, QJsonDocument::DataValidation);
  binder.static_fun<QJsonDocument, const QByteArray &, QJsonDocument::DataValidation, &QJsonDocument::fromBinaryData>("fromBinaryData")
    .apply(binding::default_arguments(QJsonDocument::Validate)).create();
  // QByteArray toBinaryData() const;
  binder.fun<QByteArray, &QJsonDocument::toBinaryData>("toBinaryData").create();
  // static QJsonDocument fromVariant(const QVariant &);
  binder.static_fun<QJsonDocument, const QVariant &, &QJsonDocument::fromVariant>("fromVariant").create();
  // QVariant toVariant() const;
  binder.fun<QVariant, &QJsonDocument::toVariant>("toVariant").create();
  // static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  /// TODO: static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  // QByteArray toJson() const;
  binder.fun<QByteArray, &QJsonDocument::toJson>("toJson").create();
  // QByteArray toJson(QJsonDocument::JsonFormat) const;
  binder.fun<QByteArray, QJsonDocument::JsonFormat, &QJsonDocument::toJson>("toJson").create();
  // bool isEmpty() const;
  binder.fun<bool, &QJsonDocument::isEmpty>("isEmpty").create();
  // bool isArray() const;
  binder.fun<bool, &QJsonDocument::isArray>("isArray").create();
  // bool isObject() const;
  binder.fun<bool, &QJsonDocument::isObject>("isObject").create();
  // QJsonObject object() const;
  binder.fun<QJsonObject, &QJsonDocument::object>("object").create();
  // QJsonArray array() const;
  binder.fun<QJsonArray, &QJsonDocument::array>("array").create();
  // void setObject(const QJsonObject &);
  binder.void_fun<const QJsonObject &, &QJsonDocument::setObject>("setObject").create();
  // void setArray(const QJsonArray &);
  binder.void_fun<const QJsonArray &, &QJsonDocument::setArray>("setArray").create();
  // const QJsonValue operator[](const QString &) const;
  binder.operators().const_subscript<const QJsonValue, const QString &>();
  // const QJsonValue operator[](QLatin1String) const;
  /// TODO: const QJsonValue operator[](QLatin1String) const;
  // const QJsonValue operator[](int) const;
  binder.operators().const_subscript<const QJsonValue, int>();
  // bool operator==(const QJsonDocument &) const;
  binder.operators().eq<const QJsonDocument &>();
  // bool operator!=(const QJsonDocument &) const;
  binder.operators().neq<const QJsonDocument &>();
  // bool isNull() const;
  binder.fun<bool, &QJsonDocument::isNull>("isNull").create();
}


void register_jsondocument_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_document_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonDocument &, QJsonDocument &);
  binder.void_fun<QJsonDocument &, QJsonDocument &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QJsonDocument &);
  /// TODO: QDebug operator<<(QDebug, const QJsonDocument &);
}

