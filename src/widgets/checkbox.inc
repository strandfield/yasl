
#include "yasl/common/wrappers/newfunction_wrapper.h"


void register_newcheckbox_functions(script::Namespace widgets)
{
  using namespace script;

  widgets.newFunction("newCheckBox", wrapper::qclass_newfunction_wrapper_t<QCheckBox, QWidget*>::wrap)
    .returns(Type::ref(script::Type::QCheckBox))
	.params(Type::QWidgetStar)
    .create();

  widgets.newFunction("newCheckBox", wrapper::qclass_newfunction_wrapper_t<QCheckBox, const QString &, QWidget*>::wrap)
    .returns(Type::ref(script::Type::QCheckBox))
	.params(Type::cref(Type::String), Type::QWidgetStar)
    .create();
}
