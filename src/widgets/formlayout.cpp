// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/formlayout.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/widgets/formlayout.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_form_layout_field_growth_policy_enum(script::Class form_layout)
{
  using namespace script;

  Enum field_growth_policy = form_layout.Enum("FieldGrowthPolicy").setId(script::Type::QFormLayoutFieldGrowthPolicy).get();

  field_growth_policy.addValue("FieldsStayAtSizeHint", QFormLayout::FieldsStayAtSizeHint);
  field_growth_policy.addValue("ExpandingFieldsGrow", QFormLayout::ExpandingFieldsGrow);
  field_growth_policy.addValue("AllNonFixedFieldsGrow", QFormLayout::AllNonFixedFieldsGrow);
}


static void register_form_layout_row_wrap_policy_enum(script::Class form_layout)
{
  using namespace script;

  Enum row_wrap_policy = form_layout.Enum("RowWrapPolicy").setId(script::Type::QFormLayoutRowWrapPolicy).get();

  row_wrap_policy.addValue("DontWrapRows", QFormLayout::DontWrapRows);
  row_wrap_policy.addValue("WrapLongRows", QFormLayout::WrapLongRows);
  row_wrap_policy.addValue("WrapAllRows", QFormLayout::WrapAllRows);
}


static void register_form_layout_item_role_enum(script::Class form_layout)
{
  using namespace script;

  Enum item_role = form_layout.Enum("ItemRole").setId(script::Type::QFormLayoutItemRole).get();

  item_role.addValue("LabelRole", QFormLayout::LabelRole);
  item_role.addValue("FieldRole", QFormLayout::FieldRole);
  item_role.addValue("SpanningRole", QFormLayout::SpanningRole);
}


static void register_form_layout_class(script::Namespace ns)
{
  using namespace script;

  Class form_layout = ns.Class("FormLayout").setId(script::Type::QFormLayout)
    .setBase(script::Type::QLayout).get();

  register_form_layout_field_growth_policy_enum(form_layout);
  register_form_layout_row_wrap_policy_enum(form_layout);
  register_form_layout_item_role_enum(form_layout);
  binding::QClass<QFormLayout> binder{ form_layout, &QFormLayout::staticMetaObject };

  // QFormLayout(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QFormLayout();
  binder.add_dtor();
  // void setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy);
  binder.add_void_fun<QFormLayout::FieldGrowthPolicy, &QFormLayout::setFieldGrowthPolicy>("setFieldGrowthPolicy");
  // QFormLayout::FieldGrowthPolicy fieldGrowthPolicy() const;
  binder.add_fun<QFormLayout::FieldGrowthPolicy, &QFormLayout::fieldGrowthPolicy>("fieldGrowthPolicy");
  // void setRowWrapPolicy(QFormLayout::RowWrapPolicy);
  binder.add_void_fun<QFormLayout::RowWrapPolicy, &QFormLayout::setRowWrapPolicy>("setRowWrapPolicy");
  // QFormLayout::RowWrapPolicy rowWrapPolicy() const;
  binder.add_fun<QFormLayout::RowWrapPolicy, &QFormLayout::rowWrapPolicy>("rowWrapPolicy");
  // void setLabelAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QFormLayout::setLabelAlignment>("setLabelAlignment");
  // Qt::Alignment labelAlignment() const;
  binder.add_fun<Qt::Alignment, &QFormLayout::labelAlignment>("labelAlignment");
  // void setFormAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QFormLayout::setFormAlignment>("setFormAlignment");
  // Qt::Alignment formAlignment() const;
  binder.add_fun<Qt::Alignment, &QFormLayout::formAlignment>("formAlignment");
  // void setHorizontalSpacing(int);
  binder.add_void_fun<int, &QFormLayout::setHorizontalSpacing>("setHorizontalSpacing");
  // int horizontalSpacing() const;
  binder.add_fun<int, &QFormLayout::horizontalSpacing>("horizontalSpacing");
  // void setVerticalSpacing(int);
  binder.add_void_fun<int, &QFormLayout::setVerticalSpacing>("setVerticalSpacing");
  // int verticalSpacing() const;
  binder.add_fun<int, &QFormLayout::verticalSpacing>("verticalSpacing");
  // int spacing() const;
  binder.add_fun<int, &QFormLayout::spacing>("spacing");
  // void setSpacing(int);
  binder.add_void_fun<int, &QFormLayout::setSpacing>("setSpacing");
  // void addRow(QWidget *, QWidget *);
  binder.add_void_fun<QWidget *, QWidget *, &QFormLayout::addRow>("addRow");
  // void addRow(QWidget *, QLayout *);
  binder.add_void_fun<QWidget *, QLayout *, &QFormLayout::addRow>("addRow");
  // void addRow(const QString &, QWidget *);
  binder.add_void_fun<const QString &, QWidget *, &QFormLayout::addRow>("addRow");
  // void addRow(const QString &, QLayout *);
  binder.add_void_fun<const QString &, QLayout *, &QFormLayout::addRow>("addRow");
  // void addRow(QWidget *);
  binder.add_void_fun<QWidget *, &QFormLayout::addRow>("addRow");
  // void addRow(QLayout *);
  binder.add_void_fun<QLayout *, &QFormLayout::addRow>("addRow");
  // void insertRow(int, QWidget *, QWidget *);
  binder.add_void_fun<int, QWidget *, QWidget *, &QFormLayout::insertRow>("insertRow");
  // void insertRow(int, QWidget *, QLayout *);
  binder.add_void_fun<int, QWidget *, QLayout *, &QFormLayout::insertRow>("insertRow");
  // void insertRow(int, const QString &, QWidget *);
  binder.add_void_fun<int, const QString &, QWidget *, &QFormLayout::insertRow>("insertRow");
  // void insertRow(int, const QString &, QLayout *);
  binder.add_void_fun<int, const QString &, QLayout *, &QFormLayout::insertRow>("insertRow");
  // void insertRow(int, QWidget *);
  binder.add_void_fun<int, QWidget *, &QFormLayout::insertRow>("insertRow");
  // void insertRow(int, QLayout *);
  binder.add_void_fun<int, QLayout *, &QFormLayout::insertRow>("insertRow");
  // void removeRow(int);
  binder.add_void_fun<int, &QFormLayout::removeRow>("removeRow");
  // void removeRow(QWidget *);
  binder.add_void_fun<QWidget *, &QFormLayout::removeRow>("removeRow");
  // void removeRow(QLayout *);
  binder.add_void_fun<QLayout *, &QFormLayout::removeRow>("removeRow");
  // QFormLayout::TakeRowResult takeRow(int);
  /// TODO: QFormLayout::TakeRowResult takeRow(int);
  // QFormLayout::TakeRowResult takeRow(QWidget *);
  /// TODO: QFormLayout::TakeRowResult takeRow(QWidget *);
  // QFormLayout::TakeRowResult takeRow(QLayout *);
  /// TODO: QFormLayout::TakeRowResult takeRow(QLayout *);
  // void setItem(int, QFormLayout::ItemRole, QLayoutItem *);
  /// TODO: void setItem(int, QFormLayout::ItemRole, QLayoutItem *);
  // void setWidget(int, QFormLayout::ItemRole, QWidget *);
  binder.add_void_fun<int, QFormLayout::ItemRole, QWidget *, &QFormLayout::setWidget>("setWidget");
  // void setLayout(int, QFormLayout::ItemRole, QLayout *);
  binder.add_void_fun<int, QFormLayout::ItemRole, QLayout *, &QFormLayout::setLayout>("setLayout");
  // QLayoutItem * itemAt(int, QFormLayout::ItemRole) const;
  /// TODO: QLayoutItem * itemAt(int, QFormLayout::ItemRole) const;
  // void getItemPosition(int, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getItemPosition(int, int *, QFormLayout::ItemRole *) const;
  // void getWidgetPosition(QWidget *, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getWidgetPosition(QWidget *, int *, QFormLayout::ItemRole *) const;
  // void getLayoutPosition(QLayout *, int *, QFormLayout::ItemRole *) const;
  /// TODO: void getLayoutPosition(QLayout *, int *, QFormLayout::ItemRole *) const;
  // QWidget * labelForField(QWidget *) const;
  binder.add_fun<QWidget *, QWidget *, &QFormLayout::labelForField>("labelForField");
  // QWidget * labelForField(QLayout *) const;
  binder.add_fun<QWidget *, QLayout *, &QFormLayout::labelForField>("labelForField");
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // int rowCount() const;
  binder.add_fun<int, &QFormLayout::rowCount>("rowCount");

  form_layout.engine()->registerQtType(&QFormLayout::staticMetaObject, form_layout.id());
}


void register_formlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_form_layout_class(ns);
  binding::Namespace binder{ ns };

}

