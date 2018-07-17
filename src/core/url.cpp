// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/url.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/flags.h"

#include <QDataStream>
#include <QDebug>
#include <QUrlQuery>

static void register_url_component_formatting_option_enum(script::Class url)
{
  using namespace script;

  Enum component_formatting_option = url.newEnum("ComponentFormattingOption", script::Type::QUrlComponentFormattingOption);

  component_formatting_option.addValue("DecodeReserved", QUrl::DecodeReserved);
  component_formatting_option.addValue("EncodeDelimiters", QUrl::EncodeDelimiters);
  component_formatting_option.addValue("EncodeReserved", QUrl::EncodeReserved);
  component_formatting_option.addValue("EncodeSpaces", QUrl::EncodeSpaces);
  component_formatting_option.addValue("EncodeUnicode", QUrl::EncodeUnicode);
  component_formatting_option.addValue("FullyDecoded", QUrl::FullyDecoded);
  component_formatting_option.addValue("FullyEncoded", QUrl::FullyEncoded);
  component_formatting_option.addValue("PrettyDecoded", QUrl::PrettyDecoded);

  register_qflags_type<QUrl::ComponentFormattingOption>(url, "ComponentFormattingOptions", Type::QUrlComponentFormattingOptions);
}

static void register_url_parsing_mode_enum(script::Class url)
{
  using namespace script;

  Enum parsing_mode = url.newEnum("ParsingMode", script::Type::QUrlParsingMode);

  parsing_mode.addValue("DecodedMode", QUrl::DecodedMode);
  parsing_mode.addValue("StrictMode", QUrl::StrictMode);
  parsing_mode.addValue("TolerantMode", QUrl::TolerantMode);
}

static void register_url_url_formatting_option_enum(script::Class url)
{
  using namespace script;

  Enum url_formatting_option = url.newEnum("UrlFormattingOption", script::Type::QUrlUrlFormattingOption);

  url_formatting_option.addValue("None", QUrl::None);
  url_formatting_option.addValue("NormalizePathSegments", QUrl::NormalizePathSegments);
  url_formatting_option.addValue("PreferLocalFile", QUrl::PreferLocalFile);
  url_formatting_option.addValue("RemoveAuthority", QUrl::RemoveAuthority);
  url_formatting_option.addValue("RemoveFilename", QUrl::RemoveFilename);
  url_formatting_option.addValue("RemoveFragment", QUrl::RemoveFragment);
  url_formatting_option.addValue("RemovePassword", QUrl::RemovePassword);
  url_formatting_option.addValue("RemovePath", QUrl::RemovePath);
  url_formatting_option.addValue("RemovePort", QUrl::RemovePort);
  url_formatting_option.addValue("RemoveQuery", QUrl::RemoveQuery);
  url_formatting_option.addValue("RemoveScheme", QUrl::RemoveScheme);
  url_formatting_option.addValue("RemoveUserInfo", QUrl::RemoveUserInfo);
  url_formatting_option.addValue("StripTrailingSlash", QUrl::StripTrailingSlash);

  register_qflags_type<QUrl::UrlFormattingOption>(url, "FormattingOptions", Type::QUrlFormattingOptions);
}

static void register_url_user_input_resolution_option_enum(script::Class url)
{
  using namespace script;

  Enum user_input_resolution_option = url.newEnum("UserInputResolutionOption", script::Type::QUrlUserInputResolutionOption);

  user_input_resolution_option.addValue("AssumeLocalFile", QUrl::AssumeLocalFile);
  user_input_resolution_option.addValue("DefaultResolution", QUrl::DefaultResolution);

  register_qflags_type<QUrl::UserInputResolutionOption>(url, "UserInputResolutionOptions", Type::QUrlUserInputResolutionOptions);
}

static void register_url_class(script::Namespace ns)
{
  using namespace script;

  Class url = ns.newClass(ClassBuilder::New("Url").setId(script::Type::QUrl));

  register_url_component_formatting_option_enum(url);
  register_url_parsing_mode_enum(url);
  register_url_url_formatting_option_enum(url);
  register_url_user_input_resolution_option_enum(url);
  binding::Class<QUrl> binder{ url };

  // ~QUrl();
  binder.add_dtor();
  // QUrl();
  binder.ctors().add_default();
  // QUrl(const QUrl &);
  binder.ctors().add<const QUrl &>();
  // QUrl & operator=(const QUrl &);
  binder.operators().assign<const QUrl &>();
  // QUrl(const QString &, QUrl::ParsingMode);
  binder.ctors().add<const QString &, QUrl::ParsingMode>();
  // QUrl & operator=(const QString &);
  binder.operators().assign<const QString &>();
  // QUrl(QUrl &&);
  /// TODO: binder.ctors().add<QUrl &&>();
  // QUrl & operator=(QUrl &&);
  /// TODO: binder.operators().assign<QUrl &&>();
  // void swap(QUrl &);
  binder.add_void_fun<QUrl &, &QUrl::swap>("swap");
  // void setUrl(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUrl>("setUrl");
  // QString url(QUrl::FormattingOptions) const;
  binder.add_fun<QString, QUrl::FormattingOptions, &QUrl::url>("url");
  // QString toString(QUrl::FormattingOptions) const;
  binder.add_fun<QString, QUrl::FormattingOptions, &QUrl::toString>("toString");
  // QString toDisplayString(QUrl::FormattingOptions) const;
  binder.add_fun<QString, QUrl::FormattingOptions, &QUrl::toDisplayString>("toDisplayString");
  // QUrl adjusted(QUrl::FormattingOptions) const;
  binder.add_fun<QUrl, QUrl::FormattingOptions, &QUrl::adjusted>("adjusted");
  // QByteArray toEncoded(QUrl::FormattingOptions) const;
  binder.add_fun<QByteArray, QUrl::FormattingOptions, &QUrl::toEncoded>("toEncoded");
  // static QUrl fromEncoded(const QByteArray &, QUrl::ParsingMode);
  binder.add_static<QUrl, const QByteArray &, QUrl::ParsingMode, &QUrl::fromEncoded>("fromEncoded");
  // static QUrl fromUserInput(const QString &);
  binder.add_static<QUrl, const QString &, &QUrl::fromUserInput>("fromUserInput");
  // static QUrl fromUserInput(const QString &, const QString &, QUrl::UserInputResolutionOptions);
  binder.add_static<QUrl, const QString &, const QString &, QUrl::UserInputResolutionOptions, &QUrl::fromUserInput>("fromUserInput");
  // bool isValid() const;
  binder.add_fun<bool, &QUrl::isValid>("isValid");
  // QString errorString() const;
  binder.add_fun<QString, &QUrl::errorString>("errorString");
  // bool isEmpty() const;
  binder.add_fun<bool, &QUrl::isEmpty>("isEmpty");
  // void clear();
  binder.add_void_fun<&QUrl::clear>("clear");
  // void setScheme(const QString &);
  binder.add_void_fun<const QString &, &QUrl::setScheme>("setScheme");
  // QString scheme() const;
  binder.add_fun<QString, &QUrl::scheme>("scheme");
  // void setAuthority(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setAuthority>("setAuthority");
  // QString authority(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::authority>("authority");
  // void setUserInfo(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUserInfo>("setUserInfo");
  // QString userInfo(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::userInfo>("userInfo");
  // void setUserName(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setUserName>("setUserName");
  // QString userName(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::userName>("userName");
  // void setPassword(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setPassword>("setPassword");
  // QString password(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::password>("password");
  // void setHost(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setHost>("setHost");
  // QString host(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::host>("host");
  // QString topLevelDomain(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::topLevelDomain>("topLevelDomain");
  // void setPort(int);
  binder.add_void_fun<int, &QUrl::setPort>("setPort");
  // int port(int) const;
  binder.add_fun<int, int, &QUrl::port>("port");
  // void setPath(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setPath>("setPath");
  // QString path(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::path>("path");
  // QString fileName(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::fileName>("fileName");
  // bool hasQuery() const;
  binder.add_fun<bool, &QUrl::hasQuery>("hasQuery");
  // void setQuery(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setQuery>("setQuery");
  // void setQuery(const QUrlQuery &);
  binder.add_void_fun<const QUrlQuery &, &QUrl::setQuery>("setQuery");
  // QString query(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::query>("query");
  // bool hasFragment() const;
  binder.add_fun<bool, &QUrl::hasFragment>("hasFragment");
  // QString fragment(QUrl::ComponentFormattingOptions) const;
  binder.add_fun<QString, QUrl::ComponentFormattingOptions, &QUrl::fragment>("fragment");
  // void setFragment(const QString &, QUrl::ParsingMode);
  binder.add_void_fun<const QString &, QUrl::ParsingMode, &QUrl::setFragment>("setFragment");
  // QUrl resolved(const QUrl &) const;
  binder.add_fun<QUrl, const QUrl &, &QUrl::resolved>("resolved");
  // bool isRelative() const;
  binder.add_fun<bool, &QUrl::isRelative>("isRelative");
  // bool isParentOf(const QUrl &) const;
  binder.add_fun<bool, const QUrl &, &QUrl::isParentOf>("isParentOf");
  // bool isLocalFile() const;
  binder.add_fun<bool, &QUrl::isLocalFile>("isLocalFile");
  // static QUrl fromLocalFile(const QString &);
  binder.add_static<QUrl, const QString &, &QUrl::fromLocalFile>("fromLocalFile");
  // QString toLocalFile() const;
  binder.add_fun<QString, &QUrl::toLocalFile>("toLocalFile");
  // void detach();
  binder.add_void_fun<&QUrl::detach>("detach");
  // bool isDetached() const;
  binder.add_fun<bool, &QUrl::isDetached>("isDetached");
  // bool operator<(const QUrl &) const;
  binder.operators().less<const QUrl &>();
  // bool operator==(const QUrl &) const;
  binder.operators().eq<const QUrl &>();
  // bool operator!=(const QUrl &) const;
  binder.operators().neq<const QUrl &>();
  // bool matches(const QUrl &, QUrl::FormattingOptions) const;
  binder.add_fun<bool, const QUrl &, QUrl::FormattingOptions, &QUrl::matches>("matches");
  // static QString fromPercentEncoding(const QByteArray &);
  binder.add_static<QString, const QByteArray &, &QUrl::fromPercentEncoding>("fromPercentEncoding");
  // static QByteArray toPercentEncoding(const QString &, const QByteArray &, const QByteArray &);
  binder.add_static<QByteArray, const QString &, const QByteArray &, const QByteArray &, &QUrl::toPercentEncoding>("toPercentEncoding");
  // static QString fromAce(const QByteArray &);
  binder.add_static<QString, const QByteArray &, &QUrl::fromAce>("fromAce");
  // static QByteArray toAce(const QString &);
  binder.add_static<QByteArray, const QString &, &QUrl::toAce>("toAce");
  // static QStringList idnWhitelist();
  binder.add_static<QStringList, &QUrl::idnWhitelist>("idnWhitelist");
  // static QStringList toStringList(const QList<QUrl> &, QUrl::FormattingOptions);
  binder.add_static<QStringList, const QList<QUrl> &, QUrl::FormattingOptions, &QUrl::toStringList>("toStringList");
  // static QList<QUrl> fromStringList(const QStringList &, QUrl::ParsingMode);
  binder.add_static<QList<QUrl>, const QStringList &, QUrl::ParsingMode, &QUrl::fromStringList>("fromStringList");
  // static void setIdnWhitelist(const QStringList &);
  binder.add_static_void_fun<const QStringList &, &QUrl::setIdnWhitelist>("setIdnWhitelist");
  // QUrl::DataPtr & data_ptr();
  /// ignore: binder.add_fun<QUrl::DataPtr &, &QUrl::data_ptr>("data_ptr");
}

void register_url_file(script::Namespace root)
{
  using namespace script;

  register_url_class(root);
  binding::Namespace binder{ root };

  // uint qHash(const QUrl &, uint);
  binder.add_fun<uint, const QUrl &, uint, &qHash>("qHash");
  // void swap(QUrl &, QUrl &);
  binder.add_void_fun<QUrl &, QUrl &, &swap>("swap");
  // QFlags<QUrl::ComponentFormattingOptions::enum_type> operator|(QUrl::ComponentFormattingOptions::enum_type, QUrl::ComponentFormattingOptions::enum_type);
  binder.operators().or<QFlags<QUrl::ComponentFormattingOptions::enum_type>, QUrl::ComponentFormattingOptions::enum_type, QUrl::ComponentFormattingOptions::enum_type>();
  // QFlags<QUrl::ComponentFormattingOptions::enum_type> operator|(QUrl::ComponentFormattingOptions::enum_type, QFlags<QUrl::ComponentFormattingOptions::enum_type>);
  binder.operators().or<QFlags<QUrl::ComponentFormattingOptions::enum_type>, QUrl::ComponentFormattingOptions::enum_type, QFlags<QUrl::ComponentFormattingOptions::enum_type>>();
  // QIncompatibleFlag operator|(QUrl::ComponentFormattingOptions::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QUrl::ComponentFormattingOptions::enum_type, int>();
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::UrlFormattingOption);
  binder.operators().or<QUrl::FormattingOptions, QUrl::UrlFormattingOption, QUrl::UrlFormattingOption>();
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::FormattingOptions);
  binder.operators().or<QUrl::FormattingOptions, QUrl::UrlFormattingOption, QUrl::FormattingOptions>();
  // QIncompatibleFlag operator|(QUrl::UrlFormattingOption, int);
  binder.operators().or<QIncompatibleFlag, QUrl::UrlFormattingOption, int>();
  // QUrl::FormattingOptions & operator|=(QUrl::FormattingOptions &, QUrl::ComponentFormattingOptions);
  binder.operators().or_assign<QUrl::FormattingOptions &, QUrl::ComponentFormattingOptions>();
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOption);
  binder.operators().or<QUrl::FormattingOptions, QUrl::UrlFormattingOption, QUrl::ComponentFormattingOption>();
  // QUrl::FormattingOptions operator|(QUrl::UrlFormattingOption, QUrl::ComponentFormattingOptions);
  binder.operators().or<QUrl::FormattingOptions, QUrl::UrlFormattingOption, QUrl::ComponentFormattingOptions>();
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::UrlFormattingOption);
  binder.operators().or<QUrl::FormattingOptions, QUrl::ComponentFormattingOption, QUrl::UrlFormattingOption>();
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::UrlFormattingOption);
  binder.operators().or<QUrl::FormattingOptions, QUrl::ComponentFormattingOptions, QUrl::UrlFormattingOption>();
  // QUrl::FormattingOptions operator|(QUrl::FormattingOptions, QUrl::ComponentFormattingOptions);
  binder.operators().or<QUrl::FormattingOptions, QUrl::FormattingOptions, QUrl::ComponentFormattingOptions>();
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOption, QUrl::FormattingOptions);
  binder.operators().or<QUrl::FormattingOptions, QUrl::ComponentFormattingOption, QUrl::FormattingOptions>();
  // QUrl::FormattingOptions operator|(QUrl::ComponentFormattingOptions, QUrl::FormattingOptions);
  binder.operators().or<QUrl::FormattingOptions, QUrl::ComponentFormattingOptions, QUrl::FormattingOptions>();
  // QDataStream & operator<<(QDataStream &, const QUrl &);
  binder.operators().put_to<QDataStream &, const QUrl &>();
  // QDataStream & operator>>(QDataStream &, QUrl &);
  binder.operators().read_from<QDataStream &, QUrl &>();
  // QDebug operator<<(QDebug, const QUrl &);
  binder.operators().left_shift<QDebug, QDebug, const QUrl &>();
}

