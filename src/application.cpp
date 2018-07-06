// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/application.h"

#include "yasl/core/coremodule.h"
#include "yasl/core/object.h"
#include "yasl/gui/guimodule.h"
#include "yasl/utils/expose.h"
#include "yasl/utils/ref.h"

#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>

#include <QDebug>

#include <iostream>

namespace callbacks
{

script::Value print_int(script::FunctionCall *c)
{
  qDebug() << c->arg(0).toInt();
  return script::Value::Void;
}

script::Value print_bool(script::FunctionCall *c)
{
  qDebug() << c->arg(0).toBool();
  return script::Value::Void;
}

script::Value print_double(script::FunctionCall *c)
{
  qDebug() << c->arg(0).toDouble();
  return script::Value::Void;
}

script::Value print_string(script::FunctionCall *c)
{
  qDebug() << c->arg(0).toString();
  return script::Value::Void;
}

}

Application::Application(int & argc, char **argv)
  : QApplication(argc, argv)
{
  mEngine.setup();

  register_ref_template(mEngine.rootNamespace());

  register_core_module(&mEngine);
  register_gui_module(&mEngine);

  mEngine.rootNamespace().Function("print", callbacks::print_int)
    .params(script::Type::Int).create();

  mEngine.rootNamespace().Function("print", callbacks::print_bool)
    .params(script::Type::Boolean).create();

  mEngine.rootNamespace().Function("print", callbacks::print_double)
    .params(script::Type::Double).create();

  mEngine.rootNamespace().Function("print", callbacks::print_string)
    .params(script::Type::cref(script::Type::String)).create();
}

void Application::registerObjectType(const QMetaObject *mo, const script::Type & type)
{
  qApp->mTypeMap.insert(mo, type);
}

void Application::run(const script::SourceFile & src)
{
  script::Script s = mEngine.newScript(src);
  if (!s.compile())
  {
    for (const auto & e : s.messages())
    {
      qDebug() << e.to_string().data();
    }
  }
  else
  {
    s.run();
  }
}

void Application::interactive()
{
  std::string command;
  for(;;)
  {
    std::cout << ">>> ";
    std::getline(std::cin, command);

    if (command == ":q")
      return;
    else
      mEngine.eval(command);
  }
}

script::Value Application::expose(QObject *obj)
{
  QVariant binding_data = obj->property("_yasl_data_");
  if (binding_data.isValid())
    return binding_data.value<binding::BindingData>().value;

  script::Type t = qApp->get_type(obj->metaObject());
  script::Value ret = qApp->scriptEngine()->uninitialized(t);
  ret.impl()->type = ret.impl()->type.withoutFlag(script::Type::UninitializedFlag);
  ret.impl()->set_qobject(obj);
  obj->setProperty("_yasl_data_", QVariant::fromValue(binding::BindingData{ ret }));
  return ret;
}

script::ClassTemplate Application::getListTemplate() const
{
  return mListTemplate;
}

void Application::setListTemplate(const script::ClassTemplate & list)
{
  mListTemplate = list;
}

script::ClassTemplate Application::getPtrTemplate() const
{
  return mPtrTemplate;
}

void Application::setPtrTemplate(const script::ClassTemplate & ptr)
{
  mPtrTemplate = ptr;
}

script::Type Application::get_type(const QMetaObject *mo)
{
  if (mo == nullptr)
    return script::Type::Null; /// TODO : throw ?

  script::Type t = mTypeMap.value(mo, script::Type::Null);
  if (!t.isNull())
    return t;

  return get_type(mo->superClass());
}