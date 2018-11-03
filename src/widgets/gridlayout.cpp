// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/gridlayout.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_grid_layout_class(script::Namespace ns)
{
  using namespace script;

  Class grid_layout = ns.Class("GridLayout").setId(script::Type::QGridLayout)
    .setBase(script::Type::QLayout).get();

  binding::QClass<QGridLayout> binder{ grid_layout, &QGridLayout::staticMetaObject };

  // QGridLayout(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // QGridLayout();
  binder.ctors().default_ctor().create();
  // ~QGridLayout();
  binder.add_dtor();
  // void setHorizontalSpacing(int);
  binder.void_fun<int, &QGridLayout::setHorizontalSpacing>("setHorizontalSpacing").create();
  // int horizontalSpacing() const;
  binder.fun<int, &QGridLayout::horizontalSpacing>("horizontalSpacing").create();
  // void setVerticalSpacing(int);
  binder.void_fun<int, &QGridLayout::setVerticalSpacing>("setVerticalSpacing").create();
  // int verticalSpacing() const;
  binder.fun<int, &QGridLayout::verticalSpacing>("verticalSpacing").create();
  // void setSpacing(int);
  binder.void_fun<int, &QGridLayout::setSpacing>("setSpacing").create();
  // int spacing() const;
  binder.fun<int, &QGridLayout::spacing>("spacing").create();
  // void setRowStretch(int, int);
  binder.void_fun<int, int, &QGridLayout::setRowStretch>("setRowStretch").create();
  // void setColumnStretch(int, int);
  binder.void_fun<int, int, &QGridLayout::setColumnStretch>("setColumnStretch").create();
  // int rowStretch(int) const;
  binder.fun<int, int, &QGridLayout::rowStretch>("rowStretch").create();
  // int columnStretch(int) const;
  binder.fun<int, int, &QGridLayout::columnStretch>("columnStretch").create();
  // void setRowMinimumHeight(int, int);
  binder.void_fun<int, int, &QGridLayout::setRowMinimumHeight>("setRowMinimumHeight").create();
  // void setColumnMinimumWidth(int, int);
  binder.void_fun<int, int, &QGridLayout::setColumnMinimumWidth>("setColumnMinimumWidth").create();
  // int rowMinimumHeight(int) const;
  binder.fun<int, int, &QGridLayout::rowMinimumHeight>("rowMinimumHeight").create();
  // int columnMinimumWidth(int) const;
  binder.fun<int, int, &QGridLayout::columnMinimumWidth>("columnMinimumWidth").create();
  // int columnCount() const;
  binder.fun<int, &QGridLayout::columnCount>("columnCount").create();
  // int rowCount() const;
  binder.fun<int, &QGridLayout::rowCount>("rowCount").create();
  // QRect cellRect(int, int) const;
  binder.fun<QRect, int, int, &QGridLayout::cellRect>("cellRect").create();
  // void addWidget(QWidget *);
  binder.void_fun<QWidget *, &QGridLayout::addWidget>("addWidget").create();
  // void addWidget(QWidget *, int, int, Qt::Alignment);
  binder.void_fun<QWidget *, int, int, Qt::Alignment, &QGridLayout::addWidget>("addWidget")
    .apply(binding::default_arguments(Qt::Alignment())).create();
  // void addLayout(QLayout *, int, int, Qt::Alignment);
  binder.void_fun<QLayout *, int, int, Qt::Alignment, &QGridLayout::addLayout>("addLayout")
    .apply(binding::default_arguments(Qt::Alignment())).create();
  // void setOriginCorner(Qt::Corner);
  binder.void_fun<Qt::Corner, &QGridLayout::setOriginCorner>("setOriginCorner").create();
  // Qt::Corner originCorner() const;
  binder.fun<Qt::Corner, &QGridLayout::originCorner>("originCorner").create();
  // QLayoutItem * itemAtPosition(int, int) const;
  /// TODO: QLayoutItem * itemAtPosition(int, int) const;
  // void setGeometry(const QRect &);
  binder.void_fun<const QRect &, &QGridLayout::setGeometry>("setGeometry").create();
  // void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  /// TODO: void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  // void setDefaultPositioning(int, Qt::Orientation);
  binder.void_fun<int, Qt::Orientation, &QGridLayout::setDefaultPositioning>("setDefaultPositioning").create();
  // void getItemPosition(int, int *, int *, int *, int *) const;
  /// TODO: void getItemPosition(int, int *, int *, int *, int *) const;

  grid_layout.engine()->registerQtType(&QGridLayout::staticMetaObject, grid_layout.id());
}


void register_gridlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_grid_layout_class(ns);
  binding::Namespace binder{ ns };

  // QGridLayout& newGridLayout(QWidget*);
  NewFunction(binder).add<QGridLayout, QWidget*>("newGridLayout");
  // QGridLayout& newGridLayout();
  NewFunction(binder).add<QGridLayout>("newGridLayout");
}

