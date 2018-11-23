// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/cursor.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/cursor.h"
#include "yasl/gui/pixmap.h"

#include <script/classbuilder.h>

static void register_cursor_class(script::Namespace ns)
{
  using namespace script;

  Class cursor = ns.newClass("Cursor").setId(script::Type::QCursor).get();


  // QCursor();
  bind::default_constructor<QCursor>(cursor).create();
  // QCursor(Qt::CursorShape);
  bind::constructor<QCursor, Qt::CursorShape>(cursor).create();
  // QCursor(const QBitmap &, const QBitmap &, int, int);
  bind::constructor<QCursor, const QBitmap &, const QBitmap &, int, int>(cursor)
    .apply(bind::default_arguments(-1, -1)).create();
  // QCursor(const QPixmap &, int, int);
  bind::constructor<QCursor, const QPixmap &, int, int>(cursor)
    .apply(bind::default_arguments(-1, -1)).create();
  // QCursor(const QCursor &);
  bind::constructor<QCursor, const QCursor &>(cursor).create();
  // ~QCursor();
  bind::destructor<QCursor>(cursor).create();
  // QCursor & operator=(const QCursor &);
  bind::memop_assign<QCursor, const QCursor &>(cursor);
  // QCursor(QCursor &&);
  bind::constructor<QCursor, QCursor &&>(cursor).create();
  // QCursor & operator=(QCursor &&);
  bind::memop_assign<QCursor, QCursor &&>(cursor);
  // void swap(QCursor &);
  bind::void_member_function<QCursor, QCursor &, &QCursor::swap>(cursor, "swap").create();
  // Qt::CursorShape shape() const;
  bind::member_function<QCursor, Qt::CursorShape, &QCursor::shape>(cursor, "shape").create();
  // void setShape(Qt::CursorShape);
  bind::void_member_function<QCursor, Qt::CursorShape, &QCursor::setShape>(cursor, "setShape").create();
  // const QBitmap * bitmap() const;
  /// TODO: const QBitmap * bitmap() const;
  // const QBitmap * mask() const;
  /// TODO: const QBitmap * mask() const;
  // QPixmap pixmap() const;
  bind::member_function<QCursor, QPixmap, &QCursor::pixmap>(cursor, "pixmap").create();
  // QPoint hotSpot() const;
  bind::member_function<QCursor, QPoint, &QCursor::hotSpot>(cursor, "hotSpot").create();
  // static QPoint pos();
  bind::static_member_function<QCursor, QPoint, &QCursor::pos>(cursor, "pos").create();
  // static QPoint pos(const QScreen *);
  /// TODO: static QPoint pos(const QScreen *);
  // static void setPos(int, int);
  bind::static_void_member_function<QCursor, int, int, &QCursor::setPos>(cursor, "setPos").create();
  // static void setPos(QScreen *, int, int);
  /// TODO: static void setPos(QScreen *, int, int);
  // static void setPos(const QPoint &);
  bind::static_void_member_function<QCursor, const QPoint &, &QCursor::setPos>(cursor, "setPos").create();
  // static void setPos(QScreen *, const QPoint &);
  /// TODO: static void setPos(QScreen *, const QPoint &);
}


void register_cursor_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_cursor_class(ns);

  // void swap(QCursor &, QCursor &);
  bind::void_function<QCursor &, QCursor &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QCursor &);
  bind::op_put_to<QDataStream &, const QCursor &>(ns);
  // QDataStream & operator>>(QDataStream &, QCursor &);
  bind::op_read_from<QDataStream &, QCursor &>(ns);
  // QDebug operator<<(QDebug, const QCursor &);
  /// TODO: QDebug operator<<(QDebug, const QCursor &);
}

