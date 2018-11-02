// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/slider.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/slider.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_slider_tick_position_enum(script::Class slider)
{
  using namespace script;

  Enum tick_position = slider.Enum("TickPosition").setId(script::Type::QSliderTickPosition).get();

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

  Class slider = ns.Class("Slider").setId(script::Type::QSlider)
    .setBase(script::Type::QAbstractSlider).get();

  register_slider_tick_position_enum(slider);
  binding::QClass<QSlider> binder{ slider, &QSlider::staticMetaObject };

  // QSlider(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QSlider(Qt::Orientation, QWidget *);
  binder.ctors().ctor<Qt::Orientation, QWidget *>().create();
  // ~QSlider();
  binder.add_dtor();
  // void setTickPosition(QSlider::TickPosition);
  binder.void_fun<QSlider::TickPosition, &QSlider::setTickPosition>("setTickPosition").create();
  // QSlider::TickPosition tickPosition() const;
  binder.fun<QSlider::TickPosition, &QSlider::tickPosition>("tickPosition").create();
  // void setTickInterval(int);
  binder.void_fun<int, &QSlider::setTickInterval>("setTickInterval").create();
  // int tickInterval() const;
  binder.fun<int, &QSlider::tickInterval>("tickInterval").create();

  slider.engine()->registerQtType(&QSlider::staticMetaObject, slider.id());
}


void register_slider_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_slider_class(ns);
  binding::Namespace binder{ ns };

  // QSlider& newSlider(QWidget*);
  NewFunction(binder).add<QSlider, QWidget*>("newSlider");
  // QSlider& newSlider(Qt::Orientation, QWidget*);
  NewFunction(binder).add<QSlider, Qt::Orientation, QWidget*>("newSlider");
}

