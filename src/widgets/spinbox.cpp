// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/spinbox.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/gui/validator.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class spin_box = ns.Class("SpinBox").setId(script::Type::QSpinBox)
    .setBase(script::Type::QAbstractSpinBox).get();

  binding::QClass<QSpinBox> binder{ spin_box, &QSpinBox::staticMetaObject };

  // QSpinBox(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QSpinBox();
  binder.add_dtor();
  // int value() const;
  binder.add_fun<int, &QSpinBox::value>("value");
  // QString prefix() const;
  binder.add_fun<QString, &QSpinBox::prefix>("prefix");
  // void setPrefix(const QString &);
  binder.add_void_fun<const QString &, &QSpinBox::setPrefix>("setPrefix");
  // QString suffix() const;
  binder.add_fun<QString, &QSpinBox::suffix>("suffix");
  // void setSuffix(const QString &);
  binder.add_void_fun<const QString &, &QSpinBox::setSuffix>("setSuffix");
  // QString cleanText() const;
  binder.add_fun<QString, &QSpinBox::cleanText>("cleanText");
  // int singleStep() const;
  binder.add_fun<int, &QSpinBox::singleStep>("singleStep");
  // void setSingleStep(int);
  binder.add_void_fun<int, &QSpinBox::setSingleStep>("setSingleStep");
  // int minimum() const;
  binder.add_fun<int, &QSpinBox::minimum>("minimum");
  // void setMinimum(int);
  binder.add_void_fun<int, &QSpinBox::setMinimum>("setMinimum");
  // int maximum() const;
  binder.add_fun<int, &QSpinBox::maximum>("maximum");
  // void setMaximum(int);
  binder.add_void_fun<int, &QSpinBox::setMaximum>("setMaximum");
  // void setRange(int, int);
  binder.add_void_fun<int, int, &QSpinBox::setRange>("setRange");
  // int displayIntegerBase() const;
  binder.add_fun<int, &QSpinBox::displayIntegerBase>("displayIntegerBase");
  // void setDisplayIntegerBase(int);
  binder.add_void_fun<int, &QSpinBox::setDisplayIntegerBase>("setDisplayIntegerBase");
  // void setValue(int);
  binder.add_void_fun<int, &QSpinBox::setValue>("setValue");
  // void valueChanged(int);
  binder.sigs().add<int>("valueChanged", "valueChanged(int)");
  // void valueChanged(const QString &);
  binder.sigs().add<const QString &>("valueChanged", "valueChanged(const QString &)");

  spin_box.engine()->registerQtType(&QSpinBox::staticMetaObject, spin_box.id());
}


static void register_double_spin_box_class(script::Namespace ns)
{
  using namespace script;

  Class double_spin_box = ns.Class("DoubleSpinBox").setId(script::Type::QDoubleSpinBox)
    .setBase(script::Type::QAbstractSpinBox).get();

  binding::QClass<QDoubleSpinBox> binder{ double_spin_box, &QDoubleSpinBox::staticMetaObject };

  // QDoubleSpinBox(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QDoubleSpinBox();
  binder.add_dtor();
  // double value() const;
  binder.add_fun<double, &QDoubleSpinBox::value>("value");
  // QString prefix() const;
  binder.add_fun<QString, &QDoubleSpinBox::prefix>("prefix");
  // void setPrefix(const QString &);
  binder.add_void_fun<const QString &, &QDoubleSpinBox::setPrefix>("setPrefix");
  // QString suffix() const;
  binder.add_fun<QString, &QDoubleSpinBox::suffix>("suffix");
  // void setSuffix(const QString &);
  binder.add_void_fun<const QString &, &QDoubleSpinBox::setSuffix>("setSuffix");
  // QString cleanText() const;
  binder.add_fun<QString, &QDoubleSpinBox::cleanText>("cleanText");
  // double singleStep() const;
  binder.add_fun<double, &QDoubleSpinBox::singleStep>("singleStep");
  // void setSingleStep(double);
  binder.add_void_fun<double, &QDoubleSpinBox::setSingleStep>("setSingleStep");
  // double minimum() const;
  binder.add_fun<double, &QDoubleSpinBox::minimum>("minimum");
  // void setMinimum(double);
  binder.add_void_fun<double, &QDoubleSpinBox::setMinimum>("setMinimum");
  // double maximum() const;
  binder.add_fun<double, &QDoubleSpinBox::maximum>("maximum");
  // void setMaximum(double);
  binder.add_void_fun<double, &QDoubleSpinBox::setMaximum>("setMaximum");
  // void setRange(double, double);
  binder.add_void_fun<double, double, &QDoubleSpinBox::setRange>("setRange");
  // int decimals() const;
  binder.add_fun<int, &QDoubleSpinBox::decimals>("decimals");
  // void setDecimals(int);
  binder.add_void_fun<int, &QDoubleSpinBox::setDecimals>("setDecimals");
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QDoubleSpinBox::validate>("validate");
  // double valueFromText(const QString &) const;
  binder.add_fun<double, const QString &, &QDoubleSpinBox::valueFromText>("valueFromText");
  // QString textFromValue(double) const;
  binder.add_fun<QString, double, &QDoubleSpinBox::textFromValue>("textFromValue");
  // void fixup(QString &) const;
  binder.add_const_void_fun<QString &, &QDoubleSpinBox::fixup>("fixup");
  // void setValue(double);
  binder.add_void_fun<double, &QDoubleSpinBox::setValue>("setValue");
  // void valueChanged(double);
  binder.sigs().add<double>("valueChanged", "valueChanged(double)");
  // void valueChanged(const QString &);
  binder.sigs().add<const QString &>("valueChanged", "valueChanged(const QString &)");

  double_spin_box.engine()->registerQtType(&QDoubleSpinBox::staticMetaObject, double_spin_box.id());
}


void register_spinbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_spin_box_class(ns);
  register_double_spin_box_class(ns);
  binding::Namespace binder{ ns };

  // QSpinBox& newSpinBox(QWidget*);
  NewFunction(binder).add<QSpinBox, QWidget*>("newSpinBox");
  // QDoubleSpinBox& newDoubleSpinBox(QWidget*);
  NewFunction(binder).add<QDoubleSpinBox, QWidget*>("newDoubleSpinBox");
}

