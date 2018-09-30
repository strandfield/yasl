// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/groupbox.h"

#include "yasl/binding/namespace.h"
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
  binder.ctors().add<QWidget *>();
  // QGroupBox(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // ~QGroupBox();
  binder.add_dtor();
  // QString title() const;
  binder.add_fun<QString, &QGroupBox::title>("title");
  // void setTitle(const QString &);
  binder.add_void_fun<const QString &, &QGroupBox::setTitle>("setTitle");
  // Qt::Alignment alignment() const;
  binder.add_fun<Qt::Alignment, &QGroupBox::alignment>("alignment");
  // void setAlignment(int);
  binder.add_void_fun<int, &QGroupBox::setAlignment>("setAlignment");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QGroupBox::minimumSizeHint>("minimumSizeHint");
  // bool isFlat() const;
  binder.add_fun<bool, &QGroupBox::isFlat>("isFlat");
  // void setFlat(bool);
  binder.add_void_fun<bool, &QGroupBox::setFlat>("setFlat");
  // bool isCheckable() const;
  binder.add_fun<bool, &QGroupBox::isCheckable>("isCheckable");
  // void setCheckable(bool);
  binder.add_void_fun<bool, &QGroupBox::setCheckable>("setCheckable");
  // bool isChecked() const;
  binder.add_fun<bool, &QGroupBox::isChecked>("isChecked");
  // void setChecked(bool);
  binder.add_void_fun<bool, &QGroupBox::setChecked>("setChecked");
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

}

