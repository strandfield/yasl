// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/binding/namespace.h"

#include <script/engine.h>
#include <script/class.h>
#include <script/classbuilder.h>

int bar()
{
  return 42;
}

void incr(int & n)
{
  n += 1;
}

TEST(BindingTests, free_functions_1) {
  using namespace script;

  Engine e;
  e.setup();

  binding::Namespace ns{ e.rootNamespace() };
  Function bar_fun = ns.add_fun<int, bar>("bar");
  Function incr_fun = ns.add_void_fun<int&, incr>("incr");

  Value n = e.eval("bar()");
  ASSERT_EQ(n.toInt(), 42);

  e.eval("a = 5");
  e.eval("incr(a)");
  n = e.eval("a");
  ASSERT_EQ(n.toInt(), 6);
}


struct Point {
  int x;
  int y;

  Point() = default;
  Point(const Point &) = default;
  Point(int a, int b) : x(a), y(b) { }

  int get2X() const { return 2 * x; }

  Point & operator=(const Point &) = default;
};

#include "yasl/binding/class.h"

TEST(BindingTests, class_1) {
  using namespace script;

  Engine e;
  e.setup();

  Class point_class = e.rootNamespace().Class("Point").get();

  auto point = binding::Class<Point>{ point_class };
  point.ctors().add_default();
  point.ctors().add<int, int>();
  point.add_dtor();
  point.add_fun<int, &Point::get2X>("get2X");
  
  Value p = e.eval("p = Point(3, 4)");
  Point & point_ref = binding::value_cast<Point&>(p);
  point_ref.x = 4;

  Value a = e.eval("p.get2X()");
  ASSERT_EQ(a.toInt(), 2*4);
}

