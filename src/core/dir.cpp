// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/dir.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/char.h"
#include "yasl/core/dir.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_dir_filter_enum(script::Class dir)
{
  using namespace script;

  Enum filter = dir.newEnum("Filter").setId(script::Type::QDirFilter).get();

  register_qflags_type<QDir::Filter>(dir, "Filters", script::Type::QDirFilters);
  filter.addValue("Dirs", QDir::Dirs);
  filter.addValue("Files", QDir::Files);
  filter.addValue("Drives", QDir::Drives);
  filter.addValue("NoSymLinks", QDir::NoSymLinks);
  filter.addValue("AllEntries", QDir::AllEntries);
  filter.addValue("TypeMask", QDir::TypeMask);
  filter.addValue("Readable", QDir::Readable);
  filter.addValue("Writable", QDir::Writable);
  filter.addValue("Executable", QDir::Executable);
  filter.addValue("PermissionMask", QDir::PermissionMask);
  filter.addValue("Modified", QDir::Modified);
  filter.addValue("Hidden", QDir::Hidden);
  filter.addValue("System", QDir::System);
  filter.addValue("AccessMask", QDir::AccessMask);
  filter.addValue("AllDirs", QDir::AllDirs);
  filter.addValue("CaseSensitive", QDir::CaseSensitive);
  filter.addValue("NoDot", QDir::NoDot);
  filter.addValue("NoDotDot", QDir::NoDotDot);
  filter.addValue("NoDotAndDotDot", QDir::NoDotAndDotDot);
  filter.addValue("NoFilter", QDir::NoFilter);
}


static void register_dir_sort_flag_enum(script::Class dir)
{
  using namespace script;

  Enum sort_flag = dir.newEnum("SortFlag").setId(script::Type::QDirSortFlag).get();

  register_qflags_type<QDir::SortFlag>(dir, "SortFlags", script::Type::QDirSortFlags);
  sort_flag.addValue("Name", QDir::Name);
  sort_flag.addValue("Time", QDir::Time);
  sort_flag.addValue("Size", QDir::Size);
  sort_flag.addValue("Unsorted", QDir::Unsorted);
  sort_flag.addValue("SortByMask", QDir::SortByMask);
  sort_flag.addValue("DirsFirst", QDir::DirsFirst);
  sort_flag.addValue("Reversed", QDir::Reversed);
  sort_flag.addValue("IgnoreCase", QDir::IgnoreCase);
  sort_flag.addValue("DirsLast", QDir::DirsLast);
  sort_flag.addValue("LocaleAware", QDir::LocaleAware);
  sort_flag.addValue("Type", QDir::Type);
  sort_flag.addValue("NoSort", QDir::NoSort);
}


static void register_dir_class(script::Namespace ns)
{
  using namespace script;

  Class dir = ns.newClass("Dir").setId(script::Type::QDir).get();

  register_dir_filter_enum(dir);
  register_dir_sort_flag_enum(dir);
  binding::ClassBinder<QDir> binder{ dir };

  // QDir(const QDir &);
  binder.ctor<const QDir &>().create();
  // QDir(const QString &);
  binder.ctor<const QString &>()
    .apply(binding::default_arguments(QString())).create();
  // QDir(const QString &, const QString &, QDir::SortFlags, QDir::Filters);
  binder.ctor<const QString &, const QString &, QDir::SortFlags, QDir::Filters>()
    .apply(binding::default_arguments(QDir::Filters(QDir::AllEntries), QDir::SortFlags(QDir::Name | QDir::IgnoreCase))).create();
  // ~QDir();
  binder.dtor().create();
  // QDir & operator=(const QDir &);
  binder.operators().assign<const QDir &>();
  // QDir & operator=(const QString &);
  binder.operators().assign<const QString &>();
  // QDir & operator=(QDir &&);
  binder.operators().assign<QDir &&>();
  // void swap(QDir &);
  binder.void_fun<QDir &, &QDir::swap>("swap").create();
  // void setPath(const QString &);
  binder.void_fun<const QString &, &QDir::setPath>("setPath").create();
  // QString path() const;
  binder.fun<QString, &QDir::path>("path").create();
  // QString absolutePath() const;
  binder.fun<QString, &QDir::absolutePath>("absolutePath").create();
  // QString canonicalPath() const;
  binder.fun<QString, &QDir::canonicalPath>("canonicalPath").create();
  // static void addResourceSearchPath(const QString &);
  binder.static_void_fun<const QString &, &QDir::addResourceSearchPath>("addResourceSearchPath").create();
  // static void setSearchPaths(const QString &, const QStringList &);
  /// TODO: static void setSearchPaths(const QString &, const QStringList &);
  // static void addSearchPath(const QString &, const QString &);
  binder.static_void_fun<const QString &, const QString &, &QDir::addSearchPath>("addSearchPath").create();
  // static QStringList searchPaths(const QString &);
  /// TODO: static QStringList searchPaths(const QString &);
  // QString dirName() const;
  binder.fun<QString, &QDir::dirName>("dirName").create();
  // QString filePath(const QString &) const;
  binder.fun<QString, const QString &, &QDir::filePath>("filePath").create();
  // QString absoluteFilePath(const QString &) const;
  binder.fun<QString, const QString &, &QDir::absoluteFilePath>("absoluteFilePath").create();
  // QString relativeFilePath(const QString &) const;
  binder.fun<QString, const QString &, &QDir::relativeFilePath>("relativeFilePath").create();
  // static QString toNativeSeparators(const QString &);
  binder.static_fun<QString, const QString &, &QDir::toNativeSeparators>("toNativeSeparators").create();
  // static QString fromNativeSeparators(const QString &);
  binder.static_fun<QString, const QString &, &QDir::fromNativeSeparators>("fromNativeSeparators").create();
  // bool cd(const QString &);
  binder.fun<bool, const QString &, &QDir::cd>("cd").create();
  // bool cdUp();
  binder.fun<bool, &QDir::cdUp>("cdUp").create();
  // QStringList nameFilters() const;
  /// TODO: QStringList nameFilters() const;
  // void setNameFilters(const QStringList &);
  /// TODO: void setNameFilters(const QStringList &);
  // QDir::Filters filter() const;
  binder.fun<QDir::Filters, &QDir::filter>("filter").create();
  // void setFilter(QDir::Filters);
  binder.void_fun<QDir::Filters, &QDir::setFilter>("setFilter").create();
  // QDir::SortFlags sorting() const;
  binder.fun<QDir::SortFlags, &QDir::sorting>("sorting").create();
  // void setSorting(QDir::SortFlags);
  binder.void_fun<QDir::SortFlags, &QDir::setSorting>("setSorting").create();
  // uint count() const;
  binder.fun<uint, &QDir::count>("count").create();
  // bool isEmpty(QDir::Filters) const;
  binder.fun<bool, QDir::Filters, &QDir::isEmpty>("isEmpty")
    .apply(binding::default_arguments(QDir::Filters(QDir::AllEntries | QDir::NoDotAndDotDot))).create();
  // QString operator[](int) const;
  binder.operators().const_subscript<QString, int>();
  // static QStringList nameFiltersFromString(const QString &);
  /// TODO: static QStringList nameFiltersFromString(const QString &);
  // QStringList entryList(QDir::Filters, QDir::SortFlags) const;
  /// TODO: QStringList entryList(QDir::Filters, QDir::SortFlags) const;
  // QStringList entryList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  /// TODO: QStringList entryList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  // QFileInfoList entryInfoList(QDir::Filters, QDir::SortFlags) const;
  /// TODO: QFileInfoList entryInfoList(QDir::Filters, QDir::SortFlags) const;
  // QFileInfoList entryInfoList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  /// TODO: QFileInfoList entryInfoList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  // bool mkdir(const QString &) const;
  binder.fun<bool, const QString &, &QDir::mkdir>("mkdir").create();
  // bool rmdir(const QString &) const;
  binder.fun<bool, const QString &, &QDir::rmdir>("rmdir").create();
  // bool mkpath(const QString &) const;
  binder.fun<bool, const QString &, &QDir::mkpath>("mkpath").create();
  // bool rmpath(const QString &) const;
  binder.fun<bool, const QString &, &QDir::rmpath>("rmpath").create();
  // bool removeRecursively();
  binder.fun<bool, &QDir::removeRecursively>("removeRecursively").create();
  // bool isReadable() const;
  binder.fun<bool, &QDir::isReadable>("isReadable").create();
  // bool exists() const;
  binder.fun<bool, &QDir::exists>("exists").create();
  // bool isRoot() const;
  binder.fun<bool, &QDir::isRoot>("isRoot").create();
  // static bool isRelativePath(const QString &);
  binder.static_fun<bool, const QString &, &QDir::isRelativePath>("isRelativePath").create();
  // static bool isAbsolutePath(const QString &);
  binder.static_fun<bool, const QString &, &QDir::isAbsolutePath>("isAbsolutePath").create();
  // bool isRelative() const;
  binder.fun<bool, &QDir::isRelative>("isRelative").create();
  // bool isAbsolute() const;
  binder.fun<bool, &QDir::isAbsolute>("isAbsolute").create();
  // bool makeAbsolute();
  binder.fun<bool, &QDir::makeAbsolute>("makeAbsolute").create();
  // bool operator==(const QDir &) const;
  binder.operators().eq<const QDir &>();
  // bool operator!=(const QDir &) const;
  binder.operators().neq<const QDir &>();
  // bool remove(const QString &);
  binder.fun<bool, const QString &, &QDir::remove>("remove").create();
  // bool rename(const QString &, const QString &);
  binder.fun<bool, const QString &, const QString &, &QDir::rename>("rename").create();
  // bool exists(const QString &) const;
  binder.fun<bool, const QString &, &QDir::exists>("exists").create();
  // static QFileInfoList drives();
  /// TODO: static QFileInfoList drives();
  // static QChar listSeparator();
  binder.static_fun<QChar, &QDir::listSeparator>("listSeparator").create();
  // static QChar separator();
  binder.static_fun<QChar, &QDir::separator>("separator").create();
  // static bool setCurrent(const QString &);
  binder.static_fun<bool, const QString &, &QDir::setCurrent>("setCurrent").create();
  // static QDir current();
  binder.static_fun<QDir, &QDir::current>("current").create();
  // static QString currentPath();
  binder.static_fun<QString, &QDir::currentPath>("currentPath").create();
  // static QDir home();
  binder.static_fun<QDir, &QDir::home>("home").create();
  // static QString homePath();
  binder.static_fun<QString, &QDir::homePath>("homePath").create();
  // static QDir root();
  binder.static_fun<QDir, &QDir::root>("root").create();
  // static QString rootPath();
  binder.static_fun<QString, &QDir::rootPath>("rootPath").create();
  // static QDir temp();
  binder.static_fun<QDir, &QDir::temp>("temp").create();
  // static QString tempPath();
  binder.static_fun<QString, &QDir::tempPath>("tempPath").create();
  // static bool match(const QStringList &, const QString &);
  /// TODO: static bool match(const QStringList &, const QString &);
  // static bool match(const QString &, const QString &);
  binder.static_fun<bool, const QString &, const QString &, &QDir::match>("match").create();
  // static QString cleanPath(const QString &);
  binder.static_fun<QString, const QString &, &QDir::cleanPath>("cleanPath").create();
  // void refresh() const;
  binder.const_void_fun<&QDir::refresh>("refresh").create();
}


void register_dir_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_dir_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QDir &, QDir &);
  binder.void_fun<QDir &, QDir &, &swap>("swap").create();
  // QDir::Filters operator|(QDir::Filter, QDir::Filter);
  binder.operators().or<QDir::Filters, QDir::Filter, QDir::Filter>();
  // QDir::Filters operator|(QDir::Filter, QDir::Filters);
  binder.operators().or<QDir::Filters, QDir::Filter, QDir::Filters>();
  // QIncompatibleFlag operator|(QDir::Filters::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDir::Filters::enum_type, int);
  // QDir::SortFlags operator|(QDir::SortFlag, QDir::SortFlag);
  binder.operators().or<QDir::SortFlags, QDir::SortFlag, QDir::SortFlag>();
  // QDir::SortFlags operator|(QDir::SortFlag, QDir::SortFlags);
  binder.operators().or<QDir::SortFlags, QDir::SortFlag, QDir::SortFlags>();
  // QIncompatibleFlag operator|(QDir::SortFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDir::SortFlags::enum_type, int);
  // QDebug operator<<(QDebug, QDir::Filters);
  /// TODO: QDebug operator<<(QDebug, QDir::Filters);
  // QDebug operator<<(QDebug, const QDir &);
  /// TODO: QDebug operator<<(QDebug, const QDir &);
}

