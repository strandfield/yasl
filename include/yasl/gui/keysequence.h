// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_KEYSEQUENCE_H
#define YASL_GUI_KEYSEQUENCE_H

#include "yasl/common/types.h"

#include <QKeySequence>

namespace script {
template<> struct make_type_helper<QKeySequence> { inline static script::Type get() { return script::Type::QKeySequence; } };
template<> struct make_type_helper<QKeySequence::SequenceFormat> { inline static script::Type get() { return script::Type::QKeySequenceSequenceFormat; } };
template<> struct make_type_helper<QKeySequence::SequenceMatch> { inline static script::Type get() { return script::Type::QKeySequenceSequenceMatch; } };
template<> struct make_type_helper<QKeySequence::StandardKey> { inline static script::Type get() { return script::Type::QKeySequenceStandardKey; } };
} // namespace script

#endif // YASL_GUI_KEYSEQUENCE_H
