// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pushbutton.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/widget.h"

#include <script/classbuilder.h>

static void register_push_button_class(script::Namespace ns)
{
  using namespace script;

  Class push_button = ns.Class("PushButton").setId(script::Type::QPushButton)
    .setBase(script::Type::QAbstractButton).get();

  binding::QClass<QPushButton> binder{ push_button, &QPushButton::staticMetaObject };

  // QPushButton(QWidget *);
  binder.ctors().add<QWidget *>();
  // QPushButton(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // QPushButton(const QIcon &, const QString &, QWidget *);
  binder.ctors().add<const QIcon &, const QString &, QWidget *>();
  // ~QPushButton();
  binder.add_dtor();
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QPushButton::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QPushButton::minimumSizeHint>("minimumSizeHint");
  // bool autoDefault() const;
  binder.add_fun<bool, &QPushButton::autoDefault>("autoDefault");
  // void setAutoDefault(bool);
  binder.add_void_fun<bool, &QPushButton::setAutoDefault>("setAutoDefault");
  // bool isDefault() const;
  binder.add_fun<bool, &QPushButton::isDefault>("isDefault");
  // void setDefault(bool);
  binder.add_void_fun<bool, &QPushButton::setDefault>("setDefault");
  // void setMenu(QMenu *);
  /// TODO: void setMenu(QMenu *);
  // QMenu * menu() const;
  /// TODO: QMenu * menu() const;
  // void setFlat(bool);
  binder.add_void_fun<bool, &QPushButton::setFlat>("setFlat");
  // bool isFlat() const;
  binder.add_fun<bool, &QPushButton::isFlat>("isFlat");
  // void showMenu();
  binder.add_void_fun<&QPushButton::showMenu>("showMenu");
  // void clicked();
  binder.sigs().add("clicked", "clicked()");

  push_button.engine()->registerQtType(&QPushButton::staticMetaObject, push_button.id());
}


void register_pushbutton_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_push_button_class(ns);
  binding::Namespace binder{ ns };

}

