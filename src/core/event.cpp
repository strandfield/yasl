// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/event.h"

#include "yasl/binding/class.h"

#include <script/interpreter/executioncontext.h>

namespace callbacks
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QEvent(binding::value_cast<QEvent::Type>(c->arg(0)));
  return self;
}

static script::Value dtor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  if (self.impl()->data.ptr != nullptr)
  {
    delete static_cast<QEvent*>(self.impl()->data.ptr);
    self.impl()->data.ptr = nullptr;
  }

  return script::Value::Void;
}

} // namespace callbacks


void register_qevent(script::Namespace root)
{
  using namespace script;

  Class event = root.newClass(ClassBuilder::New("Event").setId(Type::QEvent));
  
  Enum type = event.newEnum("Type", Type::QEventType);

  type.addValue("None", QEvent::None);
  type.addValue("Timer", QEvent::Timer);
  type.addValue("MouseButtonPress", QEvent::MouseButtonPress);
  type.addValue("MouseButtonRelease", QEvent::MouseButtonRelease);
  type.addValue("MouseButtonDblClick", QEvent::MouseButtonDblClick);
  type.addValue("MouseMove", QEvent::MouseMove);
  type.addValue("KeyPress", QEvent::KeyPress);
  type.addValue("KeyRelease", QEvent::KeyRelease);
  type.addValue("FocusIn", QEvent::FocusIn);
  type.addValue("FocusOut", QEvent::FocusOut);
  type.addValue("FocusAboutToChange", QEvent::FocusAboutToChange);
  type.addValue("Enter", QEvent::Enter);
  type.addValue("Leave", QEvent::Leave);
  type.addValue("Paint", QEvent::Paint);
  type.addValue("Move", QEvent::Move);
  type.addValue("Resize", QEvent::Resize);
  type.addValue("Create", QEvent::Create);
  type.addValue("Destroy", QEvent::Destroy);
  type.addValue("Show", QEvent::Show);
  type.addValue("Hide", QEvent::Hide);
  type.addValue("Close", QEvent::Close);
  type.addValue("Quit", QEvent::Quit);
  type.addValue("ParentChange", QEvent::ParentChange);
  type.addValue("ParentAboutToChange", QEvent::ParentAboutToChange);
  type.addValue("ThreadChange", QEvent::ThreadChange);
  type.addValue("WindowActivate", QEvent::WindowActivate);
  type.addValue("WindowDeactivate", QEvent::WindowDeactivate);
  type.addValue("ShowToParent", QEvent::ShowToParent);
  type.addValue("HideToParent", QEvent::HideToParent);
  type.addValue("Wheel", QEvent::Wheel);
  type.addValue("WindowTitleChange", QEvent::WindowTitleChange);
  type.addValue("WindowIconChange", QEvent::WindowIconChange);
  type.addValue("DragEnter", QEvent::DragEnter);
  type.addValue("DragMove", QEvent::DragMove);
  type.addValue("DragLeave", QEvent::DragLeave);
  type.addValue("Drop", QEvent::Drop);
  type.addValue("DragResponse", QEvent::DragResponse);
  type.addValue("ChildAdded", QEvent::ChildAdded);
  type.addValue("ChildPolished", QEvent::ChildPolished);
  type.addValue("ChildRemoved", QEvent::ChildRemoved);
  // for now that will do...
   
  binding::Class<QEvent> qevent{ event };
  // QEvent(QEvent::Type);
  event.Constructor(callbacks::ctor).params(Type{ Type::QEventType }).create();
  // ~QEvent();
  event.newDestructor(callbacks::dtor);
  // void accept();
  qevent.add_void_fun<&QEvent::accept>("accept");
  // void ignore();
  qevent.add_void_fun<&QEvent::ignore>("ignore");
  // bool isAccepted() const;
  qevent.add_fun<bool, &QEvent::isAccepted>("isAccepted");
  // void setAccepted(bool);
  qevent.add_void_fun<bool, &QEvent::setAccepted>("setAccepted");
  // bool spontaneous() const;
  qevent.add_fun<bool, &QEvent::spontaneous>("spontaneous");
  // QEvent::Type type() const;
  qevent.add_fun<QEvent::Type, &QEvent::type>("type");
}

script::Value make_event(QEvent *event, script::Engine *engine)
{
  return make_event(event, script::Type::QEvent, engine);
}

script::Value make_event(QEvent *event, const script::Type & event_type, script::Engine *engine)
{
  using namespace script;

  Value ret = engine->uninitialized(event_type);
  ret.impl()->data.ptr = event;
  ret.impl()->type = ret.impl()->type.withoutFlag(Type::UninitializedFlag);
  return ret;
}

void clear_event(script::Value & value)
{
  value.impl()->data.ptr = nullptr;
}

QEvent * get_event(const script::Value & val)
{
  return static_cast<QEvent*>(val.impl()->data.ptr);
}
