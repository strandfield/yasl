// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontdatabase.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"

#include "yasl/core/bytearray.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontdatabase.h"
#include "yasl/gui/fontinfo.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_database_writing_system_enum(script::Class font_database)
{
  using namespace script;

  Enum writing_system = font_database.newEnum("WritingSystem").setId(script::Type::QFontDatabaseWritingSystem).get();

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


#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
static void register_font_database_system_font_enum(script::Class font_database)
{
  using namespace script;

  Enum system_font = font_database.newEnum("SystemFont").setId(script::Type::QFontDatabaseSystemFont).get();

  system_font.addValue("GeneralFont", QFontDatabase::GeneralFont);
  system_font.addValue("FixedFont", QFontDatabase::FixedFont);
  system_font.addValue("TitleFont", QFontDatabase::TitleFont);
  system_font.addValue("SmallestReadableFont", QFontDatabase::SmallestReadableFont);
}
#endif


static void register_font_database_class(script::Namespace ns)
{
  using namespace script;

  Class font_database = ns.newClass("FontDatabase").setId(script::Type::QFontDatabase).get();

  register_font_database_writing_system_enum(font_database);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  register_font_database_system_font_enum(font_database);
#endif

  // static QList<int> standardSizes();
  /// TODO: static QList<int> standardSizes();
  // QFontDatabase();
  bind::default_constructor<QFontDatabase>(font_database).create();
  // QList<QFontDatabase::WritingSystem> writingSystems() const;
  /// TODO: QList<QFontDatabase::WritingSystem> writingSystems() const;
  // QList<QFontDatabase::WritingSystem> writingSystems(const QString &) const;
  /// TODO: QList<QFontDatabase::WritingSystem> writingSystems(const QString &) const;
  // QStringList families(QFontDatabase::WritingSystem = QFontDatabase::Any) const;
  /// TODO: QStringList families(QFontDatabase::WritingSystem = QFontDatabase::Any) const;
  // QStringList styles(const QString &) const;
  /// TODO: QStringList styles(const QString &) const;
  // QList<int> pointSizes(const QString &, const QString & = QString());
  /// TODO: QList<int> pointSizes(const QString &, const QString & = QString());
  // QList<int> smoothSizes(const QString &, const QString &);
  /// TODO: QList<int> smoothSizes(const QString &, const QString &);
  // QString styleString(const QFont &);
  bind::member_function<QFontDatabase, QString, const QFont &, &QFontDatabase::styleString>(font_database, "styleString").create();
  // QString styleString(const QFontInfo &);
  bind::member_function<QFontDatabase, QString, const QFontInfo &, &QFontDatabase::styleString>(font_database, "styleString").create();
  // QFont font(const QString &, const QString &, int) const;
  bind::member_function<QFontDatabase, QFont, const QString &, const QString &, int, &QFontDatabase::font>(font_database, "font").create();
  // bool isBitmapScalable(const QString &, const QString & = QString()) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::isBitmapScalable>(font_database, "isBitmapScalable")
    .apply(bind::default_arguments(QString())).create();
  // bool isSmoothlyScalable(const QString &, const QString & = QString()) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::isSmoothlyScalable>(font_database, "isSmoothlyScalable")
    .apply(bind::default_arguments(QString())).create();
  // bool isScalable(const QString &, const QString & = QString()) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::isScalable>(font_database, "isScalable")
    .apply(bind::default_arguments(QString())).create();
  // bool isFixedPitch(const QString &, const QString & = QString()) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::isFixedPitch>(font_database, "isFixedPitch")
    .apply(bind::default_arguments(QString())).create();
  // bool italic(const QString &, const QString &) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::italic>(font_database, "italic").create();
  // bool bold(const QString &, const QString &) const;
  bind::member_function<QFontDatabase, bool, const QString &, const QString &, &QFontDatabase::bold>(font_database, "bold").create();
  // int weight(const QString &, const QString &) const;
  bind::member_function<QFontDatabase, int, const QString &, const QString &, &QFontDatabase::weight>(font_database, "weight").create();
  // bool hasFamily(const QString &) const;
  bind::member_function<QFontDatabase, bool, const QString &, &QFontDatabase::hasFamily>(font_database, "hasFamily").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // bool isPrivateFamily(const QString &) const;
  bind::member_function<QFontDatabase, bool, const QString &, &QFontDatabase::isPrivateFamily>(font_database, "isPrivateFamily").create();
#endif
  // static QString writingSystemName(QFontDatabase::WritingSystem);
  bind::static_member_function<QFontDatabase, QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemName>(font_database, "writingSystemName").create();
  // static QString writingSystemSample(QFontDatabase::WritingSystem);
  bind::static_member_function<QFontDatabase, QString, QFontDatabase::WritingSystem, &QFontDatabase::writingSystemSample>(font_database, "writingSystemSample").create();
  // static int addApplicationFont(const QString &);
  bind::static_member_function<QFontDatabase, int, const QString &, &QFontDatabase::addApplicationFont>(font_database, "addApplicationFont").create();
  // static int addApplicationFontFromData(const QByteArray &);
  bind::static_member_function<QFontDatabase, int, const QByteArray &, &QFontDatabase::addApplicationFontFromData>(font_database, "addApplicationFontFromData").create();
  // static QStringList applicationFontFamilies(int);
  /// TODO: static QStringList applicationFontFamilies(int);
  // static bool removeApplicationFont(int);
  bind::static_member_function<QFontDatabase, bool, int, &QFontDatabase::removeApplicationFont>(font_database, "removeApplicationFont").create();
  // static bool removeAllApplicationFonts();
  bind::static_member_function<QFontDatabase, bool, &QFontDatabase::removeAllApplicationFonts>(font_database, "removeAllApplicationFonts").create();
  // static bool supportsThreadedFontRendering();
  bind::static_member_function<QFontDatabase, bool, &QFontDatabase::supportsThreadedFontRendering>(font_database, "supportsThreadedFontRendering").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QFont systemFont(QFontDatabase::SystemFont);
  bind::static_member_function<QFontDatabase, QFont, QFontDatabase::SystemFont, &QFontDatabase::systemFont>(font_database, "systemFont").create();
#endif
}


void register_fontdatabase_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_database_class(ns);

}
