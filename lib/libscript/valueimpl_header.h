

#include "script/array.h"
#include "script/enumerator.h"
#include "script/function.h"
#include "script/initializerlist.h"
#include "script/lambda.h"
#include "script/object.h"
#include "script/string.h"

class QObject;

namespace script
{

struct LIBSCRIPT_API CharRef
{
  String *string;
  size_t pos;
};


struct LIBSCRIPT_API ValueImpl
{
  ValueImpl(Type t, Engine *e);
  ValueImpl(const ValueImpl &);
  ~ValueImpl();

  reference_counter_type ref;
  Type type;
  Engine *engine;

  struct BuiltIn
  {
    BuiltIn();

    String string;
    QObject *qobject;
    Object object;
    Array array;
    Function function;
    Lambda lambda;
    Enumerator enumerator;
    CharRef charref;
    Value* valueptr;
    InitializerList initializer_list;
  };

  union Data
  {
    BuiltIn builtin;
    bool boolean;
    char character;
    int integer;
    float realf;
    double reald;
    void *ptr;
    char memory[sizeof(BuiltIn)];

    Data();
    ~Data();
  };
  Data data;

  inline bool get_bool() const { return data.boolean; }
  inline void set_bool(bool bval) { data.boolean = bval; }
  inline char get_char() const { return data.character; }
  inline void set_char(char cval) { data.character = cval; }
  inline int get_int() const { return data.integer; }
  inline void set_int(int ival) { data.integer = ival; }
  inline float get_float() const { return data.realf; }
  inline void set_float(float fval) { data.realf = fval; }
  inline double get_double() const { return data.reald; }
  inline void set_double(double dval) { data.reald = dval; }

  inline const String & get_string() const { return data.builtin.string; }
  inline String & get_string() { return data.builtin.string; }
  inline void set_string(const String & sval)
  {
    if (!type.testFlag(Type::BuiltInStorageFlag))
    {
      new (&data.builtin) BuiltIn;
      type = type.withFlag(Type::BuiltInStorageFlag);
    }

    data.builtin.string = sval;
  }

  void set_qobject(QObject *obj);

  bool is_object() const;
  const Object & get_object() const;
  void init_object();

  bool is_array() const;
  const Array & get_array() const;
  void set_array(const Array & aval);

  bool is_function() const;
  const Function & get_function() const;
  void set_function(const Function & fval);
  bool is_lambda() const;
  const Lambda & get_lambda() const;
  void set_lambda(const Lambda & lval);
  const Enumerator & get_enumerator() const;
  void set_enumerator(const Enumerator & en);
  bool is_initializer_list() const;
  InitializerList get_initializer_list() const;
  void set_initializer_list(const InitializerList & il);

  void clear()
  {
    if (type.testFlag(Type::BuiltInStorageFlag))
    {
      data.builtin.~BuiltIn();
      type = type.withoutFlag(Type::BuiltInStorageFlag);
    }
  }
};

} // namespace script