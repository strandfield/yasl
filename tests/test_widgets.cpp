// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/application.h"
#include "yasl/core/object.h"
#include "yasl/gui/widget.h"

TEST(Widgets, test1) {
  using namespace script;

  int argc = 0;
  Application app(argc, nullptr);

  Script s = app.scriptEngine()->newScript(SourceFile{ "../test-widget1.y" });
  const bool success = s.compile();
  ASSERT_TRUE(success);

  s.run();

  ASSERT_EQ(s.globals().size(), 2);
  
  script::Value n = s.globals().back();
  ASSERT_EQ(n.type(), Type::Int);
  ASSERT_EQ(n.toInt(), 400);
}

TEST(Widgets, parent_widget) {
  using namespace script;

  int argc = 0;
  Application app(argc, nullptr);

  Script s = app.scriptEngine()->newScript(SourceFile{ "../test-widget-parent.y" });
  const bool success = s.compile();
  ASSERT_TRUE(success);

  s.run();

  ASSERT_EQ(s.globals().size(), 3);

  script::Value n = s.globals().back();
  ASSERT_EQ(n.type(), Type::Boolean);
  ASSERT_EQ(n.toBool(), false);
}

TEST(Widgets, children) {
  using namespace script;

  int argc = 0;
  Application app(argc, nullptr);

  Script s = app.scriptEngine()->newScript(SourceFile{ "../test-widget-children.y" });
  const bool success = s.compile();
  ASSERT_TRUE(success);

  s.run();

  ASSERT_EQ(s.globals().size(), 3);

  script::Value children_value = s.globals().back();
  ASSERT_EQ(children_value.type(), binding::make_type<QList<QObject*>>());
  const QObjectList & children = binding::value_cast<const QObjectList &>(children_value);

  ASSERT_EQ(children.size(), 1);
}


