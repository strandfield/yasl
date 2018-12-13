
#include <cstring>

namespace script
{

ValueImpl::ValueImpl(Type t, Engine *e) : ref(0), type(t), engine(e), ptr(nullptr)
{
  std::memset(data.memory, 0, ValueImpl::BufferSize);
  which = FundamentalsField;
}

ValueImpl::Data::Data()
{
  fundamentals.boolean = false;
}

ValueImpl::Data::~Data()
{
  fundamentals.boolean = 0;
}

ValueImpl::ValueImpl(const ValueImpl & other)
 : ref(other.ref), type(other.type), engine(other.engine)
{
  assert(type.isNull() || type == Type::Void);
}

ValueImpl::~ValueImpl()
{
  clear();
}

void ValueImpl::set_string(const String & sval)
{
  if (this->which != StringField)
  {
    clear();
    new (&data.string) String{ sval };
    which = StringField;
  }
  else
  {
    data.string = sval;
  }
}

void ValueImpl::set_qobject(QObject *obj)
{
  this->ptr = obj;
}


bool ValueImpl::is_object() const
{
  return which == ObjectField && !data.object.isNull();
}

const Object & ValueImpl::get_object() const
{
  assert(which == ObjectField);

  return data.object;
}

void ValueImpl::init_object()
{
  if(which != ObjectField) 
  {
    clear();

    auto impl = std::make_shared<ObjectImpl>(this->engine->getClass(this->type));
    new (&data.object) Object{ impl };

    which = ObjectField;
  }
  else
  {
    if (!data.object.isNull())
      return;
    
    auto impl = std::make_shared<ObjectImpl>(this->engine->getClass(this->type));
    data.object = Object{ impl };
  }
}

void ValueImpl::push_member(const Value & val)
{
  assert(which == ObjectField);

  data.object.push(val);
}

Value ValueImpl::pop_member()
{
  assert(which == ObjectField);

  return data.object.pop();
}

Value ValueImpl::get_member(size_t i) const
{
  assert(which == ObjectField);

  return data.object.at(i);
}

size_t ValueImpl::member_count() const
{
  assert(which == ObjectField);

  return data.object.size();
}


bool ValueImpl::is_array() const
{
  return which == ArrayField && !data.array.isNull();
}

const Array & ValueImpl::get_array() const
{
  assert(which == ArrayField);

  return data.array;
}

void ValueImpl::set_array(const Array & aval)
{
  if (which != ArrayField)
  {
    clear();

    new (&data.array) Array{ aval };

    which = ArrayField;
  }
  else
  {
    data.array = aval;
  }
}

bool ValueImpl::is_charref() const
{
  return which == CharrefField;
}

CharRef & ValueImpl::get_charref_field()
{
  assert(which == CharrefField);

  return data.charref;
}

void ValueImpl::set_charref(const CharRef & cr)
{
  if (which != CharrefField)
  {
    clear();

    new (&data.charref) CharRef{ cr };

    which = CharrefField;
  }
  else
  {
    data.charref = cr;
  }
}


bool ValueImpl::is_function() const
{
  return which == FunctionField && !data.function.isNull();
}

const Function & ValueImpl::get_function() const
{
  assert(which == FunctionField);

  return data.function;
}

void ValueImpl::set_function(const Function & fval)
{
  if (which != FunctionField)
  {
    clear();

    new (&data.function) Function{ fval };

    which = FunctionField;
  }
  else
  {
    data.function = fval;
  }
}

bool ValueImpl::is_lambda() const
{
  return which == LambdaField && !data.lambda.isNull();
}

const Lambda & ValueImpl::get_lambda() const
{
  assert(which == LambdaField);

  return data.lambda;
}

void ValueImpl::set_lambda(const Lambda & lval)
{
  if (which != LambdaField)
  {
    clear();

    new (&data.lambda) Lambda{ lval };

    which = LambdaField;
  }
  else
  {
    data.lambda = lval;
  }
}

const Enumerator & ValueImpl::get_enumerator() const
{
  assert(which == EnumeratorField);

  return data.enumerator;
}

void ValueImpl::set_enumerator(const Enumerator & en)
{
  if (which != EnumeratorField)
  {
    clear();

    new (&data.enumerator) Enumerator{ en };

    which = EnumeratorField;
  }
  else
  {
    data.enumerator = en;
  }
}

bool ValueImpl::is_initializer_list() const
{
  return which == InitListField;
}

InitializerList ValueImpl::get_initializer_list() const
{
  assert(which == InitListField);

  return data.initializer_list;
}

void ValueImpl::set_initializer_list(const InitializerList & il)
{
  if (which != InitListField)
  {
    clear();

    new (&data.initializer_list) InitializerList{ il };

    which = InitListField;
  }
  else
  {
    data.initializer_list = il;
  }
}

void ValueImpl::clear()
{
  assert(which != MemoryField);

  switch (which)
  {
  case FundamentalsField:
    return;
  case StringField:
    data.string.~String(); 
    break;
  case ObjectField:
    data.object.~Object();
    break;
  case ArrayField:
    data.array.~Array();
    break;
  case FunctionField:
    data.function.~Function();
    break;
  case LambdaField:
    data.lambda.~Lambda();
    break;
  case EnumeratorField:
    data.enumerator.~Enumerator();
    break;
  case CharrefField:
    data.charref.~CharRef();
    break;
  case InitListField:
    data.initializer_list.~InitializerList();
    break;
  case VariantField:
    data.variant.~QVariant();
    break;
  }

  data.fundamentals.boolean = false;
  which = FundamentalsField;
}

void ValueImpl::set_cleared()
{
  assert(which == MemoryField);
  data.fundamentals.boolean = false;
  which = FundamentalsField;
}

QObject* Value::toQObject() const
{
  return static_cast<QObject*>(d->ptr);
}

void* Value::getPtr() const
{
  return d->ptr;
}

void Value::setPtr(void *ptr)
{
  d->ptr = ptr;
}

const QVariant & Value::toVariant() const
{
  assert(d->which == ValueImpl::VariantField);

  return d->data.variant;
}

QVariant & Value::toVariant()
{
  assert(d->which == ValueImpl::VariantField);

  return d->data.variant;
}

void Value::setVariant(const QVariant & v)
{
  if (d->which != ValueImpl::VariantField)
  {
    d->clear();

    new (&d->data.variant) QVariant{ v };

    d->which = ValueImpl::VariantField;
  }
  else
  {
    d->data.variant = v;
  }
}

void* Value::getMemory(passkey) const
{
  if (d->which != ValueImpl::MemoryField)
    d->clear();

  d->which = ValueImpl::MemoryField;
  return memory();
}

void* Value::memory() const
{
  assert(d->which == ValueImpl::MemoryField);

  return &(d->data.memory);
}

void Value::releaseMemory(passkey)
{
  d->set_cleared();
}

void Value::clear(passkey)
{
  d->clear();
}

bool & Value::getBoolField(passkey) const
{
  return d->data.fundamentals.boolean;
}

char & Value::getCharField(passkey) const
{
  return d->data.fundamentals.character;
}

int & Value::getIntField(passkey) const
{
  return d->data.fundamentals.integer;
}

float & Value::getFloatField(passkey) const
{
  return d->data.fundamentals.realf;
}

double & Value::getDoubleField(passkey) const
{
  return d->data.fundamentals.reald;
}

String & Value::getStringField(passkey) const
{
  return d->data.string;
}

} // namespace script