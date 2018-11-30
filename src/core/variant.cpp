// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/variant.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/common/variant-utils.h"
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
#include "yasl/core/qvariant-binder.h"
#include "yasl/core/rect.h"
#include "yasl/core/regularexpression.h"
#include "yasl/core/size.h"
#include "yasl/core/url.h"
#include "yasl/core/uuid.h"
#include "yasl/core/variant-functions.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>

static void register_variant_class(script::Namespace ns)
{
  using namespace script;

  Class variant = ns.newClass("Variant").setId(script::Type::QVariant).get();


  // QVariant();
  bind::default_constructor<QVariant>(variant).create();
  // ~QVariant();
  bind::destructor<QVariant>(variant).create();
  // QVariant(QVariant::Type);
  /// TODO: QVariant(QVariant::Type);
  // QVariant(int, const void *);
  /// TODO: QVariant(int, const void *);
  // QVariant(int, const void *, uint);
  /// TODO: QVariant(int, const void *, uint);
  // QVariant(const QVariant &);
  bind::constructor<QVariant, const QVariant &>(variant).create();
  // QVariant(QDataStream &);
  bind::constructor<QVariant, QDataStream &>(variant).create();
  // QVariant(int);
  bind::constructor<QVariant, int>(variant).create();
  // QVariant(qlonglong);
  /// TODO: QVariant(qlonglong);
  // QVariant(qulonglong);
  /// TODO: QVariant(qulonglong);
  // QVariant(bool);
  bind::constructor<QVariant, bool>(variant).create();
  // QVariant(double);
  bind::constructor<QVariant, double>(variant).create();
  // QVariant(float);
  bind::constructor<QVariant, float>(variant).create();
  // QVariant(const char *);
  /// TODO: QVariant(const char *);
  // QVariant(const QByteArray &);
  bind::constructor<QVariant, const QByteArray &>(variant).create();
  // QVariant(const QBitArray &);
  /// TODO: QVariant(const QBitArray &);
  // QVariant(const QString &);
  bind::constructor<QVariant, const QString &>(variant).create();
  // QVariant(QLatin1String);
  /// TODO: QVariant(QLatin1String);
  // QVariant(const QStringList &);
  /// TODO: QVariant(const QStringList &);
  // QVariant(QChar);
  bind::constructor<QVariant, QChar>(variant).create();
  // QVariant(const QDate &);
  bind::constructor<QVariant, const QDate &>(variant).create();
  // QVariant(const QTime &);
  bind::constructor<QVariant, const QTime &>(variant).create();
  // QVariant(const QDateTime &);
  bind::constructor<QVariant, const QDateTime &>(variant).create();
  // QVariant(const QList<QVariant> &);
  /// TODO: QVariant(const QList<QVariant> &);
  // QVariant(const QMap<QString, QVariant> &);
  /// TODO: QVariant(const QMap<QString, QVariant> &);
  // QVariant(const QHash<QString, QVariant> &);
  /// TODO: QVariant(const QHash<QString, QVariant> &);
  // QVariant(const QSize &);
  bind::constructor<QVariant, const QSize &>(variant).create();
  // QVariant(const QSizeF &);
  bind::constructor<QVariant, const QSizeF &>(variant).create();
  // QVariant(const QPoint &);
  bind::constructor<QVariant, const QPoint &>(variant).create();
  // QVariant(const QPointF &);
  bind::constructor<QVariant, const QPointF &>(variant).create();
  // QVariant(const QLine &);
  bind::constructor<QVariant, const QLine &>(variant).create();
  // QVariant(const QLineF &);
  bind::constructor<QVariant, const QLineF &>(variant).create();
  // QVariant(const QRect &);
  bind::constructor<QVariant, const QRect &>(variant).create();
  // QVariant(const QRectF &);
  bind::constructor<QVariant, const QRectF &>(variant).create();
  // QVariant(const QLocale &);
  bind::constructor<QVariant, const QLocale &>(variant).create();
  // QVariant(const QRegExp &);
  /// TODO: QVariant(const QRegExp &);
  // QVariant(const QRegularExpression &);
  bind::constructor<QVariant, const QRegularExpression &>(variant).create();
  // QVariant(const QUrl &);
  bind::constructor<QVariant, const QUrl &>(variant).create();
  // QVariant(const QEasingCurve &);
  /// TODO: QVariant(const QEasingCurve &);
  // QVariant(const QUuid &);
  bind::constructor<QVariant, const QUuid &>(variant).create();
  // QVariant(const QModelIndex &);
  /// TODO: QVariant(const QModelIndex &);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVariant(const QPersistentModelIndex &);
  /// TODO: QVariant(const QPersistentModelIndex &);
#endif
  // QVariant(const QJsonValue &);
  bind::constructor<QVariant, const QJsonValue &>(variant).create();
  // QVariant(const QJsonObject &);
  bind::constructor<QVariant, const QJsonObject &>(variant).create();
  // QVariant(const QJsonArray &);
  bind::constructor<QVariant, const QJsonArray &>(variant).create();
  // QVariant(const QJsonDocument &);
  bind::constructor<QVariant, const QJsonDocument &>(variant).create();
  // QVariant & operator=(const QVariant &);
  bind::memop_assign<QVariant, const QVariant &>(variant);
  // QVariant(QVariant &&);
  bind::constructor<QVariant, QVariant &&>(variant).create();
  // QVariant & operator=(QVariant &&);
  bind::memop_assign<QVariant, QVariant &&>(variant);
  // void swap(QVariant &);
  bind::void_member_function<QVariant, QVariant &, &QVariant::swap>(variant, "swap").create();
  // const char * typeName() const;
  /// TODO: const char * typeName() const;
  // bool canConvert(int) const;
  bind::member_function<QVariant, bool, int, &QVariant::canConvert>(variant, "canConvert").create();
  // bool convert(int);
  bind::member_function<QVariant, bool, int, &QVariant::convert>(variant, "convert").create();
  // bool isValid() const;
  bind::member_function<QVariant, bool, &QVariant::isValid>(variant, "isValid").create();
  // bool isNull() const;
  bind::member_function<QVariant, bool, &QVariant::isNull>(variant, "isNull").create();
  // void clear();
  bind::void_member_function<QVariant, &QVariant::clear>(variant, "clear").create();
  // void detach();
  bind::void_member_function<QVariant, &QVariant::detach>(variant, "detach").create();
  // bool isDetached() const;
  bind::member_function<QVariant, bool, &QVariant::isDetached>(variant, "isDetached").create();
  // int va_toInt();
  bind::fn_as_memfn<QVariant, int, &va_toInt>(variant, "toInt").create();
  // bool toBool() const;
  bind::member_function<QVariant, bool, &QVariant::toBool>(variant, "toBool").create();
  // double va_toDouble();
  bind::fn_as_memfn<QVariant, double, &va_toDouble>(variant, "toDouble").create();
  // float va_toFloat();
  bind::fn_as_memfn<QVariant, float, &va_toFloat>(variant, "toFloat").create();
  // qreal toReal(bool *) const;
  /// TODO: qreal toReal(bool *) const;
  // QByteArray toByteArray() const;
  bind::member_function<QVariant, QByteArray, &QVariant::toByteArray>(variant, "toByteArray").create();
  // QBitArray toBitArray() const;
  /// TODO: QBitArray toBitArray() const;
  // QString toString() const;
  bind::member_function<QVariant, QString, &QVariant::toString>(variant, "toString").create();
  // QStringList toStringList() const;
  /// TODO: QStringList toStringList() const;
  // QChar toChar() const;
  bind::member_function<QVariant, QChar, &QVariant::toChar>(variant, "toChar").create();
  // QDate toDate() const;
  bind::member_function<QVariant, QDate, &QVariant::toDate>(variant, "toDate").create();
  // QTime toTime() const;
  bind::member_function<QVariant, QTime, &QVariant::toTime>(variant, "toTime").create();
  // QDateTime toDateTime() const;
  bind::member_function<QVariant, QDateTime, &QVariant::toDateTime>(variant, "toDateTime").create();
  // QList<QVariant> toList() const;
  /// TODO: QList<QVariant> toList() const;
  // QMap<QString, QVariant> toMap() const;
  /// TODO: QMap<QString, QVariant> toMap() const;
  // QHash<QString, QVariant> toHash() const;
  /// TODO: QHash<QString, QVariant> toHash() const;
  // QPoint toPoint() const;
  bind::member_function<QVariant, QPoint, &QVariant::toPoint>(variant, "toPoint").create();
  // QPointF toPointF() const;
  bind::member_function<QVariant, QPointF, &QVariant::toPointF>(variant, "toPointF").create();
  // QRect toRect() const;
  bind::member_function<QVariant, QRect, &QVariant::toRect>(variant, "toRect").create();
  // QSize toSize() const;
  bind::member_function<QVariant, QSize, &QVariant::toSize>(variant, "toSize").create();
  // QSizeF toSizeF() const;
  bind::member_function<QVariant, QSizeF, &QVariant::toSizeF>(variant, "toSizeF").create();
  // QLine toLine() const;
  bind::member_function<QVariant, QLine, &QVariant::toLine>(variant, "toLine").create();
  // QLineF toLineF() const;
  bind::member_function<QVariant, QLineF, &QVariant::toLineF>(variant, "toLineF").create();
  // QRectF toRectF() const;
  bind::member_function<QVariant, QRectF, &QVariant::toRectF>(variant, "toRectF").create();
  // QLocale toLocale() const;
  bind::member_function<QVariant, QLocale, &QVariant::toLocale>(variant, "toLocale").create();
  // QRegExp toRegExp() const;
  /// TODO: QRegExp toRegExp() const;
  // QRegularExpression toRegularExpression() const;
  bind::member_function<QVariant, QRegularExpression, &QVariant::toRegularExpression>(variant, "toRegularExpression").create();
  // QUrl toUrl() const;
  bind::member_function<QVariant, QUrl, &QVariant::toUrl>(variant, "toUrl").create();
  // QEasingCurve toEasingCurve() const;
  /// TODO: QEasingCurve toEasingCurve() const;
  // QUuid toUuid() const;
  bind::member_function<QVariant, QUuid, &QVariant::toUuid>(variant, "toUuid").create();
  // QModelIndex toModelIndex() const;
  /// TODO: QModelIndex toModelIndex() const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QPersistentModelIndex toPersistentModelIndex() const;
  /// TODO: QPersistentModelIndex toPersistentModelIndex() const;
#endif
  // QJsonValue toJsonValue() const;
  bind::member_function<QVariant, QJsonValue, &QVariant::toJsonValue>(variant, "toJsonValue").create();
  // QJsonObject toJsonObject() const;
  bind::member_function<QVariant, QJsonObject, &QVariant::toJsonObject>(variant, "toJsonObject").create();
  // QJsonArray toJsonArray() const;
  bind::member_function<QVariant, QJsonArray, &QVariant::toJsonArray>(variant, "toJsonArray").create();
  // QJsonDocument toJsonDocument() const;
  bind::member_function<QVariant, QJsonDocument, &QVariant::toJsonDocument>(variant, "toJsonDocument").create();
  // void load(QDataStream &);
  bind::void_member_function<QVariant, QDataStream &, &QVariant::load>(variant, "load").create();
  // void save(QDataStream &) const;
  bind::const_void_member_function<QVariant, QDataStream &, &QVariant::save>(variant, "save").create();
  // static QVariant::Type nameToType(const char *);
  /// TODO: static QVariant::Type nameToType(const char *);
  // void * data();
  /// TODO: void * data();
  // const void * constData() const;
  /// TODO: const void * constData() const;
  // const void * data() const;
  /// TODO: const void * data() const;
  // bool operator==(const QVariant &) const;
  bind::memop_eq<QVariant, const QVariant &>(variant);
  // bool operator!=(const QVariant &) const;
  bind::memop_neq<QVariant, const QVariant &>(variant);
  // bool operator<(const QVariant &) const;
  bind::memop_less<QVariant, const QVariant &>(variant);
  // bool operator<=(const QVariant &) const;
  bind::memop_leq<QVariant, const QVariant &>(variant);
  // bool operator>(const QVariant &) const;
  bind::memop_greater<QVariant, const QVariant &>(variant);
  // bool operator>=(const QVariant &) const;
  bind::memop_geq<QVariant, const QVariant &>(variant);
  // void create(int, const void *);
  /// TODO: void create(int, const void *);
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

  // QDataStream & operator>>(QDataStream &, QVariant &);
  bind::op_read_from<QDataStream &, QVariant &>(ns);
  // QDataStream & operator<<(QDataStream &, const QVariant &);
  bind::op_put_to<QDataStream &, const QVariant &>(ns);
  // QDataStream & operator>>(QDataStream &, QVariant::Type &);
  /// TODO: QDataStream & operator>>(QDataStream &, QVariant::Type &);
  // QDataStream & operator<<(QDataStream &, const QVariant::Type);
  /// TODO: QDataStream & operator<<(QDataStream &, const QVariant::Type);
  // void swap(QVariant &, QVariant &);
  bind::void_function<QVariant &, QVariant &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QVariant &);
  /// TODO: QDebug operator<<(QDebug, const QVariant &);
  // QDebug operator<<(QDebug, const QVariant::Type);
  /// TODO: QDebug operator<<(QDebug, const QVariant::Type);
  yasl::complete_variant_class(ns.engine());
}

