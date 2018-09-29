// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/stackedlayout.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/stackedlayout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_stacked_layout_stacking_mode_enum(script::Class stacked_layout)
{
  using namespace script;

  Enum stacking_mode = stacked_layout.Enum("StackingMode").setId(script::Type::QStackedLayoutStackingMode).get();

  stacking_mode.addValue("StackOne", QStackedLayout::StackOne);
  stacking_mode.addValue("StackAll", QStackedLayout::StackAll);
}


static void register_stacked_layout_class(script::Namespace ns)
{
  using namespace script;

  Class stacked_layout = ns.Class("StackedLayout").setId(script::Type::QStackedLayout)
    .setBase(script::Type::QLayout).get();

  register_stacked_layout_stacking_mode_enum(stacked_layout);
  binding::QClass<QStackedLayout> binder{ stacked_layout, &QStackedLayout::staticMetaObject };

  // QStackedLayout();
  binder.ctors().add_default();
  // QStackedLayout(QWidget *);
  binder.ctors().add<QWidget *>();
  // QStackedLayout(QLayout *);
  binder.ctors().add<QLayout *>();
  // ~QStackedLayout();
  binder.add_dtor();
  // int addWidget(QWidget *);
  binder.add_fun<int, QWidget *, &QStackedLayout::addWidget>("addWidget");
  // int insertWidget(int, QWidget *);
  binder.add_fun<int, int, QWidget *, &QStackedLayout::insertWidget>("insertWidget");
  // QWidget * currentWidget() const;
  binder.add_fun<QWidget *, &QStackedLayout::currentWidget>("currentWidget");
  // int currentIndex() const;
  binder.add_fun<int, &QStackedLayout::currentIndex>("currentIndex");
  // QWidget * widget(int) const;
  binder.add_fun<QWidget *, int, &QStackedLayout::widget>("widget");
  // int count() const;
  binder.add_fun<int, &QStackedLayout::count>("count");
  // QStackedLayout::StackingMode stackingMode() const;
  binder.add_fun<QStackedLayout::StackingMode, &QStackedLayout::stackingMode>("stackingMode");
  // void setStackingMode(QStackedLayout::StackingMode);
  binder.add_void_fun<QStackedLayout::StackingMode, &QStackedLayout::setStackingMode>("setStackingMode");
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QStackedLayout::sizeHint>("sizeHint");
  // QSize minimumSize() const;
  binder.add_fun<QSize, &QStackedLayout::minimumSize>("minimumSize");
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // void setGeometry(const QRect &);
  binder.add_void_fun<const QRect &, &QStackedLayout::setGeometry>("setGeometry");
  // bool hasHeightForWidth() const;
  binder.add_fun<bool, &QStackedLayout::hasHeightForWidth>("hasHeightForWidth");
  // int heightForWidth(int) const;
  binder.add_fun<int, int, &QStackedLayout::heightForWidth>("heightForWidth");
  // void widgetRemoved(int);
  binder.add_void_fun<int, &QStackedLayout::widgetRemoved>("widgetRemoved");
  // void currentChanged(int);
  binder.add_void_fun<int, &QStackedLayout::currentChanged>("currentChanged");
  // void setCurrentIndex(int);
  binder.add_void_fun<int, &QStackedLayout::setCurrentIndex>("setCurrentIndex");
  // void setCurrentWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QStackedLayout::setCurrentWidget>("setCurrentWidget");

  stacked_layout.engine()->registerQtType(&QStackedLayout::staticMetaObject, stacked_layout.id());
}


void register_stackedlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_stacked_layout_class(ns);
  binding::Namespace binder{ ns };

}

