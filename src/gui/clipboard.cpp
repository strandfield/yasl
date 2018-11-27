// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/clipboard.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

#include "yasl/gui/clipboard.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_clipboard_mode_enum(script::Class clipboard)
{
  using namespace script;

  Enum mode = clipboard.newEnum("Mode").setId(script::Type::QClipboardMode).get();

  mode.addValue("Clipboard", QClipboard::Clipboard);
  mode.addValue("Selection", QClipboard::Selection);
  mode.addValue("FindBuffer", QClipboard::FindBuffer);
  mode.addValue("LastMode", QClipboard::LastMode);
}


static void register_clipboard_class(script::Namespace ns)
{
  using namespace script;

  Class clipboard = ns.newClass("Clipboard").setId(script::Type::QClipboard)
    .setBase(script::Type::QObject).get();

  register_clipboard_mode_enum(clipboard);

  // void clear(QClipboard::Mode = QClipboard::Clipboard);
  bind::void_member_function<QClipboard, QClipboard::Mode, &QClipboard::clear>(clipboard, "clear")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // bool supportsSelection() const;
  bind::member_function<QClipboard, bool, &QClipboard::supportsSelection>(clipboard, "supportsSelection").create();
  // bool supportsFindBuffer() const;
  bind::member_function<QClipboard, bool, &QClipboard::supportsFindBuffer>(clipboard, "supportsFindBuffer").create();
  // bool ownsSelection() const;
  bind::member_function<QClipboard, bool, &QClipboard::ownsSelection>(clipboard, "ownsSelection").create();
  // bool ownsClipboard() const;
  bind::member_function<QClipboard, bool, &QClipboard::ownsClipboard>(clipboard, "ownsClipboard").create();
  // bool ownsFindBuffer() const;
  bind::member_function<QClipboard, bool, &QClipboard::ownsFindBuffer>(clipboard, "ownsFindBuffer").create();
  // QString text(QClipboard::Mode = QClipboard::Clipboard) const;
  bind::member_function<QClipboard, QString, QClipboard::Mode, &QClipboard::text>(clipboard, "text")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // QString text(QString &, QClipboard::Mode = QClipboard::Clipboard) const;
  bind::member_function<QClipboard, QString, QString &, QClipboard::Mode, &QClipboard::text>(clipboard, "text")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // void setText(const QString &, QClipboard::Mode = QClipboard::Clipboard);
  bind::void_member_function<QClipboard, const QString &, QClipboard::Mode, &QClipboard::setText>(clipboard, "setText")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // const QMimeData * mimeData(QClipboard::Mode = QClipboard::Clipboard) const;
  /// TODO: const QMimeData * mimeData(QClipboard::Mode = QClipboard::Clipboard) const;
  // void setMimeData(QMimeData *, QClipboard::Mode = QClipboard::Clipboard);
  /// TODO: void setMimeData(QMimeData *, QClipboard::Mode = QClipboard::Clipboard);
  // QImage image(QClipboard::Mode = QClipboard::Clipboard) const;
  bind::member_function<QClipboard, QImage, QClipboard::Mode, &QClipboard::image>(clipboard, "image")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // QPixmap pixmap(QClipboard::Mode = QClipboard::Clipboard) const;
  bind::member_function<QClipboard, QPixmap, QClipboard::Mode, &QClipboard::pixmap>(clipboard, "pixmap")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // void setImage(const QImage &, QClipboard::Mode = QClipboard::Clipboard);
  bind::void_member_function<QClipboard, const QImage &, QClipboard::Mode, &QClipboard::setImage>(clipboard, "setImage")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // void setPixmap(const QPixmap &, QClipboard::Mode = QClipboard::Clipboard);
  bind::void_member_function<QClipboard, const QPixmap &, QClipboard::Mode, &QClipboard::setPixmap>(clipboard, "setPixmap")
    .apply(bind::default_arguments(QClipboard::Clipboard)).create();
  // void changed(QClipboard::Mode);
  bind::signal<QClipboard, QClipboard::Mode>(clipboard, "changed", "changed(QClipboard::Mode)");
  // void selectionChanged();
  bind::signal<QClipboard>(clipboard, "selectionChanged", "selectionChanged()");
  // void findBufferChanged();
  bind::signal<QClipboard>(clipboard, "findBufferChanged", "findBufferChanged()");
  // void dataChanged();
  bind::signal<QClipboard>(clipboard, "dataChanged", "dataChanged()");

  bind::link(clipboard, &QClipboard::staticMetaObject);
}


void register_clipboard_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_clipboard_class(ns);

}

