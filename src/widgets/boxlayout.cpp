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

  Enum direction = box_layout.newEnum("Direction").setId(script::Type::QBoxLayoutDirection).get();

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

  Class box_layout = ns.newClass("BoxLayout").setId(script::Type::QBoxLayout)
    .setBase(script::Type::QLayout).get();

  register_box_layout_direction_enum(box_layout);

  // QBoxLayout(QBoxLayout::Direction, QWidget *);
  bind::constructor<QBoxLayout, QBoxLayout::Direction, QWidget *>(box_layout)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QBoxLayout();
  bind::destructor<QBoxLayout>(box_layout).create();
  // QBoxLayout::Direction direction() const;
  bind::member_function<QBoxLayout, QBoxLayout::Direction, &QBoxLayout::direction>(box_layout, "direction").create();
  // void setDirection(QBoxLayout::Direction);
  bind::void_member_function<QBoxLayout, QBoxLayout::Direction, &QBoxLayout::setDirection>(box_layout, "setDirection").create();
  // void addSpacing(int);
  bind::void_member_function<QBoxLayout, int, &QBoxLayout::addSpacing>(box_layout, "addSpacing").create();
  // void addStretch(int);
  bind::void_member_function<QBoxLayout, int, &QBoxLayout::addStretch>(box_layout, "addStretch")
    .apply(bind::default_arguments(0)).create();
  // void addSpacerItem(QSpacerItem *);
  /// TODO: void addSpacerItem(QSpacerItem *);
  // void addWidget(QWidget *, int, Qt::Alignment);
  bind::void_member_function<QBoxLayout, QWidget *, int, Qt::Alignment, &QBoxLayout::addWidget>(box_layout, "addWidget")
    .apply(bind::default_arguments(Qt::Alignment(), 0)).create();
  // void addLayout(QLayout *, int);
  bind::void_member_function<QBoxLayout, QLayout *, int, &QBoxLayout::addLayout>(box_layout, "addLayout")
    .apply(bind::default_arguments(0)).create();
  // void addStrut(int);
  bind::void_member_function<QBoxLayout, int, &QBoxLayout::addStrut>(box_layout, "addStrut").create();
  // void insertSpacing(int, int);
  bind::void_member_function<QBoxLayout, int, int, &QBoxLayout::insertSpacing>(box_layout, "insertSpacing").create();
  // void insertStretch(int, int);
  bind::void_member_function<QBoxLayout, int, int, &QBoxLayout::insertStretch>(box_layout, "insertStretch")
    .apply(bind::default_arguments(0)).create();
  // void insertSpacerItem(int, QSpacerItem *);
  /// TODO: void insertSpacerItem(int, QSpacerItem *);
  // void insertWidget(int, QWidget *, int, Qt::Alignment);
  bind::void_member_function<QBoxLayout, int, QWidget *, int, Qt::Alignment, &QBoxLayout::insertWidget>(box_layout, "insertWidget")
    .apply(bind::default_arguments(Qt::Alignment(), 0)).create();
  // void insertLayout(int, QLayout *, int);
  bind::void_member_function<QBoxLayout, int, QLayout *, int, &QBoxLayout::insertLayout>(box_layout, "insertLayout")
    .apply(bind::default_arguments(0)).create();
  // void insertItem(int, QLayoutItem *);
  /// TODO: void insertItem(int, QLayoutItem *);
  // int spacing() const;
  bind::member_function<QBoxLayout, int, &QBoxLayout::spacing>(box_layout, "spacing").create();
  // void setSpacing(int);
  bind::void_member_function<QBoxLayout, int, &QBoxLayout::setSpacing>(box_layout, "setSpacing").create();
  // bool setStretchFactor(QWidget *, int);
  bind::member_function<QBoxLayout, bool, QWidget *, int, &QBoxLayout::setStretchFactor>(box_layout, "setStretchFactor").create();
  // bool setStretchFactor(QLayout *, int);
  bind::member_function<QBoxLayout, bool, QLayout *, int, &QBoxLayout::setStretchFactor>(box_layout, "setStretchFactor").create();
  // void setStretch(int, int);
  bind::void_member_function<QBoxLayout, int, int, &QBoxLayout::setStretch>(box_layout, "setStretch").create();
  // int stretch(int) const;
  bind::member_function<QBoxLayout, int, int, &QBoxLayout::stretch>(box_layout, "stretch").create();

  bind::link(box_layout, &QBoxLayout::staticMetaObject);
}


static void register_h_box_layout_class(script::Namespace ns)
{
  using namespace script;

  Class h_box_layout = ns.newClass("QHBoxLayout").setId(script::Type::QHBoxLayout)
    .setBase(script::Type::QBoxLayout).get();


  // QHBoxLayout();
  bind::default_constructor<QHBoxLayout>(h_box_layout).create();
  // QHBoxLayout(QWidget *);
  bind::constructor<QHBoxLayout, QWidget *>(h_box_layout).create();
  // ~QHBoxLayout();
  bind::destructor<QHBoxLayout>(h_box_layout).create();

  bind::link(h_box_layout, &QHBoxLayout::staticMetaObject);
}


static void register_v_box_layout_class(script::Namespace ns)
{
  using namespace script;

  Class v_box_layout = ns.newClass("QVBoxLayout").setId(script::Type::QVBoxLayout)
    .setBase(script::Type::QBoxLayout).get();


  // QVBoxLayout();
  bind::default_constructor<QVBoxLayout>(v_box_layout).create();
  // QVBoxLayout(QWidget *);
  bind::constructor<QVBoxLayout, QWidget *>(v_box_layout).create();
  // ~QVBoxLayout();
  bind::destructor<QVBoxLayout>(v_box_layout).create();

  bind::link(v_box_layout, &QVBoxLayout::staticMetaObject);
}


void register_boxlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_box_layout_class(ns);
  register_h_box_layout_class(ns);
  register_v_box_layout_class(ns);

  register_newlayout_functions(widgets);
  // QHBoxLayout& newHBoxLayout();
  bind::new_function<QHBoxLayout>(ns, "newHBoxLayout");
  // QHBoxLayout& newHBoxLayout(QWidget*);
  bind::new_function<QHBoxLayout, QWidget*>(ns, "newHBoxLayout");
  // QVBoxLayout& newVBoxLayout();
  bind::new_function<QVBoxLayout>(ns, "newVBoxLayout");
  // QVBoxLayout& newVBoxLayout(QWidget*);
  bind::new_function<QVBoxLayout, QWidget*>(ns, "newVBoxLayout");
}

