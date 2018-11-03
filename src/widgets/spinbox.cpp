// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/spinbox.h"

#include "yasl/binding/default_arguments.h"
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

  binding::ClassBinder<QSpinBox> binder{ spin_box, &QSpinBox::staticMetaObject };

  // QSpinBox(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QSpinBox();
  binder.dtor().create();
  // int value() const;
  binder.fun<int, &QSpinBox::value>("value").create();
  // QString prefix() const;
  binder.fun<QString, &QSpinBox::prefix>("prefix").create();
  // void setPrefix(const QString &);
  binder.void_fun<const QString &, &QSpinBox::setPrefix>("setPrefix").create();
  // QString suffix() const;
  binder.fun<QString, &QSpinBox::suffix>("suffix").create();
  // void setSuffix(const QString &);
  binder.void_fun<const QString &, &QSpinBox::setSuffix>("setSuffix").create();
  // QString cleanText() const;
  binder.fun<QString, &QSpinBox::cleanText>("cleanText").create();
  // int singleStep() const;
  binder.fun<int, &QSpinBox::singleStep>("singleStep").create();
  // void setSingleStep(int);
  binder.void_fun<int, &QSpinBox::setSingleStep>("setSingleStep").create();
  // int minimum() const;
  binder.fun<int, &QSpinBox::minimum>("minimum").create();
  // void setMinimum(int);
  binder.void_fun<int, &QSpinBox::setMinimum>("setMinimum").create();
  // int maximum() const;
  binder.fun<int, &QSpinBox::maximum>("maximum").create();
  // void setMaximum(int);
  binder.void_fun<int, &QSpinBox::setMaximum>("setMaximum").create();
  // void setRange(int, int);
  binder.void_fun<int, int, &QSpinBox::setRange>("setRange").create();
  // int displayIntegerBase() const;
  binder.fun<int, &QSpinBox::displayIntegerBase>("displayIntegerBase").create();
  // void setDisplayIntegerBase(int);
  binder.void_fun<int, &QSpinBox::setDisplayIntegerBase>("setDisplayIntegerBase").create();
  // void setValue(int);
  binder.void_fun<int, &QSpinBox::setValue>("setValue").create();
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

  binding::ClassBinder<QDoubleSpinBox> binder{ double_spin_box, &QDoubleSpinBox::staticMetaObject };

  // QDoubleSpinBox(QWidget *);
  binder.ctor<QWidget *>().create();
  // ~QDoubleSpinBox();
  binder.dtor().create();
  // double value() const;
  binder.fun<double, &QDoubleSpinBox::value>("value").create();
  // QString prefix() const;
  binder.fun<QString, &QDoubleSpinBox::prefix>("prefix").create();
  // void setPrefix(const QString &);
  binder.void_fun<const QString &, &QDoubleSpinBox::setPrefix>("setPrefix").create();
  // QString suffix() const;
  binder.fun<QString, &QDoubleSpinBox::suffix>("suffix").create();
  // void setSuffix(const QString &);
  binder.void_fun<const QString &, &QDoubleSpinBox::setSuffix>("setSuffix").create();
  // QString cleanText() const;
  binder.fun<QString, &QDoubleSpinBox::cleanText>("cleanText").create();
  // double singleStep() const;
  binder.fun<double, &QDoubleSpinBox::singleStep>("singleStep").create();
  // void setSingleStep(double);
  binder.void_fun<double, &QDoubleSpinBox::setSingleStep>("setSingleStep").create();
  // double minimum() const;
  binder.fun<double, &QDoubleSpinBox::minimum>("minimum").create();
  // void setMinimum(double);
  binder.void_fun<double, &QDoubleSpinBox::setMinimum>("setMinimum").create();
  // double maximum() const;
  binder.fun<double, &QDoubleSpinBox::maximum>("maximum").create();
  // void setMaximum(double);
  binder.void_fun<double, &QDoubleSpinBox::setMaximum>("setMaximum").create();
  // void setRange(double, double);
  binder.void_fun<double, double, &QDoubleSpinBox::setRange>("setRange").create();
  // int decimals() const;
  binder.fun<int, &QDoubleSpinBox::decimals>("decimals").create();
  // void setDecimals(int);
  binder.void_fun<int, &QDoubleSpinBox::setDecimals>("setDecimals").create();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QDoubleSpinBox::validate>("validate").create();
  // double valueFromText(const QString &) const;
  binder.fun<double, const QString &, &QDoubleSpinBox::valueFromText>("valueFromText").create();
  // QString textFromValue(double) const;
  binder.fun<QString, double, &QDoubleSpinBox::textFromValue>("textFromValue").create();
  // void fixup(QString &) const;
  binder.const_void_fun<QString &, &QDoubleSpinBox::fixup>("fixup").create();
  // void setValue(double);
  binder.void_fun<double, &QDoubleSpinBox::setValue>("setValue").create();
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

