// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/clipboard.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/gui/clipboard.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_clipboard_mode_enum(script::Class clipboard)
{
  using namespace script;

  Enum mode = clipboard.Enum("Mode").setId(script::Type::QClipboardMode).get();

  mode.addValue("Clipboard", QClipboard::Clipboard);
  mode.addValue("Selection", QClipboard::Selection);
  mode.addValue("FindBuffer", QClipboard::FindBuffer);
  mode.addValue("LastMode", QClipboard::LastMode);
}


static void register_clipboard_class(script::Namespace ns)
{
  using namespace script;

  Class clipboard = ns.Class("Clipboard").setId(script::Type::QClipboard)
    .setBase(script::Type::QObject).get();

  register_clipboard_mode_enum(clipboard);
  binding::ClassBinder<QClipboard> binder{ clipboard, &QClipboard::staticMetaObject };

  // void clear(QClipboard::Mode);
  binder.void_fun<QClipboard::Mode, &QClipboard::clear>("clear")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // bool supportsSelection() const;
  binder.fun<bool, &QClipboard::supportsSelection>("supportsSelection").create();
  // bool supportsFindBuffer() const;
  binder.fun<bool, &QClipboard::supportsFindBuffer>("supportsFindBuffer").create();
  // bool ownsSelection() const;
  binder.fun<bool, &QClipboard::ownsSelection>("ownsSelection").create();
  // bool ownsClipboard() const;
  binder.fun<bool, &QClipboard::ownsClipboard>("ownsClipboard").create();
  // bool ownsFindBuffer() const;
  binder.fun<bool, &QClipboard::ownsFindBuffer>("ownsFindBuffer").create();
  // QString text(QClipboard::Mode) const;
  binder.fun<QString, QClipboard::Mode, &QClipboard::text>("text")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // QString text(QString &, QClipboard::Mode) const;
  binder.fun<QString, QString &, QClipboard::Mode, &QClipboard::text>("text")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // void setText(const QString &, QClipboard::Mode);
  binder.void_fun<const QString &, QClipboard::Mode, &QClipboard::setText>("setText")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // const QMimeData * mimeData(QClipboard::Mode) const;
  /// TODO: const QMimeData * mimeData(QClipboard::Mode) const;
  // void setMimeData(QMimeData *, QClipboard::Mode);
  /// TODO: void setMimeData(QMimeData *, QClipboard::Mode);
  // QImage image(QClipboard::Mode) const;
  binder.fun<QImage, QClipboard::Mode, &QClipboard::image>("image")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // QPixmap pixmap(QClipboard::Mode) const;
  binder.fun<QPixmap, QClipboard::Mode, &QClipboard::pixmap>("pixmap")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // void setImage(const QImage &, QClipboard::Mode);
  binder.void_fun<const QImage &, QClipboard::Mode, &QClipboard::setImage>("setImage")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // void setPixmap(const QPixmap &, QClipboard::Mode);
  binder.void_fun<const QPixmap &, QClipboard::Mode, &QClipboard::setPixmap>("setPixmap")
    .apply(binding::default_arguments(QClipboard::Clipboard)).create();
  // void changed(QClipboard::Mode);
  binder.sigs().add<QClipboard::Mode>("changed", "changed(QClipboard::Mode)");
  // void selectionChanged();
  binder.sigs().add("selectionChanged", "selectionChanged()");
  // void findBufferChanged();
  binder.sigs().add("findBufferChanged", "findBufferChanged()");
  // void dataChanged();
  binder.sigs().add("dataChanged", "dataChanged()");

  clipboard.engine()->registerQtType(&QClipboard::staticMetaObject, clipboard.id());
}


void register_clipboard_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_clipboard_class(ns);
  binding::Namespace binder{ ns };

}

