// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/boxlayout.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "boxlayout.inc"
#include "yasl/core/enums.h"
#include "yasl/widgets/boxlayout.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_box_layout_direction_enum(script::Class box_layout)
{
  using namespace script;

  Enum direction = box_layout.Enum("Direction").setId(script::Type::QBoxLayoutDirection).get();

  direction.addValue("LeftToRight", QBoxLayout::LeftToRight);
  direction.addValue("RightToLeft", QBoxLayout::RightToLeft);
  direction.addValue("TopToBottom", QBoxLayout::TopToBottom);
  direction.addValue("BottomToTop", QBoxLayout::BottomToTop);
  direction.addValue("Down", QBoxLayout::Down);
  direction.addValue("Up", QBoxLayout::Up);
}


static void register_box_layout_class(script::Namespace ns)
{
  using namespace script;

  Class box_layout = ns.Class("BoxLayout").setId(script::Type::QBoxLayout)
    .setBase(script::Type::QLayout).get();

  register_box_layout_direction_enum(box_layout);
  binding::QClass<QBoxLayout> binder{ box_layout, &QBoxLayout::staticMetaObject };

  // QBoxLayout(QBoxLayout::Direction, QWidget *);
  binder.ctors().ctor<QBoxLayout::Direction, QWidget *>()
    .addDefaultArgument(binding::default_argument(box_layout.engine(), (QWidget*)nullptr)).create();
  // ~QBoxLayout();
  binder.add_dtor();
  // QBoxLayout::Direction direction() const;
  binder.fun<QBoxLayout::Direction, &QBoxLayout::direction>("direction").create();
  // void setDirection(QBoxLayout::Direction);
  binder.void_fun<QBoxLayout::Direction, &QBoxLayout::setDirection>("setDirection").create();
  // void addSpacing(int);
  binder.void_fun<int, &QBoxLayout::addSpacing>("addSpacing").create();
  // void addStretch(int);
  binder.void_fun<int, &QBoxLayout::addStretch>("addStretch")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void addSpacerItem(QSpacerItem *);
  /// TODO: void addSpacerItem(QSpacerItem *);
  // void addWidget(QWidget *, int, Qt::Alignment);
  binder.void_fun<QWidget *, int, Qt::Alignment, &QBoxLayout::addWidget>("addWidget")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), Qt::Alignment()))
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void addLayout(QLayout *, int);
  binder.void_fun<QLayout *, int, &QBoxLayout::addLayout>("addLayout")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void addStrut(int);
  binder.void_fun<int, &QBoxLayout::addStrut>("addStrut").create();
  // void insertSpacing(int, int);
  binder.void_fun<int, int, &QBoxLayout::insertSpacing>("insertSpacing").create();
  // void insertStretch(int, int);
  binder.void_fun<int, int, &QBoxLayout::insertStretch>("insertStretch")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void insertSpacerItem(int, QSpacerItem *);
  /// TODO: void insertSpacerItem(int, QSpacerItem *);
  // void insertWidget(int, QWidget *, int, Qt::Alignment);
  binder.void_fun<int, QWidget *, int, Qt::Alignment, &QBoxLayout::insertWidget>("insertWidget")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), Qt::Alignment()))
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void insertLayout(int, QLayout *, int);
  binder.void_fun<int, QLayout *, int, &QBoxLayout::insertLayout>("insertLayout")
    .addDefaultArgument(binding::default_argument(box_layout.engine(), 0)).create();
  // void insertItem(int, QLayoutItem *);
  /// TODO: void insertItem(int, QLayoutItem *);
  // int spacing() const;
  binder.fun<int, &QBoxLayout::spacing>("spacing").create();
  // void setSpacing(int);
  binder.void_fun<int, &QBoxLayout::setSpacing>("setSpacing").create();
  // bool setStretchFactor(QWidget *, int);
  binder.fun<bool, QWidget *, int, &QBoxLayout::setStretchFactor>("setStretchFactor").create();
  // bool setStretchFactor(QLayout *, int);
  binder.fun<bool, QLayout *, int, &QBoxLayout::setStretchFactor>("setStretchFactor").create();
  // void setStretch(int, int);
  binder.void_fun<int, int, &QBoxLayout::setStretch>("setStretch").create();
  // int stretch(int) const;
  binder.fun<int, int, &QBoxLayout::stretch>("stretch").create();

  box_layout.engine()->registerQtType(&QBoxLayout::staticMetaObject, box_layout.id());
}


static void register_h_box_layout_class(script::Namespace ns)
{
  using namespace script;

  Class h_box_layout = ns.Class("QHBoxLayout").setId(script::Type::QHBoxLayout)
    .setBase(script::Type::QBoxLayout).get();

  binding::QClass<QHBoxLayout> binder{ h_box_layout, &QHBoxLayout::staticMetaObject };

  // QHBoxLayout();
  binder.ctors().add_default();
  // QHBoxLayout(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // ~QHBoxLayout();
  binder.add_dtor();

  h_box_layout.engine()->registerQtType(&QHBoxLayout::staticMetaObject, h_box_layout.id());
}


static void register_v_box_layout_class(script::Namespace ns)
{
  using namespace script;

  Class v_box_layout = ns.Class("QVBoxLayout").setId(script::Type::QVBoxLayout)
    .setBase(script::Type::QBoxLayout).get();

  binding::QClass<QVBoxLayout> binder{ v_box_layout, &QVBoxLayout::staticMetaObject };

  // QVBoxLayout();
  binder.ctors().add_default();
  // QVBoxLayout(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // ~QVBoxLayout();
  binder.add_dtor();

  v_box_layout.engine()->registerQtType(&QVBoxLayout::staticMetaObject, v_box_layout.id());
}


void register_boxlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_box_layout_class(ns);
  register_h_box_layout_class(ns);
  register_v_box_layout_class(ns);
  binding::Namespace binder{ ns };

  register_newlayout_functions(widgets);
  // QHBoxLayout& newHBoxLayout();
  NewFunction(binder).add<QHBoxLayout>("newHBoxLayout");
  // QHBoxLayout& newHBoxLayout(QWidget*);
  NewFunction(binder).add<QHBoxLayout, QWidget*>("newHBoxLayout");
  // QVBoxLayout& newVBoxLayout();
  NewFunction(binder).add<QVBoxLayout>("newVBoxLayout");
  // QVBoxLayout& newVBoxLayout(QWidget*);
  NewFunction(binder).add<QVBoxLayout, QWidget*>("newVBoxLayout");
}

