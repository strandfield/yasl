// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_STATICTEXT_H
#define YASL_GUI_STATICTEXT_H

#include "yasl/binding2/types.h"

#include <QStaticText>

namespace script { namespace bind {
template<> struct make_type_t<QStaticText> { inline static script::Type get() { return script::Type::QStaticText; } };
template<> struct make_type_t<QStaticText::PerformanceHint> { inline static script::Type get() { return script::Type::QStaticTextPerformanceHint; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_STATICTEXT_H
