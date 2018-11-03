// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontdatabase.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontdatabase.h"
#include "yasl/gui/fontinfo.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_database_writing_system_enum(script::Class font_database)
{
  using namespace script;

  Enum writing_system = font_database.Enum("WritingSystem").setId(script::Type::QFontDatabaseWritingSystem).get();

  writing_system.addValue("Any", QFontDatabase::Any);
  writing_system.addValue("Latin", QFontDatabase::Latin);
  writing_system.addValue("Greek", QFontDatabase::Greek);
  writing_system.addValue("Cyrillic", QFontDatabase::Cyrillic);
  writing_system.addValue("Armenian", QFontDatabase::Armenian);
  writing_system.addValue("Hebrew", QFontDatabase::Hebrew);
  writing_system.addValue("Arabic", QFontDatabase::Arabic);
  writing_system.addValue("Syriac", QFontDatabase::Syriac);
  writing_system.addValue("Thaana", QFontDatabase::Thaana);
  writing_system.addValue("Devanagari", QFontDatabase::Devanagari);
  writing_system.addValue("Bengali", QFontDatabase::Bengali);
  writing_system.addValue("Gurmukhi", QFontDatabase::Gurmukhi);
  writing_system.addValue("Gujarati", QFontDatabase::Gujarati);
  writing_system.addValue("Oriya", QFontDatabase::Oriya);
  writing_system.addValue("Tamil", QFontDatabase::Tamil);
  writing_system.addValue("Telugu", QFontDatabase::Telugu);
  writing_system.addValue("Kannada", QFontDatabase::Kannada);
  writing_system.addValue("Malayalam", QFontDatabase::Malayalam);
  writing_system.addValue("Sinhala", QFontDatabase::Sinhala);
  writing_system.addValue("Thai", QFontDatabase::Thai);
  writing_system.addValue("Lao", QFontDatabase::Lao);
  writing_system.addValue("Tibetan", QFontDatabase::Tibetan);
  writing_system.addValue("Myanmar", QFontDatabase::Myanmar);
  writing_system.addValue("Georgian", QFontDatabase::Georgian);
  writing_system.addValue("Khmer", QFontDatabase::Khmer);
  writing_system.addValue("SimplifiedChinese", QFontDatabase::SimplifiedChinese);
  writing_system.addValue("TraditionalChinese", QFontDatabase::TraditionalChinese);
  writing_system.addValue("Japanese", QFontDatabase::Japanese);
  writing_system.addValue("Korean", QFontDatabase::Korean);
  writing_system.addValue("Vietnamese", QFontDatabase::Vietnamese);
  writing_system.addValue("Symbol", QFontDatabase::Symbol);
  writing_system.addValue("Other", QFontDatabase::Other);
  writing_system.addValue("Ogham", QFontDatabase::Ogham);
  writing_system.addValue("Runic", QFontDatabase::Runic);
  writing_system.addValue("Nko", QFontDatabase::Nko);
  writing_system.addValue("WritingSystemsCount", QFontDatabase::WritingSystemsCount);
}


static void register_font_database_system_font_enum(script::Class font_database)
{
  using namespace script;

  Enum system_font = font_database.Enum("SystemFont").setId(script::Type::QFontDatabaseSystemFont).get();

  system_font.addValue("GeneralFont", QFontDatabase::GeneralFont);
  system_font.addValue("FixedFont", QFontDatabase::FixedFont);
  system_font.addValue("TitleFont", QFontDatabase::TitleFont);
  system_font.addValue("SmallestReadableFont", QFontDatabase::SmallestReadableFont);
}


static void register_font_database_class(script::Namespace ns)
{
  using namespace script;

  Class font_database = ns.Class("FontDatabase").setId(script::Type::QFontDatabase).get();

  register_font_database_writing_system_enum(font_database);
  register_font_database_system_font_enum(font_database);
  binding::ClassBinder<QFontDatabase> binder{ font_database };

  // static QList<int> standardSizes();
  /// TODO: static QList<int> standardSizes();
  // QFontDatabase();
  binder.default_ctor().create();
  // QList<QFontDatabase::WritingSystem> writingSystems() const;
  /// TODO: QList<QFontDatabase::WritingSystem> writingSystems() const;
  // QList<QFontDatabase::WritingSystem> writingSystems(const QString &) const;
  /// TODO: QList<QFontDatabase::WritingSystem> writingSystems(const QString &) const;
  // QStringList families(QFontDatabase::WritingSystem) const;
  /// TODO: QStringList families(QFontDatabase::WritingSystem) const;
  // QStringList styles(const QString &) const;
  /// TODO: QStringList styles(const QString &) const;
  // QList<int> pointSizes(const QString &, const QString &);
  /// TODO: QList<int> pointSizes(const QString &, const QString &);
  // QList<int> smoothSizes(const QString &, const QString &);
  /// TODO: QList<int> smoothSizes(const QString &, const QString &);
  // QString styleString(const QFont &);
  binder.fun<QString, const QFont &, &QFontDatabase::styleString>("styleString").create();
  // QString styleString(const QFontInfo &);
  binder.fun<QString, const QFontInfo &, &QFontDatabase::styleString>("styleString").create();
  // QFont font(const QString &, const QString &, int) const;
  binder.fun<QFont, const QString &, const QString &, int, &QFontDatabase::font>("font").create();
  // bool isBitmapScalable(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::isBitmapScalable>("isBitmapScalable")
    .apply(binding::default_arguments(QString())).create();
  // bool isSmoothlyScalable(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::isSmoothlyScalable>("isSmoothlyScalable")
    .apply(binding::default_arguments(QString())).create();
  // bool isScalable(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::isScalable>("isScalable")
    .apply(binding::default_arguments(QString())).create();
  // bool isFixedPitch(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::isFixedPitch>("isFixedPitch")
    .apply(binding::default_arguments(QString())).create();
  // bool italic(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::italic>("italic").create();
  // bool bold(const QString &, const QString &) const;
  binder.fun<bool, const QString &, const QString &, &QFontDatabase::bold>("bold").create();
  // int weight(const QString &, const QString &) const;
  binder.fun<int, const QString &, const QString &, &QFontDatabase::weight>("weight").create();
  // bool hasFamily(const QString &) const;
  binder.fun<bool, const QString &, &QFontDatabase::hasFamily>("hasFamily").create();
  // bool isPrivateFamily(const QString &) const;
  binder.fun<bool, const QString &, &QFontDatabase::isPrivateFamily>("isPrivateFamily").create();
  // static QString writingSystemName(QFontDatabase::WritingSystem);
  binder.static_fun<QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemName>("writingSystemName").create();
  // static QString writingSystemSample(QFontDatabase::WritingSystem);
  binder.static_fun<QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemSample>("writingSystemSample").create();
  // static int addApplicationFont(const QString &);
  binder.static_fun<int, const QString &, &QFontDatabase::addApplicationFont>("addApplicationFont").create();
  // static int addApplicationFontFromData(const QByteArray &);
  binder.static_fun<int, const QByteArray &, &QFontDatabase::addApplicationFontFromData>("addApplicationFontFromData").create();
  // static QStringList applicationFontFamilies(int);
  /// TODO: static QStringList applicationFontFamilies(int);
  // static bool removeApplicationFont(int);
  binder.static_fun<bool, int, &QFontDatabase::removeApplicationFont>("removeApplicationFont").create();
  // static bool removeAllApplicationFonts();
  binder.static_fun<bool, &QFontDatabase::removeAllApplicationFonts>("removeAllApplicationFonts").create();
  // static bool supportsThreadedFontRendering();
  binder.static_fun<bool, &QFontDatabase::supportsThreadedFontRendering>("supportsThreadedFontRendering").create();
  // static QFont systemFont(QFontDatabase::SystemFont);
  binder.static_fun<QFont, QFontDatabase::SystemFont, &QFontDatabase::systemFont>("systemFont").create();
}


void register_fontdatabase_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_database_class(ns);
  binding::Namespace binder{ ns };

}

