// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/layout.h"

#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"
#include "yasl/binding2/ref.h"

#include "yasl/core/enums.h"
#include "yasl/core/margins.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_layout_size_constraint_enum(script::Class layout)
{
  using namespace script;

  Enum size_constraint = layout.newEnum("SizeConstraint").setId(script::Type::QLayoutSizeConstraint).get();

  size_constraint.addValue("SetDefaultConstraint", QLayout::SetDefaultConstraint);
  size_constraint.addValue("SetNoConstraint", QLayout::SetNoConstraint);
  size_constraint.addValue("SetMinimumSize", QLayout::SetMinimumSize);
  size_constraint.addValue("SetFixedSize", QLayout::SetFixedSize);
  size_constraint.addValue("SetMaximumSize", QLayout::SetMaximumSize);
  size_constraint.addValue("SetMinAndMaxSize", QLayout::SetMinAndMaxSize);
}


static void register_layout_class(script::Namespace ns)
{
  using namespace script;

  Class layout = ns.newClass("Layout").setId(script::Type::QLayout)
    .setBase(script::Type::QObject).get();

  bind::register_ref_specialization(layout.engine(), script::Type::QLayout, script::Type::QLayoutStar);
  register_layout_size_constraint_enum(layout);

  // ~QLayout();
  bind::destructor<QLayout>(layout).create();
  // int margin() const;
  bind::member_function<QLayout, int, &QLayout::margin>(layout, "margin").create();
  // int spacing() const;
  bind::member_function<QLayout, int, &QLayout::spacing>(layout, "spacing").create();
  // void setMargin(int);
  bind::void_member_function<QLayout, int, &QLayout::setMargin>(layout, "setMargin").create();
  // void setSpacing(int);
  bind::void_member_function<QLayout, int, &QLayout::setSpacing>(layout, "setSpacing").create();
  // void setContentsMargins(int, int, int, int);
  bind::void_member_function<QLayout, int, int, int, int, &QLayout::setContentsMargins>(layout, "setContentsMargins").create();
  // void setContentsMargins(const QMargins &);
  bind::void_member_function<QLayout, const QMargins &, &QLayout::setContentsMargins>(layout, "setContentsMargins").create();
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  bind::member_function<QLayout, QMargins, &QLayout::contentsMargins>(layout, "contentsMargins").create();
  // QRect contentsRect() const;
  bind::member_function<QLayout, QRect, &QLayout::contentsRect>(layout, "contentsRect").create();
  // bool setAlignment(QWidget *, Qt::Alignment);
  bind::member_function<QLayout, bool, QWidget *, Qt::Alignment, &QLayout::setAlignment>(layout, "setAlignment").create();
  // bool setAlignment(QLayout *, Qt::Alignment);
  bind::member_function<QLayout, bool, QLayout *, Qt::Alignment, &QLayout::setAlignment>(layout, "setAlignment").create();
  // void setSizeConstraint(QLayout::SizeConstraint);
  bind::void_member_function<QLayout, QLayout::SizeConstraint, &QLayout::setSizeConstraint>(layout, "setSizeConstraint").create();
  // QLayout::SizeConstraint sizeConstraint() const;
  bind::member_function<QLayout, QLayout::SizeConstraint, &QLayout::sizeConstraint>(layout, "sizeConstraint").create();
  // void setMenuBar(QWidget *);
  bind::void_member_function<QLayout, QWidget *, &QLayout::setMenuBar>(layout, "setMenuBar").create();
  // QWidget * menuBar() const;
  bind::member_function<QLayout, QWidget *, &QLayout::menuBar>(layout, "menuBar").create();
  // QWidget * parentWidget() const;
  bind::member_function<QLayout, QWidget *, &QLayout::parentWidget>(layout, "parentWidget").create();
  // void invalidate();
  bind::void_member_function<QLayout, &QLayout::invalidate>(layout, "invalidate").create();
  // QRect geometry() const;
  bind::member_function<QLayout, QRect, &QLayout::geometry>(layout, "geometry").create();
  // bool activate();
  bind::member_function<QLayout, bool, &QLayout::activate>(layout, "activate").create();
  // void update();
  bind::void_member_function<QLayout, &QLayout::update>(layout, "update").create();
  // void addWidget(QWidget *);
  bind::void_member_function<QLayout, QWidget *, &QLayout::addWidget>(layout, "addWidget").create();
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // void removeWidget(QWidget *);
  bind::void_member_function<QLayout, QWidget *, &QLayout::removeWidget>(layout, "removeWidget").create();
  // void removeItem(QLayoutItem *);
  /// TODO: void removeItem(QLayoutItem *);
  // Qt::Orientations expandingDirections() const;
  /// TODO: Qt::Orientations expandingDirections() const;
  // QSize minimumSize() const;
  bind::member_function<QLayout, QSize, &QLayout::minimumSize>(layout, "minimumSize").create();
  // QSize maximumSize() const;
  bind::member_function<QLayout, QSize, &QLayout::maximumSize>(layout, "maximumSize").create();
  // void setGeometry(const QRect &);
  bind::void_member_function<QLayout, const QRect &, &QLayout::setGeometry>(layout, "setGeometry").create();
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // int indexOf(QWidget *) const;
  bind::member_function<QLayout, int, QWidget *, &QLayout::indexOf>(layout, "indexOf").create();
  // int count() const;
  bind::member_function<QLayout, int, &QLayout::count>(layout, "count").create();
  // bool isEmpty() const;
  bind::member_function<QLayout, bool, &QLayout::isEmpty>(layout, "isEmpty").create();
  // QSizePolicy::ControlTypes controlTypes() const;
  /// TODO: QSizePolicy::ControlTypes controlTypes() const;
  // QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  /// TODO: QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  // int totalHeightForWidth(int) const;
  bind::member_function<QLayout, int, int, &QLayout::totalHeightForWidth>(layout, "totalHeightForWidth").create();
  // QSize totalMinimumSize() const;
  bind::member_function<QLayout, QSize, &QLayout::totalMinimumSize>(layout, "totalMinimumSize").create();
  // QSize totalMaximumSize() const;
  bind::member_function<QLayout, QSize, &QLayout::totalMaximumSize>(layout, "totalMaximumSize").create();
  // QSize totalSizeHint() const;
  bind::member_function<QLayout, QSize, &QLayout::totalSizeHint>(layout, "totalSizeHint").create();
  // QLayout * layout();
  bind::member_function<QLayout, QLayout *, &QLayout::layout>(layout, "layout").create();
  // void setEnabled(bool);
  bind::void_member_function<QLayout, bool, &QLayout::setEnabled>(layout, "setEnabled").create();
  // bool isEnabled() const;
  bind::member_function<QLayout, bool, &QLayout::isEnabled>(layout, "isEnabled").create();
  // static QSize closestAcceptableSize(const QWidget *, const QSize &);
  bind::static_member_function<QLayout, QSize, const QWidget *, const QSize &, &QLayout::closestAcceptableSize>(layout, "closestAcceptableSize").create();

  bind::link(layout, &QLayout::staticMetaObject);
}


void register_layout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_layout_class(ns);

}

