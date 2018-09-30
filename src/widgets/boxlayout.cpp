// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/boxlayout.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

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
  binder.ctors().add<QBoxLayout::Direction, QWidget *>();
  // ~QBoxLayout();
  binder.add_dtor();
  // QBoxLayout::Direction direction() const;
  binder.add_fun<QBoxLayout::Direction, &QBoxLayout::direction>("direction");
  // void setDirection(QBoxLayout::Direction);
  binder.add_void_fun<QBoxLayout::Direction, &QBoxLayout::setDirection>("setDirection");
  // void addSpacing(int);
  binder.add_void_fun<int, &QBoxLayout::addSpacing>("addSpacing");
  // void addStretch(int);
  binder.add_void_fun<int, &QBoxLayout::addStretch>("addStretch");
  // void addSpacerItem(QSpacerItem *);
  /// TODO: void addSpacerItem(QSpacerItem *);
  // void addWidget(QWidget *, int, Qt::Alignment);
  binder.add_void_fun<QWidget *, int, Qt::Alignment, &QBoxLayout::addWidget>("addWidget");
  // void addLayout(QLayout *, int);
  binder.add_void_fun<QLayout *, int, &QBoxLayout::addLayout>("addLayout");
  // void addStrut(int);
  binder.add_void_fun<int, &QBoxLayout::addStrut>("addStrut");
  // void insertSpacing(int, int);
  binder.add_void_fun<int, int, &QBoxLayout::insertSpacing>("insertSpacing");
  // void insertStretch(int, int);
  binder.add_void_fun<int, int, &QBoxLayout::insertStretch>("insertStretch");
  // void insertSpacerItem(int, QSpacerItem *);
  /// TODO: void insertSpacerItem(int, QSpacerItem *);
  // void insertWidget(int, QWidget *, int, Qt::Alignment);
  binder.add_void_fun<int, QWidget *, int, Qt::Alignment, &QBoxLayout::insertWidget>("insertWidget");
  // void insertLayout(int, QLayout *, int);
  binder.add_void_fun<int, QLayout *, int, &QBoxLayout::insertLayout>("insertLayout");
  // void insertItem(int, QLayoutItem *);
  /// TODO: void insertItem(int, QLayoutItem *);
  // int spacing() const;
  binder.add_fun<int, &QBoxLayout::spacing>("spacing");
  // void setSpacing(int);
  binder.add_void_fun<int, &QBoxLayout::setSpacing>("setSpacing");
  // bool setStretchFactor(QWidget *, int);
  binder.add_fun<bool, QWidget *, int, &QBoxLayout::setStretchFactor>("setStretchFactor");
  // bool setStretchFactor(QLayout *, int);
  binder.add_fun<bool, QLayout *, int, &QBoxLayout::setStretchFactor>("setStretchFactor");
  // void setStretch(int, int);
  binder.add_void_fun<int, int, &QBoxLayout::setStretch>("setStretch");
  // int stretch(int) const;
  binder.add_fun<int, int, &QBoxLayout::stretch>("stretch");

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
  binder.ctors().add<QWidget *>();
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
  binder.ctors().add<QWidget *>();
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

}

