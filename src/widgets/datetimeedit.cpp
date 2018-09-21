// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/datetimeedit.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/datetimeedit.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_date_time_edit_section_enum(script::Class date_time_edit)
{
  using namespace script;

  Enum section = date_time_edit.Enum("Section").setId(script::Type::QDateTimeEditSection).get();

  register_qflags_type<QDateTimeEdit::Section>(date_time_edit, "Sections", script::Type::QDateTimeEditSections);
  section.addValue("NoSection", QDateTimeEdit::NoSection);
  section.addValue("AmPmSection", QDateTimeEdit::AmPmSection);
  section.addValue("MSecSection", QDateTimeEdit::MSecSection);
  section.addValue("SecondSection", QDateTimeEdit::SecondSection);
  section.addValue("MinuteSection", QDateTimeEdit::MinuteSection);
  section.addValue("HourSection", QDateTimeEdit::HourSection);
  section.addValue("DaySection", QDateTimeEdit::DaySection);
  section.addValue("MonthSection", QDateTimeEdit::MonthSection);
  section.addValue("YearSection", QDateTimeEdit::YearSection);
  section.addValue("TimeSections_Mask", QDateTimeEdit::TimeSections_Mask);
  section.addValue("DateSections_Mask", QDateTimeEdit::DateSections_Mask);
}


static void register_date_time_edit_class(script::Namespace ns)
{
  using namespace script;

  Class date_time_edit = ns.Class("DateTimeEdit").setId(script::Type::QDateTimeEdit)
    .setBase(script::Type::QAbstractSpinBox).get();

  register_date_time_edit_section_enum(date_time_edit);
  binding::QClass<QDateTimeEdit> binder{ date_time_edit, &QDateTimeEdit::staticMetaObject };

  // QDateTimeEdit(QWidget *);
  binder.ctors().add<QWidget *>();
  // QDateTimeEdit(const QDateTime &, QWidget *);
  binder.ctors().add<const QDateTime &, QWidget *>();
  // QDateTimeEdit(const QDate &, QWidget *);
  binder.ctors().add<const QDate &, QWidget *>();
  // QDateTimeEdit(const QTime &, QWidget *);
  binder.ctors().add<const QTime &, QWidget *>();
  // ~QDateTimeEdit();
  binder.add_dtor();
  // QDateTime dateTime() const;
  binder.add_fun<QDateTime, &QDateTimeEdit::dateTime>("dateTime");
  // QDate date() const;
  binder.add_fun<QDate, &QDateTimeEdit::date>("date");
  // QTime time() const;
  binder.add_fun<QTime, &QDateTimeEdit::time>("time");
  // QDateTime minimumDateTime() const;
  binder.add_fun<QDateTime, &QDateTimeEdit::minimumDateTime>("minimumDateTime");
  // void clearMinimumDateTime();
  binder.add_void_fun<&QDateTimeEdit::clearMinimumDateTime>("clearMinimumDateTime");
  // void setMinimumDateTime(const QDateTime &);
  binder.add_void_fun<const QDateTime &, &QDateTimeEdit::setMinimumDateTime>("setMinimumDateTime");
  // QDateTime maximumDateTime() const;
  binder.add_fun<QDateTime, &QDateTimeEdit::maximumDateTime>("maximumDateTime");
  // void clearMaximumDateTime();
  binder.add_void_fun<&QDateTimeEdit::clearMaximumDateTime>("clearMaximumDateTime");
  // void setMaximumDateTime(const QDateTime &);
  binder.add_void_fun<const QDateTime &, &QDateTimeEdit::setMaximumDateTime>("setMaximumDateTime");
  // void setDateTimeRange(const QDateTime &, const QDateTime &);
  binder.add_void_fun<const QDateTime &, const QDateTime &, &QDateTimeEdit::setDateTimeRange>("setDateTimeRange");
  // QDate minimumDate() const;
  binder.add_fun<QDate, &QDateTimeEdit::minimumDate>("minimumDate");
  // void setMinimumDate(const QDate &);
  binder.add_void_fun<const QDate &, &QDateTimeEdit::setMinimumDate>("setMinimumDate");
  // void clearMinimumDate();
  binder.add_void_fun<&QDateTimeEdit::clearMinimumDate>("clearMinimumDate");
  // QDate maximumDate() const;
  binder.add_fun<QDate, &QDateTimeEdit::maximumDate>("maximumDate");
  // void setMaximumDate(const QDate &);
  binder.add_void_fun<const QDate &, &QDateTimeEdit::setMaximumDate>("setMaximumDate");
  // void clearMaximumDate();
  binder.add_void_fun<&QDateTimeEdit::clearMaximumDate>("clearMaximumDate");
  // void setDateRange(const QDate &, const QDate &);
  binder.add_void_fun<const QDate &, const QDate &, &QDateTimeEdit::setDateRange>("setDateRange");
  // QTime minimumTime() const;
  binder.add_fun<QTime, &QDateTimeEdit::minimumTime>("minimumTime");
  // void setMinimumTime(const QTime &);
  binder.add_void_fun<const QTime &, &QDateTimeEdit::setMinimumTime>("setMinimumTime");
  // void clearMinimumTime();
  binder.add_void_fun<&QDateTimeEdit::clearMinimumTime>("clearMinimumTime");
  // QTime maximumTime() const;
  binder.add_fun<QTime, &QDateTimeEdit::maximumTime>("maximumTime");
  // void setMaximumTime(const QTime &);
  binder.add_void_fun<const QTime &, &QDateTimeEdit::setMaximumTime>("setMaximumTime");
  // void clearMaximumTime();
  binder.add_void_fun<&QDateTimeEdit::clearMaximumTime>("clearMaximumTime");
  // void setTimeRange(const QTime &, const QTime &);
  binder.add_void_fun<const QTime &, const QTime &, &QDateTimeEdit::setTimeRange>("setTimeRange");
  // QDateTimeEdit::Sections displayedSections() const;
  binder.add_fun<QDateTimeEdit::Sections, &QDateTimeEdit::displayedSections>("displayedSections");
  // QDateTimeEdit::Section currentSection() const;
  binder.add_fun<QDateTimeEdit::Section, &QDateTimeEdit::currentSection>("currentSection");
  // QDateTimeEdit::Section sectionAt(int) const;
  binder.add_fun<QDateTimeEdit::Section, int, &QDateTimeEdit::sectionAt>("sectionAt");
  // void setCurrentSection(QDateTimeEdit::Section);
  binder.add_void_fun<QDateTimeEdit::Section, &QDateTimeEdit::setCurrentSection>("setCurrentSection");
  // int currentSectionIndex() const;
  binder.add_fun<int, &QDateTimeEdit::currentSectionIndex>("currentSectionIndex");
  // void setCurrentSectionIndex(int);
  binder.add_void_fun<int, &QDateTimeEdit::setCurrentSectionIndex>("setCurrentSectionIndex");
  // QCalendarWidget * calendarWidget() const;
  /// TODO: QCalendarWidget * calendarWidget() const;
  // void setCalendarWidget(QCalendarWidget *);
  /// TODO: void setCalendarWidget(QCalendarWidget *);
  // int sectionCount() const;
  binder.add_fun<int, &QDateTimeEdit::sectionCount>("sectionCount");
  // void setSelectedSection(QDateTimeEdit::Section);
  binder.add_void_fun<QDateTimeEdit::Section, &QDateTimeEdit::setSelectedSection>("setSelectedSection");
  // QString sectionText(QDateTimeEdit::Section) const;
  binder.add_fun<QString, QDateTimeEdit::Section, &QDateTimeEdit::sectionText>("sectionText");
  // QString displayFormat() const;
  binder.add_fun<QString, &QDateTimeEdit::displayFormat>("displayFormat");
  // void setDisplayFormat(const QString &);
  binder.add_void_fun<const QString &, &QDateTimeEdit::setDisplayFormat>("setDisplayFormat");
  // bool calendarPopup() const;
  binder.add_fun<bool, &QDateTimeEdit::calendarPopup>("calendarPopup");
  // void setCalendarPopup(bool);
  binder.add_void_fun<bool, &QDateTimeEdit::setCalendarPopup>("setCalendarPopup");
  // Qt::TimeSpec timeSpec() const;
  binder.add_fun<Qt::TimeSpec, &QDateTimeEdit::timeSpec>("timeSpec");
  // void setTimeSpec(Qt::TimeSpec);
  binder.add_void_fun<Qt::TimeSpec, &QDateTimeEdit::setTimeSpec>("setTimeSpec");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QDateTimeEdit::sizeHint>("sizeHint");
  // void clear();
  binder.add_void_fun<&QDateTimeEdit::clear>("clear");
  // void stepBy(int);
  binder.add_void_fun<int, &QDateTimeEdit::stepBy>("stepBy");
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // void dateTimeChanged(const QDateTime &);
  binder.sigs().add<const QDateTime &>("dateTimeChanged", "dateTimeChanged(const QDateTime &)");
  // void timeChanged(const QTime &);
  binder.sigs().add<const QTime &>("timeChanged", "timeChanged(const QTime &)");
  // void dateChanged(const QDate &);
  binder.sigs().add<const QDate &>("dateChanged", "dateChanged(const QDate &)");
  // void setDateTime(const QDateTime &);
  binder.add_void_fun<const QDateTime &, &QDateTimeEdit::setDateTime>("setDateTime");
  // void setDate(const QDate &);
  binder.add_void_fun<const QDate &, &QDateTimeEdit::setDate>("setDate");
  // void setTime(const QTime &);
  binder.add_void_fun<const QTime &, &QDateTimeEdit::setTime>("setTime");

  date_time_edit.engine()->registerQtType(&QDateTimeEdit::staticMetaObject, date_time_edit.id());
}


static void register_time_edit_class(script::Namespace ns)
{
  using namespace script;

  Class time_edit = ns.Class("TimeEdit").setId(script::Type::QTimeEdit)
    .setBase(script::Type::QDateTimeEdit).get();

  binding::QClass<QTimeEdit> binder{ time_edit, &QTimeEdit::staticMetaObject };

  // QTimeEdit(QWidget *);
  binder.ctors().add<QWidget *>();
  // QTimeEdit(const QTime &, QWidget *);
  binder.ctors().add<const QTime &, QWidget *>();
  // ~QTimeEdit();
  binder.add_dtor();
  // void userTimeChanged(const QTime &);
  binder.sigs().add<const QTime &>("userTimeChanged", "userTimeChanged(const QTime &)");

  time_edit.engine()->registerQtType(&QTimeEdit::staticMetaObject, time_edit.id());
}


static void register_date_edit_class(script::Namespace ns)
{
  using namespace script;

  Class date_edit = ns.Class("DateEdit").setId(script::Type::QDateEdit)
    .setBase(script::Type::QDateTimeEdit).get();

  binding::QClass<QDateEdit> binder{ date_edit, &QDateEdit::staticMetaObject };

  // QDateEdit(QWidget *);
  binder.ctors().add<QWidget *>();
  // QDateEdit(const QDate &, QWidget *);
  binder.ctors().add<const QDate &, QWidget *>();
  // ~QDateEdit();
  binder.add_dtor();
  // void userDateChanged(const QDate &);
  binder.sigs().add<const QDate &>("userDateChanged", "userDateChanged(const QDate &)");

  date_edit.engine()->registerQtType(&QDateEdit::staticMetaObject, date_edit.id());
}


void register_datetimeedit_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_date_time_edit_class(ns);
  register_time_edit_class(ns);
  register_date_edit_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QDateTimeEdit::Sections::enum_type);
  /// TODO: QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QDateTimeEdit::Sections::enum_type);
  // QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QFlags<QDateTimeEdit::Sections::enum_type>);
  /// TODO: QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QFlags<QDateTimeEdit::Sections::enum_type>);
  // QIncompatibleFlag operator|(QDateTimeEdit::Sections::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDateTimeEdit::Sections::enum_type, int);
}

