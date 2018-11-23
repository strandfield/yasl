// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_FONT_H
#define YASL_GUI_FONT_H

#include "yasl/binding/types.h"

#include <QFont>

namespace script { namespace bind {
template<> struct make_type_t<QFont> { inline static script::Type get() { return script::Type::QFont; } };
template<> struct make_type_t<QFont::Capitalization> { inline static script::Type get() { return script::Type::QFontCapitalization; } };
template<> struct make_type_t<QFont::HintingPreference> { inline static script::Type get() { return script::Type::QFontHintingPreference; } };
template<> struct make_type_t<QFont::ResolveProperties> { inline static script::Type get() { return script::Type::QFontResolveProperties; } };
template<> struct make_type_t<QFont::SpacingType> { inline static script::Type get() { return script::Type::QFontSpacingType; } };
template<> struct make_type_t<QFont::Stretch> { inline static script::Type get() { return script::Type::QFontStretch; } };
template<> struct make_type_t<QFont::Style> { inline static script::Type get() { return script::Type::QFontStyle; } };
template<> struct make_type_t<QFont::StyleHint> { inline static script::Type get() { return script::Type::QFontStyleHint; } };
template<> struct make_type_t<QFont::StyleStrategy> { inline static script::Type get() { return script::Type::QFontStyleStrategy; } };
template<> struct make_type_t<QFont::Weight> { inline static script::Type get() { return script::Type::QFontWeight; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_FONT_H
