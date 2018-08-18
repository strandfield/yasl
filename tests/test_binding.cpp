// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include <script/engine.h>
#include <script/class.h>
#include <script/classbuilder.h>
#include <script/operator.h>

#include <type_traits>

TEST(BindingTests, decay) {
  using namespace binding;

  ASSERT_TRUE((std::is_same<decay<bool&>::type, bool>::value));
  ASSERT_TRUE((std::is_same<decay<const bool>::type, bool>::value));
  ASSERT_TRUE((std::is_same<decay<const bool &>::type, bool>::value));
  ASSERT_TRUE((std::is_same<decay<bool *>::type, bool>::value));
  ASSERT_TRUE((std::is_same<decay<bool const *>::type, bool>::value));
}

#include <QTimer>

TEST(BindingTests, tagdetection) {
  using namespace binding;

  ASSERT_TRUE((std::is_same<typename tag_resolver<bool>::tag_type, small_object_tag>::value));

  enum Foo {};
  ASSERT_TRUE((std::is_same<typename tag_resolver<Foo>::tag_type, enum_tag>::value));

  ASSERT_TRUE((std::is_same<typename tag_resolver<QTimer>::tag_type, qobject_tag>::value));

  struct Qux { int n[20000]; };
  ASSERT_TRUE((std::is_same<typename tag_resolver<Qux>::tag_type, large_object_tag>::value));
}


TEST(BindingTests, storage) {
  using namespace binding;

  ASSERT_TRUE((std::is_same<typename storage_type<bool>::type, bool&>::value));

  enum Foo {};
  ASSERT_TRUE((std::is_same<typename storage_type<Foo>::type, Foo>::value));

  struct Bar { int n; };
  ASSERT_TRUE((std::is_same<typename storage_type<Bar>::type, Bar&>::value));

  struct Qux { int n[20000]; };
  ASSERT_TRUE((std::is_same<typename storage_type<Qux>::type, Qux*>::value));

  ASSERT_TRUE((std::is_same<typename storage_type<QTimer>::type, qobject_storage<QTimer>::type>::value));
}

int bar()
{
  return 42;
}

void incr(int & n)
{
  n += 1;
}

TEST(BindingTests, prototypes_free_functions) {
  using namespace script;

  Engine e;
  e.setup();

  binding::Namespace ns{ e.rootNamespace() };
  
  Function bar_fun = ns.add_fun<int, bar>("bar");
  ASSERT_EQ(bar_fun.returnType(), Type::Int);
  ASSERT_EQ(bar_fun.prototype().size(), 0);

  Function incr_fun = ns.add_void_fun<int&, incr>("incr");
  ASSERT_EQ(incr_fun.returnType(), Type::Void);
  ASSERT_EQ(incr_fun.prototype().size(), 1);
  ASSERT_EQ(incr_fun.parameter(0), Type::ref(Type::Int));
}

struct Point {
  int x_;
  int y_;

  Point() = default;
  Point(const Point &) = default;
  Point(int a, int b) : x_(a), y_(b) { }

  int x() const { return x_; }
  int y() const { return y_; }

  int & rx() { return x_; }
  int & ry() { return y_; }

  int get2X() const { return 2 * x_; }

  static Point max(const Point & a, const Point & b)
  {
    /* dummy impl */
    return a.x() > b.x() ? a : b;
  }

  static void print(const Point & pt) 
  { 
    std::cout << "Point(" << pt.x() << ", " << pt.y() << ")" << std::endl;
  }

  Point & operator=(const Point &) = default;
};

int point_y(const Point & pt)
{
  return pt.y();
}

namespace binding
{
template<> struct make_type_t<Point> { inline static script::Type get() { return script::Type::QPoint; } };
} // namespace binding

TEST(BindingTests, prototypes_member_functions) {
  using namespace script;

  Engine e;
  e.setup();

  Class pt = e.rootNamespace().Class("Point").setId(binding::make_type<Point>().data()).get();
  binding::Class<Point> binder{ pt };

  Function ctor = binder.ctors().add_default();
  ASSERT_TRUE(ctor.isConstructor());
  ASSERT_EQ(ctor.memberOf(), pt);
  ASSERT_EQ(ctor.prototype().size(), 0);

  ctor = binder.ctors().add<int, int>();
  ASSERT_TRUE(ctor.isConstructor());
  ASSERT_EQ(ctor.memberOf(), pt);
  ASSERT_EQ(ctor.prototype().size(), 2);
  ASSERT_EQ(ctor.parameter(0), Type::Int);
  ASSERT_EQ(ctor.parameter(1), Type::Int);

  binder.add_dtor();
  Function dtor = pt.destructor();
  ASSERT_FALSE(dtor.isNull());
  ASSERT_EQ(dtor.memberOf(), pt);

  Function x = binder.add_fun<int, &Point::x>("x");
  ASSERT_TRUE(x.isMemberFunction());
  ASSERT_EQ(x.memberOf(), pt);
  ASSERT_EQ(x.name(), "x");
  ASSERT_EQ(x.returnType(), Type::Int);
  ASSERT_EQ(x.prototype().size(), 1);
  ASSERT_TRUE(x.isConst());

  Function y = binder.add_fun<int, &point_y>("y");
  ASSERT_TRUE(y.isMemberFunction());
  ASSERT_EQ(y.memberOf(), pt);
  ASSERT_EQ(y.name(), "y");
  ASSERT_EQ(y.returnType(), Type::Int);
  ASSERT_EQ(y.prototype().size(), 1);
  ASSERT_TRUE(y.isConst());

  Function rx = binder.add_ref_mem<int&, &Point::rx>("rx");
  ASSERT_TRUE(rx.isMemberFunction());
  ASSERT_EQ(rx.memberOf(), pt);
  ASSERT_EQ(rx.name(), "rx");
  ASSERT_EQ(rx.returnType(), Type::Ptrint);
  ASSERT_EQ(rx.prototype().size(), 1);
  ASSERT_FALSE(rx.isConst());

  Function max = binder.add_static<Point, const Point &, const Point &, &Point::max>("max");
  ASSERT_TRUE(max.isMemberFunction());
  ASSERT_TRUE(max.isStatic());
  ASSERT_EQ(max.memberOf(), pt);
  ASSERT_EQ(max.name(), "max");
  ASSERT_EQ(max.returnType(), pt.id());
  ASSERT_EQ(max.prototype().size(), 2);
  ASSERT_EQ(max.parameter(0), Type::cref(pt.id()));
  ASSERT_FALSE(max.isConst());

  Function print = binder.add_static_void_fun<const Point &, &Point::print>("print");
  ASSERT_TRUE(print.isMemberFunction());
  ASSERT_TRUE(print.isStatic());
  ASSERT_EQ(print.memberOf(), pt);
  ASSERT_EQ(print.name(), "print");
  ASSERT_EQ(print.returnType(), Type::Void);
  ASSERT_EQ(print.prototype().size(), 1);
  ASSERT_EQ(print.parameter(0), Type::cref(pt.id()));
  ASSERT_FALSE(print.isConst());

  Function assign = binder.operators().assign<const Point &>();
  ASSERT_TRUE(assign.isOperator());
  ASSERT_EQ(assign.toOperator().operatorId(), AssignmentOperator);
  ASSERT_EQ(assign.returnType(), Type::ref(pt.id()));
  ASSERT_EQ(assign.parameter(0), Type::ref(pt.id()));
  ASSERT_EQ(assign.parameter(1), Type::cref(pt.id()));
  ASSERT_TRUE(assign.isMemberFunction());
  ASSERT_FALSE(assign.isStatic());
  ASSERT_FALSE(assign.isConst());
  ASSERT_EQ(assign.memberOf(), pt);
}

TEST(BindingTests, value_cast_2) {
  using namespace script;

  Engine e;
  e.setup();

  Class point_class = e.rootNamespace().Class("Point").setId(binding::make_type<Point>().data()).get();
  binding::Class<Point> binder{ point_class };

  binder.ctors().add_default();
  binder.ctors().add<const Point &>();
  binder.ctors().add<int, int>();
  binder.add_dtor();

  binder.add_fun<int, &Point::x>("x");
  binder.add_static<Point, const Point &, const Point &, &Point::max>("max");
  binder.add_static_void_fun<const Point &, &Point::print>("print");
  binder.operators().assign<const Point &>();

  {
    Value p1_val = e.eval("p = Point(3, 4)");
    Point & p1_ref = binding::get<Point>(p1_val);
    p1_ref.x_ = 4;

    Value a = e.eval("p.x()");
    ASSERT_EQ(a.type(), Type::Int);
    ASSERT_EQ(a.toInt(), 4);
  }

  {
    Value p1_val = e.eval("p = Point(3, 4)");
    Point & p1_ref = binding::value_cast<Point&>(p1_val);
    p1_ref.x_ = 4;

    Value a = e.eval("p.x()");
    ASSERT_EQ(a.type(), Type::Int);
    ASSERT_EQ(a.toInt(), 4);
  }

  {
    Value p1_val = e.eval("p = Point(3, 4)");
    Point p1_copy = binding::value_cast<Point>(p1_val);
    p1_copy.x_ = 4;

    Value a = e.eval("p.x()");
    ASSERT_EQ(a.type(), Type::Int);
    ASSERT_EQ(a.toInt(), 3);
  }
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
  point_ref.x_ = 4;

  Value a = e.eval("p.get2X()");
  ASSERT_EQ(a.toInt(), 2*4);
}

