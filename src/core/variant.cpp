// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/variant.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/char.h"
#include "yasl/core/date.h"
#include "yasl/core/datetime.h"
#include "yasl/core/line.h"
#include "yasl/core/locale.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/regularexpression.h"
#include "yasl/core/size.h"
#include "yasl/core/time.h"
#include "yasl/core/url.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#include <QBitArray>
#include <QDataStream>
#include <QDebug>
#include <QEasingCurve>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QUuid>

static void register_variant_type_enum(script::Class variant)
{
  using namespace script;

  Enum type = variant.Enum("Type").setId(script::Type::QVariantType).get();

  type.addValue("BitArray", QVariant::BitArray);
  type.addValue("Bitmap", QVariant::Bitmap);
  type.addValue("Bool", QVariant::Bool);
  type.addValue("Brush", QVariant::Brush);
  type.addValue("ByteArray", QVariant::ByteArray);
  type.addValue("Char", QVariant::Char);
  type.addValue("Color", QVariant::Color);
  type.addValue("Cursor", QVariant::Cursor);
  type.addValue("Date", QVariant::Date);
  type.addValue("DateTime", QVariant::DateTime);
  type.addValue("Double", QVariant::Double);
  type.addValue("EasingCurve", QVariant::EasingCurve);
  type.addValue("Font", QVariant::Font);
  type.addValue("Hash", QVariant::Hash);
  type.addValue("Icon", QVariant::Icon);
  type.addValue("Image", QVariant::Image);
  type.addValue("Int", QVariant::Int);
  type.addValue("Invalid", QVariant::Invalid);
  type.addValue("KeySequence", QVariant::KeySequence);
  type.addValue("LastCoreType", QVariant::LastCoreType);
  type.addValue("LastGuiType", QVariant::LastGuiType);
  type.addValue("LastType", QVariant::LastType);
  type.addValue("Line", QVariant::Line);
  type.addValue("LineF", QVariant::LineF);
  type.addValue("List", QVariant::List);
  type.addValue("Locale", QVariant::Locale);
  type.addValue("LongLong", QVariant::LongLong);
  type.addValue("Map", QVariant::Map);
  type.addValue("Matrix", QVariant::Matrix);
  type.addValue("Matrix4x4", QVariant::Matrix4x4);
  type.addValue("ModelIndex", QVariant::ModelIndex);
  type.addValue("Palette", QVariant::Palette);
  type.addValue("Pen", QVariant::Pen);
  type.addValue("PersistentModelIndex", QVariant::PersistentModelIndex);
  type.addValue("Pixmap", QVariant::Pixmap);
  type.addValue("Point", QVariant::Point);
  type.addValue("PointF", QVariant::PointF);
  type.addValue("Polygon", QVariant::Polygon);
  type.addValue("PolygonF", QVariant::PolygonF);
  type.addValue("Quaternion", QVariant::Quaternion);
  type.addValue("Rect", QVariant::Rect);
  type.addValue("RectF", QVariant::RectF);
  type.addValue("RegExp", QVariant::RegExp);
  type.addValue("Region", QVariant::Region);
  type.addValue("RegularExpression", QVariant::RegularExpression);
  type.addValue("Size", QVariant::Size);
  type.addValue("SizeF", QVariant::SizeF);
  type.addValue("SizePolicy", QVariant::SizePolicy);
  type.addValue("String", QVariant::String);
  type.addValue("StringList", QVariant::StringList);
  type.addValue("TextFormat", QVariant::TextFormat);
  type.addValue("TextLength", QVariant::TextLength);
  type.addValue("Time", QVariant::Time);
  type.addValue("Transform", QVariant::Transform);
  type.addValue("UInt", QVariant::UInt);
  type.addValue("ULongLong", QVariant::ULongLong);
  type.addValue("Url", QVariant::Url);
  type.addValue("UserType", QVariant::UserType);
  type.addValue("Uuid", QVariant::Uuid);
  type.addValue("Vector2D", QVariant::Vector2D);
  type.addValue("Vector3D", QVariant::Vector3D);
  type.addValue("Vector4D", QVariant::Vector4D);
}

static void register_variant_class(script::Namespace ns)
{
  using namespace script;

  Class variant = ns.Class("Variant").setId(script::Type::QVariant).get();

  register_variant_type_enum(variant);
  binding::Class<QVariant> binder{ variant };

  // ~QVariant();
  binder.add_dtor();
  // QVariant();
  binder.ctors().add_default();
  // QVariant(QVariant::Type);
  binder.ctors().add<QVariant::Type>();
  // QVariant(int, const void *);
  /// ignore: binder.ctors().add<int, const void *>();
  // QVariant(int, const void *, uint);
  /// ignore: binder.ctors().add<int, const void *, uint>();
  // QVariant(const QVariant &);
  binder.ctors().add<const QVariant &>();
  // QVariant(QDataStream &);
  binder.ctors().add<QDataStream &>();
  // QVariant(int);
  binder.ctors().add<int>();
  // QVariant(uint);
  /// ignore: binder.ctors().add<uint>();
  // QVariant(qlonglong);
  /// ignore: binder.ctors().add<qlonglong>();
  // QVariant(qulonglong);
  /// ignore: binder.ctors().add<qulonglong>();
  // QVariant(bool);
  binder.ctors().add<bool>();
  // QVariant(double);
  binder.ctors().add<double>();
  // QVariant(float);
  binder.ctors().add<float>();
  // QVariant(const char *);
  /// ignore: binder.ctors().add<const char *>();
  // QVariant(const QByteArray &);
  binder.ctors().add<const QByteArray &>();
  // QVariant(const QBitArray &);
  binder.ctors().add<const QBitArray &>();
  // QVariant(const QString &);
  binder.ctors().add<const QString &>();
  // QVariant(QLatin1String);
  binder.ctors().add<QLatin1String>();
  // QVariant(const QStringList &);
  binder.ctors().add<const QStringList &>();
  // QVariant(QChar);
  binder.ctors().add<QChar>();
  // QVariant(const QDate &);
  binder.ctors().add<const QDate &>();
  // QVariant(const QTime &);
  binder.ctors().add<const QTime &>();
  // QVariant(const QDateTime &);
  binder.ctors().add<const QDateTime &>();
  // QVariant(const QList<QVariant> &);
  binder.ctors().add<const QList<QVariant> &>();
  // QVariant(const QMap<QString, QVariant> &);
  binder.ctors().add<const QMap<QString, QVariant> &>();
  // QVariant(const QHash<QString, QVariant> &);
  binder.ctors().add<const QHash<QString, QVariant> &>();
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
  binder.ctors().add<const QRegExp &>();
  // QVariant(const QRegularExpression &);
  binder.ctors().add<const QRegularExpression &>();
  // QVariant(const QUrl &);
  binder.ctors().add<const QUrl &>();
  // QVariant(const QEasingCurve &);
  binder.ctors().add<const QEasingCurve &>();
  // QVariant(const QUuid &);
  binder.ctors().add<const QUuid &>();
  // QVariant(const QModelIndex &);
  binder.ctors().add<const QModelIndex &>();
  // QVariant(const QPersistentModelIndex &);
  binder.ctors().add<const QPersistentModelIndex &>();
  // QVariant(const QJsonValue &);
  binder.ctors().add<const QJsonValue &>();
  // QVariant(const QJsonObject &);
  binder.ctors().add<const QJsonObject &>();
  // QVariant(const QJsonArray &);
  binder.ctors().add<const QJsonArray &>();
  // QVariant(const QJsonDocument &);
  binder.ctors().add<const QJsonDocument &>();
  // QVariant & operator=(const QVariant &);
  binder.operators().assign<const QVariant &>();
  // QVariant(QVariant &&);
  /// TODO: binder.ctors().add<QVariant &&>();
  // QVariant & operator=(QVariant &&);
  /// TODO: binder.operators().assign<QVariant &&>();
  // void swap(QVariant &);
  binder.add_void_fun<QVariant &, &QVariant::swap>("swap");
  // QVariant::Type type() const;
  binder.add_fun<QVariant::Type, &QVariant::type>("type");
  // int userType() const;
  binder.add_fun<int, &QVariant::userType>("userType");
  // const char * typeName() const;
  binder.add_fun<const char *, &QVariant::typeName>("typeName");
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
  // int toInt(bool *) const;
  /// TODO: binder.add_fun<int, bool *, &QVariant::toInt>("toInt");
  YASL_METHOD_0(binder.class_, "toInt", int, QVariant, toInt).setConst().create();
  // uint toUInt(bool *) const;
  binder.add_fun<uint, bool *, &QVariant::toUInt>("toUInt");
  // qlonglong toLongLong(bool *) const;
  binder.add_fun<qlonglong, bool *, &QVariant::toLongLong>("toLongLong");
  // qulonglong toULongLong(bool *) const;
  binder.add_fun<qulonglong, bool *, &QVariant::toULongLong>("toULongLong");
  // bool toBool() const;
  binder.add_fun<bool, &QVariant::toBool>("toBool");
  // double toDouble(bool *) const;
  binder.add_fun<double, bool *, &QVariant::toDouble>("toDouble");
  // float toFloat(bool *) const;
  binder.add_fun<float, bool *, &QVariant::toFloat>("toFloat");
  // qreal toReal(bool *) const;
  binder.add_fun<qreal, bool *, &QVariant::toReal>("toReal");
  // QByteArray toByteArray() const;
  binder.add_fun<QByteArray, &QVariant::toByteArray>("toByteArray");
  // QBitArray toBitArray() const;
  binder.add_fun<QBitArray, &QVariant::toBitArray>("toBitArray");
  // QString toString() const;
  binder.add_fun<QString, &QVariant::toString>("toString");
  // QStringList toStringList() const;
  binder.add_fun<QStringList, &QVariant::toStringList>("toStringList");
  // QChar toChar() const;
  binder.add_fun<QChar, &QVariant::toChar>("toChar");
  // QDate toDate() const;
  binder.add_fun<QDate, &QVariant::toDate>("toDate");
  // QTime toTime() const;
  binder.add_fun<QTime, &QVariant::toTime>("toTime");
  // QDateTime toDateTime() const;
  binder.add_fun<QDateTime, &QVariant::toDateTime>("toDateTime");
  // QList<QVariant> toList() const;
  binder.add_fun<QList<QVariant>, &QVariant::toList>("toList");
  // QMap<QString, QVariant> toMap() const;
  binder.add_fun<QMap<QString, QVariant>, &QVariant::toMap>("toMap");
  // QHash<QString, QVariant> toHash() const;
  binder.add_fun<QHash<QString, QVariant>, &QVariant::toHash>("toHash");
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
  binder.add_fun<QRegExp, &QVariant::toRegExp>("toRegExp");
  // QRegularExpression toRegularExpression() const;
  binder.add_fun<QRegularExpression, &QVariant::toRegularExpression>("toRegularExpression");
  // QUrl toUrl() const;
  binder.add_fun<QUrl, &QVariant::toUrl>("toUrl");
  // QEasingCurve toEasingCurve() const;
  binder.add_fun<QEasingCurve, &QVariant::toEasingCurve>("toEasingCurve");
  // QUuid toUuid() const;
  binder.add_fun<QUuid, &QVariant::toUuid>("toUuid");
  // QModelIndex toModelIndex() const;
  binder.add_fun<QModelIndex, &QVariant::toModelIndex>("toModelIndex");
  // QPersistentModelIndex toPersistentModelIndex() const;
  binder.add_fun<QPersistentModelIndex, &QVariant::toPersistentModelIndex>("toPersistentModelIndex");
  // QJsonValue toJsonValue() const;
  binder.add_fun<QJsonValue, &QVariant::toJsonValue>("toJsonValue");
  // QJsonObject toJsonObject() const;
  binder.add_fun<QJsonObject, &QVariant::toJsonObject>("toJsonObject");
  // QJsonArray toJsonArray() const;
  binder.add_fun<QJsonArray, &QVariant::toJsonArray>("toJsonArray");
  // QJsonDocument toJsonDocument() const;
  binder.add_fun<QJsonDocument, &QVariant::toJsonDocument>("toJsonDocument");
  // void load(QDataStream &);
  binder.add_void_fun<QDataStream &, &QVariant::load>("load");
  // void save(QDataStream &) const;
  binder.add_const_void_fun<QDataStream &, &QVariant::save>("save");
  // static const char * typeToName(int);
  binder.add_static<const char *, int, &QVariant::typeToName>("typeToName");
  // static QVariant::Type nameToType(const char *);
  binder.add_static<QVariant::Type, const char *, &QVariant::nameToType>("nameToType");
  // void * data();
  /// ignore: binder.add_fun<void *, &QVariant::data>("data");
  // const void * constData() const;
  /// ignore: binder.add_fun<const void *, &QVariant::constData>("constData");
  // const void * data() const;
  /// ignore: binder.add_fun<const void *, &QVariant::data>("data");
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
  /// ignore: binder.add_void_fun<int, const void *, &QVariant::create>("create");
  // bool cmp(const QVariant &) const;
  binder.add_fun<bool, const QVariant &, &QVariant::cmp>("cmp");
  // int compare(const QVariant &) const;
  binder.add_fun<int, const QVariant &, &QVariant::compare>("compare");
  // bool convert(const int, void *) const;
  /// ignore: binder.add_fun<bool, const int, void *, &QVariant::convert>("convert");
  // QVariant::DataPtr & data_ptr();
  /// ignore: binder.add_fun<QVariant::DataPtr &, &QVariant::data_ptr>("data_ptr");
  // const QVariant::DataPtr & data_ptr() const;
  /// ignore: binder.add_fun<const QVariant::DataPtr &, &QVariant::data_ptr>("data_ptr");
}

void register_variant_file(script::Namespace root)
{
  using namespace script;

  register_variant_class(root);
  binding::Namespace binder{ root };

  // QDataStream & operator>>(QDataStream &, QVariant &);
  binder.operators().read_from<QDataStream &, QVariant &>();
  // QDataStream & operator<<(QDataStream &, const QVariant &);
  binder.operators().put_to<QDataStream &, const QVariant &>();
  // QDataStream & operator>>(QDataStream &, QVariant::Type &);
  binder.operators().read_from<QDataStream &, QVariant::Type &>();
  // QDataStream & operator<<(QDataStream &, const QVariant::Type);
  binder.operators().put_to<QDataStream &, const QVariant::Type>();
  // bool operator==(const QVariant &, const QVariantComparisonHelper &);
  binder.operators().eq<const QVariant &, const QVariantComparisonHelper &>();
  // bool operator!=(const QVariant &, const QVariantComparisonHelper &);
  binder.operators().neq<const QVariant &, const QVariantComparisonHelper &>();
  // void swap(QVariant &, QVariant &);
  binder.add_void_fun<QVariant &, QVariant &, &swap>("swap");
  // QVariant qvariant_cast(const QVariant &);
  /// TODO: binder.add_fun<QVariant, const QVariant &, &qvariant_cast>("qvariant_cast");
  // QDebug operator<<(QDebug, const QVariant &);
  binder.operators().left_shift<QDebug, QDebug, const QVariant &>();
  // QDebug operator<<(QDebug, const QVariant::Type);
  binder.operators().left_shift<QDebug, QDebug, const QVariant::Type>();
}

