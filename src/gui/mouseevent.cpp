// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/mouseevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

namespace mouseevent
{

} // namespace mouseevent

} // namespace callbacks


void register_qmouseevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class mouseevent = root.Class("MouseEvent").setId(Type::QMouseEvent).setBase(event).setFinal().get();
  
  binding::Class<QMouseEvent> qmouseevent{ mouseevent };
  // QMouseEvent(QEvent::Type type, const QPointF &localPos, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
  /// TODO !!
  // QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &screenPos, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
  /// TODO !!
  // QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
  /// TODO !!
  // QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::MouseEventSource source)
  /// TODO !!
  // ~QMouseEvent();
  mouseevent.newDestructor(event.destructor().native_callback());
  // Qt::MouseButton button() const
  /// TODO !!
  // Qt::MouseButtons buttons() const
  /// TODO !!
  // Qt::MouseEventFlags flags() const
  /// TODO !!
  // QPoint globalPos() const
  qmouseevent.add_fun<QPoint, &QMouseEvent::globalPos>("globalPos");
  // int globalX() const
  qmouseevent.add_fun<int, &QMouseEvent::globalX>("globalX");
  // int globalY() const
  qmouseevent.add_fun<int, &QMouseEvent::globalY>("globalY");
  // const QPointF & localPos() const
  /// TODO !!
  // QPoint pos() const
  qmouseevent.add_fun<QPoint, &QMouseEvent::pos>("pos");
  // const QPointF & screenPos() const
  /// TODO !!
  // Qt::MouseEventSource source() const
  /// TODO !!
  // const QPointF & windowPos() const
  /// TODO !!
  // int x() const
  qmouseevent.add_fun<int, &QMouseEvent::x>("x");
  // int y() const
  qmouseevent.add_fun<int, &QMouseEvent::y>("x");
}
