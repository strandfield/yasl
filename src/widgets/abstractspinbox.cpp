// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractspinbox.h"

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
  binder.ctors().add<QWidget *>();
  // ~QAbstractSpinBox();
  binder.add_dtor();
  // QAbstractSpinBox::ButtonSymbols buttonSymbols() const;
  binder.add_fun<QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::buttonSymbols>("buttonSymbols");
  // void setButtonSymbols(QAbstractSpinBox::ButtonSymbols);
  binder.add_void_fun<QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::setButtonSymbols>("setButtonSymbols");
  // void setCorrectionMode(QAbstractSpinBox::CorrectionMode);
  binder.add_void_fun<QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::setCorrectionMode>("setCorrectionMode");
  // QAbstractSpinBox::CorrectionMode correctionMode() const;
  binder.add_fun<QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::correctionMode>("correctionMode");
  // bool hasAcceptableInput() const;
  binder.add_fun<bool, &QAbstractSpinBox::hasAcceptableInput>("hasAcceptableInput");
  // QString text() const;
  binder.add_fun<QString, &QAbstractSpinBox::text>("text");
  // QString specialValueText() const;
  binder.add_fun<QString, &QAbstractSpinBox::specialValueText>("specialValueText");
  // void setSpecialValueText(const QString &);
  binder.add_void_fun<const QString &, &QAbstractSpinBox::setSpecialValueText>("setSpecialValueText");
  // bool wrapping() const;
  binder.add_fun<bool, &QAbstractSpinBox::wrapping>("wrapping");
  // void setWrapping(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setWrapping>("setWrapping");
  // void setReadOnly(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setReadOnly>("setReadOnly");
  // bool isReadOnly() const;
  binder.add_fun<bool, &QAbstractSpinBox::isReadOnly>("isReadOnly");
  // void setKeyboardTracking(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setKeyboardTracking>("setKeyboardTracking");
  // bool keyboardTracking() const;
  binder.add_fun<bool, &QAbstractSpinBox::keyboardTracking>("keyboardTracking");
  // void setAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QAbstractSpinBox::setAlignment>("setAlignment");
  // Qt::Alignment alignment() const;
  binder.add_fun<Qt::Alignment, &QAbstractSpinBox::alignment>("alignment");
  // void setFrame(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setFrame>("setFrame");
  // bool hasFrame() const;
  binder.add_fun<bool, &QAbstractSpinBox::hasFrame>("hasFrame");
  // void setAccelerated(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setAccelerated>("setAccelerated");
  // bool isAccelerated() const;
  binder.add_fun<bool, &QAbstractSpinBox::isAccelerated>("isAccelerated");
  // void setGroupSeparatorShown(bool);
  binder.add_void_fun<bool, &QAbstractSpinBox::setGroupSeparatorShown>("setGroupSeparatorShown");
  // bool isGroupSeparatorShown() const;
  binder.add_fun<bool, &QAbstractSpinBox::isGroupSeparatorShown>("isGroupSeparatorShown");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QAbstractSpinBox::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QAbstractSpinBox::minimumSizeHint>("minimumSizeHint");
  // void interpretText();
  binder.add_void_fun<&QAbstractSpinBox::interpretText>("interpretText");
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.add_fun<QVariant, Qt::InputMethodQuery, &QAbstractSpinBox::inputMethodQuery>("inputMethodQuery");
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QAbstractSpinBox::validate>("validate");
  // void fixup(QString &) const;
  binder.add_const_void_fun<QString &, &QAbstractSpinBox::fixup>("fixup");
  // void stepBy(int);
  binder.add_void_fun<int, &QAbstractSpinBox::stepBy>("stepBy");
  // void stepUp();
  binder.add_void_fun<&QAbstractSpinBox::stepUp>("stepUp");
  // void stepDown();
  binder.add_void_fun<&QAbstractSpinBox::stepDown>("stepDown");
  // void selectAll();
  binder.add_void_fun<&QAbstractSpinBox::selectAll>("selectAll");
  // void clear();
  binder.add_void_fun<&QAbstractSpinBox::clear>("clear");
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

