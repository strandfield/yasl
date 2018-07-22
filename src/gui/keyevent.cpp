// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/keyevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/enums.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

namespace keyevent
{

static script::Value ctor(script::FunctionCall *c)
{
  using namespace binding;

  auto self = c->thisObject();
  self.impl()->data.ptr = new QKeyEvent(
    value_cast<QEvent::Type>(c->arg(0)), 
    value_cast<int>(c->arg(1)),
    value_cast<Qt::KeyboardModifiers>(c->arg(2)), 
    value_cast<const QString &>(c->arg(3)),
    value_cast<bool>(c->arg(4)), 
    value_cast<int>(c->arg(4)));
  return self;
}

} // keyevent

} // namespace callbacks


void register_qkeyevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class keyevent = root.Class("KeyEvent").setId(Type::QKeyEvent).setBase(event).setFinal().get();
  
  binding::Class<QKeyEvent> q{ keyevent };

  // QKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString &text = QString(), bool autorep = false, ushort count = 1)
  keyevent.Constructor(callbacks::keyevent::ctor)
    .params(binding::make_type<QEvent::Type>(), Type::Int, binding::make_type<Qt::KeyboardModifiers>())
    .params(binding::make_type<const QString &>(), Type::Boolean, Type::Int)
    .create();
  // QKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, quint32 nativeScanCode, quint32 nativeVirtualKey, quint32 nativeModifiers, const QString &text = QString(), bool autorep = false, ushort count = 1)
  /// IGNORE
  // int count() const
  q.add_fun<int, &QKeyEvent::count>("count");
  // bool isAutoRepeat() const
  q.add_fun<bool, &QKeyEvent::isAutoRepeat>("isAutoRepeat");
  // int key() const
  q.add_fun<int, &QKeyEvent::key>("key");
  // bool matches(QKeySequence::StandardKey key) const
  /// TODO !!
  // Qt::KeyboardModifiers modifiers() const
  q.add_fun<Qt::KeyboardModifiers, &QKeyEvent::modifiers>("modifiers");
  // quint32 nativeModifiers() const
  /// IGNORE
  // quint32 nativeScanCode() const
  /// IGNORE
  // quint32 nativeVirtualKey() const
  /// IGNORE
  // QString text() const
  q.add_fun<QString, &QKeyEvent::text>("text");
}
