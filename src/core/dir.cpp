// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/dir.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#include <QChar>
#include <QDebug>

static void register_dir_filter_enum(script::Class dir)
{
  using namespace script;

  Enum filter = dir.Enum("Filter").setId(script::Type::QDirFilter).get();

  filter.addValue("AccessMask", QDir::AccessMask);
  filter.addValue("AllDirs", QDir::AllDirs);
  filter.addValue("AllEntries", QDir::AllEntries);
  filter.addValue("CaseSensitive", QDir::CaseSensitive);
  filter.addValue("Dirs", QDir::Dirs);
  filter.addValue("Drives", QDir::Drives);
  filter.addValue("Executable", QDir::Executable);
  filter.addValue("Files", QDir::Files);
  filter.addValue("Hidden", QDir::Hidden);
  filter.addValue("Modified", QDir::Modified);
  filter.addValue("NoDot", QDir::NoDot);
  filter.addValue("NoDotAndDotDot", QDir::NoDotAndDotDot);
  filter.addValue("NoDotDot", QDir::NoDotDot);
  filter.addValue("NoFilter", QDir::NoFilter);
  filter.addValue("NoSymLinks", QDir::NoSymLinks);
  filter.addValue("PermissionMask", QDir::PermissionMask);
  filter.addValue("Readable", QDir::Readable);
  filter.addValue("System", QDir::System);
  filter.addValue("TypeMask", QDir::TypeMask);
  filter.addValue("Writable", QDir::Writable);

  register_qflags_type<QDir::Filter>(dir, "Filters", script::Type::QDirFilters);
}

static void register_dir_sort_flag_enum(script::Class dir)
{
  using namespace script;

  Enum sort_flag = dir.Enum("SortFlag").setId(script::Type::QDirSortFlag).get();

  sort_flag.addValue("DirsFirst", QDir::DirsFirst);
  sort_flag.addValue("DirsLast", QDir::DirsLast);
  sort_flag.addValue("IgnoreCase", QDir::IgnoreCase);
  sort_flag.addValue("LocaleAware", QDir::LocaleAware);
  sort_flag.addValue("Name", QDir::Name);
  sort_flag.addValue("NoSort", QDir::NoSort);
  sort_flag.addValue("Reversed", QDir::Reversed);
  sort_flag.addValue("Size", QDir::Size);
  sort_flag.addValue("SortByMask", QDir::SortByMask);
  sort_flag.addValue("Time", QDir::Time);
  sort_flag.addValue("Type", QDir::Type);
  sort_flag.addValue("Unsorted", QDir::Unsorted);
}

static void register_dir_class(script::Namespace ns)
{
  using namespace script;

  Class dir = ns.Class("Dir").setId(script::Type::QDir).get();

  register_dir_filter_enum(dir);
  register_dir_sort_flag_enum(dir);
  binding::Class<QDir> binder{ dir };

  // ~QDir();
  binder.add_dtor();
  // QDir(const QDir &);
  binder.ctors().add<const QDir &>();
  // QDir(const QString &);
  binder.ctors().add<const QString &>();
  // QDir(const QString &, const QString &, QDir::SortFlags, QDir::Filters);
  binder.ctors().add<const QString &, const QString &, QDir::SortFlags, QDir::Filters>();
  // QDir & operator=(const QDir &);
  binder.operators().assign<const QDir &>();
  // QDir & operator=(const QString &);
  binder.operators().assign<const QString &>();
  // QDir & operator=(QDir &&);
  /// TODO : binder.operators().assign<QDir &&>();
  // void swap(QDir &);
  binder.add_void_fun<QDir &, &QDir::swap>("swap");
  // void setPath(const QString &);
  binder.add_void_fun<const QString &, &QDir::setPath>("setPath");
  // QString path() const;
  binder.add_fun<QString, &QDir::path>("path");
  // QString absolutePath() const;
  binder.add_fun<QString, &QDir::absolutePath>("absolutePath");
  // QString canonicalPath() const;
  binder.add_fun<QString, &QDir::canonicalPath>("canonicalPath");
  // static void addResourceSearchPath(const QString &);
  binder.add_static_void_fun<const QString &, &QDir::addResourceSearchPath>("addResourceSearchPath");
  // static void setSearchPaths(const QString &, const QStringList &);
  binder.add_static_void_fun<const QString &, const QStringList &, &QDir::setSearchPaths>("setSearchPaths");
  // static void addSearchPath(const QString &, const QString &);
  binder.add_static_void_fun<const QString &, const QString &, &QDir::addSearchPath>("addSearchPath");
  // static QStringList searchPaths(const QString &);
  binder.add_static<QStringList, const QString &, &QDir::searchPaths>("searchPaths");
  // QString dirName() const;
  binder.add_fun<QString, &QDir::dirName>("dirName");
  // QString filePath(const QString &) const;
  binder.add_fun<QString, const QString &, &QDir::filePath>("filePath");
  // QString absoluteFilePath(const QString &) const;
  binder.add_fun<QString, const QString &, &QDir::absoluteFilePath>("absoluteFilePath");
  // QString relativeFilePath(const QString &) const;
  binder.add_fun<QString, const QString &, &QDir::relativeFilePath>("relativeFilePath");
  // static QString toNativeSeparators(const QString &);
  binder.add_static<QString, const QString &, &QDir::toNativeSeparators>("toNativeSeparators");
  // static QString fromNativeSeparators(const QString &);
  binder.add_static<QString, const QString &, &QDir::fromNativeSeparators>("fromNativeSeparators");
  // bool cd(const QString &);
  binder.add_fun<bool, const QString &, &QDir::cd>("cd");
  // bool cdUp();
  binder.add_fun<bool, &QDir::cdUp>("cdUp");
  // QStringList nameFilters() const;
  binder.add_fun<QStringList, &QDir::nameFilters>("nameFilters");
  // void setNameFilters(const QStringList &);
  binder.add_void_fun<const QStringList &, &QDir::setNameFilters>("setNameFilters");
  // QDir::Filters filter() const;
  binder.add_fun<QDir::Filters, &QDir::filter>("filter");
  // void setFilter(QDir::Filters);
  binder.add_void_fun<QDir::Filters, &QDir::setFilter>("setFilter");
  // QDir::SortFlags sorting() const;
  binder.add_fun<QDir::SortFlags, &QDir::sorting>("sorting");
  // void setSorting(QDir::SortFlags);
  binder.add_void_fun<QDir::SortFlags, &QDir::setSorting>("setSorting");
  // uint count() const;
  binder.add_fun<uint, &QDir::count>("count");
  // bool isEmpty(QDir::Filters) const;
  binder.add_fun<bool, QDir::Filters, &QDir::isEmpty>("isEmpty");
  // QString operator[](int) const;
  binder.operators().subscript<QString, int>();
  // static QStringList nameFiltersFromString(const QString &);
  binder.add_static<QStringList, const QString &, &QDir::nameFiltersFromString>("nameFiltersFromString");
  // QStringList entryList(QDir::Filters, QDir::SortFlags) const;
  binder.add_fun<QStringList, QDir::Filters, QDir::SortFlags, &QDir::entryList>("entryList");
  // QStringList entryList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  binder.add_fun<QStringList, const QStringList &, QDir::Filters, QDir::SortFlags, &QDir::entryList>("entryList");
  // QFileInfoList entryInfoList(QDir::Filters, QDir::SortFlags) const;
  binder.add_fun<QFileInfoList, QDir::Filters, QDir::SortFlags, &QDir::entryInfoList>("entryInfoList");
  // QFileInfoList entryInfoList(const QStringList &, QDir::Filters, QDir::SortFlags) const;
  binder.add_fun<QFileInfoList, const QStringList &, QDir::Filters, QDir::SortFlags, &QDir::entryInfoList>("entryInfoList");
  // bool mkdir(const QString &) const;
  binder.add_fun<bool, const QString &, &QDir::mkdir>("mkdir");
  // bool rmdir(const QString &) const;
  binder.add_fun<bool, const QString &, &QDir::rmdir>("rmdir");
  // bool mkpath(const QString &) const;
  binder.add_fun<bool, const QString &, &QDir::mkpath>("mkpath");
  // bool rmpath(const QString &) const;
  binder.add_fun<bool, const QString &, &QDir::rmpath>("rmpath");
  // bool removeRecursively();
  binder.add_fun<bool, &QDir::removeRecursively>("removeRecursively");
  // bool isReadable() const;
  binder.add_fun<bool, &QDir::isReadable>("isReadable");
  // bool exists() const;
  binder.add_fun<bool, &QDir::exists>("exists");
  // bool isRoot() const;
  binder.add_fun<bool, &QDir::isRoot>("isRoot");
  // static bool isRelativePath(const QString &);
  binder.add_static<bool, const QString &, &QDir::isRelativePath>("isRelativePath");
  // static bool isAbsolutePath(const QString &);
  binder.add_static<bool, const QString &, &QDir::isAbsolutePath>("isAbsolutePath");
  // bool isRelative() const;
  binder.add_fun<bool, &QDir::isRelative>("isRelative");
  // bool isAbsolute() const;
  binder.add_fun<bool, &QDir::isAbsolute>("isAbsolute");
  // bool makeAbsolute();
  binder.add_fun<bool, &QDir::makeAbsolute>("makeAbsolute");
  // bool operator==(const QDir &) const;
  binder.operators().eq<const QDir &>();
  // bool operator!=(const QDir &) const;
  binder.operators().neq<const QDir &>();
  // bool remove(const QString &);
  binder.add_fun<bool, const QString &, &QDir::remove>("remove");
  // bool rename(const QString &, const QString &);
  binder.add_fun<bool, const QString &, const QString &, &QDir::rename>("rename");
  // bool exists(const QString &) const;
  binder.add_fun<bool, const QString &, &QDir::exists>("exists");
  // static QFileInfoList drives();
  binder.add_static<QFileInfoList, &QDir::drives>("drives");
  // static QChar listSeparator();
  binder.add_static<QChar, &QDir::listSeparator>("listSeparator");
  // static QChar separator();
  binder.add_static<QChar, &QDir::separator>("separator");
  // static bool setCurrent(const QString &);
  binder.add_static<bool, const QString &, &QDir::setCurrent>("setCurrent");
  // static QDir current();
  binder.add_static<QDir, &QDir::current>("current");
  // static QString currentPath();
  binder.add_static<QString, &QDir::currentPath>("currentPath");
  // static QDir home();
  binder.add_static<QDir, &QDir::home>("home");
  // static QString homePath();
  binder.add_static<QString, &QDir::homePath>("homePath");
  // static QDir root();
  binder.add_static<QDir, &QDir::root>("root");
  // static QString rootPath();
  binder.add_static<QString, &QDir::rootPath>("rootPath");
  // static QDir temp();
  binder.add_static<QDir, &QDir::temp>("temp");
  // static QString tempPath();
  binder.add_static<QString, &QDir::tempPath>("tempPath");
  // static bool match(const QStringList &, const QString &);
  binder.add_static<bool, const QStringList &, const QString &, &QDir::match>("match");
  // static bool match(const QString &, const QString &);
  binder.add_static<bool, const QString &, const QString &, &QDir::match>("match");
  // static QString cleanPath(const QString &);
  binder.add_static<QString, const QString &, &QDir::cleanPath>("cleanPath");
  // void refresh() const;
  binder.add_void_fun<&QDir::refresh>("refresh");
}

void register_qdir_file(script::Namespace root)
{
  using namespace script;

  register_dir_class(root);
  binding::Namespace binder{ root };

  // void swap(QDir &, QDir &);
  binder.add_void_fun<QDir &, QDir &, &swap>("swap");
  // QFlags<QDir::Filters::enum_type> operator|(QDir::Filters::enum_type, QDir::Filters::enum_type);
  binder.operators().or<QFlags<QDir::Filters::enum_type>, QDir::Filters::enum_type, QDir::Filters::enum_type>();
  // QFlags<QDir::Filters::enum_type> operator|(QDir::Filters::enum_type, QFlags<QDir::Filters::enum_type>);
  binder.operators().or<QFlags<QDir::Filters::enum_type>, QDir::Filters::enum_type, QFlags<QDir::Filters::enum_type>>();
  // QIncompatibleFlag operator|(QDir::Filters::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QDir::Filters::enum_type, int>();
  // QFlags<QDir::SortFlags::enum_type> operator|(QDir::SortFlags::enum_type, QDir::SortFlags::enum_type);
  binder.operators().or<QFlags<QDir::SortFlags::enum_type>, QDir::SortFlags::enum_type, QDir::SortFlags::enum_type>();
  // QFlags<QDir::SortFlags::enum_type> operator|(QDir::SortFlags::enum_type, QFlags<QDir::SortFlags::enum_type>);
  binder.operators().or<QFlags<QDir::SortFlags::enum_type>, QDir::SortFlags::enum_type, QFlags<QDir::SortFlags::enum_type>>();
  // QIncompatibleFlag operator|(QDir::SortFlags::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QDir::SortFlags::enum_type, int>();
  // QDebug operator<<(QDebug, QDir::Filters);
  binder.operators().left_shift<QDebug, QDebug, QDir::Filters>();
  // QDebug operator<<(QDebug, const QDir &);
  binder.operators().left_shift<QDebug, QDebug, const QDir &>();
}

