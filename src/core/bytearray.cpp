// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/bytearray.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"
#include "yasl/common/listspecializations.h"
#include "yasl/core/flags.h"

#include "yasl/core/bytearray-functions.h"
#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
static void register_byte_array_base64_option_enum(script::Class byte_array)
{
  using namespace script;

  Enum base64_option = byte_array.newEnum("Base64Option").setId(script::Type::QByteArrayBase64Option).get();

  register_qflags_type<QByteArray::Base64Option>(byte_array, "Base64Options", script::Type::QByteArrayBase64Options);

  base64_option.addValue("Base64Encoding", QByteArray::Base64Encoding);
  base64_option.addValue("Base64UrlEncoding", QByteArray::Base64UrlEncoding);
  base64_option.addValue("KeepTrailingEquals", QByteArray::KeepTrailingEquals);
  base64_option.addValue("OmitTrailingEquals", QByteArray::OmitTrailingEquals);
}
#endif


static void register_byte_array_class(script::Namespace ns)
{
  using namespace script;

  Class byte_array = ns.newClass("ByteArray").setId(script::Type::QByteArray).get();

  register_proxy_specialization<QByteArray>(byte_array.engine());
  register_list_specialization<QByteArray>(byte_array.engine());
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  register_byte_array_base64_option_enum(byte_array);
#endif

  // QByteArray();
  bind::default_constructor<QByteArray>(byte_array).create();
  // QByteArray(int, char);
  bind::constructor<QByteArray, int, char>(byte_array).create();
  // QByteArray(int, Qt::Initialization);
  bind::constructor<QByteArray, int, Qt::Initialization>(byte_array).create();
  // QByteArray(const QByteArray &);
  bind::constructor<QByteArray, const QByteArray &>(byte_array).create();
  // ~QByteArray();
  bind::destructor<QByteArray>(byte_array).create();
  // QByteArray & operator=(const QByteArray &);
  bind::memop_assign<QByteArray, const QByteArray &>(byte_array);
  // QByteArray(QByteArray &&);
  bind::constructor<QByteArray, QByteArray &&>(byte_array).create();
  // QByteArray & operator=(QByteArray &&);
  bind::memop_assign<QByteArray, QByteArray &&>(byte_array);
  // void swap(QByteArray &);
  bind::void_member_function<QByteArray, QByteArray &, &QByteArray::swap>(byte_array, "swap").create();
  // int size() const;
  bind::member_function<QByteArray, int, &QByteArray::size>(byte_array, "size").create();
  // bool isEmpty() const;
  bind::member_function<QByteArray, bool, &QByteArray::isEmpty>(byte_array, "isEmpty").create();
  // void resize(int);
  bind::void_member_function<QByteArray, int, &QByteArray::resize>(byte_array, "resize").create();
  // QByteArray & fill(char, int = -1);
  bind::chainable_memfn<QByteArray, char, int, &QByteArray::fill>(byte_array, "fill")
    .apply(bind::default_arguments(-1)).create();
  // int capacity() const;
  bind::member_function<QByteArray, int, &QByteArray::capacity>(byte_array, "capacity").create();
  // void reserve(int);
  bind::void_member_function<QByteArray, int, &QByteArray::reserve>(byte_array, "reserve").create();
  // void squeeze();
  bind::void_member_function<QByteArray, &QByteArray::squeeze>(byte_array, "squeeze").create();
  // void detach();
  bind::void_member_function<QByteArray, &QByteArray::detach>(byte_array, "detach").create();
  // bool isDetached() const;
  bind::member_function<QByteArray, bool, &QByteArray::isDetached>(byte_array, "isDetached").create();
  // bool isSharedWith(const QByteArray &) const;
  bind::member_function<QByteArray, bool, const QByteArray &, &QByteArray::isSharedWith>(byte_array, "isSharedWith").create();
  // void clear();
  bind::void_member_function<QByteArray, &QByteArray::clear>(byte_array, "clear").create();
  // char at(int) const;
  bind::member_function<QByteArray, char, int, &QByteArray::at>(byte_array, "at").create();
  // char operator[](int) const;
  bind::memop_const_subscript<QByteArray, char, int>(byte_array);
  // QByteRef operator[](int);
  bind::memop_subscript<QByteArray, QByteRef, int>(byte_array);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // char front() const;
  bind::member_function<QByteArray, char, &QByteArray::front>(byte_array, "front").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // char back() const;
  bind::member_function<QByteArray, char, &QByteArray::back>(byte_array, "back").create();
#endif
  // int indexOf(char, int = 0) const;
  bind::member_function<QByteArray, int, char, int, &QByteArray::indexOf>(byte_array, "indexOf")
    .apply(bind::default_arguments(0)).create();
  // int indexOf(const QByteArray &, int = 0) const;
  bind::member_function<QByteArray, int, const QByteArray &, int, &QByteArray::indexOf>(byte_array, "indexOf")
    .apply(bind::default_arguments(0)).create();
  // int lastIndexOf(char, int = -1) const;
  bind::member_function<QByteArray, int, char, int, &QByteArray::lastIndexOf>(byte_array, "lastIndexOf")
    .apply(bind::default_arguments(-1)).create();
  // int lastIndexOf(const QByteArray &, int = -1) const;
  bind::member_function<QByteArray, int, const QByteArray &, int, &QByteArray::lastIndexOf>(byte_array, "lastIndexOf")
    .apply(bind::default_arguments(-1)).create();
  // bool contains(char) const;
  bind::member_function<QByteArray, bool, char, &QByteArray::contains>(byte_array, "contains").create();
  // bool contains(const QByteArray &) const;
  bind::member_function<QByteArray, bool, const QByteArray &, &QByteArray::contains>(byte_array, "contains").create();
  // int count(char) const;
  bind::member_function<QByteArray, int, char, &QByteArray::count>(byte_array, "count").create();
  // int count(const QByteArray &) const;
  bind::member_function<QByteArray, int, const QByteArray &, &QByteArray::count>(byte_array, "count").create();
  // QByteArray left(int) const;
  bind::member_function<QByteArray, QByteArray, int, &QByteArray::left>(byte_array, "left").create();
  // QByteArray right(int) const;
  bind::member_function<QByteArray, QByteArray, int, &QByteArray::right>(byte_array, "right").create();
  // QByteArray mid(int, int = -1) const;
  bind::member_function<QByteArray, QByteArray, int, int, &QByteArray::mid>(byte_array, "mid")
    .apply(bind::default_arguments(-1)).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // QByteArray chopped(int) const;
  bind::member_function<QByteArray, QByteArray, int, &QByteArray::chopped>(byte_array, "chopped").create();
#endif
  // bool startsWith(const QByteArray &) const;
  bind::member_function<QByteArray, bool, const QByteArray &, &QByteArray::startsWith>(byte_array, "startsWith").create();
  // bool startsWith(char) const;
  bind::member_function<QByteArray, bool, char, &QByteArray::startsWith>(byte_array, "startsWith").create();
  // bool endsWith(const QByteArray &) const;
  bind::member_function<QByteArray, bool, const QByteArray &, &QByteArray::endsWith>(byte_array, "endsWith").create();
  // bool endsWith(char) const;
  bind::member_function<QByteArray, bool, char, &QByteArray::endsWith>(byte_array, "endsWith").create();
  // void truncate(int);
  bind::void_member_function<QByteArray, int, &QByteArray::truncate>(byte_array, "truncate").create();
  // void chop(int);
  bind::void_member_function<QByteArray, int, &QByteArray::chop>(byte_array, "chop").create();
  // QByteArray ba_toLower();
  bind::fn_as_memfn<QByteArray, QByteArray, &ba_toLower>(byte_array, "toLower").create();
  // QByteArray ba_toUpper();
  bind::fn_as_memfn<QByteArray, QByteArray, &ba_toUpper>(byte_array, "toUpper").create();
  // QByteArray ba_trimmed();
  bind::fn_as_memfn<QByteArray, QByteArray, &ba_trimmed>(byte_array, "trimmed").create();
  // QByteArray ba_simplified();
  bind::fn_as_memfn<QByteArray, QByteArray, &ba_simplified>(byte_array, "simplified").create();
  // QByteArray leftJustified(int, char = ' ', bool = false) const;
  bind::member_function<QByteArray, QByteArray, int, char, bool, &QByteArray::leftJustified>(byte_array, "leftJustified")
    .apply(bind::default_arguments(false, ' ')).create();
  // QByteArray rightJustified(int, char = ' ', bool = false) const;
  bind::member_function<QByteArray, QByteArray, int, char, bool, &QByteArray::rightJustified>(byte_array, "rightJustified")
    .apply(bind::default_arguments(false, ' ')).create();
  // QByteArray & prepend(char);
  bind::chainable_memfn<QByteArray, char, &QByteArray::prepend>(byte_array, "prepend").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QByteArray & prepend(int, char);
  bind::chainable_memfn<QByteArray, int, char, &QByteArray::prepend>(byte_array, "prepend").create();
#endif
  // QByteArray & prepend(const QByteArray &);
  bind::chainable_memfn<QByteArray, const QByteArray &, &QByteArray::prepend>(byte_array, "prepend").create();
  // QByteArray & append(char);
  bind::chainable_memfn<QByteArray, char, &QByteArray::append>(byte_array, "append").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QByteArray & append(int, char);
  bind::chainable_memfn<QByteArray, int, char, &QByteArray::append>(byte_array, "append").create();
#endif
  // QByteArray & append(const QByteArray &);
  bind::chainable_memfn<QByteArray, const QByteArray &, &QByteArray::append>(byte_array, "append").create();
  // QByteArray & insert(int, char);
  bind::chainable_memfn<QByteArray, int, char, &QByteArray::insert>(byte_array, "insert").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // QByteArray & insert(int, int, char);
  bind::chainable_memfn<QByteArray, int, int, char, &QByteArray::insert>(byte_array, "insert").create();
#endif
  // QByteArray & insert(int, const QByteArray &);
  bind::chainable_memfn<QByteArray, int, const QByteArray &, &QByteArray::insert>(byte_array, "insert").create();
  // QByteArray & remove(int, int);
  bind::chainable_memfn<QByteArray, int, int, &QByteArray::remove>(byte_array, "remove").create();
  // QByteArray & replace(int, int, const QByteArray &);
  bind::chainable_memfn<QByteArray, int, int, const QByteArray &, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & replace(char, const QByteArray &);
  bind::chainable_memfn<QByteArray, char, const QByteArray &, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & replace(const QByteArray &, const QByteArray &);
  bind::chainable_memfn<QByteArray, const QByteArray &, const QByteArray &, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & replace(char, char);
  bind::chainable_memfn<QByteArray, char, char, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & operator+=(char);
  bind::memop_add_assign<QByteArray, char>(byte_array);
  // QByteArray & operator+=(const QByteArray &);
  bind::memop_add_assign<QByteArray, const QByteArray &>(byte_array);
  // QList<QByteArray> split(char) const;
  bind::member_function<QByteArray, QList<QByteArray>, char, &QByteArray::split>(byte_array, "split").create();
  // QByteArray repeated(int) const;
  bind::member_function<QByteArray, QByteArray, int, &QByteArray::repeated>(byte_array, "repeated").create();
  // QByteArray & append(const QString &);
  bind::chainable_memfn<QByteArray, const QString &, &QByteArray::append>(byte_array, "append").create();
  // QByteArray & insert(int, const QString &);
  bind::chainable_memfn<QByteArray, int, const QString &, &QByteArray::insert>(byte_array, "insert").create();
  // QByteArray & replace(char, const QString &);
  bind::chainable_memfn<QByteArray, char, const QString &, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & replace(const QString &, const QByteArray &);
  bind::chainable_memfn<QByteArray, const QString &, const QByteArray &, &QByteArray::replace>(byte_array, "replace").create();
  // QByteArray & operator+=(const QString &);
  bind::memop_add_assign<QByteArray, const QString &>(byte_array);
  // int indexOf(const QString &, int) const;
  bind::member_function<QByteArray, int, const QString &, int, &QByteArray::indexOf>(byte_array, "indexOf").create();
  // int lastIndexOf(const QString &, int) const;
  bind::member_function<QByteArray, int, const QString &, int, &QByteArray::lastIndexOf>(byte_array, "lastIndexOf").create();
  // bool operator==(const QString &) const;
  bind::memop_eq<QByteArray, const QString &>(byte_array);
  // bool operator!=(const QString &) const;
  bind::memop_neq<QByteArray, const QString &>(byte_array);
  // bool operator<(const QString &) const;
  bind::memop_less<QByteArray, const QString &>(byte_array);
  // bool operator>(const QString &) const;
  bind::memop_greater<QByteArray, const QString &>(byte_array);
  // bool operator<=(const QString &) const;
  bind::memop_leq<QByteArray, const QString &>(byte_array);
  // bool operator>=(const QString &) const;
  bind::memop_geq<QByteArray, const QString &>(byte_array);
  // short toShort(bool *, int) const;
  /// TODO: short toShort(bool *, int) const;
  // ushort toUShort(bool *, int) const;
  /// TODO: ushort toUShort(bool *, int) const;
  // int toInt(bool *, int) const;
  /// TODO: int toInt(bool *, int) const;
  // uint toUInt(bool *, int) const;
  /// TODO: uint toUInt(bool *, int) const;
  // long toLong(bool *, int) const;
  /// TODO: long toLong(bool *, int) const;
  // ulong toULong(bool *, int) const;
  /// TODO: ulong toULong(bool *, int) const;
  // qlonglong toLongLong(bool *, int) const;
  /// TODO: qlonglong toLongLong(bool *, int) const;
  // qulonglong toULongLong(bool *, int) const;
  /// TODO: qulonglong toULongLong(bool *, int) const;
  // float toFloat(bool *) const;
  /// TODO: float toFloat(bool *) const;
  // double toDouble(bool *) const;
  /// TODO: double toDouble(bool *) const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QByteArray toBase64(QByteArray::Base64Options) const;
  bind::member_function<QByteArray, QByteArray, QByteArray::Base64Options, &QByteArray::toBase64>(byte_array, "toBase64").create();
#endif
  // QByteArray toBase64() const;
  bind::member_function<QByteArray, QByteArray, &QByteArray::toBase64>(byte_array, "toBase64").create();
  // QByteArray toHex() const;
  bind::member_function<QByteArray, QByteArray, &QByteArray::toHex>(byte_array, "toHex").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  // QByteArray toHex(char) const;
  bind::member_function<QByteArray, QByteArray, char, &QByteArray::toHex>(byte_array, "toHex").create();
#endif
  // QByteArray toPercentEncoding(const QByteArray &, const QByteArray &, char) const;
  bind::member_function<QByteArray, QByteArray, const QByteArray &, const QByteArray &, char, &QByteArray::toPercentEncoding>(byte_array, "toPercentEncoding").create();
  // QByteArray & setNum(short, int);
  /// TODO: QByteArray & setNum(short, int);
  // QByteArray & setNum(ushort, int);
  /// TODO: QByteArray & setNum(ushort, int);
  // QByteArray & setNum(int, int = 10);
  bind::chainable_memfn<QByteArray, int, int, &QByteArray::setNum>(byte_array, "setNum")
    .apply(bind::default_arguments(10)).create();
  // QByteArray & setNum(qlonglong, int);
  /// TODO: QByteArray & setNum(qlonglong, int);
  // QByteArray & setNum(qulonglong, int);
  /// TODO: QByteArray & setNum(qulonglong, int);
  // QByteArray & setNum(float, char = 'g', int = 6);
  bind::chainable_memfn<QByteArray, float, char, int, &QByteArray::setNum>(byte_array, "setNum")
    .apply(bind::default_arguments(6, 'g')).create();
  // QByteArray & setNum(double, char = 'g', int = 6);
  bind::chainable_memfn<QByteArray, double, char, int, &QByteArray::setNum>(byte_array, "setNum")
    .apply(bind::default_arguments(6, 'g')).create();
  // static QByteArray number(int, int);
  bind::static_member_function<QByteArray, QByteArray, int, int, &QByteArray::number>(byte_array, "number").create();
  // static QByteArray number(qlonglong, int);
  /// TODO: static QByteArray number(qlonglong, int);
  // static QByteArray number(qulonglong, int);
  /// TODO: static QByteArray number(qulonglong, int);
  // static QByteArray number(double, char, int);
  bind::static_member_function<QByteArray, QByteArray, double, char, int, &QByteArray::number>(byte_array, "number").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QByteArray fromBase64(const QByteArray &, QByteArray::Base64Options);
  bind::static_member_function<QByteArray, QByteArray, const QByteArray &, QByteArray::Base64Options, &QByteArray::fromBase64>(byte_array, "fromBase64").create();
#endif
  // static QByteArray fromBase64(const QByteArray &);
  bind::static_member_function<QByteArray, QByteArray, const QByteArray &, &QByteArray::fromBase64>(byte_array, "fromBase64").create();
  // static QByteArray fromHex(const QByteArray &);
  bind::static_member_function<QByteArray, QByteArray, const QByteArray &, &QByteArray::fromHex>(byte_array, "fromHex").create();
  // static QByteArray fromPercentEncoding(const QByteArray &, char);
  bind::static_member_function<QByteArray, QByteArray, const QByteArray &, char, &QByteArray::fromPercentEncoding>(byte_array, "fromPercentEncoding").create();
  // QByteArray::iterator begin();
  /// TODO: QByteArray::iterator begin();
  // QByteArray::const_iterator begin() const;
  /// TODO: QByteArray::const_iterator begin() const;
  // QByteArray::const_iterator cbegin() const;
  /// TODO: QByteArray::const_iterator cbegin() const;
  // QByteArray::const_iterator constBegin() const;
  /// TODO: QByteArray::const_iterator constBegin() const;
  // QByteArray::iterator end();
  /// TODO: QByteArray::iterator end();
  // QByteArray::const_iterator end() const;
  /// TODO: QByteArray::const_iterator end() const;
  // QByteArray::const_iterator cend() const;
  /// TODO: QByteArray::const_iterator cend() const;
  // QByteArray::const_iterator constEnd() const;
  /// TODO: QByteArray::const_iterator constEnd() const;
  // QByteArray::reverse_iterator rbegin();
  /// TODO: QByteArray::reverse_iterator rbegin();
  // QByteArray::reverse_iterator rend();
  /// TODO: QByteArray::reverse_iterator rend();
  // QByteArray::const_reverse_iterator rbegin() const;
  /// TODO: QByteArray::const_reverse_iterator rbegin() const;
  // QByteArray::const_reverse_iterator rend() const;
  /// TODO: QByteArray::const_reverse_iterator rend() const;
  // QByteArray::const_reverse_iterator crbegin() const;
  /// TODO: QByteArray::const_reverse_iterator crbegin() const;
  // QByteArray::const_reverse_iterator crend() const;
  /// TODO: QByteArray::const_reverse_iterator crend() const;
  // void push_back(char);
  bind::void_member_function<QByteArray, char, &QByteArray::push_back>(byte_array, "push_back").create();
  // void push_back(const QByteArray &);
  bind::void_member_function<QByteArray, const QByteArray &, &QByteArray::push_back>(byte_array, "push_back").create();
  // void push_front(char);
  bind::void_member_function<QByteArray, char, &QByteArray::push_front>(byte_array, "push_front").create();
  // void push_front(const QByteArray &);
  bind::void_member_function<QByteArray, const QByteArray &, &QByteArray::push_front>(byte_array, "push_front").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // void shrink_to_fit();
  bind::void_member_function<QByteArray, &QByteArray::shrink_to_fit>(byte_array, "shrink_to_fit").create();
#endif
  // int count() const;
  bind::member_function<QByteArray, int, &QByteArray::count>(byte_array, "count").create();
  // int length() const;
  bind::member_function<QByteArray, int, &QByteArray::length>(byte_array, "length").create();
  // bool isNull() const;
  bind::member_function<QByteArray, bool, &QByteArray::isNull>(byte_array, "isNull").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QByteArray, QMetaType::QByteArray>>();
}


static void register_byte_ref_class(script::Namespace ns)
{
  using namespace script;

  Class byte_ref = ns.newClass("ByteRef").setId(script::Type::QByteRef).get();


  // QByteRef & operator=(char);
  bind::memop_assign<QByteRef, char>(byte_ref);
  // QByteRef & operator=(const QByteRef &);
  bind::memop_assign<QByteRef, const QByteRef &>(byte_ref);
  // bool operator==(char) const;
  bind::memop_eq<QByteRef, char>(byte_ref);
  // bool operator!=(char) const;
  bind::memop_neq<QByteRef, char>(byte_ref);
  // bool operator>(char) const;
  bind::memop_greater<QByteRef, char>(byte_ref);
  // bool operator>=(char) const;
  bind::memop_geq<QByteRef, char>(byte_ref);
  // bool operator<(char) const;
  bind::memop_less<QByteRef, char>(byte_ref);
  // bool operator<=(char) const;
  bind::memop_leq<QByteRef, char>(byte_ref);
}


void register_bytearray_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_byte_array_class(ns);
  register_byte_ref_class(ns);

  // int qstrcmp(const QByteArray &, const QByteArray &);
  bind::function<int, const QByteArray &, const QByteArray &, &qstrcmp>(ns, "strcmp").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QByteArray::Base64Options operator|(QByteArray::Base64Option, QByteArray::Base64Option);
  bind::op_bitor<QByteArray::Base64Options, QByteArray::Base64Option, QByteArray::Base64Option>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QByteArray::Base64Options operator|(QByteArray::Base64Option, QByteArray::Base64Options);
  bind::op_bitor<QByteArray::Base64Options, QByteArray::Base64Option, QByteArray::Base64Options>(ns);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QIncompatibleFlag operator|(QByteArray::Base64Options::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QByteArray::Base64Options::enum_type, int);
#endif
  // bool operator==(const QByteArray &, const QByteArray &);
  bind::op_eq<const QByteArray &, const QByteArray &>(ns);
  // bool operator!=(const QByteArray &, const QByteArray &);
  bind::op_neq<const QByteArray &, const QByteArray &>(ns);
  // bool operator<(const QByteArray &, const QByteArray &);
  bind::op_less<const QByteArray &, const QByteArray &>(ns);
  // bool operator<=(const QByteArray &, const QByteArray &);
  bind::op_leq<const QByteArray &, const QByteArray &>(ns);
  // bool operator>(const QByteArray &, const QByteArray &);
  bind::op_greater<const QByteArray &, const QByteArray &>(ns);
  // bool operator>=(const QByteArray &, const QByteArray &);
  bind::op_geq<const QByteArray &, const QByteArray &>(ns);
  // const QByteArray operator+(const QByteArray &, const QByteArray &);
  bind::op_add<const QByteArray, const QByteArray &, const QByteArray &>(ns);
  // const QByteArray operator+(const QByteArray &, char);
  bind::op_add<const QByteArray, const QByteArray &, char>(ns);
  // const QByteArray operator+(char, const QByteArray &);
  bind::op_add<const QByteArray, char, const QByteArray &>(ns);
  // QDataStream & operator<<(QDataStream &, const QByteArray &);
  bind::op_put_to<QDataStream &, const QByteArray &>(ns);
  // QDataStream & operator>>(QDataStream &, QByteArray &);
  bind::op_read_from<QDataStream &, QByteArray &>(ns);
  // QByteArray qCompress(const QByteArray &, int);
  bind::function<QByteArray, const QByteArray &, int, &qCompress>(ns, "qCompress").create();
  // QByteArray qUncompress(const QByteArray &);
  bind::function<QByteArray, const QByteArray &, &qUncompress>(ns, "qUncompress").create();
}
