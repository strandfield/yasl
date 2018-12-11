// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/gridlayout.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_grid_layout_class(script::Namespace ns)
{
  using namespace script;

  Class grid_layout = ns.newClass("GridLayout").setId(script::Type::QGridLayout)
    .setBase(script::Type::QLayout).get();


  // QGridLayout(QWidget *);
  bind::constructor<QGridLayout, QWidget *>(grid_layout).create();
  // QGridLayout();
  bind::default_constructor<QGridLayout>(grid_layout).create();
  // ~QGridLayout();
  bind::destructor<QGridLayout>(grid_layout).create();
  // void setHorizontalSpacing(int);
  bind::void_member_function<QGridLayout, int, &QGridLayout::setHorizontalSpacing>(grid_layout, "setHorizontalSpacing").create();
  // int horizontalSpacing() const;
  bind::member_function<QGridLayout, int, &QGridLayout::horizontalSpacing>(grid_layout, "horizontalSpacing").create();
  // void setVerticalSpacing(int);
  bind::void_member_function<QGridLayout, int, &QGridLayout::setVerticalSpacing>(grid_layout, "setVerticalSpacing").create();
  // int verticalSpacing() const;
  bind::member_function<QGridLayout, int, &QGridLayout::verticalSpacing>(grid_layout, "verticalSpacing").create();
  // void setSpacing(int);
  bind::void_member_function<QGridLayout, int, &QGridLayout::setSpacing>(grid_layout, "setSpacing").create();
  // int spacing() const;
  bind::member_function<QGridLayout, int, &QGridLayout::spacing>(grid_layout, "spacing").create();
  // void setRowStretch(int, int);
  bind::void_member_function<QGridLayout, int, int, &QGridLayout::setRowStretch>(grid_layout, "setRowStretch").create();
  // void setColumnStretch(int, int);
  bind::void_member_function<QGridLayout, int, int, &QGridLayout::setColumnStretch>(grid_layout, "setColumnStretch").create();
  // int rowStretch(int) const;
  bind::member_function<QGridLayout, int, int, &QGridLayout::rowStretch>(grid_layout, "rowStretch").create();
  // int columnStretch(int) const;
  bind::member_function<QGridLayout, int, int, &QGridLayout::columnStretch>(grid_layout, "columnStretch").create();
  // void setRowMinimumHeight(int, int);
  bind::void_member_function<QGridLayout, int, int, &QGridLayout::setRowMinimumHeight>(grid_layout, "setRowMinimumHeight").create();
  // void setColumnMinimumWidth(int, int);
  bind::void_member_function<QGridLayout, int, int, &QGridLayout::setColumnMinimumWidth>(grid_layout, "setColumnMinimumWidth").create();
  // int rowMinimumHeight(int) const;
  bind::member_function<QGridLayout, int, int, &QGridLayout::rowMinimumHeight>(grid_layout, "rowMinimumHeight").create();
  // int columnMinimumWidth(int) const;
  bind::member_function<QGridLayout, int, int, &QGridLayout::columnMinimumWidth>(grid_layout, "columnMinimumWidth").create();
  // int columnCount() const;
  bind::member_function<QGridLayout, int, &QGridLayout::columnCount>(grid_layout, "columnCount").create();
  // int rowCount() const;
  bind::member_function<QGridLayout, int, &QGridLayout::rowCount>(grid_layout, "rowCount").create();
  // QRect cellRect(int, int) const;
  bind::member_function<QGridLayout, QRect, int, int, &QGridLayout::cellRect>(grid_layout, "cellRect").create();
  // void addWidget(QWidget *);
  bind::void_member_function<QGridLayout, QWidget *, &QGridLayout::addWidget>(grid_layout, "addWidget").create();
  // void addWidget(QWidget *, int, int, Qt::Alignment = Qt::Alignment());
  bind::void_member_function<QGridLayout, QWidget *, int, int, Qt::Alignment, &QGridLayout::addWidget>(grid_layout, "addWidget")
    .apply(bind::default_arguments(Qt::Alignment())).create();
  // void addLayout(QLayout *, int, int, Qt::Alignment = Qt::Alignment());
  bind::void_member_function<QGridLayout, QLayout *, int, int, Qt::Alignment, &QGridLayout::addLayout>(grid_layout, "addLayout")
    .apply(bind::default_arguments(Qt::Alignment())).create();
  // void setOriginCorner(Qt::Corner);
  bind::void_member_function<QGridLayout, Qt::Corner, &QGridLayout::setOriginCorner>(grid_layout, "setOriginCorner").create();
  // Qt::Corner originCorner() const;
  bind::member_function<QGridLayout, Qt::Corner, &QGridLayout::originCorner>(grid_layout, "originCorner").create();
  // QLayoutItem * itemAtPosition(int, int) const;
  /// TODO: QLayoutItem * itemAtPosition(int, int) const;
  // void setGeometry(const QRect &);
  bind::void_member_function<QGridLayout, const QRect &, &QGridLayout::setGeometry>(grid_layout, "setGeometry").create();
  // void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  /// TODO: void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  // void setDefaultPositioning(int, Qt::Orientation);
  bind::void_member_function<QGridLayout, int, Qt::Orientation, &QGridLayout::setDefaultPositioning>(grid_layout, "setDefaultPositioning").create();
  // void getItemPosition(int, int *, int *, int *, int *) const;
  /// TODO: void getItemPosition(int, int *, int *, int *, int *) const;

  bind::link(grid_layout, &QGridLayout::staticMetaObject);
}


void register_gridlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_grid_layout_class(ns);

  // QGridLayout& newGridLayout(QWidget*);
  bind::new_function<QGridLayout, QWidget*>(ns, "newGridLayout");
  // QGridLayout& newGridLayout();
  bind::new_function<QGridLayout>(ns, "newGridLayout");
}
