// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/rect.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/margins.h"
#include "yasl/core/point.h"
#include "yasl/core/size.h"


void register_qrect(script::Namespace n)
{
  using namespace script;

  Class rect = n.newClass(ClassBuilder::New("Rect").setId(Type::QRect).setFinal());

  binding::Class<QRect> r{ rect };

  // QRect()
  r.ctors().add_default();
  // QRect(const QRect &)
  r.ctors().add_copy();
  // QRect(const QPoint &, const QPoint &);
  r.ctors().add<const QPoint &, const QPoint &>();
  // QRect(int, int, int, int);
  r.ctors().add<int, int, int, int>();
  // ~QRect()
  r.add_dtor();
  // void adjust(int dx1, int dy1, int dx2, int dy2)
  r.add_void_fun<int, int, int, int, &QRect::adjust>("adjust");
  // QRect adjusted(int dx1, int dy1, int dx2, int dy2) const
  r.add_fun<QRect, int, int, int, int, &QRect::adjusted>("adjusted");
  // int bottom() const
  r.add_fun<int, &QRect::bottom>("bottom");
  // QPoint bottomLeft() const
  r.add_fun<QPoint, &QRect::bottomLeft>("bottomLeft");
  // QPoint bottomRight() const
  r.add_fun<QPoint, &QRect::bottomRight>("bottomRight");
  // QPoint center() const
  r.add_fun<QPoint, &QRect::center>("center");
  // bool contains(const QPoint &point, bool proper = false) const
  r.add_fun<bool, const QPoint &, bool, &QRect::contains>("contains");
  // bool contains(const QRect &rectangle, bool proper = false) const
  r.add_fun<bool, const QRect &, bool, &QRect::contains>("contains");
  // bool contains(int x, int y) const
  r.add_fun<bool, int, int, &QRect::contains>("contains");
  // bool contains(int x, int y, bool proper) const
  r.add_fun<bool, int, int, bool, &QRect::contains>("contains");
  // void getCoords(int *x1, int *y1, int *x2, int *y2) const
  /// TODO !!!
  // void getRect(int *x, int *y, int *width, int *height) const
  /// TODO !!!
  // int height() const
  r.add_fun<int, &QRect::height>("height");
  // QRect intersected(const QRect &rectangle) const
  r.add_fun<QRect, const QRect &, &QRect::intersected>("intersected");
  // bool intersects(const QRect &rectangle) const
  r.add_fun<bool, const QRect &, &QRect::intersects>("intersects");
  // bool isEmpty() const
  r.add_fun<bool, &QRect::isEmpty>("isEmpty");
  // bool isNull() const
  r.add_fun<bool, &QRect::isNull>("isNull");
  // bool isValid() const
  r.add_fun<bool, &QRect::isValid>("isValid");
  // int left() const
  r.add_fun<int, &QRect::left>("left");
  // QRect marginsAdded(const QMargins &margins) const
  r.add_fun<QRect, const QMargins &, &QRect::marginsAdded>("marginsAdded");
  // QRect marginsRemoved(const QMargins &margins) const
  r.add_fun<QRect, const QMargins &, &QRect::marginsRemoved>("marginsRemoved");
  // void moveBottom(int y)
  r.add_void_fun<int, &QRect::moveBottom>("moveBottom");
  // void moveBottomLeft(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveBottomLeft>("moveBottomLeft");
  // void moveBottomRight(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveBottomRight>("moveBottomRight");
  // void moveCenter(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveCenter>("moveCenter");
  // void moveLeft(int x)
  r.add_void_fun<int, &QRect::moveLeft>("moveLeft");
  // void moveRight(int x)
  r.add_void_fun<int, &QRect::moveRight>("moveRight");
  // void moveTo(int x, int y)
  r.add_void_fun<int, int, &QRect::moveTo>("moveTo");
  // void moveTo(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveTo>("moveTo");
  // void moveTop(int y)
  r.add_void_fun<int, &QRect::moveTop>("moveTop");
  // void moveTopLeft(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveTopLeft>("moveTopLeft");
  // void moveTopRight(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::moveTopRight>("moveTopRight");
  // QRect normalized() const
  r.add_fun<QRect, &QRect::normalized>("normalized");
  // int right() const
  r.add_fun<int, &QRect::right>("right");
  // void setBottom(int y)
  r.add_void_fun<int, &QRect::setBottom>("setBottom");
  // void setBottomLeft(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::setBottomLeft>("setBottomLeft");
  // void setBottomRight(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::setBottomRight>("setBottomRight");
  // void setCoords(int x1, int y1, int x2, int y2)
  r.add_void_fun<int, int, int, int, &QRect::setCoords>("setCoords");
  // void setHeight(int height)
  r.add_void_fun<int, &QRect::setHeight>("setHeight");
  // void setLeft(int x)
  r.add_void_fun<int, &QRect::setLeft>("setLeft");
  // void setRect(int x, int y, int width, int height)
  r.add_void_fun<int, int, int, int, &QRect::setRect>("setRect");
  // void setRight(int x)
  r.add_void_fun<int, &QRect::setRight>("setRight");
  // void setSize(const QSize &size)
  r.add_void_fun<const QSize &, &QRect::setSize>("setSize");
  // void setTop(int y)
  r.add_void_fun<int, &QRect::setTop>("setTop");
  // void setTopLeft(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::setTopLeft>("setTopLeft");
  // void setTopRight(const QPoint &position)
  r.add_void_fun<const QPoint &, &QRect::setTopRight>("setTopRight");
  // void setWidth(int width)
  r.add_void_fun<int, &QRect::setWidth>("setWidth");
  // void setX(int x)
  r.add_void_fun<int, &QRect::setX>("setX");
  // void setY(int y)
  r.add_void_fun<int, &QRect::setY>("setY");
  // QSize size() const
  r.add_fun<QSize, &QRect::size>("size");
  // int top() const
  r.add_fun<int, &QRect::top>("top");
  // QPoint topLeft() const
  r.add_fun<QPoint, &QRect::topLeft>("topLeft");
  // QPoint topRight() const
  r.add_fun<QPoint, &QRect::topRight>("topRight");
  // void translate(int dx, int dy)
  r.add_void_fun<int, int, &QRect::translate>("translate");
  // void translate(const QPoint &offset)
  r.add_void_fun<const QPoint &, &QRect::translate>("translate");
  // QRect translated(int dx, int dy) const
  r.add_fun<QRect, int, int, &QRect::translated>("translated");
  // QRect translated(const QPoint &offset) const
  r.add_fun<QRect, const QPoint &, &QRect::translated>("translated");
  // QRect transposed() const
  r.add_fun<QRect, &QRect::transposed>("transposed");
  // QRect united(const QRect &rectangle) const
  r.add_fun<QRect, const QRect &, &QRect::united>("united");
  // int width() const
  r.add_fun<int, &QRect::width>("width");
  // int x() const
  r.add_fun<int, &QRect::x>("x");
  // int y() const
  r.add_fun<int, &QRect::y>("y");

  // QRect & operator=(const QRect &);
  r.operators().assign<const QRect &>();
  // QRect operator&(const QRect &rectangle) const
  r.operators().and<QRect, const QRect &>();
  // QRect & operator&=(const QRect &rectangle)
  r.operators().and_assign<const QRect &>();
  // QRect & operator+=(const QMargins &margins)
  r.operators().add_assign<const QMargins &>();
  // QRect & operator-=(const QMargins &margins)
  r.operators().sub_assign<const QMargins &>();
  // QRect operator|(const QRect &rectangle) const
  r.operators().or<QRect, const QRect &>();
  // QRect & operator|=(const QRect &rectangle)
  r.operators().or_assign<const QRect &>();


  /* Non members */
  binding::Namespace ns{ n };
  // bool operator!=(const QRect &r1, const QRect &r2)
  ns.operators().neq<const QRect &, const QRect &>();
  // QRect operator+(const QRect &rectangle, const QMargins &margins)
  ns.operators().add<QRect, const QRect&, const QMargins&>();
  // QRect operator+(const QMargins &margins, const QRect &rectangle)
  ns.operators().add<QRect, const QMargins&, const QRect&>();
  // QRect operator-(const QRect &lhs, const QMargins &rhs)
  ns.operators().sub<QRect, const QRect&, const QMargins&>();
  // QDataStream & operator<<(QDataStream &stream, const QRect &rectangle)
  /// TODO !!!
  // bool operator==(const QRect &r1, const QRect &r2)
  ns.operators().eq<const QRect &, const QRect &>();
  // QDataStream & operator>>(QDataStream &stream, QRect &rectangle)
  /// TODO !!!

}
