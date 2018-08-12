// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/bytearray.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/macros.h"
#include "yasl/core/listspecializations.h"

#include <script/classbuilder.h>
#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>

QByteArray ba_simplified(const QByteArray & ba)
{
  return ba.simplified();
}

void register_qbytearray(script::Namespace ns)
{
  using namespace script;

  Class qbytearray_class = ns.Class("ByteArray").setFinal().setId(Type::QByteArray).get();
  Type bytearray_type = qbytearray_class.id();

  register_ptr_specialization<QByteArray>(ns.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQByteArray);
  register_list_specialization<QByteArray>(ns.engine(), Type::QListQByteArray);

  auto ba = binding::Class<QByteArray>{ qbytearray_class };
  ba.ctors().add_default();
  ba.ctors().add_copy();
  ba.ctors().add<int, char>();
  ba.add_dtor();

  ba.add_chainable<const QByteArray &, &QByteArray::append>("append");
  ba.add_chainable<int, char, &QByteArray::append>("append");
  //QByteArray & append(const char *str)
  //QByteArray & append(const char *str, int len)
  ba.add_chainable<const QString &, &QByteArray::append>("append");
  ba.add_fun<char, int, &QByteArray::at>("at");
  ba.add_fun<char, &QByteArray::back>("back");

  // QByteRef back()
  // QByteArray::iterator begin()
  // QByteArray::const_iterator begin() const
  ba.add_fun<int, &QByteArray::capacity>("capacity");
  // QByteArray::const_iterator cbegin() const
  // QByteArray::const_iterator cend() const
  ba.add_void_fun<int, &QByteArray::chop>("chop");
  ba.add_fun<QByteArray, int, &QByteArray::chopped>("chopped");
  ba.add_void_fun<&QByteArray::clear>("clear");
  // QByteArray::const_iterator constBegin() const
  // const char * constData() const
  // QByteArray::const_iterator constEnd() const
  ba.add_fun<bool, const QByteArray&, &QByteArray::contains>("contains");
  // bool contains(const char *str) const
  ba.add_fun<bool, char, &QByteArray::contains>("contains");
  ba.add_fun<int, const QByteArray &, &QByteArray::count>("count");
  // int count(const char *str) const
  ba.add_fun<int, char, &QByteArray::count>("count");
  ba.add_fun<int, &QByteArray::count>("count");
  // QByteArray::const_reverse_iterator crbegin() const
  // QByteArray::const_reverse_iterator crend() const
  // char * data()
  // const char * data() const
  // QByteArray::iterator end()
  // QByteArray::const_iterator end() const
  ba.add_fun<bool, const QByteArray &, &QByteArray::endsWith>("endsWith");
  ba.add_fun<bool, char, &QByteArray::endsWith>("endsWith");
  // bool endsWith(const char *str) const
  ba.add_chainable<char, int, &QByteArray::fill>("fill"); /// TODO : add default argument value, see next line
  // QByteArray & fill(char ch, int size = -1)
  ba.add_fun<char, &QByteArray::front>("front");
  // QByteRef front()
  ba.add_fun<int, const QByteArray &, int, &QByteArray::indexOf>("indexOf");  /// TODO : add default argument value, see next line
  // int indexOf(const QByteArray &ba, int from = 0) const
  // int indexOf(const char *str, int from = 0) const
  ba.add_fun<int, char, int, &QByteArray::indexOf>("indexOf");  /// TODO : add default argument value, see next line
  // int indexOf(char ch, int from = 0) const
  ba.add_fun<int, const QString &, int, &QByteArray::indexOf>("indexOf");  /// TODO : add default argument value, see next line
  // int indexOf(const QString &str, int from = 0) const
  ba.add_chainable<int, const QByteArray&, &QByteArray::insert>("insert");
  // QByteArray & insert(int i, const QByteArray &ba)
  // QByteArray & insert(int i, int count, char ch)
  ba.add_chainable<int, int, char, &QByteArray::insert>("insert");
  // QByteArray & insert(int i, const char *str)
  // QByteArray & insert(int i, const char *str, int len)
  // QByteArray & insert(int i, char ch)
  ba.add_chainable<int, char, &QByteArray::insert>("insert");
  // QByteArray & insert(int i, const QString &str)
  ba.add_chainable<int, const QString &, &QByteArray::insert>("insert");
  // bool isEmpty() const
  ba.add_fun<bool, &QByteArray::isEmpty>("isEmpty");
  // bool isNull() const
  ba.add_fun<bool, &QByteArray::isNull>("isNull");
  // int lastIndexOf(const QByteArray &ba, int from = -1) const
  ba.add_fun<int, const QByteArray &, int, &QByteArray::lastIndexOf>("lastIndexOf");
  // int lastIndexOf(const char *str, int from = -1) const
  // int lastIndexOf(char ch, int from = -1) const
  ba.add_fun<int, char, int, &QByteArray::lastIndexOf>("lastIndexOf");
  // int lastIndexOf(const QString &str, int from = -1) const
  ba.add_fun<int, const QString &, int, &QByteArray::lastIndexOf>("lastIndexOf");
  // QByteArray left(int len) const
  ba.add_fun<QByteArray, int, &QByteArray::left>("left");
  // QByteArray leftJustified(int width, char fill = ' ', bool truncate = false) const
  ba.add_fun<QByteArray, int, char, bool, &QByteArray::leftJustified>("leftJustified");
  // int length() const
  ba.add_fun<int, &QByteArray::length>("length");
  // QByteArray mid(int pos, int len = -1) const
  ba.add_fun<QByteArray, int, int, &QByteArray::mid>("mid");
  // QByteArray & prepend(const QByteArray &ba)
  ba.add_chainable<const QByteArray &, &QByteArray::prepend>("prepend");
  // QByteArray & prepend(int count, char ch)
  ba.add_chainable<int, char, &QByteArray::prepend>("prepend");
  // QByteArray & prepend(const char *str)
  // QByteArray & prepend(const char *str, int len)
  // QByteArray & prepend(char ch)
  ba.add_chainable<char, &QByteArray::prepend>("prepend");
  // void push_back(const QByteArray &other)
  // void push_back(const char *str)
  // void push_back(char ch)
  // void push_front(const QByteArray &other)
  // void push_front(const char *str)
  // void push_front(char ch)
  // QByteArray::reverse_iterator rbegin()
  // QByteArray::const_reverse_iterator rbegin() const
  // QByteArray & remove(int pos, int len)
  ba.add_chainable<int, int, &QByteArray::remove>("remove");
  // QByteArray::reverse_iterator rend()
  // QByteArray::const_reverse_iterator rend() const
  // QByteArray repeated(int times) const
  ba.add_fun<QByteArray, int, &QByteArray::repeated>("repeated");
  // QByteArray & replace(int pos, int len, const QByteArray &after)
  ba.add_chainable<int, int, const QByteArray&, &QByteArray::replace>("replace");
  // QByteArray & replace(int pos, int len, const char *after, int alen)
  // QByteArray & replace(int pos, int len, const char *after)
  // QByteArray & replace(char before, const char *after)
  // QByteArray & replace(char before, const QByteArray &after)
  ba.add_chainable<char, const QByteArray&, &QByteArray::replace>("replace");
  // QByteArray & replace(const char *before, const char *after)
  // QByteArray & replace(const char *before, int bsize, const char *after, int asize)
  // QByteArray & replace(const QByteArray &before, const QByteArray &after)
  ba.add_chainable<const QByteArray&, const QByteArray&, &QByteArray::replace>("replace");
  // QByteArray & replace(const QByteArray &before, const char *after)
  // QByteArray & replace(const char *before, const QByteArray &after)
  // QByteArray & replace(char before, char after)
  ba.add_chainable<char, char, &QByteArray::replace>("replace");
  // QByteArray & replace(const QString &before, const char *after)
  // QByteArray & replace(char before, const QString &after)
  ba.add_chainable<char, const QString &, &QByteArray::replace>("replace");
  // QByteArray & replace(const QString &before, const QByteArray &after)
  ba.add_chainable<const QString &, const QByteArray &, &QByteArray::replace>("replace");
  // void reserve(int size)
  ba.add_void_fun<int, &QByteArray::reserve>("reserve");
  // void resize(int size)
  ba.add_void_fun<int, &QByteArray::resize>("resize");
  // QByteArray right(int len) const
  ba.add_fun<QByteArray, int, &QByteArray::right>("right");
  // QByteArray rightJustified(int width, char fill = ' ', bool truncate = false) const
  // QByteArray & setNum(int n, int base = 10)
  ba.add_chainable<int, int, &QByteArray::setNum>("setNum");
  // QByteArray & setNum(ushort n, int base = 10)
  // QByteArray & setNum(short n, int base = 10)
  // QByteArray & setNum(uint n, int base = 10)
  // QByteArray & setNum(qlonglong n, int base = 10)
  // QByteArray & setNum(qulonglong n, int base = 10)
  // QByteArray & setNum(float n, char f = 'g', int prec = 6)
  ba.add_chainable<float, char, int, &QByteArray::setNum>("setNum");
  // QByteArray & setNum(double n, char f = 'g', int prec = 6)
  ba.add_chainable<double, char, int, &QByteArray::setNum>("setNum");
  // QByteArray & setRawData(const char *data, uint size)
  // void shrink_to_fit()
  ba.add_void_fun<&QByteArray::shrink_to_fit>("shrink_to_fit");
  // QByteArray simplified() const
  /// TODO : somehow this is not working : ba.add_fun<QByteArray, static_cast<QByteArray(QByteArray::*)()>(&QByteArray::simplified)>("simplified");
  ba.add_fun<QByteArray, &ba_simplified>("simplified");
  // int size() const
  ba.add_fun<int, &QByteArray::size>("size");
  // QList<QByteArray> split(char sep) const
  // void squeeze()
  ba.add_void_fun<&QByteArray::squeeze>("squeeze");
  // bool startsWith(const QByteArray &ba) const
  ba.add_fun<bool, const QByteArray&, &QByteArray::startsWith>("startsWith");
  // bool startsWith(char ch) const
  ba.add_fun<bool, char, &QByteArray::startsWith>("startsWith");
  // bool startsWith(const char *str) const
  // void swap(QByteArray &other)
  ba.add_void_fun<QByteArray&, &QByteArray::swap>("swap");
  // QByteArray toBase64() const
  ba.add_fun<QByteArray, &QByteArray::toBase64>("toBase64");
  // QByteArray toBase64(QByteArray::Base64Options options) const
  // CFDataRef toCFData() const
  // double toDouble(bool *ok = nullptr) const
  // float toFloat(bool *ok = nullptr) const
  // QByteArray toHex() const
  ba.add_fun<QByteArray, &QByteArray::toHex>("toHex");
  // QByteArray toHex(char separator) const
  ba.add_fun<QByteArray, char, &QByteArray::toHex>("toHex");
  // int toInt(bool *ok = nullptr, int base = 10) const
  // long toLong(bool *ok = nullptr, int base = 10) const
  // qlonglong toLongLong(bool *ok = nullptr, int base = 10) const
  // QByteArray toLower() const
  YASL_METHOD_0(qbytearray_class, "toLower", QByteArray, QByteArray, toLower).setConst().create();
  // NSData * toNSData() const
  // QByteArray toPercentEncoding(const QByteArray &exclude = QByteArray(), const QByteArray &include = QByteArray(), char percent = '%') const
  // CFDataRef toRawCFData() const
  // NSData * toRawNSData() const
  // short toShort(bool *ok = nullptr, int base = 10) const
  // std::string toStdString() const
  // uint toUInt(bool *ok = nullptr, int base = 10) const
  // ulong toULong(bool *ok = nullptr, int base = 10) const
  // qulonglong toULongLong(bool *ok = nullptr, int base = 10) const
  // ushort toUShort(bool *ok = nullptr, int base = 10) const
  // QByteArray toUpper() const
  YASL_METHOD_0(qbytearray_class, "toUpper", QByteArray, QByteArray, toUpper).setConst().create();
  // QByteArray trimmed() const
  YASL_METHOD_0(qbytearray_class, "trimmed", QByteArray, QByteArray, trimmed).setConst().create();
  // void truncate(int pos)
  ba.add_void_fun<int, &QByteArray::truncate>("truncate");

  // const char * operator const char *() const
  // const void * operator const void *() const
  // bool operator!=(const QString &str) const
  ba.operators().neq<const QString &>();
  // QByteArray & operator+=(const QByteArray &ba)
  // QByteArray & operator+=(const char *str)
  // QByteArray & operator+=(char ch)
  // QByteArray & operator+=(const QString &str)
  // bool operator<(const QString &str) const
  // bool operator<=(const QString &str) const
  // QByteArray & operator=(const QByteArray &other)
  ba.operators().assign<const QByteArray&>();
  // QByteArray & operator=(const char *str)
  // QByteArray & operator=(QByteArray &&other)
  // bool operator==(const QString &str) const
  ba.operators().eq<const QString &>();
  // bool operator>(const QString &str) const
  // bool operator>=(const QString &str) const
  // QByteRef operator[](int i)
  // char operator[](uint i) const
  // char operator[](int i) const
  ba.operators().subscript<char, int>();
  // QByteRef operator[](uint i)
  
  /* Non-members */

  binding::Namespace n{ ns };
  // bool operator!=(const QByteArray & a1, const QByteArray & a2)
  n.operators().neq<const QByteArray &, const QByteArray &>();
  // const QByteArray operator+(const QByteArray & a1, const QByteArray & a2)
  n.operators().add<const QByteArray, const QByteArray &, const QByteArray &>();
  // const QByteArray operator+(const QByteArray & a1, char a2)
  n.operators().add<const QByteArray, const QByteArray &, char>();
  // const QByteArray operator+(char a1, const QByteArray & a2)
  n.operators().add<const QByteArray, char, const QByteArray &>();
  // bool operator<(const QByteArray & a1, const QByteArray & a2)
  n.operators().less<const QByteArray &, const QByteArray &>();
  // QDataStream & operator<<(QDataStream & out, const QByteArray & ba)
  /// TODO : add this operator
  // bool operator<=(const QByteArray & a1, const QByteArray & a2)
  n.operators().leq<const QByteArray &, const QByteArray &>();
  // bool operator==(const QByteArray & a1, const QByteArray & a2)
  n.operators().eq<const QByteArray &, const QByteArray &>();
  // bool operator>(const QByteArray & a1, const QByteArray & a2)
  n.operators().greater<const QByteArray &, const QByteArray &>();
  // bool operator>=(const QByteArray & a1, const QByteArray & a2)
  n.operators().geq<const QByteArray &, const QByteArray &>();
}

//script::Value make_bytearray(const QByteArray & ba, script::Engine *e)
//{
//  script::Value val = e->construct(get_qbytearray_type(), {});
//  QByteArray &self = binding::value_cast<QByteArray&>(val);
//  self = ba;
//  return val;
//}
