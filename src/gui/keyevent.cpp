// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/keyevent.h"

#include "yasl/core/qevent-binder.h"
#include "yasl/core/enums.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qkeyevent(script::Namespace root)
{
  using namespace script;

  Class keyevent = root.Class("KeyEvent").setId(Type::QKeyEvent).setBase(Type::QEvent).setFinal().get();
  
  binding::Event<QKeyEvent> q{ keyevent };

  // QKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString &text = QString(), bool autorep = false, ushort count = 1)
  q.ctors().add<QEvent::Type, int, Qt::KeyboardModifiers, const QString &, bool, int>();
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
