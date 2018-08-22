// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/clipboard.h"

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
  binding::QClass<QClipboard> binder{ clipboard, &QClipboard::staticMetaObject };

  // void clear(QClipboard::Mode);
  binder.add_void_fun<QClipboard::Mode, &QClipboard::clear>("clear");
  // bool supportsSelection() const;
  binder.add_fun<bool, &QClipboard::supportsSelection>("supportsSelection");
  // bool supportsFindBuffer() const;
  binder.add_fun<bool, &QClipboard::supportsFindBuffer>("supportsFindBuffer");
  // bool ownsSelection() const;
  binder.add_fun<bool, &QClipboard::ownsSelection>("ownsSelection");
  // bool ownsClipboard() const;
  binder.add_fun<bool, &QClipboard::ownsClipboard>("ownsClipboard");
  // bool ownsFindBuffer() const;
  binder.add_fun<bool, &QClipboard::ownsFindBuffer>("ownsFindBuffer");
  // QString text(QClipboard::Mode) const;
  binder.add_fun<QString, QClipboard::Mode, &QClipboard::text>("text");
  // QString text(QString &, QClipboard::Mode) const;
  binder.add_fun<QString, QString &, QClipboard::Mode, &QClipboard::text>("text");
  // void setText(const QString &, QClipboard::Mode);
  binder.add_void_fun<const QString &, QClipboard::Mode, &QClipboard::setText>("setText");
  // const QMimeData * mimeData(QClipboard::Mode) const;
  /// TODO: const QMimeData * mimeData(QClipboard::Mode) const;
  // void setMimeData(QMimeData *, QClipboard::Mode);
  /// TODO: void setMimeData(QMimeData *, QClipboard::Mode);
  // QImage image(QClipboard::Mode) const;
  binder.add_fun<QImage, QClipboard::Mode, &QClipboard::image>("image");
  // QPixmap pixmap(QClipboard::Mode) const;
  binder.add_fun<QPixmap, QClipboard::Mode, &QClipboard::pixmap>("pixmap");
  // void setImage(const QImage &, QClipboard::Mode);
  binder.add_void_fun<const QImage &, QClipboard::Mode, &QClipboard::setImage>("setImage");
  // void setPixmap(const QPixmap &, QClipboard::Mode);
  binder.add_void_fun<const QPixmap &, QClipboard::Mode, &QClipboard::setPixmap>("setPixmap");
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

