
#include <QObject>

namespace script
{

namespace bind
{

BindingData BindingData::get(QObject *obj)
{
  return obj->property("_yasl_data_").value<BindingData>();
}

void BindingData::set(QObject *obj, const BindingData & d)
{
  obj->setProperty("_yasl_data_", QVariant::fromValue(d));
}

} // namespace bind


const Engine::list_template_t Engine::ListTemplate = Engine::list_template_t{};

ClassTemplate Engine::getTemplate(list_template_t) const
{
  return d->list_template_;
}


const Engine::proxy_template_t Engine::ProxyTemplate = Engine::proxy_template_t{};

ClassTemplate Engine::getTemplate(proxy_template_t) const
{
  return d->proxy_template_;
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
    return binding_data.value<bind::BindingData>().value;

  script::Type t = get_qt_type(obj->metaObject(), d->qt_type_map);
  return this->construct(t, [obj, this](Value & ret) {
    this->bind(ret, obj);
  });
}

Value Engine::expose(QObject *obj, Type t)
{
  return this->construct(t, [obj, this](Value & ret) {
    this->bind(ret, obj);
  });
}

void Engine::bind(const Value & val, QObject *obj)
{
  val.impl()->set_qobject(obj);
  obj->setProperty("_yasl_data_", QVariant::fromValue(bind::BindingData{ val }));
}

Value Engine::newPtr(const script::Type & ptr_type, void *value)
{
  return this->construct(ptr_type, [value](Value & ret) {
    ret.impl()->ptr = value;
  });
}

} // namespace script