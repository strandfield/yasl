// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/application.h"
#include "yasl/core/coremodule.h"
#include "yasl/core/size.h"

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
  ASSERT_EQ(s1.type(), get_qsize_type());

  script::Value s2 = s.globals().back();
  ASSERT_EQ(s2.type(), get_qsize_type());

  QSize & s2_val = binding::value_cast<QSize &>(s2);
  ASSERT_EQ(s2_val, QSize(30, 20));
}

