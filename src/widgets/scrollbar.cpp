// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/scrollbar.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_scroll_bar_class(script::Namespace ns)
{
  using namespace script;

  Class scroll_bar = ns.Class("ScrollBar").setId(script::Type::QScrollBar)
    .setBase(script::Type::QAbstractSlider).get();

  binding::QClass<QScrollBar> binder{ scroll_bar, &QScrollBar::staticMetaObject };

  // QScrollBar(QWidget *);
  binder.ctors().add<QWidget *>();
  // QScrollBar(Qt::Orientation, QWidget *);
  binder.ctors().add<Qt::Orientation, QWidget *>();
  // ~QScrollBar();
  binder.add_dtor();

  scroll_bar.engine()->registerQtType(&QScrollBar::staticMetaObject, scroll_bar.id());
}


void register_scrollbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_scroll_bar_class(ns);
  binding::Namespace binder{ ns };

  // QScrollBar& newScrollBar(QWidget*);
  NewFunction(binder).add<QScrollBar, QWidget*>("newScrollBar");
  // QScrollBar& newScrollBar(Qt::Orientation, QWidget*);
  NewFunction(binder).add<QScrollBar, Qt::Orientation, QWidget*>("newScrollBar");
}

