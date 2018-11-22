// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/bitmap.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/namespace.h"

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

  Class bitmap = ns.newClass("Bitmap").setId(script::Type::QBitmap)
    .setBase(script::Type::QPixmap).get();


  // QBitmap();
  bind::default_constructor<QBitmap>(bitmap).create();
  // QBitmap(const QPixmap &);
  bind::constructor<QBitmap, const QPixmap &>(bitmap).create();
  // QBitmap(int, int);
  bind::constructor<QBitmap, int, int>(bitmap).create();
  // QBitmap(const QSize &);
  bind::constructor<QBitmap, const QSize &>(bitmap).create();
  // QBitmap(const QString &, const char *);
  /// TODO: QBitmap(const QString &, const char *);
  // QBitmap(const QBitmap &);
  bind::constructor<QBitmap, const QBitmap &>(bitmap).create();
  // QBitmap & operator=(const QBitmap &);
  bind::memop_assign<QBitmap, const QBitmap &>(bitmap);
  // QBitmap & operator=(QBitmap &&);
  bind::memop_assign<QBitmap, QBitmap &&>(bitmap);
  // ~QBitmap();
  bind::destructor<QBitmap>(bitmap).create();
  // QBitmap & operator=(const QPixmap &);
  bind::memop_assign<QBitmap, const QPixmap &>(bitmap);
  // void swap(QBitmap &);
  bind::void_member_function<QBitmap, QBitmap &, &QBitmap::swap>(bitmap, "swap").create();
  // void clear();
  bind::void_member_function<QBitmap, &QBitmap::clear>(bitmap, "clear").create();
  // static QBitmap fromImage(const QImage &, Qt::ImageConversionFlags);
  bind::static_member_function<QBitmap, QBitmap, const QImage &, Qt::ImageConversionFlags, &QBitmap::fromImage>(bitmap, "fromImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  /// TODO: static QBitmap fromData(const QSize &, const uchar *, QImage::Format);
  // QBitmap transformed(const QMatrix &) const;
  /// TODO: QBitmap transformed(const QMatrix &) const;
  // QBitmap transformed(const QTransform &) const;
  bind::member_function<QBitmap, QBitmap, const QTransform &, &QBitmap::transformed>(bitmap, "transformed").create();
}


void register_bitmap_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_bitmap_class(ns);

  // void swap(QBitmap &, QBitmap &);
  bind::void_function<QBitmap &, QBitmap &, &swap>(ns, "swap").create();
}

