// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/rect.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>

static void register_rect_class(script::Namespace ns)
{
  using namespace script;

  Class rect = ns.Class("Rect").setId(script::Type::QRect).get();

  binding::Class<QRect> binder{ rect };

  // QRect();
  binder.ctors().add_default();
  // QRect(const QRect &);
  binder.ctors().add<const QRect &>();
  // ~QRect();
  binder.add_dtor();
  // QRect(const QPoint &, const QPoint &);
  binder.ctors().add<const QPoint &, const QPoint &>();
  // QRect(const QPoint &, const QSize &);
  binder.ctors().add<const QPoint &, const QSize &>();
  // QRect(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QRect::isNull>("isNull");
  // bool isEmpty() const;
  binder.add_fun<bool, &QRect::isEmpty>("isEmpty");
  // bool isValid() const;
  binder.add_fun<bool, &QRect::isValid>("isValid");
  // int left() const;
  binder.add_fun<int, &QRect::left>("left");
  // int top() const;
  binder.add_fun<int, &QRect::top>("top");
  // int right() const;
  binder.add_fun<int, &QRect::right>("right");
  // int bottom() const;
  binder.add_fun<int, &QRect::bottom>("bottom");
  // QRect normalized() const;
  binder.add_fun<QRect, &QRect::normalized>("normalized");
  // int x() const;
  binder.add_fun<int, &QRect::x>("x");
  // int y() const;
  binder.add_fun<int, &QRect::y>("y");
  // void setLeft(int);
  binder.add_void_fun<int, &QRect::setLeft>("setLeft");
  // void setTop(int);
  binder.add_void_fun<int, &QRect::setTop>("setTop");
  // void setRight(int);
  binder.add_void_fun<int, &QRect::setRight>("setRight");
  // void setBottom(int);
  binder.add_void_fun<int, &QRect::setBottom>("setBottom");
  // void setX(int);
  binder.add_void_fun<int, &QRect::setX>("setX");
  // void setY(int);
  binder.add_void_fun<int, &QRect::setY>("setY");
  // void setTopLeft(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::setTopLeft>("setTopLeft");
  // void setBottomRight(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::setBottomRight>("setBottomRight");
  // void setTopRight(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::setTopRight>("setTopRight");
  // void setBottomLeft(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::setBottomLeft>("setBottomLeft");
  // QPoint topLeft() const;
  binder.add_fun<QPoint, &QRect::topLeft>("topLeft");
  // QPoint bottomRight() const;
  binder.add_fun<QPoint, &QRect::bottomRight>("bottomRight");
  // QPoint topRight() const;
  binder.add_fun<QPoint, &QRect::topRight>("topRight");
  // QPoint bottomLeft() const;
  binder.add_fun<QPoint, &QRect::bottomLeft>("bottomLeft");
  // QPoint center() const;
  binder.add_fun<QPoint, &QRect::center>("center");
  // void moveLeft(int);
  binder.add_void_fun<int, &QRect::moveLeft>("moveLeft");
  // void moveTop(int);
  binder.add_void_fun<int, &QRect::moveTop>("moveTop");
  // void moveRight(int);
  binder.add_void_fun<int, &QRect::moveRight>("moveRight");
  // void moveBottom(int);
  binder.add_void_fun<int, &QRect::moveBottom>("moveBottom");
  // void moveTopLeft(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveTopLeft>("moveTopLeft");
  // void moveBottomRight(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveBottomRight>("moveBottomRight");
  // void moveTopRight(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveTopRight>("moveTopRight");
  // void moveBottomLeft(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveBottomLeft>("moveBottomLeft");
  // void moveCenter(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveCenter>("moveCenter");
  // void translate(int, int);
  binder.add_void_fun<int, int, &QRect::translate>("translate");
  // void translate(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::translate>("translate");
  // QRect translated(int, int) const;
  binder.add_fun<QRect, int, int, &QRect::translated>("translated");
  // QRect translated(const QPoint &) const;
  binder.add_fun<QRect, const QPoint &, &QRect::translated>("translated");
  // QRect transposed() const;
  binder.add_fun<QRect, &QRect::transposed>("transposed");
  // void moveTo(int, int);
  binder.add_void_fun<int, int, &QRect::moveTo>("moveTo");
  // void moveTo(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRect::moveTo>("moveTo");
  // void setRect(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QRect::setRect>("setRect");
  // void getRect(int *, int *, int *, int *) const;
  /// TODO: void getRect(int *, int *, int *, int *) const;
  // void setCoords(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QRect::setCoords>("setCoords");
  // void getCoords(int *, int *, int *, int *) const;
  /// TODO: void getCoords(int *, int *, int *, int *) const;
  // void adjust(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QRect::adjust>("adjust");
  // QRect adjusted(int, int, int, int) const;
  binder.add_fun<QRect, int, int, int, int, &QRect::adjusted>("adjusted");
  // QSize size() const;
  binder.add_fun<QSize, &QRect::size>("size");
  // int width() const;
  binder.add_fun<int, &QRect::width>("width");
  // int height() const;
  binder.add_fun<int, &QRect::height>("height");
  // void setWidth(int);
  binder.add_void_fun<int, &QRect::setWidth>("setWidth");
  // void setHeight(int);
  binder.add_void_fun<int, &QRect::setHeight>("setHeight");
  // void setSize(const QSize &);
  binder.add_void_fun<const QSize &, &QRect::setSize>("setSize");
  // QRect operator|(const QRect &) const;
  binder.operators().or<QRect, const QRect &>();
  // QRect operator&(const QRect &) const;
  binder.operators().and<QRect, const QRect &>();
  // QRect & operator|=(const QRect &);
  binder.operators().or_assign<const QRect &>();
  // QRect & operator&=(const QRect &);
  binder.operators().and_assign<const QRect &>();
  // bool contains(const QRect &, bool) const;
  binder.add_fun<bool, const QRect &, bool, &QRect::contains>("contains");
  // bool contains(const QPoint &, bool) const;
  binder.add_fun<bool, const QPoint &, bool, &QRect::contains>("contains");
  // bool contains(int, int) const;
  binder.add_fun<bool, int, int, &QRect::contains>("contains");
  // bool contains(int, int, bool) const;
  binder.add_fun<bool, int, int, bool, &QRect::contains>("contains");
  // QRect united(const QRect &) const;
  binder.add_fun<QRect, const QRect &, &QRect::united>("united");
  // QRect intersected(const QRect &) const;
  binder.add_fun<QRect, const QRect &, &QRect::intersected>("intersected");
  // bool intersects(const QRect &) const;
  binder.add_fun<bool, const QRect &, &QRect::intersects>("intersects");
  // QRect marginsAdded(const QMargins &) const;
  /// TODO: QRect marginsAdded(const QMargins &) const;
  // QRect marginsRemoved(const QMargins &) const;
  /// TODO: QRect marginsRemoved(const QMargins &) const;
  // QRect & operator+=(const QMargins &);
  /// TODO: QRect & operator+=(const QMargins &);
  // QRect & operator-=(const QMargins &);
  /// TODO: QRect & operator-=(const QMargins &);
}


static void register_rect_f_class(script::Namespace ns)
{
  using namespace script;

  Class rect_f = ns.Class("RectF").setId(script::Type::QRectF).get();

  binding::Class<QRectF> binder{ rect_f };

  // QRectF();
  binder.ctors().add_default();
  // QRectF(const QRectF &);
  binder.ctors().add<const QRectF &>();
  // ~QRectF();
  binder.add_dtor();
  // QRectF(const QPointF &, const QSizeF &);
  binder.ctors().add<const QPointF &, const QSizeF &>();
  // QRectF(const QPointF &, const QPointF &);
  binder.ctors().add<const QPointF &, const QPointF &>();
  // QRectF(qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal>();
  // QRectF(const QRect &);
  binder.ctors().add<const QRect &>();
  // bool isNull() const;
  binder.add_fun<bool, &QRectF::isNull>("isNull");
  // bool isEmpty() const;
  binder.add_fun<bool, &QRectF::isEmpty>("isEmpty");
  // bool isValid() const;
  binder.add_fun<bool, &QRectF::isValid>("isValid");
  // QRectF normalized() const;
  binder.add_fun<QRectF, &QRectF::normalized>("normalized");
  // qreal left() const;
  binder.add_fun<qreal, &QRectF::left>("left");
  // qreal top() const;
  binder.add_fun<qreal, &QRectF::top>("top");
  // qreal right() const;
  binder.add_fun<qreal, &QRectF::right>("right");
  // qreal bottom() const;
  binder.add_fun<qreal, &QRectF::bottom>("bottom");
  // qreal x() const;
  binder.add_fun<qreal, &QRectF::x>("x");
  // qreal y() const;
  binder.add_fun<qreal, &QRectF::y>("y");
  // void setLeft(qreal);
  binder.add_void_fun<qreal, &QRectF::setLeft>("setLeft");
  // void setTop(qreal);
  binder.add_void_fun<qreal, &QRectF::setTop>("setTop");
  // void setRight(qreal);
  binder.add_void_fun<qreal, &QRectF::setRight>("setRight");
  // void setBottom(qreal);
  binder.add_void_fun<qreal, &QRectF::setBottom>("setBottom");
  // void setX(qreal);
  binder.add_void_fun<qreal, &QRectF::setX>("setX");
  // void setY(qreal);
  binder.add_void_fun<qreal, &QRectF::setY>("setY");
  // QPointF topLeft() const;
  binder.add_fun<QPointF, &QRectF::topLeft>("topLeft");
  // QPointF bottomRight() const;
  binder.add_fun<QPointF, &QRectF::bottomRight>("bottomRight");
  // QPointF topRight() const;
  binder.add_fun<QPointF, &QRectF::topRight>("topRight");
  // QPointF bottomLeft() const;
  binder.add_fun<QPointF, &QRectF::bottomLeft>("bottomLeft");
  // QPointF center() const;
  binder.add_fun<QPointF, &QRectF::center>("center");
  // void setTopLeft(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::setTopLeft>("setTopLeft");
  // void setBottomRight(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::setBottomRight>("setBottomRight");
  // void setTopRight(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::setTopRight>("setTopRight");
  // void setBottomLeft(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::setBottomLeft>("setBottomLeft");
  // void moveLeft(qreal);
  binder.add_void_fun<qreal, &QRectF::moveLeft>("moveLeft");
  // void moveTop(qreal);
  binder.add_void_fun<qreal, &QRectF::moveTop>("moveTop");
  // void moveRight(qreal);
  binder.add_void_fun<qreal, &QRectF::moveRight>("moveRight");
  // void moveBottom(qreal);
  binder.add_void_fun<qreal, &QRectF::moveBottom>("moveBottom");
  // void moveTopLeft(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveTopLeft>("moveTopLeft");
  // void moveBottomRight(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveBottomRight>("moveBottomRight");
  // void moveTopRight(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveTopRight>("moveTopRight");
  // void moveBottomLeft(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveBottomLeft>("moveBottomLeft");
  // void moveCenter(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveCenter>("moveCenter");
  // void translate(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QRectF::translate>("translate");
  // void translate(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::translate>("translate");
  // QRectF translated(qreal, qreal) const;
  binder.add_fun<QRectF, qreal, qreal, &QRectF::translated>("translated");
  // QRectF translated(const QPointF &) const;
  binder.add_fun<QRectF, const QPointF &, &QRectF::translated>("translated");
  // QRectF transposed() const;
  binder.add_fun<QRectF, &QRectF::transposed>("transposed");
  // void moveTo(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QRectF::moveTo>("moveTo");
  // void moveTo(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRectF::moveTo>("moveTo");
  // void setRect(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QRectF::setRect>("setRect");
  // void getRect(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRect(qreal *, qreal *, qreal *, qreal *) const;
  // void setCoords(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QRectF::setCoords>("setCoords");
  // void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  // void adjust(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QRectF::adjust>("adjust");
  // QRectF adjusted(qreal, qreal, qreal, qreal) const;
  binder.add_fun<QRectF, qreal, qreal, qreal, qreal, &QRectF::adjusted>("adjusted");
  // QSizeF size() const;
  binder.add_fun<QSizeF, &QRectF::size>("size");
  // qreal width() const;
  binder.add_fun<qreal, &QRectF::width>("width");
  // qreal height() const;
  binder.add_fun<qreal, &QRectF::height>("height");
  // void setWidth(qreal);
  binder.add_void_fun<qreal, &QRectF::setWidth>("setWidth");
  // void setHeight(qreal);
  binder.add_void_fun<qreal, &QRectF::setHeight>("setHeight");
  // void setSize(const QSizeF &);
  binder.add_void_fun<const QSizeF &, &QRectF::setSize>("setSize");
  // QRectF operator|(const QRectF &) const;
  binder.operators().or<QRectF, const QRectF &>();
  // QRectF operator&(const QRectF &) const;
  binder.operators().and<QRectF, const QRectF &>();
  // QRectF & operator|=(const QRectF &);
  binder.operators().or_assign<const QRectF &>();
  // QRectF & operator&=(const QRectF &);
  binder.operators().and_assign<const QRectF &>();
  // bool contains(const QRectF &) const;
  binder.add_fun<bool, const QRectF &, &QRectF::contains>("contains");
  // bool contains(const QPointF &) const;
  binder.add_fun<bool, const QPointF &, &QRectF::contains>("contains");
  // bool contains(qreal, qreal) const;
  binder.add_fun<bool, qreal, qreal, &QRectF::contains>("contains");
  // QRectF united(const QRectF &) const;
  binder.add_fun<QRectF, const QRectF &, &QRectF::united>("united");
  // QRectF intersected(const QRectF &) const;
  binder.add_fun<QRectF, const QRectF &, &QRectF::intersected>("intersected");
  // bool intersects(const QRectF &) const;
  binder.add_fun<bool, const QRectF &, &QRectF::intersects>("intersects");
  // QRectF marginsAdded(const QMarginsF &) const;
  /// TODO: QRectF marginsAdded(const QMarginsF &) const;
  // QRectF marginsRemoved(const QMarginsF &) const;
  /// TODO: QRectF marginsRemoved(const QMarginsF &) const;
  // QRectF & operator+=(const QMarginsF &);
  /// TODO: QRectF & operator+=(const QMarginsF &);
  // QRectF & operator-=(const QMarginsF &);
  /// TODO: QRectF & operator-=(const QMarginsF &);
  // QRect toRect() const;
  binder.add_fun<QRect, &QRectF::toRect>("toRect");
  // QRect toAlignedRect() const;
  binder.add_fun<QRect, &QRectF::toAlignedRect>("toAlignedRect");
}


void register_rect_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_rect_class(ns);
  register_rect_f_class(ns);
  binding::Namespace binder{ ns };

  // bool operator==(const QRect &, const QRect &);
  binder.operators().eq<const QRect &, const QRect &>();
  // bool operator!=(const QRect &, const QRect &);
  binder.operators().neq<const QRect &, const QRect &>();
  // QDataStream & operator<<(QDataStream &, const QRect &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QRect &);
  // QDataStream & operator>>(QDataStream &, QRect &);
  /// TODO: QDataStream & operator>>(QDataStream &, QRect &);
  // bool operator==(const QRect &, const QRect &);
  binder.operators().eq<const QRect &, const QRect &>();
  // bool operator!=(const QRect &, const QRect &);
  binder.operators().neq<const QRect &, const QRect &>();
  // QRect operator+(const QRect &, const QMargins &);
  /// TODO: QRect operator+(const QRect &, const QMargins &);
  // QRect operator+(const QMargins &, const QRect &);
  /// TODO: QRect operator+(const QMargins &, const QRect &);
  // QRect operator-(const QRect &, const QMargins &);
  /// TODO: QRect operator-(const QRect &, const QMargins &);
  // QDebug operator<<(QDebug, const QRect &);
  /// TODO: QDebug operator<<(QDebug, const QRect &);
  // bool operator==(const QRectF &, const QRectF &);
  binder.operators().eq<const QRectF &, const QRectF &>();
  // bool operator!=(const QRectF &, const QRectF &);
  binder.operators().neq<const QRectF &, const QRectF &>();
  // QDataStream & operator<<(QDataStream &, const QRectF &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QRectF &);
  // QDataStream & operator>>(QDataStream &, QRectF &);
  /// TODO: QDataStream & operator>>(QDataStream &, QRectF &);
  // bool operator==(const QRectF &, const QRectF &);
  binder.operators().eq<const QRectF &, const QRectF &>();
  // bool operator!=(const QRectF &, const QRectF &);
  binder.operators().neq<const QRectF &, const QRectF &>();
  // QRectF operator+(const QRectF &, const QMarginsF &);
  /// TODO: QRectF operator+(const QRectF &, const QMarginsF &);
  // QRectF operator+(const QMarginsF &, const QRectF &);
  /// TODO: QRectF operator+(const QMarginsF &, const QRectF &);
  // QRectF operator-(const QRectF &, const QMarginsF &);
  /// TODO: QRectF operator-(const QRectF &, const QMarginsF &);
  // QDebug operator<<(QDebug, const QRectF &);
  /// TODO: QDebug operator<<(QDebug, const QRectF &);
}

