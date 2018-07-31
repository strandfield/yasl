// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontdatabase.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/list.h"
#include "yasl/core/string.h"

#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_font_database_system_font_enum(script::Class font_database)
{
  using namespace script;

  Enum system_font = font_database.Enum("SystemFont").setId(script::Type::QFontDatabaseSystemFont).get();

  system_font.addValue("FixedFont", QFontDatabase::FixedFont);
  system_font.addValue("GeneralFont", QFontDatabase::GeneralFont);
  system_font.addValue("SmallestReadableFont", QFontDatabase::SmallestReadableFont);
  system_font.addValue("TitleFont", QFontDatabase::TitleFont);
}

static void register_font_database_writing_system_enum(script::Class font_database)
{
  using namespace script;

  Enum writing_system = font_database.Enum("WritingSystem").setId(script::Type::QFontDatabaseWritingSystem).get();

  writing_system.addValue("Any", QFontDatabase::Any);
  writing_system.addValue("Arabic", QFontDatabase::Arabic);
  writing_system.addValue("Armenian", QFontDatabase::Armenian);
  writing_system.addValue("Bengali", QFontDatabase::Bengali);
  writing_system.addValue("Cyrillic", QFontDatabase::Cyrillic);
  writing_system.addValue("Devanagari", QFontDatabase::Devanagari);
  writing_system.addValue("Georgian", QFontDatabase::Georgian);
  writing_system.addValue("Greek", QFontDatabase::Greek);
  writing_system.addValue("Gujarati", QFontDatabase::Gujarati);
  writing_system.addValue("Gurmukhi", QFontDatabase::Gurmukhi);
  writing_system.addValue("Hebrew", QFontDatabase::Hebrew);
  writing_system.addValue("Japanese", QFontDatabase::Japanese);
  writing_system.addValue("Kannada", QFontDatabase::Kannada);
  writing_system.addValue("Khmer", QFontDatabase::Khmer);
  writing_system.addValue("Korean", QFontDatabase::Korean);
  writing_system.addValue("Lao", QFontDatabase::Lao);
  writing_system.addValue("Latin", QFontDatabase::Latin);
  writing_system.addValue("Malayalam", QFontDatabase::Malayalam);
  writing_system.addValue("Myanmar", QFontDatabase::Myanmar);
  writing_system.addValue("Nko", QFontDatabase::Nko);
  writing_system.addValue("Ogham", QFontDatabase::Ogham);
  writing_system.addValue("Oriya", QFontDatabase::Oriya);
  writing_system.addValue("Other", QFontDatabase::Other);
  writing_system.addValue("Runic", QFontDatabase::Runic);
  writing_system.addValue("SimplifiedChinese", QFontDatabase::SimplifiedChinese);
  writing_system.addValue("Sinhala", QFontDatabase::Sinhala);
  writing_system.addValue("Symbol", QFontDatabase::Symbol);
  writing_system.addValue("Syriac", QFontDatabase::Syriac);
  writing_system.addValue("Tamil", QFontDatabase::Tamil);
  writing_system.addValue("Telugu", QFontDatabase::Telugu);
  writing_system.addValue("Thaana", QFontDatabase::Thaana);
  writing_system.addValue("Thai", QFontDatabase::Thai);
  writing_system.addValue("Tibetan", QFontDatabase::Tibetan);
  writing_system.addValue("TraditionalChinese", QFontDatabase::TraditionalChinese);
  writing_system.addValue("Vietnamese", QFontDatabase::Vietnamese);
  writing_system.addValue("WritingSystemsCount", QFontDatabase::WritingSystemsCount);
}

static void register_font_database_class(script::Namespace ns)
{
  using namespace script;

  Class font_database = ns.Class("FontDatabase").setId(script::Type::QFontDatabase).get();

  register_font_database_system_font_enum(font_database);
  register_font_database_writing_system_enum(font_database);
  binding::Class<QFontDatabase> binder{ font_database };

  // ~QFontDatabase();
  binder.add_dtor();
  // static QList<int> standardSizes();
  binder.add_static<QList<int>, &QFontDatabase::standardSizes>("standardSizes");
  // QFontDatabase();
  binder.ctors().add_default();
  // QList<QFontDatabase::WritingSystem> writingSystems() const;
  binder.add_fun<QList<QFontDatabase::WritingSystem>, &QFontDatabase::writingSystems>("writingSystems");
  // QList<QFontDatabase::WritingSystem> writingSystems(const QString &) const;
  binder.add_fun<QList<QFontDatabase::WritingSystem>, const QString &, &QFontDatabase::writingSystems>("writingSystems");
  // QStringList families(QFontDatabase::WritingSystem) const;
  binder.add_fun<QStringList, QFontDatabase::WritingSystem, &QFontDatabase::families>("families");
  // QStringList styles(const QString &) const;
  binder.add_fun<QStringList, const QString &, &QFontDatabase::styles>("styles");
  // QList<int> pointSizes(const QString &, const QString &);
  binder.add_fun<QList<int>, const QString &, const QString &, &QFontDatabase::pointSizes>("pointSizes");
  // QList<int> smoothSizes(const QString &, const QString &);
  binder.add_fun<QList<int>, const QString &, const QString &, &QFontDatabase::smoothSizes>("smoothSizes");
  // QString styleString(const QFont &);
  binder.add_fun<QString, const QFont &, &QFontDatabase::styleString>("styleString");
  // QString styleString(const QFontInfo &);
  binder.add_fun<QString, const QFontInfo &, &QFontDatabase::styleString>("styleString");
  // QFont font(const QString &, const QString &, int) const;
  binder.add_fun<QFont, const QString &, const QString &, int, &QFontDatabase::font>("font");
  // bool isBitmapScalable(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::isBitmapScalable>("isBitmapScalable");
  // bool isSmoothlyScalable(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::isSmoothlyScalable>("isSmoothlyScalable");
  // bool isScalable(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::isScalable>("isScalable");
  // bool isFixedPitch(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::isFixedPitch>("isFixedPitch");
  // bool italic(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::italic>("italic");
  // bool bold(const QString &, const QString &) const;
  binder.add_fun<bool, const QString &, const QString &, &QFontDatabase::bold>("bold");
  // int weight(const QString &, const QString &) const;
  binder.add_fun<int, const QString &, const QString &, &QFontDatabase::weight>("weight");
  // bool hasFamily(const QString &) const;
  binder.add_fun<bool, const QString &, &QFontDatabase::hasFamily>("hasFamily");
  // bool isPrivateFamily(const QString &) const;
  binder.add_fun<bool, const QString &, &QFontDatabase::isPrivateFamily>("isPrivateFamily");
  // static QString writingSystemName(QFontDatabase::WritingSystem);
  binder.add_static<QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemName>("writingSystemName");
  // static QString writingSystemSample(QFontDatabase::WritingSystem);
  binder.add_static<QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemSample>("writingSystemSample");
  // static int addApplicationFont(const QString &);
  binder.add_static<int, const QString &, &QFontDatabase::addApplicationFont>("addApplicationFont");
  // static int addApplicationFontFromData(const QByteArray &);
  binder.add_static<int, const QByteArray &, &QFontDatabase::addApplicationFontFromData>("addApplicationFontFromData");
  // static QStringList applicationFontFamilies(int);
  binder.add_static<QStringList, int, &QFontDatabase::applicationFontFamilies>("applicationFontFamilies");
  // static bool removeApplicationFont(int);
  binder.add_static<bool, int, &QFontDatabase::removeApplicationFont>("removeApplicationFont");
  // static bool removeAllApplicationFonts();
  binder.add_static<bool, &QFontDatabase::removeAllApplicationFonts>("removeAllApplicationFonts");
  // static bool supportsThreadedFontRendering();
  binder.add_static<bool, &QFontDatabase::supportsThreadedFontRendering>("supportsThreadedFontRendering");
  // static QFont systemFont(QFontDatabase::SystemFont);
  binder.add_static<QFont, QFontDatabase::SystemFont, &QFontDatabase::systemFont>("systemFont");
}

void register_fontdatabase_file(script::Namespace root)
{
  using namespace script;

  register_font_database_class(root);
  binding::Namespace binder{ root };

}

