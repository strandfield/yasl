// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/url.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
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

  Enum parsing_mode = url.newEnum("ParsingMode").setId(script::Type::QUrlParsingMode).get();

  parsing_mode.addValue("TolerantMode", QUrl::TolerantMode);
  parsing_mode.addValue("StrictMode", QUrl::StrictMode);
  parsing_mode.addValue("DecodedMode", QUrl::DecodedMode);
}


static void register_url_url_formatting_option_enum(script::Class url)
{
  using namespace script;

  Enum url_formatting_option = url.newEnum("UrlFormattingOption").setId(script::Type::QUrlUrlFormattingOption).get();

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

  Enum component_formatting_option = url.newEnum("ComponentFormattingOption").setId(script::Type::QUrlComponentFormattingOption).get();

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

  Enum user_input_resolution_option = url.newEnum("UserInputResolutionOption").setId(script::Type::QUrlUserInputResolutionOption).get();

  register_qflags_type<QUrl::UserInputResolutionOption>(url, "UserInputResolutionOptions", script::Type::QUrlUserInputResolutionOptions);
  user_input_resolution_option.addValue("DefaultResolution", QUrl::DefaultResolution);
  user_input_resolution_option.addValue("AssumeLocalFile", QUrl::AssumeLocalFile);
}


static void register_url_class(script::Namespace ns)
{
  using namespace script;

  Class url = ns.newClass("Url").setId(script::Type::QUrl).get();

  register_url_parsing_mode_enum(url);
  register_url_url_formatting_option_enum(url);
  register_url_component_formatting_option_enum(url);
  register_url_user_input_resolution_option_enum(url);

  // QUrl();
  bind::default_constructor<QUrl>(url).create();
  // QUrl(const QUrl &);
  bind::constructor<QUrl, const QUrl &>(url).create();
  // QUrl & operator=(const QUrl &);
  bind::memop_assign<QUrl, const QUrl &>(url);
  // QUrl(const QString &, QUrl::ParsingMode);
  bind::constructor<QUrl, const QString &, QUrl::ParsingMode>(url)
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
  // QUrl & operator=(const QString &);
  bind::memop_assign<QUrl, const QString &>(url);
  // QUrl(QUrl &&);
  bind::constructor<QUrl, QUrl &&>(url).create();
  // QUrl & operator=(QUrl &&);
  bind::memop_assign<QUrl, QUrl &&>(url);
  // ~QUrl();
  bind::destructor<QUrl>(url).create();
  // void swap(QUrl &);
  bind::void_member_function<QUrl, QUrl &, &QUrl::swap>(url, "swap").create();
  // void setUrl(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setUrl>(url, "setUrl")
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
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
  bind::static_member_function<QUrl, QUrl, const QByteArray &, QUrl::ParsingMode, &QUrl::fromEncoded>(url, "fromEncoded")
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
  // static QUrl fromUserInput(const QString &);
  bind::static_member_function<QUrl, QUrl, const QString &, &QUrl::fromUserInput>(url, "fromUserInput").create();
  // static QUrl fromUserInput(const QString &, const QString &, QUrl::UserInputResolutionOptions);
  bind::static_member_function<QUrl, QUrl, const QString &, const QString &, QUrl::UserInputResolutionOptions, &QUrl::fromUserInput>(url, "fromUserInput")
    .apply(bind::default_arguments(QUrl::UserInputResolutionOptions(QUrl::DefaultResolution))).create();
  // bool isValid() const;
  bind::member_function<QUrl, bool, &QUrl::isValid>(url, "isValid").create();
  // QString errorString() const;
  bind::member_function<QUrl, QString, &QUrl::errorString>(url, "errorString").create();
  // bool isEmpty() const;
  bind::member_function<QUrl, bool, &QUrl::isEmpty>(url, "isEmpty").create();
  // void clear();
  bind::void_member_function<QUrl, &QUrl::clear>(url, "clear").create();
  // void setScheme(const QString &);
  bind::void_member_function<QUrl, const QString &, &QUrl::setScheme>(url, "setScheme").create();
  // QString scheme() const;
  bind::member_function<QUrl, QString, &QUrl::scheme>(url, "scheme").create();
  // void setAuthority(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setAuthority>(url, "setAuthority")
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
  // QString authority(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::authority>(url, "authority")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setUserInfo(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setUserInfo>(url, "setUserInfo")
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
  // QString userInfo(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::userInfo>(url, "userInfo")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setUserName(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setUserName>(url, "setUserName")
    .apply(bind::default_arguments(QUrl::DecodedMode)).create();
  // QString userName(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::userName>(url, "userName")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // void setPassword(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setPassword>(url, "setPassword")
    .apply(bind::default_arguments(QUrl::DecodedMode)).create();
  // QString password(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::password>(url, "password")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // void setHost(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setHost>(url, "setHost")
    .apply(bind::default_arguments(QUrl::DecodedMode)).create();
  // QString host(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::host>(url, "host")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // QString topLevelDomain(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::topLevelDomain>(url, "topLevelDomain")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // void setPort(int);
  bind::void_member_function<QUrl, int, &QUrl::setPort>(url, "setPort").create();
  // int port(int) const;
  bind::member_function<QUrl, int, int, &QUrl::port>(url, "port")
    .apply(bind::default_arguments(-1)).create();
  // void setPath(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setPath>(url, "setPath")
    .apply(bind::default_arguments(QUrl::DecodedMode)).create();
  // QString path(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::path>(url, "path")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // QString fileName(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::fileName>(url, "fileName")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::FullyDecoded))).create();
  // bool hasQuery() const;
  bind::member_function<QUrl, bool, &QUrl::hasQuery>(url, "hasQuery").create();
  // void setQuery(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setQuery>(url, "setQuery")
    .apply(bind::default_arguments(QUrl::TolerantMode)).create();
  // void setQuery(const QUrlQuery &);
  bind::void_member_function<QUrl, const QUrlQuery &, &QUrl::setQuery>(url, "setQuery").create();
  // QString query(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::query>(url, "query")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // bool hasFragment() const;
  bind::member_function<QUrl, bool, &QUrl::hasFragment>(url, "hasFragment").create();
  // QString fragment(QUrl::ComponentFormattingOptions) const;
  bind::member_function<QUrl, QString, QUrl::ComponentFormattingOptions, &QUrl::fragment>(url, "fragment")
    .apply(bind::default_arguments(QUrl::ComponentFormattingOptions(QUrl::PrettyDecoded))).create();
  // void setFragment(const QString &, QUrl::ParsingMode);
  bind::void_member_function<QUrl, const QString &, QUrl::ParsingMode, &QUrl::setFragment>(url, "setFragment").create();
  // QUrl resolved(const QUrl &) const;
  bind::member_function<QUrl, QUrl, const QUrl &, &QUrl::resolved>(url, "resolved").create();
  // bool isRelative() const;
  bind::member_function<QUrl, bool, &QUrl::isRelative>(url, "isRelative").create();
  // bool isParentOf(const QUrl &) const;
  bind::member_function<QUrl, bool, const QUrl &, &QUrl::isParentOf>(url, "isParentOf").create();
  // bool isLocalFile() const;
  bind::member_function<QUrl, bool, &QUrl::isLocalFile>(url, "isLocalFile").create();
  // static QUrl fromLocalFile(const QString &);
  bind::static_member_function<QUrl, QUrl, const QString &, &QUrl::fromLocalFile>(url, "fromLocalFile").create();
  // QString toLocalFile() const;
  bind::member_function<QUrl, QString, &QUrl::toLocalFile>(url, "toLocalFile").create();
  // void detach();
  bind::void_member_function<QUrl, &QUrl::detach>(url, "detach").create();
  // bool isDetached() const;
  bind::member_function<QUrl, bool, &QUrl::isDetached>(url, "isDetached").create();
  // bool operator<(const QUrl &) const;
  bind::memop_less<QUrl, const QUrl &>(url);
  // bool operator==(const QUrl &) const;
  bind::memop_eq<QUrl, const QUrl &>(url);
  // bool operator!=(const QUrl &) const;
  bind::memop_neq<QUrl, const QUrl &>(url);
  // bool matches(const QUrl &, QUrl::FormattingOptions) const;
  /// TODO: bool matches(const QUrl &, QUrl::FormattingOptions) const;
  // static QString fromPercentEncoding(const QByteArray &);
  bind::static_member_function<QUrl, QString, const QByteArray &, &QUrl::fromPercentEncoding>(url, "fromPercentEncoding").create();
  // static QByteArray toPercentEncoding(const QString &, const QByteArray &, const QByteArray &);
  bind::static_member_function<QUrl, QByteArray, const QString &, const QByteArray &, const QByteArray &, &QUrl::toPercentEncoding>(url, "toPercentEncoding")
    .apply(bind::default_arguments(QByteArray(), QByteArray())).create();
  // static QString fromAce(const QByteArray &);
  bind::static_member_function<QUrl, QString, const QByteArray &, &QUrl::fromAce>(url, "fromAce").create();
  // static QByteArray toAce(const QString &);
  bind::static_member_function<QUrl, QByteArray, const QString &, &QUrl::toAce>(url, "toAce").create();
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

  // uint qHash(const QUrl &, uint);
  bind::function<uint, const QUrl &, uint, &qHash>(ns, "qHash").create();
  // void swap(QUrl &, QUrl &);
  bind::void_function<QUrl &, QUrl &, &swap>(ns, "swap").create();
  // QUrl::ComponentFormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOption);
  bind::op_bitor<QUrl::ComponentFormattingOptions, QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOption>(ns);
  // QUrl::ComponentFormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOptions);
  bind::op_bitor<QUrl::ComponentFormattingOptions, QUrl::ComponentFormattingOption, QUrl::ComponentFormattingOptions>(ns);
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
  bind::op_put_to<QDataStream &, const QUrl &>(ns);
  // QDataStream & operator>>(QDataStream &, QUrl &);
  bind::op_read_from<QDataStream &, QUrl &>(ns);
  // QDebug operator<<(QDebug, const QUrl &);
  /// TODO: QDebug operator<<(QDebug, const QUrl &);
}

