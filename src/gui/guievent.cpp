// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/guievent.h"

#include "yasl/common/binding/namespace.h"
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

  Class mouse_event = ns.newClass("MouseEvent").setId(script::Type::QMouseEvent)
    .setBase(script::Type::QEvent).get();


  // QMouseEvent(QEvent::Type, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers);
  // QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::MouseEventSource);
  /// TODO: QMouseEvent(QEvent::Type, const QPointF &, const QPointF &, const QPointF &, Qt::MouseButton, Qt::MouseButtons, Qt::KeyboardModifiers, Qt::MouseEventSource);
  // ~QMouseEvent();
  bind::destructor<QMouseEvent>(mouse_event).create();
  // QPoint pos() const;
  bind::member_function<QMouseEvent, QPoint, &QMouseEvent::pos>(mouse_event, "pos").create();
  // QPoint globalPos() const;
  bind::member_function<QMouseEvent, QPoint, &QMouseEvent::globalPos>(mouse_event, "globalPos").create();
  // int x() const;
  bind::member_function<QMouseEvent, int, &QMouseEvent::x>(mouse_event, "x").create();
  // int y() const;
  bind::member_function<QMouseEvent, int, &QMouseEvent::y>(mouse_event, "y").create();
  // int globalX() const;
  bind::member_function<QMouseEvent, int, &QMouseEvent::globalX>(mouse_event, "globalX").create();
  // int globalY() const;
  bind::member_function<QMouseEvent, int, &QMouseEvent::globalY>(mouse_event, "globalY").create();
  // const QPointF & localPos() const;
  bind::member_function<QMouseEvent, const QPointF &, &QMouseEvent::localPos>(mouse_event, "localPos").create();
  // const QPointF & windowPos() const;
  bind::member_function<QMouseEvent, const QPointF &, &QMouseEvent::windowPos>(mouse_event, "windowPos").create();
  // const QPointF & screenPos() const;
  bind::member_function<QMouseEvent, const QPointF &, &QMouseEvent::screenPos>(mouse_event, "screenPos").create();
  // Qt::MouseButton button() const;
  bind::member_function<QMouseEvent, Qt::MouseButton, &QMouseEvent::button>(mouse_event, "button").create();
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // void setLocalPos(const QPointF &);
  bind::void_member_function<QMouseEvent, const QPointF &, &QMouseEvent::setLocalPos>(mouse_event, "setLocalPos").create();
  // Qt::MouseEventSource source() const;
  bind::member_function<QMouseEvent, Qt::MouseEventSource, &QMouseEvent::source>(mouse_event, "source").create();
  // Qt::MouseEventFlags flags() const;
  /// TODO: Qt::MouseEventFlags flags() const;
}


static void register_wheel_event_class(script::Namespace ns)
{
  using namespace script;

  Class wheel_event = ns.newClass("WheelEvent").setId(script::Type::QWheelEvent)
    .setBase(script::Type::QEvent).get();


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
  bind::destructor<QWheelEvent>(wheel_event).create();
  // QPoint pixelDelta() const;
  bind::member_function<QWheelEvent, QPoint, &QWheelEvent::pixelDelta>(wheel_event, "pixelDelta").create();
  // QPoint angleDelta() const;
  bind::member_function<QWheelEvent, QPoint, &QWheelEvent::angleDelta>(wheel_event, "angleDelta").create();
  // int delta() const;
  bind::member_function<QWheelEvent, int, &QWheelEvent::delta>(wheel_event, "delta").create();
  // Qt::Orientation orientation() const;
  bind::member_function<QWheelEvent, Qt::Orientation, &QWheelEvent::orientation>(wheel_event, "orientation").create();
  // QPoint pos() const;
  bind::member_function<QWheelEvent, QPoint, &QWheelEvent::pos>(wheel_event, "pos").create();
  // QPoint globalPos() const;
  bind::member_function<QWheelEvent, QPoint, &QWheelEvent::globalPos>(wheel_event, "globalPos").create();
  // int x() const;
  bind::member_function<QWheelEvent, int, &QWheelEvent::x>(wheel_event, "x").create();
  // int y() const;
  bind::member_function<QWheelEvent, int, &QWheelEvent::y>(wheel_event, "y").create();
  // int globalX() const;
  bind::member_function<QWheelEvent, int, &QWheelEvent::globalX>(wheel_event, "globalX").create();
  // int globalY() const;
  bind::member_function<QWheelEvent, int, &QWheelEvent::globalY>(wheel_event, "globalY").create();
  // const QPointF & posF() const;
  bind::member_function<QWheelEvent, const QPointF &, &QWheelEvent::posF>(wheel_event, "posF").create();
  // const QPointF & globalPosF() const;
  bind::member_function<QWheelEvent, const QPointF &, &QWheelEvent::globalPosF>(wheel_event, "globalPosF").create();
  // Qt::MouseButtons buttons() const;
  /// TODO: Qt::MouseButtons buttons() const;
  // Qt::ScrollPhase phase() const;
  bind::member_function<QWheelEvent, Qt::ScrollPhase, &QWheelEvent::phase>(wheel_event, "phase").create();
  // bool inverted() const;
  bind::member_function<QWheelEvent, bool, &QWheelEvent::inverted>(wheel_event, "inverted").create();
  // Qt::MouseEventSource source() const;
  bind::member_function<QWheelEvent, Qt::MouseEventSource, &QWheelEvent::source>(wheel_event, "source").create();
}


static void register_key_event_class(script::Namespace ns)
{
  using namespace script;

  Class key_event = ns.newClass("KeyEvent").setId(script::Type::QKeyEvent)
    .setBase(script::Type::QEvent).get();


  // QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, const QString &, bool, ushort);
  /// TODO: QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, const QString &, bool, ushort);
  // QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, quint32, quint32, quint32, const QString &, bool, ushort);
  /// TODO: QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, quint32, quint32, quint32, const QString &, bool, ushort);
  // ~QKeyEvent();
  bind::destructor<QKeyEvent>(key_event).create();
  // int key() const;
  bind::member_function<QKeyEvent, int, &QKeyEvent::key>(key_event, "key").create();
  // bool matches(QKeySequence::StandardKey) const;
  bind::member_function<QKeyEvent, bool, QKeySequence::StandardKey, &QKeyEvent::matches>(key_event, "matches").create();
  // Qt::KeyboardModifiers modifiers() const;
  bind::member_function<QKeyEvent, Qt::KeyboardModifiers, &QKeyEvent::modifiers>(key_event, "modifiers").create();
  // QString text() const;
  bind::member_function<QKeyEvent, QString, &QKeyEvent::text>(key_event, "text").create();
  // bool isAutoRepeat() const;
  bind::member_function<QKeyEvent, bool, &QKeyEvent::isAutoRepeat>(key_event, "isAutoRepeat").create();
  // int count() const;
  bind::member_function<QKeyEvent, int, &QKeyEvent::count>(key_event, "count").create();
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

  Class paint_event = ns.newClass("PaintEvent").setId(script::Type::QPaintEvent)
    .setBase(script::Type::QEvent).get();


  // QPaintEvent(const QRegion &);
  bind::constructor<QPaintEvent, const QRegion &>(paint_event).create();
  // QPaintEvent(const QRect &);
  bind::constructor<QPaintEvent, const QRect &>(paint_event).create();
  // ~QPaintEvent();
  bind::destructor<QPaintEvent>(paint_event).create();
  // const QRect & rect() const;
  bind::member_function<QPaintEvent, const QRect &, &QPaintEvent::rect>(paint_event, "rect").create();
  // const QRegion & region() const;
  bind::member_function<QPaintEvent, const QRegion &, &QPaintEvent::region>(paint_event, "region").create();
}


static void register_move_event_class(script::Namespace ns)
{
  using namespace script;

  Class move_event = ns.newClass("MoveEvent").setId(script::Type::QMoveEvent)
    .setBase(script::Type::QEvent).get();


  // QMoveEvent(const QPoint &, const QPoint &);
  bind::constructor<QMoveEvent, const QPoint &, const QPoint &>(move_event).create();
  // ~QMoveEvent();
  bind::destructor<QMoveEvent>(move_event).create();
  // const QPoint & pos() const;
  bind::member_function<QMoveEvent, const QPoint &, &QMoveEvent::pos>(move_event, "pos").create();
  // const QPoint & oldPos() const;
  bind::member_function<QMoveEvent, const QPoint &, &QMoveEvent::oldPos>(move_event, "oldPos").create();
}


static void register_resize_event_class(script::Namespace ns)
{
  using namespace script;

  Class resize_event = ns.newClass("ResizeEvent").setId(script::Type::QResizeEvent)
    .setBase(script::Type::QEvent).get();


  // QResizeEvent(const QSize &, const QSize &);
  bind::constructor<QResizeEvent, const QSize &, const QSize &>(resize_event).create();
  // ~QResizeEvent();
  bind::destructor<QResizeEvent>(resize_event).create();
  // const QSize & size() const;
  bind::member_function<QResizeEvent, const QSize &, &QResizeEvent::size>(resize_event, "size").create();
  // const QSize & oldSize() const;
  bind::member_function<QResizeEvent, const QSize &, &QResizeEvent::oldSize>(resize_event, "oldSize").create();
}


static void register_close_event_class(script::Namespace ns)
{
  using namespace script;

  Class close_event = ns.newClass("CloseEvent").setId(script::Type::QCloseEvent)
    .setBase(script::Type::QEvent).get();


  // QCloseEvent();
  bind::default_constructor<QCloseEvent>(close_event).create();
  // ~QCloseEvent();
  bind::destructor<QCloseEvent>(close_event).create();
}


static void register_show_event_class(script::Namespace ns)
{
  using namespace script;

  Class show_event = ns.newClass("ShowEvent").setId(script::Type::QShowEvent)
    .setBase(script::Type::QEvent).get();


  // QShowEvent();
  bind::default_constructor<QShowEvent>(show_event).create();
  // ~QShowEvent();
  bind::destructor<QShowEvent>(show_event).create();
}


static void register_hide_event_class(script::Namespace ns)
{
  using namespace script;

  Class hide_event = ns.newClass("HideEvent").setId(script::Type::QHideEvent)
    .setBase(script::Type::QEvent).get();


  // QHideEvent();
  bind::default_constructor<QHideEvent>(hide_event).create();
  // ~QHideEvent();
  bind::destructor<QHideEvent>(hide_event).create();
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

  // bool operator==(QKeyEvent *, QKeySequence::StandardKey);
  /// TODO: bool operator==(QKeyEvent *, QKeySequence::StandardKey);
  // bool operator==(QKeySequence::StandardKey, QKeyEvent *);
  /// TODO: bool operator==(QKeySequence::StandardKey, QKeyEvent *);
}

