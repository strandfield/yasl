// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/settings.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/object.h"
#include "yasl/core/settings.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_settings_status_enum(script::Class settings)
{
  using namespace script;

  Enum status = settings.Enum("Status").setId(script::Type::QSettingsStatus).get();

  status.addValue("NoError", QSettings::NoError);
  status.addValue("AccessError", QSettings::AccessError);
  status.addValue("FormatError", QSettings::FormatError);
}


static void register_settings_format_enum(script::Class settings)
{
  using namespace script;

  Enum format = settings.Enum("Format").setId(script::Type::QSettingsFormat).get();

  format.addValue("NativeFormat", QSettings::NativeFormat);
  format.addValue("IniFormat", QSettings::IniFormat);
  format.addValue("Registry32Format", QSettings::Registry32Format);
  format.addValue("Registry64Format", QSettings::Registry64Format);
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

  Enum scope = settings.Enum("Scope").setId(script::Type::QSettingsScope).get();

  scope.addValue("UserScope", QSettings::UserScope);
  scope.addValue("SystemScope", QSettings::SystemScope);
}


static void register_settings_class(script::Namespace ns)
{
  using namespace script;

  Class settings = ns.Class("Settings").setId(script::Type::QSettings)
    .setBase(script::Type::QObject).get();

  register_settings_status_enum(settings);
  register_settings_format_enum(settings);
  register_settings_scope_enum(settings);
  binding::QClass<QSettings> binder{ settings, &QSettings::staticMetaObject };

  // QSettings(const QString &, const QString &, QObject *);
  binder.ctors().add<const QString &, const QString &, QObject *>();
  // QSettings(QSettings::Scope, const QString &, const QString &, QObject *);
  binder.ctors().add<QSettings::Scope, const QString &, const QString &, QObject *>();
  // QSettings(QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *);
  binder.ctors().add<QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>();
  // QSettings(const QString &, QSettings::Format, QObject *);
  binder.ctors().add<const QString &, QSettings::Format, QObject *>();
  // QSettings(QObject *);
  binder.ctors().add<QObject *>();
  // ~QSettings();
  binder.add_dtor();
  // void clear();
  binder.add_void_fun<&QSettings::clear>("clear");
  // void sync();
  binder.add_void_fun<&QSettings::sync>("sync");
  // QSettings::Status status() const;
  binder.add_fun<QSettings::Status, &QSettings::status>("status");
  // bool isAtomicSyncRequired() const;
  binder.add_fun<bool, &QSettings::isAtomicSyncRequired>("isAtomicSyncRequired");
  // void setAtomicSyncRequired(bool);
  binder.add_void_fun<bool, &QSettings::setAtomicSyncRequired>("setAtomicSyncRequired");
  // void beginGroup(const QString &);
  binder.add_void_fun<const QString &, &QSettings::beginGroup>("beginGroup");
  // void endGroup();
  binder.add_void_fun<&QSettings::endGroup>("endGroup");
  // QString group() const;
  binder.add_fun<QString, &QSettings::group>("group");
  // int beginReadArray(const QString &);
  binder.add_fun<int, const QString &, &QSettings::beginReadArray>("beginReadArray");
  // void beginWriteArray(const QString &, int);
  binder.add_void_fun<const QString &, int, &QSettings::beginWriteArray>("beginWriteArray");
  // void endArray();
  binder.add_void_fun<&QSettings::endArray>("endArray");
  // void setArrayIndex(int);
  binder.add_void_fun<int, &QSettings::setArrayIndex>("setArrayIndex");
  // QStringList allKeys() const;
  /// TODO: QStringList allKeys() const;
  // QStringList childKeys() const;
  /// TODO: QStringList childKeys() const;
  // QStringList childGroups() const;
  /// TODO: QStringList childGroups() const;
  // bool isWritable() const;
  binder.add_fun<bool, &QSettings::isWritable>("isWritable");
  // void setValue(const QString &, const QVariant &);
  binder.add_void_fun<const QString &, const QVariant &, &QSettings::setValue>("setValue");
  // QVariant value(const QString &, const QVariant &) const;
  binder.add_fun<QVariant, const QString &, const QVariant &, &QSettings::value>("value");
  // void remove(const QString &);
  binder.add_void_fun<const QString &, &QSettings::remove>("remove");
  // bool contains(const QString &) const;
  binder.add_fun<bool, const QString &, &QSettings::contains>("contains");
  // void setFallbacksEnabled(bool);
  binder.add_void_fun<bool, &QSettings::setFallbacksEnabled>("setFallbacksEnabled");
  // bool fallbacksEnabled() const;
  binder.add_fun<bool, &QSettings::fallbacksEnabled>("fallbacksEnabled");
  // QString fileName() const;
  binder.add_fun<QString, &QSettings::fileName>("fileName");
  // QSettings::Format format() const;
  binder.add_fun<QSettings::Format, &QSettings::format>("format");
  // QSettings::Scope scope() const;
  binder.add_fun<QSettings::Scope, &QSettings::scope>("scope");
  // QString organizationName() const;
  binder.add_fun<QString, &QSettings::organizationName>("organizationName");
  // QString applicationName() const;
  binder.add_fun<QString, &QSettings::applicationName>("applicationName");
  // void setIniCodec(QTextCodec *);
  /// TODO: void setIniCodec(QTextCodec *);
  // void setIniCodec(const char *);
  /// TODO: void setIniCodec(const char *);
  // QTextCodec * iniCodec() const;
  /// TODO: QTextCodec * iniCodec() const;
  // static void setDefaultFormat(QSettings::Format);
  binder.add_static_void_fun<QSettings::Format, &QSettings::setDefaultFormat>("setDefaultFormat");
  // static QSettings::Format defaultFormat();
  binder.add_static<QSettings::Format, &QSettings::defaultFormat>("defaultFormat");
  // static void setSystemIniPath(const QString &);
  binder.add_static_void_fun<const QString &, &QSettings::setSystemIniPath>("setSystemIniPath");
  // static void setUserIniPath(const QString &);
  binder.add_static_void_fun<const QString &, &QSettings::setUserIniPath>("setUserIniPath");
  // static void setPath(QSettings::Format, QSettings::Scope, const QString &);
  binder.add_static_void_fun<QSettings::Format, QSettings::Scope, const QString &, &QSettings::setPath>("setPath");
  // static QSettings::Format registerFormat(const QString &, QSettings::ReadFunc, QSettings::WriteFunc, Qt::CaseSensitivity);
  /// TODO: static QSettings::Format registerFormat(const QString &, QSettings::ReadFunc, QSettings::WriteFunc, Qt::CaseSensitivity);

  settings.engine()->registerQtType(&QSettings::staticMetaObject, settings.id());
}


void register_settings_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_settings_class(ns);
  binding::Namespace binder{ ns };

}

