// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/regularexpression.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#include <QDataStream>
#include <QDebug>

static void register_regular_expression_match_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum match_option = regular_expression.Enum("MatchOption").setId(script::Type::QRegularExpressionMatchOption).get();

  match_option.addValue("AnchoredMatchOption", QRegularExpression::AnchoredMatchOption);
  match_option.addValue("DontCheckSubjectStringMatchOption", QRegularExpression::DontCheckSubjectStringMatchOption);
  match_option.addValue("NoMatchOption", QRegularExpression::NoMatchOption);

  register_qflags_type<QRegularExpression::MatchOption>(regular_expression, "MatchOptions", script::Type::QRegularExpressionMatchOptions);
}

static void register_regular_expression_match_type_enum(script::Class regular_expression)
{
  using namespace script;

  Enum match_type = regular_expression.Enum("MatchType").setId(script::Type::QRegularExpressionMatchType).get();

  match_type.addValue("NoMatch", QRegularExpression::NoMatch);
  match_type.addValue("NormalMatch", QRegularExpression::NormalMatch);
  match_type.addValue("PartialPreferCompleteMatch", QRegularExpression::PartialPreferCompleteMatch);
  match_type.addValue("PartialPreferFirstMatch", QRegularExpression::PartialPreferFirstMatch);
}

static void register_regular_expression_pattern_option_enum(script::Class regular_expression)
{
  using namespace script;

  Enum pattern_option = regular_expression.Enum("PatternOption").setId(script::Type::QRegularExpressionPatternOption).get();

  pattern_option.addValue("CaseInsensitiveOption", QRegularExpression::CaseInsensitiveOption);
  pattern_option.addValue("DontAutomaticallyOptimizeOption", QRegularExpression::DontAutomaticallyOptimizeOption);
  pattern_option.addValue("DontCaptureOption", QRegularExpression::DontCaptureOption);
  pattern_option.addValue("DotMatchesEverythingOption", QRegularExpression::DotMatchesEverythingOption);
  pattern_option.addValue("ExtendedPatternSyntaxOption", QRegularExpression::ExtendedPatternSyntaxOption);
  pattern_option.addValue("InvertedGreedinessOption", QRegularExpression::InvertedGreedinessOption);
  pattern_option.addValue("MultilineOption", QRegularExpression::MultilineOption);
  pattern_option.addValue("NoPatternOption", QRegularExpression::NoPatternOption);
  pattern_option.addValue("OptimizeOnFirstUsageOption", QRegularExpression::OptimizeOnFirstUsageOption);
  pattern_option.addValue("UseUnicodePropertiesOption", QRegularExpression::UseUnicodePropertiesOption);

  register_qflags_type<QRegularExpression::PatternOption>(regular_expression, "PatternOptions", script::Type::QRegularExpressionPatternOptions);
}

static void register_regular_expression_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression = ns.Class("RegularExpression").setId(script::Type::QRegularExpression).get();

  register_regular_expression_match_option_enum(regular_expression);
  register_regular_expression_match_type_enum(regular_expression);
  register_regular_expression_pattern_option_enum(regular_expression);
  binding::Class<QRegularExpression> binder{ regular_expression };

  // ~QRegularExpression();
  binder.add_dtor();
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
  // QRegularExpression & operator=(const QRegularExpression &);
  binder.operators().assign<const QRegularExpression &>();
  // QRegularExpression & operator=(QRegularExpression &&);
  /// TODO: binder.operators().assign<QRegularExpression &&>();
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
  binder.add_fun<QStringList, &QRegularExpression::namedCaptureGroups>("namedCaptureGroups");
  // QRegularExpressionMatch match(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatch, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::match>("match");
  // QRegularExpressionMatch match(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatch, const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::match>("match");
  // QRegularExpressionMatchIterator globalMatch(const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatchIterator, const QString &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::globalMatch>("globalMatch");
  // QRegularExpressionMatchIterator globalMatch(const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const;
  binder.add_fun<QRegularExpressionMatchIterator, const QStringRef &, int, QRegularExpression::MatchType, QRegularExpression::MatchOptions, &QRegularExpression::globalMatch>("globalMatch");
  // void optimize() const;
  binder.add_void_fun<&QRegularExpression::optimize>("optimize");
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

  // ~QRegularExpressionMatch();
  binder.add_dtor();
  // QRegularExpressionMatch();
  binder.ctors().add_default();
  // QRegularExpressionMatch(const QRegularExpressionMatch &);
  binder.ctors().add<const QRegularExpressionMatch &>();
  // QRegularExpressionMatch & operator=(const QRegularExpressionMatch &);
  binder.operators().assign<const QRegularExpressionMatch &>();
  // QRegularExpressionMatch & operator=(QRegularExpressionMatch &&);
  /// TODO: binder.operators().assign<QRegularExpressionMatch &&>();
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
  binder.add_fun<QStringRef, int, &QRegularExpressionMatch::capturedRef>("capturedRef");
  // QStringView capturedView(int) const;
  binder.add_fun<QStringView, int, &QRegularExpressionMatch::capturedView>("capturedView");
  // QString captured(const QString &) const;
  binder.add_fun<QString, const QString &, &QRegularExpressionMatch::captured>("captured");
  // QStringRef capturedRef(const QString &) const;
  binder.add_fun<QStringRef, const QString &, &QRegularExpressionMatch::capturedRef>("capturedRef");
  // QString captured(QStringView) const;
  binder.add_fun<QString, QStringView, &QRegularExpressionMatch::captured>("captured");
  // QStringRef capturedRef(QStringView) const;
  binder.add_fun<QStringRef, QStringView, &QRegularExpressionMatch::capturedRef>("capturedRef");
  // QStringView capturedView(QStringView) const;
  binder.add_fun<QStringView, QStringView, &QRegularExpressionMatch::capturedView>("capturedView");
  // QStringList capturedTexts() const;
  binder.add_fun<QStringList, &QRegularExpressionMatch::capturedTexts>("capturedTexts");
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
  binder.add_fun<int, QStringView, &QRegularExpressionMatch::capturedStart>("capturedStart");
  // int capturedLength(QStringView) const;
  binder.add_fun<int, QStringView, &QRegularExpressionMatch::capturedLength>("capturedLength");
  // int capturedEnd(QStringView) const;
  binder.add_fun<int, QStringView, &QRegularExpressionMatch::capturedEnd>("capturedEnd");
}

static void register_regular_expression_match_iterator_class(script::Namespace ns)
{
  using namespace script;

  Class regular_expression_match_iterator = ns.Class("RegularExpressionMatchIterator").setId(script::Type::QRegularExpressionMatchIterator).get();

  binding::Class<QRegularExpressionMatchIterator> binder{ regular_expression_match_iterator };

  // ~QRegularExpressionMatchIterator();
  binder.add_dtor();
  // QRegularExpressionMatchIterator();
  binder.ctors().add_default();
  // QRegularExpressionMatchIterator(const QRegularExpressionMatchIterator &);
  binder.ctors().add<const QRegularExpressionMatchIterator &>();
  // QRegularExpressionMatchIterator & operator=(const QRegularExpressionMatchIterator &);
  binder.operators().assign<const QRegularExpressionMatchIterator &>();
  // QRegularExpressionMatchIterator & operator=(QRegularExpressionMatchIterator &&);
  /// TODO: binder.operators().assign<QRegularExpressionMatchIterator &&>();
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

void register_regularexpression_file(script::Namespace root)
{
  using namespace script;

  register_regular_expression_class(root);
  register_regular_expression_match_class(root);
  register_regular_expression_match_iterator_class(root);
  binding::Namespace binder{ root };

  // uint qHash(const QRegularExpression &, uint);
  binder.add_fun<uint, const QRegularExpression &, uint, &qHash>("qHash");
  // void swap(QRegularExpression &, QRegularExpression &);
  binder.add_void_fun<QRegularExpression &, QRegularExpression &, &swap>("swap");
  // QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QRegularExpression::PatternOptions::enum_type);
  binder.operators().or<QFlags<QRegularExpression::PatternOptions::enum_type>, QRegularExpression::PatternOptions::enum_type, QRegularExpression::PatternOptions::enum_type>();
  // QFlags<QRegularExpression::PatternOptions::enum_type> operator|(QRegularExpression::PatternOptions::enum_type, QFlags<QRegularExpression::PatternOptions::enum_type>);
  binder.operators().or<QFlags<QRegularExpression::PatternOptions::enum_type>, QRegularExpression::PatternOptions::enum_type, QFlags<QRegularExpression::PatternOptions::enum_type>>();
  // QIncompatibleFlag operator|(QRegularExpression::PatternOptions::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QRegularExpression::PatternOptions::enum_type, int>();
  // QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QRegularExpression::MatchOptions::enum_type);
  binder.operators().or<QFlags<QRegularExpression::MatchOptions::enum_type>, QRegularExpression::MatchOptions::enum_type, QRegularExpression::MatchOptions::enum_type>();
  // QFlags<QRegularExpression::MatchOptions::enum_type> operator|(QRegularExpression::MatchOptions::enum_type, QFlags<QRegularExpression::MatchOptions::enum_type>);
  binder.operators().or<QFlags<QRegularExpression::MatchOptions::enum_type>, QRegularExpression::MatchOptions::enum_type, QFlags<QRegularExpression::MatchOptions::enum_type>>();
  // QIncompatibleFlag operator|(QRegularExpression::MatchOptions::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QRegularExpression::MatchOptions::enum_type, int>();
  // QDataStream & operator<<(QDataStream &, const QRegularExpression &);
  binder.operators().put_to<QDataStream &, const QRegularExpression &>();
  // QDataStream & operator>>(QDataStream &, QRegularExpression &);
  binder.operators().read_from<QDataStream &, QRegularExpression &>();
  // QDebug operator<<(QDebug, const QRegularExpression &);
  binder.operators().left_shift<QDebug, QDebug, const QRegularExpression &>();
  // QDebug operator<<(QDebug, QRegularExpression::PatternOptions);
  binder.operators().left_shift<QDebug, QDebug, QRegularExpression::PatternOptions>();
  // void swap(QRegularExpressionMatch &, QRegularExpressionMatch &);
  binder.add_void_fun<QRegularExpressionMatch &, QRegularExpressionMatch &, &swap>("swap");
  // QDebug operator<<(QDebug, const QRegularExpressionMatch &);
  binder.operators().left_shift<QDebug, QDebug, const QRegularExpressionMatch &>();
  // void swap(QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &);
  binder.add_void_fun<QRegularExpressionMatchIterator &, QRegularExpressionMatchIterator &, &swap>("swap");
}

