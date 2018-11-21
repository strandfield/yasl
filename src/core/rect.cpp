// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/rect.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/margins.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>

static void register_rect_class(script::Namespace ns)
{
  using namespace script;

  Class rect = ns.newClass("Rect").setId(script::Type::QRect).get();

  binding::ClassBinder<QRect> binder{ rect };

  // QRect();
  binder.default_ctor().create();
  // QRect(const QRect &);
  binder.ctor<const QRect &>().create();
  // ~QRect();
  binder.dtor().create();
  // QRect(const QPoint &, const QPoint &);
  binder.ctor<const QPoint &, const QPoint &>().create();
  // QRect(const QPoint &, const QSize &);
  binder.ctor<const QPoint &, const QSize &>().create();
  // QRect(int, int, int, int);
  binder.ctor<int, int, int, int>().create();
  // bool isNull() const;
  binder.fun<bool, &QRect::isNull>("isNull").create();
  // bool isEmpty() const;
  binder.fun<bool, &QRect::isEmpty>("isEmpty").create();
  // bool isValid() const;
  binder.fun<bool, &QRect::isValid>("isValid").create();
  // int left() const;
  binder.fun<int, &QRect::left>("left").create();
  // int top() const;
  binder.fun<int, &QRect::top>("top").create();
  // int right() const;
  binder.fun<int, &QRect::right>("right").create();
  // int bottom() const;
  binder.fun<int, &QRect::bottom>("bottom").create();
  // QRect normalized() const;
  binder.fun<QRect, &QRect::normalized>("normalized").create();
  // int x() const;
  binder.fun<int, &QRect::x>("x").create();
  // int y() const;
  binder.fun<int, &QRect::y>("y").create();
  // void setLeft(int);
  binder.void_fun<int, &QRect::setLeft>("setLeft").create();
  // void setTop(int);
  binder.void_fun<int, &QRect::setTop>("setTop").create();
  // void setRight(int);
  binder.void_fun<int, &QRect::setRight>("setRight").create();
  // void setBottom(int);
  binder.void_fun<int, &QRect::setBottom>("setBottom").create();
  // void setX(int);
  binder.void_fun<int, &QRect::setX>("setX").create();
  // void setY(int);
  binder.void_fun<int, &QRect::setY>("setY").create();
  // void setTopLeft(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::setTopLeft>("setTopLeft").create();
  // void setBottomRight(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::setBottomRight>("setBottomRight").create();
  // void setTopRight(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::setTopRight>("setTopRight").create();
  // void setBottomLeft(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::setBottomLeft>("setBottomLeft").create();
  // QPoint topLeft() const;
  binder.fun<QPoint, &QRect::topLeft>("topLeft").create();
  // QPoint bottomRight() const;
  binder.fun<QPoint, &QRect::bottomRight>("bottomRight").create();
  // QPoint topRight() const;
  binder.fun<QPoint, &QRect::topRight>("topRight").create();
  // QPoint bottomLeft() const;
  binder.fun<QPoint, &QRect::bottomLeft>("bottomLeft").create();
  // QPoint center() const;
  binder.fun<QPoint, &QRect::center>("center").create();
  // void moveLeft(int);
  binder.void_fun<int, &QRect::moveLeft>("moveLeft").create();
  // void moveTop(int);
  binder.void_fun<int, &QRect::moveTop>("moveTop").create();
  // void moveRight(int);
  binder.void_fun<int, &QRect::moveRight>("moveRight").create();
  // void moveBottom(int);
  binder.void_fun<int, &QRect::moveBottom>("moveBottom").create();
  // void moveTopLeft(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveTopLeft>("moveTopLeft").create();
  // void moveBottomRight(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveBottomRight>("moveBottomRight").create();
  // void moveTopRight(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveTopRight>("moveTopRight").create();
  // void moveBottomLeft(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveBottomLeft>("moveBottomLeft").create();
  // void moveCenter(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveCenter>("moveCenter").create();
  // void translate(int, int);
  binder.void_fun<int, int, &QRect::translate>("translate").create();
  // void translate(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::translate>("translate").create();
  // QRect translated(int, int) const;
  binder.fun<QRect, int, int, &QRect::translated>("translated").create();
  // QRect translated(const QPoint &) const;
  binder.fun<QRect, const QPoint &, &QRect::translated>("translated").create();
  // QRect transposed() const;
  binder.fun<QRect, &QRect::transposed>("transposed").create();
  // void moveTo(int, int);
  binder.void_fun<int, int, &QRect::moveTo>("moveTo").create();
  // void moveTo(const QPoint &);
  binder.void_fun<const QPoint &, &QRect::moveTo>("moveTo").create();
  // void setRect(int, int, int, int);
  binder.void_fun<int, int, int, int, &QRect::setRect>("setRect").create();
  // void getRect(int *, int *, int *, int *) const;
  /// TODO: void getRect(int *, int *, int *, int *) const;
  // void setCoords(int, int, int, int);
  binder.void_fun<int, int, int, int, &QRect::setCoords>("setCoords").create();
  // void getCoords(int *, int *, int *, int *) const;
  /// TODO: void getCoords(int *, int *, int *, int *) const;
  // void adjust(int, int, int, int);
  binder.void_fun<int, int, int, int, &QRect::adjust>("adjust").create();
  // QRect adjusted(int, int, int, int) const;
  binder.fun<QRect, int, int, int, int, &QRect::adjusted>("adjusted").create();
  // QSize size() const;
  binder.fun<QSize, &QRect::size>("size").create();
  // int width() const;
  binder.fun<int, &QRect::width>("width").create();
  // int height() const;
  binder.fun<int, &QRect::height>("height").create();
  // void setWidth(int);
  binder.void_fun<int, &QRect::setWidth>("setWidth").create();
  // void setHeight(int);
  binder.void_fun<int, &QRect::setHeight>("setHeight").create();
  // void setSize(const QSize &);
  binder.void_fun<const QSize &, &QRect::setSize>("setSize").create();
  // QRect operator|(const QRect &) const;
  binder.operators().or<QRect, const QRect &>();
  // QRect operator&(const QRect &) const;
  binder.operators().and<QRect, const QRect &>();
  // QRect & operator|=(const QRect &);
  binder.operators().or_assign<const QRect &>();
  // QRect & operator&=(const QRect &);
  binder.operators().and_assign<const QRect &>();
  // bool contains(const QRect &, bool) const;
  binder.fun<bool, const QRect &, bool, &QRect::contains>("contains").create();
  // bool contains(const QPoint &, bool) const;
  binder.fun<bool, const QPoint &, bool, &QRect::contains>("contains").create();
  // bool contains(int, int) const;
  binder.fun<bool, int, int, &QRect::contains>("contains").create();
  // bool contains(int, int, bool) const;
  binder.fun<bool, int, int, bool, &QRect::contains>("contains").create();
  // QRect united(const QRect &) const;
  binder.fun<QRect, const QRect &, &QRect::united>("united").create();
  // QRect intersected(const QRect &) const;
  binder.fun<QRect, const QRect &, &QRect::intersected>("intersected").create();
  // bool intersects(const QRect &) const;
  binder.fun<bool, const QRect &, &QRect::intersects>("intersects").create();
  // QRect marginsAdded(const QMargins &) const;
  binder.fun<QRect, const QMargins &, &QRect::marginsAdded>("marginsAdded").create();
  // QRect marginsRemoved(const QMargins &) const;
  binder.fun<QRect, const QMargins &, &QRect::marginsRemoved>("marginsRemoved").create();
  // QRect & operator+=(const QMargins &);
  binder.operators().add_assign<const QMargins &>();
  // QRect & operator-=(const QMargins &);
  binder.operators().sub_assign<const QMargins &>();
}


static void register_rect_f_class(script::Namespace ns)
{
  using namespace script;

  Class rect_f = ns.newClass("RectF").setId(script::Type::QRectF).get();

  binding::ClassBinder<QRectF> binder{ rect_f };

  // QRectF();
  binder.default_ctor().create();
  // QRectF(const QRectF &);
  binder.ctor<const QRectF &>().create();
  // ~QRectF();
  binder.dtor().create();
  // QRectF(const QPointF &, const QSizeF &);
  binder.ctor<const QPointF &, const QSizeF &>().create();
  // QRectF(const QPointF &, const QPointF &);
  binder.ctor<const QPointF &, const QPointF &>().create();
  // QRectF(qreal, qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal, qreal>().create();
  // QRectF(const QRect &);
  binder.ctor<const QRect &>().create();
  // bool isNull() const;
  binder.fun<bool, &QRectF::isNull>("isNull").create();
  // bool isEmpty() const;
  binder.fun<bool, &QRectF::isEmpty>("isEmpty").create();
  // bool isValid() const;
  binder.fun<bool, &QRectF::isValid>("isValid").create();
  // QRectF normalized() const;
  binder.fun<QRectF, &QRectF::normalized>("normalized").create();
  // qreal left() const;
  binder.fun<qreal, &QRectF::left>("left").create();
  // qreal top() const;
  binder.fun<qreal, &QRectF::top>("top").create();
  // qreal right() const;
  binder.fun<qreal, &QRectF::right>("right").create();
  // qreal bottom() const;
  binder.fun<qreal, &QRectF::bottom>("bottom").create();
  // qreal x() const;
  binder.fun<qreal, &QRectF::x>("x").create();
  // qreal y() const;
  binder.fun<qreal, &QRectF::y>("y").create();
  // void setLeft(qreal);
  binder.void_fun<qreal, &QRectF::setLeft>("setLeft").create();
  // void setTop(qreal);
  binder.void_fun<qreal, &QRectF::setTop>("setTop").create();
  // void setRight(qreal);
  binder.void_fun<qreal, &QRectF::setRight>("setRight").create();
  // void setBottom(qreal);
  binder.void_fun<qreal, &QRectF::setBottom>("setBottom").create();
  // void setX(qreal);
  binder.void_fun<qreal, &QRectF::setX>("setX").create();
  // void setY(qreal);
  binder.void_fun<qreal, &QRectF::setY>("setY").create();
  // QPointF topLeft() const;
  binder.fun<QPointF, &QRectF::topLeft>("topLeft").create();
  // QPointF bottomRight() const;
  binder.fun<QPointF, &QRectF::bottomRight>("bottomRight").create();
  // QPointF topRight() const;
  binder.fun<QPointF, &QRectF::topRight>("topRight").create();
  // QPointF bottomLeft() const;
  binder.fun<QPointF, &QRectF::bottomLeft>("bottomLeft").create();
  // QPointF center() const;
  binder.fun<QPointF, &QRectF::center>("center").create();
  // void setTopLeft(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::setTopLeft>("setTopLeft").create();
  // void setBottomRight(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::setBottomRight>("setBottomRight").create();
  // void setTopRight(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::setTopRight>("setTopRight").create();
  // void setBottomLeft(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::setBottomLeft>("setBottomLeft").create();
  // void moveLeft(qreal);
  binder.void_fun<qreal, &QRectF::moveLeft>("moveLeft").create();
  // void moveTop(qreal);
  binder.void_fun<qreal, &QRectF::moveTop>("moveTop").create();
  // void moveRight(qreal);
  binder.void_fun<qreal, &QRectF::moveRight>("moveRight").create();
  // void moveBottom(qreal);
  binder.void_fun<qreal, &QRectF::moveBottom>("moveBottom").create();
  // void moveTopLeft(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveTopLeft>("moveTopLeft").create();
  // void moveBottomRight(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveBottomRight>("moveBottomRight").create();
  // void moveTopRight(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveTopRight>("moveTopRight").create();
  // void moveBottomLeft(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveBottomLeft>("moveBottomLeft").create();
  // void moveCenter(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveCenter>("moveCenter").create();
  // void translate(qreal, qreal);
  binder.void_fun<qreal, qreal, &QRectF::translate>("translate").create();
  // void translate(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::translate>("translate").create();
  // QRectF translated(qreal, qreal) const;
  binder.fun<QRectF, qreal, qreal, &QRectF::translated>("translated").create();
  // QRectF translated(const QPointF &) const;
  binder.fun<QRectF, const QPointF &, &QRectF::translated>("translated").create();
  // QRectF transposed() const;
  binder.fun<QRectF, &QRectF::transposed>("transposed").create();
  // void moveTo(qreal, qreal);
  binder.void_fun<qreal, qreal, &QRectF::moveTo>("moveTo").create();
  // void moveTo(const QPointF &);
  binder.void_fun<const QPointF &, &QRectF::moveTo>("moveTo").create();
  // void setRect(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QRectF::setRect>("setRect").create();
  // void getRect(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRect(qreal *, qreal *, qreal *, qreal *) const;
  // void setCoords(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QRectF::setCoords>("setCoords").create();
  // void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  // void adjust(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QRectF::adjust>("adjust").create();
  // QRectF adjusted(qreal, qreal, qreal, qreal) const;
  binder.fun<QRectF, qreal, qreal, qreal, qreal, &QRectF::adjusted>("adjusted").create();
  // QSizeF size() const;
  binder.fun<QSizeF, &QRectF::size>("size").create();
  // qreal width() const;
  binder.fun<qreal, &QRectF::width>("width").create();
  // qreal height() const;
  binder.fun<qreal, &QRectF::height>("height").create();
  // void setWidth(qreal);
  binder.void_fun<qreal, &QRectF::setWidth>("setWidth").create();
  // void setHeight(qreal);
  binder.void_fun<qreal, &QRectF::setHeight>("setHeight").create();
  // void setSize(const QSizeF &);
  binder.void_fun<const QSizeF &, &QRectF::setSize>("setSize").create();
  // QRectF operator|(const QRectF &) const;
  binder.operators().or<QRectF, const QRectF &>();
  // QRectF operator&(const QRectF &) const;
  binder.operators().and<QRectF, const QRectF &>();
  // QRectF & operator|=(const QRectF &);
  binder.operators().or_assign<const QRectF &>();
  // QRectF & operator&=(const QRectF &);
  binder.operators().and_assign<const QRectF &>();
  // bool contains(const QRectF &) const;
  binder.fun<bool, const QRectF &, &QRectF::contains>("contains").create();
  // bool contains(const QPointF &) const;
  binder.fun<bool, const QPointF &, &QRectF::contains>("contains").create();
  // bool contains(qreal, qreal) const;
  binder.fun<bool, qreal, qreal, &QRectF::contains>("contains").create();
  // QRectF united(const QRectF &) const;
  binder.fun<QRectF, const QRectF &, &QRectF::united>("united").create();
  // QRectF intersected(const QRectF &) const;
  binder.fun<QRectF, const QRectF &, &QRectF::intersected>("intersected").create();
  // bool intersects(const QRectF &) const;
  binder.fun<bool, const QRectF &, &QRectF::intersects>("intersects").create();
  // QRectF marginsAdded(const QMarginsF &) const;
  binder.fun<QRectF, const QMarginsF &, &QRectF::marginsAdded>("marginsAdded").create();
  // QRectF marginsRemoved(const QMarginsF &) const;
  binder.fun<QRectF, const QMarginsF &, &QRectF::marginsRemoved>("marginsRemoved").create();
  // QRectF & operator+=(const QMarginsF &);
  binder.operators().add_assign<const QMarginsF &>();
  // QRectF & operator-=(const QMarginsF &);
  binder.operators().sub_assign<const QMarginsF &>();
  // QRect toRect() const;
  binder.fun<QRect, &QRectF::toRect>("toRect").create();
  // QRect toAlignedRect() const;
  binder.fun<QRect, &QRectF::toAlignedRect>("toAlignedRect").create();
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
  binder.operators().put_to<QDataStream &, const QRect &>();
  // QDataStream & operator>>(QDataStream &, QRect &);
  binder.operators().read_from<QDataStream &, QRect &>();
  // bool operator==(const QRect &, const QRect &);
  binder.operators().eq<const QRect &, const QRect &>();
  // bool operator!=(const QRect &, const QRect &);
  binder.operators().neq<const QRect &, const QRect &>();
  // QRect operator+(const QRect &, const QMargins &);
  binder.operators().add<QRect, const QRect &, const QMargins &>();
  // QRect operator+(const QMargins &, const QRect &);
  binder.operators().add<QRect, const QMargins &, const QRect &>();
  // QRect operator-(const QRect &, const QMargins &);
  binder.operators().sub<QRect, const QRect &, const QMargins &>();
  // QDebug operator<<(QDebug, const QRect &);
  /// TODO: QDebug operator<<(QDebug, const QRect &);
  // bool operator==(const QRectF &, const QRectF &);
  binder.operators().eq<const QRectF &, const QRectF &>();
  // bool operator!=(const QRectF &, const QRectF &);
  binder.operators().neq<const QRectF &, const QRectF &>();
  // QDataStream & operator<<(QDataStream &, const QRectF &);
  binder.operators().put_to<QDataStream &, const QRectF &>();
  // QDataStream & operator>>(QDataStream &, QRectF &);
  binder.operators().read_from<QDataStream &, QRectF &>();
  // bool operator==(const QRectF &, const QRectF &);
  binder.operators().eq<const QRectF &, const QRectF &>();
  // bool operator!=(const QRectF &, const QRectF &);
  binder.operators().neq<const QRectF &, const QRectF &>();
  // QRectF operator+(const QRectF &, const QMarginsF &);
  binder.operators().add<QRectF, const QRectF &, const QMarginsF &>();
  // QRectF operator+(const QMarginsF &, const QRectF &);
  binder.operators().add<QRectF, const QMarginsF &, const QRectF &>();
  // QRectF operator-(const QRectF &, const QMarginsF &);
  binder.operators().sub<QRectF, const QRectF &, const QMarginsF &>();
  // QDebug operator<<(QDebug, const QRectF &);
  /// TODO: QDebug operator<<(QDebug, const QRectF &);
}

