// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/wheelevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

namespace wheelevent
{

} // namespace wheelevent

} // namespace callbacks


void register_qwheelevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(Type::QEvent);
  Class wheelevent = root.Class("WheelEvent").setId(Type::QWheelEvent).setBase(event).setFinal().get();
  
  binding::Class<QWheelEvent> qwheelevent{ wheelevent };
  // QWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
  /// TODO !!
  // QWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase)
  /// TODO !!
  // QWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase, Qt::MouseEventSource source)
  /// TODO !!
  // QWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase, Qt::MouseEventSource source, bool inverted)
  /// TODO !!
  // ~QWheelEvent();
  wheelevent.newDestructor(event.destructor().native_callback());
  // QPoint angleDelta() const
  qwheelevent.add_fun<QPoint, &QWheelEvent::angleDelta>("angleDelta");
  // Qt::MouseButtons buttons() const
  /// TODO !!
  // QPoint globalPos() const
  qwheelevent.add_fun<QPoint, &QWheelEvent::globalPos>("globalPos");
  // const QPointF & globalPosF() const
  /// TODO !!
  // int globalX() const
  qwheelevent.add_fun<int, &QWheelEvent::globalX>("globalX");
  // int globalY() const
  qwheelevent.add_fun<int, &QWheelEvent::globalY>("globalY");
  // bool inverted() const
  qwheelevent.add_fun<bool, &QWheelEvent::inverted>("inverted");
  // Qt::ScrollPhase phase() const
  /// TODO !!
  // QPoint pixelDelta() const
  qwheelevent.add_fun<QPoint, &QWheelEvent::pixelDelta>("pixelDelta");
  // QPoint pos() const
  qwheelevent.add_fun<QPoint, &QWheelEvent::pos>("pos");
  // const QPointF & posF() const
  /// TODO !!
  // Qt::MouseEventSource source() const
  /// TODO !!
  // int x() const
  qwheelevent.add_fun<int, &QWheelEvent::x>("x");
  // int y() const
  qwheelevent.add_fun<int, &QWheelEvent::y>("x");
}
