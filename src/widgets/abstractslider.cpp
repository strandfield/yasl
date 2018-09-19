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
  binder.ctors().add<QWidget *>();
  // ~QAbstractSlider();
  binder.add_dtor();
  // Qt::Orientation orientation() const;
  binder.add_fun<Qt::Orientation, &QAbstractSlider::orientation>("orientation");
  // void setMinimum(int);
  binder.add_void_fun<int, &QAbstractSlider::setMinimum>("setMinimum");
  // int minimum() const;
  binder.add_fun<int, &QAbstractSlider::minimum>("minimum");
  // void setMaximum(int);
  binder.add_void_fun<int, &QAbstractSlider::setMaximum>("setMaximum");
  // int maximum() const;
  binder.add_fun<int, &QAbstractSlider::maximum>("maximum");
  // void setSingleStep(int);
  binder.add_void_fun<int, &QAbstractSlider::setSingleStep>("setSingleStep");
  // int singleStep() const;
  binder.add_fun<int, &QAbstractSlider::singleStep>("singleStep");
  // void setPageStep(int);
  binder.add_void_fun<int, &QAbstractSlider::setPageStep>("setPageStep");
  // int pageStep() const;
  binder.add_fun<int, &QAbstractSlider::pageStep>("pageStep");
  // void setTracking(bool);
  binder.add_void_fun<bool, &QAbstractSlider::setTracking>("setTracking");
  // bool hasTracking() const;
  binder.add_fun<bool, &QAbstractSlider::hasTracking>("hasTracking");
  // void setSliderDown(bool);
  binder.add_void_fun<bool, &QAbstractSlider::setSliderDown>("setSliderDown");
  // bool isSliderDown() const;
  binder.add_fun<bool, &QAbstractSlider::isSliderDown>("isSliderDown");
  // void setSliderPosition(int);
  binder.add_void_fun<int, &QAbstractSlider::setSliderPosition>("setSliderPosition");
  // int sliderPosition() const;
  binder.add_fun<int, &QAbstractSlider::sliderPosition>("sliderPosition");
  // void setInvertedAppearance(bool);
  binder.add_void_fun<bool, &QAbstractSlider::setInvertedAppearance>("setInvertedAppearance");
  // bool invertedAppearance() const;
  binder.add_fun<bool, &QAbstractSlider::invertedAppearance>("invertedAppearance");
  // void setInvertedControls(bool);
  binder.add_void_fun<bool, &QAbstractSlider::setInvertedControls>("setInvertedControls");
  // bool invertedControls() const;
  binder.add_fun<bool, &QAbstractSlider::invertedControls>("invertedControls");
  // int value() const;
  binder.add_fun<int, &QAbstractSlider::value>("value");
  // void triggerAction(QAbstractSlider::SliderAction);
  binder.add_void_fun<QAbstractSlider::SliderAction, &QAbstractSlider::triggerAction>("triggerAction");
  // void setValue(int);
  binder.add_void_fun<int, &QAbstractSlider::setValue>("setValue");
  // void setOrientation(Qt::Orientation);
  binder.add_void_fun<Qt::Orientation, &QAbstractSlider::setOrientation>("setOrientation");
  // void setRange(int, int);
  binder.add_void_fun<int, int, &QAbstractSlider::setRange>("setRange");
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

