// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/ref.h"

#include <script/castbuilder.h>
#include <script/class.h>
#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/classtemplatespecializationbuilder.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/namespace.h>
#include <script/operatorbuilder.h>
#include <script/private/engine_p.h>
#include <script/private/function_p.h>
#include <script/templatebuilder.h>
#include <script/typesystem.h>

#include <script/qt.h>

#include <QObject>

namespace script
{

namespace callbacks
{

script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().init<qt::QObjectStar>();
  return c->thisObject();
}

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  c->thisObject().init<qt::QObjectStar>(other.toQObject());
  return c->thisObject();
}

script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<qt::QObjectStar>();
  return c->thisObject();
}

script::Value get(script::FunctionCall *c)
{
  /// TODO : throw on error ?
  QObject *ptr = c->arg(0).toQObject();
  return qt::BindingData::get(ptr)->value;
}

script::Value reset(script::FunctionCall *c)
{
  script::get<qt::QObjectStar>(c->arg(0)).p = nullptr;
  return script::Value::Void;
}

script::Value is_null(script::FunctionCall *c)
{
  return c->engine()->newBool(c->arg(0).toQObject() == nullptr);
}

script::Value is_valid(script::FunctionCall *c)
{
  return c->engine()->newBool(c->arg(0).toQObject() != nullptr);
}

script::Value assign(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  script::get<qt::QObjectStar>(c->arg(0)).p = other.toQObject();
  return c->thisObject();
}

script::Value cast(script::FunctionCall *c)
{
  QObject* ptr = c->arg(0).toQObject();
  script::Value ret = c->engine()->construct(c->callee().returnType(), {});
  script::get<qt::QObjectStar>(ret).p = ptr;
  return ret;
}

}

static script::Class get_ref_instance(const script::Class & qobjectclass)
{
  using namespace script;

  ClassTemplate ct = ClassTemplate::get<RefTemplate>(qobjectclass.engine());
  std::vector<TemplateArgument> args;
  args.push_back(TemplateArgument{ Type{ qobjectclass.id() } });
  return ct.getInstance(args);
}

static void inject_conversions(script::Class & ref, const script::Class & src)
{
  using namespace script;

  if (src.id() == ref.arguments().front().type.baseType().data())
    return;

  // we add a conversion from Ref<T> to Ref<Base>
  ref.newConversion(get_ref_instance(src).id(), callbacks::cast).create();
}

static void inject_conversions_recursively(script::Class & ref, const script::Class & src, const script::Class & qobject)
{
  inject_conversions(ref, src);

  if (src == qobject)
    return;

  inject_conversions_recursively(ref, src.parent(), qobject);
}


static void fill_ref_instance(script::Class & instance, const script::Class & qclass)
{
  using namespace script;

  instance.newConstructor(callbacks::default_ctor).create();
  instance.newConstructor(callbacks::copy_ctor).params(Type::cref(instance.id())).create();
  instance.newConstructor(callbacks::copy_ctor).params(Type::cref(qclass.id())).create();

  // Ref<T>(NullType);
  instance.newConstructor(callbacks::default_ctor)
    .params(Type::cref(Type::NullType)).create();

  instance.newDestructor(callbacks::dtor).create();

  instance.newMethod("get", callbacks::get)
    .setConst()
    .returns(Type::ref(qclass.id()))
    .create();

  instance.newMethod("isNull", callbacks::is_null)
    .setConst()
    .returns(Type::Boolean)
    .create();

  instance.newMethod("isValid", callbacks::is_valid)
    .setConst()
    .returns(Type::Boolean)
    .create();

  instance.newOperator(AssignmentOperator, callbacks::assign)
    .returns(Type::ref(instance.id()))
    .params(Type::cref(instance.id())).create();

  // Ref<T> & operator=(const NullType &);
  instance.newOperator(AssignmentOperator, callbacks::reset)
    .returns(Type::ref(instance.id()))
    .params(Type::cref(Type::NullType)).create();

  // bool operator==(const NullType &) const;
  instance.newOperator(EqualOperator, callbacks::is_null)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(Type::NullType)).create();

  // bool operator!=(const NullType &) const;
  instance.newOperator(InequalOperator, callbacks::is_valid)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(Type::NullType)).create();

  instance.newConversion(Type::ref(qclass.id()), callbacks::get)
    .setConst()
    .create();

  inject_conversions_recursively(instance, qclass, qclass.engine()->typeSystem()->getClass(script::Type::QObject));
}


Class RefTemplate::instantiate(ClassTemplateInstanceBuilder& builder)
{
  using namespace script;

  if (builder.arguments().size() != 1 || builder.arguments().at(0).kind != TemplateArgument::TypeArgument)
    return Class{};

  Type T = builder.arguments().front().type;
  if (!T.isObjectType() || T.isReference() || T.isRefRef())
    return Class{};

  Engine * e = builder.getTemplate().engine();

  Class qobject_class = e->typeSystem()->getClass(script::Type::QObject);
  Class qclass = e->typeSystem()->getClass(T);
  if (!qclass.inherits(qobject_class))
    return Class{};

  Class result = builder.get();

  fill_ref_instance(result, qclass);

  return result;
}

void register_ref_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params;
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });

  ClassTemplate ref = Symbol{ ns }.newClassTemplate("Ref")
    .setParams(std::move(params))
    .setScope(Scope{ ns })
    .withBackend<RefTemplate>()
    .get();
}

script::Class register_ref_specialization(script::Engine *e, script::Type object_type, script::Type::BuiltInType type_id)
{
  using namespace script;

  auto ref_template = ClassTemplate::get<RefTemplate>(e);

  std::vector<TemplateArgument> targs{
    TemplateArgument{ object_type },
  };

  Class ref_type = ref_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal().get();

  fill_ref_instance(ref_type, e->typeSystem()->getClass(object_type));

  return ref_type;
}

script::Value make_ref(script::Engine *e, const script::Type & ref_type, QObject *value)
{
  script::Value ret = e->allocate(ref_type);
  script::ThisObject(ret).init<qt::QObjectStar>(value);
  return ret;
}

script::Class get_ref_type(script::Engine *e, const script::Type & object_type)
{
  return get_ref_instance(e->typeSystem()->getClass(object_type));
}

} // namespace script
