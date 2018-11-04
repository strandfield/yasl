// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/bytearray.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"
#include "yasl/core/listspecializations.h"

#include "yasl/core/bytearray-functions.h"
#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_byte_array_base64_option_enum(script::Class byte_array)
{
  using namespace script;

  Enum base64_option = byte_array.Enum("Base64Option").setId(script::Type::QByteArrayBase64Option).get();

  register_qflags_type<QByteArray::Base64Option>(byte_array, "Base64Options", script::Type::QByteArrayBase64Options);
  base64_option.addValue("Base64Encoding", QByteArray::Base64Encoding);
  base64_option.addValue("Base64UrlEncoding", QByteArray::Base64UrlEncoding);
  base64_option.addValue("KeepTrailingEquals", QByteArray::KeepTrailingEquals);
  base64_option.addValue("OmitTrailingEquals", QByteArray::OmitTrailingEquals);
}


static void register_byte_array_class(script::Namespace ns)
{
  using namespace script;

  Class byte_array = ns.Class("ByteArray").setId(script::Type::QByteArray).get();

  register_proxy_specialization<QByteArray>(byte_array.engine()->getTemplate(Engine::ProxyTemplate), script::Type::ProxyQByteArray);
  register_list_specialization<QByteArray>(byte_array.engine(), script::Type::QListQByteArray);
  register_byte_array_base64_option_enum(byte_array);
  binding::ClassBinder<QByteArray> binder{ byte_array };

  // QByteArray();
  binder.default_ctor().create();
  // QByteArray(int, char);
  binder.ctor<int, char>().create();
  // QByteArray(int, Qt::Initialization);
  binder.ctor<int, Qt::Initialization>().create();
  // QByteArray(const QByteArray &);
  binder.ctor<const QByteArray &>().create();
  // ~QByteArray();
  binder.dtor().create();
  // QByteArray & operator=(const QByteArray &);
  binder.operators().assign<const QByteArray &>();
  // QByteArray(QByteArray &&);
  binder.ctor<QByteArray &&>().create();
  // QByteArray & operator=(QByteArray &&);
  binder.operators().assign<QByteArray &&>();
  // void swap(QByteArray &);
  binder.void_fun<QByteArray &, &QByteArray::swap>("swap").create();
  // int size() const;
  binder.fun<int, &QByteArray::size>("size").create();
  // bool isEmpty() const;
  binder.fun<bool, &QByteArray::isEmpty>("isEmpty").create();
  // void resize(int);
  binder.void_fun<int, &QByteArray::resize>("resize").create();
  // QByteArray & fill(char, int);
  binder.chainable<char, int, &QByteArray::fill>("fill")
    .apply(binding::default_arguments(-1)).create();
  // int capacity() const;
  binder.fun<int, &QByteArray::capacity>("capacity").create();
  // void reserve(int);
  binder.void_fun<int, &QByteArray::reserve>("reserve").create();
  // void squeeze();
  binder.void_fun<&QByteArray::squeeze>("squeeze").create();
  // void detach();
  binder.void_fun<&QByteArray::detach>("detach").create();
  // bool isDetached() const;
  binder.fun<bool, &QByteArray::isDetached>("isDetached").create();
  // bool isSharedWith(const QByteArray &) const;
  binder.fun<bool, const QByteArray &, &QByteArray::isSharedWith>("isSharedWith").create();
  // void clear();
  binder.void_fun<&QByteArray::clear>("clear").create();
  // char at(int) const;
  binder.fun<char, int, &QByteArray::at>("at").create();
  // char operator[](int) const;
  binder.operators().const_subscript<char, int>();
  // QByteRef operator[](int);
  binder.operators().subscript<QByteRef, int>();
  // char front() const;
  binder.fun<char, &QByteArray::front>("front").create();
  // QByteRef front();
  binder.fun<QByteRef, &QByteArray::front>("front").create();
  // char back() const;
  binder.fun<char, &QByteArray::back>("back").create();
  // QByteRef back();
  binder.fun<QByteRef, &QByteArray::back>("back").create();
  // int indexOf(char, int) const;
  binder.fun<int, char, int, &QByteArray::indexOf>("indexOf")
    .apply(binding::default_arguments(0)).create();
  // int indexOf(const QByteArray &, int) const;
  binder.fun<int, const QByteArray &, int, &QByteArray::indexOf>("indexOf")
    .apply(binding::default_arguments(0)).create();
  // int lastIndexOf(char, int) const;
  binder.fun<int, char, int, &QByteArray::lastIndexOf>("lastIndexOf")
    .apply(binding::default_arguments(-1)).create();
  // int lastIndexOf(const QByteArray &, int) const;
  binder.fun<int, const QByteArray &, int, &QByteArray::lastIndexOf>("lastIndexOf")
    .apply(binding::default_arguments(-1)).create();
  // bool contains(char) const;
  binder.fun<bool, char, &QByteArray::contains>("contains").create();
  // bool contains(const QByteArray &) const;
  binder.fun<bool, const QByteArray &, &QByteArray::contains>("contains").create();
  // int count(char) const;
  binder.fun<int, char, &QByteArray::count>("count").create();
  // int count(const QByteArray &) const;
  binder.fun<int, const QByteArray &, &QByteArray::count>("count").create();
  // QByteArray left(int) const;
  binder.fun<QByteArray, int, &QByteArray::left>("left").create();
  // QByteArray right(int) const;
  binder.fun<QByteArray, int, &QByteArray::right>("right").create();
  // QByteArray mid(int, int) const;
  binder.fun<QByteArray, int, int, &QByteArray::mid>("mid")
    .apply(binding::default_arguments(-1)).create();
  // QByteArray chopped(int) const;
  binder.fun<QByteArray, int, &QByteArray::chopped>("chopped").create();
  // bool startsWith(const QByteArray &) const;
  binder.fun<bool, const QByteArray &, &QByteArray::startsWith>("startsWith").create();
  // bool startsWith(char) const;
  binder.fun<bool, char, &QByteArray::startsWith>("startsWith").create();
  // bool endsWith(const QByteArray &) const;
  binder.fun<bool, const QByteArray &, &QByteArray::endsWith>("endsWith").create();
  // bool endsWith(char) const;
  binder.fun<bool, char, &QByteArray::endsWith>("endsWith").create();
  // void truncate(int);
  binder.void_fun<int, &QByteArray::truncate>("truncate").create();
  // void chop(int);
  binder.void_fun<int, &QByteArray::chop>("chop").create();
  // QByteArray ba_toLower();
  binder.fun<QByteArray, &ba_toLower>("toLower").create();
  // QByteArray ba_toUpper();
  binder.fun<QByteArray, &ba_toUpper>("toUpper").create();
  // QByteArray ba_trimmed();
  binder.fun<QByteArray, &ba_trimmed>("trimmed").create();
  // QByteArray ba_simplified();
  binder.fun<QByteArray, &ba_simplified>("simplified").create();
  // QByteArray leftJustified(int, char, bool) const;
  binder.fun<QByteArray, int, char, bool, &QByteArray::leftJustified>("leftJustified")
    .apply(binding::default_arguments(false, ' ')).create();
  // QByteArray rightJustified(int, char, bool) const;
  binder.fun<QByteArray, int, char, bool, &QByteArray::rightJustified>("rightJustified")
    .apply(binding::default_arguments(false, ' ')).create();
  // QByteArray & prepend(char);
  binder.chainable<char, &QByteArray::prepend>("prepend").create();
  // QByteArray & prepend(int, char);
  binder.chainable<int, char, &QByteArray::prepend>("prepend").create();
  // QByteArray & prepend(const QByteArray &);
  binder.chainable<const QByteArray &, &QByteArray::prepend>("prepend").create();
  // QByteArray & append(char);
  binder.chainable<char, &QByteArray::append>("append").create();
  // QByteArray & append(int, char);
  binder.chainable<int, char, &QByteArray::append>("append").create();
  // QByteArray & append(const QByteArray &);
  binder.chainable<const QByteArray &, &QByteArray::append>("append").create();
  // QByteArray & insert(int, char);
  binder.chainable<int, char, &QByteArray::insert>("insert").create();
  // QByteArray & insert(int, int, char);
  binder.chainable<int, int, char, &QByteArray::insert>("insert").create();
  // QByteArray & insert(int, const QByteArray &);
  binder.chainable<int, const QByteArray &, &QByteArray::insert>("insert").create();
  // QByteArray & remove(int, int);
  binder.chainable<int, int, &QByteArray::remove>("remove").create();
  // QByteArray & replace(int, int, const QByteArray &);
  binder.chainable<int, int, const QByteArray &, &QByteArray::replace>("replace").create();
  // QByteArray & replace(char, const QByteArray &);
  binder.chainable<char, const QByteArray &, &QByteArray::replace>("replace").create();
  // QByteArray & replace(const QByteArray &, const QByteArray &);
  binder.chainable<const QByteArray &, const QByteArray &, &QByteArray::replace>("replace").create();
  // QByteArray & replace(char, char);
  binder.chainable<char, char, &QByteArray::replace>("replace").create();
  // QByteArray & operator+=(char);
  binder.operators().add_assign<char>();
  // QByteArray & operator+=(const QByteArray &);
  binder.operators().add_assign<const QByteArray &>();
  // QList<QByteArray> split(char) const;
  binder.fun<QList<QByteArray>, char, &QByteArray::split>("split").create();
  // QByteArray repeated(int) const;
  binder.fun<QByteArray, int, &QByteArray::repeated>("repeated").create();
  // QByteArray & append(const QString &);
  binder.chainable<const QString &, &QByteArray::append>("append").create();
  // QByteArray & insert(int, const QString &);
  binder.chainable<int, const QString &, &QByteArray::insert>("insert").create();
  // QByteArray & replace(char, const QString &);
  binder.chainable<char, const QString &, &QByteArray::replace>("replace").create();
  // QByteArray & replace(const QString &, const QByteArray &);
  binder.chainable<const QString &, const QByteArray &, &QByteArray::replace>("replace").create();
  // QByteArray & operator+=(const QString &);
  binder.operators().add_assign<const QString &>();
  // int indexOf(const QString &, int) const;
  binder.fun<int, const QString &, int, &QByteArray::indexOf>("indexOf").create();
  // int lastIndexOf(const QString &, int) const;
  binder.fun<int, const QString &, int, &QByteArray::lastIndexOf>("lastIndexOf").create();
  // bool operator==(const QString &) const;
  binder.operators().eq<const QString &>();
  // bool operator!=(const QString &) const;
  binder.operators().neq<const QString &>();
  // bool operator<(const QString &) const;
  binder.operators().less<const QString &>();
  // bool operator>(const QString &) const;
  binder.operators().greater<const QString &>();
  // bool operator<=(const QString &) const;
  binder.operators().leq<const QString &>();
  // bool operator>=(const QString &) const;
  binder.operators().geq<const QString &>();
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
  // QByteArray toBase64(QByteArray::Base64Options) const;
  binder.fun<QByteArray, QByteArray::Base64Options, &QByteArray::toBase64>("toBase64").create();
  // QByteArray toBase64() const;
  binder.fun<QByteArray, &QByteArray::toBase64>("toBase64").create();
  // QByteArray toHex() const;
  binder.fun<QByteArray, &QByteArray::toHex>("toHex").create();
  // QByteArray toHex(char) const;
  binder.fun<QByteArray, char, &QByteArray::toHex>("toHex").create();
  // QByteArray toPercentEncoding(const QByteArray &, const QByteArray &, char) const;
  binder.fun<QByteArray, const QByteArray &, const QByteArray &, char, &QByteArray::toPercentEncoding>("toPercentEncoding").create();
  // QByteArray & setNum(short, int);
  /// TODO: QByteArray & setNum(short, int);
  // QByteArray & setNum(ushort, int);
  /// TODO: QByteArray & setNum(ushort, int);
  // QByteArray & setNum(int, int);
  binder.chainable<int, int, &QByteArray::setNum>("setNum")
    .apply(binding::default_arguments(10)).create();
  // QByteArray & setNum(qlonglong, int);
  /// TODO: QByteArray & setNum(qlonglong, int);
  // QByteArray & setNum(qulonglong, int);
  /// TODO: QByteArray & setNum(qulonglong, int);
  // QByteArray & setNum(float, char, int);
  binder.chainable<float, char, int, &QByteArray::setNum>("setNum")
    .apply(binding::default_arguments(6, 'g')).create();
  // QByteArray & setNum(double, char, int);
  binder.chainable<double, char, int, &QByteArray::setNum>("setNum")
    .apply(binding::default_arguments(6, 'g')).create();
  // static QByteArray number(int, int);
  binder.static_fun<QByteArray, int, int, &QByteArray::number>("number").create();
  // static QByteArray number(qlonglong, int);
  /// TODO: static QByteArray number(qlonglong, int);
  // static QByteArray number(qulonglong, int);
  /// TODO: static QByteArray number(qulonglong, int);
  // static QByteArray number(double, char, int);
  binder.static_fun<QByteArray, double, char, int, &QByteArray::number>("number").create();
  // static QByteArray fromBase64(const QByteArray &, QByteArray::Base64Options);
  binder.static_fun<QByteArray, const QByteArray &, QByteArray::Base64Options, &QByteArray::fromBase64>("fromBase64").create();
  // static QByteArray fromBase64(const QByteArray &);
  binder.static_fun<QByteArray, const QByteArray &, &QByteArray::fromBase64>("fromBase64").create();
  // static QByteArray fromHex(const QByteArray &);
  binder.static_fun<QByteArray, const QByteArray &, &QByteArray::fromHex>("fromHex").create();
  // static QByteArray fromPercentEncoding(const QByteArray &, char);
  binder.static_fun<QByteArray, const QByteArray &, char, &QByteArray::fromPercentEncoding>("fromPercentEncoding").create();
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
  binder.void_fun<char, &QByteArray::push_back>("push_back").create();
  // void push_back(const QByteArray &);
  binder.void_fun<const QByteArray &, &QByteArray::push_back>("push_back").create();
  // void push_front(char);
  binder.void_fun<char, &QByteArray::push_front>("push_front").create();
  // void push_front(const QByteArray &);
  binder.void_fun<const QByteArray &, &QByteArray::push_front>("push_front").create();
  // void shrink_to_fit();
  binder.void_fun<&QByteArray::shrink_to_fit>("shrink_to_fit").create();
  // int count() const;
  binder.fun<int, &QByteArray::count>("count").create();
  // int length() const;
  binder.fun<int, &QByteArray::length>("length").create();
  // bool isNull() const;
  binder.fun<bool, &QByteArray::isNull>("isNull").create();
}


static void register_byte_ref_class(script::Namespace ns)
{
  using namespace script;

  Class byte_ref = ns.Class("ByteRef").setId(script::Type::QByteRef).get();

  binding::ClassBinder<QByteRef> binder{ byte_ref };

  // QByteRef & operator=(char);
  binder.operators().assign<char>();
  // QByteRef & operator=(const QByteRef &);
  binder.operators().assign<const QByteRef &>();
  // bool operator==(char) const;
  binder.operators().eq<char>();
  // bool operator!=(char) const;
  binder.operators().neq<char>();
  // bool operator>(char) const;
  binder.operators().greater<char>();
  // bool operator>=(char) const;
  binder.operators().geq<char>();
  // bool operator<(char) const;
  binder.operators().less<char>();
  // bool operator<=(char) const;
  binder.operators().leq<char>();
}


void register_bytearray_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_byte_array_class(ns);
  register_byte_ref_class(ns);
  binding::Namespace binder{ ns };

  // int qstrcmp(const QByteArray &, const QByteArray &);
  binder.fun<int, const QByteArray &, const QByteArray &, &qstrcmp>("strcmp").create();
  // QByteArray::Base64Options operator|(QByteArray::Base64Option, QByteArray::Base64Option);
  binder.operators().or<QByteArray::Base64Options, QByteArray::Base64Option, QByteArray::Base64Option>();
  // QByteArray::Base64Options operator|(QByteArray::Base64Option, QByteArray::Base64Options);
  binder.operators().or<QByteArray::Base64Options, QByteArray::Base64Option, QByteArray::Base64Options>();
  // QIncompatibleFlag operator|(QByteArray::Base64Options::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QByteArray::Base64Options::enum_type, int);
  // bool operator==(const QByteArray &, const QByteArray &);
  binder.operators().eq<const QByteArray &, const QByteArray &>();
  // bool operator!=(const QByteArray &, const QByteArray &);
  binder.operators().neq<const QByteArray &, const QByteArray &>();
  // bool operator<(const QByteArray &, const QByteArray &);
  binder.operators().less<const QByteArray &, const QByteArray &>();
  // bool operator<=(const QByteArray &, const QByteArray &);
  binder.operators().leq<const QByteArray &, const QByteArray &>();
  // bool operator>(const QByteArray &, const QByteArray &);
  binder.operators().greater<const QByteArray &, const QByteArray &>();
  // bool operator>=(const QByteArray &, const QByteArray &);
  binder.operators().geq<const QByteArray &, const QByteArray &>();
  // const QByteArray operator+(const QByteArray &, const QByteArray &);
  binder.operators().add<const QByteArray, const QByteArray &, const QByteArray &>();
  // const QByteArray operator+(const QByteArray &, char);
  binder.operators().add<const QByteArray, const QByteArray &, char>();
  // const QByteArray operator+(char, const QByteArray &);
  binder.operators().add<const QByteArray, char, const QByteArray &>();
  // QDataStream & operator<<(QDataStream &, const QByteArray &);
  binder.operators().put_to<QDataStream &, const QByteArray &>();
  // QDataStream & operator>>(QDataStream &, QByteArray &);
  binder.operators().read_from<QDataStream &, QByteArray &>();
  // QByteArray qCompress(const QByteArray &, int);
  binder.fun<QByteArray, const QByteArray &, int, &qCompress>("qCompress").create();
  // QByteArray qUncompress(const QByteArray &);
  binder.fun<QByteArray, const QByteArray &, &qUncompress>("qUncompress").create();
  // void swap(QByteArray &, QByteArray &);
  binder.void_fun<QByteArray &, QByteArray &, &swap>("swap").create();
}

