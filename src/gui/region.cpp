// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "qregion.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"

#include "yasl/gui/bitmap.h"
#include "yasl/gui/polygon.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_region_region_type_enum(script::Class region)
{
  using namespace script;

  Enum region_type = region.Enum("RegionType").setId(script::Type::QRegionRegionType).get();

  region_type.addValue("Ellipse", QRegion::Ellipse);
  region_type.addValue("Rectangle", QRegion::Rectangle);
}

static void register_region_class(script::Namespace ns)
{
  using namespace script;

  Class region = ns.Class("Region").setId(script::Type::QRegion).get();

  register_region_region_type_enum(region);
  binding::Class<QRegion> binder{ region };

  // QRegion();
  binder.ctors().add_default();
  // QRegion(int, int, int, int, QRegion::RegionType);
  binder.ctors().add<int, int, int, int, QRegion::RegionType>();
  // QRegion(const QRect &, QRegion::RegionType);
  binder.ctors().add<const QRect &, QRegion::RegionType>();
  // QRegion(const QPolygon &, Qt::FillRule);
  binder.ctors().add<const QPolygon &, Qt::FillRule>();
  // QRegion(const QRegion &);
  binder.ctors().add<const QRegion &>();
  // QRegion(QRegion &&);
  binder.ctors().add<QRegion &&>();
  // QRegion(const QBitmap &);
  binder.ctors().add<const QBitmap &>();
  // QRegion & operator=(const QRegion &);
  binder.operators().assign<const QRegion &>();
  // QRegion & operator=(QRegion &&);
  binder.operators().assign<QRegion &&>();
  // void swap(QRegion &);
  binder.add_void_fun<QRegion &, &QRegion::swap>("swap");
  // bool isEmpty() const;
  binder.add_fun<bool, &QRegion::isEmpty>("isEmpty");
  // bool isNull() const;
  binder.add_fun<bool, &QRegion::isNull>("isNull");
  // QRegion::const_iterator begin() const;
  binder.add_fun<QRegion::const_iterator, &QRegion::begin>("begin");
  // QRegion::const_iterator cbegin() const;
  binder.add_fun<QRegion::const_iterator, &QRegion::cbegin>("cbegin");
  // QRegion::const_iterator end() const;
  binder.add_fun<QRegion::const_iterator, &QRegion::end>("end");
  // QRegion::const_iterator cend() const;
  binder.add_fun<QRegion::const_iterator, &QRegion::cend>("cend");
  // QRegion::const_reverse_iterator rbegin() const;
  binder.add_fun<QRegion::const_reverse_iterator, &QRegion::rbegin>("rbegin");
  // QRegion::const_reverse_iterator crbegin() const;
  binder.add_fun<QRegion::const_reverse_iterator, &QRegion::crbegin>("crbegin");
  // QRegion::const_reverse_iterator rend() const;
  binder.add_fun<QRegion::const_reverse_iterator, &QRegion::rend>("rend");
  // QRegion::const_reverse_iterator crend() const;
  binder.add_fun<QRegion::const_reverse_iterator, &QRegion::crend>("crend");
  // bool contains(const QPoint &) const;
  binder.add_fun<bool, const QPoint &, &QRegion::contains>("contains");
  // bool contains(const QRect &) const;
  binder.add_fun<bool, const QRect &, &QRegion::contains>("contains");
  // void translate(int, int);
  binder.add_void_fun<int, int, &QRegion::translate>("translate");
  // void translate(const QPoint &);
  binder.add_void_fun<const QPoint &, &QRegion::translate>("translate");
  // QRegion translated(int, int) const;
  binder.add_fun<QRegion, int, int, &QRegion::translated>("translated");
  // QRegion translated(const QPoint &) const;
  binder.add_fun<QRegion, const QPoint &, &QRegion::translated>("translated");
  // QRegion united(const QRegion &) const;
  binder.add_fun<QRegion, const QRegion &, &QRegion::united>("united");
  // QRegion united(const QRect &) const;
  binder.add_fun<QRegion, const QRect &, &QRegion::united>("united");
  // QRegion intersected(const QRegion &) const;
  binder.add_fun<QRegion, const QRegion &, &QRegion::intersected>("intersected");
  // QRegion intersected(const QRect &) const;
  binder.add_fun<QRegion, const QRect &, &QRegion::intersected>("intersected");
  // QRegion subtracted(const QRegion &) const;
  binder.add_fun<QRegion, const QRegion &, &QRegion::subtracted>("subtracted");
  // QRegion xored(const QRegion &) const;
  binder.add_fun<QRegion, const QRegion &, &QRegion::xored>("xored");
  // bool intersects(const QRegion &) const;
  binder.add_fun<bool, const QRegion &, &QRegion::intersects>("intersects");
  // bool intersects(const QRect &) const;
  binder.add_fun<bool, const QRect &, &QRegion::intersects>("intersects");
  // QRect boundingRect() const;
  binder.add_fun<QRect, &QRegion::boundingRect>("boundingRect");
  // QVector<QRect> rects() const;
  binder.add_fun<QVector<QRect>, &QRegion::rects>("rects");
  // void setRects(const QRect *, int);
  binder.add_void_fun<const QRect *, int, &QRegion::setRects>("setRects");
  // int rectCount() const;
  binder.add_fun<int, &QRegion::rectCount>("rectCount");
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

void register_region_file(script::Namespace root)
{
  using namespace script;

  register_region_class(root);
  binding::Namespace binder{ root };

  // void swap(QRegion &, QRegion &);
  binder.add_void_fun<QRegion &, QRegion &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QRegion &);
  binder.operators().put_to<QDataStream &, const QRegion &>();
  // QDataStream & operator>>(QDataStream &, QRegion &);
  binder.operators().read_from<QDataStream &, QRegion &>();
  // QDebug operator<<(QDebug, const QRegion &);
  binder.operators().left_shift<QDebug, QDebug, const QRegion &>();
}

