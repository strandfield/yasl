// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsondocument.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/jsonarray.h"
#include "yasl/core/jsondocument.h"
#include "yasl/core/jsonobject.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_json_document_data_validation_enum(script::Class json_document)
{
  using namespace script;

  Enum data_validation = json_document.newEnum("DataValidation").setId(script::Type::QJsonDocumentDataValidation).get();

  data_validation.addValue("Validate", QJsonDocument::Validate);
  data_validation.addValue("BypassValidation", QJsonDocument::BypassValidation);
}


static void register_json_document_json_format_enum(script::Class json_document)
{
  using namespace script;

  Enum json_format = json_document.newEnum("JsonFormat").setId(script::Type::QJsonDocumentJsonFormat).get();

  json_format.addValue("Indented", QJsonDocument::Indented);
  json_format.addValue("Compact", QJsonDocument::Compact);
}


static void register_json_document_class(script::Namespace ns)
{
  using namespace script;

  Class json_document = ns.newClass("JsonDocument").setId(script::Type::QJsonDocument).get();

  register_json_document_data_validation_enum(json_document);
  register_json_document_json_format_enum(json_document);

  // QJsonDocument();
  bind::default_constructor<QJsonDocument>(json_document).create();
  // QJsonDocument(const QJsonObject &);
  bind::constructor<QJsonDocument, const QJsonObject &>(json_document).create();
  // QJsonDocument(const QJsonArray &);
  bind::constructor<QJsonDocument, const QJsonArray &>(json_document).create();
  // ~QJsonDocument();
  bind::destructor<QJsonDocument>(json_document).create();
  // QJsonDocument(const QJsonDocument &);
  bind::constructor<QJsonDocument, const QJsonDocument &>(json_document).create();
  // QJsonDocument & operator=(const QJsonDocument &);
  bind::memop_assign<QJsonDocument, const QJsonDocument &>(json_document);
  // static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  /// TODO: static QJsonDocument fromRawData(const char *, int, QJsonDocument::DataValidation);
  // const char * rawData(int *) const;
  /// TODO: const char * rawData(int *) const;
  // static QJsonDocument fromBinaryData(const QByteArray &, QJsonDocument::DataValidation = QJsonDocument::Validate);
  bind::static_member_function<QJsonDocument, QJsonDocument, const QByteArray &, QJsonDocument::DataValidation, &QJsonDocument::fromBinaryData>(json_document, "fromBinaryData")
    .apply(bind::default_arguments(QJsonDocument::Validate)).create();
  // QByteArray toBinaryData() const;
  bind::member_function<QJsonDocument, QByteArray, &QJsonDocument::toBinaryData>(json_document, "toBinaryData").create();
  // static QJsonDocument fromVariant(const QVariant &);
  bind::static_member_function<QJsonDocument, QJsonDocument, const QVariant &, &QJsonDocument::fromVariant>(json_document, "fromVariant").create();
  // QVariant toVariant() const;
  bind::member_function<QJsonDocument, QVariant, &QJsonDocument::toVariant>(json_document, "toVariant").create();
  // static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  /// TODO: static QJsonDocument fromJson(const QByteArray &, QJsonParseError *);
  // QByteArray toJson() const;
  bind::member_function<QJsonDocument, QByteArray, &QJsonDocument::toJson>(json_document, "toJson").create();
  // QByteArray toJson(QJsonDocument::JsonFormat) const;
  bind::member_function<QJsonDocument, QByteArray, QJsonDocument::JsonFormat, &QJsonDocument::toJson>(json_document, "toJson").create();
  // bool isEmpty() const;
  bind::member_function<QJsonDocument, bool, &QJsonDocument::isEmpty>(json_document, "isEmpty").create();
  // bool isArray() const;
  bind::member_function<QJsonDocument, bool, &QJsonDocument::isArray>(json_document, "isArray").create();
  // bool isObject() const;
  bind::member_function<QJsonDocument, bool, &QJsonDocument::isObject>(json_document, "isObject").create();
  // QJsonObject object() const;
  bind::member_function<QJsonDocument, QJsonObject, &QJsonDocument::object>(json_document, "object").create();
  // QJsonArray array() const;
  bind::member_function<QJsonDocument, QJsonArray, &QJsonDocument::array>(json_document, "array").create();
  // void setObject(const QJsonObject &);
  bind::void_member_function<QJsonDocument, const QJsonObject &, &QJsonDocument::setObject>(json_document, "setObject").create();
  // void setArray(const QJsonArray &);
  bind::void_member_function<QJsonDocument, const QJsonArray &, &QJsonDocument::setArray>(json_document, "setArray").create();
  // bool operator==(const QJsonDocument &) const;
  bind::memop_eq<QJsonDocument, const QJsonDocument &>(json_document);
  // bool operator!=(const QJsonDocument &) const;
  bind::memop_neq<QJsonDocument, const QJsonDocument &>(json_document);
  // bool isNull() const;
  bind::member_function<QJsonDocument, bool, &QJsonDocument::isNull>(json_document, "isNull").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QJsonDocument, QMetaType::QJsonDocument>>();
}


void register_jsondocument_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_document_class(ns);

  // QDebug operator<<(QDebug, const QJsonDocument &);
  /// TODO: QDebug operator<<(QDebug, const QJsonDocument &);
}

