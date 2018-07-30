// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/cursor.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"

#include "yasl/gui/bitmap.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/screen.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_cursor_class(script::Namespace ns)
{
  using namespace script;

  Class cursor = ns.Class("Cursor").setId(script::Type::QCursor).get();

  binding::Class<QCursor> binder{ cursor };

  // ~QCursor();
  binder.add_dtor();
  // QCursor();
  binder.ctors().add_default();
  // QCursor(Qt::CursorShape);
  binder.ctors().add<Qt::CursorShape>();
  // QCursor(const QBitmap &, const QBitmap &, int, int);
  binder.ctors().add<const QBitmap &, const QBitmap &, int, int>();
  // QCursor(const QPixmap &, int, int);
  binder.ctors().add<const QPixmap &, int, int>();
  // QCursor(const QCursor &);
  binder.ctors().add<const QCursor &>();
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
  binder.add_fun<const QBitmap *, &QCursor::bitmap>("bitmap");
  // const QBitmap * mask() const;
  binder.add_fun<const QBitmap *, &QCursor::mask>("mask");
  // QPixmap pixmap() const;
  binder.add_fun<QPixmap, &QCursor::pixmap>("pixmap");
  // QPoint hotSpot() const;
  binder.add_fun<QPoint, &QCursor::hotSpot>("hotSpot");
  // static QPoint pos();
  binder.add_static<QPoint, &QCursor::pos>("pos");
  // static QPoint pos(const QScreen *);
  binder.add_static<QPoint, const QScreen *, &QCursor::pos>("pos");
  // static void setPos(int, int);
  binder.add_static_void_fun<int, int, &QCursor::setPos>("setPos");
  // static void setPos(QScreen *, int, int);
  binder.add_static_void_fun<QScreen *, int, int, &QCursor::setPos>("setPos");
  // static void setPos(const QPoint &);
  binder.add_static_void_fun<const QPoint &, &QCursor::setPos>("setPos");
  // static void setPos(QScreen *, const QPoint &);
  binder.add_static_void_fun<QScreen *, const QPoint &, &QCursor::setPos>("setPos");
}

void register_cursor_file(script::Namespace root)
{
  using namespace script;

  register_cursor_class(root);
  binding::Namespace binder{ root };

  // void swap(QCursor &, QCursor &);
  binder.add_void_fun<QCursor &, QCursor &, &swap>("swap");
  // bool operator==(const QCursor &, const QCursor &);
  binder.operators().eq<const QCursor &, const QCursor &>();
  // bool operator!=(const QCursor &, const QCursor &);
  binder.operators().neq<const QCursor &, const QCursor &>();
  // QDataStream & operator<<(QDataStream &, const QCursor &);
  binder.operators().put_to<QDataStream &, const QCursor &>();
  // QDataStream & operator>>(QDataStream &, QCursor &);
  binder.operators().read_from<QDataStream &, QCursor &>();
  // QDebug operator<<(QDebug, const QCursor &);
  binder.operators().left_shift<QDebug, QDebug, const QCursor &>();
}

