// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/label.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/gui/picture.h"
#include "yasl/gui/pixmap.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_label_class(script::Namespace ns)
{
  using namespace script;

  Class label = ns.Class("Label").setId(script::Type::QLabel)
    .setBase(script::Type::QFrame).get();

  binding::QClass<QLabel> binder{ label, &QLabel::staticMetaObject };

  // QLabel(QWidget *, Qt::WindowFlags);
  /// TODO: QLabel(QWidget *, Qt::WindowFlags);
  // QLabel(const QString &, QWidget *, Qt::WindowFlags);
  /// TODO: QLabel(const QString &, QWidget *, Qt::WindowFlags);
  // ~QLabel();
  binder.add_dtor();
  // QString text() const;
  binder.fun<QString, &QLabel::text>("text").create();
  // const QPixmap * pixmap() const;
  /// TODO: const QPixmap * pixmap() const;
  // const QPicture * picture() const;
  /// TODO: const QPicture * picture() const;
  // QMovie * movie() const;
  /// TODO: QMovie * movie() const;
  // Qt::TextFormat textFormat() const;
  binder.fun<Qt::TextFormat, &QLabel::textFormat>("textFormat").create();
  // void setTextFormat(Qt::TextFormat);
  binder.void_fun<Qt::TextFormat, &QLabel::setTextFormat>("setTextFormat").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QLabel::alignment>("alignment").create();
  // void setAlignment(Qt::Alignment);
  binder.void_fun<Qt::Alignment, &QLabel::setAlignment>("setAlignment").create();
  // void setWordWrap(bool);
  binder.void_fun<bool, &QLabel::setWordWrap>("setWordWrap").create();
  // bool wordWrap() const;
  binder.fun<bool, &QLabel::wordWrap>("wordWrap").create();
  // int indent() const;
  binder.fun<int, &QLabel::indent>("indent").create();
  // void setIndent(int);
  binder.void_fun<int, &QLabel::setIndent>("setIndent").create();
  // int margin() const;
  binder.fun<int, &QLabel::margin>("margin").create();
  // void setMargin(int);
  binder.void_fun<int, &QLabel::setMargin>("setMargin").create();
  // bool hasScaledContents() const;
  binder.fun<bool, &QLabel::hasScaledContents>("hasScaledContents").create();
  // void setScaledContents(bool);
  binder.void_fun<bool, &QLabel::setScaledContents>("setScaledContents").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QLabel::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QLabel::minimumSizeHint>("minimumSizeHint").create();
  // void setBuddy(QWidget *);
  binder.void_fun<QWidget *, &QLabel::setBuddy>("setBuddy").create();
  // QWidget * buddy() const;
  binder.fun<QWidget *, &QLabel::buddy>("buddy").create();
  // int heightForWidth(int) const;
  binder.fun<int, int, &QLabel::heightForWidth>("heightForWidth").create();
  // bool openExternalLinks() const;
  binder.fun<bool, &QLabel::openExternalLinks>("openExternalLinks").create();
  // void setOpenExternalLinks(bool);
  binder.void_fun<bool, &QLabel::setOpenExternalLinks>("setOpenExternalLinks").create();
  // void setTextInteractionFlags(Qt::TextInteractionFlags);
  /// TODO: void setTextInteractionFlags(Qt::TextInteractionFlags);
  // Qt::TextInteractionFlags textInteractionFlags() const;
  /// TODO: Qt::TextInteractionFlags textInteractionFlags() const;
  // void setSelection(int, int);
  binder.void_fun<int, int, &QLabel::setSelection>("setSelection").create();
  // bool hasSelectedText() const;
  binder.fun<bool, &QLabel::hasSelectedText>("hasSelectedText").create();
  // QString selectedText() const;
  binder.fun<QString, &QLabel::selectedText>("selectedText").create();
  // int selectionStart() const;
  binder.fun<int, &QLabel::selectionStart>("selectionStart").create();
  // void setText(const QString &);
  binder.void_fun<const QString &, &QLabel::setText>("setText").create();
  // void setPixmap(const QPixmap &);
  binder.void_fun<const QPixmap &, &QLabel::setPixmap>("setPixmap").create();
  // void setPicture(const QPicture &);
  binder.void_fun<const QPicture &, &QLabel::setPicture>("setPicture").create();
  // void setMovie(QMovie *);
  /// TODO: void setMovie(QMovie *);
  // void setNum(int);
  binder.void_fun<int, &QLabel::setNum>("setNum").create();
  // void setNum(double);
  binder.void_fun<double, &QLabel::setNum>("setNum").create();
  // void clear();
  binder.void_fun<&QLabel::clear>("clear").create();
  // void linkActivated(const QString &);
  binder.void_fun<const QString &, &QLabel::linkActivated>("linkActivated").create();
  // void linkHovered(const QString &);
  binder.void_fun<const QString &, &QLabel::linkHovered>("linkHovered").create();

  label.engine()->registerQtType(&QLabel::staticMetaObject, label.id());
}


void register_label_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_label_class(ns);
  binding::Namespace binder{ ns };

  // QLabel& newLabel(QWidget*);
  NewFunction(binder).add<QLabel, QWidget*>("newLabel");
  // QLabel& newLabel(const QString&, QWidget*);
  NewFunction(binder).add<QLabel, const QString&, QWidget*>("newLabel");
}

