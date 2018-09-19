// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/slider.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
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
  binder.ctors().add<QWidget *>();
  // QSlider(Qt::Orientation, QWidget *);
  binder.ctors().add<Qt::Orientation, QWidget *>();
  // ~QSlider();
  binder.add_dtor();
  // void setTickPosition(QSlider::TickPosition);
  binder.add_void_fun<QSlider::TickPosition, &QSlider::setTickPosition>("setTickPosition");
  // QSlider::TickPosition tickPosition() const;
  binder.add_fun<QSlider::TickPosition, &QSlider::tickPosition>("tickPosition");
  // void setTickInterval(int);
  binder.add_void_fun<int, &QSlider::setTickInterval>("setTickInterval");
  // int tickInterval() const;
  binder.add_fun<int, &QSlider::tickInterval>("tickInterval");

  slider.engine()->registerQtType(&QSlider::staticMetaObject, slider.id());
}


void register_slider_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_slider_class(ns);
  binding::Namespace binder{ ns };

}

