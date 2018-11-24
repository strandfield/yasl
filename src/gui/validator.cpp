// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/validator.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/locale.h"
#include "yasl/core/object.h"
#include "yasl/core/regularexpression.h"
#include "yasl/gui/validator.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_validator_state_enum(script::Class validator)
{
  using namespace script;

  Enum state = validator.newEnum("State").setId(script::Type::QValidatorState).get();

  state.addValue("Invalid", QValidator::Invalid);
  state.addValue("Intermediate", QValidator::Intermediate);
  state.addValue("Acceptable", QValidator::Acceptable);
}


static void register_validator_class(script::Namespace ns)
{
  using namespace script;

  Class validator = ns.newClass("Validator").setId(script::Type::QValidator)
    .setBase(script::Type::QObject).get();

  register_validator_state_enum(validator);

  // ~QValidator();
  bind::destructor<QValidator>(validator).create();
  // void setLocale(const QLocale &);
  bind::void_member_function<QValidator, const QLocale &, &QValidator::setLocale>(validator, "setLocale").create();
  // QLocale locale() const;
  bind::member_function<QValidator, QLocale, &QValidator::locale>(validator, "locale").create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QValidator, QValidator::State, QString &, int &, &QValidator::validate>(validator, "validate").create();
  // void fixup(QString &) const;
  bind::const_void_member_function<QValidator, QString &, &QValidator::fixup>(validator, "fixup").create();
  // void changed();
  bind::signal<QValidator>(validator, "changed", "changed()");

  bind::link(validator, &QValidator::staticMetaObject);
}


static void register_int_validator_class(script::Namespace ns)
{
  using namespace script;

  Class int_validator = ns.newClass("IntValidator").setId(script::Type::QIntValidator)
    .setBase(script::Type::QValidator).get();


  // QIntValidator(QObject *);
  bind::constructor<QIntValidator, QObject *>(int_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QIntValidator(int, int, QObject *);
  bind::constructor<QIntValidator, int, int, QObject *>(int_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QIntValidator();
  bind::destructor<QIntValidator>(int_validator).create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QIntValidator, QValidator::State, QString &, int &, &QIntValidator::validate>(int_validator, "validate").create();
  // void fixup(QString &) const;
  bind::const_void_member_function<QIntValidator, QString &, &QIntValidator::fixup>(int_validator, "fixup").create();
  // void setBottom(int);
  bind::void_member_function<QIntValidator, int, &QIntValidator::setBottom>(int_validator, "setBottom").create();
  // void setTop(int);
  bind::void_member_function<QIntValidator, int, &QIntValidator::setTop>(int_validator, "setTop").create();
  // void setRange(int, int);
  bind::void_member_function<QIntValidator, int, int, &QIntValidator::setRange>(int_validator, "setRange").create();
  // int bottom() const;
  bind::member_function<QIntValidator, int, &QIntValidator::bottom>(int_validator, "bottom").create();
  // int top() const;
  bind::member_function<QIntValidator, int, &QIntValidator::top>(int_validator, "top").create();
  // void bottomChanged(int);
  bind::void_member_function<QIntValidator, int, &QIntValidator::bottomChanged>(int_validator, "bottomChanged").create();
  // void topChanged(int);
  bind::void_member_function<QIntValidator, int, &QIntValidator::topChanged>(int_validator, "topChanged").create();

  bind::link(int_validator, &QIntValidator::staticMetaObject);
}


static void register_double_validator_notation_enum(script::Class double_validator)
{
  using namespace script;

  Enum notation = double_validator.newEnum("Notation").setId(script::Type::QDoubleValidatorNotation).get();

  notation.addValue("StandardNotation", QDoubleValidator::StandardNotation);
  notation.addValue("ScientificNotation", QDoubleValidator::ScientificNotation);
}


static void register_double_validator_class(script::Namespace ns)
{
  using namespace script;

  Class double_validator = ns.newClass("DoubleValidator").setId(script::Type::QDoubleValidator)
    .setBase(script::Type::QValidator).get();

  register_double_validator_notation_enum(double_validator);

  // QDoubleValidator(QObject *);
  bind::constructor<QDoubleValidator, QObject *>(double_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QDoubleValidator(double, double, int, QObject *);
  bind::constructor<QDoubleValidator, double, double, int, QObject *>(double_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QDoubleValidator();
  bind::destructor<QDoubleValidator>(double_validator).create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QDoubleValidator, QValidator::State, QString &, int &, &QDoubleValidator::validate>(double_validator, "validate").create();
  // void setRange(double, double, int);
  bind::void_member_function<QDoubleValidator, double, double, int, &QDoubleValidator::setRange>(double_validator, "setRange")
    .apply(bind::default_arguments(0)).create();
  // void setBottom(double);
  bind::void_member_function<QDoubleValidator, double, &QDoubleValidator::setBottom>(double_validator, "setBottom").create();
  // void setTop(double);
  bind::void_member_function<QDoubleValidator, double, &QDoubleValidator::setTop>(double_validator, "setTop").create();
  // void setDecimals(int);
  bind::void_member_function<QDoubleValidator, int, &QDoubleValidator::setDecimals>(double_validator, "setDecimals").create();
  // void setNotation(QDoubleValidator::Notation);
  bind::void_member_function<QDoubleValidator, QDoubleValidator::Notation, &QDoubleValidator::setNotation>(double_validator, "setNotation").create();
  // double bottom() const;
  bind::member_function<QDoubleValidator, double, &QDoubleValidator::bottom>(double_validator, "bottom").create();
  // double top() const;
  bind::member_function<QDoubleValidator, double, &QDoubleValidator::top>(double_validator, "top").create();
  // int decimals() const;
  bind::member_function<QDoubleValidator, int, &QDoubleValidator::decimals>(double_validator, "decimals").create();
  // QDoubleValidator::Notation notation() const;
  bind::member_function<QDoubleValidator, QDoubleValidator::Notation, &QDoubleValidator::notation>(double_validator, "notation").create();
  // void bottomChanged(double);
  bind::void_member_function<QDoubleValidator, double, &QDoubleValidator::bottomChanged>(double_validator, "bottomChanged").create();
  // void topChanged(double);
  bind::void_member_function<QDoubleValidator, double, &QDoubleValidator::topChanged>(double_validator, "topChanged").create();
  // void decimalsChanged(int);
  bind::void_member_function<QDoubleValidator, int, &QDoubleValidator::decimalsChanged>(double_validator, "decimalsChanged").create();
  // void notationChanged(QDoubleValidator::Notation);
  bind::void_member_function<QDoubleValidator, QDoubleValidator::Notation, &QDoubleValidator::notationChanged>(double_validator, "notationChanged").create();

  bind::link(double_validator, &QDoubleValidator::staticMetaObject);
}


static void register_regular_expression_validator_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_validator = ns.newClass("RegularExpressionValidator").setId(script::Type::QRegularExpressionValidator)
    .setBase(script::Type::QValidator).get();


  // QRegularExpressionValidator(QObject *);
  bind::constructor<QRegularExpressionValidator, QObject *>(regular_expression_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QRegularExpressionValidator(const QRegularExpression &, QObject *);
  bind::constructor<QRegularExpressionValidator, const QRegularExpression &, QObject *>(regular_expression_validator)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QRegularExpressionValidator();
  bind::destructor<QRegularExpressionValidator>(regular_expression_validator).create();
  // QValidator::State validate(QString &, int &) const;
  bind::member_function<QRegularExpressionValidator, QValidator::State, QString &, int &, &QRegularExpressionValidator::validate>(regular_expression_validator, "validate").create();
  // QRegularExpression regularExpression() const;
  bind::member_function<QRegularExpressionValidator, QRegularExpression, &QRegularExpressionValidator::regularExpression>(regular_expression_validator, "regularExpression").create();
  // void setRegularExpression(const QRegularExpression &);
  bind::void_member_function<QRegularExpressionValidator, const QRegularExpression &, &QRegularExpressionValidator::setRegularExpression>(regular_expression_validator, "setRegularExpression").create();
  // void regularExpressionChanged(const QRegularExpression &);
  bind::void_member_function<QRegularExpressionValidator, const QRegularExpression &, &QRegularExpressionValidator::regularExpressionChanged>(regular_expression_validator, "regularExpressionChanged").create();

  bind::link(regular_expression_validator, &QRegularExpressionValidator::staticMetaObject);
}


void register_validator_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_validator_class(ns);
  register_int_validator_class(ns);
  register_double_validator_class(ns);
  register_regular_expression_validator_class(ns);

}

