// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pen.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"

#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_pen_class(script::Namespace ns)
{
  using namespace script;

  Class pen = ns.Class("Pen").setId(script::Type::QPen).get();

  binding::Class<QPen> binder{ pen };

  // ~QPen();
  binder.add_dtor();
  // QPen();
  binder.ctors().add_default();
  // QPen(Qt::PenStyle);
  binder.ctors().add<Qt::PenStyle>();
  // QPen(const QColor &);
  binder.ctors().add<const QColor &>();
  // QPen(const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
  binder.ctors().add<const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle>();
  // QPen(const QPen &);
  binder.ctors().add<const QPen &>();
  // QPen & operator=(const QPen &);
  binder.operators().assign<const QPen &>();
  // QPen(QPen &&);
  binder.ctors().add<QPen &&>();
  // QPen & operator=(QPen &&);
  binder.operators().assign<QPen &&>();
  // void swap(QPen &);
  binder.add_void_fun<QPen &, &QPen::swap>("swap");
  // Qt::PenStyle style() const;
  binder.add_fun<Qt::PenStyle, &QPen::style>("style");
  // void setStyle(Qt::PenStyle);
  binder.add_void_fun<Qt::PenStyle, &QPen::setStyle>("setStyle");
  // QVector<qreal> dashPattern() const;
  binder.add_fun<QVector<qreal>, &QPen::dashPattern>("dashPattern");
  // void setDashPattern(const QVector<qreal> &);
  binder.add_void_fun<const QVector<qreal> &, &QPen::setDashPattern>("setDashPattern");
  // qreal dashOffset() const;
  binder.add_fun<qreal, &QPen::dashOffset>("dashOffset");
  // void setDashOffset(qreal);
  binder.add_void_fun<qreal, &QPen::setDashOffset>("setDashOffset");
  // qreal miterLimit() const;
  binder.add_fun<qreal, &QPen::miterLimit>("miterLimit");
  // void setMiterLimit(qreal);
  binder.add_void_fun<qreal, &QPen::setMiterLimit>("setMiterLimit");
  // qreal widthF() const;
  binder.add_fun<qreal, &QPen::widthF>("widthF");
  // void setWidthF(qreal);
  binder.add_void_fun<qreal, &QPen::setWidthF>("setWidthF");
  // int width() const;
  binder.add_fun<int, &QPen::width>("width");
  // void setWidth(int);
  binder.add_void_fun<int, &QPen::setWidth>("setWidth");
  // QColor color() const;
  binder.add_fun<QColor, &QPen::color>("color");
  // void setColor(const QColor &);
  binder.add_void_fun<const QColor &, &QPen::setColor>("setColor");
  // QBrush brush() const;
  binder.add_fun<QBrush, &QPen::brush>("brush");
  // void setBrush(const QBrush &);
  binder.add_void_fun<const QBrush &, &QPen::setBrush>("setBrush");
  // bool isSolid() const;
  binder.add_fun<bool, &QPen::isSolid>("isSolid");
  // Qt::PenCapStyle capStyle() const;
  binder.add_fun<Qt::PenCapStyle, &QPen::capStyle>("capStyle");
  // void setCapStyle(Qt::PenCapStyle);
  binder.add_void_fun<Qt::PenCapStyle, &QPen::setCapStyle>("setCapStyle");
  // Qt::PenJoinStyle joinStyle() const;
  binder.add_fun<Qt::PenJoinStyle, &QPen::joinStyle>("joinStyle");
  // void setJoinStyle(Qt::PenJoinStyle);
  binder.add_void_fun<Qt::PenJoinStyle, &QPen::setJoinStyle>("setJoinStyle");
  // bool isCosmetic() const;
  binder.add_fun<bool, &QPen::isCosmetic>("isCosmetic");
  // void setCosmetic(bool);
  binder.add_void_fun<bool, &QPen::setCosmetic>("setCosmetic");
  // bool operator==(const QPen &) const;
  binder.operators().eq<const QPen &>();
  // bool operator!=(const QPen &) const;
  binder.operators().neq<const QPen &>();
  // bool isDetached();
  binder.add_fun<bool, &QPen::isDetached>("isDetached");
}

void register_pen_file(script::Namespace root)
{
  using namespace script;

  register_pen_class(root);
  binding::Namespace binder{ root };

  // QDataStream & operator<<(QDataStream &, const QPen &);
  binder.operators().put_to<QDataStream &, const QPen &>();
  // QDataStream & operator>>(QDataStream &, QPen &);
  binder.operators().read_from<QDataStream &, QPen &>();
  // void swap(QPen &, QPen &);
  binder.add_void_fun<QPen &, QPen &, &swap>("swap");
  // QDebug operator<<(QDebug, const QPen &);
  binder.operators().left_shift<QDebug, QDebug, const QPen &>();
}

