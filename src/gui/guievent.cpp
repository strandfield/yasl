// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/guievent.h"

#include "yasl/binding/namespace.h"
#include "yasl/core/qevent-binder.h"

#include "yasl/core/enums.h"
#include "yasl/core/event.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/keysequence.h"
#include "yasl/gui/region.h"

#include <script/classbuilder.h>

static void register_mouse_event_class(script::Namespace ns)
{
  using namespace script;

  Class mouse_event = ns.Class("MouseEvent").setId(script::Type::QMouseEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QMouseEvent> binder{ mouse_event };

  // QMouseEvent(QEvent::Type, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::MouseEventSource);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::MouseEventSource);
  // ~QMouseEvent();
  binder.add_dtor();
  // QPoint pos() const;
  binder.fun<QPoint, &QMouseEvent::pos>("pos").create();
  // QPoint globalPos() const;
  binder.fun<QPoint, &QMouseEvent::globalPos>("globalPos").create();
  // int x() const;
  binder.fun<int, &QMouseEvent::x>("x").create();
  // int y() const;
  binder.fun<int, &QMouseEvent::y>("y").create();
  // int globalX() const;
  binder.fun<int, &QMouseEvent::globalX>("globalX").create();
  // int globalY() const;
  binder.fun<int, &QMouseEvent::globalY>("globalY").create();
  // const QPointF & localPos() const;
  binder.fun<const QPointF &, &QMouseEvent::localPos>("localPos").create();
  // const QPointF & windowPos() const;
  binder.fun<const QPointF &, &QMouseEvent::windowPos>("windowPos").create();
  // const QPointF & screenPos() const;
  binder.fun<const QPointF &, &QMouseEvent::screenPos>("screenPos").create();
  // Qt::MouseButton button() const;
  binder.fun<Qt::MouseButton, &QMouseEvent::button>("button").create();
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // void setLocalPos(const QPointF &);
  binder.void_fun<const QPointF &, &QMouseEvent::setLocalPos>("setLocalPos").create();
  // Qt::MouseEventSource source() const;
  binder.fun<Qt::MouseEventSource, &QMouseEvent::source>("source").create();
  // Qt::MouseEventFlags flags() const;
  /// TODO: Qt::MouseEventFlags flags() const;
}


static void register_wheel_event_class(script::Namespace ns)
{
  using namespace script;

  Class wheel_event = ns.Class("WheelEvent").setId(script::Type::QWheelEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QWheelEvent> binder{ wheel_event };

  // QWheelEvent(const QPointF &, int, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::Orientation);
  /// TODO: QWheelEvent(const QPointF &, int, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::Orientation);
  // QWheelEvent(const QPointF &, const QPointF &, int, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::Orientation);
  /// TODO: QWheelEvent(const QPointF &, const QPointF &, int, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::Orientation);
  // QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase);
  /// TODO: QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase);
  // QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase, Qt::MouseEventSource);
  /// TODO: QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase, Qt::MouseEventSource);
  // QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase, Qt::MouseEventSource, bool);
  /// TODO: QWheelEvent(const QPointF &, const QPointF &, QPoint, QPoint, int, Qt::Orientation, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::ScrollPhase, Qt::MouseEventSource, bool);
  // ~QWheelEvent();
  binder.add_dtor();
  // QPoint pixelDelta() const;
  binder.fun<QPoint, &QWheelEvent::pixelDelta>("pixelDelta").create();
  // QPoint angleDelta() const;
  binder.fun<QPoint, &QWheelEvent::angleDelta>("angleDelta").create();
  // int delta() const;
  binder.fun<int, &QWheelEvent::delta>("delta").create();
  // Qt::Orientation orientation() const;
  binder.fun<Qt::Orientation, &QWheelEvent::orientation>("orientation").create();
  // QPoint pos() const;
  binder.fun<QPoint, &QWheelEvent::pos>("pos").create();
  // QPoint globalPos() const;
  binder.fun<QPoint, &QWheelEvent::globalPos>("globalPos").create();
  // int x() const;
  binder.fun<int, &QWheelEvent::x>("x").create();
  // int y() const;
  binder.fun<int, &QWheelEvent::y>("y").create();
  // int globalX() const;
  binder.fun<int, &QWheelEvent::globalX>("globalX").create();
  // int globalY() const;
  binder.fun<int, &QWheelEvent::globalY>("globalY").create();
  // const QPointF & posF() const;
  binder.fun<const QPointF &, &QWheelEvent::posF>("posF").create();
  // const QPointF & globalPosF() const;
  binder.fun<const QPointF &, &QWheelEvent::globalPosF>("globalPosF").create();
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // Qt::ScrollPhase phase() const;
  binder.fun<Qt::ScrollPhase, &QWheelEvent::phase>("phase").create();
  // bool inverted() const;
  binder.fun<bool, &QWheelEvent::inverted>("inverted").create();
  // Qt::MouseEventSource source() const;
  binder.fun<Qt::MouseEventSource, &QWheelEvent::source>("source").create();
}


static void register_key_event_class(script::Namespace ns)
{
  using namespace script;

  Class key_event = ns.Class("KeyEvent").setId(script::Type::QKeyEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QKeyEvent> binder{ key_event };

  // QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, const QString &, bool, ushort);
  /// TODO: QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, const QString &, bool, ushort);
  // QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, quint32, quint32, quint32, const QString &, bool, ushort);
  /// TODO: QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, quint32, quint32, quint32, const QString &, bool, ushort);
  // ~QKeyEvent();
  binder.add_dtor();
  // int key() const;
  binder.fun<int, &QKeyEvent::key>("key").create();
  // bool matches(QKeySequence::StandardKey) const;
  binder.fun<bool, QKeySequence::StandardKey, &QKeyEvent::matches>("matches").create();
  // Qt::KeyboardModifiers modifiers() const;
  binder.fun<Qt::KeyboardModifiers, &QKeyEvent::modifiers>("modifiers").create();
  // QString text() const;
  binder.fun<QString, &QKeyEvent::text>("text").create();
  // bool isAutoRepeat() const;
  binder.fun<bool, &QKeyEvent::isAutoRepeat>("isAutoRepeat").create();
  // int count() const;
  binder.fun<int, &QKeyEvent::count>("count").create();
  // quint32 nativeScanCode() const;
  /// TODO: quint32 nativeScanCode() const;
  // quint32 nativeVirtualKey() const;
  /// TODO: quint32 nativeVirtualKey() const;
  // quint32 nativeModifiers() const;
  /// TODO: quint32 nativeModifiers() const;
}


static void register_paint_event_class(script::Namespace ns)
{
  using namespace script;

  Class paint_event = ns.Class("PaintEvent").setId(script::Type::QPaintEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QPaintEvent> binder{ paint_event };

  // QPaintEvent(const QRegion &);
  binder.ctors().ctor<const QRegion &>().create();
  // QPaintEvent(const QRect &);
  binder.ctors().ctor<const QRect &>().create();
  // ~QPaintEvent();
  binder.add_dtor();
  // const QRect & rect() const;
  binder.fun<const QRect &, &QPaintEvent::rect>("rect").create();
  // const QRegion & region() const;
  binder.fun<const QRegion &, &QPaintEvent::region>("region").create();
}


static void register_move_event_class(script::Namespace ns)
{
  using namespace script;

  Class move_event = ns.Class("MoveEvent").setId(script::Type::QMoveEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QMoveEvent> binder{ move_event };

  // QMoveEvent(const QPoint &, const QPoint &);
  binder.ctors().ctor<const QPoint &, const QPoint &>().create();
  // ~QMoveEvent();
  binder.add_dtor();
  // const QPoint & pos() const;
  binder.fun<const QPoint &, &QMoveEvent::pos>("pos").create();
  // const QPoint & oldPos() const;
  binder.fun<const QPoint &, &QMoveEvent::oldPos>("oldPos").create();
}


static void register_resize_event_class(script::Namespace ns)
{
  using namespace script;

  Class resize_event = ns.Class("ResizeEvent").setId(script::Type::QResizeEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QResizeEvent> binder{ resize_event };

  // QResizeEvent(const QSize &, const QSize &);
  binder.ctors().ctor<const QSize &, const QSize &>().create();
  // ~QResizeEvent();
  binder.add_dtor();
  // const QSize & size() const;
  binder.fun<const QSize &, &QResizeEvent::size>("size").create();
  // const QSize & oldSize() const;
  binder.fun<const QSize &, &QResizeEvent::oldSize>("oldSize").create();
}


static void register_close_event_class(script::Namespace ns)
{
  using namespace script;

  Class close_event = ns.Class("CloseEvent").setId(script::Type::QCloseEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QCloseEvent> binder{ close_event };

  // QCloseEvent();
  binder.ctors().default_ctor().create();
  // ~QCloseEvent();
  binder.add_dtor();
}


static void register_show_event_class(script::Namespace ns)
{
  using namespace script;

  Class show_event = ns.Class("ShowEvent").setId(script::Type::QShowEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QShowEvent> binder{ show_event };

  // QShowEvent();
  binder.ctors().default_ctor().create();
  // ~QShowEvent();
  binder.add_dtor();
}


static void register_hide_event_class(script::Namespace ns)
{
  using namespace script;

  Class hide_event = ns.Class("HideEvent").setId(script::Type::QHideEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QHideEvent> binder{ hide_event };

  // QHideEvent();
  binder.ctors().default_ctor().create();
  // ~QHideEvent();
  binder.add_dtor();
}


void register_guievent_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_mouse_event_class(ns);
  register_wheel_event_class(ns);
  register_key_event_class(ns);
  register_paint_event_class(ns);
  register_move_event_class(ns);
  register_resize_event_class(ns);
  register_close_event_class(ns);
  register_show_event_class(ns);
  register_hide_event_class(ns);
  binding::Namespace binder{ ns };

  // bool operator==(QKeyEvent *, QKeySequence::StandardKey);
  /// TODO: bool operator==(QKeyEvent *, QKeySequence::StandardKey);
  // bool operator==(QKeySequence::StandardKey, QKeyEvent *);
  /// TODO: bool operator==(QKeySequence::StandardKey, QKeyEvent *);
}

