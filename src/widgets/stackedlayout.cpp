// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/stackedlayout.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

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

  Enum stacking_mode = stacked_layout.newEnum("StackingMode").setId(script::Type::QStackedLayoutStackingMode).get();

  stacking_mode.addValue("StackOne", QStackedLayout::StackOne);
  stacking_mode.addValue("StackAll", QStackedLayout::StackAll);
}


static void register_stacked_layout_class(script::Namespace ns)
{
  using namespace script;

  Class stacked_layout = ns.newClass("StackedLayout").setId(script::Type::QStackedLayout)
    .setBase(script::Type::QLayout).get();

  register_stacked_layout_stacking_mode_enum(stacked_layout);

  // QStackedLayout();
  bind::default_constructor<QStackedLayout>(stacked_layout).create();
  // QStackedLayout(QWidget *);
  bind::constructor<QStackedLayout, QWidget *>(stacked_layout).create();
  // QStackedLayout(QLayout *);
  bind::constructor<QStackedLayout, QLayout *>(stacked_layout).create();
  // ~QStackedLayout();
  bind::destructor<QStackedLayout>(stacked_layout).create();
  // int addWidget(QWidget *);
  bind::member_function<QStackedLayout, int, QWidget *, &QStackedLayout::addWidget>(stacked_layout, "addWidget").create();
  // int insertWidget(int, QWidget *);
  bind::member_function<QStackedLayout, int, int, QWidget *, &QStackedLayout::insertWidget>(stacked_layout, "insertWidget").create();
  // QWidget * currentWidget() const;
  bind::member_function<QStackedLayout, QWidget *, &QStackedLayout::currentWidget>(stacked_layout, "currentWidget").create();
  // int currentIndex() const;
  bind::member_function<QStackedLayout, int, &QStackedLayout::currentIndex>(stacked_layout, "currentIndex").create();
  // QWidget * widget(int) const;
  bind::member_function<QStackedLayout, QWidget *, int, &QStackedLayout::widget>(stacked_layout, "widget").create();
  // int count() const;
  bind::member_function<QStackedLayout, int, &QStackedLayout::count>(stacked_layout, "count").create();
  // QStackedLayout::StackingMode stackingMode() const;
  bind::member_function<QStackedLayout, QStackedLayout::StackingMode, &QStackedLayout::stackingMode>(stacked_layout, "stackingMode").create();
  // void setStackingMode(QStackedLayout::StackingMode);
  bind::void_member_function<QStackedLayout, QStackedLayout::StackingMode, &QStackedLayout::setStackingMode>(stacked_layout, "setStackingMode").create();
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // QSize sizeHint() const;
  bind::member_function<QStackedLayout, QSize, &QStackedLayout::sizeHint>(stacked_layout, "sizeHint").create();
  // QSize minimumSize() const;
  bind::member_function<QStackedLayout, QSize, &QStackedLayout::minimumSize>(stacked_layout, "minimumSize").create();
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // void setGeometry(const QRect &);
  bind::void_member_function<QStackedLayout, const QRect &, &QStackedLayout::setGeometry>(stacked_layout, "setGeometry").create();
  // bool hasHeightForWidth() const;
  bind::member_function<QStackedLayout, bool, &QStackedLayout::hasHeightForWidth>(stacked_layout, "hasHeightForWidth").create();
  // int heightForWidth(int) const;
  bind::member_function<QStackedLayout, int, int, &QStackedLayout::heightForWidth>(stacked_layout, "heightForWidth").create();
  // void widgetRemoved(int);
  bind::void_member_function<QStackedLayout, int, &QStackedLayout::widgetRemoved>(stacked_layout, "widgetRemoved").create();
  // void currentChanged(int);
  bind::void_member_function<QStackedLayout, int, &QStackedLayout::currentChanged>(stacked_layout, "currentChanged").create();
  // void setCurrentIndex(int);
  bind::void_member_function<QStackedLayout, int, &QStackedLayout::setCurrentIndex>(stacked_layout, "setCurrentIndex").create();
  // void setCurrentWidget(QWidget *);
  bind::void_member_function<QStackedLayout, QWidget *, &QStackedLayout::setCurrentWidget>(stacked_layout, "setCurrentWidget").create();

  bind::link(stacked_layout, &QStackedLayout::staticMetaObject);
}


void register_stackedlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_stacked_layout_class(ns);

  // QStackedLayout& newStackedLayout();
  bind::new_function<QStackedLayout>(ns, "newStackedLayout");
  // QStackedLayout& newStackedLayout(QWidget*);
  bind::new_function<QStackedLayout, QWidget*>(ns, "newStackedLayout");
  // QStackedLayout& newStackedLayout(QLayout*);
  bind::new_function<QStackedLayout, QLayout*>(ns, "newStackedLayout");
}
