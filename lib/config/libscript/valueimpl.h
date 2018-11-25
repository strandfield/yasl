

#include "script/array.h"
#include "script/enumerator.h"
#include "script/function.h"
#include "script/initializerlist.h"
#include "script/lambda.h"
#include "script/object.h"
#include "script/string.h"

#include <QVariant>

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

  struct Fundamentals
  {
    bool boolean;
    char character;
    int integer;
    float realf;
    double reald;
  };

  static const int BufferSize = 40;

  union Data
  {
    Fundamentals fundamentals;
    String string;
    Object object;
    Array array;
    Function function;
    Lambda lambda;
    Enumerator enumerator;
    CharRef charref;
    InitializerList initializer_list;
    QVariant variant;
    char memory[40];

    Data();
    ~Data();
  };
  Data data;
  void *ptr;

  enum Field {
    FundamentalsField,
    StringField,
    ObjectField,
    ArrayField,
    FunctionField,
    LambdaField,
    EnumeratorField,
    CharrefField,
    InitListField,
    VariantField,
    MemoryField,
  };
  char which;

  inline bool get_bool() const { return data.fundamentals.boolean; }
  inline void set_bool(bool bval) { data.fundamentals.boolean = bval; }
  inline char get_char() const { return data.fundamentals.character; }
  inline void set_char(char cval) { data.fundamentals.character = cval; }
  inline int get_int() const { return data.fundamentals.integer; }
  inline void set_int(int ival) { data.fundamentals.integer = ival; }
  inline float get_float() const { return data.fundamentals.realf; }
  inline void set_float(float fval) { data.fundamentals.realf = fval; }
  inline double get_double() const { return data.fundamentals.reald; }
  inline void set_double(double dval) { data.fundamentals.reald = dval; }

  inline const String & get_string() const { return data.string; }
  inline String & get_string() { return data.string; }
  void set_string(const String & sval);

  void set_qobject(QObject *obj);

  bool is_object() const;
  const Object & get_object() const;
  void init_object();
  void push_member(const Value & val);
  Value pop_member();
  Value get_member(size_t i) const;
  size_t member_count() const;

  bool is_array() const;
  const Array & get_array() const;
  void set_array(const Array & aval);

  bool is_charref() const;
  CharRef & get_charref_field();
  void set_charref(const CharRef & cr);

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

  void clear();
  void set_cleared();
};

} // namespace script