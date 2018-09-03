// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsondocument.h"

#include "yasl/binding/class.h"
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
  binding::Class<QJsonDocument> binder{ json_document };

  // QJsonDocument();
  binder.ctors().add_default();
  // QJsonDocument(const QJsonObject &);
  binder.ctors().add<const QJsonObject &>();
  // QJsonDocument(const QJsonArray &);
  binder.ctors().add<const QJsonArray &>();
  // ~QJsonDocument();
  binder.add_dtor();
  // QJsonDocument(const QJsonDocument &);
  binder.ctors().add<const QJsonDocument &>();
  // QJsonDocument & operator=(const QJsonDocument &);
  binder.operators().assign<const QJsonDocument &>();
  // QJsonDocument(QJsonDocument &&);
  binder.ctors().add<QJsonDocument &&>();
  // QJsonDocument & operator=(QJsonDocument &&);
  binder.operators().assign<QJsonDocument &&>();
  // void swap(QJsonDocument &);
  binder.add_void_fun<QJsonDocument &, &QJsonDocument::swap>("swap");
  // static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  /// TODO: static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  // const char * rawData(int *) const;
  /// TODO: const char * rawData(int *) const;
  // static QJsonDocument fromBinaryData(const QByteArray &, QJsonDocument::DataValidation);
  binder.add_static<QJsonDocument, const QByteArray &, QJsonDocument::DataValidation, &QJsonDocument::fromBinaryData>("fromBinaryData");
  // QByteArray toBinaryData() const;
  binder.add_fun<QByteArray, &QJsonDocument::toBinaryData>("toBinaryData");
  // static QJsonDocument fromVariant(const QVariant &);
  binder.add_static<QJsonDocument, const QVariant &, &QJsonDocument::fromVariant>("fromVariant");
  // QVariant toVariant() const;
  binder.add_fun<QVariant, &QJsonDocument::toVariant>("toVariant");
  // static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  /// TODO: static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  // QByteArray toJson() const;
  binder.add_fun<QByteArray, &QJsonDocument::toJson>("toJson");
  // QByteArray toJson(QJsonDocument::JsonFormat) const;
  binder.add_fun<QByteArray, QJsonDocument::JsonFormat, &QJsonDocument::toJson>("toJson");
  // bool isEmpty() const;
  binder.add_fun<bool, &QJsonDocument::isEmpty>("isEmpty");
  // bool isArray() const;
  binder.add_fun<bool, &QJsonDocument::isArray>("isArray");
  // bool isObject() const;
  binder.add_fun<bool, &QJsonDocument::isObject>("isObject");
  // QJsonObject object() const;
  binder.add_fun<QJsonObject, &QJsonDocument::object>("object");
  // QJsonArray array() const;
  binder.add_fun<QJsonArray, &QJsonDocument::array>("array");
  // void setObject(const QJsonObject &);
  binder.add_void_fun<const QJsonObject &, &QJsonDocument::setObject>("setObject");
  // void setArray(const QJsonArray &);
  binder.add_void_fun<const QJsonArray &, &QJsonDocument::setArray>("setArray");
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
  binder.add_fun<bool, &QJsonDocument::isNull>("isNull");
}


void register_jsondocument_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_document_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonDocument &, QJsonDocument &);
  binder.add_void_fun<QJsonDocument &, QJsonDocument &, &swap>("swap");
  // QDebug operator<<(QDebug, const QJsonDocument &);
  /// TODO: QDebug operator<<(QDebug, const QJsonDocument &);
}

