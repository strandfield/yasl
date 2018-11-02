// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/bitmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/transform.h"

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
  binder.ctors().ctor<const QPixmap &>().create();
  // QBitmap(int, int);
  binder.ctors().ctor<int, int>().create();
  // QBitmap(const QSize &);
  binder.ctors().ctor<const QSize &>().create();
  // QBitmap(const QString &, const char *);
  /// TODO: QBitmap(const QString &, const char *);
  // QBitmap(const QBitmap &);
  binder.ctors().ctor<const QBitmap &>().create();
  // QBitmap & operator=(const QBitmap &);
  binder.operators().assign<const QBitmap &>();
  // QBitmap & operator=(QBitmap &&);
  binder.operators().assign<QBitmap &&>();
  // ~QBitmap();
  binder.add_dtor();
  // QBitmap & operator=(const QPixmap &);
  binder.operators().assign<const QPixmap &>();
  // void swap(QBitmap &);
  binder.void_fun<QBitmap &, &QBitmap::swap>("swap").create();
  // void clear();
  binder.void_fun<&QBitmap::clear>("clear").create();
  // static QBitmap fromImage(const QImage &, Qt::ImageConversionFlags);
  binder.static_fun<QBitmap, const QImage &, Qt::ImageConversionFlags, &QBitmap::fromImage>("fromImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  /// TODO: static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  // QBitmap transformed(const QMatrix &) const;
  /// TODO: QBitmap transformed(const QMatrix &) const;
  // QBitmap transformed(const QTransform &) const;
  binder.fun<QBitmap, const QTransform &, &QBitmap::transformed>("transformed").create();
}


void register_bitmap_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_bitmap_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QBitmap &, QBitmap &);
  binder.void_fun<QBitmap &, QBitmap &, &swap>("swap").create();
}

