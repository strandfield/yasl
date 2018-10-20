// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractspinbox.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/core/variant.h"
#include "yasl/gui/validator.h"
#include "yasl/widgets/abstractspinbox.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_abstract_spin_box_step_enabled_flag_enum(script::Class abstract_spin_box)
{
  using namespace script;

  Enum step_enabled_flag = abstract_spin_box.Enum("StepEnabledFlag").setId(script::Type::QAbstractSpinBoxStepEnabledFlag).get();

  register_qflags_type<QAbstractSpinBox::StepEnabledFlag>(abstract_spin_box, "StepEnabled", script::Type::QAbstractSpinBoxStepEnabled);
  step_enabled_flag.addValue("StepNone", QAbstractSpinBox::StepNone);
  step_enabled_flag.addValue("StepUpEnabled", QAbstractSpinBox::StepUpEnabled);
  step_enabled_flag.addValue("StepDownEnabled", QAbstractSpinBox::StepDownEnabled);
}


static void register_abstract_spin_box_button_symbols_enum(script::Class abstract_spin_box)
{
  using namespace script;

  Enum button_symbols = abstract_spin_box.Enum("ButtonSymbols").setId(script::Type::QAbstractSpinBoxButtonSymbols).get();

  button_symbols.addValue("UpDownArrows", QAbstractSpinBox::UpDownArrows);
  button_symbols.addValue("PlusMinus", QAbstractSpinBox::PlusMinus);
  button_symbols.addValue("NoButtons", QAbstractSpinBox::NoButtons);
}


static void register_abstract_spin_box_correction_mode_enum(script::Class abstract_spin_box)
{
  using namespace script;

  Enum correction_mode = abstract_spin_box.Enum("CorrectionMode").setId(script::Type::QAbstractSpinBoxCorrectionMode).get();

  correction_mode.addValue("CorrectToPreviousValue", QAbstractSpinBox::CorrectToPreviousValue);
  correction_mode.addValue("CorrectToNearestValue", QAbstractSpinBox::CorrectToNearestValue);
}


static void register_abstract_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class abstract_spin_box = ns.Class("AbstractSpinBox").setId(script::Type::QAbstractSpinBox)
    .setBase(script::Type::QWidget).get();

  register_abstract_spin_box_step_enabled_flag_enum(abstract_spin_box);
  register_abstract_spin_box_button_symbols_enum(abstract_spin_box);
  register_abstract_spin_box_correction_mode_enum(abstract_spin_box);
  binding::QClass<QAbstractSpinBox> binder{ abstract_spin_box, &QAbstractSpinBox::staticMetaObject };

  // QAbstractSpinBox(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .addDefaultArgument(binding::default_argument(abstract_spin_box.engine(), (QWidget*)nullptr)).create();
  // ~QAbstractSpinBox();
  binder.add_dtor();
  // QAbstractSpinBox::ButtonSymbols buttonSymbols() const;
  binder.fun<QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::buttonSymbols>("buttonSymbols").create();
  // void setButtonSymbols(QAbstractSpinBox::ButtonSymbols);
  binder.void_fun<QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::setButtonSymbols>("setButtonSymbols").create();
  // void setCorrectionMode(QAbstractSpinBox::CorrectionMode);
  binder.void_fun<QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::setCorrectionMode>("setCorrectionMode").create();
  // QAbstractSpinBox::CorrectionMode correctionMode() const;
  binder.fun<QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::correctionMode>("correctionMode").create();
  // bool hasAcceptableInput() const;
  binder.fun<bool, &QAbstractSpinBox::hasAcceptableInput>("hasAcceptableInput").create();
  // QString text() const;
  binder.fun<QString, &QAbstractSpinBox::text>("text").create();
  // QString specialValueText() const;
  binder.fun<QString, &QAbstractSpinBox::specialValueText>("specialValueText").create();
  // void setSpecialValueText(const QString &);
  binder.void_fun<const QString &, &QAbstractSpinBox::setSpecialValueText>("setSpecialValueText").create();
  // bool wrapping() const;
  binder.fun<bool, &QAbstractSpinBox::wrapping>("wrapping").create();
  // void setWrapping(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setWrapping>("setWrapping").create();
  // void setReadOnly(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setReadOnly>("setReadOnly").create();
  // bool isReadOnly() const;
  binder.fun<bool, &QAbstractSpinBox::isReadOnly>("isReadOnly").create();
  // void setKeyboardTracking(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setKeyboardTracking>("setKeyboardTracking").create();
  // bool keyboardTracking() const;
  binder.fun<bool, &QAbstractSpinBox::keyboardTracking>("keyboardTracking").create();
  // void setAlignment(Qt::Alignment);
  binder.void_fun<Qt::Alignment, &QAbstractSpinBox::setAlignment>("setAlignment").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QAbstractSpinBox::alignment>("alignment").create();
  // void setFrame(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setFrame>("setFrame").create();
  // bool hasFrame() const;
  binder.fun<bool, &QAbstractSpinBox::hasFrame>("hasFrame").create();
  // void setAccelerated(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setAccelerated>("setAccelerated").create();
  // bool isAccelerated() const;
  binder.fun<bool, &QAbstractSpinBox::isAccelerated>("isAccelerated").create();
  // void setGroupSeparatorShown(bool);
  binder.void_fun<bool, &QAbstractSpinBox::setGroupSeparatorShown>("setGroupSeparatorShown").create();
  // bool isGroupSeparatorShown() const;
  binder.fun<bool, &QAbstractSpinBox::isGroupSeparatorShown>("isGroupSeparatorShown").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QAbstractSpinBox::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QAbstractSpinBox::minimumSizeHint>("minimumSizeHint").create();
  // void interpretText();
  binder.void_fun<&QAbstractSpinBox::interpretText>("interpretText").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.fun<QVariant, Qt::InputMethodQuery, &QAbstractSpinBox::inputMethodQuery>("inputMethodQuery").create();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QAbstractSpinBox::validate>("validate").create();
  // void fixup(QString &) const;
  binder.const_void_fun<QString &, &QAbstractSpinBox::fixup>("fixup").create();
  // void stepBy(int);
  binder.void_fun<int, &QAbstractSpinBox::stepBy>("stepBy").create();
  // void stepUp();
  binder.void_fun<&QAbstractSpinBox::stepUp>("stepUp").create();
  // void stepDown();
  binder.void_fun<&QAbstractSpinBox::stepDown>("stepDown").create();
  // void selectAll();
  binder.void_fun<&QAbstractSpinBox::selectAll>("selectAll").create();
  // void clear();
  binder.void_fun<&QAbstractSpinBox::clear>("clear").create();
  // void editingFinished();
  binder.sigs().add("editingFinished", "editingFinished()");

  abstract_spin_box.engine()->registerQtType(&QAbstractSpinBox::staticMetaObject, abstract_spin_box.id());
}


void register_abstractspinbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_spin_box_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QAbstractSpinBox::StepEnabled::enum_type);
  /// TODO: QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QAbstractSpinBox::StepEnabled::enum_type);
  // QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QFlags<QAbstractSpinBox::StepEnabled::enum_type>);
  /// TODO: QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QFlags<QAbstractSpinBox::StepEnabled::enum_type>);
  // QIncompatibleFlag operator|(QAbstractSpinBox::StepEnabled::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QAbstractSpinBox::StepEnabled::enum_type, int);
}

