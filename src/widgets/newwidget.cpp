// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/newwidget.h"

#include "yasl/common/binding/qclass.h"
#include "yasl/core/size.h"
#include "yasl/gui/guievent.h"
#include "yasl/common/ref.h"

#include <script/classbuilder.h>
#include <script/classtemplate.h>
#include <script/conversions.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/initialization.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/overloadresolution.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>
#include <script/userdata.h>
#include <script/value.h>

namespace script
{

namespace callbacks
{

static script::Value widget_ctor(script::FunctionCall *c)
{
  script::Value self = c->thisObject();
  Widget *obj = new Widget();
  c->engine()->bind(self, obj);
  return self;
}

static script::Value new_widget(script::FunctionCall *c)
{
  using namespace script;
  Type widget_type = c->callee().returnType().baseType();
  Value v = c->engine()->construct(Type::QWidget, {});
  return v;
}


static script::Value new_widget_window_title(script::FunctionCall *c)
{
  using namespace script;

  QWidget *widget = new QWidget;
  widget->setWindowTitle(script::value_cast<QString>(c->arg(0)));

  Type widget_type = c->callee().returnType().baseType();

  return c->engine()->construct(widget_type, [c, widget](Value & ret) {
    c->engine()->bind(ret, widget);
  });
}

static script::Value event_handler(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  const bool result = self->QWidgetEvent(script::value_cast<QEvent*>(c->arg(1)));
  return c->engine()->newBool(result);
}

static script::Value close_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetCloseEvent(script::value_cast<QCloseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value enter_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetEnterEvent(script::value_cast<QEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value hide_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetHideEvent(script::value_cast<QHideEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value key_press_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetKeyPressEvent(script::value_cast<QKeyEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value key_release_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetKeyReleaseEvent(script::value_cast<QKeyEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value leave_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetLeaveEvent(script::value_cast<QEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_double_click_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseDoubleClickEvent(script::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_move_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseMoveEvent(script::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_press_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetMousePressEvent(script::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_release_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseReleaseEvent(script::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value move_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetMoveEvent(script::value_cast<QMoveEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value paint_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetPaintEvent(script::value_cast<QPaintEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value resize_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetResizeEvent(script::value_cast<QResizeEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value show_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetShowEvent(script::value_cast<QShowEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value wheel_event(script::FunctionCall *c)
{
  Widget *self = script::value_cast<Widget*>(c->arg(0));
  self->QWidgetWheelEvent(script::value_cast<QWheelEvent*>(c->arg(1)));
  return script::Value::Void;
}

} // namespace callbacks

} // namespace script


static void add_events_method(script::Engine *e)
{
  using namespace script;

  Class widget = e->getClass(Type::QWidget);
  
  /* Events */
  widget.newMethod("event", callbacks::event_handler)
    .setProtected()
    .returns(Type::Boolean)
    .params(script::make_type<QEvent &>())
    .create();
  
  widget.newMethod("closeEvent", callbacks::close_event)
    .setProtected()
    .params(script::make_type<QCloseEvent &>())
    .create();

  widget.newMethod("enterEvent", callbacks::enter_event)
    .setProtected()
    .params(script::make_type<QEvent &>())
    .create();

  widget.newMethod("hideEvent", callbacks::hide_event)
    .setProtected()
    .params(script::make_type<QHideEvent &>())
    .create();

  widget.newMethod("keyPressEvent", callbacks::key_press_event)
    .setProtected()
    .params(script::make_type<QKeyEvent &>())
    .create();

  widget.newMethod("keyReleaseEvent", callbacks::key_release_event)
    .setProtected()
    .params(script::make_type<QKeyEvent &>())
    .create();

  widget.newMethod("leaveEvent", callbacks::leave_event)
    .setProtected()
    .params(script::make_type<QEvent &>())
    .create();

  widget.newMethod("mouseDoubleClickEvent", callbacks::mouse_double_click_event)
    .setProtected()
    .params(script::make_type<QMouseEvent &>())
    .create();

  widget.newMethod("mouseMoveEvent", callbacks::mouse_move_event)
    .setProtected()
    .params(script::make_type<QMouseEvent &>())
    .create();

  widget.newMethod("mousePressEvent", callbacks::mouse_press_event)
    .setProtected()
    .params(script::make_type<QMouseEvent &>())
    .create();

  widget.newMethod("mouseReleaseEvent", callbacks::mouse_release_event)
    .setProtected()
    .params(script::make_type<QMouseEvent &>())
    .create();

  widget.newMethod("moveEvent", callbacks::mouse_move_event)
    .setProtected()
    .params(script::make_type<QMoveEvent &>())
    .create();

  widget.newMethod("paintEvent", callbacks::paint_event)
    .setProtected()
    .params(script::make_type<QPaintEvent &>())
    .create();

  widget.newMethod("resizeEvent", callbacks::resize_event)
    .setProtected()
    .params(script::make_type<QResizeEvent &>())
    .create();

  widget.newMethod("showEvent", callbacks::show_event)
    .setProtected()
    .params(script::make_type<QShowEvent &>())
    .create();

  widget.newMethod("wheelEvent", callbacks::wheel_event)
    .setProtected()
    .params(script::make_type<QWheelEvent &>())
    .create();
}


void new_widget_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & new_widget, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() != 1)
    return deduc.fail();

  std::vector<TemplateArgument> args;
  for (const auto & t : itypes)
  {
    if (t.isConst())
      args.push_back(TemplateArgument{ Type::cref(t.baseType()) });
    else
      args.push_back(TemplateArgument{ Type::ref(t.baseType()) });
  }

  deduc.record_deduction(1, TemplateArgument{ std::move(args) });
}

void new_widget_substitute(script::FunctionBuilder & builder, script::FunctionTemplate new_widget, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  builder.returns(Type::ref(targs.front().type));

  for (const auto & p : targs.back().pack->args())
  {
    builder.addParam(p.type);
  }
}


class NewWidgetTemplateData : public script::UserData
{
public:
  ~NewWidgetTemplateData() = default;

  script::Function target;
  std::vector<script::Conversion> conversions;
  std::vector<script::Type> types;
  Widget::Callbacks callbacks;
};

namespace script
{
namespace callbacks
{

static script::Value new_widget_template(script::FunctionCall *c)
{
  using namespace script;
  auto data = std::static_pointer_cast<NewWidgetTemplateData>(c->callee().data());
  Value widget = c->engine()->allocate(data->target.memberOf().id());
  std::vector<Value> args{
    widget
  };
  args.insert(args.end(), c->args().begin(), c->args().end());
  c->engine()->applyConversions(args, data->conversions);
  c->engine()->invoke(data->target, args);
  script::value_cast<Widget*>(widget)->mCallbacks = data->callbacks;
  return widget;
}

} // namespace callbacks
} // namespace script

void assign_callback(script::Function & callback, const script::Function & candidate, const std::string & name, const script::Type & param_type)
{
  if (candidate.returnType() != script::Type::Void || candidate.prototype().count() != 2 || candidate.parameter(1) != param_type)
    return;

  if (candidate.name() == name)
    callback = candidate;
}

void assign_callback_ex(script::Function & callback, const script::Function & candidate, const std::string & name, const script::Type & return_type, const script::Type & param_type)
{
  if (candidate.returnType() != return_type || candidate.prototype().count() != 2 || candidate.parameter(1) != param_type)
    return;

  if (candidate.name() == name)
    callback = candidate;
}

void fill_callbacks(Widget::Callbacks & cbs, const script::Class & c)
{
  using namespace script;

  if (c.id() == Type::QWidget)
    return;

  for (const auto & f : c.memberFunctions())
  {
    assign_callback_ex(cbs.event, f, "event", Type::Boolean, Type::ref(script::Type::QEvent));
    assign_callback(cbs.close, f, "closeEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.enter, f, "enterEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.hide, f, "hideEvent", Type::ref(script::Type::QHideEvent));
    assign_callback(cbs.keyPress, f, "keyPressEvent", Type::ref(script::Type::QKeyEvent));
    assign_callback(cbs.keyRelease, f, "keyReleaseEvent", Type::ref(script::Type::QKeyEvent));
    assign_callback(cbs.leave, f, "leaveEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.mouseDoubleClick, f, "mouseDoubleClickEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mouseMove, f, "mouseMoveEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mousePress, f, "mousePressEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mouseRelease, f, "mouseReleaseEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.move, f, "mouseReleaseEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.paint, f, "paintEvent", Type::ref(script::Type::QPaintEvent));
    assign_callback(cbs.resize, f, "resizeEvent", Type::ref(script::Type::QResizeEvent));
    assign_callback(cbs.show, f, "showEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.wheel, f, "wheelEvent", Type::ref(script::Type::QWheelEvent));
  }

  fill_callbacks(cbs, c.parent());
}

std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> new_widget_instantitate(script::FunctionTemplate new_widget, script::Function instance)
{
  using namespace script;

  auto data = std::make_shared<NewWidgetTemplateData>();

  Class target_type = new_widget.engine()->getClass(instance.returnType());
  
  std::vector<Type> types{
    Type::ref(target_type.id())
  };
  types.insert(types.end(), instance.prototype().begin(), instance.prototype().end());
  
  OverloadResolution resol = OverloadResolution::New(new_widget.engine());
  if (!resol.process(target_type.constructors(), types))
    throw TemplateInstantiationError{ "newWidget() : Could not find valid constructor" };

  data->target = resol.selectedOverload();
  /// TODO: should we use Initialization instead ?
  for (const auto & init : resol.initializations())
    data->conversions.push_back(init.conversion());
  data->types = data->target.prototype().parameters();

  fill_callbacks(data->callbacks, target_type);

  return { callbacks::new_widget_template, data };
}

static void register_new_widget_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params;
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, TemplateParameter::ParameterPack{}, "Args" });

  FunctionTemplate new_widget = Symbol{ n }.newFunctionTemplate("newWidget")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .deduce(new_widget_deduce).substitute(new_widget_substitute).instantiate(new_widget_instantitate)
    .get();
}

void register_newwidget_file(script::Namespace core)
{
  using namespace script;

  /// TODO : maybe move elsewhere
  Class widget = core.engine()->getClass(Type::QWidget);
  widget.newConstructor(callbacks::widget_ctor).create();

  core.newFunction("newWidget", callbacks::new_widget)
    .returns(Type::ref(Type::QWidget))
    .create();

  core.newFunction("newWidget", callbacks::new_widget_window_title)
    .returns(Type::ref(Type::QWidget))
    .params(Type::cref(Type::String))
    .create();

  register_new_widget_template(core);

  add_events_method(core.engine());
}


Widget::Widget()
{

}

bool Widget::QWidgetEvent(QEvent *e)
{
  return QWidget::event(e);
}

void Widget::QWidgetCloseEvent(QCloseEvent *e)
{
  return QWidget::closeEvent(e);
}

void Widget::QWidgetEnterEvent(QEvent *e)
{
  return QWidget::enterEvent(e);
}

void Widget::QWidgetHideEvent(QHideEvent *e)
{
  return QWidget::hideEvent(e);
}

void Widget::QWidgetKeyPressEvent(QKeyEvent *e)
{
  return QWidget::keyPressEvent(e);
}

void Widget::QWidgetKeyReleaseEvent(QKeyEvent *e)
{
  return QWidget::keyReleaseEvent(e);
}

void Widget::QWidgetLeaveEvent(QEvent *e)
{
  return QWidget::leaveEvent(e);
}

void Widget::QWidgetMouseDoubleClickEvent(QMouseEvent *e)
{
  return QWidget::mouseDoubleClickEvent(e);
}

void Widget::QWidgetMouseMoveEvent(QMouseEvent *e)
{
  return QWidget::mouseMoveEvent(e);
}

void Widget::QWidgetMousePressEvent(QMouseEvent *e)
{
  return QWidget::mousePressEvent(e);
}

void Widget::QWidgetMouseReleaseEvent(QMouseEvent *e)
{
  return QWidget::mouseReleaseEvent(e);
}

void Widget::QWidgetMoveEvent(QMoveEvent *e)
{
  return QWidget::moveEvent(e);
}

void Widget::QWidgetPaintEvent(QPaintEvent *e)
{
  return QWidget::paintEvent(e);
}

void Widget::QWidgetResizeEvent(QResizeEvent *e)
{
  return QWidget::resizeEvent(e);
}

void Widget::QWidgetShowEvent(QShowEvent *e)
{
  return QWidget::showEvent(e);
}

void Widget::QWidgetWheelEvent(QWheelEvent *e)
{
  return QWidget::wheelEvent(e);
}

script::Value Widget::self() const
{
  return this->property("_yasl_data_").value<script::bind::BindingData>().value;
}

bool Widget::event(QEvent *e)
{
  if (mCallbacks.event.isNull())
    return QWidget::event(e);

  script::Engine *engine = mCallbacks.event.engine();
  script::Value val = make_event(e, script::make_type<QEvent>(), engine);
  script::Value ret = engine->invoke(mCallbacks.event, { self(), val });
  const bool result = ret.toBool();
  engine->destroy(ret);
  clear_event(val);
  engine->destroy(val);
  return result;
}

void Widget::closeEvent(QCloseEvent *e)
{
  if (mCallbacks.close.isNull())
    return QWidget::closeEvent(e);

  script::Engine *engine = mCallbacks.close.engine();
  script::Value val = make_event(e, script::make_type<QCloseEvent>(), engine);
  engine->invoke(mCallbacks.close, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::enterEvent(QEvent *e)
{
  if (mCallbacks.enter.isNull())
    return QWidget::enterEvent(e);

  script::Engine *engine = mCallbacks.enter.engine();
  script::Value val = make_event(e, script::make_type<QEvent>(), engine);
  engine->invoke(mCallbacks.enter, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::hideEvent(QHideEvent *e)
{
  if (mCallbacks.hide.isNull())
    return QWidget::hideEvent(e);

  script::Engine *engine = mCallbacks.hide.engine();
  script::Value val = make_event(e, script::make_type<QHideEvent>(), engine);
  engine->invoke(mCallbacks.hide, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
  if (mCallbacks.keyPress.isNull())
    return QWidget::keyPressEvent(e);

  script::Engine *engine = mCallbacks.keyPress.engine();
  script::Value val = make_event(e, script::make_type<QKeyEvent>(), engine);
  engine->invoke(mCallbacks.keyPress, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
  if (mCallbacks.keyRelease.isNull())
    return QWidget::keyReleaseEvent(e);

  script::Engine *engine = mCallbacks.keyRelease.engine();
  script::Value val = make_event(e, script::make_type<QKeyEvent>(), engine);
  engine->invoke(mCallbacks.keyRelease, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::leaveEvent(QEvent *e)
{
  if (mCallbacks.leave.isNull())
    return QWidget::leaveEvent(e);

  script::Engine *engine = mCallbacks.leave.engine();
  script::Value val = make_event(e, script::make_type<QEvent>(), engine);
  engine->invoke(mCallbacks.leave, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseDoubleClick.isNull())
    return QWidget::mouseDoubleClickEvent(e);

  script::Engine *engine = mCallbacks.mouseDoubleClick.engine();
  script::Value val = make_event(e, script::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseDoubleClick, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseMove.isNull())
    return QWidget::mouseMoveEvent(e);

  script::Engine *engine = mCallbacks.mouseMove.engine();
  script::Value val = make_event(e, script::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseMove, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
  if (mCallbacks.mousePress.isNull())
    return QWidget::mousePressEvent(e);

  script::Engine *engine = mCallbacks.mousePress.engine();
  script::Value val = make_event(e, script::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mousePress, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseRelease.isNull())
    return QWidget::mouseReleaseEvent(e);

  script::Engine *engine = mCallbacks.mouseRelease.engine();
  script::Value val = make_event(e, script::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseRelease, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::moveEvent(QMoveEvent *e)
{
  if (mCallbacks.move.isNull())
    return QWidget::moveEvent(e);

  script::Engine *engine = mCallbacks.move.engine();
  script::Value val = make_event(e, script::make_type<QMoveEvent>(), engine);
  engine->invoke(mCallbacks.move, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::paintEvent(QPaintEvent *e)
{
  if (mCallbacks.paint.isNull())
    return QWidget::paintEvent(e);

  script::Engine *engine = mCallbacks.paint.engine();
  script::Value val = make_event(e, script::make_type<QPaintEvent>(), engine);
  engine->invoke(mCallbacks.paint, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::resizeEvent(QResizeEvent *e)
{
  if (mCallbacks.resize.isNull())
    return QWidget::resizeEvent(e);

  script::Engine *engine = mCallbacks.resize.engine();
  script::Value val = make_event(e, script::make_type<QResizeEvent>(), engine);
  engine->invoke(mCallbacks.resize, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::showEvent(QShowEvent *e)
{
  if (mCallbacks.show.isNull())
    return QWidget::showEvent(e);

  script::Engine *engine = mCallbacks.show.engine();
  script::Value val = make_event(e, script::make_type<QShowEvent>(), engine);
  engine->invoke(mCallbacks.show, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::wheelEvent(QWheelEvent *e)
{
  if (mCallbacks.wheel.isNull())
    return QWidget::wheelEvent(e);

  script::Engine *engine = mCallbacks.wheel.engine();
  script::Value val = make_event(e, script::make_type<QWheelEvent>(), engine);
  engine->invoke(mCallbacks.wheel, { self(), val });
  clear_event(val);
  engine->destroy(val);
}
