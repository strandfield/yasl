// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/newpushbutton.h"

#include "yasl/widgets/widget.h"

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
  Value v = c->engine()->construct(script::Type::QPushButton, {});
  return v;
}

static script::Value new_pushbutton_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<QWidget*>(c->arg(0)));
  return c->engine()->expose(object, script::Type::QPushButton);
}

static script::Value new_pushbutton_text(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)));
  return c->engine()->expose(object, script::Type::QPushButton);
}

static script::Value new_pushbutton_text_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)), value_cast<QWidget*>(c->arg(1)));
  return c->engine()->expose(object, script::Type::QPushButton);
}

} // namespace callbacks


void register_newpushbutton_file(script::Namespace gui)
{
  using namespace script;

  gui.Function("newPushButton", callbacks::new_pushbutton)
    .returns(Type::ref(script::Type::QPushButton))
    .create();

  gui.Function("newPushButton", callbacks::new_pushbutton_parent)
    .returns(Type::ref(script::Type::QPushButton))
    .params(binding::make_type<QWidget*>())
    .create();

  gui.Function("newPushButton", callbacks::new_pushbutton_text)
    .returns(Type::ref(script::Type::QPushButton))
    .params(binding::make_type<const QString &>())
    .create();

  gui.Function("newPushButton", callbacks::new_pushbutton_text_parent)
    .returns(Type::ref(script::Type::QPushButton))
    .params(binding::make_type<const QString &>(), binding::make_type<QWidget*>())
    .create();
}
