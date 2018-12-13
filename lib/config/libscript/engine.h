
#include "script/function.h"
#include "script/value.h"

#include <QPointer>
#include <QVariant>

struct QMetaObject;
class QObject;

namespace script
{

namespace bind
{

struct LIBSCRIPT_API Connection
{
  script::Function signal;
  QPointer<QObject> receiver;
  script::Function slot;
};

// Put out of bind namespace & rename
struct LIBSCRIPT_API BindingData
{
  script::Value value;
  QList<Connection> connections;

  BindingData() = default;
  BindingData(const BindingData &) = default;
  ~BindingData() = default;

  static BindingData get(QObject *obj);
  static void set(QObject *obj, const BindingData & d);

  BindingData & operator=(const BindingData &) = default;
};

} // namespace bind

} // namespace script

Q_DECLARE_METATYPE(script::bind::BindingData);