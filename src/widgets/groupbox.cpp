// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/groupbox.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_group_box_class(script::Namespace ns)
{
  using namespace script;

  Class group_box = ns.Class("GroupBox").setId(script::Type::QGroupBox)
    .setBase(script::Type::QWidget).get();

  binding::QClass<QGroupBox> binder{ group_box, &QGroupBox::staticMetaObject };

  // QGroupBox(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QGroupBox(const QString &, QWidget *);
  binder.ctors().ctor<const QString &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QGroupBox();
  binder.add_dtor();
  // QString title() const;
  binder.fun<QString, &QGroupBox::title>("title").create();
  // void setTitle(const QString &);
  binder.void_fun<const QString &, &QGroupBox::setTitle>("setTitle").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QGroupBox::alignment>("alignment").create();
  // void setAlignment(int);
  binder.void_fun<int, &QGroupBox::setAlignment>("setAlignment").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QGroupBox::minimumSizeHint>("minimumSizeHint").create();
  // bool isFlat() const;
  binder.fun<bool, &QGroupBox::isFlat>("isFlat").create();
  // void setFlat(bool);
  binder.void_fun<bool, &QGroupBox::setFlat>("setFlat").create();
  // bool isCheckable() const;
  binder.fun<bool, &QGroupBox::isCheckable>("isCheckable").create();
  // void setCheckable(bool);
  binder.void_fun<bool, &QGroupBox::setCheckable>("setCheckable").create();
  // bool isChecked() const;
  binder.fun<bool, &QGroupBox::isChecked>("isChecked").create();
  // void setChecked(bool);
  binder.void_fun<bool, &QGroupBox::setChecked>("setChecked").create();
  // void clicked(bool);
  binder.sigs().add<bool>("clicked", "clicked(bool)");
  // void toggled(bool);
  binder.sigs().add<bool>("toggled", "toggled(bool)");

  group_box.engine()->registerQtType(&QGroupBox::staticMetaObject, group_box.id());
}


void register_groupbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_group_box_class(ns);
  binding::Namespace binder{ ns };

  // QGroupBox& newGroupBox(QWidget*);
  NewFunction(binder).add<QGroupBox, QWidget*>("newGroupBox");
  // QGroupBox& newGroupBox(const QString &, QWidget*);
  NewFunction(binder).add<QGroupBox, const QString &, QWidget*>("newGroupBox");
}

