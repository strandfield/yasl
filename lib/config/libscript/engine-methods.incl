
public:

struct list_template_t {};
static const list_template_t ListTemplate;
ClassTemplate getTemplate(list_template_t) const;

struct proxy_template_t {};
static const proxy_template_t ProxyTemplate;
ClassTemplate getTemplate(proxy_template_t) const;

struct ref_template_t {};
static const ref_template_t RefTemplate;
ClassTemplate getTemplate(ref_template_t) const;


void registerQtType(const QMetaObject *mo, const script::Type & type);
Value expose(QObject *obj);
Value expose(QObject *obj, Type t);
void bind(const script::Value & val, QObject *obj);

Value newPtr(const Type & ptr_type, void *value);