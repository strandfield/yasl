// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/application.h"

#include "yasl/core/object.h"
#include "yasl/utils/ref.h"

#include <script/functionbuilder.h>
#include <script/namespace.h>
#include <script/script.h>

#include <script/interpreter/executioncontext.h>

#include <QDebug>

#include <iostream>

void register_core_module(script::Engine*); // defined in coremodule.cpp
void register_gui_module(script::Engine*); // defined in guimodule.cpp
void register_widgets_module(script::Engine*); // defined in widgets.cpp

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

  mEngine.reserveTypeRange(script::Type::FirstEnumType, script::Type::LastEnumType);
  mEngine.reserveTypeRange(script::Type::FirstClassType, script::Type::LastClassType);

  register_ref_template(mEngine.rootNamespace());

  register_core_module(&mEngine);
  register_gui_module(&mEngine);
  register_widgets_module(&mEngine);

  mEngine.rootNamespace().Function("print", callbacks::print_int)
    .params(script::Type::Int).create();

  mEngine.rootNamespace().Function("print", callbacks::print_bool)
    .params(script::Type::Boolean).create();

  mEngine.rootNamespace().Function("print", callbacks::print_double)
    .params(script::Type::Double).create();

  mEngine.rootNamespace().Function("print", callbacks::print_string)
    .params(script::Type::cref(script::Type::String)).create();
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
