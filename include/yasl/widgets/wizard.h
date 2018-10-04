// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_WIZARD_H
#define YASL_WIDGETS_WIZARD_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QWizard>

namespace binding {
template<> struct make_type_t<QWizard> { inline static script::Type get() { return script::Type::QWizard; } };
template<> struct tag_resolver<QWizard> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QWizard::WizardButton> { inline static script::Type get() { return script::Type::QWizardWizardButton; } };
template<> struct make_type_t<QWizard::WizardOption> { inline static script::Type get() { return script::Type::QWizardWizardOption; } };
template<> struct make_type_t<QWizard::WizardOptions> { inline static script::Type get() { return script::Type::QWizardWizardOptions; } };
template<> struct make_type_t<QWizard::WizardPixmap> { inline static script::Type get() { return script::Type::QWizardWizardPixmap; } };
template<> struct make_type_t<QWizard::WizardStyle> { inline static script::Type get() { return script::Type::QWizardWizardStyle; } };
template<> struct make_type_t<QWizardPage> { inline static script::Type get() { return script::Type::QWizardPage; } };
template<> struct tag_resolver<QWizardPage> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_WIDGETS_WIZARD_H
