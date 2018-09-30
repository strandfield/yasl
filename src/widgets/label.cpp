// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/label.h"

#include "yasl/binding/namespace.h"
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
  binder.add_fun<QString, &QLabel::text>("text");
  // const QPixmap * pixmap() const;
  /// TODO: const QPixmap * pixmap() const;
  // const QPicture * picture() const;
  /// TODO: const QPicture * picture() const;
  // QMovie * movie() const;
  /// TODO: QMovie * movie() const;
  // Qt::TextFormat textFormat() const;
  binder.add_fun<Qt::TextFormat, &QLabel::textFormat>("textFormat");
  // void setTextFormat(Qt::TextFormat);
  binder.add_void_fun<Qt::TextFormat, &QLabel::setTextFormat>("setTextFormat");
  // Qt::Alignment alignment() const;
  binder.add_fun<Qt::Alignment, &QLabel::alignment>("alignment");
  // void setAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QLabel::setAlignment>("setAlignment");
  // void setWordWrap(bool);
  binder.add_void_fun<bool, &QLabel::setWordWrap>("setWordWrap");
  // bool wordWrap() const;
  binder.add_fun<bool, &QLabel::wordWrap>("wordWrap");
  // int indent() const;
  binder.add_fun<int, &QLabel::indent>("indent");
  // void setIndent(int);
  binder.add_void_fun<int, &QLabel::setIndent>("setIndent");
  // int margin() const;
  binder.add_fun<int, &QLabel::margin>("margin");
  // void setMargin(int);
  binder.add_void_fun<int, &QLabel::setMargin>("setMargin");
  // bool hasScaledContents() const;
  binder.add_fun<bool, &QLabel::hasScaledContents>("hasScaledContents");
  // void setScaledContents(bool);
  binder.add_void_fun<bool, &QLabel::setScaledContents>("setScaledContents");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QLabel::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QLabel::minimumSizeHint>("minimumSizeHint");
  // void setBuddy(QWidget *);
  binder.add_void_fun<QWidget *, &QLabel::setBuddy>("setBuddy");
  // QWidget * buddy() const;
  binder.add_fun<QWidget *, &QLabel::buddy>("buddy");
  // int heightForWidth(int) const;
  binder.add_fun<int, int, &QLabel::heightForWidth>("heightForWidth");
  // bool openExternalLinks() const;
  binder.add_fun<bool, &QLabel::openExternalLinks>("openExternalLinks");
  // void setOpenExternalLinks(bool);
  binder.add_void_fun<bool, &QLabel::setOpenExternalLinks>("setOpenExternalLinks");
  // void setTextInteractionFlags(Qt::TextInteractionFlags);
  /// TODO: void setTextInteractionFlags(Qt::TextInteractionFlags);
  // Qt::TextInteractionFlags textInteractionFlags() const;
  /// TODO: Qt::TextInteractionFlags textInteractionFlags() const;
  // void setSelection(int, int);
  binder.add_void_fun<int, int, &QLabel::setSelection>("setSelection");
  // bool hasSelectedText() const;
  binder.add_fun<bool, &QLabel::hasSelectedText>("hasSelectedText");
  // QString selectedText() const;
  binder.add_fun<QString, &QLabel::selectedText>("selectedText");
  // int selectionStart() const;
  binder.add_fun<int, &QLabel::selectionStart>("selectionStart");
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QLabel::setText>("setText");
  // void setPixmap(const QPixmap &);
  binder.add_void_fun<const QPixmap &, &QLabel::setPixmap>("setPixmap");
  // void setPicture(const QPicture &);
  binder.add_void_fun<const QPicture &, &QLabel::setPicture>("setPicture");
  // void setMovie(QMovie *);
  /// TODO: void setMovie(QMovie *);
  // void setNum(int);
  binder.add_void_fun<int, &QLabel::setNum>("setNum");
  // void setNum(double);
  binder.add_void_fun<double, &QLabel::setNum>("setNum");
  // void clear();
  binder.add_void_fun<&QLabel::clear>("clear");
  // void linkActivated(const QString &);
  binder.add_void_fun<const QString &, &QLabel::linkActivated>("linkActivated");
  // void linkHovered(const QString &);
  binder.add_void_fun<const QString &, &QLabel::linkHovered>("linkHovered");

  label.engine()->registerQtType(&QLabel::staticMetaObject, label.id());
}


void register_label_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_label_class(ns);
  binding::Namespace binder{ ns };

}

