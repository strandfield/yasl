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
  binder.add_void_fun<const QLocale &, &QValidator::setLocale>("setLocale");
  // QLocale locale() const;
  binder.add_fun<QLocale, &QValidator::locale>("locale");
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QValidator::validate>("validate");
  // void fixup(QString &) const;
  binder.add_const_void_fun<QString &, &QValidator::fixup>("fixup");
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
  binder.ctors().add<QObject *>();
  // QIntValidator(int, int, QObject *);
  binder.ctors().add<int, int, QObject *>();
  // ~QIntValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QIntValidator::validate>("validate");
  // void fixup(QString &) const;
  binder.add_const_void_fun<QString &, &QIntValidator::fixup>("fixup");
  // void setBottom(int);
  binder.add_void_fun<int, &QIntValidator::setBottom>("setBottom");
  // void setTop(int);
  binder.add_void_fun<int, &QIntValidator::setTop>("setTop");
  // void setRange(int, int);
  binder.add_void_fun<int, int, &QIntValidator::setRange>("setRange");
  // int bottom() const;
  binder.add_fun<int, &QIntValidator::bottom>("bottom");
  // int top() const;
  binder.add_fun<int, &QIntValidator::top>("top");
  // void bottomChanged(int);
  binder.add_void_fun<int, &QIntValidator::bottomChanged>("bottomChanged");
  // void topChanged(int);
  binder.add_void_fun<int, &QIntValidator::topChanged>("topChanged");

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
  binder.ctors().add<QObject *>();
  // QDoubleValidator(double, double, int, QObject *);
  binder.ctors().add<double, double, int, QObject *>();
  // ~QDoubleValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QDoubleValidator::validate>("validate");
  // void setRange(double, double, int);
  binder.add_void_fun<double, double, int, &QDoubleValidator::setRange>("setRange");
  // void setBottom(double);
  binder.add_void_fun<double, &QDoubleValidator::setBottom>("setBottom");
  // void setTop(double);
  binder.add_void_fun<double, &QDoubleValidator::setTop>("setTop");
  // void setDecimals(int);
  binder.add_void_fun<int, &QDoubleValidator::setDecimals>("setDecimals");
  // void setNotation(QDoubleValidator::Notation);
  binder.add_void_fun<QDoubleValidator::Notation, &QDoubleValidator::setNotation>("setNotation");
  // double bottom() const;
  binder.add_fun<double, &QDoubleValidator::bottom>("bottom");
  // double top() const;
  binder.add_fun<double, &QDoubleValidator::top>("top");
  // int decimals() const;
  binder.add_fun<int, &QDoubleValidator::decimals>("decimals");
  // QDoubleValidator::Notation notation() const;
  binder.add_fun<QDoubleValidator::Notation, &QDoubleValidator::notation>("notation");
  // void bottomChanged(double);
  binder.add_void_fun<double, &QDoubleValidator::bottomChanged>("bottomChanged");
  // void topChanged(double);
  binder.add_void_fun<double, &QDoubleValidator::topChanged>("topChanged");
  // void decimalsChanged(int);
  binder.add_void_fun<int, &QDoubleValidator::decimalsChanged>("decimalsChanged");
  // void notationChanged(QDoubleValidator::Notation);
  binder.add_void_fun<QDoubleValidator::Notation, &QDoubleValidator::notationChanged>("notationChanged");

  double_validator.engine()->registerQtType(&QDoubleValidator::staticMetaObject, double_validator.id());
}


static void register_regular_expression_validator_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_validator = ns.Class("RegularExpressionValidator").setId(script::Type::QRegularExpressionValidator)
    .setBase(script::Type::QValidator).get();

  binding::QClass<QRegularExpressionValidator> binder{ regular_expression_validator, &QRegularExpressionValidator::staticMetaObject };

  // QRegularExpressionValidator(QObject *);
  binder.ctors().add<QObject *>();
  // QRegularExpressionValidator(const QRegularExpression &, QObject *);
  binder.ctors().add<const QRegularExpression &, QObject *>();
  // ~QRegularExpressionValidator();
  binder.add_dtor();
  // QValidator::State validate(QString &, int &) const;
  binder.add_fun<QValidator::State, QString &, int &, &QRegularExpressionValidator::validate>("validate");
  // QRegularExpression regularExpression() const;
  binder.add_fun<QRegularExpression, &QRegularExpressionValidator::regularExpression>("regularExpression");
  // void setRegularExpression(const QRegularExpression &);
  binder.add_void_fun<const QRegularExpression &, &QRegularExpressionValidator::setRegularExpression>("setRegularExpression");
  // void regularExpressionChanged(const QRegularExpression &);
  binder.add_void_fun<const QRegularExpression &, &QRegularExpressionValidator::regularExpressionChanged>("regularExpressionChanged");

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

