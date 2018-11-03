// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/variant.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/char.h"
#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/jsonarray.h"
#include "yasl/core/jsondocument.h"
#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"
#include "yasl/core/line.h"
#include "yasl/core/locale.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/regularexpression.h"
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
  binder.ctors().default_ctor().create();
  // ~QVariant();
  binder.add_dtor();
  // QVariant(QVariant::Type);
  binder.ctors().ctor<QVariant::Type>().create();
  // QVariant(int, const void *);
  /// TODO: QVariant(int, const void *);
  // QVariant(int, const void *, uint);
  /// TODO: QVariant(int, const void *, uint);
  // QVariant(const QVariant &);
  binder.ctors().ctor<const QVariant &>().create();
  // QVariant(QDataStream &);
  binder.ctors().ctor<QDataStream &>().create();
  // QVariant(int);
  binder.ctors().ctor<int>().create();
  // QVariant(qlonglong);
  /// TODO: QVariant(qlonglong);
  // QVariant(qulonglong);
  /// TODO: QVariant(qulonglong);
  // QVariant(bool);
  binder.ctors().ctor<bool>().create();
  // QVariant(double);
  binder.ctors().ctor<double>().create();
  // QVariant(float);
  binder.ctors().ctor<float>().create();
  // QVariant(const char *);
  /// TODO: QVariant(const char *);
  // QVariant(const QByteArray &);
  binder.ctors().ctor<const QByteArray &>().create();
  // QVariant(const QBitArray &);
  /// TODO: QVariant(const QBitArray &);
  // QVariant(const QString &);
  binder.ctors().ctor<const QString &>().create();
  // QVariant(QLatin1String);
  /// TODO: QVariant(QLatin1String);
  // QVariant(const QStringList &);
  /// TODO: QVariant(const QStringList &);
  // QVariant(QChar);
  binder.ctors().ctor<QChar>().create();
  // QVariant(const QDate &);
  binder.ctors().ctor<const QDate &>().create();
  // QVariant(const QTime &);
  binder.ctors().ctor<const QTime &>().create();
  // QVariant(const QDateTime &);
  binder.ctors().ctor<const QDateTime &>().create();
  // QVariant(const QList<QVariant> &);
  /// TODO: QVariant(const QList<QVariant> &);
  // QVariant(const QMap<QString, QVariant> &);
  /// TODO: QVariant(const QMap<QString, QVariant> &);
  // QVariant(const QHash<QString, QVariant> &);
  /// TODO: QVariant(const QHash<QString, QVariant> &);
  // QVariant(const QSize &);
  binder.ctors().ctor<const QSize &>().create();
  // QVariant(const QSizeF &);
  binder.ctors().ctor<const QSizeF &>().create();
  // QVariant(const QPoint &);
  binder.ctors().ctor<const QPoint &>().create();
  // QVariant(const QPointF &);
  binder.ctors().ctor<const QPointF &>().create();
  // QVariant(const QLine &);
  binder.ctors().ctor<const QLine &>().create();
  // QVariant(const QLineF &);
  binder.ctors().ctor<const QLineF &>().create();
  // QVariant(const QRect &);
  binder.ctors().ctor<const QRect &>().create();
  // QVariant(const QRectF &);
  binder.ctors().ctor<const QRectF &>().create();
  // QVariant(const QLocale &);
  binder.ctors().ctor<const QLocale &>().create();
  // QVariant(const QRegExp &);
  /// TODO: QVariant(const QRegExp &);
  // QVariant(const QRegularExpression &);
  binder.ctors().ctor<const QRegularExpression &>().create();
  // QVariant(const QUrl &);
  binder.ctors().ctor<const QUrl &>().create();
  // QVariant(const QEasingCurve &);
  /// TODO: QVariant(const QEasingCurve &);
  // QVariant(const QUuid &);
  binder.ctors().ctor<const QUuid &>().create();
  // QVariant(const QModelIndex &);
  /// TODO: QVariant(const QModelIndex &);
  // QVariant(const QPersistentModelIndex &);
  /// TODO: QVariant(const QPersistentModelIndex &);
  // QVariant(const QJsonValue &);
  binder.ctors().ctor<const QJsonValue &>().create();
  // QVariant(const QJsonObject &);
  binder.ctors().ctor<const QJsonObject &>().create();
  // QVariant(const QJsonArray &);
  binder.ctors().ctor<const QJsonArray &>().create();
  // QVariant(const QJsonDocument &);
  binder.ctors().ctor<const QJsonDocument &>().create();
  // QVariant & operator=(const QVariant &);
  binder.operators().assign<const QVariant &>();
  // QVariant(QVariant &&);
  binder.ctors().ctor<QVariant &&>().create();
  // QVariant & operator=(QVariant &&);
  binder.operators().assign<QVariant &&>();
  // void swap(QVariant &);
  binder.void_fun<QVariant &, &QVariant::swap>("swap").create();
  // QVariant::Type type() const;
  binder.fun<QVariant::Type, &QVariant::type>("type").create();
  // int userType() const;
  binder.fun<int, &QVariant::userType>("userType").create();
  // const char * typeName() const;
  /// TODO: const char * typeName() const;
  // bool canConvert(int) const;
  binder.fun<bool, int, &QVariant::canConvert>("canConvert").create();
  // bool convert(int);
  binder.fun<bool, int, &QVariant::convert>("convert").create();
  // bool isValid() const;
  binder.fun<bool, &QVariant::isValid>("isValid").create();
  // bool isNull() const;
  binder.fun<bool, &QVariant::isNull>("isNull").create();
  // void clear();
  binder.void_fun<&QVariant::clear>("clear").create();
  // void detach();
  binder.void_fun<&QVariant::detach>("detach").create();
  // bool isDetached() const;
  binder.fun<bool, &QVariant::isDetached>("isDetached").create();
  // int va_toInt();
  binder.fun<int, &va_toInt>("toInt").create();
  // bool toBool() const;
  binder.fun<bool, &QVariant::toBool>("toBool").create();
  // double va_toDouble();
  binder.fun<double, &va_toDouble>("toDouble").create();
  // float va_toFloat();
  binder.fun<float, &va_toFloat>("toFloat").create();
  // qreal toReal(bool *) const;
  /// TODO: qreal toReal(bool *) const;
  // QByteArray toByteArray() const;
  binder.fun<QByteArray, &QVariant::toByteArray>("toByteArray").create();
  // QBitArray toBitArray() const;
  /// TODO: QBitArray toBitArray() const;
  // QString toString() const;
  binder.fun<QString, &QVariant::toString>("toString").create();
  // QStringList toStringList() const;
  /// TODO: QStringList toStringList() const;
  // QChar toChar() const;
  binder.fun<QChar, &QVariant::toChar>("toChar").create();
  // QDate toDate() const;
  binder.fun<QDate, &QVariant::toDate>("toDate").create();
  // QTime toTime() const;
  binder.fun<QTime, &QVariant::toTime>("toTime").create();
  // QDateTime toDateTime() const;
  binder.fun<QDateTime, &QVariant::toDateTime>("toDateTime").create();
  // QList<QVariant> toList() const;
  /// TODO: QList<QVariant> toList() const;
  // QMap<QString, QVariant> toMap() const;
  /// TODO: QMap<QString, QVariant> toMap() const;
  // QHash<QString, QVariant> toHash() const;
  /// TODO: QHash<QString, QVariant> toHash() const;
  // QPoint toPoint() const;
  binder.fun<QPoint, &QVariant::toPoint>("toPoint").create();
  // QPointF toPointF() const;
  binder.fun<QPointF, &QVariant::toPointF>("toPointF").create();
  // QRect toRect() const;
  binder.fun<QRect, &QVariant::toRect>("toRect").create();
  // QSize toSize() const;
  binder.fun<QSize, &QVariant::toSize>("toSize").create();
  // QSizeF toSizeF() const;
  binder.fun<QSizeF, &QVariant::toSizeF>("toSizeF").create();
  // QLine toLine() const;
  binder.fun<QLine, &QVariant::toLine>("toLine").create();
  // QLineF toLineF() const;
  binder.fun<QLineF, &QVariant::toLineF>("toLineF").create();
  // QRectF toRectF() const;
  binder.fun<QRectF, &QVariant::toRectF>("toRectF").create();
  // QLocale toLocale() const;
  binder.fun<QLocale, &QVariant::toLocale>("toLocale").create();
  // QRegExp toRegExp() const;
  /// TODO: QRegExp toRegExp() const;
  // QRegularExpression toRegularExpression() const;
  binder.fun<QRegularExpression, &QVariant::toRegularExpression>("toRegularExpression").create();
  // QUrl toUrl() const;
  binder.fun<QUrl, &QVariant::toUrl>("toUrl").create();
  // QEasingCurve toEasingCurve() const;
  /// TODO: QEasingCurve toEasingCurve() const;
  // QUuid toUuid() const;
  binder.fun<QUuid, &QVariant::toUuid>("toUuid").create();
  // QModelIndex toModelIndex() const;
  /// TODO: QModelIndex toModelIndex() const;
  // QPersistentModelIndex toPersistentModelIndex() const;
  /// TODO: QPersistentModelIndex toPersistentModelIndex() const;
  // QJsonValue toJsonValue() const;
  binder.fun<QJsonValue, &QVariant::toJsonValue>("toJsonValue").create();
  // QJsonObject toJsonObject() const;
  binder.fun<QJsonObject, &QVariant::toJsonObject>("toJsonObject").create();
  // QJsonArray toJsonArray() const;
  binder.fun<QJsonArray, &QVariant::toJsonArray>("toJsonArray").create();
  // QJsonDocument toJsonDocument() const;
  binder.fun<QJsonDocument, &QVariant::toJsonDocument>("toJsonDocument").create();
  // void load(QDataStream &);
  binder.void_fun<QDataStream &, &QVariant::load>("load").create();
  // void save(QDataStream &) const;
  binder.const_void_fun<QDataStream &, &QVariant::save>("save").create();
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
  binder.fun<bool, const QVariant &, &QVariant::cmp>("cmp").create();
  // int compare(const QVariant &) const;
  binder.fun<int, const QVariant &, &QVariant::compare>("compare").create();
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
  binder.operators().read_from<QDataStream &, QVariant &>();
  // QDataStream & operator<<(QDataStream &, const QVariant &);
  binder.operators().put_to<QDataStream &, const QVariant &>();
  // QDataStream & operator>>(QDataStream &, QVariant::Type &);
  binder.operators().read_from<QDataStream &, QVariant::Type &>();
  // QDataStream & operator<<(QDataStream &, const QVariant::Type);
  binder.operators().put_to<QDataStream &, const QVariant::Type>();
  // void swap(QVariant &, QVariant &);
  binder.void_fun<QVariant &, QVariant &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QVariant &);
  /// TODO: QDebug operator<<(QDebug, const QVariant &);
  // QDebug operator<<(QDebug, const QVariant::Type);
  /// TODO: QDebug operator<<(QDebug, const QVariant::Type);
}

