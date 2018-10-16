// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractslider.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/abstractslider.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_abstract_slider_slider_action_enum(script::Class abstract_slider)
{
  using namespace script;

  Enum slider_action = abstract_slider.Enum("SliderAction").setId(script::Type::QAbstractSliderSliderAction).get();

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

  Class abstract_slider = ns.Class("AbstractSlider").setId(script::Type::QAbstractSlider)
    .setBase(script::Type::QWidget).get();

  register_abstract_slider_slider_action_enum(abstract_slider);
  binding::QClass<QAbstractSlider> binder{ abstract_slider, &QAbstractSlider::staticMetaObject };

  // QAbstractSlider(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // ~QAbstractSlider();
  binder.add_dtor();
  // Qt::Orientation orientation() const;
  binder.fun<Qt::Orientation, &QAbstractSlider::orientation>("orientation").create();
  // void setMinimum(int);
  binder.void_fun<int, &QAbstractSlider::setMinimum>("setMinimum").create();
  // int minimum() const;
  binder.fun<int, &QAbstractSlider::minimum>("minimum").create();
  // void setMaximum(int);
  binder.void_fun<int, &QAbstractSlider::setMaximum>("setMaximum").create();
  // int maximum() const;
  binder.fun<int, &QAbstractSlider::maximum>("maximum").create();
  // void setSingleStep(int);
  binder.void_fun<int, &QAbstractSlider::setSingleStep>("setSingleStep").create();
  // int singleStep() const;
  binder.fun<int, &QAbstractSlider::singleStep>("singleStep").create();
  // void setPageStep(int);
  binder.void_fun<int, &QAbstractSlider::setPageStep>("setPageStep").create();
  // int pageStep() const;
  binder.fun<int, &QAbstractSlider::pageStep>("pageStep").create();
  // void setTracking(bool);
  binder.void_fun<bool, &QAbstractSlider::setTracking>("setTracking").create();
  // bool hasTracking() const;
  binder.fun<bool, &QAbstractSlider::hasTracking>("hasTracking").create();
  // void setSliderDown(bool);
  binder.void_fun<bool, &QAbstractSlider::setSliderDown>("setSliderDown").create();
  // bool isSliderDown() const;
  binder.fun<bool, &QAbstractSlider::isSliderDown>("isSliderDown").create();
  // void setSliderPosition(int);
  binder.void_fun<int, &QAbstractSlider::setSliderPosition>("setSliderPosition").create();
  // int sliderPosition() const;
  binder.fun<int, &QAbstractSlider::sliderPosition>("sliderPosition").create();
  // void setInvertedAppearance(bool);
  binder.void_fun<bool, &QAbstractSlider::setInvertedAppearance>("setInvertedAppearance").create();
  // bool invertedAppearance() const;
  binder.fun<bool, &QAbstractSlider::invertedAppearance>("invertedAppearance").create();
  // void setInvertedControls(bool);
  binder.void_fun<bool, &QAbstractSlider::setInvertedControls>("setInvertedControls").create();
  // bool invertedControls() const;
  binder.fun<bool, &QAbstractSlider::invertedControls>("invertedControls").create();
  // int value() const;
  binder.fun<int, &QAbstractSlider::value>("value").create();
  // void triggerAction(QAbstractSlider::SliderAction);
  binder.void_fun<QAbstractSlider::SliderAction, &QAbstractSlider::triggerAction>("triggerAction").create();
  // void setValue(int);
  binder.void_fun<int, &QAbstractSlider::setValue>("setValue").create();
  // void setOrientation(Qt::Orientation);
  binder.void_fun<Qt::Orientation, &QAbstractSlider::setOrientation>("setOrientation").create();
  // void setRange(int, int);
  binder.void_fun<int, int, &QAbstractSlider::setRange>("setRange").create();
  // void valueChanged(int);
  binder.sigs().add<int>("valueChanged", "valueChanged(int)");
  // void sliderPressed();
  binder.sigs().add("sliderPressed", "sliderPressed()");
  // void sliderMoved(int);
  binder.sigs().add<int>("sliderMoved", "sliderMoved(int)");
  // void sliderReleased();
  binder.sigs().add("sliderReleased", "sliderReleased()");
  // void rangeChanged(int, int);
  binder.sigs().add<int, int>("rangeChanged", "rangeChanged(int,int)");
  // void actionTriggered(int);
  binder.sigs().add<int>("actionTriggered", "actionTriggered(int)");

  abstract_slider.engine()->registerQtType(&QAbstractSlider::staticMetaObject, abstract_slider.id());
}


void register_abstractslider_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_slider_class(ns);
  binding::Namespace binder{ ns };

}

