// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/url.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/url.h"
#include "yasl/core/urlquery.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_url_parsing_mode_enum(script::Class url)
{
  using namespace script;

  Enum parsing_mode = url.Enum("ParsingMode").setId(script::Type::QUrlParsingMode).get();

  parsing_mode.addValue("TolerantMode", QUrl::TolerantMode);
  parsing_mode.addValue("StrictMode", QUrl::StrictMode);
  parsing_mode.addValue("DecodedMode", QUrl::DecodedMode);
}


static void register_url_url_formatting_option_enum(script::Class url)
{
  using namespace script;

  Enum url_formatting_option = url.Enum("UrlFormattingOption").setId(script::Type::QUrlUrlFormattingOption).get();

  url_formatting_option.addValue("None", QUrl::None);
  url_formatting_option.addValue("RemoveScheme", QUrl::RemoveScheme);
  url_formatting_option.addValue("RemovePassword", QUrl::RemovePassword);
  url_formatting_option.addValue("RemoveUserInfo", QUrl::RemoveUserInfo);
  url_formatting_option.addValue("RemovePort", QUrl::RemovePort);
  url_formatting_option.addValue("RemoveAuthority", QUrl::RemoveAuthority);
  url_formatting_option.addValue("RemovePath", QUrl::RemovePath);
  url_formatting_option.addValue("RemoveQuery", QUrl::RemoveQuery);
  url_formatting_option.addValue("RemoveFragment", QUrl::RemoveFragment);
  url_formatting_option.addValue("PreferLocalFile", QUrl::PreferLocalFile);
  url_formatting_option.addValue("StripTrailingSlash", QUrl::StripTrailingSlash);
  url_formatting_option.addValue("RemoveFilename", QUrl::RemoveFilename);
  url_formatting_option.addValue("NormalizePathSegments", QUrl::NormalizePathSegments);
}


static void register_url_component_formatting_option_enum(script::Class url)
{
  using namespace script;

  Enum component_formatting_option = url.Enum("ComponentFormattingOption").setId(script::Type::QUrlComponentFormattingOption).get();

  register_qflags_type<QUrl::ComponentFormattingOption>(url, "ComponentFormattingOptions", script::Type::QUrlComponentFormattingOptions);
  component_formatting_option.addValue("PrettyDecoded", QUrl::PrettyDecoded);
  component_formatting_option.addValue("EncodeSpaces", QUrl::EncodeSpaces);
  component_formatting_option.addValue("EncodeUnicode", QUrl::EncodeUnicode);
  component_formatting_option.addValue("EncodeDelimiters", QUrl::EncodeDelimiters);
  component_formatting_option.addValue("EncodeReserved", QUrl::EncodeReserved);
  component_formatting_option.addValue("DecodeReserved", QUrl::DecodeReserved);
  component_formatting_option.addValue("FullyEncoded", QUrl::FullyEncoded);
  component_formatting_option.addValue("FullyDecoded", QUrl::FullyDecoded);
}


static void register_url_user_input_resolution_option_enum(script::Class url)
{
  using namespace script;

  Enum user_input_resolution_option = url.Enum("UserInputResolutionOption").setId(script::Type::QUrlUserInputResolutionOption).get();

  register_qflags_type<QUrl::UserInputResolutionOption>(url, "UserInputResolutionOptions", script::Type::QUrlUserInputResolutionOptions);
  user_input_resolution_option.addValue("DefaultResolution", QUrl::DefaultResolution);
  user_input_resolution_option.addValue("AssumeLocalFile", QUrl::AssumeLocalFile);
}


static void register_url_class(script::Namespace ns)
{
  using namespace script;

  Class url = ns.Class("Url").setId(script::Type::QUrl).get();

  register_url_parsing_mode_enum(url);
  register_url_url_formatting_option_enum(url);
  register_url_component_formatting_option_enum(url);
  register_url_user_input_resolution_option_enum(url);
  binding::Class<QUrl> binder{ url };

  // QUrl();
  binder.ctors().add_default();
  // QUrl(const QUrl &);
  binder.ctors().ctor<const QUrl &>().create();
  // QUrl & operator=(const QUrl &);
  binder.operators().assign<const QUrl &>();
  // QUrl(const QString &, QUrl::ParsingMode);
  binder.ctors().ctor<const QString &, QUrl::ParsingMode>().create();
  // QUrl & operator=(const QString &);
  binder.operators().assign<const QString &>();
  // QUrl(QUrl &&);
  binder.ctors().ctor<QUrl &&>().create();
  // QUrl & operator=(QUrl &&);
  binder.operators().assign<QUrl &&>();
  // ~QUrl();
  binder.add_dtor();
  // void swap(QUrl &);
  binder.void_fun<QUrl &, &QUrl::swap>("swap").create();
  // void setUrl(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUrl>("setUrl").create();
  // QString url(QUrl::FormattingOptions) const;
  /// TODO: QString url(QUrl::FormattingOptions) const;
  // QString toString(QUrl::FormattingOptions) const;
  /// TODO: QString toString(QUrl::FormattingOptions) const;
  // QString toDisplayString(QUrl::FormattingOptions) const;
  /// TODO: QString toDisplayString(QUrl::FormattingOptions) const;
  // QUrl adjusted(QUrl::FormattingOptions) const;
  /// TODO: QUrl adjusted(QUrl::FormattingOptions) const;
  // QByteArray toEncoded(QUrl::FormattingOptions) const;
  /// TODO: QByteArray toEncoded(QUrl::FormattingOptions) const;
  // static QUrl fromEncoded(const QByteArray &, QUrl::ParsingMode);
  binder.static_fun<QUrl, const QByteArray &, QUrl::ParsingMode, &QUrl::fromEncoded>("fromEncoded").create();
  // static QUrl fromUserInput(const QString &);
  binder.static_fun<QUrl, const QString &, &QUrl::fromUserInput>("fromUserInput").create();
  // static QUrl fromUserInput(const QString &, const QString &, QUrl::UserInputResolutionOptions);
  binder.static_fun<QUrl, const QString &, const QString &, QUrl::UserInputResolutionOptions, &QUrl::fromUserInput>("fromUserInput").create();
  // bool isValid() const;
  binder.fun<bool, &QUrl::isValid>("isValid").create();
  // QString errorString() const;
  binder.fun<QString, &QUrl::errorString>("errorString").create();
  // bool isEmpty() const;
  binder.fun<bool, &QUrl::isEmpty>("isEmpty").create();
  // void clear();
  binder.void_fun<&QUrl::clear>("clear").create();
  // void setScheme(const QString &);
  binder.void_fun<const QString &, &QUrl::setScheme>("setScheme").create();
  // QString scheme() const;
  binder.fun<QString, &QUrl::scheme>("scheme").create();
  // void setAuthority(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setAuthority>("setAuthority").create();
  // QString authority(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::authority>("authority").create();
  // void setUserInfo(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUserInfo>("setUserInfo").create();
  // QString userInfo(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::userInfo>("userInfo").create();
  // void setUserName(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUserName>("setUserName").create();
  // QString userName(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::userName>("userName").create();
  // void setPassword(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setPassword>("setPassword").create();
  // QString password(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::password>("password").create();
  // void setHost(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setHost>("setHost").create();
  // QString host(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::host>("host").create();
  // QString topLevelDomain(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::topLevelDomain>("topLevelDomain").create();
  // void setPort(int);
  binder.void_fun<int, &QUrl::setPort>("setPort").create();
  // int port(int) const;
  binder.fun<int, int, &QUrl::port>("port").create();
  // void setPath(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setPath>("setPath").create();
  // QString path(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::path>("path").create();
  // QString fileName(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::fileName>("fileName").create();
  // bool hasQuery() const;
  binder.fun<bool, &QUrl::hasQuery>("hasQuery").create();
  // void setQuery(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setQuery>("setQuery").create();
  // void setQuery(const QUrlQuery &);
  binder.void_fun<const QUrlQuery &, &QUrl::setQuery>("setQuery").create();
  // QString query(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::query>("query").create();
  // bool hasFragment() const;
  binder.fun<bool, &QUrl::hasFragment>("hasFragment").create();
  // QString fragment(QUrl::ComponentFormattingOptions) const;
  binder.fun<QString, QUrl::ComponentFormattingOptions, &QUrl::fragment>("fragment").create();
  // void setFragment(const QString &, QUrl::ParsingMode);
  binder.void_fun<const QString &, QUrl::ParsingMode, &QUrl::setFragment>("setFragment").create();
  // QUrl resolved(const QUrl &) const;
  binder.fun<QUrl, const QUrl &, &QUrl::resolved>("resolved").create();
  // bool isRelative() const;
  binder.fun<bool, &QUrl::isRelative>("isRelative").create();
  // bool isParentOf(const QUrl &) const;
  binder.fun<bool, const QUrl &, &QUrl::isParentOf>("isParentOf").create();
  // bool isLocalFile() const;
  binder.fun<bool, &QUrl::isLocalFile>("isLocalFile").create();
  // static QUrl fromLocalFile(const QString &);
  binder.static_fun<QUrl, const QString &, &QUrl::fromLocalFile>("fromLocalFile").create();
  // QString toLocalFile() const;
  binder.fun<QString, &QUrl::toLocalFile>("toLocalFile").create();
  // void detach();
  binder.void_fun<&QUrl::detach>("detach").create();
  // bool isDetached() const;
  binder.fun<bool, &QUrl::isDetached>("isDetached").create();
  // bool operator<(const QUrl &) const;
  binder.operators().less<const QUrl &>();
  // bool operator==(const QUrl &) const;
  binder.operators().eq<const QUrl &>();
  // bool operator!=(const QUrl &) const;
  binder.operators().neq<const QUrl &>();
  // bool matches(const QUrl &, QUrl::FormattingOptions) const;
  /// TODO: bool matches(const QUrl &, QUrl::FormattingOptions) const;
  // static QString fromPercentEncoding(const QByteArray &);
  binder.static_fun<QString, const QByteArray &, &QUrl::fromPercentEncoding>("fromPercentEncoding").create();
  // static QByteArray toPercentEncoding(const QString &, const QByteArray &, const QByteArray &);
  binder.static_fun<QByteArray, const QString &, const QByteArray &, const QByteArray &, &QUrl::toPercentEncoding>("toPercentEncoding").create();
  // static QString fromAce(const QByteArray &);
  binder.static_fun<QString, const QByteArray &, &QUrl::fromAce>("fromAce").create();
  // static QByteArray toAce(const QString &);
  binder.static_fun<QByteArray, const QString &, &QUrl::toAce>("toAce").create();
  // static QStringList idnWhitelist();
  /// TODO: static QStringList idnWhitelist();
  // static QStringList toStringList(const QList<QUrl> &, QUrl::FormattingOptions);
  /// TODO: static QStringList toStringList(const QList<QUrl> &, QUrl::FormattingOptions);
  // static QList<QUrl> fromStringList(const QStringList &, QUrl::ParsingMode);
  /// TODO: static QList<QUrl> fromStringList(const QStringList &, QUrl::ParsingMode);
  // static void setIdnWhitelist(const QStringList &);
  /// TODO: static void setIdnWhitelist(const QStringList &);
  // QUrl::DataPtr & data_ptr();
  /// TODO: QUrl::DataPtr & data_ptr();
}


void register_url_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_url_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QUrl &, uint);
  binder.fun<uint, const QUrl &, uint, &qHash>("qHash").create();
  // void swap(QUrl &, QUrl &);
  binder.void_fun<QUrl &, QUrl &, &swap>("swap").create();
  // QUrl::ComponentFormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOption);
  binder.operators().or<QUrl::ComponentFormattingOptions, QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOption>();
  // QUrl::ComponentFormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOptions);
  binder.operators().or<QUrl::ComponentFormattingOptions, QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOptions>();
  // QIncompatibleFlag operator|(QUrl::ComponentFormattingOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QUrl::ComponentFormattingOptions::enum_type, int);
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::UrlFormattingOption);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::UrlFormattingOption);
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::FormattingOptions);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::FormattingOptions);
  // QIncompatibleFlag operator|(QUrl::UrlFormattingOption, int);
  /// TODO: QIncompatibleFlag operator|(QUrl::UrlFormattingOption, int);
  // QUrl::FormattingOptions & operator|=(QUrl::FormattingOptions &, QUrl::ComponentFormattingOptions);
  /// TODO: QUrl::FormattingOptions & operator|=(QUrl::FormattingOptions &, QUrl::ComponentFormattingOptions);
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOption);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOption);
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOptions);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOptions);
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::UrlFormattingOption);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::UrlFormattingOption);
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::UrlFormattingOption);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::UrlFormattingOption);
  // QUrl::FormattingOptions operator|(QUrl::FormattingOptions, QUrl::ComponentFormattingOptions);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::FormattingOptions, QUrl::ComponentFormattingOptions);
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::FormattingOptions);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::FormattingOptions);
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::FormattingOptions);
  /// TODO: QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::FormattingOptions);
  // QDataStream & operator<<(QDataStream &, const QUrl &);
  binder.operators().put_to<QDataStream &, const QUrl &>();
  // QDataStream & operator>>(QDataStream &, QUrl &);
  binder.operators().read_from<QDataStream &, QUrl &>();
  // QDebug operator<<(QDebug, const QUrl &);
  /// TODO: QDebug operator<<(QDebug, const QUrl &);
}

