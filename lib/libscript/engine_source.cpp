
#include <QObject>

binding::BindingData binding::BindingData::get(QObject *obj)
{
  return obj->property("_yasl_data_").value<binding::BindingData>();
}

void binding::BindingData::set(QObject *obj, const BindingData & d)
{
  obj->setProperty("_yasl_data_", QVariant::fromValue(d));
}

namespace script
{

const Engine::list_template_t Engine::ListTemplate = Engine::list_template_t{};

ClassTemplate Engine::getTemplate(list_template_t) const
{
  return d->list_template_;
}


const Engine::ptr_template_t Engine::PtrTemplate = Engine::ptr_template_t{};

ClassTemplate Engine::getTemplate(ptr_template_t) const
{
  return d->ptr_template_;
}


const Engine::ref_template_t Engine::RefTemplate = Engine::ref_template_t{};

ClassTemplate Engine::getTemplate(ref_template_t) const
{
  return d->ref_template_;
}


void Engine::registerQtType(const QMetaObject *mo, const script::Type & type)
{
  d->qt_type_map.insert(mo, type);
}

static Type get_qt_type(const QMetaObject *mo, const QMap<const QMetaObject*, script::Type> & map)
{
  if (mo == nullptr)
    return script::Type::Null; /// TODO : throw ?

  script::Type t = map.value(mo, script::Type::Null);
  if (!t.isNull())
    return t;

  return get_qt_type(mo->superClass(), map);
}

Value Engine::expose(QObject *obj)
{
  QVariant binding_data = obj->property("_yasl_data_");
  if (binding_data.isValid())
    return binding_data.value<binding::BindingData>().value;

  script::Type t = get_qt_type(obj->metaObject(), d->qt_type_map);
  script::Value ret = this->uninitialized(t);
  ret.impl()->type = ret.impl()->type.withoutFlag(script::Type::UninitializedFlag);
  bind(ret, obj);
  return ret;
}

void Engine::bind(const Value & val, QObject *obj)
{
  val.impl()->set_qobject(obj);
  obj->setProperty("_yasl_data_", QVariant::fromValue(binding::BindingData{ val }));
}

} // namespace script