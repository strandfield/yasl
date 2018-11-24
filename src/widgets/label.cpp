// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/label.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/gui/picture.h"
#include "yasl/gui/pixmap.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_label_class(script::Namespace ns)
{
  using namespace script;

  Class label = ns.newClass("Label").setId(script::Type::QLabel)
    .setBase(script::Type::QFrame).get();


  // QLabel(QWidget *, Qt::WindowFlags);
  /// TODO: QLabel(QWidget *, Qt::WindowFlags);
  // QLabel(const QString &, QWidget *, Qt::WindowFlags);
  /// TODO: QLabel(const QString &, QWidget *, Qt::WindowFlags);
  // ~QLabel();
  bind::destructor<QLabel>(label).create();
  // QString text() const;
  bind::member_function<QLabel, QString, &QLabel::text>(label, "text").create();
  // const QPixmap * pixmap() const;
  /// TODO: const QPixmap * pixmap() const;
  // const QPicture * picture() const;
  /// TODO: const QPicture * picture() const;
  // QMovie * movie() const;
  /// TODO: QMovie * movie() const;
  // Qt::TextFormat textFormat() const;
  bind::member_function<QLabel, Qt::TextFormat, &QLabel::textFormat>(label, "textFormat").create();
  // void setTextFormat(Qt::TextFormat);
  bind::void_member_function<QLabel, Qt::TextFormat, &QLabel::setTextFormat>(label, "setTextFormat").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QLabel, Qt::Alignment, &QLabel::alignment>(label, "alignment").create();
  // void setAlignment(Qt::Alignment);
  bind::void_member_function<QLabel, Qt::Alignment, &QLabel::setAlignment>(label, "setAlignment").create();
  // void setWordWrap(bool);
  bind::void_member_function<QLabel, bool, &QLabel::setWordWrap>(label, "setWordWrap").create();
  // bool wordWrap() const;
  bind::member_function<QLabel, bool, &QLabel::wordWrap>(label, "wordWrap").create();
  // int indent() const;
  bind::member_function<QLabel, int, &QLabel::indent>(label, "indent").create();
  // void setIndent(int);
  bind::void_member_function<QLabel, int, &QLabel::setIndent>(label, "setIndent").create();
  // int margin() const;
  bind::member_function<QLabel, int, &QLabel::margin>(label, "margin").create();
  // void setMargin(int);
  bind::void_member_function<QLabel, int, &QLabel::setMargin>(label, "setMargin").create();
  // bool hasScaledContents() const;
  bind::member_function<QLabel, bool, &QLabel::hasScaledContents>(label, "hasScaledContents").create();
  // void setScaledContents(bool);
  bind::void_member_function<QLabel, bool, &QLabel::setScaledContents>(label, "setScaledContents").create();
  // QSize sizeHint() const;
  bind::member_function<QLabel, QSize, &QLabel::sizeHint>(label, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QLabel, QSize, &QLabel::minimumSizeHint>(label, "minimumSizeHint").create();
  // void setBuddy(QWidget *);
  bind::void_member_function<QLabel, QWidget *, &QLabel::setBuddy>(label, "setBuddy").create();
  // QWidget * buddy() const;
  bind::member_function<QLabel, QWidget *, &QLabel::buddy>(label, "buddy").create();
  // int heightForWidth(int) const;
  bind::member_function<QLabel, int, int, &QLabel::heightForWidth>(label, "heightForWidth").create();
  // bool openExternalLinks() const;
  bind::member_function<QLabel, bool, &QLabel::openExternalLinks>(label, "openExternalLinks").create();
  // void setOpenExternalLinks(bool);
  bind::void_member_function<QLabel, bool, &QLabel::setOpenExternalLinks>(label, "setOpenExternalLinks").create();
  // void setTextInteractionFlags(Qt::TextInteractionFlags);
  /// TODO: void setTextInteractionFlags(Qt::TextInteractionFlags);
  // Qt::TextInteractionFlags textInteractionFlags() const;
  /// TODO: Qt::TextInteractionFlags textInteractionFlags() const;
  // void setSelection(int, int);
  bind::void_member_function<QLabel, int, int, &QLabel::setSelection>(label, "setSelection").create();
  // bool hasSelectedText() const;
  bind::member_function<QLabel, bool, &QLabel::hasSelectedText>(label, "hasSelectedText").create();
  // QString selectedText() const;
  bind::member_function<QLabel, QString, &QLabel::selectedText>(label, "selectedText").create();
  // int selectionStart() const;
  bind::member_function<QLabel, int, &QLabel::selectionStart>(label, "selectionStart").create();
  // void setText(const QString &);
  bind::void_member_function<QLabel, const QString &, &QLabel::setText>(label, "setText").create();
  // void setPixmap(const QPixmap &);
  bind::void_member_function<QLabel, const QPixmap &, &QLabel::setPixmap>(label, "setPixmap").create();
  // void setPicture(const QPicture &);
  bind::void_member_function<QLabel, const QPicture &, &QLabel::setPicture>(label, "setPicture").create();
  // void setMovie(QMovie *);
  /// TODO: void setMovie(QMovie *);
  // void setNum(int);
  bind::void_member_function<QLabel, int, &QLabel::setNum>(label, "setNum").create();
  // void setNum(double);
  bind::void_member_function<QLabel, double, &QLabel::setNum>(label, "setNum").create();
  // void clear();
  bind::void_member_function<QLabel, &QLabel::clear>(label, "clear").create();
  // void linkActivated(const QString &);
  bind::void_member_function<QLabel, const QString &, &QLabel::linkActivated>(label, "linkActivated").create();
  // void linkHovered(const QString &);
  bind::void_member_function<QLabel, const QString &, &QLabel::linkHovered>(label, "linkHovered").create();

  bind::link(label, &QLabel::staticMetaObject);
}


void register_label_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_label_class(ns);

  // QLabel& newLabel(QWidget*);
  bind::new_function<QLabel, QWidget*>(ns, "newLabel");
  // QLabel& newLabel(const QString&, QWidget*);
  bind::new_function<QLabel, const QString&, QWidget*>(ns, "newLabel");
}

