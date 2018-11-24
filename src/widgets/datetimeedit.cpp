// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/datetimeedit.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
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

  Enum section = date_time_edit.newEnum("Section").setId(script::Type::QDateTimeEditSection).get();

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

  Class date_time_edit = ns.newClass("DateTimeEdit").setId(script::Type::QDateTimeEdit)
    .setBase(script::Type::QAbstractSpinBox).get();

  register_date_time_edit_section_enum(date_time_edit);

  // QDateTimeEdit(QWidget *);
  bind::constructor<QDateTimeEdit, QWidget *>(date_time_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QDateTime &, QWidget *);
  bind::constructor<QDateTimeEdit, const QDateTime &, QWidget *>(date_time_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QDate &, QWidget *);
  bind::constructor<QDateTimeEdit, const QDate &, QWidget *>(date_time_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QTime &, QWidget *);
  bind::constructor<QDateTimeEdit, const QTime &, QWidget *>(date_time_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QDateTimeEdit();
  bind::destructor<QDateTimeEdit>(date_time_edit).create();
  // QDateTime dateTime() const;
  bind::member_function<QDateTimeEdit, QDateTime, &QDateTimeEdit::dateTime>(date_time_edit, "dateTime").create();
  // QDate date() const;
  bind::member_function<QDateTimeEdit, QDate, &QDateTimeEdit::date>(date_time_edit, "date").create();
  // QTime time() const;
  bind::member_function<QDateTimeEdit, QTime, &QDateTimeEdit::time>(date_time_edit, "time").create();
  // QDateTime minimumDateTime() const;
  bind::member_function<QDateTimeEdit, QDateTime, &QDateTimeEdit::minimumDateTime>(date_time_edit, "minimumDateTime").create();
  // void clearMinimumDateTime();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMinimumDateTime>(date_time_edit, "clearMinimumDateTime").create();
  // void setMinimumDateTime(const QDateTime &);
  bind::void_member_function<QDateTimeEdit, const QDateTime &, &QDateTimeEdit::setMinimumDateTime>(date_time_edit, "setMinimumDateTime").create();
  // QDateTime maximumDateTime() const;
  bind::member_function<QDateTimeEdit, QDateTime, &QDateTimeEdit::maximumDateTime>(date_time_edit, "maximumDateTime").create();
  // void clearMaximumDateTime();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMaximumDateTime>(date_time_edit, "clearMaximumDateTime").create();
  // void setMaximumDateTime(const QDateTime &);
  bind::void_member_function<QDateTimeEdit, const QDateTime &, &QDateTimeEdit::setMaximumDateTime>(date_time_edit, "setMaximumDateTime").create();
  // void setDateTimeRange(const QDateTime &, const QDateTime &);
  bind::void_member_function<QDateTimeEdit, const QDateTime &, const QDateTime &, &QDateTimeEdit::setDateTimeRange>(date_time_edit, "setDateTimeRange").create();
  // QDate minimumDate() const;
  bind::member_function<QDateTimeEdit, QDate, &QDateTimeEdit::minimumDate>(date_time_edit, "minimumDate").create();
  // void setMinimumDate(const QDate &);
  bind::void_member_function<QDateTimeEdit, const QDate &, &QDateTimeEdit::setMinimumDate>(date_time_edit, "setMinimumDate").create();
  // void clearMinimumDate();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMinimumDate>(date_time_edit, "clearMinimumDate").create();
  // QDate maximumDate() const;
  bind::member_function<QDateTimeEdit, QDate, &QDateTimeEdit::maximumDate>(date_time_edit, "maximumDate").create();
  // void setMaximumDate(const QDate &);
  bind::void_member_function<QDateTimeEdit, const QDate &, &QDateTimeEdit::setMaximumDate>(date_time_edit, "setMaximumDate").create();
  // void clearMaximumDate();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMaximumDate>(date_time_edit, "clearMaximumDate").create();
  // void setDateRange(const QDate &, const QDate &);
  bind::void_member_function<QDateTimeEdit, const QDate &, const QDate &, &QDateTimeEdit::setDateRange>(date_time_edit, "setDateRange").create();
  // QTime minimumTime() const;
  bind::member_function<QDateTimeEdit, QTime, &QDateTimeEdit::minimumTime>(date_time_edit, "minimumTime").create();
  // void setMinimumTime(const QTime &);
  bind::void_member_function<QDateTimeEdit, const QTime &, &QDateTimeEdit::setMinimumTime>(date_time_edit, "setMinimumTime").create();
  // void clearMinimumTime();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMinimumTime>(date_time_edit, "clearMinimumTime").create();
  // QTime maximumTime() const;
  bind::member_function<QDateTimeEdit, QTime, &QDateTimeEdit::maximumTime>(date_time_edit, "maximumTime").create();
  // void setMaximumTime(const QTime &);
  bind::void_member_function<QDateTimeEdit, const QTime &, &QDateTimeEdit::setMaximumTime>(date_time_edit, "setMaximumTime").create();
  // void clearMaximumTime();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clearMaximumTime>(date_time_edit, "clearMaximumTime").create();
  // void setTimeRange(const QTime &, const QTime &);
  bind::void_member_function<QDateTimeEdit, const QTime &, const QTime &, &QDateTimeEdit::setTimeRange>(date_time_edit, "setTimeRange").create();
  // QDateTimeEdit::Sections displayedSections() const;
  bind::member_function<QDateTimeEdit, QDateTimeEdit::Sections, &QDateTimeEdit::displayedSections>(date_time_edit, "displayedSections").create();
  // QDateTimeEdit::Section currentSection() const;
  bind::member_function<QDateTimeEdit, QDateTimeEdit::Section, &QDateTimeEdit::currentSection>(date_time_edit, "currentSection").create();
  // QDateTimeEdit::Section sectionAt(int) const;
  bind::member_function<QDateTimeEdit, QDateTimeEdit::Section, int, &QDateTimeEdit::sectionAt>(date_time_edit, "sectionAt").create();
  // void setCurrentSection(QDateTimeEdit::Section);
  bind::void_member_function<QDateTimeEdit, QDateTimeEdit::Section, &QDateTimeEdit::setCurrentSection>(date_time_edit, "setCurrentSection").create();
  // int currentSectionIndex() const;
  bind::member_function<QDateTimeEdit, int, &QDateTimeEdit::currentSectionIndex>(date_time_edit, "currentSectionIndex").create();
  // void setCurrentSectionIndex(int);
  bind::void_member_function<QDateTimeEdit, int, &QDateTimeEdit::setCurrentSectionIndex>(date_time_edit, "setCurrentSectionIndex").create();
  // QCalendarWidget * calendarWidget() const;
  /// TODO: QCalendarWidget * calendarWidget() const;
  // void setCalendarWidget(QCalendarWidget *);
  /// TODO: void setCalendarWidget(QCalendarWidget *);
  // int sectionCount() const;
  bind::member_function<QDateTimeEdit, int, &QDateTimeEdit::sectionCount>(date_time_edit, "sectionCount").create();
  // void setSelectedSection(QDateTimeEdit::Section);
  bind::void_member_function<QDateTimeEdit, QDateTimeEdit::Section, &QDateTimeEdit::setSelectedSection>(date_time_edit, "setSelectedSection").create();
  // QString sectionText(QDateTimeEdit::Section) const;
  bind::member_function<QDateTimeEdit, QString, QDateTimeEdit::Section, &QDateTimeEdit::sectionText>(date_time_edit, "sectionText").create();
  // QString displayFormat() const;
  bind::member_function<QDateTimeEdit, QString, &QDateTimeEdit::displayFormat>(date_time_edit, "displayFormat").create();
  // void setDisplayFormat(const QString &);
  bind::void_member_function<QDateTimeEdit, const QString &, &QDateTimeEdit::setDisplayFormat>(date_time_edit, "setDisplayFormat").create();
  // bool calendarPopup() const;
  bind::member_function<QDateTimeEdit, bool, &QDateTimeEdit::calendarPopup>(date_time_edit, "calendarPopup").create();
  // void setCalendarPopup(bool);
  bind::void_member_function<QDateTimeEdit, bool, &QDateTimeEdit::setCalendarPopup>(date_time_edit, "setCalendarPopup").create();
  // Qt::TimeSpec timeSpec() const;
  bind::member_function<QDateTimeEdit, Qt::TimeSpec, &QDateTimeEdit::timeSpec>(date_time_edit, "timeSpec").create();
  // void setTimeSpec(Qt::TimeSpec);
  bind::void_member_function<QDateTimeEdit, Qt::TimeSpec, &QDateTimeEdit::setTimeSpec>(date_time_edit, "setTimeSpec").create();
  // QSize sizeHint() const;
  bind::member_function<QDateTimeEdit, QSize, &QDateTimeEdit::sizeHint>(date_time_edit, "sizeHint").create();
  // void clear();
  bind::void_member_function<QDateTimeEdit, &QDateTimeEdit::clear>(date_time_edit, "clear").create();
  // void stepBy(int);
  bind::void_member_function<QDateTimeEdit, int, &QDateTimeEdit::stepBy>(date_time_edit, "stepBy").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // void dateTimeChanged(const QDateTime &);
  bind::signal<QDateTimeEdit, const QDateTime &>(date_time_edit, "dateTimeChanged", "dateTimeChanged(const QDateTime &)");
  // void timeChanged(const QTime &);
  bind::signal<QDateTimeEdit, const QTime &>(date_time_edit, "timeChanged", "timeChanged(const QTime &)");
  // void dateChanged(const QDate &);
  bind::signal<QDateTimeEdit, const QDate &>(date_time_edit, "dateChanged", "dateChanged(const QDate &)");
  // void setDateTime(const QDateTime &);
  bind::void_member_function<QDateTimeEdit, const QDateTime &, &QDateTimeEdit::setDateTime>(date_time_edit, "setDateTime").create();
  // void setDate(const QDate &);
  bind::void_member_function<QDateTimeEdit, const QDate &, &QDateTimeEdit::setDate>(date_time_edit, "setDate").create();
  // void setTime(const QTime &);
  bind::void_member_function<QDateTimeEdit, const QTime &, &QDateTimeEdit::setTime>(date_time_edit, "setTime").create();

  bind::link(date_time_edit, &QDateTimeEdit::staticMetaObject);
}


static void register_time_edit_class(script::Namespace ns)
{
  using namespace script;

  Class time_edit = ns.newClass("TimeEdit").setId(script::Type::QTimeEdit)
    .setBase(script::Type::QDateTimeEdit).get();


  // QTimeEdit(QWidget *);
  bind::constructor<QTimeEdit, QWidget *>(time_edit).create();
  // QTimeEdit(const QTime &, QWidget *);
  bind::constructor<QTimeEdit, const QTime &, QWidget *>(time_edit).create();
  // ~QTimeEdit();
  bind::destructor<QTimeEdit>(time_edit).create();
  // void userTimeChanged(const QTime &);
  bind::signal<QTimeEdit, const QTime &>(time_edit, "userTimeChanged", "userTimeChanged(const QTime &)");

  bind::link(time_edit, &QTimeEdit::staticMetaObject);
}


static void register_date_edit_class(script::Namespace ns)
{
  using namespace script;

  Class date_edit = ns.newClass("DateEdit").setId(script::Type::QDateEdit)
    .setBase(script::Type::QDateTimeEdit).get();


  // QDateEdit(QWidget *);
  bind::constructor<QDateEdit, QWidget *>(date_edit).create();
  // QDateEdit(const QDate &, QWidget *);
  bind::constructor<QDateEdit, const QDate &, QWidget *>(date_edit).create();
  // ~QDateEdit();
  bind::destructor<QDateEdit>(date_edit).create();
  // void userDateChanged(const QDate &);
  bind::signal<QDateEdit, const QDate &>(date_edit, "userDateChanged", "userDateChanged(const QDate &)");

  bind::link(date_edit, &QDateEdit::staticMetaObject);
}


void register_datetimeedit_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_date_time_edit_class(ns);
  register_time_edit_class(ns);
  register_date_edit_class(ns);

  // QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QDateTimeEdit::Sections::enum_type);
  /// TODO: QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QDateTimeEdit::Sections::enum_type);
  // QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QFlags<QDateTimeEdit::Sections::enum_type>);
  /// TODO: QFlags<QDateTimeEdit::Sections::enum_type> operator|(QDateTimeEdit::Sections::enum_type, QFlags<QDateTimeEdit::Sections::enum_type>);
  // QIncompatibleFlag operator|(QDateTimeEdit::Sections::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QDateTimeEdit::Sections::enum_type, int);
  // QDateTimeEdit& newDateTimeEdit(QWidget*);
  bind::new_function<QDateTimeEdit, QWidget*>(ns, "newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QDateTime&, QWidget*);
  bind::new_function<QDateTimeEdit, const QDateTime&, QWidget*>(ns, "newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QDate&, QWidget*);
  bind::new_function<QDateTimeEdit, const QDate&, QWidget*>(ns, "newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QTime&, QWidget*);
  bind::new_function<QDateTimeEdit, const QTime&, QWidget*>(ns, "newDateTimeEdit");
  // QDateEdit& newDateEdit(QWidget*);
  bind::new_function<QDateEdit, QWidget*>(ns, "newDateEdit");
  // QDateEdit& newDateEdit(const QDate&, QWidget*);
  bind::new_function<QDateEdit, const QDate&, QWidget*>(ns, "newDateEdit");
  // QTimeEdit& newTimeEdit(QWidget*);
  bind::new_function<QTimeEdit, QWidget*>(ns, "newTimeEdit");
  // QTimeEdit& newTimeEdit(const QTime&, QWidget*);
  bind::new_function<QTimeEdit, const QTime&, QWidget*>(ns, "newTimeEdit");
}

