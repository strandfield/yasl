// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractspinbox.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
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

  Enum step_enabled_flag = abstract_spin_box.newEnum("StepEnabledFlag").setId(script::Type::QAbstractSpinBoxStepEnabledFlag).get();

  register_qflags_type<QAbstractSpinBox::StepEnabledFlag>(abstract_spin_box, "StepEnabled", script::Type::QAbstractSpinBoxStepEnabled);
  step_enabled_flag.addValue("StepNone", QAbstractSpinBox::StepNone);
  step_enabled_flag.addValue("StepUpEnabled", QAbstractSpinBox::StepUpEnabled);
  step_enabled_flag.addValue("StepDownEnabled", QAbstractSpinBox::StepDownEnabled);
}


static void register_abstract_spin_box_button_symbols_enum(script::Class abstract_spin_box)
{
  using namespace script;

  Enum button_symbols = abstract_spin_box.newEnum("ButtonSymbols").setId(script::Type::QAbstractSpinBoxButtonSymbols).get();

  button_symbols.addValue("UpDownArrows", QAbstractSpinBox::UpDownArrows);
  button_symbols.addValue("PlusMinus", QAbstractSpinBox::PlusMinus);
  button_symbols.addValue("NoButtons", QAbstractSpinBox::NoButtons);
}


static void register_abstract_spin_box_correction_mode_enum(script::Class abstract_spin_box)
{
  using namespace script;

  Enum correction_mode = abstract_spin_box.newEnum("CorrectionMode").setId(script::Type::QAbstractSpinBoxCorrectionMode).get();

  correction_mode.addValue("CorrectToPreviousValue", QAbstractSpinBox::CorrectToPreviousValue);
  correction_mode.addValue("CorrectToNearestValue", QAbstractSpinBox::CorrectToNearestValue);
}


static void register_abstract_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class abstract_spin_box = ns.newClass("AbstractSpinBox").setId(script::Type::QAbstractSpinBox)
    .setBase(script::Type::QWidget).get();

  register_abstract_spin_box_step_enabled_flag_enum(abstract_spin_box);
  register_abstract_spin_box_button_symbols_enum(abstract_spin_box);
  register_abstract_spin_box_correction_mode_enum(abstract_spin_box);

  // QAbstractSpinBox(QWidget *);
  bind::constructor<QAbstractSpinBox, QWidget *>(abstract_spin_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QAbstractSpinBox();
  bind::destructor<QAbstractSpinBox>(abstract_spin_box).create();
  // QAbstractSpinBox::ButtonSymbols buttonSymbols() const;
  bind::member_function<QAbstractSpinBox, QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::buttonSymbols>(abstract_spin_box, "buttonSymbols").create();
  // void setButtonSymbols(QAbstractSpinBox::ButtonSymbols);
  bind::void_member_function<QAbstractSpinBox, QAbstractSpinBox::ButtonSymbols, &QAbstractSpinBox::setButtonSymbols>(abstract_spin_box, "setButtonSymbols").create();
  // void setCorrectionMode(QAbstractSpinBox::CorrectionMode);
  bind::void_member_function<QAbstractSpinBox, QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::setCorrectionMode>(abstract_spin_box, "setCorrectionMode").create();
  // QAbstractSpinBox::CorrectionMode correctionMode() const;
  bind::member_function<QAbstractSpinBox, QAbstractSpinBox::CorrectionMode, &QAbstractSpinBox::correctionMode>(abstract_spin_box, "correctionMode").create();
  // bool hasAcceptableInput() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::hasAcceptableInput>(abstract_spin_box, "hasAcceptableInput").create();
  // QString text() const;
  bind::member_function<QAbstractSpinBox, QString, &QAbstractSpinBox::text>(abstract_spin_box, "text").create();
  // QString specialValueText() const;
  bind::member_function<QAbstractSpinBox, QString, &QAbstractSpinBox::specialValueText>(abstract_spin_box, "specialValueText").create();
  // void setSpecialValueText(const QString &);
  bind::void_member_function<QAbstractSpinBox, const QString &, &QAbstractSpinBox::setSpecialValueText>(abstract_spin_box, "setSpecialValueText").create();
  // bool wrapping() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::wrapping>(abstract_spin_box, "wrapping").create();
  // void setWrapping(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setWrapping>(abstract_spin_box, "setWrapping").create();
  // void setReadOnly(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setReadOnly>(abstract_spin_box, "setReadOnly").create();
  // bool isReadOnly() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::isReadOnly>(abstract_spin_box, "isReadOnly").create();
  // void setKeyboardTracking(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setKeyboardTracking>(abstract_spin_box, "setKeyboardTracking").create();
  // bool keyboardTracking() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::keyboardTracking>(abstract_spin_box, "keyboardTracking").create();
  // void setAlignment(Qt::Alignment);
  bind::void_member_function<QAbstractSpinBox, Qt::Alignment, &QAbstractSpinBox::setAlignment>(abstract_spin_box, "setAlignment").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QAbstractSpinBox, Qt::Alignment, &QAbstractSpinBox::alignment>(abstract_spin_box, "alignment").create();
  // void setFrame(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setFrame>(abstract_spin_box, "setFrame").create();
  // bool hasFrame() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::hasFrame>(abstract_spin_box, "hasFrame").create();
  // void setAccelerated(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setAccelerated>(abstract_spin_box, "setAccelerated").create();
  // bool isAccelerated() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::isAccelerated>(abstract_spin_box, "isAccelerated").create();
  // void setGroupSeparatorShown(bool);
  bind::void_member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::setGroupSeparatorShown>(abstract_spin_box, "setGroupSeparatorShown").create();
  // bool isGroupSeparatorShown() const;
  bind::member_function<QAbstractSpinBox, bool, &QAbstractSpinBox::isGroupSeparatorShown>(abstract_spin_box, "isGroupSeparatorShown").create();
  // QSize sizeHint() const;
  bind::member_function<QAbstractSpinBox, QSize, &QAbstractSpinBox::sizeHint>(abstract_spin_box, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QAbstractSpinBox, QSize, &QAbstractSpinBox::minimumSizeHint>(abstract_spin_box, "minimumSizeHint").create();
  // void interpretText();
  bind::void_member_function<QAbstractSpinBox, &QAbstractSpinBox::interpretText>(abstract_spin_box, "interpretText").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  bind::member_function<QAbstractSpinBox, QVariant, Qt::InputMethodQuery, &QAbstractSpinBox::inputMethodQuery>(abstract_spin_box, "inputMethodQuery").create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QAbstractSpinBox, QValidator::State, QString &, int &, &QAbstractSpinBox::validate>(abstract_spin_box, "validate").create();
  // void fixup(QString &) const;
  bind::const_void_member_function<QAbstractSpinBox, QString &, &QAbstractSpinBox::fixup>(abstract_spin_box, "fixup").create();
  // void stepBy(int);
  bind::void_member_function<QAbstractSpinBox, int, &QAbstractSpinBox::stepBy>(abstract_spin_box, "stepBy").create();
  // void stepUp();
  bind::void_member_function<QAbstractSpinBox, &QAbstractSpinBox::stepUp>(abstract_spin_box, "stepUp").create();
  // void stepDown();
  bind::void_member_function<QAbstractSpinBox, &QAbstractSpinBox::stepDown>(abstract_spin_box, "stepDown").create();
  // void selectAll();
  bind::void_member_function<QAbstractSpinBox, &QAbstractSpinBox::selectAll>(abstract_spin_box, "selectAll").create();
  // void clear();
  bind::void_member_function<QAbstractSpinBox, &QAbstractSpinBox::clear>(abstract_spin_box, "clear").create();
  // void editingFinished();
  bind::signal<QAbstractSpinBox>(abstract_spin_box, "editingFinished", "editingFinished()");

  bind::link(abstract_spin_box, &QAbstractSpinBox::staticMetaObject);
}


void register_abstractspinbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_spin_box_class(ns);

  // QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QAbstractSpinBox::StepEnabled::enum_type);
  /// TODO: QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QAbstractSpinBox::StepEnabled::enum_type);
  // QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QFlags<QAbstractSpinBox::StepEnabled::enum_type>);
  /// TODO: QFlags<QAbstractSpinBox::StepEnabled::enum_type> operator|(QAbstractSpinBox::StepEnabled::enum_type, QFlags<QAbstractSpinBox::StepEnabled::enum_type>);
  // QIncompatibleFlag operator|(QAbstractSpinBox::StepEnabled::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QAbstractSpinBox::StepEnabled::enum_type, int);
}

