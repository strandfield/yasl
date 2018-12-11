// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/rect.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

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


  // QRect();
  bind::default_constructor<QRect>(rect).create();
  // QRect(const QRect &);
  bind::constructor<QRect, const QRect &>(rect).create();
  // ~QRect();
  bind::destructor<QRect>(rect).create();
  // QRect(const QPoint &, const QPoint &);
  bind::constructor<QRect, const QPoint &, const QPoint &>(rect).create();
  // QRect(const QPoint &, const QSize &);
  bind::constructor<QRect, const QPoint &, const QSize &>(rect).create();
  // QRect(int, int, int, int);
  bind::constructor<QRect, int, int, int, int>(rect).create();
  // bool isNull() const;
  bind::member_function<QRect, bool, &QRect::isNull>(rect, "isNull").create();
  // bool isEmpty() const;
  bind::member_function<QRect, bool, &QRect::isEmpty>(rect, "isEmpty").create();
  // bool isValid() const;
  bind::member_function<QRect, bool, &QRect::isValid>(rect, "isValid").create();
  // int left() const;
  bind::member_function<QRect, int, &QRect::left>(rect, "left").create();
  // int top() const;
  bind::member_function<QRect, int, &QRect::top>(rect, "top").create();
  // int right() const;
  bind::member_function<QRect, int, &QRect::right>(rect, "right").create();
  // int bottom() const;
  bind::member_function<QRect, int, &QRect::bottom>(rect, "bottom").create();
  // QRect normalized() const;
  bind::member_function<QRect, QRect, &QRect::normalized>(rect, "normalized").create();
  // int x() const;
  bind::member_function<QRect, int, &QRect::x>(rect, "x").create();
  // int y() const;
  bind::member_function<QRect, int, &QRect::y>(rect, "y").create();
  // void setLeft(int);
  bind::void_member_function<QRect, int, &QRect::setLeft>(rect, "setLeft").create();
  // void setTop(int);
  bind::void_member_function<QRect, int, &QRect::setTop>(rect, "setTop").create();
  // void setRight(int);
  bind::void_member_function<QRect, int, &QRect::setRight>(rect, "setRight").create();
  // void setBottom(int);
  bind::void_member_function<QRect, int, &QRect::setBottom>(rect, "setBottom").create();
  // void setX(int);
  bind::void_member_function<QRect, int, &QRect::setX>(rect, "setX").create();
  // void setY(int);
  bind::void_member_function<QRect, int, &QRect::setY>(rect, "setY").create();
  // void setTopLeft(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::setTopLeft>(rect, "setTopLeft").create();
  // void setBottomRight(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::setBottomRight>(rect, "setBottomRight").create();
  // void setTopRight(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::setTopRight>(rect, "setTopRight").create();
  // void setBottomLeft(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::setBottomLeft>(rect, "setBottomLeft").create();
  // QPoint topLeft() const;
  bind::member_function<QRect, QPoint, &QRect::topLeft>(rect, "topLeft").create();
  // QPoint bottomRight() const;
  bind::member_function<QRect, QPoint, &QRect::bottomRight>(rect, "bottomRight").create();
  // QPoint topRight() const;
  bind::member_function<QRect, QPoint, &QRect::topRight>(rect, "topRight").create();
  // QPoint bottomLeft() const;
  bind::member_function<QRect, QPoint, &QRect::bottomLeft>(rect, "bottomLeft").create();
  // QPoint center() const;
  bind::member_function<QRect, QPoint, &QRect::center>(rect, "center").create();
  // void moveLeft(int);
  bind::void_member_function<QRect, int, &QRect::moveLeft>(rect, "moveLeft").create();
  // void moveTop(int);
  bind::void_member_function<QRect, int, &QRect::moveTop>(rect, "moveTop").create();
  // void moveRight(int);
  bind::void_member_function<QRect, int, &QRect::moveRight>(rect, "moveRight").create();
  // void moveBottom(int);
  bind::void_member_function<QRect, int, &QRect::moveBottom>(rect, "moveBottom").create();
  // void moveTopLeft(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveTopLeft>(rect, "moveTopLeft").create();
  // void moveBottomRight(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveBottomRight>(rect, "moveBottomRight").create();
  // void moveTopRight(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveTopRight>(rect, "moveTopRight").create();
  // void moveBottomLeft(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveBottomLeft>(rect, "moveBottomLeft").create();
  // void moveCenter(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveCenter>(rect, "moveCenter").create();
  // void translate(int, int);
  bind::void_member_function<QRect, int, int, &QRect::translate>(rect, "translate").create();
  // void translate(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::translate>(rect, "translate").create();
  // QRect translated(int, int) const;
  bind::member_function<QRect, QRect, int, int, &QRect::translated>(rect, "translated").create();
  // QRect translated(const QPoint &) const;
  bind::member_function<QRect, QRect, const QPoint &, &QRect::translated>(rect, "translated").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QRect transposed() const;
  bind::member_function<QRect, QRect, &QRect::transposed>(rect, "transposed").create();
#endif
  // void moveTo(int, int);
  bind::void_member_function<QRect, int, int, &QRect::moveTo>(rect, "moveTo").create();
  // void moveTo(const QPoint &);
  bind::void_member_function<QRect, const QPoint &, &QRect::moveTo>(rect, "moveTo").create();
  // void setRect(int, int, int, int);
  bind::void_member_function<QRect, int, int, int, int, &QRect::setRect>(rect, "setRect").create();
  // void getRect(int *, int *, int *, int *) const;
  /// TODO: void getRect(int *, int *, int *, int *) const;
  // void setCoords(int, int, int, int);
  bind::void_member_function<QRect, int, int, int, int, &QRect::setCoords>(rect, "setCoords").create();
  // void getCoords(int *, int *, int *, int *) const;
  /// TODO: void getCoords(int *, int *, int *, int *) const;
  // void adjust(int, int, int, int);
  bind::void_member_function<QRect, int, int, int, int, &QRect::adjust>(rect, "adjust").create();
  // QRect adjusted(int, int, int, int) const;
  bind::member_function<QRect, QRect, int, int, int, int, &QRect::adjusted>(rect, "adjusted").create();
  // QSize size() const;
  bind::member_function<QRect, QSize, &QRect::size>(rect, "size").create();
  // int width() const;
  bind::member_function<QRect, int, &QRect::width>(rect, "width").create();
  // int height() const;
  bind::member_function<QRect, int, &QRect::height>(rect, "height").create();
  // void setWidth(int);
  bind::void_member_function<QRect, int, &QRect::setWidth>(rect, "setWidth").create();
  // void setHeight(int);
  bind::void_member_function<QRect, int, &QRect::setHeight>(rect, "setHeight").create();
  // void setSize(const QSize &);
  bind::void_member_function<QRect, const QSize &, &QRect::setSize>(rect, "setSize").create();
  // QRect operator|(const QRect &) const;
  bind::memop_bitor<QRect, QRect, const QRect &>(rect);
  // QRect operator&(const QRect &) const;
  bind::memop_bitand<QRect, QRect, const QRect &>(rect);
  // QRect & operator|=(const QRect &);
  bind::memop_or_assign<QRect, const QRect &>(rect);
  // QRect & operator&=(const QRect &);
  bind::memop_and_assign<QRect, const QRect &>(rect);
  // bool contains(const QRect &, bool) const;
  bind::member_function<QRect, bool, const QRect &, bool, &QRect::contains>(rect, "contains").create();
  // bool contains(const QPoint &, bool) const;
  bind::member_function<QRect, bool, const QPoint &, bool, &QRect::contains>(rect, "contains").create();
  // bool contains(int, int) const;
  bind::member_function<QRect, bool, int, int, &QRect::contains>(rect, "contains").create();
  // bool contains(int, int, bool) const;
  bind::member_function<QRect, bool, int, int, bool, &QRect::contains>(rect, "contains").create();
  // QRect united(const QRect &) const;
  bind::member_function<QRect, QRect, const QRect &, &QRect::united>(rect, "united").create();
  // QRect intersected(const QRect &) const;
  bind::member_function<QRect, QRect, const QRect &, &QRect::intersected>(rect, "intersected").create();
  // bool intersects(const QRect &) const;
  bind::member_function<QRect, bool, const QRect &, &QRect::intersects>(rect, "intersects").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect marginsAdded(const QMargins &) const;
  bind::member_function<QRect, QRect, const QMargins &, &QRect::marginsAdded>(rect, "marginsAdded").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect marginsRemoved(const QMargins &) const;
  bind::member_function<QRect, QRect, const QMargins &, &QRect::marginsRemoved>(rect, "marginsRemoved").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect & operator+=(const QMargins &);
  bind::memop_add_assign<QRect, const QMargins &>(rect);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect & operator-=(const QMargins &);
  bind::memop_sub_assign<QRect, const QMargins &>(rect);
#endif

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QRect, QMetaType::QRect>>();
}


static void register_rect_f_class(script::Namespace ns)
{
  using namespace script;

  Class rect_f = ns.newClass("RectF").setId(script::Type::QRectF).get();


  // QRectF();
  bind::default_constructor<QRectF>(rect_f).create();
  // QRectF(const QRectF &);
  bind::constructor<QRectF, const QRectF &>(rect_f).create();
  // ~QRectF();
  bind::destructor<QRectF>(rect_f).create();
  // QRectF(const QPointF &, const QSizeF &);
  bind::constructor<QRectF, const QPointF &, const QSizeF &>(rect_f).create();
  // QRectF(const QPointF &, const QPointF &);
  bind::constructor<QRectF, const QPointF &, const QPointF &>(rect_f).create();
  // QRectF(qreal, qreal, qreal, qreal);
  bind::constructor<QRectF, qreal, qreal, qreal, qreal>(rect_f).create();
  // QRectF(const QRect &);
  bind::constructor<QRectF, const QRect &>(rect_f).create();
  // bool isNull() const;
  bind::member_function<QRectF, bool, &QRectF::isNull>(rect_f, "isNull").create();
  // bool isEmpty() const;
  bind::member_function<QRectF, bool, &QRectF::isEmpty>(rect_f, "isEmpty").create();
  // bool isValid() const;
  bind::member_function<QRectF, bool, &QRectF::isValid>(rect_f, "isValid").create();
  // QRectF normalized() const;
  bind::member_function<QRectF, QRectF, &QRectF::normalized>(rect_f, "normalized").create();
  // qreal left() const;
  bind::member_function<QRectF, qreal, &QRectF::left>(rect_f, "left").create();
  // qreal top() const;
  bind::member_function<QRectF, qreal, &QRectF::top>(rect_f, "top").create();
  // qreal right() const;
  bind::member_function<QRectF, qreal, &QRectF::right>(rect_f, "right").create();
  // qreal bottom() const;
  bind::member_function<QRectF, qreal, &QRectF::bottom>(rect_f, "bottom").create();
  // qreal x() const;
  bind::member_function<QRectF, qreal, &QRectF::x>(rect_f, "x").create();
  // qreal y() const;
  bind::member_function<QRectF, qreal, &QRectF::y>(rect_f, "y").create();
  // void setLeft(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setLeft>(rect_f, "setLeft").create();
  // void setTop(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setTop>(rect_f, "setTop").create();
  // void setRight(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setRight>(rect_f, "setRight").create();
  // void setBottom(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setBottom>(rect_f, "setBottom").create();
  // void setX(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setX>(rect_f, "setX").create();
  // void setY(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setY>(rect_f, "setY").create();
  // QPointF topLeft() const;
  bind::member_function<QRectF, QPointF, &QRectF::topLeft>(rect_f, "topLeft").create();
  // QPointF bottomRight() const;
  bind::member_function<QRectF, QPointF, &QRectF::bottomRight>(rect_f, "bottomRight").create();
  // QPointF topRight() const;
  bind::member_function<QRectF, QPointF, &QRectF::topRight>(rect_f, "topRight").create();
  // QPointF bottomLeft() const;
  bind::member_function<QRectF, QPointF, &QRectF::bottomLeft>(rect_f, "bottomLeft").create();
  // QPointF center() const;
  bind::member_function<QRectF, QPointF, &QRectF::center>(rect_f, "center").create();
  // void setTopLeft(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::setTopLeft>(rect_f, "setTopLeft").create();
  // void setBottomRight(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::setBottomRight>(rect_f, "setBottomRight").create();
  // void setTopRight(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::setTopRight>(rect_f, "setTopRight").create();
  // void setBottomLeft(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::setBottomLeft>(rect_f, "setBottomLeft").create();
  // void moveLeft(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::moveLeft>(rect_f, "moveLeft").create();
  // void moveTop(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::moveTop>(rect_f, "moveTop").create();
  // void moveRight(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::moveRight>(rect_f, "moveRight").create();
  // void moveBottom(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::moveBottom>(rect_f, "moveBottom").create();
  // void moveTopLeft(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveTopLeft>(rect_f, "moveTopLeft").create();
  // void moveBottomRight(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveBottomRight>(rect_f, "moveBottomRight").create();
  // void moveTopRight(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveTopRight>(rect_f, "moveTopRight").create();
  // void moveBottomLeft(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveBottomLeft>(rect_f, "moveBottomLeft").create();
  // void moveCenter(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveCenter>(rect_f, "moveCenter").create();
  // void translate(qreal, qreal);
  bind::void_member_function<QRectF, qreal, qreal, &QRectF::translate>(rect_f, "translate").create();
  // void translate(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::translate>(rect_f, "translate").create();
  // QRectF translated(qreal, qreal) const;
  bind::member_function<QRectF, QRectF, qreal, qreal, &QRectF::translated>(rect_f, "translated").create();
  // QRectF translated(const QPointF &) const;
  bind::member_function<QRectF, QRectF, const QPointF &, &QRectF::translated>(rect_f, "translated").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QRectF transposed() const;
  bind::member_function<QRectF, QRectF, &QRectF::transposed>(rect_f, "transposed").create();
#endif
  // void moveTo(qreal, qreal);
  bind::void_member_function<QRectF, qreal, qreal, &QRectF::moveTo>(rect_f, "moveTo").create();
  // void moveTo(const QPointF &);
  bind::void_member_function<QRectF, const QPointF &, &QRectF::moveTo>(rect_f, "moveTo").create();
  // void setRect(qreal, qreal, qreal, qreal);
  bind::void_member_function<QRectF, qreal, qreal, qreal, qreal, &QRectF::setRect>(rect_f, "setRect").create();
  // void getRect(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRect(qreal *, qreal *, qreal *, qreal *) const;
  // void setCoords(qreal, qreal, qreal, qreal);
  bind::void_member_function<QRectF, qreal, qreal, qreal, qreal, &QRectF::setCoords>(rect_f, "setCoords").create();
  // void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getCoords(qreal *, qreal *, qreal *, qreal *) const;
  // void adjust(qreal, qreal, qreal, qreal);
  bind::void_member_function<QRectF, qreal, qreal, qreal, qreal, &QRectF::adjust>(rect_f, "adjust").create();
  // QRectF adjusted(qreal, qreal, qreal, qreal) const;
  bind::member_function<QRectF, QRectF, qreal, qreal, qreal, qreal, &QRectF::adjusted>(rect_f, "adjusted").create();
  // QSizeF size() const;
  bind::member_function<QRectF, QSizeF, &QRectF::size>(rect_f, "size").create();
  // qreal width() const;
  bind::member_function<QRectF, qreal, &QRectF::width>(rect_f, "width").create();
  // qreal height() const;
  bind::member_function<QRectF, qreal, &QRectF::height>(rect_f, "height").create();
  // void setWidth(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setWidth>(rect_f, "setWidth").create();
  // void setHeight(qreal);
  bind::void_member_function<QRectF, qreal, &QRectF::setHeight>(rect_f, "setHeight").create();
  // void setSize(const QSizeF &);
  bind::void_member_function<QRectF, const QSizeF &, &QRectF::setSize>(rect_f, "setSize").create();
  // QRectF operator|(const QRectF &) const;
  bind::memop_bitor<QRectF, QRectF, const QRectF &>(rect_f);
  // QRectF operator&(const QRectF &) const;
  bind::memop_bitand<QRectF, QRectF, const QRectF &>(rect_f);
  // QRectF & operator|=(const QRectF &);
  bind::memop_or_assign<QRectF, const QRectF &>(rect_f);
  // QRectF & operator&=(const QRectF &);
  bind::memop_and_assign<QRectF, const QRectF &>(rect_f);
  // bool contains(const QRectF &) const;
  bind::member_function<QRectF, bool, const QRectF &, &QRectF::contains>(rect_f, "contains").create();
  // bool contains(const QPointF &) const;
  bind::member_function<QRectF, bool, const QPointF &, &QRectF::contains>(rect_f, "contains").create();
  // bool contains(qreal, qreal) const;
  bind::member_function<QRectF, bool, qreal, qreal, &QRectF::contains>(rect_f, "contains").create();
  // QRectF united(const QRectF &) const;
  bind::member_function<QRectF, QRectF, const QRectF &, &QRectF::united>(rect_f, "united").create();
  // QRectF intersected(const QRectF &) const;
  bind::member_function<QRectF, QRectF, const QRectF &, &QRectF::intersected>(rect_f, "intersected").create();
  // bool intersects(const QRectF &) const;
  bind::member_function<QRectF, bool, const QRectF &, &QRectF::intersects>(rect_f, "intersects").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF marginsAdded(const QMarginsF &) const;
  bind::member_function<QRectF, QRectF, const QMarginsF &, &QRectF::marginsAdded>(rect_f, "marginsAdded").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF marginsRemoved(const QMarginsF &) const;
  bind::member_function<QRectF, QRectF, const QMarginsF &, &QRectF::marginsRemoved>(rect_f, "marginsRemoved").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF & operator+=(const QMarginsF &);
  bind::memop_add_assign<QRectF, const QMarginsF &>(rect_f);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF & operator-=(const QMarginsF &);
  bind::memop_sub_assign<QRectF, const QMarginsF &>(rect_f);
#endif
  // QRect toRect() const;
  bind::member_function<QRectF, QRect, &QRectF::toRect>(rect_f, "toRect").create();
  // QRect toAlignedRect() const;
  bind::member_function<QRectF, QRect, &QRectF::toAlignedRect>(rect_f, "toAlignedRect").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QRectF, QMetaType::QRectF>>();
}


void register_rect_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_rect_class(ns);
  register_rect_f_class(ns);

  // bool operator==(const QRect &, const QRect &);
  bind::op_eq<const QRect &, const QRect &>(ns);
  // bool operator!=(const QRect &, const QRect &);
  bind::op_neq<const QRect &, const QRect &>(ns);
  // QDataStream & operator<<(QDataStream &, const QRect &);
  bind::op_put_to<QDataStream &, const QRect &>(ns);
  // QDataStream & operator>>(QDataStream &, QRect &);
  bind::op_read_from<QDataStream &, QRect &>(ns);
  // bool operator==(const QRect &, const QRect &);
  bind::op_eq<const QRect &, const QRect &>(ns);
  // bool operator!=(const QRect &, const QRect &);
  bind::op_neq<const QRect &, const QRect &>(ns);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect operator+(const QRect &, const QMargins &);
  bind::op_add<QRect, const QRect &, const QMargins &>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRect operator+(const QMargins &, const QRect &);
  bind::op_add<QRect, const QMargins &, const QRect &>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRect operator-(const QRect &, const QMargins &);
  bind::op_sub<QRect, const QRect &, const QMargins &>(ns);
#endif
  // QDebug operator<<(QDebug, const QRect &);
  /// TODO: QDebug operator<<(QDebug, const QRect &);
  // bool operator==(const QRectF &, const QRectF &);
  bind::op_eq<const QRectF &, const QRectF &>(ns);
  // bool operator!=(const QRectF &, const QRectF &);
  bind::op_neq<const QRectF &, const QRectF &>(ns);
  // QDataStream & operator<<(QDataStream &, const QRectF &);
  bind::op_put_to<QDataStream &, const QRectF &>(ns);
  // QDataStream & operator>>(QDataStream &, QRectF &);
  bind::op_read_from<QDataStream &, QRectF &>(ns);
  // bool operator==(const QRectF &, const QRectF &);
  bind::op_eq<const QRectF &, const QRectF &>(ns);
  // bool operator!=(const QRectF &, const QRectF &);
  bind::op_neq<const QRectF &, const QRectF &>(ns);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF operator+(const QRectF &, const QMarginsF &);
  bind::op_add<QRectF, const QRectF &, const QMarginsF &>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF operator+(const QMarginsF &, const QRectF &);
  bind::op_add<QRectF, const QMarginsF &, const QRectF &>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // QRectF operator-(const QRectF &, const QMarginsF &);
  bind::op_sub<QRectF, const QRectF &, const QMarginsF &>(ns);
#endif
  // QDebug operator<<(QDebug, const QRectF &);
  /// TODO: QDebug operator<<(QDebug, const QRectF &);
}
