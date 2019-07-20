// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_WIZARD_H
#define YASL_WIDGETS_WIZARD_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QWizard>

namespace script {
template<> struct make_type_helper<QWizard> { inline static script::Type get() { return script::Type::QWizard; } };
namespace details { template<> struct tag_resolver<QWizard> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QWizard::WizardButton> { inline static script::Type get() { return script::Type::QWizardWizardButton; } };
template<> struct make_type_helper<QWizard::WizardOption> { inline static script::Type get() { return script::Type::QWizardWizardOption; } };
template<> struct make_type_helper<QWizard::WizardOptions> { inline static script::Type get() { return script::Type::QWizardWizardOptions; } };
template<> struct make_type_helper<QWizard::WizardPixmap> { inline static script::Type get() { return script::Type::QWizardWizardPixmap; } };
template<> struct make_type_helper<QWizard::WizardStyle> { inline static script::Type get() { return script::Type::QWizardWizardStyle; } };
template<> struct make_type_helper<QWizardPage> { inline static script::Type get() { return script::Type::QWizardPage; } };
namespace details { template<> struct tag_resolver<QWizardPage> { typedef qobject_tag tag_type; }; }
} // namespace script

#endif // YASL_WIDGETS_WIZARD_H
