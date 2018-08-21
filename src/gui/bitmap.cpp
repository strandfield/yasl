// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/bitmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/size.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/pixmap.h"

#include <script/classbuilder.h>

static void register_bitmap_class(script::Namespace ns)
{
  using namespace script;

  Class bitmap = ns.Class("Bitmap").setId(script::Type::QBitmap)
    .setBase(script::Type::QPixmap).get();

  binding::Class<QBitmap> binder{ bitmap };

  // QBitmap();
  binder.ctors().add_default();
  // QBitmap(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // QBitmap(int, int);
  binder.ctors().add<int, int>();
  // QBitmap(const QSize &);
  binder.ctors().add<const QSize &>();
  // QBitmap(const QString &, const char *);
  /// TODO: QBitmap(const QString &, const char *);
  // QBitmap(const QBitmap &);
  binder.ctors().add<const QBitmap &>();
  // QBitmap & operator=(const QBitmap &);
  binder.operators().assign<const QBitmap &>();
  // QBitmap & operator=(QBitmap &&);
  binder.operators().assign<QBitmap &&>();
  // ~QBitmap();
  binder.add_dtor();
  // QBitmap & operator=(const QPixmap &);
  binder.operators().assign<const QPixmap &>();
  // void swap(QBitmap &);
  binder.add_void_fun<QBitmap &, &QBitmap::swap>("swap");
  // void clear();
  binder.add_void_fun<&QBitmap::clear>("clear");
  // static QBitmap fromImage(const QImage &, Qt::ImageConversionFlags);
  /// TODO: static QBitmap fromImage(const QImage &, Qt::ImageConversionFlags);
  // static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  /// TODO: static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  // QBitmap transformed(const QMatrix &) const;
  /// TODO: QBitmap transformed(const QMatrix &) const;
  // QBitmap transformed(const QTransform &) const;
  /// TODO: QBitmap transformed(const QTransform &) const;
}


void register_bitmap_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_bitmap_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QBitmap &, QBitmap &);
  binder.add_void_fun<QBitmap &, QBitmap &, &swap>("swap");
}

