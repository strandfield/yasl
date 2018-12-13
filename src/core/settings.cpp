// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/settings.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

#include "yasl/core/object.h"
#include "yasl/core/settings.h"
#include "yasl/core/string.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_settings_status_enum(script::Class settings)
{
  using namespace script;

  Enum status = settings.newEnum("Status").setId(script::Type::QSettingsStatus).get();

  status.addValue("NoError", QSettings::NoError);
  status.addValue("AccessError", QSettings::AccessError);
  status.addValue("FormatError", QSettings::FormatError);
}


static void register_settings_format_enum(script::Class settings)
{
  using namespace script;

  Enum format = settings.newEnum("Format").setId(script::Type::QSettingsFormat).get();

  format.addValue("NativeFormat", QSettings::NativeFormat);
  format.addValue("IniFormat", QSettings::IniFormat);
  format.addValue("InvalidFormat", QSettings::InvalidFormat);
  format.addValue("CustomFormat1", QSettings::CustomFormat1);
  format.addValue("CustomFormat2", QSettings::CustomFormat2);
  format.addValue("CustomFormat3", QSettings::CustomFormat3);
  format.addValue("CustomFormat4", QSettings::CustomFormat4);
  format.addValue("CustomFormat5", QSettings::CustomFormat5);
  format.addValue("CustomFormat6", QSettings::CustomFormat6);
  format.addValue("CustomFormat7", QSettings::CustomFormat7);
  format.addValue("CustomFormat8", QSettings::CustomFormat8);
  format.addValue("CustomFormat9", QSettings::CustomFormat9);
  format.addValue("CustomFormat10", QSettings::CustomFormat10);
  format.addValue("CustomFormat11", QSettings::CustomFormat11);
  format.addValue("CustomFormat12", QSettings::CustomFormat12);
  format.addValue("CustomFormat13", QSettings::CustomFormat13);
  format.addValue("CustomFormat14", QSettings::CustomFormat14);
  format.addValue("CustomFormat15", QSettings::CustomFormat15);
  format.addValue("CustomFormat16", QSettings::CustomFormat16);
}


static void register_settings_scope_enum(script::Class settings)
{
  using namespace script;

  Enum scope = settings.newEnum("Scope").setId(script::Type::QSettingsScope).get();

  scope.addValue("UserScope", QSettings::UserScope);
  scope.addValue("SystemScope", QSettings::SystemScope);
}


static void register_settings_class(script::Namespace ns)
{
  using namespace script;

  Class settings = ns.newClass("Settings").setId(script::Type::QSettings)
    .setBase(script::Type::QObject).get();

  register_settings_status_enum(settings);
  register_settings_format_enum(settings);
  register_settings_scope_enum(settings);

  // QSettings(const QString &, const QString & = QString(), QObject * = (QObject*)nullptr);
  bind::constructor<QSettings, const QString &, const QString &, QObject *>(settings)
    .apply(bind::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(QSettings::Scope, const QString &, const QString & = QString(), QObject * = (QObject*)nullptr);
  bind::constructor<QSettings, QSettings::Scope, const QString &, const QString &, QObject *>(settings)
    .apply(bind::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(QSettings::Format, QSettings::Scope, const QString &, const QString & = QString(), QObject * = (QObject*)nullptr);
  bind::constructor<QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>(settings)
    .apply(bind::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(const QString &, QSettings::Format, QObject * = (QObject*)nullptr);
  bind::constructor<QSettings, const QString &, QSettings::Format, QObject *>(settings)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QSettings(QObject * = (QObject*)nullptr);
  bind::constructor<QSettings, QObject *>(settings)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QSettings();
  bind::destructor<QSettings>(settings).create();
  // void clear();
  bind::void_member_function<QSettings, &QSettings::clear>(settings, "clear").create();
  // void sync();
  bind::void_member_function<QSettings, &QSettings::sync>(settings, "sync").create();
  // QSettings::Status status() const;
  bind::member_function<QSettings, QSettings::Status, &QSettings::status>(settings, "status").create();
  // void beginGroup(const QString &);
  bind::void_member_function<QSettings, const QString &, &QSettings::beginGroup>(settings, "beginGroup").create();
  // void endGroup();
  bind::void_member_function<QSettings, &QSettings::endGroup>(settings, "endGroup").create();
  // QString group() const;
  bind::member_function<QSettings, QString, &QSettings::group>(settings, "group").create();
  // int beginReadArray(const QString &);
  bind::member_function<QSettings, int, const QString &, &QSettings::beginReadArray>(settings, "beginReadArray").create();
  // void beginWriteArray(const QString &, int = -1);
  bind::void_member_function<QSettings, const QString &, int, &QSettings::beginWriteArray>(settings, "beginWriteArray")
    .apply(bind::default_arguments(-1)).create();
  // void endArray();
  bind::void_member_function<QSettings, &QSettings::endArray>(settings, "endArray").create();
  // void setArrayIndex(int);
  bind::void_member_function<QSettings, int, &QSettings::setArrayIndex>(settings, "setArrayIndex").create();
  // QStringList allKeys() const;
  bind::member_function<QSettings, QStringList, &QSettings::allKeys>(settings, "allKeys").create();
  // QStringList childKeys() const;
  bind::member_function<QSettings, QStringList, &QSettings::childKeys>(settings, "childKeys").create();
  // QStringList childGroups() const;
  bind::member_function<QSettings, QStringList, &QSettings::childGroups>(settings, "childGroups").create();
  // bool isWritable() const;
  bind::member_function<QSettings, bool, &QSettings::isWritable>(settings, "isWritable").create();
  // void setValue(const QString &, const QVariant &);
  bind::void_member_function<QSettings, const QString &, const QVariant &, &QSettings::setValue>(settings, "setValue").create();
  // QVariant value(const QString &, const QVariant & = QVariant()) const;
  bind::member_function<QSettings, QVariant, const QString &, const QVariant &, &QSettings::value>(settings, "value")
    .apply(bind::default_arguments(QVariant())).create();
  // void remove(const QString &);
  bind::void_member_function<QSettings, const QString &, &QSettings::remove>(settings, "remove").create();
  // bool contains(const QString &) const;
  bind::member_function<QSettings, bool, const QString &, &QSettings::contains>(settings, "contains").create();
  // void setFallbacksEnabled(bool);
  bind::void_member_function<QSettings, bool, &QSettings::setFallbacksEnabled>(settings, "setFallbacksEnabled").create();
  // bool fallbacksEnabled() const;
  bind::member_function<QSettings, bool, &QSettings::fallbacksEnabled>(settings, "fallbacksEnabled").create();
  // QString fileName() const;
  bind::member_function<QSettings, QString, &QSettings::fileName>(settings, "fileName").create();
  // QSettings::Format format() const;
  bind::member_function<QSettings, QSettings::Format, &QSettings::format>(settings, "format").create();
  // QSettings::Scope scope() const;
  bind::member_function<QSettings, QSettings::Scope, &QSettings::scope>(settings, "scope").create();
  // QString organizationName() const;
  bind::member_function<QSettings, QString, &QSettings::organizationName>(settings, "organizationName").create();
  // QString applicationName() const;
  bind::member_function<QSettings, QString, &QSettings::applicationName>(settings, "applicationName").create();
  // void setIniCodec(QTextCodec *);
  /// TODO: void setIniCodec(QTextCodec *);
  // void setIniCodec(const char *);
  /// TODO: void setIniCodec(const char *);
  // QTextCodec * iniCodec() const;
  /// TODO: QTextCodec * iniCodec() const;
  // static void setDefaultFormat(QSettings::Format);
  bind::static_void_member_function<QSettings, QSettings::Format, &QSettings::setDefaultFormat>(settings, "setDefaultFormat").create();
  // static QSettings::Format defaultFormat();
  bind::static_member_function<QSettings, QSettings::Format, &QSettings::defaultFormat>(settings, "defaultFormat").create();
  // static void setSystemIniPath(const QString &);
  bind::static_void_member_function<QSettings, const QString &, &QSettings::setSystemIniPath>(settings, "setSystemIniPath").create();
  // static void setUserIniPath(const QString &);
  bind::static_void_member_function<QSettings, const QString &, &QSettings::setUserIniPath>(settings, "setUserIniPath").create();
  // static void setPath(QSettings::Format, QSettings::Scope, const QString &);
  bind::static_void_member_function<QSettings, QSettings::Format, QSettings::Scope, const QString &, &QSettings::setPath>(settings, "setPath").create();
  // static QSettings::Format registerFormat(const QString &, QSettings::ReadFunc, QSettings::WriteFunc, Qt::CaseSensitivity);
  /// TODO: static QSettings::Format registerFormat(const QString &, QSettings::ReadFunc, QSettings::WriteFunc, Qt::CaseSensitivity);

  bind::link(settings, &QSettings::staticMetaObject);
}


void register_settings_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_settings_class(ns);

}
