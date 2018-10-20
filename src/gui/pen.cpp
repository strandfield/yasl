// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pen.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/pen.h"

#include <script/classbuilder.h>

static void register_pen_class(script::Namespace ns)
{
  using namespace script;

  Class pen = ns.Class("Pen").setId(script::Type::QPen).get();

  binding::Class<QPen> binder{ pen };

  // QPen();
  binder.ctors().add_default();
  // QPen(Qt::PenStyle);
  binder.ctors().ctor<Qt::PenStyle>().create();
  // QPen(const QColor &);
  binder.ctors().ctor<const QColor &>().create();
  // QPen(const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
  binder.ctors().ctor<const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle>()
    .addDefaultArgument(binding::default_argument(pen.engine(), Qt::BevelJoin))
    .addDefaultArgument(binding::default_argument(pen.engine(), Qt::SquareCap))
    .addDefaultArgument(binding::default_argument(pen.engine(), Qt::SolidLine)).create();
  // QPen(const QPen &);
  binder.ctors().ctor<const QPen &>().create();
  // ~QPen();
  binder.add_dtor();
  // QPen & operator=(const QPen &);
  binder.operators().assign<const QPen &>();
  // QPen(QPen &&);
  binder.ctors().ctor<QPen &&>().create();
  // QPen & operator=(QPen &&);
  binder.operators().assign<QPen &&>();
  // void swap(QPen &);
  binder.void_fun<QPen &, &QPen::swap>("swap").create();
  // Qt::PenStyle style() const;
  binder.fun<Qt::PenStyle, &QPen::style>("style").create();
  // void setStyle(Qt::PenStyle);
  binder.void_fun<Qt::PenStyle, &QPen::setStyle>("setStyle").create();
  // QVector<qreal> dashPattern() const;
  /// TODO: QVector<qreal> dashPattern() const;
  // void setDashPattern(const QVector<qreal> &);
  /// TODO: void setDashPattern(const QVector<qreal> &);
  // qreal dashOffset() const;
  binder.fun<qreal, &QPen::dashOffset>("dashOffset").create();
  // void setDashOffset(qreal);
  binder.void_fun<qreal, &QPen::setDashOffset>("setDashOffset").create();
  // qreal miterLimit() const;
  binder.fun<qreal, &QPen::miterLimit>("miterLimit").create();
  // void setMiterLimit(qreal);
  binder.void_fun<qreal, &QPen::setMiterLimit>("setMiterLimit").create();
  // qreal widthF() const;
  binder.fun<qreal, &QPen::widthF>("widthF").create();
  // void setWidthF(qreal);
  binder.void_fun<qreal, &QPen::setWidthF>("setWidthF").create();
  // int width() const;
  binder.fun<int, &QPen::width>("width").create();
  // void setWidth(int);
  binder.void_fun<int, &QPen::setWidth>("setWidth").create();
  // QColor color() const;
  binder.fun<QColor, &QPen::color>("color").create();
  // void setColor(const QColor &);
  binder.void_fun<const QColor &, &QPen::setColor>("setColor").create();
  // QBrush brush() const;
  binder.fun<QBrush, &QPen::brush>("brush").create();
  // void setBrush(const QBrush &);
  binder.void_fun<const QBrush &, &QPen::setBrush>("setBrush").create();
  // bool isSolid() const;
  binder.fun<bool, &QPen::isSolid>("isSolid").create();
  // Qt::PenCapStyle capStyle() const;
  binder.fun<Qt::PenCapStyle, &QPen::capStyle>("capStyle").create();
  // void setCapStyle(Qt::PenCapStyle);
  binder.void_fun<Qt::PenCapStyle, &QPen::setCapStyle>("setCapStyle").create();
  // Qt::PenJoinStyle joinStyle() const;
  binder.fun<Qt::PenJoinStyle, &QPen::joinStyle>("joinStyle").create();
  // void setJoinStyle(Qt::PenJoinStyle);
  binder.void_fun<Qt::PenJoinStyle, &QPen::setJoinStyle>("setJoinStyle").create();
  // bool isCosmetic() const;
  binder.fun<bool, &QPen::isCosmetic>("isCosmetic").create();
  // void setCosmetic(bool);
  binder.void_fun<bool, &QPen::setCosmetic>("setCosmetic").create();
  // bool operator==(const QPen &) const;
  binder.operators().eq<const QPen &>();
  // bool operator!=(const QPen &) const;
  binder.operators().neq<const QPen &>();
  // bool isDetached();
  binder.fun<bool, &QPen::isDetached>("isDetached").create();
  // QPen::DataPtr & data_ptr();
  /// TODO: QPen::DataPtr & data_ptr();
}


void register_pen_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_pen_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QPen &);
  binder.operators().put_to<QDataStream &, const QPen &>();
  // QDataStream & operator>>(QDataStream &, QPen &);
  binder.operators().read_from<QDataStream &, QPen &>();
  // void swap(QPen &, QPen &);
  binder.void_fun<QPen &, QPen &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QPen &);
  /// TODO: QDebug operator<<(QDebug, const QPen &);
}

