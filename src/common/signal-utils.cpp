// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/signal-utils.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplatenativebackend.h>
#include <script/functiontype.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/qt.h>
#include <script/scope.h>
#include <script/symbol.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>
#include <script/typesystem.h>
#include <script/value.h>

#include <QMetaMethod>
#include <QMetaObject>
#include <QObject>


namespace script
{

namespace callbacks
{

script::Value generic_connect(script::FunctionCall *c)
{
  script::Value sender = c->arg(0);
  script::Function signal = c->arg(1).toFunction();
  script::Value receiver = c->arg(2);
  script::Function slot = c->arg(3).toFunction();

  /// TODO: return the result of yasl::connect instead of Void
  yasl::connect(sender, signal, receiver, slot);

  return script::Value::Void;
}

script::Value connect_string_overload(script::FunctionCall *c)
{
  script::Value sender = c->arg(0);
  QString signal = c->arg(1).toString();
  script::Value receiver = c->arg(2);
  QString slot = c->arg(3).toString();

  const bool result = yasl::connect(sender, signal.toStdString(), receiver, slot.toStdString());

  return c->engine()->newBool(result);
}

script::Value emit_callback(script::FunctionCall *c)
{
  // first arg is the object, second is the signal
  // the rest are the signal's args.
  yasl::emitSignal(c->thisObject(), c->arg(1).toFunction(), c->args().begin() + 2, c->args().end());
  return script::Value::Void;
}

} // namespace callbacks

} // namespace script

namespace yasl
{

SignalTableEntry::SignalTableEntry()
  : signal_index(-1)
  , mapper_index(-1)
  , slot_index(-1)
{

}

SignalTableEntry::SignalTableEntry(int sig, int mapper, int slot)
  : signal_index(sig)
  , mapper_index(mapper)
  , slot_index(slot)
{

}

SignalMapper::SignalMapper()
  : receiver_(nullptr)
{

}

SignalMapper::SignalMapper(QObject* obj, const script::Function & target)
  : receiver_(obj)
  , slot_(target)
{

}

int SignalMapper::slotIndex(const QMetaMethod & signal) const
{
  const QMetaObject *self = this->metaObject();
  const char *class_name = self->className();
  const int method_offset = self->methodOffset();
  const int method_count = self->methodCount();

  for (int i(method_offset); i < method_count; ++i)
  {
    const QMetaMethod slot = self->method(i);
    if (slot.methodType() != QMetaMethod::Slot)
      continue;

    if (QMetaObject::checkConnectArgs(signal, slot))
      return i;
  }
  return -1;
}

void SignalMapper::registerMapper(SignalMapper* mapper)
{
  mappers().append(QPointer<SignalMapper>(mapper));
}

QList<QPointer<SignalMapper>> & SignalMapper::mappers()
{
  static QList<QPointer<SignalMapper>> static_list = {};
  return static_list;
}

std::pair<int, int> SignalMapper::getMapperAndSlotIndex(const QMetaMethod & signal)
{
  auto & list = mappers();

  for (int i(0); i < list.size(); ++i)
  {
    auto m = list.at(i);
    int j = m->slotIndex(signal);
    if (j != -1)
      return std::make_pair(i, j);
  }

  return std::make_pair(-1, -1);
}

void SignalMapper::invoke(std::initializer_list<script::Value> && args)
{
  script::Engine *e = slot_.engine();
  std::vector<script::Value> invoke_args{ e->expose(receiver_) };
  invoke_args.insert(invoke_args.end(), args.begin(), args.end());
  script::Value result = slot_.invoke(invoke_args);
  if (!slot_.returnType().isReference())
    e->destroy(result);
}

std::shared_ptr<script::UserData> createSignalTable()
{
  return std::make_shared<SignalTableClassData>();
}

std::shared_ptr<SignalTableClassData> getSignalTable(script::Class & c)
{
  return std::static_pointer_cast<SignalTableClassData>(c.data());
}

SignalTableEntry getSignalTableEntry(const script::Function & sig)
{
  script::Class c = sig.memberOf();
  auto table = getSignalTable(c);
  return table->table.value(sig);
}

void registerSignal(script::Class & c, const QMetaObject *meta, const script::Function & sig, const std::string & signature)
{
  const int signal_index = meta->indexOfSignal(QMetaObject::normalizedSignature(signature.data()));
  if (signal_index == -1)
    throw std::runtime_error{ std::string{ meta->className() } +std::string{ " has no such signal : " } +signature };
  QMetaMethod sender_signal = meta->method(signal_index);

  auto info = SignalMapper::getMapperAndSlotIndex(sender_signal);

  if (info.first == -1)
    throw std::runtime_error{ std::string{ " No SignalMapper support the following signature : " } +signature };

  auto table = getSignalTable(c);
  table->table.insert(sig, SignalTableEntry{ signal_index, info.first, info.second });
}

bool connect(const script::Value & sender, const script::Function & sig, const script::Value & receiver, const script::Function & slot)
{
  QObject *sender_object = sender.toQObject();
  QObject *receiver_object = receiver.toQObject();

  if (sender_object == nullptr || receiver_object == nullptr)
    return false;

  if (sig.isNative())
  {
    // We create a SignalMapper to map from the QObject C++ signal to the script::Function slot
    SignalTableEntry entry = getSignalTableEntry(sig);
    SignalMapper *mapper = SignalMapper::mappers().at(entry.mapper_index)->clone(receiver_object, slot);
    /// TODO: could we add the signal mapper to receiver instead of creating a new connection ?
    QObject::connect(receiver_object, SIGNAL(destroyed()), mapper, SLOT(deleteLater()));
    const bool ok = QMetaObject::connect(sender_object, entry.signal_index, mapper, entry.slot_index);
    return true;
  }
  else
  {
    // We connect a user-defined signal to a script::Function slot
    auto data = script::qt::BindingData::get(sender_object);
    data->connections.push_back(script::qt::Connection{ sig, QPointer<QObject>{receiver_object}, slot });
  }

  return true;
}

static bool signal_slot_match(const script::Function & sig, const script::Function & slot)
{
  const auto & sig_proto = sig.prototype();
  const auto & slot_proto = slot.prototype();

  if (sig_proto.size() != slot_proto.size())
    return false;

  for (int i(1); i < sig_proto.size(); ++i)
  {
    if (sig_proto.at(i) != slot_proto.at(i))
      return false;
  }

  return true;
}

bool connect(const script::Value & sender, const std::string & signal, const script::Value & receiver, const std::string & slot)
{
  script::Engine *e = sender.engine();

  script::Class sender_class = e->typeSystem()->getClass(e->getQtType(sender.toQObject()->metaObject()));
  const script::Class receiver_class = e->typeSystem()->getClass(e->getQtType(receiver.toQObject()->metaObject()));

  while (!sender_class.isNull())
  {

    for (const auto & f : sender_class.memberFunctions())
    {
      if (f.name() != signal)
        continue;

      script::Class receiver_it = receiver_class;
      while (!receiver_it.isNull())
      {
        for (const auto & g : receiver_class.memberFunctions())
        {
          if (g.name() != slot)
            continue;

          if (signal_slot_match(f, g))
            return yasl::connect(sender, f, receiver, g);
        }

        receiver_it = receiver_it.parent();
      }
    }

    sender_class = sender_class.parent();
  }

  return false;
}


void emitSignal(const script::Value & object, const script::Function & sig, const script::Value *begin, const script::Value *end)
{
  script::Engine *e = sig.engine();

  std::vector<script::Value> invoke_args{ script::Value{} };
  invoke_args.insert(invoke_args.end(), begin, end);

  std::vector<script::qt::Connection>& connections = script::qt::BindingData::get(object.toQObject())->connections;

  for (const script::qt::Connection & c : connections)
  {
    if (c.signal != sig)
      continue;

    if (c.receiver.isNull())
      continue;

    invoke_args[0] = e->expose(c.receiver.data());
    script::Value result = c.slot.invoke(invoke_args);
    if (!c.slot.returnType().isReference())
      e->destroy(result);
  }
}

class ConnectTemplate : public script::FunctionTemplateNativeBackend
{
public:
  void deduce(script::TemplateArgumentDeduction& deduc, const std::vector<script::TemplateArgument>& targs, const std::vector<script::Type>& itypes) override
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

    Engine * e = functionTemplate().engine();
    Class sender_type = e->typeSystem()->getClass(itypes.at(0));
    Class receiver_type = e->typeSystem()->getClass(itypes.at(2));
    FunctionType signal_type = e->typeSystem()->getFunctionType(itypes.at(1));
    FunctionType slot_type = e->typeSystem()->getFunctionType(itypes.at(3));

    if (signal_type.prototype().returnType() != Type::Void)
      return deduc.fail();

    if (signal_type.prototype().count() == 0 || slot_type.prototype().count() == 0)
      return deduc.fail();

    if (signal_type.prototype().count() != slot_type.prototype().count())
      return deduc.fail();

    if (!signal_type.prototype().at(0).isObjectType() || !slot_type.prototype().at(0).isObjectType())
      return deduc.fail();

    Class signal_class = e->typeSystem()->getClass(signal_type.prototype().at(0));
    Class slot_class = e->typeSystem()->getClass(slot_type.prototype().at(0));

    if (!sender_type.inherits(signal_class))
      return deduc.fail();
    if (!receiver_type.inherits(slot_class))
      return deduc.fail();

    deduc.record_deduction(0, TemplateArgument{ signal_type.type() });
    deduc.record_deduction(1, TemplateArgument{ slot_type.type() });

    for (int i(1); i < signal_type.prototype().count(); ++i)
    {
      if (signal_type.prototype().at(i) != slot_type.prototype().at(i))
        return deduc.fail();
    }
  }

  void substitute(script::FunctionBuilder& builder, const std::vector<script::TemplateArgument>& targs) override
  {
    using namespace script;

    Engine* e = functionTemplate().engine();
    FunctionType signal_type = e->typeSystem()->getFunctionType(targs.front().type);
    FunctionType slot_type = e->typeSystem()->getFunctionType(targs.back().type);

    builder.returns(Type::Void);
    builder.addParam(Type::ref(signal_type.prototype().at(0).baseType()));
    builder.addParam(signal_type.type());
    builder.addParam(Type::ref(slot_type.prototype().at(0).baseType()));
    builder.addParam(slot_type.type());
  }

  std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> instantiate(script::Function& function) override
  {
    return { script::callbacks::generic_connect, nullptr };
  }
};

class EmitTemplate : public script::FunctionTemplateNativeBackend
{
public:
  void deduce(script::TemplateArgumentDeduction& deduc, const std::vector<script::TemplateArgument>& targs, const std::vector<script::Type>& itypes) override
  {
    using namespace script;

    if (targs.size() != 0)
      return deduc.fail();

    if (itypes.size() < 1) /// TODO : handle the implicit object, note: it is not in itypes
      return deduc.fail();

    if (!itypes.at(0).isFunctionType())
      return deduc.fail();

    Engine * e = functionTemplate().engine();
    //Class sender_type = e->getClass(itypes.at(0));
    FunctionType signal_type = e->typeSystem()->getFunctionType(itypes.at(0));

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

    Class signal_class = e->typeSystem()->getClass(signal_type.prototype().at(0));

    //if (!sender_type.inherits(signal_class))
    //  return deduc.fail();

    deduc.record_deduction(0, TemplateArgument{ signal_type.type() });
  }

  void substitute(script::FunctionBuilder & builder, const std::vector<script::TemplateArgument> & targs) override
  {
    using namespace script;

    Engine* e = functionTemplate().engine();
    FunctionType signal_type = e->typeSystem()->getFunctionType(targs.front().type);

    builder.returns(Type::Void);
    builder.addParam(signal_type.type());
    for (int i(1); i < signal_type.prototype().count(); ++i)
    {
      builder.addParam(signal_type.prototype().at(i));
    }
  }

  std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> instantiate(script::Function & function) override
  {
    return { script::callbacks::emit_callback, nullptr };
  }
};

void registerSignalUtils(script::Namespace core)
{
  // template<typename SignalType> 
  // void Object::emit(SignalType signal, SignalArgs ...)
  {
    std::vector<script::TemplateParameter> params{
      script::TemplateParameter{ script::TemplateParameter::TypeParameter{}, "SignalType" },
    };

    script::Class object = core.engine()->typeSystem()->getClass(script::Type::QObject);

    script::Symbol{ object }.newFunctionTemplate("emit")
      .setParams(std::move(params))
      .setScope(script::Scope{ object })
      .withBackend<EmitTemplate>()
      .create();
  }

  // template<typename SignalType, typename SlotType> 
  // bool connect(Object & sender, SignalType signal, Object & receiver, SlotType slot);
  {
    std::vector<script::TemplateParameter> params{
      script::TemplateParameter{ script::TemplateParameter::TypeParameter{}, "SignalType" },
      script::TemplateParameter{ script::TemplateParameter::TypeParameter{}, "SlotType" },
    };

    script::Symbol{ core }.newFunctionTemplate("connect")
      .setParams(std::move(params))
      .setScope(script::Scope{ core })
      .withBackend<ConnectTemplate>()
      .create();
  }

  // bool connect(Object & sender, const String & signal, Object & receiver, const String & slot);
  {
    using namespace script;
    core.newFunction("connect", callbacks::connect_string_overload)
      .returns(Type::Boolean)
      .params(Type::ref(Type::QObject), Type::cref(Type::String), Type::ref(Type::QObject), Type::cref(Type::String))
      .create();
  }
}

} // namespace yasl
