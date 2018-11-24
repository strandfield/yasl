// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/scrollbar.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_scroll_bar_class(script::Namespace ns)
{
  using namespace script;

  Class scroll_bar = ns.newClass("ScrollBar").setId(script::Type::QScrollBar)
    .setBase(script::Type::QAbstractSlider).get();


  // QScrollBar(QWidget *);
  bind::constructor<QScrollBar, QWidget *>(scroll_bar)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QScrollBar(Qt::Orientation, QWidget *);
  bind::constructor<QScrollBar, Qt::Orientation, QWidget *>(scroll_bar)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QScrollBar();
  bind::destructor<QScrollBar>(scroll_bar).create();

  bind::link(scroll_bar, &QScrollBar::staticMetaObject);
}


void register_scrollbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_scroll_bar_class(ns);

  // QScrollBar& newScrollBar(QWidget*);
  bind::new_function<QScrollBar, QWidget*>(ns, "newScrollBar");
  // QScrollBar& newScrollBar(Qt::Orientation, QWidget*);
  bind::new_function<QScrollBar, Qt::Orientation, QWidget*>(ns, "newScrollBar");
}

