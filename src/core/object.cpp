// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/object.h"

#include "yasl/binding/qclass.h"
#include "yasl/core/list.h"
#include "yasl/utils/ref.h"
#include "yasl/utils/signals.h"

#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/functiontype.h>
#include <script/interpreter/executioncontext.h>
#include <script/templateargumentdeduction.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <QObject>


namespace callbacks
{

script::Value new_object(script::FunctionCall *c)
{
  using namespace script;
  Type object_type = c->callee().returnType().baseType();
  Value v = c->engine()->construct(object_type, {});
  return v;
}


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



void register_qobject(script::Namespace n)
{
  using namespace script;

  Class qobject_class = n.newClass(ClassBuilder::New("Object").setId(Type::QObject));
  Type object_type = qobject_class.id();

  register_ref_specialization(n.engine(), Type::QObject, Type::QObjectStar);
  register_ptr_specialization<QObject*>(n.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQObject);
  register_list_specialization<QObject*>(n.engine()->getTemplate(Engine::ListTemplate), Type::QListQObject);

  auto qobject = binding::QClass<QObject>{ qobject_class };
  qobject.ctors().add_default();
  qobject.add_dtor();
  qobject.add_fun<bool, bool, &QObject::blockSignals>("blockSignals");
  // const QObjectList & children() const;
  qobject.add_fun<const QObjectList &, &QObject::children>("children");
  // QMetaObject::Connection 	connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const
  // bool 	disconnect(const char *signal = nullptr, const QObject *receiver = nullptr, const char *method = nullptr) const
  // bool 	disconnect(const QObject *receiver, const char *method = nullptr) const
  qobject.add_void_fun<&QObject::dumpObjectInfo>("dumpObjectInfo");
  qobject.add_void_fun<&QObject::dumpObjectTree>("dumpObjectTree");
  //qobject.add_fun<QList<QByteArray>, &QObject::dynamicPropertyNames>("dynamicPropertyNames");
  //virtual bool 	event(QEvent *e)
  // virtual bool 	eventFilter(QObject *watched, QEvent *event)
//  QList<T> 	findChildren(const QString &name = QString(), Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//QList<T> 	findChildren(const QRegExp &regExp, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//QList<T> 	findChildren(const QRegularExpression &re, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//bool 	inherits(const char *className) const
//void 	installEventFilter(QObject *filterObj)
  qobject.add_fun<bool, &QObject::isWidgetType>("isWidgetType");
  qobject.add_fun<bool, &QObject::isWindowType>("isWindowType");
  qobject.add_void_fun<int, &QObject::killTimer>("killTimer");
//virtual const QMetaObject *	metaObject() const
//void 	moveToThread(QThread *targetThread)
  qobject.add_fun<QString, &QObject::objectName>("objectName");
// QObject* parent() const
  qobject.add_fun<QObject*, &QObject::parent>("parent");
  //QVariant 	property(const char *name) const
//void 	removeEventFilter(QObject *obj)
// void setObjectName(const QString &);
  qobject.add_void_fun<const QString &, &QObject::setObjectName>("setObjectName");
//void 	setParent(QObject *parent)
  qobject.add_void_fun<QObject*, &QObject::setParent>("setParent");
//bool 	setProperty(const char *name, const QVariant &value)
  qobject.add_fun<bool, &QObject::signalsBlocked>("signalsBlocked");
//int 	startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
//int 	startTimer(std::chrono::milliseconds time, Qt::TimerType timerType = Qt::CoarseTimer)
//QThread *	thread() const
  
  n.Function("newObject", callbacks::new_object)
    .returns(Type::ref(object_type))
    .create();

  {
    std::vector<TemplateParameter> params{
      TemplateParameter{ TemplateParameter::TypeParameter{}, "SignalType" },
      TemplateParameter{ TemplateParameter::TypeParameter{}, "SlotType" },
    };

    FunctionTemplate connect_template = n.engine()->newFunctionTemplate("connect", std::move(params), Scope{ n },
      connect_template_deduce, connect_template_substitute, connect_template_instantiate);

    qobject_class.addTemplate(connect_template);
  }

  {
    std::vector<TemplateParameter> params{
      TemplateParameter{ TemplateParameter::TypeParameter{}, "SignalType" },
    };

    FunctionTemplate emit_template = n.engine()->newFunctionTemplate("emit", std::move(params), Scope{ n },
      emit_template_deduce, emit_template_substitute, emit_template_instantiate);

    qobject_class.addTemplate(emit_template);
  }

  n.engine()->registerQtType(&QObject::staticMetaObject, object_type);
}

script::Value make_object(script::Engine *e, script::Type object_type, QObject *value)
{
  script::Value v = e->uninitialized(object_type);
  e->bind(v, value);
  v.impl()->type = v.impl()->type.withoutFlag(script::Type::UninitializedFlag);
  return v;
}

