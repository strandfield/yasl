// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/layout.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/utils/ref.h"

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

  Enum size_constraint = layout.Enum("SizeConstraint").setId(script::Type::QLayoutSizeConstraint).get();

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

  Class layout = ns.Class("Layout").setId(script::Type::QLayout)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(layout.engine(), script::Type::QLayout, script::Type::QLayoutStar);
  register_layout_size_constraint_enum(layout);
  binding::QClass<QLayout> binder{ layout, &QLayout::staticMetaObject };

  // ~QLayout();
  binder.add_dtor();
  // int margin() const;
  binder.add_fun<int, &QLayout::margin>("margin");
  // int spacing() const;
  binder.add_fun<int, &QLayout::spacing>("spacing");
  // void setMargin(int);
  binder.add_void_fun<int, &QLayout::setMargin>("setMargin");
  // void setSpacing(int);
  binder.add_void_fun<int, &QLayout::setSpacing>("setSpacing");
  // void setContentsMargins(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QLayout::setContentsMargins>("setContentsMargins");
  // void setContentsMargins(const QMargins &);
  binder.add_void_fun<const QMargins &, &QLayout::setContentsMargins>("setContentsMargins");
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  binder.add_fun<QMargins, &QLayout::contentsMargins>("contentsMargins");
  // QRect contentsRect() const;
  binder.add_fun<QRect, &QLayout::contentsRect>("contentsRect");
  // bool setAlignment(QWidget *, Qt::Alignment);
  binder.add_fun<bool, QWidget *, Qt::Alignment, &QLayout::setAlignment>("setAlignment");
  // bool setAlignment(QLayout *, Qt::Alignment);
  binder.add_fun<bool, QLayout *, Qt::Alignment, &QLayout::setAlignment>("setAlignment");
  // void setSizeConstraint(QLayout::SizeConstraint);
  binder.add_void_fun<QLayout::SizeConstraint, &QLayout::setSizeConstraint>("setSizeConstraint");
  // QLayout::SizeConstraint sizeConstraint() const;
  binder.add_fun<QLayout::SizeConstraint, &QLayout::sizeConstraint>("sizeConstraint");
  // void setMenuBar(QWidget *);
  binder.add_void_fun<QWidget *, &QLayout::setMenuBar>("setMenuBar");
  // QWidget * menuBar() const;
  binder.add_fun<QWidget *, &QLayout::menuBar>("menuBar");
  // QWidget * parentWidget() const;
  binder.add_fun<QWidget *, &QLayout::parentWidget>("parentWidget");
  // void invalidate();
  binder.add_void_fun<&QLayout::invalidate>("invalidate");
  // QRect geometry() const;
  binder.add_fun<QRect, &QLayout::geometry>("geometry");
  // bool activate();
  binder.add_fun<bool, &QLayout::activate>("activate");
  // void update();
  binder.add_void_fun<&QLayout::update>("update");
  // void addWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QLayout::addWidget>("addWidget");
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // void removeWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QLayout::removeWidget>("removeWidget");
  // void removeItem(QLayoutItem *);
  /// TODO: void removeItem(QLayoutItem *);
  // Qt::Orientations expandingDirections() const;
  /// TODO: Qt::Orientations expandingDirections() const;
  // QSize minimumSize() const;
  binder.add_fun<QSize, &QLayout::minimumSize>("minimumSize");
  // QSize maximumSize() const;
  binder.add_fun<QSize, &QLayout::maximumSize>("maximumSize");
  // void setGeometry(const QRect &);
  binder.add_void_fun<const QRect &, &QLayout::setGeometry>("setGeometry");
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // int indexOf(QWidget *) const;
  binder.add_fun<int, QWidget *, &QLayout::indexOf>("indexOf");
  // int count() const;
  binder.add_fun<int, &QLayout::count>("count");
  // bool isEmpty() const;
  binder.add_fun<bool, &QLayout::isEmpty>("isEmpty");
  // QSizePolicy::ControlTypes controlTypes() const;
  /// TODO: QSizePolicy::ControlTypes controlTypes() const;
  // QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  /// TODO: QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  // int totalHeightForWidth(int) const;
  binder.add_fun<int, int, &QLayout::totalHeightForWidth>("totalHeightForWidth");
  // QSize totalMinimumSize() const;
  binder.add_fun<QSize, &QLayout::totalMinimumSize>("totalMinimumSize");
  // QSize totalMaximumSize() const;
  binder.add_fun<QSize, &QLayout::totalMaximumSize>("totalMaximumSize");
  // QSize totalSizeHint() const;
  binder.add_fun<QSize, &QLayout::totalSizeHint>("totalSizeHint");
  // QLayout * layout();
  binder.add_fun<QLayout *, &QLayout::layout>("layout");
  // void setEnabled(bool);
  binder.add_void_fun<bool, &QLayout::setEnabled>("setEnabled");
  // bool isEnabled() const;
  binder.add_fun<bool, &QLayout::isEnabled>("isEnabled");
  // static QSize closestAcceptableSize(const QWidget *, const QSize &);
  binder.add_static<QSize, const QWidget *, const QSize &, &QLayout::closestAcceptableSize>("closestAcceptableSize");

  layout.engine()->registerQtType(&QLayout::staticMetaObject, layout.id());
}


void register_layout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_layout_class(ns);
  binding::Namespace binder{ ns };

}

