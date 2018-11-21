// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/settings.h"

#include "yasl/binding/default_arguments.h"
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
  binding::ClassBinder<QSettings> binder{ settings, &QSettings::staticMetaObject };

  // QSettings(const QString &, const QString &, QObject *);
  binder.ctor<const QString &, const QString &, QObject *>()
    .apply(binding::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(QSettings::Scope, const QString &, const QString &, QObject *);
  binder.ctor<QSettings::Scope, const QString &, const QString &, QObject *>()
    .apply(binding::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *);
  binder.ctor<QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>()
    .apply(binding::default_arguments((QObject*)nullptr, QString())).create();
  // QSettings(const QString &, QSettings::Format, QObject *);
  binder.ctor<const QString &, QSettings::Format, QObject *>()
    .apply(binding::default_arguments((QObject*)nullptr)).create();
  // QSettings(QObject *);
  binder.ctor<QObject *>()
    .apply(binding::default_arguments((QObject*)nullptr)).create();
  // ~QSettings();
  binder.dtor().create();
  // void clear();
  binder.void_fun<&QSettings::clear>("clear").create();
  // void sync();
  binder.void_fun<&QSettings::sync>("sync").create();
  // QSettings::Status status() const;
  binder.fun<QSettings::Status, &QSettings::status>("status").create();
  // bool isAtomicSyncRequired() const;
  binder.fun<bool, &QSettings::isAtomicSyncRequired>("isAtomicSyncRequired").create();
  // void setAtomicSyncRequired(bool);
  binder.void_fun<bool, &QSettings::setAtomicSyncRequired>("setAtomicSyncRequired").create();
  // void beginGroup(const QString &);
  binder.void_fun<const QString &, &QSettings::beginGroup>("beginGroup").create();
  // void endGroup();
  binder.void_fun<&QSettings::endGroup>("endGroup").create();
  // QString group() const;
  binder.fun<QString, &QSettings::group>("group").create();
  // int beginReadArray(const QString &);
  binder.fun<int, const QString &, &QSettings::beginReadArray>("beginReadArray").create();
  // void beginWriteArray(const QString &, int);
  binder.void_fun<const QString &, int, &QSettings::beginWriteArray>("beginWriteArray")
    .apply(binding::default_arguments(-1)).create();
  // void endArray();
  binder.void_fun<&QSettings::endArray>("endArray").create();
  // void setArrayIndex(int);
  binder.void_fun<int, &QSettings::setArrayIndex>("setArrayIndex").create();
  // QStringList allKeys() const;
  /// TODO: QStringList allKeys() const;
  // QStringList childKeys() const;
  /// TODO: QStringList childKeys() const;
  // QStringList childGroups() const;
  /// TODO: QStringList childGroups() const;
  // bool isWritable() const;
  binder.fun<bool, &QSettings::isWritable>("isWritable").create();
  // void setValue(const QString &, const QVariant &);
  binder.void_fun<const QString &, const QVariant &, &QSettings::setValue>("setValue").create();
  // QVariant value(const QString &, const QVariant &) const;
  binder.fun<QVariant, const QString &, const QVariant &, &QSettings::value>("value")
    .apply(binding::default_arguments(QVariant())).create();
  // void remove(const QString &);
  binder.void_fun<const QString &, &QSettings::remove>("remove").create();
  // bool contains(const QString &) const;
  binder.fun<bool, const QString &, &QSettings::contains>("contains").create();
  // void setFallbacksEnabled(bool);
  binder.void_fun<bool, &QSettings::setFallbacksEnabled>("setFallbacksEnabled").create();
  // bool fallbacksEnabled() const;
  binder.fun<bool, &QSettings::fallbacksEnabled>("fallbacksEnabled").create();
  // QString fileName() const;
  binder.fun<QString, &QSettings::fileName>("fileName").create();
  // QSettings::Format format() const;
  binder.fun<QSettings::Format, &QSettings::format>("format").create();
  // QSettings::Scope scope() const;
  binder.fun<QSettings::Scope, &QSettings::scope>("scope").create();
  // QString organizationName() const;
  binder.fun<QString, &QSettings::organizationName>("organizationName").create();
  // QString applicationName() const;
  binder.fun<QString, &QSettings::applicationName>("applicationName").create();
  // void setIniCodec(QTextCodec *);
  /// TODO: void setIniCodec(QTextCodec *);
  // void setIniCodec(const char *);
  /// TODO: void setIniCodec(const char *);
  // QTextCodec * iniCodec() const;
  /// TODO: QTextCodec * iniCodec() const;
  // static void setDefaultFormat(QSettings::Format);
  binder.static_void_fun<QSettings::Format, &QSettings::setDefaultFormat>("setDefaultFormat").create();
  // static QSettings::Format defaultFormat();
  binder.static_fun<QSettings::Format, &QSettings::defaultFormat>("defaultFormat").create();
  // static void setSystemIniPath(const QString &);
  binder.static_void_fun<const QString &, &QSettings::setSystemIniPath>("setSystemIniPath").create();
  // static void setUserIniPath(const QString &);
  binder.static_void_fun<const QString &, &QSettings::setUserIniPath>("setUserIniPath").create();
  // static void setPath(QSettings::Format, QSettings::Scope, const QString &);
  binder.static_void_fun<QSettings::Format, QSettings::Scope, const QString &, &QSettings::setPath>("setPath").create();
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

