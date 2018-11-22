// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractslider.h"

#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/abstractslider.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_abstract_slider_slider_action_enum(script::Class abstract_slider)
{
  using namespace script;

  Enum slider_action = abstract_slider.newEnum("SliderAction").setId(script::Type::QAbstractSliderSliderAction).get();

  slider_action.addValue("SliderNoAction", QAbstractSlider::SliderNoAction);
  slider_action.addValue("SliderSingleStepAdd", QAbstractSlider::SliderSingleStepAdd);
  slider_action.addValue("SliderSingleStepSub", QAbstractSlider::SliderSingleStepSub);
  slider_action.addValue("SliderPageStepAdd", QAbstractSlider::SliderPageStepAdd);
  slider_action.addValue("SliderPageStepSub", QAbstractSlider::SliderPageStepSub);
  slider_action.addValue("SliderToMinimum", QAbstractSlider::SliderToMinimum);
  slider_action.addValue("SliderToMaximum", QAbstractSlider::SliderToMaximum);
  slider_action.addValue("SliderMove", QAbstractSlider::SliderMove);
}


static void register_abstract_slider_class(script::Namespace ns)
{
  using namespace script;

  Class abstract_slider = ns.newClass("AbstractSlider").setId(script::Type::QAbstractSlider)
    .setBase(script::Type::QWidget).get();

  register_abstract_slider_slider_action_enum(abstract_slider);

  // QAbstractSlider(QWidget *);
  bind::constructor<QAbstractSlider, QWidget *>(abstract_slider)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QAbstractSlider();
  bind::destructor<QAbstractSlider>(abstract_slider).create();
  // Qt::Orientation orientation() const;
  bind::member_function<QAbstractSlider, Qt::Orientation, &QAbstractSlider::orientation>(abstract_slider, "orientation").create();
  // void setMinimum(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setMinimum>(abstract_slider, "setMinimum").create();
  // int minimum() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::minimum>(abstract_slider, "minimum").create();
  // void setMaximum(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setMaximum>(abstract_slider, "setMaximum").create();
  // int maximum() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::maximum>(abstract_slider, "maximum").create();
  // void setSingleStep(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setSingleStep>(abstract_slider, "setSingleStep").create();
  // int singleStep() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::singleStep>(abstract_slider, "singleStep").create();
  // void setPageStep(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setPageStep>(abstract_slider, "setPageStep").create();
  // int pageStep() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::pageStep>(abstract_slider, "pageStep").create();
  // void setTracking(bool);
  bind::void_member_function<QAbstractSlider, bool, &QAbstractSlider::setTracking>(abstract_slider, "setTracking").create();
  // bool hasTracking() const;
  bind::member_function<QAbstractSlider, bool, &QAbstractSlider::hasTracking>(abstract_slider, "hasTracking").create();
  // void setSliderDown(bool);
  bind::void_member_function<QAbstractSlider, bool, &QAbstractSlider::setSliderDown>(abstract_slider, "setSliderDown").create();
  // bool isSliderDown() const;
  bind::member_function<QAbstractSlider, bool, &QAbstractSlider::isSliderDown>(abstract_slider, "isSliderDown").create();
  // void setSliderPosition(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setSliderPosition>(abstract_slider, "setSliderPosition").create();
  // int sliderPosition() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::sliderPosition>(abstract_slider, "sliderPosition").create();
  // void setInvertedAppearance(bool);
  bind::void_member_function<QAbstractSlider, bool, &QAbstractSlider::setInvertedAppearance>(abstract_slider, "setInvertedAppearance").create();
  // bool invertedAppearance() const;
  bind::member_function<QAbstractSlider, bool, &QAbstractSlider::invertedAppearance>(abstract_slider, "invertedAppearance").create();
  // void setInvertedControls(bool);
  bind::void_member_function<QAbstractSlider, bool, &QAbstractSlider::setInvertedControls>(abstract_slider, "setInvertedControls").create();
  // bool invertedControls() const;
  bind::member_function<QAbstractSlider, bool, &QAbstractSlider::invertedControls>(abstract_slider, "invertedControls").create();
  // int value() const;
  bind::member_function<QAbstractSlider, int, &QAbstractSlider::value>(abstract_slider, "value").create();
  // void triggerAction(QAbstractSlider::SliderAction);
  bind::void_member_function<QAbstractSlider, QAbstractSlider::SliderAction, &QAbstractSlider::triggerAction>(abstract_slider, "triggerAction").create();
  // void setValue(int);
  bind::void_member_function<QAbstractSlider, int, &QAbstractSlider::setValue>(abstract_slider, "setValue").create();
  // void setOrientation(Qt::Orientation);
  bind::void_member_function<QAbstractSlider, Qt::Orientation, &QAbstractSlider::setOrientation>(abstract_slider, "setOrientation").create();
  // void setRange(int, int);
  bind::void_member_function<QAbstractSlider, int, int, &QAbstractSlider::setRange>(abstract_slider, "setRange").create();
  // void valueChanged(int);
  bind::signal<QAbstractSlider, int>(abstract_slider, "valueChanged", "valueChanged(int)");
  // void sliderPressed();
  bind::signal<QAbstractSlider>(abstract_slider, "sliderPressed", "sliderPressed()");
  // void sliderMoved(int);
  bind::signal<QAbstractSlider, int>(abstract_slider, "sliderMoved", "sliderMoved(int)");
  // void sliderReleased();
  bind::signal<QAbstractSlider>(abstract_slider, "sliderReleased", "sliderReleased()");
  // void rangeChanged(int, int);
  bind::signal<QAbstractSlider, int, int>(abstract_slider, "rangeChanged", "rangeChanged(int,int)");
  // void actionTriggered(int);
  bind::signal<QAbstractSlider, int>(abstract_slider, "actionTriggered", "actionTriggered(int)");

  bind::link(abstract_slider, &QAbstractSlider::staticMetaObject);
}


void register_abstractslider_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_slider_class(ns);

}

