// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/region.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/region.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_region_region_type_enum(script::Class region)
{
  using namespace script;

  Enum region_type = region.Enum("RegionType").setId(script::Type::QRegionRegionType).get();

  region_type.addValue("Rectangle", QRegion::Rectangle);
  region_type.addValue("Ellipse", QRegion::Ellipse);
}


static void register_region_class(script::Namespace ns)
{
  using namespace script;

  Class region = ns.Class("Region").setId(script::Type::QRegion).get();

  register_region_region_type_enum(region);
  binding::ClassBinder<QRegion> binder{ region };

  // QRegion();
  binder.default_ctor().create();
  // QRegion(int, int, int, int, QRegion::RegionType);
  binder.ctor<int, int, int, int, QRegion::RegionType>()
    .apply(binding::default_arguments(QRegion::Rectangle)).create();
  // QRegion(const QRect &, QRegion::RegionType);
  binder.ctor<const QRect &, QRegion::RegionType>()
    .apply(binding::default_arguments(QRegion::Rectangle)).create();
  // QRegion(const QPolygon &, Qt::FillRule);
  /// TODO: QRegion(const QPolygon &, Qt::FillRule);
  // QRegion(const QRegion &);
  binder.ctor<const QRegion &>().create();
  // QRegion(QRegion &&);
  binder.ctor<QRegion &&>().create();
  // QRegion(const QBitmap &);
  binder.ctor<const QBitmap &>().create();
  // ~QRegion();
  binder.dtor().create();
  // QRegion & operator=(const QRegion &);
  binder.operators().assign<const QRegion &>();
  // QRegion & operator=(QRegion &&);
  binder.operators().assign<QRegion &&>();
  // void swap(QRegion &);
  binder.void_fun<QRegion &, &QRegion::swap>("swap").create();
  // bool isEmpty() const;
  binder.fun<bool, &QRegion::isEmpty>("isEmpty").create();
  // bool isNull() const;
  binder.fun<bool, &QRegion::isNull>("isNull").create();
  // QRegion::const_iterator begin() const;
  /// TODO: QRegion::const_iterator begin() const;
  // QRegion::const_iterator cbegin() const;
  /// TODO: QRegion::const_iterator cbegin() const;
  // QRegion::const_iterator end() const;
  /// TODO: QRegion::const_iterator end() const;
  // QRegion::const_iterator cend() const;
  /// TODO: QRegion::const_iterator cend() const;
  // QRegion::const_reverse_iterator rbegin() const;
  /// TODO: QRegion::const_reverse_iterator rbegin() const;
  // QRegion::const_reverse_iterator crbegin() const;
  /// TODO: QRegion::const_reverse_iterator crbegin() const;
  // QRegion::const_reverse_iterator rend() const;
  /// TODO: QRegion::const_reverse_iterator rend() const;
  // QRegion::const_reverse_iterator crend() const;
  /// TODO: QRegion::const_reverse_iterator crend() const;
  // bool contains(const QPoint &) const;
  binder.fun<bool, const QPoint &, &QRegion::contains>("contains").create();
  // bool contains(const QRect &) const;
  binder.fun<bool, const QRect &, &QRegion::contains>("contains").create();
  // void translate(int, int);
  binder.void_fun<int, int, &QRegion::translate>("translate").create();
  // void translate(const QPoint &);
  binder.void_fun<const QPoint &, &QRegion::translate>("translate").create();
  // QRegion translated(int, int) const;
  binder.fun<QRegion, int, int, &QRegion::translated>("translated").create();
  // QRegion translated(const QPoint &) const;
  binder.fun<QRegion, const QPoint &, &QRegion::translated>("translated").create();
  // QRegion united(const QRegion &) const;
  binder.fun<QRegion, const QRegion &, &QRegion::united>("united").create();
  // QRegion united(const QRect &) const;
  binder.fun<QRegion, const QRect &, &QRegion::united>("united").create();
  // QRegion intersected(const QRegion &) const;
  binder.fun<QRegion, const QRegion &, &QRegion::intersected>("intersected").create();
  // QRegion intersected(const QRect &) const;
  binder.fun<QRegion, const QRect &, &QRegion::intersected>("intersected").create();
  // QRegion subtracted(const QRegion &) const;
  binder.fun<QRegion, const QRegion &, &QRegion::subtracted>("subtracted").create();
  // QRegion xored(const QRegion &) const;
  binder.fun<QRegion, const QRegion &, &QRegion::xored>("xored").create();
  // bool intersects(const QRegion &) const;
  binder.fun<bool, const QRegion &, &QRegion::intersects>("intersects").create();
  // bool intersects(const QRect &) const;
  binder.fun<bool, const QRect &, &QRegion::intersects>("intersects").create();
  // QRect boundingRect() const;
  binder.fun<QRect, &QRegion::boundingRect>("boundingRect").create();
  // QVector<QRect> rects() const;
  /// TODO: QVector<QRect> rects() const;
  // void setRects(const QRect *, int);
  /// TODO: void setRects(const QRect *, int);
  // int rectCount() const;
  binder.fun<int, &QRegion::rectCount>("rectCount").create();
  // const QRegion operator|(const QRegion &) const;
  binder.operators().or<const QRegion, const QRegion &>();
  // const QRegion operator+(const QRegion &) const;
  binder.operators().add<const QRegion, const QRegion &>();
  // const QRegion operator+(const QRect &) const;
  binder.operators().add<const QRegion, const QRect &>();
  // const QRegion operator&(const QRegion &) const;
  binder.operators().and<const QRegion, const QRegion &>();
  // const QRegion operator&(const QRect &) const;
  binder.operators().and<const QRegion, const QRect &>();
  // const QRegion operator-(const QRegion &) const;
  binder.operators().sub<const QRegion, const QRegion &>();
  // const QRegion operator^(const QRegion &) const;
  binder.operators().xor<const QRegion, const QRegion &>();
  // QRegion & operator|=(const QRegion &);
  binder.operators().or_assign<const QRegion &>();
  // QRegion & operator+=(const QRegion &);
  binder.operators().add_assign<const QRegion &>();
  // QRegion & operator+=(const QRect &);
  binder.operators().add_assign<const QRect &>();
  // QRegion & operator&=(const QRegion &);
  binder.operators().and_assign<const QRegion &>();
  // QRegion & operator&=(const QRect &);
  binder.operators().and_assign<const QRect &>();
  // QRegion & operator-=(const QRegion &);
  binder.operators().sub_assign<const QRegion &>();
  // QRegion & operator^=(const QRegion &);
  binder.operators().xor_assign<const QRegion &>();
  // bool operator==(const QRegion &) const;
  binder.operators().eq<const QRegion &>();
  // bool operator!=(const QRegion &) const;
  binder.operators().neq<const QRegion &>();
}


void register_region_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_region_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QRegion &, QRegion &);
  binder.void_fun<QRegion &, QRegion &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QRegion &);
  binder.operators().put_to<QDataStream &, const QRegion &>();
  // QDataStream & operator>>(QDataStream &, QRegion &);
  binder.operators().read_from<QDataStream &, QRegion &>();
  // QDebug operator<<(QDebug, const QRegion &);
  /// TODO: QDebug operator<<(QDebug, const QRegion &);
}

