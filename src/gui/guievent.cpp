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
  binder.add_fun<QPoint, &QMouseEvent::pos>("pos");
  // QPoint globalPos() const;
  binder.add_fun<QPoint, &QMouseEvent::globalPos>("globalPos");
  // int x() const;
  binder.add_fun<int, &QMouseEvent::x>("x");
  // int y() const;
  binder.add_fun<int, &QMouseEvent::y>("y");
  // int globalX() const;
  binder.add_fun<int, &QMouseEvent::globalX>("globalX");
  // int globalY() const;
  binder.add_fun<int, &QMouseEvent::globalY>("globalY");
  // const QPointF & localPos() const;
  binder.add_fun<const QPointF &, &QMouseEvent::localPos>("localPos");
  // const QPointF & windowPos() const;
  binder.add_fun<const QPointF &, &QMouseEvent::windowPos>("windowPos");
  // const QPointF & screenPos() const;
  binder.add_fun<const QPointF &, &QMouseEvent::screenPos>("screenPos");
  // Qt::MouseButton button() const;
  binder.add_fun<Qt::MouseButton, &QMouseEvent::button>("button");
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // void setLocalPos(const QPointF &);
  binder.add_void_fun<const QPointF &, &QMouseEvent::setLocalPos>("setLocalPos");
  // Qt::MouseEventSource source() const;
  binder.add_fun<Qt::MouseEventSource, &QMouseEvent::source>("source");
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
  binder.add_fun<QPoint, &QWheelEvent::pixelDelta>("pixelDelta");
  // QPoint angleDelta() const;
  binder.add_fun<QPoint, &QWheelEvent::angleDelta>("angleDelta");
  // int delta() const;
  binder.add_fun<int, &QWheelEvent::delta>("delta");
  // Qt::Orientation orientation() const;
  binder.add_fun<Qt::Orientation, &QWheelEvent::orientation>("orientation");
  // QPoint pos() const;
  binder.add_fun<QPoint, &QWheelEvent::pos>("pos");
  // QPoint globalPos() const;
  binder.add_fun<QPoint, &QWheelEvent::globalPos>("globalPos");
  // int x() const;
  binder.add_fun<int, &QWheelEvent::x>("x");
  // int y() const;
  binder.add_fun<int, &QWheelEvent::y>("y");
  // int globalX() const;
  binder.add_fun<int, &QWheelEvent::globalX>("globalX");
  // int globalY() const;
  binder.add_fun<int, &QWheelEvent::globalY>("globalY");
  // const QPointF & posF() const;
  binder.add_fun<const QPointF &, &QWheelEvent::posF>("posF");
  // const QPointF & globalPosF() const;
  binder.add_fun<const QPointF &, &QWheelEvent::globalPosF>("globalPosF");
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // Qt::ScrollPhase phase() const;
  binder.add_fun<Qt::ScrollPhase, &QWheelEvent::phase>("phase");
  // bool inverted() const;
  binder.add_fun<bool, &QWheelEvent::inverted>("inverted");
  // Qt::MouseEventSource source() const;
  binder.add_fun<Qt::MouseEventSource, &QWheelEvent::source>("source");
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
  binder.add_fun<int, &QKeyEvent::key>("key");
  // bool matches(QKeySequence::StandardKey) const;
  binder.add_fun<bool, QKeySequence::StandardKey, &QKeyEvent::matches>("matches");
  // Qt::KeyboardModifiers modifiers() const;
  binder.add_fun<Qt::KeyboardModifiers, &QKeyEvent::modifiers>("modifiers");
  // QString text() const;
  binder.add_fun<QString, &QKeyEvent::text>("text");
  // bool isAutoRepeat() const;
  binder.add_fun<bool, &QKeyEvent::isAutoRepeat>("isAutoRepeat");
  // int count() const;
  binder.add_fun<int, &QKeyEvent::count>("count");
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
  binder.ctors().add<const QRegion &>();
  // QPaintEvent(const QRect &);
  binder.ctors().add<const QRect &>();
  // ~QPaintEvent();
  binder.add_dtor();
  // const QRect & rect() const;
  binder.add_fun<const QRect &, &QPaintEvent::rect>("rect");
  // const QRegion & region() const;
  binder.add_fun<const QRegion &, &QPaintEvent::region>("region");
}


static void register_move_event_class(script::Namespace ns)
{
  using namespace script;

  Class move_event = ns.Class("MoveEvent").setId(script::Type::QMoveEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QMoveEvent> binder{ move_event };

  // QMoveEvent(const QPoint &, const QPoint &);
  binder.ctors().add<const QPoint &, const QPoint &>();
  // ~QMoveEvent();
  binder.add_dtor();
  // const QPoint & pos() const;
  binder.add_fun<const QPoint &, &QMoveEvent::pos>("pos");
  // const QPoint & oldPos() const;
  binder.add_fun<const QPoint &, &QMoveEvent::oldPos>("oldPos");
}


static void register_resize_event_class(script::Namespace ns)
{
  using namespace script;

  Class resize_event = ns.Class("ResizeEvent").setId(script::Type::QResizeEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QResizeEvent> binder{ resize_event };

  // QResizeEvent(const QSize &, const QSize &);
  binder.ctors().add<const QSize &, const QSize &>();
  // ~QResizeEvent();
  binder.add_dtor();
  // const QSize & size() const;
  binder.add_fun<const QSize &, &QResizeEvent::size>("size");
  // const QSize & oldSize() const;
  binder.add_fun<const QSize &, &QResizeEvent::oldSize>("oldSize");
}


static void register_close_event_class(script::Namespace ns)
{
  using namespace script;

  Class close_event = ns.Class("CloseEvent").setId(script::Type::QCloseEvent)
    .setBase(script::Type::QEvent).get();

  binding::Event<QCloseEvent> binder{ close_event };

  // QCloseEvent();
  binder.ctors().add_default();
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
  binder.ctors().add_default();
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
  binder.ctors().add_default();
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

