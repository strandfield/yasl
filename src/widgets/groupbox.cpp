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

  Class group_box = ns.newClass("GroupBox").setId(script::Type::QGroupBox)
    .setBase(script::Type::QWidget).get();


  // QGroupBox(QWidget *);
  bind::constructor<QGroupBox, QWidget *>(group_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QGroupBox(const QString &, QWidget *);
  bind::constructor<QGroupBox, const QString &, QWidget *>(group_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QGroupBox();
  bind::destructor<QGroupBox>(group_box).create();
  // QString title() const;
  bind::member_function<QGroupBox, QString, &QGroupBox::title>(group_box, "title").create();
  // void setTitle(const QString &);
  bind::void_member_function<QGroupBox, const QString &, &QGroupBox::setTitle>(group_box, "setTitle").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QGroupBox, Qt::Alignment, &QGroupBox::alignment>(group_box, "alignment").create();
  // void setAlignment(int);
  bind::void_member_function<QGroupBox, int, &QGroupBox::setAlignment>(group_box, "setAlignment").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QGroupBox, QSize, &QGroupBox::minimumSizeHint>(group_box, "minimumSizeHint").create();
  // bool isFlat() const;
  bind::member_function<QGroupBox, bool, &QGroupBox::isFlat>(group_box, "isFlat").create();
  // void setFlat(bool);
  bind::void_member_function<QGroupBox, bool, &QGroupBox::setFlat>(group_box, "setFlat").create();
  // bool isCheckable() const;
  bind::member_function<QGroupBox, bool, &QGroupBox::isCheckable>(group_box, "isCheckable").create();
  // void setCheckable(bool);
  bind::void_member_function<QGroupBox, bool, &QGroupBox::setCheckable>(group_box, "setCheckable").create();
  // bool isChecked() const;
  bind::member_function<QGroupBox, bool, &QGroupBox::isChecked>(group_box, "isChecked").create();
  // void setChecked(bool);
  bind::void_member_function<QGroupBox, bool, &QGroupBox::setChecked>(group_box, "setChecked").create();
  // void clicked(bool);
  bind::signal<QGroupBox, bool>(group_box, "clicked", "clicked(bool)");
  // void toggled(bool);
  bind::signal<QGroupBox, bool>(group_box, "toggled", "toggled(bool)");

  bind::link(group_box, &QGroupBox::staticMetaObject);
}


void register_groupbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_group_box_class(ns);

  // QGroupBox& newGroupBox(QWidget*);
  bind::new_function<QGroupBox, QWidget*>(ns, "newGroupBox");
  // QGroupBox& newGroupBox(const QString &, QWidget*);
  bind::new_function<QGroupBox, const QString &, QWidget*>(ns, "newGroupBox");
}

