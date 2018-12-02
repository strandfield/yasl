// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_FONTDATABASE_H
#define YASL_GUI_FONTDATABASE_H

#include "yasl/common/types.h"

#include <QFontDatabase>

namespace script {
template<> struct make_type_t<QFontDatabase> { inline static script::Type get() { return script::Type::QFontDatabase; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QFontDatabase::SystemFont> { inline static script::Type get() { return script::Type::QFontDatabaseSystemFont; } };
#endif
template<> struct make_type_t<QFontDatabase::WritingSystem> { inline static script::Type get() { return script::Type::QFontDatabaseWritingSystem; } };
} // namespace script

#endif // YASL_GUI_FONTDATABASE_H
