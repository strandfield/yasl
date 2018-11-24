// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/formlayout.h"

#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/formlayout.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_form_layout_field_growth_policy_enum(script::Class form_layout)
{
  using namespace script;

  Enum field_growth_policy = form_layout.newEnum("FieldGrowthPolicy").setId(script::Type::QFormLayoutFieldGrowthPolicy).get();

  field_growth_policy.addValue("FieldsStayAtSizeHint", QFormLayout::FieldsStayAtSizeHint);
  field_growth_policy.addValue("ExpandingFieldsGrow", QFormLayout::ExpandingFieldsGrow);
  field_growth_policy.addValue("AllNonFixedFieldsGrow", QFormLayout::AllNonFixedFieldsGrow);
}


static void register_form_layout_row_wrap_policy_enum(script::Class form_layout)
{
  using namespace script;

  Enum row_wrap_policy = form_layout.newEnum("RowWrapPolicy").setId(script::Type::QFormLayoutRowWrapPolicy).get();

  row_wrap_policy.addValue("DontWrapRows", QFormLayout::DontWrapRows);
  row_wrap_policy.addValue("WrapLongRows", QFormLayout::WrapLongRows);
  row_wrap_policy.addValue("WrapAllRows", QFormLayout::WrapAllRows);
}


static void register_form_layout_item_role_enum(script::Class form_layout)
{
  using namespace script;

  Enum item_role = form_layout.newEnum("ItemRole").setId(script::Type::QFormLayoutItemRole).get();

  item_role.addValue("LabelRole", QFormLayout::LabelRole);
  item_role.addValue("FieldRole", QFormLayout::FieldRole);
  item_role.addValue("SpanningRole", QFormLayout::SpanningRole);
}


static void register_form_layout_class(script::Namespace ns)
{
  using namespace script;

  Class form_layout = ns.newClass("FormLayout").setId(script::Type::QFormLayout)
    .setBase(script::Type::QLayout).get();

  register_form_layout_field_growth_policy_enum(form_layout);
  register_form_layout_row_wrap_policy_enum(form_layout);
  register_form_layout_item_role_enum(form_layout);

  // QFormLayout(QWidget *);
  bind::constructor<QFormLayout, QWidget *>(form_layout).create();
  // ~QFormLayout();
  bind::destructor<QFormLayout>(form_layout).create();
  // void setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy);
  bind::void_member_function<QFormLayout, QFormLayout::FieldGrowthPolicy, &QFormLayout::setFieldGrowthPolicy>(form_layout, "setFieldGrowthPolicy").create();
  // QFormLayout::FieldGrowthPolicy fieldGrowthPolicy() const;
  bind::member_function<QFormLayout, QFormLayout::FieldGrowthPolicy, &QFormLayout::fieldGrowthPolicy>(form_layout, "fieldGrowthPolicy").create();
  // void setRowWrapPolicy(QFormLayout::RowWrapPolicy);
  bind::void_member_function<QFormLayout, QFormLayout::RowWrapPolicy, &QFormLayout::setRowWrapPolicy>(form_layout, "setRowWrapPolicy").create();
  // QFormLayout::RowWrapPolicy rowWrapPolicy() const;
  bind::member_function<QFormLayout, QFormLayout::RowWrapPolicy, &QFormLayout::rowWrapPolicy>(form_layout, "rowWrapPolicy").create();
  // void setLabelAlignment(Qt::Alignment);
  bind::void_member_function<QFormLayout, Qt::Alignment, &QFormLayout::setLabelAlignment>(form_layout, "setLabelAlignment").create();
  // Qt::Alignment labelAlignment() const;
  bind::member_function<QFormLayout, Qt::Alignment, &QFormLayout::labelAlignment>(form_layout, "labelAlignment").create();
  // void setFormAlignment(Qt::Alignment);
  bind::void_member_function<QFormLayout, Qt::Alignment, &QFormLayout::setFormAlignment>(form_layout, "setFormAlignment").create();
  // Qt::Alignment formAlignment() const;
  bind::member_function<QFormLayout, Qt::Alignment, &QFormLayout::formAlignment>(form_layout, "formAlignment").create();
  // void setHorizontalSpacing(int);
  bind::void_member_function<QFormLayout, int, &QFormLayout::setHorizontalSpacing>(form_layout, "setHorizontalSpacing").create();
  // int horizontalSpacing() const;
  bind::member_function<QFormLayout, int, &QFormLayout::horizontalSpacing>(form_layout, "horizontalSpacing").create();
  // void setVerticalSpacing(int);
  bind::void_member_function<QFormLayout, int, &QFormLayout::setVerticalSpacing>(form_layout, "setVerticalSpacing").create();
  // int verticalSpacing() const;
  bind::member_function<QFormLayout, int, &QFormLayout::verticalSpacing>(form_layout, "verticalSpacing").create();
  // int spacing() const;
  bind::member_function<QFormLayout, int, &QFormLayout::spacing>(form_layout, "spacing").create();
  // void setSpacing(int);
  bind::void_member_function<QFormLayout, int, &QFormLayout::setSpacing>(form_layout, "setSpacing").create();
  // void addRow(QWidget *, QWidget *);
  bind::void_member_function<QFormLayout, QWidget *, QWidget *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void addRow(QWidget *, QLayout *);
  bind::void_member_function<QFormLayout, QWidget *, QLayout *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void addRow(const QString &, QWidget *);
  bind::void_member_function<QFormLayout, const QString &, QWidget *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void addRow(const QString &, QLayout *);
  bind::void_member_function<QFormLayout, const QString &, QLayout *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void addRow(QWidget *);
  bind::void_member_function<QFormLayout, QWidget *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void addRow(QLayout *);
  bind::void_member_function<QFormLayout, QLayout *, &QFormLayout::addRow>(form_layout, "addRow").create();
  // void insertRow(int, QWidget *, QWidget *);
  bind::void_member_function<QFormLayout, int, QWidget *, QWidget *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void insertRow(int, QWidget *, QLayout *);
  bind::void_member_function<QFormLayout, int, QWidget *, QLayout *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void insertRow(int, const QString &, QWidget *);
  bind::void_member_function<QFormLayout, int, const QString &, QWidget *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void insertRow(int, const QString &, QLayout *);
  bind::void_member_function<QFormLayout, int, const QString &, QLayout *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void insertRow(int, QWidget *);
  bind::void_member_function<QFormLayout, int, QWidget *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void insertRow(int, QLayout *);
  bind::void_member_function<QFormLayout, int, QLayout *, &QFormLayout::insertRow>(form_layout, "insertRow").create();
  // void removeRow(int);
  bind::void_member_function<QFormLayout, int, &QFormLayout::removeRow>(form_layout, "removeRow").create();
  // void removeRow(QWidget *);
  bind::void_member_function<QFormLayout, QWidget *, &QFormLayout::removeRow>(form_layout, "removeRow").create();
  // void removeRow(QLayout *);
  bind::void_member_function<QFormLayout, QLayout *, &QFormLayout::removeRow>(form_layout, "removeRow").create();
  // QFormLayout::TakeRowResult takeRow(int);
  /// TODO: QFormLayout::TakeRowResult takeRow(int);
  // QFormLayout::TakeRowResult takeRow(QWidget *);
  /// TODO: QFormLayout::TakeRowResult takeRow(QWidget *);
  // QFormLayout::TakeRowResult takeRow(QLayout *);
  /// TODO: QFormLayout::TakeRowResult takeRow(QLayout *);
  // void setItem(int, QFormLayout::ItemRole, QLayoutItem *);
  /// TODO: void setItem(int, QFormLayout::ItemRole, QLayoutItem *);
  // void setWidget(int, QFormLayout::ItemRole, QWidget *);
  bind::void_member_function<QFormLayout, int, QFormLayout::ItemRole, QWidget *, &QFormLayout::setWidget>(form_layout, "setWidget").create();
  // void setLayout(int, QFormLayout::ItemRole, QLayout *);
  bind::void_member_function<QFormLayout, int, QFormLayout::ItemRole, QLayout *, &QFormLayout::setLayout>(form_layout, "setLayout").create();
  // QLayoutItem * itemAt(int, QFormLayout::ItemRole) const;
  /// TODO: QLayoutItem * itemAt(int, QFormLayout::ItemRole) const;
  // void getItemPosition(int, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getItemPosition(int, int *, QFormLayout::ItemRole *) const;
  // void getWidgetPosition(QWidget *, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getWidgetPosition(QWidget *, int *, QFormLayout::ItemRole *) const;
  // void getLayoutPosition(QLayout *, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getLayoutPosition(QLayout *, int *, QFormLayout::ItemRole *) const;
  // QWidget * labelForField(QWidget *) const;
  bind::member_function<QFormLayout, QWidget *, QWidget *, &QFormLayout::labelForField>(form_layout, "labelForField").create();
  // QWidget * labelForField(QLayout *) const;
  bind::member_function<QFormLayout, QWidget *, QLayout *, &QFormLayout::labelForField>(form_layout, "labelForField").create();
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // int rowCount() const;
  bind::member_function<QFormLayout, int, &QFormLayout::rowCount>(form_layout, "rowCount").create();

  bind::link(form_layout, &QFormLayout::staticMetaObject);
}


void register_formlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_form_layout_class(ns);

  // QFormLayout& newFormLayout(QWidget*);
  bind::new_function<QFormLayout, QWidget*>(ns, "newFormLayout");
}

