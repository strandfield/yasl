// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include <gtest/gtest.h>

#include "yasl/binding2/constructor.h"
#include "yasl/binding2/destructor.h"
#include "yasl/binding2/function.h"
#include "yasl/binding2/memberfunction.h"
#include "yasl/binding2/fn-memfn.h"
#include "yasl/binding2/chainable-memfn.h"

#include <script/engine.h>
#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

#include <type_traits>

int add(int a, int b)
{
  return a + b;
}

struct Point {
  int x_;
  int y_;

  Point() = default;
  Point(const Point &) = default;
  Point(int a, int b = 0) : x_(a), y_(b) { }

  int x() const { return x_; }
  int y() const { return y_; }

  int & rx() { return x_; }
  int & ry() { return y_; }

  int get2X() const { return 2 * x_; }

  Point & incrX(int n) { x_ += n; return *this; }

  void invert() { std::swap(x_, y_); }

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

namespace script
{
namespace bind
{
template<> struct make_type_t<Point> { inline static script::Type get() { return script::Type::QPoint; } };
template<> struct make_type_t<long unsigned int> { inline static script::Type get() { return script::Type::Int; } };
}
} // namespace script

TEST(BindingTests, prototypes_member_functions) {
  using namespace script;

  Engine e;
  e.setup();

  Namespace ns = e.rootNamespace();
  
  Function add_func = bind::function<int, int, int, &add>(ns, "add").get();
  ASSERT_EQ(add_func.returnType(), Type::Int);
  ASSERT_EQ(add_func.prototype().size(), 2);
  ASSERT_EQ(add_func.parameter(0), Type::Int);
  ASSERT_EQ(add_func.parameter(1), Type::Int);

  Class pt = ns.newClass("Point").setId(bind::make_type<Point>().data()).get();

  Function ctor = bind::default_constructor<Point>(pt).get();
  ASSERT_TRUE(ctor.isConstructor());
  ASSERT_EQ(ctor.memberOf(), pt);
  ASSERT_EQ(ctor.prototype().size(), 1);

  ctor = bind::constructor<Point, int, int>(pt).get();
  ASSERT_TRUE(ctor.isConstructor());
  ASSERT_EQ(ctor.memberOf(), pt);
  ASSERT_EQ(ctor.prototype().size(), 3);
  ASSERT_EQ(ctor.parameter(1), Type::Int);
  ASSERT_EQ(ctor.parameter(2), Type::Int);

  Function dtor = bind::destructor<Point>(pt).get();
  ASSERT_FALSE(dtor.isNull());
  ASSERT_TRUE(dtor.isDestructor());
  ASSERT_EQ(dtor.memberOf(), pt);


  Function x = bind::member_function<Point, int, &Point::x>(pt, "x").get();
  ASSERT_TRUE(x.isMemberFunction());
  ASSERT_EQ(x.memberOf(), pt);
  ASSERT_EQ(x.name(), "x");
  ASSERT_EQ(x.returnType(), Type::Int);
  ASSERT_EQ(x.prototype().size(), 1);
  ASSERT_TRUE(x.isConst());

  Function y = bind::fn_as_memfn<Point, int, &point_y>(pt, "y").get();
  ASSERT_TRUE(y.isMemberFunction());
  ASSERT_EQ(y.memberOf(), pt);
  ASSERT_EQ(y.name(), "y");
  ASSERT_EQ(y.returnType(), Type::Int);
  ASSERT_EQ(y.prototype().size(), 1);
  ASSERT_TRUE(y.isConst());

  Function incr_x = bind::chainable_memfn<Point, int, &Point::incrX>(pt, "incrX").get();
  ASSERT_TRUE(incr_x.isMemberFunction());
  ASSERT_EQ(incr_x.memberOf(), pt);
  ASSERT_EQ(incr_x.name(), "incrX");
  ASSERT_EQ(incr_x.returnType(), Type::ref(pt.id()));
  ASSERT_EQ(incr_x.prototype().size(), 2);
  ASSERT_EQ(incr_x.parameter(1), Type::Int);
  ASSERT_FALSE(incr_x.isConst());

  Function invert = bind::void_member_function<Point, &Point::invert>(pt, "invert").get();
  ASSERT_TRUE(invert.isMemberFunction());
  ASSERT_EQ(invert.memberOf(), pt);
  ASSERT_EQ(invert.name(), "invert");
  ASSERT_EQ(invert.returnType(), Type::Void);
  ASSERT_EQ(invert.prototype().size(), 1);
  ASSERT_FALSE(invert.isConst());

  /*
  Function rx = binder.ref_mem_getter<int&, &Point::rx>("rx").get();
  ASSERT_TRUE(rx.isMemberFunction());
  ASSERT_EQ(rx.memberOf(), pt);
  ASSERT_EQ(rx.name(), "rx");
  ASSERT_EQ(rx.returnType(), Type::Proxyint);
  ASSERT_EQ(rx.prototype().size(), 1);
  ASSERT_FALSE(rx.isConst());

  Function max = binder.static_fun<Point, const Point &, const Point &, &Point::max>("max").get();
  ASSERT_TRUE(max.isMemberFunction());
  ASSERT_TRUE(max.isStatic());
  ASSERT_EQ(max.memberOf(), pt);
  ASSERT_EQ(max.name(), "max");
  ASSERT_EQ(max.returnType(), pt.id());
  ASSERT_EQ(max.prototype().size(), 2);
  ASSERT_EQ(max.parameter(0), Type::cref(pt.id()));
  ASSERT_FALSE(max.isConst());

  Function print = binder.static_void_fun<const Point &, &Point::print>("print").get();
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
  ASSERT_EQ(assign.memberOf(), pt);*/
}

namespace script
{
namespace bind
{
template<> struct make_type_t<std::vector<int>> { inline static script::Type get() { return script::Type::QListint; } };
}
} // namespace script

template<typename T>
script::Class parameterized_bind(script::Namespace &ns)
{
  using namespace script;

  using Vec = std::vector<T>;

  Class vec = ns.newClass("Vector").get();

  bind::default_constructor<Vec>(vec).get();
  bind::constructor<Vec, size_t>(vec).get();

  bind::member_function<Vec, size_t, &Vec::size>(vec, "size").get();

  return vec;
}


TEST(BindingTests, parameterized_binding) {
  using namespace script;

  Engine e;
  e.setup();

  Namespace ns = e.rootNamespace();

  Class vec = parameterized_bind<int>(ns);

  ASSERT_EQ(vec.constructors().size(), 2);
}


//
//TEST(BindingTests, value_cast_2) {
//  using namespace script;
//
//  Engine e;
//  e.setup();
//
//  Class point_class = e.rootNamespace().newClass("Point").setId(binding::make_type<Point>().data()).get();
//  binding::ClassBinder<Point> binder{ point_class };
//
//  binder.default_ctor().create();
//  binder.ctor<const Point &>().create();
//  binder.ctor<int, int>().create();
//  binder.dtor().create();
//
//  binder.fun<int, &Point::x>("x").create();
//  binder.static_fun<Point, const Point &, const Point &, &Point::max>("max").create();
//  binder.static_void_fun<const Point &, &Point::print>("print").create();
//  binder.operators().assign<const Point &>();
//
//  {
//    Value p1_val = e.eval("p = Point(3, 4)");
//    Point & p1_ref = binding::get<Point>(p1_val);
//    p1_ref.x_ = 4;
//
//    Value a = e.eval("p.x()");
//    ASSERT_EQ(a.type(), Type::Int);
//    ASSERT_EQ(a.toInt(), 4);
//  }
//
//  {
//    Value p1_val = e.eval("p = Point(3, 4)");
//    Point & p1_ref = binding::value_cast<Point&>(p1_val);
//    p1_ref.x_ = 4;
//
//    Value a = e.eval("p.x()");
//    ASSERT_EQ(a.type(), Type::Int);
//    ASSERT_EQ(a.toInt(), 4);
//  }
//
//  {
//    Value p1_val = e.eval("p = Point(3, 4)");
//    Point p1_copy = binding::value_cast<Point>(p1_val);
//    p1_copy.x_ = 4;
//
//    Value a = e.eval("p.x()");
//    ASSERT_EQ(a.type(), Type::Int);
//    ASSERT_EQ(a.toInt(), 3);
//  }
//}
//
//
//TEST(BindingTests, free_functions_1) {
//  using namespace script;
//
//  Engine e;
//  e.setup();
//
//  binding::Namespace ns{ e.rootNamespace() };
//  Function bar_fun = ns.fun<int, bar>("bar").get();
//  Function incr_fun = ns.void_fun<int&, incr>("incr").get();
//
//  Value n = e.eval("bar()");
//  ASSERT_EQ(n.toInt(), 42);
//
//  e.eval("a = 5");
//  e.eval("incr(a)");
//  n = e.eval("a");
//  ASSERT_EQ(n.toInt(), 6);
//}
//
//TEST(BindingTests, class_1) {
//  using namespace script;
//
//  Engine e;
//  e.setup();
//
//  Class point_class = e.rootNamespace().newClass("Point").get();
//
//  auto point = binding::ClassBinder<Point>{ point_class };
//  point.default_ctor().create();
//  point.ctor<int, int>().create();
//  point.dtor().create();
//  point.fun<int, &Point::get2X>("get2X").create();
//  
//  Value p = e.eval("p = Point(3, 4)");
//  Point & point_ref = binding::value_cast<Point&>(p);
//  point_ref.x_ = 4;
//
//  Value a = e.eval("p.get2X()");
//  ASSERT_EQ(a.toInt(), 2*4);
//}
//
