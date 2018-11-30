// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/region.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

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

  Enum region_type = region.newEnum("RegionType").setId(script::Type::QRegionRegionType).get();

  region_type.addValue("Rectangle", QRegion::Rectangle);
  region_type.addValue("Ellipse", QRegion::Ellipse);
}


static void register_region_class(script::Namespace ns)
{
  using namespace script;

  Class region = ns.newClass("Region").setId(script::Type::QRegion).get();

  register_region_region_type_enum(region);

  // QRegion();
  bind::default_constructor<QRegion>(region).create();
  // QRegion(int, int, int, int, QRegion::RegionType = QRegion::Rectangle);
  bind::constructor<QRegion, int, int, int, int, QRegion::RegionType>(region)
    .apply(bind::default_arguments(QRegion::Rectangle)).create();
  // QRegion(const QRect &, QRegion::RegionType = QRegion::Rectangle);
  bind::constructor<QRegion, const QRect &, QRegion::RegionType>(region)
    .apply(bind::default_arguments(QRegion::Rectangle)).create();
  // QRegion(const QPolygon &, Qt::FillRule = Qt::OddEvenFill);
  /// TODO: QRegion(const QPolygon &, Qt::FillRule = Qt::OddEvenFill);
  // QRegion(const QRegion &);
  bind::constructor<QRegion, const QRegion &>(region).create();
  // QRegion(QRegion &&);
  bind::constructor<QRegion, QRegion &&>(region).create();
  // QRegion(const QBitmap &);
  bind::constructor<QRegion, const QBitmap &>(region).create();
  // ~QRegion();
  bind::destructor<QRegion>(region).create();
  // QRegion & operator=(const QRegion &);
  bind::memop_assign<QRegion, const QRegion &>(region);
  // QRegion & operator=(QRegion &&);
  bind::memop_assign<QRegion, QRegion &&>(region);
  // void swap(QRegion &);
  bind::void_member_function<QRegion, QRegion &, &QRegion::swap>(region, "swap").create();
  // bool isEmpty() const;
  bind::member_function<QRegion, bool, &QRegion::isEmpty>(region, "isEmpty").create();
  // bool isNull() const;
  bind::member_function<QRegion, bool, &QRegion::isNull>(region, "isNull").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_iterator begin() const;
  /// TODO: QRegion::const_iterator begin() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_iterator cbegin() const;
  /// TODO: QRegion::const_iterator cbegin() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_iterator end() const;
  /// TODO: QRegion::const_iterator end() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_iterator cend() const;
  /// TODO: QRegion::const_iterator cend() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_reverse_iterator rbegin() const;
  /// TODO: QRegion::const_reverse_iterator rbegin() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_reverse_iterator crbegin() const;
  /// TODO: QRegion::const_reverse_iterator crbegin() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_reverse_iterator rend() const;
  /// TODO: QRegion::const_reverse_iterator rend() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // QRegion::const_reverse_iterator crend() const;
  /// TODO: QRegion::const_reverse_iterator crend() const;
#endif
  // bool contains(const QPoint &) const;
  bind::member_function<QRegion, bool, const QPoint &, &QRegion::contains>(region, "contains").create();
  // bool contains(const QRect &) const;
  bind::member_function<QRegion, bool, const QRect &, &QRegion::contains>(region, "contains").create();
  // void translate(int, int);
  bind::void_member_function<QRegion, int, int, &QRegion::translate>(region, "translate").create();
  // void translate(const QPoint &);
  bind::void_member_function<QRegion, const QPoint &, &QRegion::translate>(region, "translate").create();
  // QRegion translated(int, int) const;
  bind::member_function<QRegion, QRegion, int, int, &QRegion::translated>(region, "translated").create();
  // QRegion translated(const QPoint &) const;
  bind::member_function<QRegion, QRegion, const QPoint &, &QRegion::translated>(region, "translated").create();
  // QRegion united(const QRegion &) const;
  bind::member_function<QRegion, QRegion, const QRegion &, &QRegion::united>(region, "united").create();
  // QRegion united(const QRect &) const;
  bind::member_function<QRegion, QRegion, const QRect &, &QRegion::united>(region, "united").create();
  // QRegion intersected(const QRegion &) const;
  bind::member_function<QRegion, QRegion, const QRegion &, &QRegion::intersected>(region, "intersected").create();
  // QRegion intersected(const QRect &) const;
  bind::member_function<QRegion, QRegion, const QRect &, &QRegion::intersected>(region, "intersected").create();
  // QRegion subtracted(const QRegion &) const;
  bind::member_function<QRegion, QRegion, const QRegion &, &QRegion::subtracted>(region, "subtracted").create();
  // QRegion xored(const QRegion &) const;
  bind::member_function<QRegion, QRegion, const QRegion &, &QRegion::xored>(region, "xored").create();
  // bool intersects(const QRegion &) const;
  bind::member_function<QRegion, bool, const QRegion &, &QRegion::intersects>(region, "intersects").create();
  // bool intersects(const QRect &) const;
  bind::member_function<QRegion, bool, const QRect &, &QRegion::intersects>(region, "intersects").create();
  // QRect boundingRect() const;
  bind::member_function<QRegion, QRect, &QRegion::boundingRect>(region, "boundingRect").create();
  // QVector<QRect> rects() const;
  /// TODO: QVector<QRect> rects() const;
  // void setRects(const QRect *, int);
  /// TODO: void setRects(const QRect *, int);
  // int rectCount() const;
  bind::member_function<QRegion, int, &QRegion::rectCount>(region, "rectCount").create();
  // const QRegion operator|(const QRegion &) const;
  bind::memop_bitor<QRegion, const QRegion, const QRegion &>(region);
  // const QRegion operator+(const QRegion &) const;
  bind::memop_add<QRegion, const QRegion, const QRegion &>(region);
  // const QRegion operator+(const QRect &) const;
  bind::memop_add<QRegion, const QRegion, const QRect &>(region);
  // const QRegion operator&(const QRegion &) const;
  bind::memop_bitand<QRegion, const QRegion, const QRegion &>(region);
  // const QRegion operator&(const QRect &) const;
  bind::memop_bitand<QRegion, const QRegion, const QRect &>(region);
  // const QRegion operator-(const QRegion &) const;
  bind::memop_sub<QRegion, const QRegion, const QRegion &>(region);
  // const QRegion operator^(const QRegion &) const;
  bind::memop_bitxor<QRegion, const QRegion, const QRegion &>(region);
  // QRegion & operator|=(const QRegion &);
  bind::memop_or_assign<QRegion, const QRegion &>(region);
  // QRegion & operator+=(const QRegion &);
  bind::memop_add_assign<QRegion, const QRegion &>(region);
  // QRegion & operator+=(const QRect &);
  bind::memop_add_assign<QRegion, const QRect &>(region);
  // QRegion & operator&=(const QRegion &);
  bind::memop_and_assign<QRegion, const QRegion &>(region);
  // QRegion & operator&=(const QRect &);
  bind::memop_and_assign<QRegion, const QRect &>(region);
  // QRegion & operator-=(const QRegion &);
  bind::memop_sub_assign<QRegion, const QRegion &>(region);
  // QRegion & operator^=(const QRegion &);
  bind::memop_xor_assign<QRegion, const QRegion &>(region);
  // bool operator==(const QRegion &) const;
  bind::memop_eq<QRegion, const QRegion &>(region);
  // bool operator!=(const QRegion &) const;
  bind::memop_neq<QRegion, const QRegion &>(region);

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QRegion, QMetaType::QRegion>>();
}


void register_region_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_region_class(ns);

  // void swap(QRegion &, QRegion &);
  bind::void_function<QRegion &, QRegion &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QRegion &);
  bind::op_put_to<QDataStream &, const QRegion &>(ns);
  // QDataStream & operator>>(QDataStream &, QRegion &);
  bind::op_read_from<QDataStream &, QRegion &>(ns);
  // QDebug operator<<(QDebug, const QRegion &);
  /// TODO: QDebug operator<<(QDebug, const QRegion &);
}

