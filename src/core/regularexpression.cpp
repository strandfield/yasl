// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/regularexpression.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/regularexpression.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_regular_expression_pattern_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum pattern_option = regular_expression.Enum("PatternOption").setId(script::Type::QRegularExpressionPatternOption).get();

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

  Enum match_type = regular_expression.Enum("MatchType").setId(script::Type::QRegularExpressionMatchType).get();

  match_type.addValue("NormalMatch", QRegularExpression::NormalMatch);
  match_type.addValue("PartialPreferCompleteMatch", QRegularExpression::PartialPreferCompleteMatch);
  match_type.addValue("PartialPreferFirstMatch", QRegularExpression::PartialPreferFirstMatch);
  match_type.addValue("NoMatch", QRegularExpression::NoMatch);
}


static void register_regular_expression_match_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum match_option = regular_expression.Enum("MatchOption").setId(script::Type::QRegularExpressionMatchOption).get();

  register_qflags_type<QRegularExpression::MatchOption>(regular_expression, "MatchOptions", script::Type::QRegularExpressionMatchOptions);
  match_option.addValue("NoMatchOption", QRegularExpression::NoMatchOption);
  match_option.addValue("AnchoredMatchOption", QRegularExpression::AnchoredMatchOption);
  match_option.addValue("DontCheckSubjectStringMatchOption", QRegularExpression::DontCheckSubjectStringMatchOption);
}


static void register_regular_expression_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression = ns.Class("RegularExpression").setId(script::Type::QRegularExpression).get();

  register_regular_expression_pattern_option_enum(regular_expression);
  register_regular_expression_match_type_enum(regular_expression);
  register_regular_expression_match_option_enum(regular_expression);
  binding::Class<QRegularExpression> binder{ regular_expression };

  // QRegularExpression::PatternOptions patternOptions() const;
  binder.add_fun<QRegularExpression::PatternOptions, &QRegularExpression::patternOptions>("patternOptions");
  // void setPatternOptions(QRegularExpression::PatternOptions);
  binder.add_void_fun<QRegularExpression::PatternOptions, &QRegularExpression::setPatternOptions>("setPatternOptions");
  // QRegularExpression();
  binder.ctors().add_default();
  // QRegularExpression(const QString &, QRegularExpression::PatternOptions);
  binder.ctors().add<const QString &, QRegularExpression::PatternOptions>();
  // QRegularExpression(const QRegularExpression &);
  binder.ctors().add<const QRegularExpression &>();
  // ~QRegularExpression();
  binder.add_dtor();
  // QRegularExpression & operator=(const QRegularExpression &);
  binder.operators().assign<const QRegularExpression &>();
  // QRegularExpression & operator=(QRegularExpression &&);
  binder.operators().assign<QRegularExpression &&>();
  // void swap(QRegularExpression &);
  binder.add_void_fun<QRegularExpression &, &QRegularExpression::swap>("swap");
  // QString pattern() const;
  binder.add_fun<QString, &QRegularExpression::pattern>("pattern");
  // void setPattern(const QString &);
  binder.add_void_fun<const QString &, &QRegularExpression::setPattern>("setPattern");
  // bool isValid() const;
  binder.add_fun<bool, &QRegularExpression::isValid>("isValid");
  // int patternErrorOffset() const;
  binder.add_fun<int, &QRegularExpression::patternErrorOffset>("patternErrorOffset");
  // QString errorString() const;
  binder.add_fun<QString, &QRegularExpression::errorString>("errorString");
  // int captureCount() const;
  binder.add_fun<int, &QRegularExpression::captureCount>("captureCount");
  // QStringList namedCaptureGroups() const;
  /// TODO: QStringList namedCaptureGroups() const;
  // QRegularExpressionMatch match(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatch, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::match>("match");
  // QRegularExpressionMatch match(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  /// TODO: QRegularExpressionMatch match(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  // QRegularExpressionMatchIterator globalMatch(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatchIterator, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::globalMatch>("globalMatch");
  // QRegularExpressionMatchIterator globalMatch(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  /// TODO: QRegularExpressionMatchIterator globalMatch(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  // void optimize() const;
  binder.add_const_void_fun<&QRegularExpression::optimize>("optimize");
  // static QString escape(const QString &);
  binder.add_static<QString, const QString &, &QRegularExpression::escape>("escape");
  // bool operator==(const QRegularExpression &) const;
  binder.operators().eq<const QRegularExpression &>();
  // bool operator!=(const QRegularExpression &) const;
  binder.operators().neq<const QRegularExpression &>();
}


static void register_regular_expression_match_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_match = ns.Class("RegularExpressionMatch").setId(script::Type::QRegularExpressionMatch).get();

  binding::Class<QRegularExpressionMatch> binder{ regular_expression_match };

  // QRegularExpressionMatch();
  binder.ctors().add_default();
  // ~QRegularExpressionMatch();
  binder.add_dtor();
  // QRegularExpressionMatch(const QRegularExpressionMatch &);
  binder.ctors().add<const QRegularExpressionMatch &>();
  // QRegularExpressionMatch & operator=(const QRegularExpressionMatch &);
  binder.operators().assign<const QRegularExpressionMatch &>();
  // QRegularExpressionMatch & operator=(QRegularExpressionMatch &&);
  binder.operators().assign<QRegularExpressionMatch &&>();
  // void swap(QRegularExpressionMatch &);
  binder.add_void_fun<QRegularExpressionMatch &, &QRegularExpressionMatch::swap>("swap");
  // QRegularExpression regularExpression() const;
  binder.add_fun<QRegularExpression, &QRegularExpressionMatch::regularExpression>("regularExpression");
  // QRegularExpression::MatchType matchType() const;
  binder.add_fun<QRegularExpression::MatchType, &QRegularExpressionMatch::matchType>("matchType");
  // QRegularExpression::MatchOptions matchOptions() const;
  binder.add_fun<QRegularExpression::MatchOptions, &QRegularExpressionMatch::matchOptions>("matchOptions");
  // bool hasMatch() const;
  binder.add_fun<bool, &QRegularExpressionMatch::hasMatch>("hasMatch");
  // bool hasPartialMatch() const;
  binder.add_fun<bool, &QRegularExpressionMatch::hasPartialMatch>("hasPartialMatch");
  // bool isValid() const;
  binder.add_fun<bool, &QRegularExpressionMatch::isValid>("isValid");
  // int lastCapturedIndex() const;
  binder.add_fun<int, &QRegularExpressionMatch::lastCapturedIndex>("lastCapturedIndex");
  // QString captured(int) const;
  binder.add_fun<QString, int, &QRegularExpressionMatch::captured>("captured");
  // QStringRef capturedRef(int) const;
  /// TODO: QStringRef capturedRef(int) const;
  // QStringView capturedView(int) const;
  /// TODO: QStringView capturedView(int) const;
  // QString captured(const QString &) const;
  binder.add_fun<QString, const QString &, &QRegularExpressionMatch::captured>("captured");
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
  binder.add_fun<int, int, &QRegularExpressionMatch::capturedStart>("capturedStart");
  // int capturedLength(int) const;
  binder.add_fun<int, int, &QRegularExpressionMatch::capturedLength>("capturedLength");
  // int capturedEnd(int) const;
  binder.add_fun<int, int, &QRegularExpressionMatch::capturedEnd>("capturedEnd");
  // int capturedStart(const QString &) const;
  binder.add_fun<int, const QString &, &QRegularExpressionMatch::capturedStart>("capturedStart");
  // int capturedLength(const QString &) const;
  binder.add_fun<int, const QString &, &QRegularExpressionMatch::capturedLength>("capturedLength");
  // int capturedEnd(const QString &) const;
  binder.add_fun<int, const QString &, &QRegularExpressionMatch::capturedEnd>("capturedEnd");
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

  Class regular_expression_match_iterator = ns.Class("RegularExpressionMatchIterator").setId(script::Type::QRegularExpressionMatchIterator).get();

  binding::Class<QRegularExpressionMatchIterator> binder{ regular_expression_match_iterator };

  // QRegularExpressionMatchIterator();
  binder.ctors().add_default();
  // ~QRegularExpressionMatchIterator();
  binder.add_dtor();
  // QRegularExpressionMatchIterator(const QRegularExpressionMatchIterator &);
  binder.ctors().add<const QRegularExpressionMatchIterator &>();
  // QRegularExpressionMatchIterator & operator=(const QRegularExpressionMatchIterator &);
  binder.operators().assign<const QRegularExpressionMatchIterator &>();
  // QRegularExpressionMatchIterator & operator=(QRegularExpressionMatchIterator &&);
  binder.operators().assign<QRegularExpressionMatchIterator &&>();
  // void swap(QRegularExpressionMatchIterator &);
  binder.add_void_fun<QRegularExpressionMatchIterator &, &QRegularExpressionMatchIterator::swap>("swap");
  // bool isValid() const;
  binder.add_fun<bool, &QRegularExpressionMatchIterator::isValid>("isValid");
  // bool hasNext() const;
  binder.add_fun<bool, &QRegularExpressionMatchIterator::hasNext>("hasNext");
  // QRegularExpressionMatch next();
  binder.add_fun<QRegularExpressionMatch, &QRegularExpressionMatchIterator::next>("next");
  // QRegularExpressionMatch peekNext() const;
  binder.add_fun<QRegularExpressionMatch, &QRegularExpressionMatchIterator::peekNext>("peekNext");
  // QRegularExpression regularExpression() const;
  binder.add_fun<QRegularExpression, &QRegularExpressionMatchIterator::regularExpression>("regularExpression");
  // QRegularExpression::MatchType matchType() const;
  binder.add_fun<QRegularExpression::MatchType, &QRegularExpressionMatchIterator::matchType>("matchType");
  // QRegularExpression::MatchOptions matchOptions() const;
  binder.add_fun<QRegularExpression::MatchOptions, &QRegularExpressionMatchIterator::matchOptions>("matchOptions");
}


void register_regularexpression_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_regular_expression_class(ns);
  register_regular_expression_match_class(ns);
  register_regular_expression_match_iterator_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QRegularExpression &, uint);
  binder.add_fun<uint, const QRegularExpression &, uint, &qHash>("qHash");
  // void swap(QRegularExpression &, QRegularExpression &);
  binder.add_void_fun<QRegularExpression &, QRegularExpression &, &swap>("swap");
  // QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QRegularExpression::PatternOptions::enum_type);
  /// TODO: QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QRegularExpression::PatternOptions::enum_type);
  // QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QFlags<QRegularExpression::PatternOptions::enum_type>);
  /// TODO: QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QFlags<QRegularExpression::PatternOptions::enum_type>);
  // QIncompatibleFlag operator|(QRegularExpression::PatternOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QRegularExpression::PatternOptions::enum_type, int);
  // QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QRegularExpression::MatchOptions::enum_type);
  /// TODO: QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QRegularExpression::MatchOptions::enum_type);
  // QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QFlags<QRegularExpression::MatchOptions::enum_type>);
  /// TODO: QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QFlags<QRegularExpression::MatchOptions::enum_type>);
  // QIncompatibleFlag operator|(QRegularExpression::MatchOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QRegularExpression::MatchOptions::enum_type, int);
  // QDataStream & operator<<(QDataStream &, const QRegularExpression &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QRegularExpression &);
  // QDataStream & operator>>(QDataStream &, QRegularExpression &);
  /// TODO: QDataStream & operator>>(QDataStream &, QRegularExpression &);
  // QDebug operator<<(QDebug, const QRegularExpression &);
  /// TODO: QDebug operator<<(QDebug, const QRegularExpression &);
  // QDebug operator<<(QDebug, QRegularExpression::PatternOptions);
  /// TODO: QDebug operator<<(QDebug, QRegularExpression::PatternOptions);
  // void swap(QRegularExpressionMatch &, QRegularExpressionMatch &);
  binder.add_void_fun<QRegularExpressionMatch &, QRegularExpressionMatch &, &swap>("swap");
  // QDebug operator<<(QDebug, const QRegularExpressionMatch &);
  /// TODO: QDebug operator<<(QDebug, const QRegularExpressionMatch &);
  // void swap(QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &);
  binder.add_void_fun<QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &, &swap>("swap");
}

