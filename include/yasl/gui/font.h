// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_FONT_H
#define YASL_GUI_FONT_H

#include "yasl/common/types.h"

#include <QFont>

namespace script {
template<> struct make_type_helper<QFont> { inline static script::Type get() { return script::Type::QFont; } };
template<> struct make_type_helper<QFont::Capitalization> { inline static script::Type get() { return script::Type::QFontCapitalization; } };
template<> struct make_type_helper<QFont::HintingPreference> { inline static script::Type get() { return script::Type::QFontHintingPreference; } };
template<> struct make_type_helper<QFont::ResolveProperties> { inline static script::Type get() { return script::Type::QFontResolveProperties; } };
template<> struct make_type_helper<QFont::SpacingType> { inline static script::Type get() { return script::Type::QFontSpacingType; } };
template<> struct make_type_helper<QFont::Stretch> { inline static script::Type get() { return script::Type::QFontStretch; } };
template<> struct make_type_helper<QFont::Style> { inline static script::Type get() { return script::Type::QFontStyle; } };
template<> struct make_type_helper<QFont::StyleHint> { inline static script::Type get() { return script::Type::QFontStyleHint; } };
template<> struct make_type_helper<QFont::StyleStrategy> { inline static script::Type get() { return script::Type::QFontStyleStrategy; } };
template<> struct make_type_helper<QFont::Weight> { inline static script::Type get() { return script::Type::QFontWeight; } };
} // namespace script

#endif // YASL_GUI_FONT_H
