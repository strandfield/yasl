// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/variant.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/char.h"
#include "yasl/core/datetime.h"
#include "yasl/core/line.h"
#include "yasl/core/locale.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/core/url.h"
#include "yasl/core/uuid.h"
#include "yasl/core/variant-functions.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_variant_type_enum(script::Class variant)
{
  using namespace script;

  Enum type = variant.Enum("Type").setId(script::Type::QVariantType).get();

  type.addValue("Invalid", QVariant::Invalid);
  type.addValue("Bool", QVariant::Bool);
  type.addValue("Int", QVariant::Int);
  type.addValue("UInt", QVariant::UInt);
  type.addValue("LongLong", QVariant::LongLong);
  type.addValue("ULongLong", QVariant::ULongLong);
  type.addValue("Double", QVariant::Double);
  type.addValue("Char", QVariant::Char);
  type.addValue("Map", QVariant::Map);
  type.addValue("List", QVariant::List);
  type.addValue("String", QVariant::String);
  type.addValue("StringList", QVariant::StringList);
  type.addValue("ByteArray", QVariant::ByteArray);
  type.addValue("BitArray", QVariant::BitArray);
  type.addValue("Date", QVariant::Date);
  type.addValue("Time", QVariant::Time);
  type.addValue("DateTime", QVariant::DateTime);
  type.addValue("Url", QVariant::Url);
  type.addValue("Locale", QVariant::Locale);
  type.addValue("Rect", QVariant::Rect);
  type.addValue("RectF", QVariant::RectF);
  type.addValue("Size", QVariant::Size);
  type.addValue("SizeF", QVariant::SizeF);
  type.addValue("Line", QVariant::Line);
  type.addValue("LineF", QVariant::LineF);
  type.addValue("Point", QVariant::Point);
  type.addValue("PointF", QVariant::PointF);
  type.addValue("RegExp", QVariant::RegExp);
  type.addValue("RegularExpression", QVariant::RegularExpression);
  type.addValue("Hash", QVariant::Hash);
  type.addValue("EasingCurve", QVariant::EasingCurve);
  type.addValue("Uuid", QVariant::Uuid);
  type.addValue("ModelIndex", QVariant::ModelIndex);
  type.addValue("PersistentModelIndex", QVariant::PersistentModelIndex);
  type.addValue("LastCoreType", QVariant::LastCoreType);
  type.addValue("Font", QVariant::Font);
  type.addValue("Pixmap", QVariant::Pixmap);
  type.addValue("Brush", QVariant::Brush);
  type.addValue("Color", QVariant::Color);
  type.addValue("Palette", QVariant::Palette);
  type.addValue("Image", QVariant::Image);
  type.addValue("Polygon", QVariant::Polygon);
  type.addValue("Region", QVariant::Region);
  type.addValue("Bitmap", QVariant::Bitmap);
  type.addValue("Cursor", QVariant::Cursor);
  type.addValue("KeySequence", QVariant::KeySequence);
  type.addValue("Pen", QVariant::Pen);
  type.addValue("TextLength", QVariant::TextLength);
  type.addValue("TextFormat", QVariant::TextFormat);
  type.addValue("Matrix", QVariant::Matrix);
  type.addValue("Transform", QVariant::Transform);
  type.addValue("Matrix4x4", QVariant::Matrix4x4);
  type.addValue("Vector2D", QVariant::Vector2D);
  type.addValue("Vector3D", QVariant::Vector3D);
  type.addValue("Vector4D", QVariant::Vector4D);
  type.addValue("Quaternion", QVariant::Quaternion);
  type.addValue("PolygonF", QVariant::PolygonF);
  type.addValue("Icon", QVariant::Icon);
  type.addValue("LastGuiType", QVariant::LastGuiType);
  type.addValue("SizePolicy", QVariant::SizePolicy);
  type.addValue("UserType", QVariant::UserType);
  type.addValue("LastType", QVariant::LastType);
}


static void register_variant_class(script::Namespace ns)
{
  using namespace script;

  Class variant = ns.Class("Variant").setId(script::Type::QVariant).get();

  register_variant_type_enum(variant);
  binding::Class<QVariant> binder{ variant };

  // QVariant();
  binder.ctors().add_default();
  // ~QVariant();
  binder.add_dtor();
  // QVariant(QVariant::Type);
  binder.ctors().add<QVariant::Type>();
  // QVariant(int, const void *);
  /// TODO: QVariant(int, const void *);
  // QVariant(int, const void *, uint);
  /// TODO: QVariant(int, const void *, uint);
  // QVariant(const QVariant &);
  binder.ctors().add<const QVariant &>();
  // QVariant(QDataStream &);
  /// TODO: QVariant(QDataStream &);
  // QVariant(int);
  binder.ctors().add<int>();
  // QVariant(qlonglong);
  /// TODO: QVariant(qlonglong);
  // QVariant(qulonglong);
  /// TODO: QVariant(qulonglong);
  // QVariant(bool);
  binder.ctors().add<bool>();
  // QVariant(double);
  binder.ctors().add<double>();
  // QVariant(float);
  binder.ctors().add<float>();
  // QVariant(const char *);
  /// TODO: QVariant(const char *);
  // QVariant(const QByteArray &);
  binder.ctors().add<const QByteArray &>();
  // QVariant(const QBitArray &);
  /// TODO: QVariant(const QBitArray &);
  // QVariant(const QString &);
  binder.ctors().add<const QString &>();
  // QVariant(QLatin1String);
  /// TODO: QVariant(QLatin1String);
  // QVariant(const QStringList &);
  /// TODO: QVariant(const QStringList &);
  // QVariant(QChar);
  binder.ctors().add<QChar>();
  // QVariant(const QDate &);
  binder.ctors().add<const QDate &>();
  // QVariant(const QTime &);
  binder.ctors().add<const QTime &>();
  // QVariant(const QDateTime &);
  binder.ctors().add<const QDateTime &>();
  // QVariant(const QList<QVariant> &);
  /// TODO: QVariant(const QList<QVariant> &);
  // QVariant(const QMap<QString, QVariant> &);
  /// TODO: QVariant(const QMap<QString, QVariant> &);
  // QVariant(const QHash<QString, QVariant> &);
  /// TODO: QVariant(const QHash<QString, QVariant> &);
  // QVariant(const QSize &);
  binder.ctors().add<const QSize &>();
  // QVariant(const QSizeF &);
  binder.ctors().add<const QSizeF &>();
  // QVariant(const QPoint &);
  binder.ctors().add<const QPoint &>();
  // QVariant(const QPointF &);
  binder.ctors().add<const QPointF &>();
  // QVariant(const QLine &);
  binder.ctors().add<const QLine &>();
  // QVariant(const QLineF &);
  binder.ctors().add<const QLineF &>();
  // QVariant(const QRect &);
  binder.ctors().add<const QRect &>();
  // QVariant(const QRectF &);
  binder.ctors().add<const QRectF &>();
  // QVariant(const QLocale &);
  binder.ctors().add<const QLocale &>();
  // QVariant(const QRegExp &);
  /// TODO: QVariant(const QRegExp &);
  // QVariant(const QRegularExpression &);
  /// TODO: QVariant(const QRegularExpression &);
  // QVariant(const QUrl &);
  binder.ctors().add<const QUrl &>();
  // QVariant(const QEasingCurve &);
  /// TODO: QVariant(const QEasingCurve &);
  // QVariant(const QUuid &);
  binder.ctors().add<const QUuid &>();
  // QVariant(const QModelIndex &);
  /// TODO: QVariant(const QModelIndex &);
  // QVariant(const QPersistentModelIndex &);
  /// TODO: QVariant(const QPersistentModelIndex &);
  // QVariant(const QJsonValue &);
  /// TODO: QVariant(const QJsonValue &);
  // QVariant(const QJsonObject &);
  /// TODO: QVariant(const QJsonObject &);
  // QVariant(const QJsonArray &);
  /// TODO: QVariant(const QJsonArray &);
  // QVariant(const QJsonDocument &);
  /// TODO: QVariant(const QJsonDocument &);
  // QVariant & operator=(const QVariant &);
  binder.operators().assign<const QVariant &>();
  // QVariant(QVariant &&);
  binder.ctors().add<QVariant &&>();
  // QVariant & operator=(QVariant &&);
  binder.operators().assign<QVariant &&>();
  // void swap(QVariant &);
  binder.add_void_fun<QVariant &, &QVariant::swap>("swap");
  // QVariant::Type type() const;
  binder.add_fun<QVariant::Type, &QVariant::type>("type");
  // int userType() const;
  binder.add_fun<int, &QVariant::userType>("userType");
  // const char * typeName() const;
  /// TODO: const char * typeName() const;
  // bool canConvert(int) const;
  binder.add_fun<bool, int, &QVariant::canConvert>("canConvert");
  // bool convert(int);
  binder.add_fun<bool, int, &QVariant::convert>("convert");
  // bool isValid() const;
  binder.add_fun<bool, &QVariant::isValid>("isValid");
  // bool isNull() const;
  binder.add_fun<bool, &QVariant::isNull>("isNull");
  // void clear();
  binder.add_void_fun<&QVariant::clear>("clear");
  // void detach();
  binder.add_void_fun<&QVariant::detach>("detach");
  // bool isDetached() const;
  binder.add_fun<bool, &QVariant::isDetached>("isDetached");
  // int va_toInt();
  binder.add_fun<int, &va_toInt>("toInt");
  // bool toBool() const;
  binder.add_fun<bool, &QVariant::toBool>("toBool");
  // double va_toDouble();
  binder.add_fun<double, &va_toDouble>("toDouble");
  // float va_toFloat();
  binder.add_fun<float, &va_toFloat>("toFloat");
  // qreal toReal(bool *) const;
  /// TODO: qreal toReal(bool *) const;
  // QByteArray toByteArray() const;
  binder.add_fun<QByteArray, &QVariant::toByteArray>("toByteArray");
  // QBitArray toBitArray() const;
  /// TODO: QBitArray toBitArray() const;
  // QString toString() const;
  binder.add_fun<QString, &QVariant::toString>("toString");
  // QStringList toStringList() const;
  /// TODO: QStringList toStringList() const;
  // QChar toChar() const;
  binder.add_fun<QChar, &QVariant::toChar>("toChar");
  // QDate toDate() const;
  binder.add_fun<QDate, &QVariant::toDate>("toDate");
  // QTime toTime() const;
  binder.add_fun<QTime, &QVariant::toTime>("toTime");
  // QDateTime toDateTime() const;
  binder.add_fun<QDateTime, &QVariant::toDateTime>("toDateTime");
  // QList<QVariant> toList() const;
  /// TODO: QList<QVariant> toList() const;
  // QMap<QString, QVariant> toMap() const;
  /// TODO: QMap<QString, QVariant> toMap() const;
  // QHash<QString, QVariant> toHash() const;
  /// TODO: QHash<QString, QVariant> toHash() const;
  // QPoint toPoint() const;
  binder.add_fun<QPoint, &QVariant::toPoint>("toPoint");
  // QPointF toPointF() const;
  binder.add_fun<QPointF, &QVariant::toPointF>("toPointF");
  // QRect toRect() const;
  binder.add_fun<QRect, &QVariant::toRect>("toRect");
  // QSize toSize() const;
  binder.add_fun<QSize, &QVariant::toSize>("toSize");
  // QSizeF toSizeF() const;
  binder.add_fun<QSizeF, &QVariant::toSizeF>("toSizeF");
  // QLine toLine() const;
  binder.add_fun<QLine, &QVariant::toLine>("toLine");
  // QLineF toLineF() const;
  binder.add_fun<QLineF, &QVariant::toLineF>("toLineF");
  // QRectF toRectF() const;
  binder.add_fun<QRectF, &QVariant::toRectF>("toRectF");
  // QLocale toLocale() const;
  binder.add_fun<QLocale, &QVariant::toLocale>("toLocale");
  // QRegExp toRegExp() const;
  /// TODO: QRegExp toRegExp() const;
  // QRegularExpression toRegularExpression() const;
  /// TODO: QRegularExpression toRegularExpression() const;
  // QUrl toUrl() const;
  binder.add_fun<QUrl, &QVariant::toUrl>("toUrl");
  // QEasingCurve toEasingCurve() const;
  /// TODO: QEasingCurve toEasingCurve() const;
  // QUuid toUuid() const;
  binder.add_fun<QUuid, &QVariant::toUuid>("toUuid");
  // QModelIndex toModelIndex() const;
  /// TODO: QModelIndex toModelIndex() const;
  // QPersistentModelIndex toPersistentModelIndex() const;
  /// TODO: QPersistentModelIndex toPersistentModelIndex() const;
  // QJsonValue toJsonValue() const;
  /// TODO: QJsonValue toJsonValue() const;
  // QJsonObject toJsonObject() const;
  /// TODO: QJsonObject toJsonObject() const;
  // QJsonArray toJsonArray() const;
  /// TODO: QJsonArray toJsonArray() const;
  // QJsonDocument toJsonDocument() const;
  /// TODO: QJsonDocument toJsonDocument() const;
  // void load(QDataStream &);
  /// TODO: void load(QDataStream &);
  // void save(QDataStream &) const;
  /// TODO: void save(QDataStream &) const;
  // static const char * typeToName(int);
  /// TODO: static const char * typeToName(int);
  // static QVariant::Type nameToType(const char *);
  /// TODO: static QVariant::Type nameToType(const char *);
  // void * data();
  /// TODO: void * data();
  // const void * constData() const;
  /// TODO: const void * constData() const;
  // const void * data() const;
  /// TODO: const void * data() const;
  // bool operator==(const QVariant &) const;
  binder.operators().eq<const QVariant &>();
  // bool operator!=(const QVariant &) const;
  binder.operators().neq<const QVariant &>();
  // bool operator<(const QVariant &) const;
  binder.operators().less<const QVariant &>();
  // bool operator<=(const QVariant &) const;
  binder.operators().leq<const QVariant &>();
  // bool operator>(const QVariant &) const;
  binder.operators().greater<const QVariant &>();
  // bool operator>=(const QVariant &) const;
  binder.operators().geq<const QVariant &>();
  // void create(int, const void *);
  /// TODO: void create(int, const void *);
  // bool cmp(const QVariant &) const;
  binder.add_fun<bool, const QVariant &, &QVariant::cmp>("cmp");
  // int compare(const QVariant &) const;
  binder.add_fun<int, const QVariant &, &QVariant::compare>("compare");
  // bool convert(const int, void *) const;
  /// TODO: bool convert(const int, void *) const;
  // QVariant::DataPtr & data_ptr();
  /// TODO: QVariant::DataPtr & data_ptr();
  // const QVariant::DataPtr & data_ptr() const;
  /// TODO: const QVariant::DataPtr & data_ptr() const;
}


void register_variant_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_variant_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator>>(QDataStream &, QVariant &);
  /// TODO: QDataStream & operator>>(QDataStream &, QVariant &);
  // QDataStream & operator<<(QDataStream &, const QVariant &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QVariant &);
  // QDataStream & operator>>(QDataStream &, QVariant::Type &);
  /// TODO: QDataStream & operator>>(QDataStream &, QVariant::Type &);
  // QDataStream & operator<<(QDataStream &, const QVariant::Type);
  /// TODO: QDataStream & operator<<(QDataStream &, const QVariant::Type);
  // void swap(QVariant &, QVariant &);
  binder.add_void_fun<QVariant &, QVariant &, &swap>("swap");
  // QDebug operator<<(QDebug, const QVariant &);
  /// TODO: QDebug operator<<(QDebug, const QVariant &);
  // QDebug operator<<(QDebug, const QVariant::Type);
  /// TODO: QDebug operator<<(QDebug, const QVariant::Type);
}

