// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_FONTDATABASE_H
#define YASL_GUI_FONTDATABASE_H

#include "yasl/binding2/types.h"

#include <QFontDatabase>

namespace script { namespace bind {
template<> struct make_type_t<QFontDatabase> { inline static script::Type get() { return script::Type::QFontDatabase; } };
template<> struct make_type_t<QFontDatabase::SystemFont> { inline static script::Type get() { return script::Type::QFontDatabaseSystemFont; } };
template<> struct make_type_t<QFontDatabase::WritingSystem> { inline static script::Type get() { return script::Type::QFontDatabaseWritingSystem; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_FONTDATABASE_H
