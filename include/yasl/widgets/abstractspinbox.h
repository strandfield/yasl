// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ABSTRACTSPINBOX_H
#define YASL_WIDGETS_ABSTRACTSPINBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QAbstractSpinBox>

namespace script {
template<> struct make_type_helper<QAbstractSpinBox> { inline static script::Type get() { return script::Type::QAbstractSpinBox; } };
namespace details { template<> struct tag_resolver<QAbstractSpinBox> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QAbstractSpinBox::ButtonSymbols> { inline static script::Type get() { return script::Type::QAbstractSpinBoxButtonSymbols; } };
template<> struct make_type_helper<QAbstractSpinBox::CorrectionMode> { inline static script::Type get() { return script::Type::QAbstractSpinBoxCorrectionMode; } };
template<> struct make_type_helper<QAbstractSpinBox::StepEnabled> { inline static script::Type get() { return script::Type::QAbstractSpinBoxStepEnabled; } };
template<> struct make_type_helper<QAbstractSpinBox::StepEnabledFlag> { inline static script::Type get() { return script::Type::QAbstractSpinBoxStepEnabledFlag; } };
} // namespace script

#endif // YASL_WIDGETS_ABSTRACTSPINBOX_H
