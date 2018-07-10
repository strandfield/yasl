
#include <QPointer>
#include <QVariant>

struct QMetaObject;
class QObject;

namespace binding
{

struct LIBSCRIPT_API Connection
{
  script::Function signal;
  QPointer<QObject> receiver;
  script::Function slot;
};

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

} // namespace binding

Q_DECLARE_METATYPE(binding::BindingData);

LIBSCRIPT_API void expose(QObject *obj, script::Value val);