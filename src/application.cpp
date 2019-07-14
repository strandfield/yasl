// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/application.h"

#include "yasl/consolelistener.h"

#include "yasl/core/object.h"
#include "yasl/common/commons.h"
#include "yasl/common/ref.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/context.h>
#include <script/functionbuilder.h>
#include <script/module.h>
#include <script/namespace.h>
#include <script/script.h>

#include <script/interpreter/executioncontext.h>

#include <QDebug>
#include <QtGlobal>

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

script::Value app_start(script::FunctionCall *c)
{
  qApp->setRunEventLoop(true);
  return script::Value::Void;
}

script::Value app_exit(script::FunctionCall *c)
{
  qApp->exit();
  return script::Value::Void;
}

script::Value app_qtVersion(script::FunctionCall *c)
{
  return c->engine()->newString(QString(QT_VERSION_STR));
}

script::Value app_loadModule(script::FunctionCall *c)
{
  script::Module m = c->engine()->getModule(c->arg(0).toString().toStdString());
  if (m.isNull())
  {
    qDebug() << "No such module: " << m.name().data();
    return script::Value::Void;
  }
  m.load();
  c->engine()->currentContext().use(m);
  return script::Value::Void;
}

}

Application::Application(int & argc, char **argv)
  : QApplication(argc, argv)
  , mRunEventLoop(false)
  , mConsoleListener(nullptr)
{
  mEngine.setup();

  register_commons_utils(&mEngine);

  /// TODO: move to register_common_utils
  script::register_ref_template(mEngine.rootNamespace());

  register_core_module(&mEngine);
  register_gui_module(&mEngine);
  register_widgets_module(&mEngine);

  mEngine.rootNamespace().newFunction("print", callbacks::print_int)
    .params(script::Type::Int).create();

  mEngine.rootNamespace().newFunction("print", callbacks::print_bool)
    .params(script::Type::Boolean).create();

  mEngine.rootNamespace().newFunction("print", callbacks::print_double)
    .params(script::Type::Double).create();

  mEngine.rootNamespace().newFunction("print", callbacks::print_string)
    .params(script::Type::cref(script::Type::String)).create();

  script::Class App = mEngine.rootNamespace().newClass("App").setId(script::Type::App).get();
  App.newMethod("start", callbacks::app_start).setStatic().create();
  App.newMethod("exit", callbacks::app_exit).setStatic().create();
  App.newMethod("qtVersion", callbacks::app_qtVersion).setStatic()
    .returns(script::Type::String).create();
  App.newMethod("loadModule", callbacks::app_loadModule)
    .params(script::Type::cref(script::Type::String))
    .setStatic().create();
}

Application::~Application()
{

}

int Application::runScript(const script::SourceFile & src)
{
  script::Script s = mEngine.newScript(src);
  if (!s.compile())
  {
    for (const auto & e : s.messages())
    {
      qDebug() << e.to_string().data();
    }

    return -1;
  }
  else
  {
    s.run();

    return 0;
  }
}

void Application::startInteractiveSession()
{
  ConsoleListener::registerEventTypes();

  mConsoleListener = new ConsoleListener;
  mConsoleListener->moveToThread(&mConsoleListenerThread);
  connect(&mConsoleListenerThread, &QThread::finished, mConsoleListener, &QObject::deleteLater);
  connect(mConsoleListener, &ConsoleListener::commandReceived, this, &Application::execCommand);
  mConsoleListenerThread.start();

  QEvent *ev = new QEvent{ static_cast<QEvent::Type>(ConsoleListener::ListenEvent) };
  QCoreApplication::postEvent(mConsoleListener, ev);

  this->setQuitOnLastWindowClosed(false);
}

void Application::execCommand(QString str)
{
  std::string command = str.toStdString();

  if (command == ":q")
  {
    QEvent *ev = new QEvent{ static_cast<QEvent::Type>(ConsoleListener::ExitEvent) };
    QCoreApplication::postEvent(mConsoleListener, ev);
    mConsoleListener = nullptr;

    this->exit();
    return;
  }
  else
  {
    try
    {
      script::Value v = mEngine.eval(command);
      display(v);
      mEngine.manage(v);
    }
    catch (const std::runtime_error & ex)
    {
      std::cout << ex.what() << std::endl;
    }
    catch (const script::EvaluationError & ex)
    {
      std::cout << ex.message << std::endl;
    }
  }

  QEvent *ev = new QEvent{ static_cast<QEvent::Type>(ConsoleListener::ListenEvent) };
  QCoreApplication::postEvent(mConsoleListener, ev);
}

void Application::exit()
{
  if (mConsoleListener != nullptr)
  {
    QEvent *ev = new QEvent{ static_cast<QEvent::Type>(ConsoleListener::ExitEvent) };
    QCoreApplication::postEvent(mConsoleListener, ev);
    mConsoleListener = nullptr;
  }

  // Wait for the other thread to finish
  mConsoleListenerThread.wait();

  QCoreApplication::exit();
}

void Application::display(const script::Value & val)
{
  switch (val.type().baseType().data())
  {
  case script::Type::Void:
    return;
  case script::Type::Boolean:
    std::cout << (val.toBool() ? "true" : "false") << std::endl;
    return;
  case script::Type::Char:
    std::cout << val.toChar() << std::endl;
    return;
  case script::Type::Int:
    std::cout << val.toInt() << std::endl;
    return;
  case script::Type::Float:
    std::cout << val.toFloat() << std::endl;
    return;
  case script::Type::Double:
    std::cout << val.toDouble() << std::endl;
    return;
  case script::Type::String:
    std::cout << val.toString().toUtf8().data() << std::endl;
    return;
  default:
    break;
  }

  /// TODO: better print
  std::cout << mEngine.typeSystem()->typeName(val.type()) << "@" << (void*)(val.impl()) << std::endl;
}
