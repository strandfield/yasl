// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/datetimeedit.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
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
  binding::ClassBinder<QDateTimeEdit> binder{ date_time_edit, &QDateTimeEdit::staticMetaObject };

  // QDateTimeEdit(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QDateTime &, QWidget *);
  binder.ctor<const QDateTime &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QDate &, QWidget *);
  binder.ctor<const QDate &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QDateTimeEdit(const QTime &, QWidget *);
  binder.ctor<const QTime &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QDateTimeEdit();
  binder.dtor().create();
  // QDateTime dateTime() const;
  binder.fun<QDateTime, &QDateTimeEdit::dateTime>("dateTime").create();
  // QDate date() const;
  binder.fun<QDate, &QDateTimeEdit::date>("date").create();
  // QTime time() const;
  binder.fun<QTime, &QDateTimeEdit::time>("time").create();
  // QDateTime minimumDateTime() const;
  binder.fun<QDateTime, &QDateTimeEdit::minimumDateTime>("minimumDateTime").create();
  // void clearMinimumDateTime();
  binder.void_fun<&QDateTimeEdit::clearMinimumDateTime>("clearMinimumDateTime").create();
  // void setMinimumDateTime(const QDateTime &);
  binder.void_fun<const QDateTime &, &QDateTimeEdit::setMinimumDateTime>("setMinimumDateTime").create();
  // QDateTime maximumDateTime() const;
  binder.fun<QDateTime, &QDateTimeEdit::maximumDateTime>("maximumDateTime").create();
  // void clearMaximumDateTime();
  binder.void_fun<&QDateTimeEdit::clearMaximumDateTime>("clearMaximumDateTime").create();
  // void setMaximumDateTime(const QDateTime &);
  binder.void_fun<const QDateTime &, &QDateTimeEdit::setMaximumDateTime>("setMaximumDateTime").create();
  // void setDateTimeRange(const QDateTime &, const QDateTime &);
  binder.void_fun<const QDateTime &, const QDateTime &, &QDateTimeEdit::setDateTimeRange>("setDateTimeRange").create();
  // QDate minimumDate() const;
  binder.fun<QDate, &QDateTimeEdit::minimumDate>("minimumDate").create();
  // void setMinimumDate(const QDate &);
  binder.void_fun<const QDate &, &QDateTimeEdit::setMinimumDate>("setMinimumDate").create();
  // void clearMinimumDate();
  binder.void_fun<&QDateTimeEdit::clearMinimumDate>("clearMinimumDate").create();
  // QDate maximumDate() const;
  binder.fun<QDate, &QDateTimeEdit::maximumDate>("maximumDate").create();
  // void setMaximumDate(const QDate &);
  binder.void_fun<const QDate &, &QDateTimeEdit::setMaximumDate>("setMaximumDate").create();
  // void clearMaximumDate();
  binder.void_fun<&QDateTimeEdit::clearMaximumDate>("clearMaximumDate").create();
  // void setDateRange(const QDate &, const QDate &);
  binder.void_fun<const QDate &, const QDate &, &QDateTimeEdit::setDateRange>("setDateRange").create();
  // QTime minimumTime() const;
  binder.fun<QTime, &QDateTimeEdit::minimumTime>("minimumTime").create();
  // void setMinimumTime(const QTime &);
  binder.void_fun<const QTime &, &QDateTimeEdit::setMinimumTime>("setMinimumTime").create();
  // void clearMinimumTime();
  binder.void_fun<&QDateTimeEdit::clearMinimumTime>("clearMinimumTime").create();
  // QTime maximumTime() const;
  binder.fun<QTime, &QDateTimeEdit::maximumTime>("maximumTime").create();
  // void setMaximumTime(const QTime &);
  binder.void_fun<const QTime &, &QDateTimeEdit::setMaximumTime>("setMaximumTime").create();
  // void clearMaximumTime();
  binder.void_fun<&QDateTimeEdit::clearMaximumTime>("clearMaximumTime").create();
  // void setTimeRange(const QTime &, const QTime &);
  binder.void_fun<const QTime &, const QTime &, &QDateTimeEdit::setTimeRange>("setTimeRange").create();
  // QDateTimeEdit::Sections displayedSections() const;
  binder.fun<QDateTimeEdit::Sections, &QDateTimeEdit::displayedSections>("displayedSections").create();
  // QDateTimeEdit::Section currentSection() const;
  binder.fun<QDateTimeEdit::Section, &QDateTimeEdit::currentSection>("currentSection").create();
  // QDateTimeEdit::Section sectionAt(int) const;
  binder.fun<QDateTimeEdit::Section, int, &QDateTimeEdit::sectionAt>("sectionAt").create();
  // void setCurrentSection(QDateTimeEdit::Section);
  binder.void_fun<QDateTimeEdit::Section, &QDateTimeEdit::setCurrentSection>("setCurrentSection").create();
  // int currentSectionIndex() const;
  binder.fun<int, &QDateTimeEdit::currentSectionIndex>("currentSectionIndex").create();
  // void setCurrentSectionIndex(int);
  binder.void_fun<int, &QDateTimeEdit::setCurrentSectionIndex>("setCurrentSectionIndex").create();
  // QCalendarWidget * calendarWidget() const;
  /// TODO: QCalendarWidget * calendarWidget() const;
  // void setCalendarWidget(QCalendarWidget *);
  /// TODO: void setCalendarWidget(QCalendarWidget *);
  // int sectionCount() const;
  binder.fun<int, &QDateTimeEdit::sectionCount>("sectionCount").create();
  // void setSelectedSection(QDateTimeEdit::Section);
  binder.void_fun<QDateTimeEdit::Section, &QDateTimeEdit::setSelectedSection>("setSelectedSection").create();
  // QString sectionText(QDateTimeEdit::Section) const;
  binder.fun<QString, QDateTimeEdit::Section, &QDateTimeEdit::sectionText>("sectionText").create();
  // QString displayFormat() const;
  binder.fun<QString, &QDateTimeEdit::displayFormat>("displayFormat").create();
  // void setDisplayFormat(const QString &);
  binder.void_fun<const QString &, &QDateTimeEdit::setDisplayFormat>("setDisplayFormat").create();
  // bool calendarPopup() const;
  binder.fun<bool, &QDateTimeEdit::calendarPopup>("calendarPopup").create();
  // void setCalendarPopup(bool);
  binder.void_fun<bool, &QDateTimeEdit::setCalendarPopup>("setCalendarPopup").create();
  // Qt::TimeSpec timeSpec() const;
  binder.fun<Qt::TimeSpec, &QDateTimeEdit::timeSpec>("timeSpec").create();
  // void setTimeSpec(Qt::TimeSpec);
  binder.void_fun<Qt::TimeSpec, &QDateTimeEdit::setTimeSpec>("setTimeSpec").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QDateTimeEdit::sizeHint>("sizeHint").create();
  // void clear();
  binder.void_fun<&QDateTimeEdit::clear>("clear").create();
  // void stepBy(int);
  binder.void_fun<int, &QDateTimeEdit::stepBy>("stepBy").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // void dateTimeChanged(const QDateTime &);
  binder.sigs().add<const QDateTime &>("dateTimeChanged", "dateTimeChanged(const QDateTime &)");
  // void timeChanged(const QTime &);
  binder.sigs().add<const QTime &>("timeChanged", "timeChanged(const QTime &)");
  // void dateChanged(const QDate &);
  binder.sigs().add<const QDate &>("dateChanged", "dateChanged(const QDate &)");
  // void setDateTime(const QDateTime &);
  binder.void_fun<const QDateTime &, &QDateTimeEdit::setDateTime>("setDateTime").create();
  // void setDate(const QDate &);
  binder.void_fun<const QDate &, &QDateTimeEdit::setDate>("setDate").create();
  // void setTime(const QTime &);
  binder.void_fun<const QTime &, &QDateTimeEdit::setTime>("setTime").create();

  date_time_edit.engine()->registerQtType(&QDateTimeEdit::staticMetaObject, date_time_edit.id());
}


static void register_time_edit_class(script::Namespace ns)
{
  using namespace script;

  Class time_edit = ns.newClass("TimeEdit").setId(script::Type::QTimeEdit)
    .setBase(script::Type::QDateTimeEdit).get();

  binding::ClassBinder<QTimeEdit> binder{ time_edit, &QTimeEdit::staticMetaObject };

  // QTimeEdit(QWidget *);
  binder.ctor<QWidget *>().create();
  // QTimeEdit(const QTime &, QWidget *);
  binder.ctor<const QTime &, QWidget *>().create();
  // ~QTimeEdit();
  binder.dtor().create();
  // void userTimeChanged(const QTime &);
  binder.sigs().add<const QTime &>("userTimeChanged", "userTimeChanged(const QTime &)");

  time_edit.engine()->registerQtType(&QTimeEdit::staticMetaObject, time_edit.id());
}


static void register_date_edit_class(script::Namespace ns)
{
  using namespace script;

  Class date_edit = ns.newClass("DateEdit").setId(script::Type::QDateEdit)
    .setBase(script::Type::QDateTimeEdit).get();

  binding::ClassBinder<QDateEdit> binder{ date_edit, &QDateEdit::staticMetaObject };

  // QDateEdit(QWidget *);
  binder.ctor<QWidget *>().create();
  // QDateEdit(const QDate &, QWidget *);
  binder.ctor<const QDate &, QWidget *>().create();
  // ~QDateEdit();
  binder.dtor().create();
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
  // QDateTimeEdit& newDateTimeEdit(QWidget*);
  NewFunction(binder).add<QDateTimeEdit, QWidget*>("newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QDateTime&, QWidget*);
  NewFunction(binder).add<QDateTimeEdit, const QDateTime&, QWidget*>("newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QDate&, QWidget*);
  NewFunction(binder).add<QDateTimeEdit, const QDate&, QWidget*>("newDateTimeEdit");
  // QDateTimeEdit& newDateTimeEdit(const QTime&, QWidget*);
  NewFunction(binder).add<QDateTimeEdit, const QTime&, QWidget*>("newDateTimeEdit");
  // QDateEdit& newDateEdit(QWidget*);
  NewFunction(binder).add<QDateEdit, QWidget*>("newDateEdit");
  // QDateEdit& newDateEdit(const QDate&, QWidget*);
  NewFunction(binder).add<QDateEdit, const QDate&, QWidget*>("newDateEdit");
  // QTimeEdit& newTimeEdit(QWidget*);
  NewFunction(binder).add<QTimeEdit, QWidget*>("newTimeEdit");
  // QTimeEdit& newTimeEdit(const QTime&, QWidget*);
  NewFunction(binder).add<QTimeEdit, const QTime&, QWidget*>("newTimeEdit");
}

