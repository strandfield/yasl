// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/signals.h"

#include "yasl/core/object.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/private/class_p.h> // not that good...

#include <QMetaMethod>


SignalMapper::SignalMapper(QObject *obj, script::Function target_slot)
  : receiver(obj)
  , slot(target_slot)
{

}

SignalMapper * SignalMapper::make(QObject *sender, const script::Function & signal, QObject *receiver, const script::Function & slot)
{
  SignalMapper *result = new SignalMapper{ receiver, slot };

  QObject::connect(receiver, SIGNAL(destroyed()), result, SLOT(deleteLater()));

  auto entry = get_signal_entry(signal);
  QMetaObject::connect(sender, entry.signal_index, result, entry.slot_index);
  return result;
}

SignalTableEntry SignalMapper::get_signal_entry(const script::Function & sig)
{
  script::Class c = sig.memberOf();
  auto table = get_table(c);
  return table->table.value(sig);
}

void SignalMapper::register_signal(script::Class & c, const QMetaObject *meta, const script::Function & sig, const std::string & signature)
{
  const int signal_index = meta->indexOfSignal(QMetaObject::normalizedSignature(signature.data()));
  if (signal_index == -1)
    throw std::runtime_error{ std::string{meta->className()} +std::string{" has no such signal : "} + signature };
  QMetaMethod sender_signal = meta->method(signal_index);

  const QMetaObject *signal_mapper = &SignalMapper::staticMetaObject;
  int slot_index = -1;
  for (int i(0); i < signal_mapper->methodCount(); ++i)
  {
    if (QMetaObject::checkConnectArgs(sender_signal, signal_mapper->method(i)))
      slot_index = i;
  }

  if(slot_index == -1)
    throw std::runtime_error{ std::string{ " SignalMapper does not support the following signature : " } + signature };

  auto table = get_table(c);
  table->table.insert(sig, SignalTableEntry{ signal_index, slot_index });
}

std::shared_ptr<SignalTableClassData> SignalMapper::get_table(script::Class & c)
{
  if (c.data() == nullptr)
  {
    c.impl()->data = std::make_shared<SignalTableClassData>();
  }

  return std::static_pointer_cast<SignalTableClassData>(c.data());
}

void SignalMapper::activate()
{
  invoke(this->slot, this->slot.engine()->expose(this->receiver), {});
}

void SignalMapper::activate(bool arg)
{
  script::Engine *e = this->slot.engine();
  invoke(this->slot, e->expose(this->receiver), { binding::make_value(arg, e) });
}

void SignalMapper::activate(int arg)
{
  script::Engine *e = this->slot.engine();
  invoke(this->slot, e->expose(this->receiver), { binding::make_value(arg, e) });
}

void SignalMapper::activate(int a1, qint64 a2)
{
  script::Engine *e = this->slot.engine();
  invoke(this->slot, e->expose(this->receiver), { binding::make_value(a1, e), binding::make_value(a2, e) });
}

void SignalMapper::activate(const QString & arg)
{
  script::Engine *e = this->slot.engine();
  invoke(this->slot, e->expose(this->receiver), { binding::make_value(arg, e) });
}

void SignalMapper::activate(qint64 arg)
{
  script::Engine *e = this->slot.engine();
  invoke(this->slot, e->expose(this->receiver), { binding::make_value(arg, e) });
}



void SignalMapper::invoke(const script::Function & slot, const script::Value & receiver, std::initializer_list<script::Value> && args)
{
  script::Engine *e = slot.engine();
  std::vector<script::Value> invoke_args{ receiver };
  invoke_args.insert(invoke_args.end(), args.begin(), args.end());
  script::Value result = e->invoke(slot, invoke_args);
  if (!slot.returnType().isReference())
    e->destroy(result);
}

void emit_signal(const script::Value & object, const script::Function & sig, const std::vector<script::Value> & args)
{
  script::Engine *e = sig.engine();

  std::vector<script::Value> invoke_args{ script::Value{} };
  invoke_args.insert(invoke_args.end(), args.begin(), args.end());

  QList<binding::Connection> connections = binding::BindingData::get(binding::value_cast<QObject*>(object)).connections;
  for (const binding::Connection & c : connections)
  {
    if (c.signal != sig)
      continue;

    if (c.receiver.isNull())
      continue;

    invoke_args[0] = e->expose(c.receiver.data());
    script::Value result = e->invoke(c.slot, invoke_args);
    if (!c.slot.returnType().isReference())
      e->destroy(result);
  }
}

void emit_signal(const std::vector<script::Value> & args)
{
  script::Value object = args.front();
  script::Engine *e = object.engine();
  script::Function signal = args.at(1).toFunction();
  std::vector<script::Value> invoke_args{ script::Value{} };
  invoke_args.insert(invoke_args.end(), args.begin() + 2, args.end());

  QList<binding::Connection> connections = binding::BindingData::get(binding::value_cast<QObject*>(object)).connections;
  for (const binding::Connection & c : connections)
  {
    if (c.signal != signal)
      continue;

    if (c.receiver.isNull())
      continue;

    invoke_args[0] = e->expose(c.receiver.data());
    script::Value result = e->invoke(c.slot, invoke_args);
    if (!c.slot.returnType().isReference())
      e->destroy(result);
  }
}

SignalTableEntry::SignalTableEntry()
  : signal_index(-1)
  , slot_index(-1)
{

}

SignalTableEntry::SignalTableEntry(int sig, int slot)
  : signal_index(sig)
  , slot_index(slot)
{

}


bool operator<(const script::Function & lhs, const script::Function & rhs)
{
  return lhs.impl() < rhs.impl();
}


namespace callbacks
{
script::Value emit_callback(script::FunctionCall *c)
{
  emit_signal(std::vector<script::Value>(c->args().begin(), c->args().end()));
  return script::Value::Void;
}

script::Value signal_callback(script::FunctionCall *c)
{
  emit_signal(c->thisObject(), c->callee(), std::vector<script::Value>(c->args().begin() + 1, c->args().end()));
  return script::Value::Void;
}

} // namespace callbacks
