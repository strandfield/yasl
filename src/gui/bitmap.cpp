// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/bitmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"

#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/transform.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_bitmap_class(script::Namespace ns)
{
  using namespace script;

  Class bitmap = ns.Class("Bitmap").setId(script::Type::QBitmap)
    .setBase(script::Type::QPixmap).get();

  binding::Class<QBitmap> binder{ bitmap };

  // ~QBitmap();
  binder.add_dtor();
  // QBitmap();
  binder.ctors().add_default();
  // QBitmap(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // QBitmap(int, int);
  binder.ctors().add<int, int>();
  // QBitmap(const QSize &);
  binder.ctors().add<const QSize &>();
  // QBitmap(const QString &, const char *);
  binder.ctors().add<const QString &, const char *>();
  // QBitmap(const QBitmap &);
  binder.ctors().add<const QBitmap &>();
  // QBitmap & operator=(const QBitmap &);
  binder.operators().assign<const QBitmap &>();
  // QBitmap & operator=(QBitmap &&);
  binder.operators().assign<QBitmap &&>();
  // QBitmap & operator=(const QPixmap &);
  binder.operators().assign<const QPixmap &>();
  // void swap(QBitmap &);
  binder.add_void_fun<QBitmap &, &QBitmap::swap>("swap");
  // void clear();
  binder.add_void_fun<&QBitmap::clear>("clear");
  // static QBitmap fromImage(const QImage &, Qt::ImageConversionFlags);
  binder.add_static<QBitmap, const QImage &, Qt::ImageConversionFlags, &QBitmap::fromImage>("fromImage");
  // static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  binder.add_static<QBitmap, const QSize &, const uchar *, QImage::Format, &QBitmap::fromData>("fromData");
  // QBitmap transformed(const QMatrix &) const;
  /// ignore: binder.add_fun<QBitmap, const QMatrix &, &QBitmap::transformed>("transformed");
  // QBitmap transformed(const QTransform &) const;
  binder.add_fun<QBitmap, const QTransform &, &QBitmap::transformed>("transformed");
}

void register_bitmap_file(script::Namespace root)
{
  using namespace script;

  register_bitmap_class(root);
  binding::Namespace binder{ root };

  // void swap(QBitmap &, QBitmap &);
  binder.add_void_fun<QBitmap &, QBitmap &, &swap>("swap");
}

