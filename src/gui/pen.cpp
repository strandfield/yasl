// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pen.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/pen.h"

#include <script/classbuilder.h>

static void register_pen_class(script::Namespace ns)
{
  using namespace script;

  Class pen = ns.newClass("Pen").setId(script::Type::QPen).get();


  // QPen();
  bind::default_constructor<QPen>(pen).create();
  // QPen(Qt::PenStyle);
  bind::constructor<QPen, Qt::PenStyle>(pen).create();
  // QPen(const QColor &);
  bind::constructor<QPen, const QColor &>(pen).create();
  // QPen(const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
  bind::constructor<QPen, const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle>(pen)
    .apply(bind::default_arguments(Qt::BevelJoin, Qt::SquareCap, Qt::SolidLine)).create();
  // QPen(const QPen &);
  bind::constructor<QPen, const QPen &>(pen).create();
  // ~QPen();
  bind::destructor<QPen>(pen).create();
  // QPen & operator=(const QPen &);
  bind::memop_assign<QPen, const QPen &>(pen);
  // QPen(QPen &&);
  bind::constructor<QPen, QPen &&>(pen).create();
  // QPen & operator=(QPen &&);
  bind::memop_assign<QPen, QPen &&>(pen);
  // void swap(QPen &);
  bind::void_member_function<QPen, QPen &, &QPen::swap>(pen, "swap").create();
  // Qt::PenStyle style() const;
  bind::member_function<QPen, Qt::PenStyle, &QPen::style>(pen, "style").create();
  // void setStyle(Qt::PenStyle);
  bind::void_member_function<QPen, Qt::PenStyle, &QPen::setStyle>(pen, "setStyle").create();
  // QVector<qreal> dashPattern() const;
  /// TODO: QVector<qreal> dashPattern() const;
  // void setDashPattern(const QVector<qreal> &);
  /// TODO: void setDashPattern(const QVector<qreal> &);
  // qreal dashOffset() const;
  bind::member_function<QPen, qreal, &QPen::dashOffset>(pen, "dashOffset").create();
  // void setDashOffset(qreal);
  bind::void_member_function<QPen, qreal, &QPen::setDashOffset>(pen, "setDashOffset").create();
  // qreal miterLimit() const;
  bind::member_function<QPen, qreal, &QPen::miterLimit>(pen, "miterLimit").create();
  // void setMiterLimit(qreal);
  bind::void_member_function<QPen, qreal, &QPen::setMiterLimit>(pen, "setMiterLimit").create();
  // qreal widthF() const;
  bind::member_function<QPen, qreal, &QPen::widthF>(pen, "widthF").create();
  // void setWidthF(qreal);
  bind::void_member_function<QPen, qreal, &QPen::setWidthF>(pen, "setWidthF").create();
  // int width() const;
  bind::member_function<QPen, int, &QPen::width>(pen, "width").create();
  // void setWidth(int);
  bind::void_member_function<QPen, int, &QPen::setWidth>(pen, "setWidth").create();
  // QColor color() const;
  bind::member_function<QPen, QColor, &QPen::color>(pen, "color").create();
  // void setColor(const QColor &);
  bind::void_member_function<QPen, const QColor &, &QPen::setColor>(pen, "setColor").create();
  // QBrush brush() const;
  bind::member_function<QPen, QBrush, &QPen::brush>(pen, "brush").create();
  // void setBrush(const QBrush &);
  bind::void_member_function<QPen, const QBrush &, &QPen::setBrush>(pen, "setBrush").create();
  // bool isSolid() const;
  bind::member_function<QPen, bool, &QPen::isSolid>(pen, "isSolid").create();
  // Qt::PenCapStyle capStyle() const;
  bind::member_function<QPen, Qt::PenCapStyle, &QPen::capStyle>(pen, "capStyle").create();
  // void setCapStyle(Qt::PenCapStyle);
  bind::void_member_function<QPen, Qt::PenCapStyle, &QPen::setCapStyle>(pen, "setCapStyle").create();
  // Qt::PenJoinStyle joinStyle() const;
  bind::member_function<QPen, Qt::PenJoinStyle, &QPen::joinStyle>(pen, "joinStyle").create();
  // void setJoinStyle(Qt::PenJoinStyle);
  bind::void_member_function<QPen, Qt::PenJoinStyle, &QPen::setJoinStyle>(pen, "setJoinStyle").create();
  // bool isCosmetic() const;
  bind::member_function<QPen, bool, &QPen::isCosmetic>(pen, "isCosmetic").create();
  // void setCosmetic(bool);
  bind::void_member_function<QPen, bool, &QPen::setCosmetic>(pen, "setCosmetic").create();
  // bool operator==(const QPen &) const;
  bind::memop_eq<QPen, const QPen &>(pen);
  // bool operator!=(const QPen &) const;
  bind::memop_neq<QPen, const QPen &>(pen);
  // bool isDetached();
  bind::member_function<QPen, bool, &QPen::isDetached>(pen, "isDetached").create();
  // QPen::DataPtr & data_ptr();
  /// TODO: QPen::DataPtr & data_ptr();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QPen, QMetaType::QPen>>();
}


void register_pen_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_pen_class(ns);

  // QDataStream & operator<<(QDataStream &, const QPen &);
  bind::op_put_to<QDataStream &, const QPen &>(ns);
  // QDataStream & operator>>(QDataStream &, QPen &);
  bind::op_read_from<QDataStream &, QPen &>(ns);
  // void swap(QPen &, QPen &);
  bind::void_function<QPen &, QPen &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QPen &);
  /// TODO: QDebug operator<<(QDebug, const QPen &);
}

