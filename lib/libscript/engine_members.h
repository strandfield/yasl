
public:

struct list_template_t {};
static const list_template_t ListTemplate;
ClassTemplate getTemplate(list_template_t) const;

struct ptr_template_t {};
static const ptr_template_t PtrTemplate;
ClassTemplate getTemplate(ptr_template_t) const;

struct ref_template_t {};
static const ref_template_t RefTemplate;
ClassTemplate getTemplate(ref_template_t) const;


void registerQtType(const QMetaObject *mo, const script::Type & type);
Value expose(QObject *obj);
void bind(const script::Value & val, QObject *obj);
Value newPtr(const Type & ptr_type, void *value);