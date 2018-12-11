// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/slider.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/slider.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_slider_tick_position_enum(script::Class slider)
{
  using namespace script;

  Enum tick_position = slider.newEnum("TickPosition").setId(script::Type::QSliderTickPosition).get();

  tick_position.addValue("NoTicks", QSlider::NoTicks);
  tick_position.addValue("TicksAbove", QSlider::TicksAbove);
  tick_position.addValue("TicksLeft", QSlider::TicksLeft);
  tick_position.addValue("TicksBelow", QSlider::TicksBelow);
  tick_position.addValue("TicksRight", QSlider::TicksRight);
  tick_position.addValue("TicksBothSides", QSlider::TicksBothSides);
}


static void register_slider_class(script::Namespace ns)
{
  using namespace script;

  Class slider = ns.newClass("Slider").setId(script::Type::QSlider)
    .setBase(script::Type::QAbstractSlider).get();

  register_slider_tick_position_enum(slider);

  // QSlider(QWidget * = (QWidget*)nullptr);
  bind::constructor<QSlider, QWidget *>(slider)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QSlider(Qt::Orientation, QWidget *);
  bind::constructor<QSlider, Qt::Orientation, QWidget *>(slider).create();
  // ~QSlider();
  bind::destructor<QSlider>(slider).create();
  // void setTickPosition(QSlider::TickPosition);
  bind::void_member_function<QSlider, QSlider::TickPosition, &QSlider::setTickPosition>(slider, "setTickPosition").create();
  // QSlider::TickPosition tickPosition() const;
  bind::member_function<QSlider, QSlider::TickPosition, &QSlider::tickPosition>(slider, "tickPosition").create();
  // void setTickInterval(int);
  bind::void_member_function<QSlider, int, &QSlider::setTickInterval>(slider, "setTickInterval").create();
  // int tickInterval() const;
  bind::member_function<QSlider, int, &QSlider::tickInterval>(slider, "tickInterval").create();

  bind::link(slider, &QSlider::staticMetaObject);
}


void register_slider_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_slider_class(ns);

  // QSlider& newSlider(QWidget*);
  bind::new_function<QSlider, QWidget*>(ns, "newSlider");
  // QSlider& newSlider(Qt::Orientation, QWidget*);
  bind::new_function<QSlider, Qt::Orientation, QWidget*>(ns, "newSlider");
}
