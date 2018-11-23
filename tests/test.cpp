// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/binding2/constructor.h"
#include "yasl/binding2/destructor.h"
#include "yasl/binding2/function.h"
#include "yasl/binding2/memberfunction.h"
#include "yasl/binding2/fn-memfn.h"
#include "yasl/binding2/chainable-memfn.h"
#include "yasl/binding2/getter.h"
#include "yasl/binding2/staticmemberfunction.h"
#include "yasl/binding2/operators.h"

#include <script/engine.h>
#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/operator.h>

#include <QList>

#include <cassert>
#include <iostream>
#include <type_traits>

#define ASSERT_EQ(a, b) assert((a) == (b))
#define ASSERT_TRUE(a) assert((a))
#define ASSERT_FALSE(a) assert(!(a))

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

void test_simple_bindind()
{
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

  Function rx = bind::non_const_getter<Point, int&, &Point::rx>(pt, "rx").get();
  ASSERT_TRUE(rx.isMemberFunction());
  ASSERT_EQ(rx.memberOf(), pt);
  ASSERT_EQ(rx.name(), "rx");
  ASSERT_EQ(rx.returnType(), Type::Proxyint);
  ASSERT_EQ(rx.prototype().size(), 1);
  ASSERT_FALSE(rx.isConst());


  Function max = bind::static_member_function<Point, Point, const Point &, const Point &, &Point::max>(pt, "max").get();
  ASSERT_TRUE(max.isMemberFunction());
  ASSERT_TRUE(max.isStatic());
  ASSERT_EQ(max.memberOf(), pt);
  ASSERT_EQ(max.name(), "max");
  ASSERT_EQ(max.returnType(), pt.id());
  ASSERT_EQ(max.prototype().size(), 2);
  ASSERT_EQ(max.parameter(0), Type::cref(pt.id()));
  ASSERT_FALSE(max.isConst());

  Function print = bind::static_void_member_function<Point, const Point &, &Point::print>(pt, "print").get();
  ASSERT_TRUE(print.isMemberFunction());
  ASSERT_TRUE(print.isStatic());
  ASSERT_EQ(print.memberOf(), pt);
  ASSERT_EQ(print.name(), "print");
  ASSERT_EQ(print.returnType(), Type::Void);
  ASSERT_EQ(print.prototype().size(), 1);
  ASSERT_EQ(print.parameter(0), Type::cref(pt.id()));
  ASSERT_FALSE(print.isConst());

  Function assign = bind::memop_assign<Point, const Point &>(pt);
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

#include <QByteArray>

namespace script
{
namespace bind
{
template<> struct make_type_t<QByteArray> { inline static script::Type get() { return script::Type::QByteArray; } };
template<> struct make_type_t<Proxy<QByteArray>> { inline static script::Type get() { return script::Type::ProxyQByteArray; } };
template<> struct make_type_t<QList<QByteArray>> { inline static script::Type get() { return script::Type::QListQByteArray; } };
}
} // namespace script

void bytearray_binding()
{
  using namespace script;

  Engine e;
  e.setup();

  Namespace ns = e.rootNamespace();

  Class ba = ns.newClass("ByteArray").setId(Type::QByteArray).get();

  // QByteArray();
  bind::default_constructor<QByteArray>(ba).create();
  // QByteArray(int, char);
  bind::constructor<QByteArray, int, char>(ba).create();
  // QByteArray(const QByteArray &);
  bind::constructor<QByteArray, const QByteArray &>(ba).create();
  // ~QByteArray();
  bind::destructor<QByteArray>(ba).create();
  // QByteArray & operator=(const QByteArray &);
  // QByteArray(QByteArray &&);
  // QByteArray & operator=(QByteArray &&);
  // void swap(QByteArray &);
  bind::void_member_function<QByteArray, QByteArray&, &QByteArray::swap>(ba, "swap").create();
  // int size() const;
  bind::member_function<QByteArray, int, &QByteArray::size>(ba, "size").create();
  // bool isEmpty() const;
  bind::member_function<QByteArray, bool, &QByteArray::isEmpty>(ba, "isEmpty").create();
  // void resize(int);
  // QByteArray & fill(char, int);
  bind::chainable_memfn<QByteArray, char, int, &QByteArray::fill>(ba, "fill").create();
  // int capacity() const;
  // void reserve(int);
  // void squeeze();
  // void detach();
  // bool isDetached() const;
  // bool isSharedWith(const QByteArray &) const;
  // void clear();
  // char at(int) const;
}

namespace script
{
namespace bind
{
template<> struct make_type_t<QList<int>> { inline static script::Type get() { return script::Type::QListint; } };
}
} // namespace script

template<typename T>
script::Class parameterized_bind(script::Namespace &ns)
{
  using namespace script;

  using Vec = QList<T>;

  Class vec = ns.newClass("List<T>").get();

  bind::default_constructor<Vec>(vec).get();
  bind::constructor<Vec, const Vec &>(vec).get();

  bind::member_function<Vec, int, &Vec::size>(vec, "size").get();

  return vec;
}


void parameterized_binding()
{
  using namespace script;

  Engine e;
  e.setup();

  Namespace ns = e.rootNamespace();

  Class vec = parameterized_bind<int>(ns);

  ASSERT_EQ(vec.constructors().size(), 2);
}


int main(int argc, char *argv[])
{
  test_simple_bindind();
  bytearray_binding();
  parameterized_binding();

  return 0;
}
