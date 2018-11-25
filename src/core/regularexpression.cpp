// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/regularexpression.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"
#include "yasl/core/flags.h"

#include "yasl/core/datastream.h"
#include "yasl/core/regularexpression.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_regular_expression_pattern_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum pattern_option = regular_expression.newEnum("PatternOption").setId(script::Type::QRegularExpressionPatternOption).get();

  register_qflags_type<QRegularExpression::PatternOption>(regular_expression, "PatternOptions", script::Type::QRegularExpressionPatternOptions);
  pattern_option.addValue("NoPatternOption", QRegularExpression::NoPatternOption);
  pattern_option.addValue("CaseInsensitiveOption", QRegularExpression::CaseInsensitiveOption);
  pattern_option.addValue("DotMatchesEverythingOption", QRegularExpression::DotMatchesEverythingOption);
  pattern_option.addValue("MultilineOption", QRegularExpression::MultilineOption);
  pattern_option.addValue("ExtendedPatternSyntaxOption", QRegularExpression::ExtendedPatternSyntaxOption);
  pattern_option.addValue("InvertedGreedinessOption", QRegularExpression::InvertedGreedinessOption);
  pattern_option.addValue("DontCaptureOption", QRegularExpression::DontCaptureOption);
  pattern_option.addValue("UseUnicodePropertiesOption", QRegularExpression::UseUnicodePropertiesOption);
  pattern_option.addValue("OptimizeOnFirstUsageOption", QRegularExpression::OptimizeOnFirstUsageOption);
  pattern_option.addValue("DontAutomaticallyOptimizeOption", QRegularExpression::DontAutomaticallyOptimizeOption);
}


static void register_regular_expression_match_type_enum(script::Class regular_expression)
{
  using namespace script;

  Enum match_type = regular_expression.newEnum("MatchType").setId(script::Type::QRegularExpressionMatchType).get();

  match_type.addValue("NormalMatch", QRegularExpression::NormalMatch);
  match_type.addValue("PartialPreferCompleteMatch", QRegularExpression::PartialPreferCompleteMatch);
  match_type.addValue("PartialPreferFirstMatch", QRegularExpression::PartialPreferFirstMatch);
  match_type.addValue("NoMatch", QRegularExpression::NoMatch);
}


static void register_regular_expression_match_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum match_option = regular_expression.newEnum("MatchOption").setId(script::Type::QRegularExpressionMatchOption).get();

  register_qflags_type<QRegularExpression::MatchOption>(regular_expression, "MatchOptions", script::Type::QRegularExpressionMatchOptions);
  match_option.addValue("NoMatchOption", QRegularExpression::NoMatchOption);
  match_option.addValue("AnchoredMatchOption", QRegularExpression::AnchoredMatchOption);
  match_option.addValue("DontCheckSubjectStringMatchOption", QRegularExpression::DontCheckSubjectStringMatchOption);
}


static void register_regular_expression_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression = ns.newClass("RegularExpression").setId(script::Type::QRegularExpression).get();

  register_regular_expression_pattern_option_enum(regular_expression);
  register_regular_expression_match_type_enum(regular_expression);
  register_regular_expression_match_option_enum(regular_expression);

  // QRegularExpression::PatternOptions patternOptions() const;
  bind::member_function<QRegularExpression, QRegularExpression::PatternOptions, &QRegularExpression::patternOptions>(regular_expression, "patternOptions").create();
  // void setPatternOptions(QRegularExpression::PatternOptions);
  bind::void_member_function<QRegularExpression, QRegularExpression::PatternOptions, &QRegularExpression::setPatternOptions>(regular_expression, "setPatternOptions").create();
  // QRegularExpression();
  bind::default_constructor<QRegularExpression>(regular_expression).create();
  // QRegularExpression(const QString &, QRegularExpression::PatternOptions);
  bind::constructor<QRegularExpression, const QString &, QRegularExpression::PatternOptions>(regular_expression)
    .apply(bind::default_arguments(QRegularExpression::PatternOptions(QRegularExpression::NoPatternOption))).create();
  // QRegularExpression(const QRegularExpression &);
  bind::constructor<QRegularExpression, const QRegularExpression &>(regular_expression).create();
  // ~QRegularExpression();
  bind::destructor<QRegularExpression>(regular_expression).create();
  // QRegularExpression & operator=(const QRegularExpression &);
  bind::memop_assign<QRegularExpression, const QRegularExpression &>(regular_expression);
  // QRegularExpression & operator=(QRegularExpression &&);
  bind::memop_assign<QRegularExpression, QRegularExpression &&>(regular_expression);
  // void swap(QRegularExpression &);
  bind::void_member_function<QRegularExpression, QRegularExpression &, &QRegularExpression::swap>(regular_expression, "swap").create();
  // QString pattern() const;
  bind::member_function<QRegularExpression, QString, &QRegularExpression::pattern>(regular_expression, "pattern").create();
  // void setPattern(const QString &);
  bind::void_member_function<QRegularExpression, const QString &, &QRegularExpression::setPattern>(regular_expression, "setPattern").create();
  // bool isValid() const;
  bind::member_function<QRegularExpression, bool, &QRegularExpression::isValid>(regular_expression, "isValid").create();
  // int patternErrorOffset() const;
  bind::member_function<QRegularExpression, int, &QRegularExpression::patternErrorOffset>(regular_expression, "patternErrorOffset").create();
  // QString errorString() const;
  bind::member_function<QRegularExpression, QString, &QRegularExpression::errorString>(regular_expression, "errorString").create();
  // int captureCount() const;
  bind::member_function<QRegularExpression, int, &QRegularExpression::captureCount>(regular_expression, "captureCount").create();
  // QStringList namedCaptureGroups() const;
  /// TODO: QStringList namedCaptureGroups() const;
  // QRegularExpressionMatch match(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  bind::member_function<QRegularExpression, QRegularExpressionMatch, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::match>(regular_expression, "match")
    .apply(bind::default_arguments(QRegularExpression::MatchOptions(QRegularExpression::NoMatchOption), QRegularExpression::NormalMatch)).create();
  // QRegularExpressionMatch match(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  /// TODO: QRegularExpressionMatch match(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  // QRegularExpressionMatchIterator globalMatch(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  bind::member_function<QRegularExpression, QRegularExpressionMatchIterator, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::globalMatch>(regular_expression, "globalMatch")
    .apply(bind::default_arguments(QRegularExpression::MatchOptions(QRegularExpression::NoMatchOption), QRegularExpression::NormalMatch)).create();
  // void optimize() const;
  bind::const_void_member_function<QRegularExpression, &QRegularExpression::optimize>(regular_expression, "optimize").create();
  // static QString escape(const QString &);
  bind::static_member_function<QRegularExpression, QString, const QString &, &QRegularExpression::escape>(regular_expression, "escape").create();
  // bool operator==(const QRegularExpression &) const;
  bind::memop_eq<QRegularExpression, const QRegularExpression &>(regular_expression);
  // bool operator!=(const QRegularExpression &) const;
  bind::memop_neq<QRegularExpression, const QRegularExpression &>(regular_expression);

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QRegularExpression, QMetaType::QRegularExpression>>();
}


static void register_regular_expression_match_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_match = ns.newClass("RegularExpressionMatch").setId(script::Type::QRegularExpressionMatch).get();


  // QRegularExpressionMatch();
  bind::default_constructor<QRegularExpressionMatch>(regular_expression_match).create();
  // ~QRegularExpressionMatch();
  bind::destructor<QRegularExpressionMatch>(regular_expression_match).create();
  // QRegularExpressionMatch(const QRegularExpressionMatch &);
  bind::constructor<QRegularExpressionMatch, const QRegularExpressionMatch &>(regular_expression_match).create();
  // QRegularExpressionMatch & operator=(const QRegularExpressionMatch &);
  bind::memop_assign<QRegularExpressionMatch, const QRegularExpressionMatch &>(regular_expression_match);
  // QRegularExpressionMatch & operator=(QRegularExpressionMatch &&);
  bind::memop_assign<QRegularExpressionMatch, QRegularExpressionMatch &&>(regular_expression_match);
  // void swap(QRegularExpressionMatch &);
  bind::void_member_function<QRegularExpressionMatch, QRegularExpressionMatch &, &QRegularExpressionMatch::swap>(regular_expression_match, "swap").create();
  // QRegularExpression regularExpression() const;
  bind::member_function<QRegularExpressionMatch, QRegularExpression, &QRegularExpressionMatch::regularExpression>(regular_expression_match, "regularExpression").create();
  // QRegularExpression::MatchType matchType() const;
  bind::member_function<QRegularExpressionMatch, QRegularExpression::MatchType, &QRegularExpressionMatch::matchType>(regular_expression_match, "matchType").create();
  // QRegularExpression::MatchOptions matchOptions() const;
  bind::member_function<QRegularExpressionMatch, QRegularExpression::MatchOptions, &QRegularExpressionMatch::matchOptions>(regular_expression_match, "matchOptions").create();
  // bool hasMatch() const;
  bind::member_function<QRegularExpressionMatch, bool, &QRegularExpressionMatch::hasMatch>(regular_expression_match, "hasMatch").create();
  // bool hasPartialMatch() const;
  bind::member_function<QRegularExpressionMatch, bool, &QRegularExpressionMatch::hasPartialMatch>(regular_expression_match, "hasPartialMatch").create();
  // bool isValid() const;
  bind::member_function<QRegularExpressionMatch, bool, &QRegularExpressionMatch::isValid>(regular_expression_match, "isValid").create();
  // int lastCapturedIndex() const;
  bind::member_function<QRegularExpressionMatch, int, &QRegularExpressionMatch::lastCapturedIndex>(regular_expression_match, "lastCapturedIndex").create();
  // QString captured(int) const;
  bind::member_function<QRegularExpressionMatch, QString, int, &QRegularExpressionMatch::captured>(regular_expression_match, "captured").create();
  // QStringRef capturedRef(int) const;
  /// TODO: QStringRef capturedRef(int) const;
  // QStringView capturedView(int) const;
  /// TODO: QStringView capturedView(int) const;
  // QString captured(const QString &) const;
  bind::member_function<QRegularExpressionMatch, QString, const QString &, &QRegularExpressionMatch::captured>(regular_expression_match, "captured").create();
  // QStringRef capturedRef(const QString &) const;
  /// TODO: QStringRef capturedRef(const QString &) const;
  // QString captured(QStringView) const;
  /// TODO: QString captured(QStringView) const;
  // QStringRef capturedRef(QStringView) const;
  /// TODO: QStringRef capturedRef(QStringView) const;
  // QStringView capturedView(QStringView) const;
  /// TODO: QStringView capturedView(QStringView) const;
  // QStringList capturedTexts() const;
  /// TODO: QStringList capturedTexts() const;
  // int capturedStart(int) const;
  bind::member_function<QRegularExpressionMatch, int, int, &QRegularExpressionMatch::capturedStart>(regular_expression_match, "capturedStart").create();
  // int capturedLength(int) const;
  bind::member_function<QRegularExpressionMatch, int, int, &QRegularExpressionMatch::capturedLength>(regular_expression_match, "capturedLength").create();
  // int capturedEnd(int) const;
  bind::member_function<QRegularExpressionMatch, int, int, &QRegularExpressionMatch::capturedEnd>(regular_expression_match, "capturedEnd").create();
  // int capturedStart(const QString &) const;
  bind::member_function<QRegularExpressionMatch, int, const QString &, &QRegularExpressionMatch::capturedStart>(regular_expression_match, "capturedStart").create();
  // int capturedLength(const QString &) const;
  bind::member_function<QRegularExpressionMatch, int, const QString &, &QRegularExpressionMatch::capturedLength>(regular_expression_match, "capturedLength").create();
  // int capturedEnd(const QString &) const;
  bind::member_function<QRegularExpressionMatch, int, const QString &, &QRegularExpressionMatch::capturedEnd>(regular_expression_match, "capturedEnd").create();
  // int capturedStart(QStringView) const;
  /// TODO: int capturedStart(QStringView) const;
  // int capturedLength(QStringView) const;
  /// TODO: int capturedLength(QStringView) const;
  // int capturedEnd(QStringView) const;
  /// TODO: int capturedEnd(QStringView) const;
}


static void register_regular_expression_match_iterator_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_match_iterator = ns.newClass("RegularExpressionMatchIterator").setId(script::Type::QRegularExpressionMatchIterator).get();


  // QRegularExpressionMatchIterator();
  bind::default_constructor<QRegularExpressionMatchIterator>(regular_expression_match_iterator).create();
  // ~QRegularExpressionMatchIterator();
  bind::destructor<QRegularExpressionMatchIterator>(regular_expression_match_iterator).create();
  // QRegularExpressionMatchIterator(const QRegularExpressionMatchIterator &);
  bind::constructor<QRegularExpressionMatchIterator, const QRegularExpressionMatchIterator &>(regular_expression_match_iterator).create();
  // QRegularExpressionMatchIterator & operator=(const QRegularExpressionMatchIterator &);
  bind::memop_assign<QRegularExpressionMatchIterator, const QRegularExpressionMatchIterator &>(regular_expression_match_iterator);
  // QRegularExpressionMatchIterator & operator=(QRegularExpressionMatchIterator &&);
  bind::memop_assign<QRegularExpressionMatchIterator, QRegularExpressionMatchIterator &&>(regular_expression_match_iterator);
  // void swap(QRegularExpressionMatchIterator &);
  bind::void_member_function<QRegularExpressionMatchIterator, QRegularExpressionMatchIterator &, &QRegularExpressionMatchIterator::swap>(regular_expression_match_iterator, "swap").create();
  // bool isValid() const;
  bind::member_function<QRegularExpressionMatchIterator, bool, &QRegularExpressionMatchIterator::isValid>(regular_expression_match_iterator, "isValid").create();
  // bool hasNext() const;
  bind::member_function<QRegularExpressionMatchIterator, bool, &QRegularExpressionMatchIterator::hasNext>(regular_expression_match_iterator, "hasNext").create();
  // QRegularExpressionMatch next();
  bind::member_function<QRegularExpressionMatchIterator, QRegularExpressionMatch, &QRegularExpressionMatchIterator::next>(regular_expression_match_iterator, "next").create();
  // QRegularExpressionMatch peekNext() const;
  bind::member_function<QRegularExpressionMatchIterator, QRegularExpressionMatch, &QRegularExpressionMatchIterator::peekNext>(regular_expression_match_iterator, "peekNext").create();
  // QRegularExpression regularExpression() const;
  bind::member_function<QRegularExpressionMatchIterator, QRegularExpression, &QRegularExpressionMatchIterator::regularExpression>(regular_expression_match_iterator, "regularExpression").create();
  // QRegularExpression::MatchType matchType() const;
  bind::member_function<QRegularExpressionMatchIterator, QRegularExpression::MatchType, &QRegularExpressionMatchIterator::matchType>(regular_expression_match_iterator, "matchType").create();
  // QRegularExpression::MatchOptions matchOptions() const;
  bind::member_function<QRegularExpressionMatchIterator, QRegularExpression::MatchOptions, &QRegularExpressionMatchIterator::matchOptions>(regular_expression_match_iterator, "matchOptions").create();
}


void register_regularexpression_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_regular_expression_class(ns);
  register_regular_expression_match_class(ns);
  register_regular_expression_match_iterator_class(ns);

  // uint qHash(const QRegularExpression &, uint);
  bind::function<uint, const QRegularExpression &, uint, &qHash>(ns, "qHash").create();
  // void swap(QRegularExpression &, QRegularExpression &);
  bind::void_function<QRegularExpression &, QRegularExpression &, &swap>(ns, "swap").create();
  // QRegularExpression::PatternOptions operator|(QRegularExpression::PatternOption, QRegularExpression::PatternOption);
  bind::op_bitor<QRegularExpression::PatternOptions, QRegularExpression::PatternOption, QRegularExpression::PatternOption>(ns);
  // QRegularExpression::PatternOptions operator|(QRegularExpression::PatternOption, QRegularExpression::PatternOptions);
  bind::op_bitor<QRegularExpression::PatternOptions, QRegularExpression::PatternOption, QRegularExpression::PatternOptions>(ns);
  // QIncompatibleFlag operator|(QRegularExpression::PatternOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QRegularExpression::PatternOptions::enum_type, int);
  // QRegularExpression::MatchOptions operator|(QRegularExpression::MatchOption, QRegularExpression::MatchOption);
  bind::op_bitor<QRegularExpression::MatchOptions, QRegularExpression::MatchOption, QRegularExpression::MatchOption>(ns);
  // QRegularExpression::MatchOptions operator|(QRegularExpression::MatchOption, QRegularExpression::MatchOptions);
  bind::op_bitor<QRegularExpression::MatchOptions, QRegularExpression::MatchOption, QRegularExpression::MatchOptions>(ns);
  // QIncompatibleFlag operator|(QRegularExpression::MatchOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QRegularExpression::MatchOptions::enum_type, int);
  // QDataStream & operator<<(QDataStream &, const QRegularExpression &);
  bind::op_put_to<QDataStream &, const QRegularExpression &>(ns);
  // QDataStream & operator>>(QDataStream &, QRegularExpression &);
  bind::op_read_from<QDataStream &, QRegularExpression &>(ns);
  // QDebug operator<<(QDebug, const QRegularExpression &);
  /// TODO: QDebug operator<<(QDebug, const QRegularExpression &);
  // QDebug operator<<(QDebug, QRegularExpression::PatternOptions);
  /// TODO: QDebug operator<<(QDebug, QRegularExpression::PatternOptions);
  // void swap(QRegularExpressionMatch &, QRegularExpressionMatch &);
  bind::void_function<QRegularExpressionMatch &, QRegularExpressionMatch &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QRegularExpressionMatch &);
  /// TODO: QDebug operator<<(QDebug, const QRegularExpressionMatch &);
  // void swap(QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &);
  bind::void_function<QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &, &swap>(ns, "swap").create();
}

