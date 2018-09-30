
namespace callbacks
{

static script::Value new_boxlayout(script::FunctionCall *c)
{
  using namespace binding;
  QBoxLayout *blayout = new QBoxLayout(value_cast<QBoxLayout::Direction>(c->arg(0)));
  return c->engine()->expose(blayout, script::Type::QBoxLayout);
}

static script::Value new_boxlayout_parent(script::FunctionCall *c)
{
  using namespace binding;
  QBoxLayout *blayout = new QBoxLayout(value_cast<QBoxLayout::Direction>(c->arg(0)), value_cast<QWidget*>(c->arg(1)));
  return c->engine()->expose(blayout, script::Type::QBoxLayout);
}

} // namespace callbacks


void register_newlayout_functions(script::Namespace widgets)
{
  using namespace script;

  widgets.Function("newBoxLayout", callbacks::new_boxlayout)
    .returns(Type::ref(script::Type::QBoxLayout))
	.params(Type::QBoxLayoutDirection)
    .create();

  widgets.Function("newBoxLayout", callbacks::new_boxlayout_parent)
    .returns(Type::ref(script::Type::QBoxLayout))
	.params(Type::QBoxLayoutDirection, Type::QWidgetStar)
    .create();
}
