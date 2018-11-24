// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_JSONDOCUMENT_H
#define YASL_CORE_JSONDOCUMENT_H

#include "yasl/common/types.h"

#include <QJsonDocument>

namespace script {
template<> struct make_type_t<QJsonDocument> { inline static script::Type get() { return script::Type::QJsonDocument; } };
template<> struct make_type_t<QJsonDocument::DataValidation> { inline static script::Type get() { return script::Type::QJsonDocumentDataValidation; } };
template<> struct make_type_t<QJsonDocument::JsonFormat> { inline static script::Type get() { return script::Type::QJsonDocumentJsonFormat; } };
} // namespace script

#endif // YASL_CORE_JSONDOCUMENT_H
