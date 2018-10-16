// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/validator.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/locale.h"
#include "yasl/core/object.h"
#include "yasl/core/regularexpression.h"
#include "yasl/gui/validator.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_validator_state_enum(script::Class validator)
{
  using namespace script;

  Enum state = validator.Enum("State").setId(script::Type::QValidatorState).get();

  state.addValue("Invalid", QValidator::Invalid);
  state.addValue("Intermediate", QValidator::Intermediate);
  state.addValue("Acceptable", QValidator::Acceptable);
}


static void register_validator_class(script::Namespace ns)
{
  using namespace script;

  Class validator = ns.Class("Validator").setId(script::Type::QValidator)
    .setBase(script::Type::QObject).get();

  register_validator_state_enum(validator);
  binding::QClass<QValidator> binder{ validator, &QValidator::staticMetaObject };

  // ~QValidator();
  binder.add_dtor();
  // void setLocale(const QLocale &);
  binder.void_fun<const QLocale &, &QValidator::setLocale>("setLocale").create();
  // QLocale locale() const;
  binder.fun<QLocale, &QValidator::locale>("locale").create();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QValidator::validate>("validate").create();
  // void fixup(QString &) const;
  binder.const_void_fun<QString &, &QValidator::fixup>("fixup").create();
  // void changed();
  binder.sigs().add("changed", "changed()");

  validator.engine()->registerQtType(&QValidator::staticMetaObject, validator.id());
}


static void register_int_validator_class(script::Namespace ns)
{
  using namespace script;

  Class int_validator = ns.Class("IntValidator").setId(script::Type::QIntValidator)
    .setBase(script::Type::QValidator).get();

  binding::QClass<QIntValidator> binder{ int_validator, &QIntValidator::staticMetaObject };

  // QIntValidator(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // QIntValidator(int, int, QObject *);
  binder.ctors().ctor<int, int, QObject *>().create();
  // ~QIntValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QIntValidator::validate>("validate").create();
  // void fixup(QString &) const;
  binder.const_void_fun<QString &, &QIntValidator::fixup>("fixup").create();
  // void setBottom(int);
  binder.void_fun<int, &QIntValidator::setBottom>("setBottom").create();
  // void setTop(int);
  binder.void_fun<int, &QIntValidator::setTop>("setTop").create();
  // void setRange(int, int);
  binder.void_fun<int, int, &QIntValidator::setRange>("setRange").create();
  // int bottom() const;
  binder.fun<int, &QIntValidator::bottom>("bottom").create();
  // int top() const;
  binder.fun<int, &QIntValidator::top>("top").create();
  // void bottomChanged(int);
  binder.void_fun<int, &QIntValidator::bottomChanged>("bottomChanged").create();
  // void topChanged(int);
  binder.void_fun<int, &QIntValidator::topChanged>("topChanged").create();

  int_validator.engine()->registerQtType(&QIntValidator::staticMetaObject, int_validator.id());
}


static void register_double_validator_notation_enum(script::Class double_validator)
{
  using namespace script;

  Enum notation = double_validator.Enum("Notation").setId(script::Type::QDoubleValidatorNotation).get();

  notation.addValue("StandardNotation", QDoubleValidator::StandardNotation);
  notation.addValue("ScientificNotation", QDoubleValidator::ScientificNotation);
}


static void register_double_validator_class(script::Namespace ns)
{
  using namespace script;

  Class double_validator = ns.Class("DoubleValidator").setId(script::Type::QDoubleValidator)
    .setBase(script::Type::QValidator).get();

  register_double_validator_notation_enum(double_validator);
  binding::QClass<QDoubleValidator> binder{ double_validator, &QDoubleValidator::staticMetaObject };

  // QDoubleValidator(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // QDoubleValidator(double, double, int, QObject *);
  binder.ctors().ctor<double, double, int, QObject *>().create();
  // ~QDoubleValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QDoubleValidator::validate>("validate").create();
  // void setRange(double, double, int);
  binder.void_fun<double, double, int, &QDoubleValidator::setRange>("setRange").create();
  // void setBottom(double);
  binder.void_fun<double, &QDoubleValidator::setBottom>("setBottom").create();
  // void setTop(double);
  binder.void_fun<double, &QDoubleValidator::setTop>("setTop").create();
  // void setDecimals(int);
  binder.void_fun<int, &QDoubleValidator::setDecimals>("setDecimals").create();
  // void setNotation(QDoubleValidator::Notation);
  binder.void_fun<QDoubleValidator::Notation, &QDoubleValidator::setNotation>("setNotation").create();
  // double bottom() const;
  binder.fun<double, &QDoubleValidator::bottom>("bottom").create();
  // double top() const;
  binder.fun<double, &QDoubleValidator::top>("top").create();
  // int decimals() const;
  binder.fun<int, &QDoubleValidator::decimals>("decimals").create();
  // QDoubleValidator::Notation notation() const;
  binder.fun<QDoubleValidator::Notation, &QDoubleValidator::notation>("notation").create();
  // void bottomChanged(double);
  binder.void_fun<double, &QDoubleValidator::bottomChanged>("bottomChanged").create();
  // void topChanged(double);
  binder.void_fun<double, &QDoubleValidator::topChanged>("topChanged").create();
  // void decimalsChanged(int);
  binder.void_fun<int, &QDoubleValidator::decimalsChanged>("decimalsChanged").create();
  // void notationChanged(QDoubleValidator::Notation);
  binder.void_fun<QDoubleValidator::Notation, &QDoubleValidator::notationChanged>("notationChanged").create();

  double_validator.engine()->registerQtType(&QDoubleValidator::staticMetaObject, double_validator.id());
}


static void register_regular_expression_validator_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_validator = ns.Class("RegularExpressionValidator").setId(script::Type::QRegularExpressionValidator)
    .setBase(script::Type::QValidator).get();

  binding::QClass<QRegularExpressionValidator> binder{ regular_expression_validator, &QRegularExpressionValidator::staticMetaObject };

  // QRegularExpressionValidator(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // QRegularExpressionValidator(const QRegularExpression &, QObject *);
  binder.ctors().ctor<const QRegularExpression &, QObject *>().create();
  // ~QRegularExpressionValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.fun<QValidator::State, QString &, int &, &QRegularExpressionValidator::validate>("validate").create();
  // QRegularExpression regularExpression() const;
  binder.fun<QRegularExpression, &QRegularExpressionValidator::regularExpression>("regularExpression").create();
  // void setRegularExpression(const QRegularExpression &);
  binder.void_fun<const QRegularExpression &, &QRegularExpressionValidator::setRegularExpression>("setRegularExpression").create();
  // void regularExpressionChanged(const QRegularExpression &);
  binder.void_fun<const QRegularExpression &, &QRegularExpressionValidator::regularExpressionChanged>("regularExpressionChanged").create();

  regular_expression_validator.engine()->registerQtType(&QRegularExpressionValidator::staticMetaObject, regular_expression_validator.id());
}


void register_validator_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_validator_class(ns);
  register_int_validator_class(ns);
  register_double_validator_class(ns);
  register_regular_expression_validator_class(ns);
  binding::Namespace binder{ ns };

}

