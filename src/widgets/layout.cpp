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

  register_ref_specialization(layout.engine(), script::Type::QLayout, script::Type::QLayoutStar);
  register_layout_size_constraint_enum(layout);
  binding::ClassBinder<QLayout> binder{ layout, &QLayout::staticMetaObject };

  // ~QLayout();
  binder.dtor().create();
  // int margin() const;
  binder.fun<int, &QLayout::margin>("margin").create();
  // int spacing() const;
  binder.fun<int, &QLayout::spacing>("spacing").create();
  // void setMargin(int);
  binder.void_fun<int, &QLayout::setMargin>("setMargin").create();
  // void setSpacing(int);
  binder.void_fun<int, &QLayout::setSpacing>("setSpacing").create();
  // void setContentsMargins(int, int, int, int);
  binder.void_fun<int, int, int, int, &QLayout::setContentsMargins>("setContentsMargins").create();
  // void setContentsMargins(const QMargins &);
  binder.void_fun<const QMargins &, &QLayout::setContentsMargins>("setContentsMargins").create();
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  binder.fun<QMargins, &QLayout::contentsMargins>("contentsMargins").create();
  // QRect contentsRect() const;
  binder.fun<QRect, &QLayout::contentsRect>("contentsRect").create();
  // bool setAlignment(QWidget *, Qt::Alignment);
  binder.fun<bool, QWidget *, Qt::Alignment, &QLayout::setAlignment>("setAlignment").create();
  // bool setAlignment(QLayout *, Qt::Alignment);
  binder.fun<bool, QLayout *, Qt::Alignment, &QLayout::setAlignment>("setAlignment").create();
  // void setSizeConstraint(QLayout::SizeConstraint);
  binder.void_fun<QLayout::SizeConstraint, &QLayout::setSizeConstraint>("setSizeConstraint").create();
  // QLayout::SizeConstraint sizeConstraint() const;
  binder.fun<QLayout::SizeConstraint, &QLayout::sizeConstraint>("sizeConstraint").create();
  // void setMenuBar(QWidget *);
  binder.void_fun<QWidget *, &QLayout::setMenuBar>("setMenuBar").create();
  // QWidget * menuBar() const;
  binder.fun<QWidget *, &QLayout::menuBar>("menuBar").create();
  // QWidget * parentWidget() const;
  binder.fun<QWidget *, &QLayout::parentWidget>("parentWidget").create();
  // void invalidate();
  binder.void_fun<&QLayout::invalidate>("invalidate").create();
  // QRect geometry() const;
  binder.fun<QRect, &QLayout::geometry>("geometry").create();
  // bool activate();
  binder.fun<bool, &QLayout::activate>("activate").create();
  // void update();
  binder.void_fun<&QLayout::update>("update").create();
  // void addWidget(QWidget *);
  binder.void_fun<QWidget *, &QLayout::addWidget>("addWidget").create();
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // void removeWidget(QWidget *);
  binder.void_fun<QWidget *, &QLayout::removeWidget>("removeWidget").create();
  // void removeItem(QLayoutItem *);
  /// TODO: void removeItem(QLayoutItem *);
  // Qt::Orientations expandingDirections() const;
  /// TODO: Qt::Orientations expandingDirections() const;
  // QSize minimumSize() const;
  binder.fun<QSize, &QLayout::minimumSize>("minimumSize").create();
  // QSize maximumSize() const;
  binder.fun<QSize, &QLayout::maximumSize>("maximumSize").create();
  // void setGeometry(const QRect &);
  binder.void_fun<const QRect &, &QLayout::setGeometry>("setGeometry").create();
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // int indexOf(QWidget *) const;
  binder.fun<int, QWidget *, &QLayout::indexOf>("indexOf").create();
  // int count() const;
  binder.fun<int, &QLayout::count>("count").create();
  // bool isEmpty() const;
  binder.fun<bool, &QLayout::isEmpty>("isEmpty").create();
  // QSizePolicy::ControlTypes controlTypes() const;
  /// TODO: QSizePolicy::ControlTypes controlTypes() const;
  // QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  /// TODO: QLayoutItem * replaceWidget(QWidget *, QWidget *, Qt::FindChildOptions);
  // int totalHeightForWidth(int) const;
  binder.fun<int, int, &QLayout::totalHeightForWidth>("totalHeightForWidth").create();
  // QSize totalMinimumSize() const;
  binder.fun<QSize, &QLayout::totalMinimumSize>("totalMinimumSize").create();
  // QSize totalMaximumSize() const;
  binder.fun<QSize, &QLayout::totalMaximumSize>("totalMaximumSize").create();
  // QSize totalSizeHint() const;
  binder.fun<QSize, &QLayout::totalSizeHint>("totalSizeHint").create();
  // QLayout * layout();
  binder.fun<QLayout *, &QLayout::layout>("layout").create();
  // void setEnabled(bool);
  binder.void_fun<bool, &QLayout::setEnabled>("setEnabled").create();
  // bool isEnabled() const;
  binder.fun<bool, &QLayout::isEnabled>("isEnabled").create();
  // static QSize closestAcceptableSize(const QWidget *, const QSize &);
  binder.static_fun<QSize, const QWidget *, const QSize &, &QLayout::closestAcceptableSize>("closestAcceptableSize").create();

  layout.engine()->registerQtType(&QLayout::staticMetaObject, layout.id());
}


void register_layout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_layout_class(ns);
  binding::Namespace binder{ ns };

}

