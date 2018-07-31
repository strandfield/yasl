// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/clipboard.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"

#include "yasl/core/mimedata.h"
#include "yasl/core/object.h"

#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_clipboard_mode_enum(script::Class clipboard)
{
  using namespace script;

  Enum mode = clipboard.Enum("Mode").setId(script::Type::QClipboardMode).get();

  mode.addValue("Clipboard", QClipboard::Clipboard);
  mode.addValue("FindBuffer", QClipboard::FindBuffer);
  mode.addValue("LastMode", QClipboard::LastMode);
  mode.addValue("Selection", QClipboard::Selection);
}

static void register_clipboard_class(script::Namespace ns)
{
  using namespace script;

  Class clipboard = ns.Class("Clipboard").setId(script::Type::QClipboard)
    .setBase(script::Type::QObject).get();

  register_clipboard_mode_enum(clipboard);
  binding::QClass<QClipboard> binder{ clipboard };

  // ~QClipboard();
  /// ignore: QClipboard destructor is private !
  // static QString tr(const char *, const char *, int);
  /// TODO: binder.add_static<QString, const char *, const char *, int, &QClipboard::tr>("tr");
  // static QString trUtf8(const char *, const char *, int);
  /// TODO: binder.add_static<QString, const char *, const char *, int, &QClipboard::trUtf8>("trUtf8");
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
  binder.add_fun<const QMimeData *, QClipboard::Mode, &QClipboard::mimeData>("mimeData");
  // void setMimeData(QMimeData *, QClipboard::Mode);
  binder.add_void_fun<QMimeData *, QClipboard::Mode, &QClipboard::setMimeData>("setMimeData");
  // QImage image(QClipboard::Mode) const;
  binder.add_fun<QImage, QClipboard::Mode, &QClipboard::image>("image");
  // QPixmap pixmap(QClipboard::Mode) const;
  binder.add_fun<QPixmap, QClipboard::Mode, &QClipboard::pixmap>("pixmap");
  // void setImage(const QImage &, QClipboard::Mode);
  binder.add_void_fun<const QImage &, QClipboard::Mode, &QClipboard::setImage>("setImage");
  // void setPixmap(const QPixmap &, QClipboard::Mode);
  binder.add_void_fun<const QPixmap &, QClipboard::Mode, &QClipboard::setPixmap>("setPixmap");

  /* Signals */
  binding::QSignal sigs{ clipboard, &QClipboard::staticMetaObject };
  // void changed(QClipboard::Mode);
  sigs.add<QClipboard::Mode>("changed", "changed(QClipboard::Mode)");
  // void selectionChanged();
  sigs.add("selectionChanged", "selectionChanged()");
  // void findBufferChanged();
  sigs.add("findBufferChanged", "findBufferChanged()");
  // void dataChanged();
  sigs.add("dataChanged", "dataChanged()");

  ns.engine()->registerQtType(&QClipboard::staticMetaObject, clipboard.id());
}

void register_clipboard_file(script::Namespace root)
{
  using namespace script;

  register_clipboard_class(root);
  binding::Namespace binder{ root };

}

