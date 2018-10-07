// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/gridlayout.h"

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
  binder.ctors().add<QWidget *>();
  // QGridLayout();
  binder.ctors().add_default();
  // ~QGridLayout();
  binder.add_dtor();
  // void setHorizontalSpacing(int);
  binder.add_void_fun<int, &QGridLayout::setHorizontalSpacing>("setHorizontalSpacing");
  // int horizontalSpacing() const;
  binder.add_fun<int, &QGridLayout::horizontalSpacing>("horizontalSpacing");
  // void setVerticalSpacing(int);
  binder.add_void_fun<int, &QGridLayout::setVerticalSpacing>("setVerticalSpacing");
  // int verticalSpacing() const;
  binder.add_fun<int, &QGridLayout::verticalSpacing>("verticalSpacing");
  // void setSpacing(int);
  binder.add_void_fun<int, &QGridLayout::setSpacing>("setSpacing");
  // int spacing() const;
  binder.add_fun<int, &QGridLayout::spacing>("spacing");
  // void setRowStretch(int, int);
  binder.add_void_fun<int, int, &QGridLayout::setRowStretch>("setRowStretch");
  // void setColumnStretch(int, int);
  binder.add_void_fun<int, int, &QGridLayout::setColumnStretch>("setColumnStretch");
  // int rowStretch(int) const;
  binder.add_fun<int, int, &QGridLayout::rowStretch>("rowStretch");
  // int columnStretch(int) const;
  binder.add_fun<int, int, &QGridLayout::columnStretch>("columnStretch");
  // void setRowMinimumHeight(int, int);
  binder.add_void_fun<int, int, &QGridLayout::setRowMinimumHeight>("setRowMinimumHeight");
  // void setColumnMinimumWidth(int, int);
  binder.add_void_fun<int, int, &QGridLayout::setColumnMinimumWidth>("setColumnMinimumWidth");
  // int rowMinimumHeight(int) const;
  binder.add_fun<int, int, &QGridLayout::rowMinimumHeight>("rowMinimumHeight");
  // int columnMinimumWidth(int) const;
  binder.add_fun<int, int, &QGridLayout::columnMinimumWidth>("columnMinimumWidth");
  // int columnCount() const;
  binder.add_fun<int, &QGridLayout::columnCount>("columnCount");
  // int rowCount() const;
  binder.add_fun<int, &QGridLayout::rowCount>("rowCount");
  // QRect cellRect(int, int) const;
  binder.add_fun<QRect, int, int, &QGridLayout::cellRect>("cellRect");
  // void addWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QGridLayout::addWidget>("addWidget");
  // void addWidget(QWidget *, int, int, Qt::Alignment);
  binder.add_void_fun<QWidget *, int, int, Qt::Alignment, &QGridLayout::addWidget>("addWidget");
  // void addLayout(QLayout *, int, int, Qt::Alignment);
  binder.add_void_fun<QLayout *, int, int, Qt::Alignment, &QGridLayout::addLayout>("addLayout");
  // void setOriginCorner(Qt::Corner);
  binder.add_void_fun<Qt::Corner, &QGridLayout::setOriginCorner>("setOriginCorner");
  // Qt::Corner originCorner() const;
  binder.add_fun<Qt::Corner, &QGridLayout::originCorner>("originCorner");
  // QLayoutItem * itemAtPosition(int, int) const;
  /// TODO: QLayoutItem * itemAtPosition(int, int) const;
  // void setGeometry(const QRect &);
  binder.add_void_fun<const QRect &, &QGridLayout::setGeometry>("setGeometry");
  // void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  /// TODO: void addItem(QLayoutItem *, int, int, int, int, Qt::Alignment);
  // void setDefaultPositioning(int, Qt::Orientation);
  binder.add_void_fun<int, Qt::Orientation, &QGridLayout::setDefaultPositioning>("setDefaultPositioning");
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

