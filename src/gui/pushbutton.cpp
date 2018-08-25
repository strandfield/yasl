// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pushbutton.h"

#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"

#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/value.h>

namespace callbacks
{

static script::Value new_pushbutton(script::FunctionCall *c)
{
  using namespace script;
  Type type = c->callee().returnType().baseType();
  Value v = c->engine()->construct(type, {});
  return v;
}


static script::Value new_pushbutton_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<QWidget*>(c->arg(0)));
  return c->engine()->expose(object, c->callee().returnType().baseType());
}

static script::Value new_pushbutton_text(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)));
  return c->engine()->expose(object, c->callee().returnType().baseType());
}

static script::Value new_pushbutton_text_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)), value_cast<QWidget*>(c->arg(1)));
  return c->engine()->expose(object, c->callee().returnType().baseType());
}

} // namespace callbacks


void register_qpushbutton(script::Namespace n)
{
  using namespace script;

  Class pushbutton = n.Class("PushButton").setId(Type::QPushButton).setBase(script::Type::QAbstractButton).get();
  Type pushbutton_type = pushbutton.id();

  auto qpushbutton = binding::QClass<QPushButton>{ pushbutton, &QPushButton::staticMetaObject };
  qpushbutton.ctors().add_default();
  qpushbutton.ctors().add<QWidget*>();
  qpushbutton.ctors().add<const QString &>();
  qpushbutton.ctors().add<const QString &, QWidget*>();
  qpushbutton.add_dtor();

  /* QPushButton members */
  // bool autoDefault() const
  qpushbutton.add_fun<bool, &QPushButton::autoDefault>("autoDefault");
  // bool isDefault() const
  qpushbutton.add_fun<bool, &QPushButton::isDefault>("isDefault");
  // bool isFlat() const
  qpushbutton.add_fun<bool, &QPushButton::isFlat>("isFlat");
  // QMenu * menu() const
  // void setAutoDefault(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setAutoDefault>("setAutoDefault");
  // void setDefault(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setDefault>("setDefault");
  // void setFlat(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setFlat>("setFlat");
  // void setMenu(QMenu *menu)

  qpushbutton.sigs().add("clicked", Q_SIGNAL("clicked()"));

  n.Function("newPushButton", callbacks::new_pushbutton)
    .returns(Type::ref(pushbutton_type))
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_parent)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<QWidget*>())
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_text)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<const QString &>())
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_text_parent)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<const QString &>(), binding::make_type<QWidget*>())
    .create();

  n.engine()->registerQtType(&QPushButton::staticMetaObject, pushbutton_type);
}

