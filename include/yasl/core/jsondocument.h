// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_JSONDOCUMENT_H
#define YASL_CORE_JSONDOCUMENT_H

#include "yasl/common/types.h"

#include <QJsonDocument>

namespace script {
template<> struct make_type_helper<QJsonDocument> { inline static script::Type get() { return script::Type::QJsonDocument; } };
template<> struct make_type_helper<QJsonDocument::DataValidation> { inline static script::Type get() { return script::Type::QJsonDocumentDataValidation; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_helper<QJsonDocument::JsonFormat> { inline static script::Type get() { return script::Type::QJsonDocumentJsonFormat; } };
#endif
} // namespace script

#endif // YASL_CORE_JSONDOCUMENT_H
