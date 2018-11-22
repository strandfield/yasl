// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/spinbox.h"

#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/newfunction.h"
#include "yasl/binding2/qclass.h"

#include "yasl/gui/validator.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class spin_box = ns.newClass("SpinBox").setId(script::Type::QSpinBox)
    .setBase(script::Type::QAbstractSpinBox).get();


  // QSpinBox(QWidget *);
  bind::constructor<QSpinBox, QWidget *>(spin_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QSpinBox();
  bind::destructor<QSpinBox>(spin_box).create();
  // int value() const;
  bind::member_function<QSpinBox, int, &QSpinBox::value>(spin_box, "value").create();
  // QString prefix() const;
  bind::member_function<QSpinBox, QString, &QSpinBox::prefix>(spin_box, "prefix").create();
  // void setPrefix(const QString &);
  bind::void_member_function<QSpinBox, const QString &, &QSpinBox::setPrefix>(spin_box, "setPrefix").create();
  // QString suffix() const;
  bind::member_function<QSpinBox, QString, &QSpinBox::suffix>(spin_box, "suffix").create();
  // void setSuffix(const QString &);
  bind::void_member_function<QSpinBox, const QString &, &QSpinBox::setSuffix>(spin_box, "setSuffix").create();
  // QString cleanText() const;
  bind::member_function<QSpinBox, QString, &QSpinBox::cleanText>(spin_box, "cleanText").create();
  // int singleStep() const;
  bind::member_function<QSpinBox, int, &QSpinBox::singleStep>(spin_box, "singleStep").create();
  // void setSingleStep(int);
  bind::void_member_function<QSpinBox, int, &QSpinBox::setSingleStep>(spin_box, "setSingleStep").create();
  // int minimum() const;
  bind::member_function<QSpinBox, int, &QSpinBox::minimum>(spin_box, "minimum").create();
  // void setMinimum(int);
  bind::void_member_function<QSpinBox, int, &QSpinBox::setMinimum>(spin_box, "setMinimum").create();
  // int maximum() const;
  bind::member_function<QSpinBox, int, &QSpinBox::maximum>(spin_box, "maximum").create();
  // void setMaximum(int);
  bind::void_member_function<QSpinBox, int, &QSpinBox::setMaximum>(spin_box, "setMaximum").create();
  // void setRange(int, int);
  bind::void_member_function<QSpinBox, int, int, &QSpinBox::setRange>(spin_box, "setRange").create();
  // int displayIntegerBase() const;
  bind::member_function<QSpinBox, int, &QSpinBox::displayIntegerBase>(spin_box, "displayIntegerBase").create();
  // void setDisplayIntegerBase(int);
  bind::void_member_function<QSpinBox, int, &QSpinBox::setDisplayIntegerBase>(spin_box, "setDisplayIntegerBase").create();
  // void setValue(int);
  bind::void_member_function<QSpinBox, int, &QSpinBox::setValue>(spin_box, "setValue").create();
  // void valueChanged(int);
  bind::signal<QSpinBox, int>(spin_box, "valueChanged", "valueChanged(int)");
  // void valueChanged(const QString &);
  bind::signal<QSpinBox, const QString &>(spin_box, "valueChanged", "valueChanged(const QString &)");

  bind::link(spin_box, &QSpinBox::staticMetaObject);
}


static void register_double_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class double_spin_box = ns.newClass("DoubleSpinBox").setId(script::Type::QDoubleSpinBox)
    .setBase(script::Type::QAbstractSpinBox).get();


  // QDoubleSpinBox(QWidget *);
  bind::constructor<QDoubleSpinBox, QWidget *>(double_spin_box).create();
  // ~QDoubleSpinBox();
  bind::destructor<QDoubleSpinBox>(double_spin_box).create();
  // double value() const;
  bind::member_function<QDoubleSpinBox, double, &QDoubleSpinBox::value>(double_spin_box, "value").create();
  // QString prefix() const;
  bind::member_function<QDoubleSpinBox, QString, &QDoubleSpinBox::prefix>(double_spin_box, "prefix").create();
  // void setPrefix(const QString &);
  bind::void_member_function<QDoubleSpinBox, const QString &, &QDoubleSpinBox::setPrefix>(double_spin_box, "setPrefix").create();
  // QString suffix() const;
  bind::member_function<QDoubleSpinBox, QString, &QDoubleSpinBox::suffix>(double_spin_box, "suffix").create();
  // void setSuffix(const QString &);
  bind::void_member_function<QDoubleSpinBox, const QString &, &QDoubleSpinBox::setSuffix>(double_spin_box, "setSuffix").create();
  // QString cleanText() const;
  bind::member_function<QDoubleSpinBox, QString, &QDoubleSpinBox::cleanText>(double_spin_box, "cleanText").create();
  // double singleStep() const;
  bind::member_function<QDoubleSpinBox, double, &QDoubleSpinBox::singleStep>(double_spin_box, "singleStep").create();
  // void setSingleStep(double);
  bind::void_member_function<QDoubleSpinBox, double, &QDoubleSpinBox::setSingleStep>(double_spin_box, "setSingleStep").create();
  // double minimum() const;
  bind::member_function<QDoubleSpinBox, double, &QDoubleSpinBox::minimum>(double_spin_box, "minimum").create();
  // void setMinimum(double);
  bind::void_member_function<QDoubleSpinBox, double, &QDoubleSpinBox::setMinimum>(double_spin_box, "setMinimum").create();
  // double maximum() const;
  bind::member_function<QDoubleSpinBox, double, &QDoubleSpinBox::maximum>(double_spin_box, "maximum").create();
  // void setMaximum(double);
  bind::void_member_function<QDoubleSpinBox, double, &QDoubleSpinBox::setMaximum>(double_spin_box, "setMaximum").create();
  // void setRange(double, double);
  bind::void_member_function<QDoubleSpinBox, double, double, &QDoubleSpinBox::setRange>(double_spin_box, "setRange").create();
  // int decimals() const;
  bind::member_function<QDoubleSpinBox, int, &QDoubleSpinBox::decimals>(double_spin_box, "decimals").create();
  // void setDecimals(int);
  bind::void_member_function<QDoubleSpinBox, int, &QDoubleSpinBox::setDecimals>(double_spin_box, "setDecimals").create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QDoubleSpinBox, QValidator::State, QString &, int &, &QDoubleSpinBox::validate>(double_spin_box, "validate").create();
  // double valueFromText(const QString &) const;
  bind::member_function<QDoubleSpinBox, double, const QString &, &QDoubleSpinBox::valueFromText>(double_spin_box, "valueFromText").create();
  // QString textFromValue(double) const;
  bind::member_function<QDoubleSpinBox, QString, double, &QDoubleSpinBox::textFromValue>(double_spin_box, "textFromValue").create();
  // void fixup(QString &) const;
  bind::const_void_member_function<QDoubleSpinBox, QString &, &QDoubleSpinBox::fixup>(double_spin_box, "fixup").create();
  // void setValue(double);
  bind::void_member_function<QDoubleSpinBox, double, &QDoubleSpinBox::setValue>(double_spin_box, "setValue").create();
  // void valueChanged(double);
  bind::signal<QDoubleSpinBox, double>(double_spin_box, "valueChanged", "valueChanged(double)");
  // void valueChanged(const QString &);
  bind::signal<QDoubleSpinBox, const QString &>(double_spin_box, "valueChanged", "valueChanged(const QString &)");

  bind::link(double_spin_box, &QDoubleSpinBox::staticMetaObject);
}


void register_spinbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_spin_box_class(ns);
  register_double_spin_box_class(ns);

  // QSpinBox& newSpinBox(QWidget*);
  bind::new_function<QSpinBox, QWidget*>(ns, "newSpinBox");
  // QDoubleSpinBox& newDoubleSpinBox(QWidget*);
  bind::new_function<QDoubleSpinBox, QWidget*>(ns, "newDoubleSpinBox");
}

