// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/dir.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
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

  // QDir(const QDir &);
  bind::constructor<QDir, const QDir &>(dir).create();
  // QDir(const QString &);
  bind::constructor<QDir, const QString &>(dir)
    .apply(bind::default_arguments(QString())).create();
  // QDir(const QString &, const QString &, QDir::SortFlags, QDir::Filters);
  bind::constructor<QDir, const QString &, const QString &, QDir::SortFlags, QDir::Filters>(dir)
    .apply(bind::default_arguments(QDir::Filters(QDir::AllEntries), QDir::SortFlags(QDir::Name | QDir::IgnoreCase))).create();
  // ~QDir();
  bind::destructor<QDir>(dir).create();
  // QDir & operator=(const QDir &);
  bind::memop_assign<QDir, const QDir &>(dir);
  // QDir & operator=(const QString &);
  bind::memop_assign<QDir, const QString &>(dir);
  // QDir & operator=(QDir &&);
  bind::memop_assign<QDir, QDir &&>(dir);
  // void swap(QDir &);
  bind::void_member_function<QDir, QDir &, &QDir::swap>(dir, "swap").create();
  // void setPath(const QString &);
  bind::void_member_function<QDir, const QString &, &QDir::setPath>(dir, "setPath").create();
  // QString path() const;
  bind::member_function<QDir, QString, &QDir::path>(dir, "path").create();
  // QString absolutePath() const;
  bind::member_function<QDir, QString, &QDir::absolutePath>(dir, "absolutePath").create();
  // QString canonicalPath() const;
  bind::member_function<QDir, QString, &QDir::canonicalPath>(dir, "canonicalPath").create();
  // static void addResourceSearchPath(const QString &);
  bind::static_void_member_function<QDir, const QString &, &QDir::addResourceSearchPath>(dir, "addResourceSearchPath").create();
  // static void setSearchPaths(const QString &, const QStringList &);
  /// TODO: static void setSearchPaths(const QString &, const QStringList &);
  // static void addSearchPath(const QString &, const QString &);
  bind::static_void_member_function<QDir, const QString &, const QString &, &QDir::addSearchPath>(dir, "addSearchPath").create();
  // static QStringList searchPaths(const QString &);
  /// TODO: static QStringList searchPaths(const QString &);
  // QString dirName() const;
  bind::member_function<QDir, QString, &QDir::dirName>(dir, "dirName").create();
  // QString filePath(const QString &) const;
  bind::member_function<QDir, QString, const QString &, &QDir::filePath>(dir, "filePath").create();
  // QString absoluteFilePath(const QString &) const;
  bind::member_function<QDir, QString, const QString &, &QDir::absoluteFilePath>(dir, "absoluteFilePath").create();
  // QString relativeFilePath(const QString &) const;
  bind::member_function<QDir, QString, const QString &, &QDir::relativeFilePath>(dir, "relativeFilePath").create();
  // static QString toNativeSeparators(const QString &);
  bind::static_member_function<QDir, QString, const QString &, &QDir::toNativeSeparators>(dir, "toNativeSeparators").create();
  // static QString fromNativeSeparators(const QString &);
  bind::static_member_function<QDir, QString, const QString &, &QDir::fromNativeSeparators>(dir, "fromNativeSeparators").create();
  // bool cd(const QString &);
  bind::member_function<QDir, bool, const QString &, &QDir::cd>(dir, "cd").create();
  // bool cdUp();
  bind::member_function<QDir, bool, &QDir::cdUp>(dir, "cdUp").create();
  // QStringList nameFilters() const;
  /// TODO: QStringList nameFilters() const;
  // void setNameFilters(const QStringList &);
  /// TODO: void setNameFilters(const QStringList &);
  // QDir::Filters filter() const;
  bind::member_function<QDir, QDir::Filters, &QDir::filter>(dir, "filter").create();
  // void setFilter(QDir::Filters);
  bind::void_member_function<QDir, QDir::Filters, &QDir::setFilter>(dir, "setFilter").create();
  // QDir::SortFlags sorting() const;
  bind::member_function<QDir, QDir::SortFlags, &QDir::sorting>(dir, "sorting").create();
  // void setSorting(QDir::SortFlags);
  bind::void_member_function<QDir, QDir::SortFlags, &QDir::setSorting>(dir, "setSorting").create();
  // uint count() const;
  bind::member_function<QDir, uint, &QDir::count>(dir, "count").create();
  // bool isEmpty(QDir::Filters) const;
  bind::member_function<QDir, bool, QDir::Filters, &QDir::isEmpty>(dir, "isEmpty")
    .apply(bind::default_arguments(QDir::Filters(QDir::AllEntries | QDir::NoDotAndDotDot))).create();
  // QString operator[](int) const;
  bind::memop_const_subscript<QDir, QString, int>(dir);
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
  bind::member_function<QDir, bool, const QString &, &QDir::mkdir>(dir, "mkdir").create();
  // bool rmdir(const QString &) const;
  bind::member_function<QDir, bool, const QString &, &QDir::rmdir>(dir, "rmdir").create();
  // bool mkpath(const QString &) const;
  bind::member_function<QDir, bool, const QString &, &QDir::mkpath>(dir, "mkpath").create();
  // bool rmpath(const QString &) const;
  bind::member_function<QDir, bool, const QString &, &QDir::rmpath>(dir, "rmpath").create();
  // bool removeRecursively();
  bind::member_function<QDir, bool, &QDir::removeRecursively>(dir, "removeRecursively").create();
  // bool isReadable() const;
  bind::member_function<QDir, bool, &QDir::isReadable>(dir, "isReadable").create();
  // bool exists() const;
  bind::member_function<QDir, bool, &QDir::exists>(dir, "exists").create();
  // bool isRoot() const;
  bind::member_function<QDir, bool, &QDir::isRoot>(dir, "isRoot").create();
  // static bool isRelativePath(const QString &);
  bind::static_member_function<QDir, bool, const QString &, &QDir::isRelativePath>(dir, "isRelativePath").create();
  // static bool isAbsolutePath(const QString &);
  bind::static_member_function<QDir, bool, const QString &, &QDir::isAbsolutePath>(dir, "isAbsolutePath").create();
  // bool isRelative() const;
  bind::member_function<QDir, bool, &QDir::isRelative>(dir, "isRelative").create();
  // bool isAbsolute() const;
  bind::member_function<QDir, bool, &QDir::isAbsolute>(dir, "isAbsolute").create();
  // bool makeAbsolute();
  bind::member_function<QDir, bool, &QDir::makeAbsolute>(dir, "makeAbsolute").create();
  // bool operator==(const QDir &) const;
  bind::memop_eq<QDir, const QDir &>(dir);
  // bool operator!=(const QDir &) const;
  bind::memop_neq<QDir, const QDir &>(dir);
  // bool remove(const QString &);
  bind::member_function<QDir, bool, const QString &, &QDir::remove>(dir, "remove").create();
  // bool rename(const QString &, const QString &);
  bind::member_function<QDir, bool, const QString &, const QString &, &QDir::rename>(dir, "rename").create();
  // bool exists(const QString &) const;
  bind::member_function<QDir, bool, const QString &, &QDir::exists>(dir, "exists").create();
  // static QFileInfoList drives();
  /// TODO: static QFileInfoList drives();
  // static QChar listSeparator();
  bind::static_member_function<QDir, QChar, &QDir::listSeparator>(dir, "listSeparator").create();
  // static QChar separator();
  bind::static_member_function<QDir, QChar, &QDir::separator>(dir, "separator").create();
  // static bool setCurrent(const QString &);
  bind::static_member_function<QDir, bool, const QString &, &QDir::setCurrent>(dir, "setCurrent").create();
  // static QDir current();
  bind::static_member_function<QDir, QDir, &QDir::current>(dir, "current").create();
  // static QString currentPath();
  bind::static_member_function<QDir, QString, &QDir::currentPath>(dir, "currentPath").create();
  // static QDir home();
  bind::static_member_function<QDir, QDir, &QDir::home>(dir, "home").create();
  // static QString homePath();
  bind::static_member_function<QDir, QString, &QDir::homePath>(dir, "homePath").create();
  // static QDir root();
  bind::static_member_function<QDir, QDir, &QDir::root>(dir, "root").create();
  // static QString rootPath();
  bind::static_member_function<QDir, QString, &QDir::rootPath>(dir, "rootPath").create();
  // static QDir temp();
  bind::static_member_function<QDir, QDir, &QDir::temp>(dir, "temp").create();
  // static QString tempPath();
  bind::static_member_function<QDir, QString, &QDir::tempPath>(dir, "tempPath").create();
  // static bool match(const QStringList &, const QString &);
  /// TODO: static bool match(const QStringList &, const QString &);
  // static bool match(const QString &, const QString &);
  bind::static_member_function<QDir, bool, const QString &, const QString &, &QDir::match>(dir, "match").create();
  // static QString cleanPath(const QString &);
  bind::static_member_function<QDir, QString, const QString &, &QDir::cleanPath>(dir, "cleanPath").create();
  // void refresh() const;
  bind::const_void_member_function<QDir, &QDir::refresh>(dir, "refresh").create();
}


void register_dir_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_dir_class(ns);

  // void swap(QDir &, QDir &);
  bind::void_function<QDir &, QDir &, &swap>(ns, "swap").create();
  // QDir::Filters operator|(QDir::Filter, QDir::Filter);
  bind::op_bitor<QDir::Filters, QDir::Filter, QDir::Filter>(ns);
  // QDir::Filters operator|(QDir::Filter, QDir::Filters);
  bind::op_bitor<QDir::Filters, QDir::Filter, QDir::Filters>(ns);
  // QIncompatibleFlag operator|(QDir::Filters::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDir::Filters::enum_type, int);
  // QDir::SortFlags operator|(QDir::SortFlag, QDir::SortFlag);
  bind::op_bitor<QDir::SortFlags, QDir::SortFlag, QDir::SortFlag>(ns);
  // QDir::SortFlags operator|(QDir::SortFlag, QDir::SortFlags);
  bind::op_bitor<QDir::SortFlags, QDir::SortFlag, QDir::SortFlags>(ns);
  // QIncompatibleFlag operator|(QDir::SortFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDir::SortFlags::enum_type, int);
  // QDebug operator<<(QDebug, QDir::Filters);
  /// TODO: QDebug operator<<(QDebug, QDir::Filters);
  // QDebug operator<<(QDebug, const QDir &);
  /// TODO: QDebug operator<<(QDebug, const QDir &);
}

