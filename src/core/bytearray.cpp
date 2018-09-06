// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/bytearray.h"

#include "yasl/binding/class.h"
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

  register_ptr_specialization<QByteArray>(byte_array.engine()->getTemplate(Engine::PtrTemplate), script::Type::PtrQByteArray);
  register_list_specialization<QByteArray>(byte_array.engine(), script::Type::QListQByteArray);
  register_byte_array_base64_option_enum(byte_array);
  binding::Class<QByteArray> binder{ byte_array };

  // QByteArray();
  binder.ctors().add_default();
  // QByteArray(int, char);
  binder.ctors().add<int, char>();
  // QByteArray(int, Qt::Initialization);
  binder.ctors().add<int, Qt::Initialization>();
  // QByteArray(const QByteArray &);
  binder.ctors().add<const QByteArray &>();
  // ~QByteArray();
  binder.add_dtor();
  // QByteArray & operator=(const QByteArray &);
  binder.operators().assign<const QByteArray &>();
  // QByteArray(QByteArray &&);
  binder.ctors().add<QByteArray &&>();
  // QByteArray & operator=(QByteArray &&);
  binder.operators().assign<QByteArray &&>();
  // void swap(QByteArray &);
  binder.add_void_fun<QByteArray &, &QByteArray::swap>("swap");
  // int size() const;
  binder.add_fun<int, &QByteArray::size>("size");
  // bool isEmpty() const;
  binder.add_fun<bool, &QByteArray::isEmpty>("isEmpty");
  // void resize(int);
  binder.add_void_fun<int, &QByteArray::resize>("resize");
  // QByteArray & fill(char, int);
  binder.add_chainable<char, int, &QByteArray::fill>("fill");
  // int capacity() const;
  binder.add_fun<int, &QByteArray::capacity>("capacity");
  // void reserve(int);
  binder.add_void_fun<int, &QByteArray::reserve>("reserve");
  // void squeeze();
  binder.add_void_fun<&QByteArray::squeeze>("squeeze");
  // void detach();
  binder.add_void_fun<&QByteArray::detach>("detach");
  // bool isDetached() const;
  binder.add_fun<bool, &QByteArray::isDetached>("isDetached");
  // bool isSharedWith(const QByteArray &) const;
  binder.add_fun<bool, const QByteArray &, &QByteArray::isSharedWith>("isSharedWith");
  // void clear();
  binder.add_void_fun<&QByteArray::clear>("clear");
  // char at(int) const;
  binder.add_fun<char, int, &QByteArray::at>("at");
  // char operator[](int) const;
  binder.operators().const_subscript<char, int>();
  // QByteRef operator[](int);
  binder.operators().subscript<QByteRef, int>();
  // char front() const;
  binder.add_fun<char, &QByteArray::front>("front");
  // QByteRef front();
  binder.add_fun<QByteRef, &QByteArray::front>("front");
  // char back() const;
  binder.add_fun<char, &QByteArray::back>("back");
  // QByteRef back();
  binder.add_fun<QByteRef, &QByteArray::back>("back");
  // int indexOf(char, int) const;
  binder.add_fun<int, char, int, &QByteArray::indexOf>("indexOf");
  // int indexOf(const QByteArray &, int) const;
  binder.add_fun<int, const QByteArray &, int, &QByteArray::indexOf>("indexOf");
  // int lastIndexOf(char, int) const;
  binder.add_fun<int, char, int, &QByteArray::lastIndexOf>("lastIndexOf");
  // int lastIndexOf(const QByteArray &, int) const;
  binder.add_fun<int, const QByteArray &, int, &QByteArray::lastIndexOf>("lastIndexOf");
  // bool contains(char) const;
  binder.add_fun<bool, char, &QByteArray::contains>("contains");
  // bool contains(const QByteArray &) const;
  binder.add_fun<bool, const QByteArray &, &QByteArray::contains>("contains");
  // int count(char) const;
  binder.add_fun<int, char, &QByteArray::count>("count");
  // int count(const QByteArray &) const;
  binder.add_fun<int, const QByteArray &, &QByteArray::count>("count");
  // QByteArray left(int) const;
  binder.add_fun<QByteArray, int, &QByteArray::left>("left");
  // QByteArray right(int) const;
  binder.add_fun<QByteArray, int, &QByteArray::right>("right");
  // QByteArray mid(int, int) const;
  binder.add_fun<QByteArray, int, int, &QByteArray::mid>("mid");
  // QByteArray chopped(int) const;
  binder.add_fun<QByteArray, int, &QByteArray::chopped>("chopped");
  // bool startsWith(const QByteArray &) const;
  binder.add_fun<bool, const QByteArray &, &QByteArray::startsWith>("startsWith");
  // bool startsWith(char) const;
  binder.add_fun<bool, char, &QByteArray::startsWith>("startsWith");
  // bool endsWith(const QByteArray &) const;
  binder.add_fun<bool, const QByteArray &, &QByteArray::endsWith>("endsWith");
  // bool endsWith(char) const;
  binder.add_fun<bool, char, &QByteArray::endsWith>("endsWith");
  // void truncate(int);
  binder.add_void_fun<int, &QByteArray::truncate>("truncate");
  // void chop(int);
  binder.add_void_fun<int, &QByteArray::chop>("chop");
  // QByteArray ba_toLower();
  binder.add_fun<QByteArray, &ba_toLower>("toLower");
  // QByteArray ba_toUpper();
  binder.add_fun<QByteArray, &ba_toUpper>("toUpper");
  // QByteArray ba_trimmed();
  binder.add_fun<QByteArray, &ba_trimmed>("trimmed");
  // QByteArray ba_simplified();
  binder.add_fun<QByteArray, &ba_simplified>("simplified");
  // QByteArray leftJustified(int, char, bool) const;
  binder.add_fun<QByteArray, int, char, bool, &QByteArray::leftJustified>("leftJustified");
  // QByteArray rightJustified(int, char, bool) const;
  binder.add_fun<QByteArray, int, char, bool, &QByteArray::rightJustified>("rightJustified");
  // QByteArray & prepend(char);
  binder.add_chainable<char, &QByteArray::prepend>("prepend");
  // QByteArray & prepend(int, char);
  binder.add_chainable<int, char, &QByteArray::prepend>("prepend");
  // QByteArray & prepend(const QByteArray &);
  binder.add_chainable<const QByteArray &, &QByteArray::prepend>("prepend");
  // QByteArray & append(char);
  binder.add_chainable<char, &QByteArray::append>("append");
  // QByteArray & append(int, char);
  binder.add_chainable<int, char, &QByteArray::append>("append");
  // QByteArray & append(const QByteArray &);
  binder.add_chainable<const QByteArray &, &QByteArray::append>("append");
  // QByteArray & insert(int, char);
  binder.add_chainable<int, char, &QByteArray::insert>("insert");
  // QByteArray & insert(int, int, char);
  binder.add_chainable<int, int, char, &QByteArray::insert>("insert");
  // QByteArray & insert(int, const QByteArray &);
  binder.add_chainable<int, const QByteArray &, &QByteArray::insert>("insert");
  // QByteArray & remove(int, int);
  binder.add_chainable<int, int, &QByteArray::remove>("remove");
  // QByteArray & replace(int, int, const QByteArray &);
  binder.add_chainable<int, int, const QByteArray &, &QByteArray::replace>("replace");
  // QByteArray & replace(char, const QByteArray &);
  binder.add_chainable<char, const QByteArray &, &QByteArray::replace>("replace");
  // QByteArray & replace(const QByteArray &, const QByteArray &);
  binder.add_chainable<const QByteArray &, const QByteArray &, &QByteArray::replace>("replace");
  // QByteArray & replace(char, char);
  binder.add_chainable<char, char, &QByteArray::replace>("replace");
  // QByteArray & operator+=(char);
  binder.operators().add_assign<char>();
  // QByteArray & operator+=(const QByteArray &);
  binder.operators().add_assign<const QByteArray &>();
  // QList<QByteArray> split(char) const;
  binder.add_fun<QList<QByteArray>, char, &QByteArray::split>("split");
  // QByteArray repeated(int) const;
  binder.add_fun<QByteArray, int, &QByteArray::repeated>("repeated");
  // QByteArray & append(const QString &);
  binder.add_chainable<const QString &, &QByteArray::append>("append");
  // QByteArray & insert(int, const QString &);
  binder.add_chainable<int, const QString &, &QByteArray::insert>("insert");
  // QByteArray & replace(char, const QString &);
  binder.add_chainable<char, const QString &, &QByteArray::replace>("replace");
  // QByteArray & replace(const QString &, const QByteArray &);
  binder.add_chainable<const QString &, const QByteArray &, &QByteArray::replace>("replace");
  // QByteArray & operator+=(const QString &);
  binder.operators().add_assign<const QString &>();
  // int indexOf(const QString &, int) const;
  binder.add_fun<int, const QString &, int, &QByteArray::indexOf>("indexOf");
  // int lastIndexOf(const QString &, int) const;
  binder.add_fun<int, const QString &, int, &QByteArray::lastIndexOf>("lastIndexOf");
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
  binder.add_fun<QByteArray, QByteArray::Base64Options, &QByteArray::toBase64>("toBase64");
  // QByteArray toBase64() const;
  binder.add_fun<QByteArray, &QByteArray::toBase64>("toBase64");
  // QByteArray toHex() const;
  binder.add_fun<QByteArray, &QByteArray::toHex>("toHex");
  // QByteArray toHex(char) const;
  binder.add_fun<QByteArray, char, &QByteArray::toHex>("toHex");
  // QByteArray toPercentEncoding(const QByteArray &, const QByteArray &, char) const;
  binder.add_fun<QByteArray, const QByteArray &, const QByteArray &, char, &QByteArray::toPercentEncoding>("toPercentEncoding");
  // QByteArray & setNum(short, int);
  /// TODO: QByteArray & setNum(short, int);
  // QByteArray & setNum(ushort, int);
  /// TODO: QByteArray & setNum(ushort, int);
  // QByteArray & setNum(int, int);
  binder.add_chainable<int, int, &QByteArray::setNum>("setNum");
  // QByteArray & setNum(qlonglong, int);
  /// TODO: QByteArray & setNum(qlonglong, int);
  // QByteArray & setNum(qulonglong, int);
  /// TODO: QByteArray & setNum(qulonglong, int);
  // QByteArray & setNum(float, char, int);
  binder.add_chainable<float, char, int, &QByteArray::setNum>("setNum");
  // QByteArray & setNum(double, char, int);
  binder.add_chainable<double, char, int, &QByteArray::setNum>("setNum");
  // static QByteArray number(int, int);
  binder.add_static<QByteArray, int, int, &QByteArray::number>("number");
  // static QByteArray number(qlonglong, int);
  /// TODO: static QByteArray number(qlonglong, int);
  // static QByteArray number(qulonglong, int);
  /// TODO: static QByteArray number(qulonglong, int);
  // static QByteArray number(double, char, int);
  binder.add_static<QByteArray, double, char, int, &QByteArray::number>("number");
  // static QByteArray fromBase64(const QByteArray &, QByteArray::Base64Options);
  binder.add_static<QByteArray, const QByteArray &, QByteArray::Base64Options, &QByteArray::fromBase64>("fromBase64");
  // static QByteArray fromBase64(const QByteArray &);
  binder.add_static<QByteArray, const QByteArray &, &QByteArray::fromBase64>("fromBase64");
  // static QByteArray fromHex(const QByteArray &);
  binder.add_static<QByteArray, const QByteArray &, &QByteArray::fromHex>("fromHex");
  // static QByteArray fromPercentEncoding(const QByteArray &, char);
  binder.add_static<QByteArray, const QByteArray &, char, &QByteArray::fromPercentEncoding>("fromPercentEncoding");
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
  binder.add_void_fun<char, &QByteArray::push_back>("push_back");
  // void push_back(const QByteArray &);
  binder.add_void_fun<const QByteArray &, &QByteArray::push_back>("push_back");
  // void push_front(char);
  binder.add_void_fun<char, &QByteArray::push_front>("push_front");
  // void push_front(const QByteArray &);
  binder.add_void_fun<const QByteArray &, &QByteArray::push_front>("push_front");
  // void shrink_to_fit();
  binder.add_void_fun<&QByteArray::shrink_to_fit>("shrink_to_fit");
  // int count() const;
  binder.add_fun<int, &QByteArray::count>("count");
  // int length() const;
  binder.add_fun<int, &QByteArray::length>("length");
  // bool isNull() const;
  binder.add_fun<bool, &QByteArray::isNull>("isNull");
}


static void register_byte_ref_class(script::Namespace ns)
{
  using namespace script;

  Class byte_ref = ns.Class("ByteRef").setId(script::Type::QByteRef).get();

  binding::Class<QByteRef> binder{ byte_ref };

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
  binder.add_fun<int, const QByteArray &, const QByteArray &, &qstrcmp>("strcmp");
  // QFlags<QByteArray::Base64Options::enum_type> operator|(QByteArray::Base64Options::enum_type, QByteArray::Base64Options::enum_type);
  /// TODO: QFlags<QByteArray::Base64Options::enum_type> operator|(QByteArray::Base64Options::enum_type, QByteArray::Base64Options::enum_type);
  // QFlags<QByteArray::Base64Options::enum_type> operator|(QByteArray::Base64Options::enum_type, QFlags<QByteArray::Base64Options::enum_type>);
  /// TODO: QFlags<QByteArray::Base64Options::enum_type> operator|(QByteArray::Base64Options::enum_type, QFlags<QByteArray::Base64Options::enum_type>);
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
  binder.add_fun<QByteArray, const QByteArray &, int, &qCompress>("qCompress");
  // QByteArray qUncompress(const QByteArray &);
  binder.add_fun<QByteArray, const QByteArray &, &qUncompress>("qUncompress");
  // void swap(QByteArray &, QByteArray &);
  binder.add_void_fun<QByteArray &, QByteArray &, &swap>("swap");
}

