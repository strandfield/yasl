// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/signals.h"

#include "yasl/binding/values.h"

#include <script/classbuilder.h>
#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/function.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/functiontype.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>
#include <script/userdata.h>
#include <script/value.h>
#include <script/private/value_p.h>
#include <script/private/class_p.h> // not that good...

#include <QMap>
#include <QMetaMethod>

struct SignalTableClassData;
struct SignalTableEntry;

struct SignalMapper : public QObject
{
  Q_OBJECT
private:
  QObject * receiver;
  script::Function slot;

public:
  static SignalMapper * make(QObject *sender, const script::Function & signal, QObject *receiver, const script::Function & slot);

protected:
  SignalMapper(QObject *obj, script::Function target_slot);

protected Q_SLOTS:
  void activate();
  void activate(bool);
  void activate(int);
  void activate(int, qint64);
  void activate(const QString &);
  void activate(qint64);

private:
  void invoke(const script::Function & slot, const script::Value & receiver, std::initializer_list<script::Value> && args);
};

struct SignalTableEntry
{
  SignalTableEntry();
  SignalTableEntry(int sig, int slot);

  int signal_index; // signal index of the sender's Class
  int slot_index; // slot index of SignalMapper
};

bool operator<(const script::Function & lhs, const script::Function & rhs)
{
  return lhs.impl() < rhs.impl();
}

typedef QMap<script::Function, SignalTableEntry> SignalTable; // stored in the sender's class

struct SignalTableClassData : public script::UserData
{
  SignalTableClassData() = default;
  ~SignalTableClassData() = default;

  SignalTable table;
};



SignalMapper::SignalMapper(QObject *obj, script::Function target_slot)
  : receiver(obj)
  , slot(target_slot)
{

}

static std::shared_ptr<SignalTableClassData> get_table(script::Class & c)
{
  if (c.data() == nullptr)
  {
    c.impl()->data = std::make_shared<SignalTableClassData>();
  }

  return std::static_pointer_cast<SignalTableClassData>(c.data());
}

static SignalTableEntry get_signal_entry(const script::Function & sig)
{
  script::Class c = sig.memberOf();
  auto table = get_table(c);
  return table->table.value(sig);
}

SignalMapper * SignalMapper::make(QObject *sender, const script::Function & signal, QObject *receiver, const script::Function & slot)
{
  SignalMapper *result = new SignalMapper{ receiver, slot };

  QObject::connect(receiver, SIGNAL(destroyed()), result, SLOT(deleteLater()));

  auto entry = get_signal_entry(signal);
  QMetaObject::connect(sender, entry.signal_index, result, entry.slot_index);
  return result;
}


void register_signal(script::Class & c, const QMetaObject *meta, const script::Function & sig, const std::string & signature)
{
  const int signal_index = meta->indexOfSignal(QMetaObject::normalizedSignature(signature.data()));
  if (signal_index == -1)
    throw std::runtime_error{ std::string{ meta->className() } +std::string{ " has no such signal : " } +signature };
  QMetaMethod sender_signal = meta->method(signal_index);

  const QMetaObject *signal_mapper = &SignalMapper::staticMetaObject;
  int slot_index = -1;
  for (int i(0); i < signal_mapper->methodCount(); ++i)
  {
    if (QMetaObject::checkConnectArgs(sender_signal, signal_mapper->method(i)))
      slot_index = i;
  }

  if (slot_index == -1)
    throw std::runtime_error{ std::string{ " SignalMapper does not support the following signature : " } +signature };

  auto table = get_table(c);
  table->table.insert(sig, SignalTableEntry{ signal_index, slot_index });
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

static void emit_signal(const script::Value & object, const script::Function & sig, const std::vector<script::Value> & args)
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

// first arg is the object, second is the signal
// the rest are the signal's args.
static void emit_signal(const std::vector<script::Value> & args)
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


namespace callbacks
{

script::Value connect(script::FunctionCall *c)
{
  QObject *sender = binding::value_cast<QObject*>(c->arg(0));

  script::Function signal = c->arg(1).toFunction();
  QObject *receiver = binding::value_cast<QObject*>(c->arg(2));
  script::Function slot = c->arg(3).toFunction();

  if (signal.isNative())
  {
    SignalMapper::make(sender, signal, receiver, slot);
  }
  else
  {
    auto data = binding::BindingData::get(sender);
    data.connections.append(binding::Connection{ signal, QPointer<QObject>{receiver}, slot });
    binding::BindingData::set(sender, data);
  }

  return script::Value::Void;
}

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



void connect_template_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & connect_template, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() != 0)
    return deduc.fail();
  if (itypes.size() != 4)
    return deduc.fail();
  
  if (!itypes.at(0).isObjectType() || !itypes.at(2).isObjectType())
    return deduc.fail();
  if (!itypes.at(1).isFunctionType() || !itypes.at(3).isFunctionType())
    return deduc.fail();

  Engine *e = connect_template.engine();
  Class sender_type = e->getClass(itypes.at(0));
  Class receiver_type = e->getClass(itypes.at(2));
  FunctionType signal_type = e->getFunctionType(itypes.at(1));
  FunctionType slot_type = e->getFunctionType(itypes.at(3));

  if (signal_type.prototype().returnType() != Type::Void)
    return deduc.fail();

  if(signal_type.prototype().count() == 0 || slot_type.prototype().count() == 0)
    return deduc.fail();

  if (signal_type.prototype().count() != slot_type.prototype().count())
    return deduc.fail();

  if (!signal_type.prototype().at(0).isObjectType() || !slot_type.prototype().at(0).isObjectType())
    return deduc.fail();

  Class signal_class = e->getClass(signal_type.prototype().at(0));
  Class slot_class = e->getClass(slot_type.prototype().at(0));

  if(!sender_type.inherits(signal_class))
    return deduc.fail();
  if (!receiver_type.inherits(slot_class))
    return deduc.fail();

  deduc.record_deduction(0, TemplateArgument{ signal_type.type() });
  deduc.record_deduction(1, TemplateArgument{ slot_type.type() });

  for (size_t i(1); i < signal_type.prototype().count(); ++i)
  {
    if (signal_type.prototype().at(i) != slot_type.prototype().at(i))
      return deduc.fail();
  }
}

void connect_template_substitute(script::FunctionBuilder & builder, script::FunctionTemplate connect_template, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  Engine *e = connect_template.engine();
  FunctionType signal_type = e->getFunctionType(targs.front().type);
  FunctionType slot_type = e->getFunctionType(targs.back().type);

  builder.setStatic();
  builder.returns(Type::Void);
  builder.addParam(Type::ref(signal_type.prototype().at(0).baseType()));
  builder.addParam(signal_type.type());
  builder.addParam(Type::ref(slot_type.prototype().at(0).baseType()));
  builder.addParam(slot_type.type());
}

std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> connect_template_instantiate(script::FunctionTemplate connect_template, script::Function instance)
{
  return { callbacks::connect, nullptr };
}



void emit_template_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & emit_template, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() != 0)
    return deduc.fail();

  if (itypes.size() < 1) /// TODO : handle the implicit object, note: it is not in itypes
    return deduc.fail();

  if (!itypes.at(0).isFunctionType())
    return deduc.fail();

  Engine *e = emit_template.engine();
  //Class sender_type = e->getClass(itypes.at(0));
  FunctionType signal_type = e->getFunctionType(itypes.at(0));

  if (signal_type.prototype().returnType() != Type::Void)
    return deduc.fail();

  if (signal_type.prototype().count() == 0)
    return deduc.fail();

  //if (signal_type.prototype().argc() != itypes.size() - 1)
  //  return deduc.fail();
  if (signal_type.prototype().count() != itypes.size())
    return deduc.fail();

  if (!signal_type.prototype().at(0).isObjectType())
    return deduc.fail();

  Class signal_class = e->getClass(signal_type.prototype().at(0));

  //if (!sender_type.inherits(signal_class))
  //  return deduc.fail();

  deduc.record_deduction(0, TemplateArgument{ signal_type.type() });
}

void emit_template_substitute(script::FunctionBuilder & builder, script::FunctionTemplate emit_template, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  Engine *e = emit_template.engine();
  FunctionType signal_type = e->getFunctionType(targs.front().type);

  builder.returns(Type::Void);
  builder.addParam(signal_type.type());
  for (size_t i(1); i < signal_type.prototype().count(); ++i)
  {
    builder.addParam(signal_type.prototype().at(i));
  }
}

std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> emit_template_instantiate(script::FunctionTemplate emit_template, script::Function instance)
{
  return { callbacks::emit_callback, nullptr };
}


static void register_connect_template(script::Namespace core)
{
  using namespace script;

  Class object = core.engine()->getClass(Type::QObject);

  std::vector<TemplateParameter> params{
    TemplateParameter{ TemplateParameter::TypeParameter{}, "SignalType" },
    TemplateParameter{ TemplateParameter::TypeParameter{}, "SlotType" },
  };

  Symbol{ object }.FunctionTemplate("connect")
    .setParams(std::move(params))
    .setScope(Scope{ core })
    .deduce(connect_template_deduce).substitute(connect_template_substitute).instantiate(connect_template_instantiate)
    .create();
}

static void register_emit_template(script::Namespace core)
{
  using namespace script;

  Class object = core.engine()->getClass(Type::QObject);

  std::vector<TemplateParameter> params{
    TemplateParameter{ TemplateParameter::TypeParameter{}, "SignalType" },
  };

  Symbol{ object }.FunctionTemplate("emit")
    .setParams(std::move(params))
    .setScope(Scope{ core })
    .deduce(emit_template_deduce).substitute(emit_template_substitute).instantiate(emit_template_instantiate)
    .create();
}

void register_signals_file(script::Namespace core)
{
  register_connect_template(core);
  register_emit_template(core);
}

#include "signals.moc"
