// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/cursor.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/cursor.h"

#include <script/classbuilder.h>

static void register_cursor_class(script::Namespace ns)
{
  using namespace script;

  Class cursor = ns.Class("Cursor").setId(script::Type::QCursor).get();

  binding::Class<QCursor> binder{ cursor };

  // QCursor();
  binder.ctors().add_default();
  // QCursor(Qt::CursorShape);
  binder.ctors().add<Qt::CursorShape>();
  // QCursor(const QBitmap &, const QBitmap &, int, int);
  /// TODO: QCursor(const QBitmap &, const QBitmap &, int, int);
  // QCursor(const QPixmap &, int, int);
  /// TODO: QCursor(const QPixmap &, int, int);
  // QCursor(const QCursor &);
  binder.ctors().add<const QCursor &>();
  // ~QCursor();
  binder.add_dtor();
  // QCursor & operator=(const QCursor &);
  binder.operators().assign<const QCursor &>();
  // QCursor(QCursor &&);
  binder.ctors().add<QCursor &&>();
  // QCursor & operator=(QCursor &&);
  binder.operators().assign<QCursor &&>();
  // void swap(QCursor &);
  binder.add_void_fun<QCursor &, &QCursor::swap>("swap");
  // Qt::CursorShape shape() const;
  binder.add_fun<Qt::CursorShape, &QCursor::shape>("shape");
  // void setShape(Qt::CursorShape);
  binder.add_void_fun<Qt::CursorShape, &QCursor::setShape>("setShape");
  // const QBitmap * bitmap() const;
  /// TODO: const QBitmap * bitmap() const;
  // const QBitmap * mask() const;
  /// TODO: const QBitmap * mask() const;
  // QPixmap pixmap() const;
  /// TODO: QPixmap pixmap() const;
  // QPoint hotSpot() const;
  binder.add_fun<QPoint, &QCursor::hotSpot>("hotSpot");
  // static QPoint pos();
  binder.add_static<QPoint, &QCursor::pos>("pos");
  // static QPoint pos(const QScreen *);
  /// TODO: static QPoint pos(const QScreen *);
  // static void setPos(int, int);
  binder.add_static_void_fun<int, int, &QCursor::setPos>("setPos");
  // static void setPos(QScreen *, int, int);
  /// TODO: static void setPos(QScreen *, int, int);
  // static void setPos(const QPoint &);
  binder.add_static_void_fun<const QPoint &, &QCursor::setPos>("setPos");
  // static void setPos(QScreen *, const QPoint &);
  /// TODO: static void setPos(QScreen *, const QPoint &);
}


void register_cursor_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_cursor_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QCursor &, QCursor &);
  binder.add_void_fun<QCursor &, QCursor &, &swap>("swap");
  // bool operator==(const QCursor &, const QCursor &);
  binder.operators().eq<const QCursor &, const QCursor &>();
  // bool operator!=(const QCursor &, const QCursor &);
  binder.operators().neq<const QCursor &, const QCursor &>();
  // QDataStream & operator<<(QDataStream &, const QCursor &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QCursor &);
  // QDataStream & operator>>(QDataStream &, QCursor &);
  /// TODO: QDataStream & operator>>(QDataStream &, QCursor &);
  // QDebug operator<<(QDebug, const QCursor &);
  /// TODO: QDebug operator<<(QDebug, const QCursor &);
}

