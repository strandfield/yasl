// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/application.h"
#include "yasl/binding/values.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/coremodule.h"
#include "yasl/core/size.h"

#include <script/functionbuilder.h>

TEST(CoreModule, size) {
  using namespace script;

  int argc = 0;
  Application app(argc, nullptr);

  Script s = app.scriptEngine()->newScript(SourceFile{ "../size.y" });
  const bool success = s.compile();
  ASSERT_TRUE(success);

  s.run();

  ASSERT_EQ(s.globals().size(), 2);

  script::Value s1 = s.globals().front();
  ASSERT_EQ(s1.type(), script::Type::QSize);

  script::Value s2 = s.globals().back();
  ASSERT_EQ(s2.type(), script::Type::QSize);

  QSize & s2_val = binding::value_cast<QSize &>(s2);
  ASSERT_EQ(s2_val, QSize(30, 20));
}


static bool gAnyTestFailed = false;

void Assert(bool val)
{
  gAnyTestFailed = gAnyTestFailed || !val;
}

void AssertFalse(bool val)
{
  gAnyTestFailed = gAnyTestFailed || val;
}

void register_assert_functions(script::Engine *e)
{
  using namespace script;
  
  binding::Namespace ns{ e->rootNamespace() };
  ns.add_void_fun<bool, Assert>("Assert");
  ns.add_void_fun<bool, AssertFalse>("AssertFalse");
}

TEST(CoreModule, all) {
  using namespace script;

  QStringList files;
  files << "../char.y" << "../dir.y" << "../fileinfo.y" << "../line.y"
    << "../regularexpression.y" << "../variant.y" << "../url.y";

  for (const auto & f : files)
  {
    gAnyTestFailed = false;

    int argc = 0;
    Application app(argc, nullptr);

    register_assert_functions(app.scriptEngine());

    Script s = app.scriptEngine()->newScript(SourceFile{ f.toLocal8Bit().data() });
    const bool success = s.compile();
    if (!success) {
      std::string mssg;
      for (const auto & m : s.messages())
        mssg += m.to_string() + "\n";
      FAIL() << "Failed to compile " << s.path() << "\n" + mssg;
    }

    s.run();

    if (gAnyTestFailed) {
      FAIL() << "Test failed : " << s.path();
    }
  }
}

