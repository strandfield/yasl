// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/wizard.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/core/variant.h"
#include "yasl/gui/pixmap.h"
#include "yasl/widgets/widget.h"
#include "yasl/widgets/wizard.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_wizard_wizard_button_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_button = wizard.newEnum("WizardButton").setId(script::Type::QWizardWizardButton).get();

  wizard_button.addValue("BackButton", QWizard::BackButton);
  wizard_button.addValue("NextButton", QWizard::NextButton);
  wizard_button.addValue("CommitButton", QWizard::CommitButton);
  wizard_button.addValue("FinishButton", QWizard::FinishButton);
  wizard_button.addValue("CancelButton", QWizard::CancelButton);
  wizard_button.addValue("HelpButton", QWizard::HelpButton);
  wizard_button.addValue("CustomButton1", QWizard::CustomButton1);
  wizard_button.addValue("CustomButton2", QWizard::CustomButton2);
  wizard_button.addValue("CustomButton3", QWizard::CustomButton3);
  wizard_button.addValue("Stretch", QWizard::Stretch);
  wizard_button.addValue("NoButton", QWizard::NoButton);
  wizard_button.addValue("NStandardButtons", QWizard::NStandardButtons);
  wizard_button.addValue("NButtons", QWizard::NButtons);
}


static void register_wizard_wizard_pixmap_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_pixmap = wizard.newEnum("WizardPixmap").setId(script::Type::QWizardWizardPixmap).get();

  wizard_pixmap.addValue("WatermarkPixmap", QWizard::WatermarkPixmap);
  wizard_pixmap.addValue("LogoPixmap", QWizard::LogoPixmap);
  wizard_pixmap.addValue("BannerPixmap", QWizard::BannerPixmap);
  wizard_pixmap.addValue("BackgroundPixmap", QWizard::BackgroundPixmap);
  wizard_pixmap.addValue("NPixmaps", QWizard::NPixmaps);
}


static void register_wizard_wizard_style_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_style = wizard.newEnum("WizardStyle").setId(script::Type::QWizardWizardStyle).get();

  wizard_style.addValue("ClassicStyle", QWizard::ClassicStyle);
  wizard_style.addValue("ModernStyle", QWizard::ModernStyle);
  wizard_style.addValue("MacStyle", QWizard::MacStyle);
  wizard_style.addValue("AeroStyle", QWizard::AeroStyle);
  wizard_style.addValue("NStyles", QWizard::NStyles);
}


static void register_wizard_wizard_option_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_option = wizard.newEnum("WizardOption").setId(script::Type::QWizardWizardOption).get();

  register_qflags_type<QWizard::WizardOption>(wizard, "WizardOptions", script::Type::QWizardWizardOptions);
  wizard_option.addValue("IndependentPages", QWizard::IndependentPages);
  wizard_option.addValue("IgnoreSubTitles", QWizard::IgnoreSubTitles);
  wizard_option.addValue("ExtendedWatermarkPixmap", QWizard::ExtendedWatermarkPixmap);
  wizard_option.addValue("NoDefaultButton", QWizard::NoDefaultButton);
  wizard_option.addValue("NoBackButtonOnStartPage", QWizard::NoBackButtonOnStartPage);
  wizard_option.addValue("NoBackButtonOnLastPage", QWizard::NoBackButtonOnLastPage);
  wizard_option.addValue("DisabledBackButtonOnLastPage", QWizard::DisabledBackButtonOnLastPage);
  wizard_option.addValue("HaveNextButtonOnLastPage", QWizard::HaveNextButtonOnLastPage);
  wizard_option.addValue("HaveFinishButtonOnEarlyPages", QWizard::HaveFinishButtonOnEarlyPages);
  wizard_option.addValue("NoCancelButton", QWizard::NoCancelButton);
  wizard_option.addValue("CancelButtonOnLeft", QWizard::CancelButtonOnLeft);
  wizard_option.addValue("HaveHelpButton", QWizard::HaveHelpButton);
  wizard_option.addValue("HelpButtonOnRight", QWizard::HelpButtonOnRight);
  wizard_option.addValue("HaveCustomButton1", QWizard::HaveCustomButton1);
  wizard_option.addValue("HaveCustomButton2", QWizard::HaveCustomButton2);
  wizard_option.addValue("HaveCustomButton3", QWizard::HaveCustomButton3);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  wizard_option.addValue("NoCancelButtonOnLastPage", QWizard::NoCancelButtonOnLastPage);
#endif
}


static void register_wizard_class(script::Namespace ns)
{
  using namespace script;

  Class wizard = ns.newClass("Wizard").setId(script::Type::QWizard)
    .setBase(script::Type::QDialog).get();

  register_wizard_wizard_button_enum(wizard);
  register_wizard_wizard_pixmap_enum(wizard);
  register_wizard_wizard_style_enum(wizard);
  register_wizard_wizard_option_enum(wizard);

  // QWizard(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: QWizard(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // ~QWizard();
  bind::destructor<QWizard>(wizard).create();
  // int addPage(QWizardPage *);
  /// TODO: int addPage(QWizardPage *);
  // void setPage(int, QWizardPage *);
  /// TODO: void setPage(int, QWizardPage *);
  // void removePage(int);
  bind::void_member_function<QWizard, int, &QWizard::removePage>(wizard, "removePage").create();
  // QWizardPage * page(int) const;
  /// TODO: QWizardPage * page(int) const;
  // bool hasVisitedPage(int) const;
  bind::member_function<QWizard, bool, int, &QWizard::hasVisitedPage>(wizard, "hasVisitedPage").create();
  // QList<int> visitedPages() const;
  /// TODO: QList<int> visitedPages() const;
  // QList<int> pageIds() const;
  /// TODO: QList<int> pageIds() const;
  // void setStartId(int);
  bind::void_member_function<QWizard, int, &QWizard::setStartId>(wizard, "setStartId").create();
  // int startId() const;
  bind::member_function<QWizard, int, &QWizard::startId>(wizard, "startId").create();
  // QWizardPage * currentPage() const;
  /// TODO: QWizardPage * currentPage() const;
  // int currentId() const;
  bind::member_function<QWizard, int, &QWizard::currentId>(wizard, "currentId").create();
  // bool validateCurrentPage();
  bind::member_function<QWizard, bool, &QWizard::validateCurrentPage>(wizard, "validateCurrentPage").create();
  // int nextId() const;
  bind::member_function<QWizard, int, &QWizard::nextId>(wizard, "nextId").create();
  // void setField(const QString &, const QVariant &);
  bind::void_member_function<QWizard, const QString &, const QVariant &, &QWizard::setField>(wizard, "setField").create();
  // QVariant field(const QString &) const;
  bind::member_function<QWizard, QVariant, const QString &, &QWizard::field>(wizard, "field").create();
  // void setWizardStyle(QWizard::WizardStyle);
  bind::void_member_function<QWizard, QWizard::WizardStyle, &QWizard::setWizardStyle>(wizard, "setWizardStyle").create();
  // QWizard::WizardStyle wizardStyle() const;
  bind::member_function<QWizard, QWizard::WizardStyle, &QWizard::wizardStyle>(wizard, "wizardStyle").create();
  // void setOption(QWizard::WizardOption, bool);
  bind::void_member_function<QWizard, QWizard::WizardOption, bool, &QWizard::setOption>(wizard, "setOption").create();
  // bool testOption(QWizard::WizardOption) const;
  bind::member_function<QWizard, bool, QWizard::WizardOption, &QWizard::testOption>(wizard, "testOption").create();
  // void setOptions(QWizard::WizardOptions);
  bind::void_member_function<QWizard, QWizard::WizardOptions, &QWizard::setOptions>(wizard, "setOptions").create();
  // QWizard::WizardOptions options() const;
  bind::member_function<QWizard, QWizard::WizardOptions, &QWizard::options>(wizard, "options").create();
  // void setButtonText(QWizard::WizardButton, const QString &);
  bind::void_member_function<QWizard, QWizard::WizardButton, const QString &, &QWizard::setButtonText>(wizard, "setButtonText").create();
  // QString buttonText(QWizard::WizardButton) const;
  bind::member_function<QWizard, QString, QWizard::WizardButton, &QWizard::buttonText>(wizard, "buttonText").create();
  // void setButtonLayout(const QList<QWizard::WizardButton> &);
  /// TODO: void setButtonLayout(const QList<QWizard::WizardButton> &);
  // void setButton(QWizard::WizardButton, QAbstractButton *);
  /// TODO: void setButton(QWizard::WizardButton, QAbstractButton *);
  // QAbstractButton * button(QWizard::WizardButton) const;
  /// TODO: QAbstractButton * button(QWizard::WizardButton) const;
  // void setTitleFormat(Qt::TextFormat);
  bind::void_member_function<QWizard, Qt::TextFormat, &QWizard::setTitleFormat>(wizard, "setTitleFormat").create();
  // Qt::TextFormat titleFormat() const;
  bind::member_function<QWizard, Qt::TextFormat, &QWizard::titleFormat>(wizard, "titleFormat").create();
  // void setSubTitleFormat(Qt::TextFormat);
  bind::void_member_function<QWizard, Qt::TextFormat, &QWizard::setSubTitleFormat>(wizard, "setSubTitleFormat").create();
  // Qt::TextFormat subTitleFormat() const;
  bind::member_function<QWizard, Qt::TextFormat, &QWizard::subTitleFormat>(wizard, "subTitleFormat").create();
  // void setPixmap(QWizard::WizardPixmap, const QPixmap &);
  bind::void_member_function<QWizard, QWizard::WizardPixmap, const QPixmap &, &QWizard::setPixmap>(wizard, "setPixmap").create();
  // QPixmap pixmap(QWizard::WizardPixmap) const;
  bind::member_function<QWizard, QPixmap, QWizard::WizardPixmap, &QWizard::pixmap>(wizard, "pixmap").create();
  // void setSideWidget(QWidget *);
  bind::void_member_function<QWizard, QWidget *, &QWizard::setSideWidget>(wizard, "setSideWidget").create();
  // QWidget * sideWidget() const;
  bind::member_function<QWizard, QWidget *, &QWizard::sideWidget>(wizard, "sideWidget").create();
  // void setDefaultProperty(const char *, const char *, const char *);
  /// TODO: void setDefaultProperty(const char *, const char *, const char *);
  // void setVisible(bool);
  bind::void_member_function<QWizard, bool, &QWizard::setVisible>(wizard, "setVisible").create();
  // QSize sizeHint() const;
  bind::member_function<QWizard, QSize, &QWizard::sizeHint>(wizard, "sizeHint").create();
  // void currentIdChanged(int);
  bind::signal<QWizard, int>(wizard, "currentIdChanged", "currentIdChanged(int)");
  // void helpRequested();
  bind::signal<QWizard>(wizard, "helpRequested", "helpRequested()");
  // void customButtonClicked(int);
  bind::signal<QWizard, int>(wizard, "customButtonClicked", "customButtonClicked(int)");
  // void pageAdded(int);
  bind::signal<QWizard, int>(wizard, "pageAdded", "pageAdded(int)");
  // void pageRemoved(int);
  bind::signal<QWizard, int>(wizard, "pageRemoved", "pageRemoved(int)");
  // void back();
  bind::void_member_function<QWizard, &QWizard::back>(wizard, "back").create();
  // void next();
  bind::void_member_function<QWizard, &QWizard::next>(wizard, "next").create();
  // void restart();
  bind::void_member_function<QWizard, &QWizard::restart>(wizard, "restart").create();

  bind::link(wizard, &QWizard::staticMetaObject);
}


static void register_wizard_page_class(script::Namespace ns)
{
  using namespace script;

  Class wizard_page = ns.newClass("WizardPage").setId(script::Type::QWizardPage)
    .setBase(script::Type::QWidget).get();


  // QWizardPage(QWidget * = (QWidget*)nullptr);
  bind::constructor<QWizardPage, QWidget *>(wizard_page)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QWizardPage();
  bind::destructor<QWizardPage>(wizard_page).create();
  // void setTitle(const QString &);
  bind::void_member_function<QWizardPage, const QString &, &QWizardPage::setTitle>(wizard_page, "setTitle").create();
  // QString title() const;
  bind::member_function<QWizardPage, QString, &QWizardPage::title>(wizard_page, "title").create();
  // void setSubTitle(const QString &);
  bind::void_member_function<QWizardPage, const QString &, &QWizardPage::setSubTitle>(wizard_page, "setSubTitle").create();
  // QString subTitle() const;
  bind::member_function<QWizardPage, QString, &QWizardPage::subTitle>(wizard_page, "subTitle").create();
  // void setPixmap(QWizard::WizardPixmap, const QPixmap &);
  bind::void_member_function<QWizardPage, QWizard::WizardPixmap, const QPixmap &, &QWizardPage::setPixmap>(wizard_page, "setPixmap").create();
  // QPixmap pixmap(QWizard::WizardPixmap) const;
  bind::member_function<QWizardPage, QPixmap, QWizard::WizardPixmap, &QWizardPage::pixmap>(wizard_page, "pixmap").create();
  // void setFinalPage(bool);
  bind::void_member_function<QWizardPage, bool, &QWizardPage::setFinalPage>(wizard_page, "setFinalPage").create();
  // bool isFinalPage() const;
  bind::member_function<QWizardPage, bool, &QWizardPage::isFinalPage>(wizard_page, "isFinalPage").create();
  // void setCommitPage(bool);
  bind::void_member_function<QWizardPage, bool, &QWizardPage::setCommitPage>(wizard_page, "setCommitPage").create();
  // bool isCommitPage() const;
  bind::member_function<QWizardPage, bool, &QWizardPage::isCommitPage>(wizard_page, "isCommitPage").create();
  // void setButtonText(QWizard::WizardButton, const QString &);
  bind::void_member_function<QWizardPage, QWizard::WizardButton, const QString &, &QWizardPage::setButtonText>(wizard_page, "setButtonText").create();
  // QString buttonText(QWizard::WizardButton) const;
  bind::member_function<QWizardPage, QString, QWizard::WizardButton, &QWizardPage::buttonText>(wizard_page, "buttonText").create();
  // void initializePage();
  bind::void_member_function<QWizardPage, &QWizardPage::initializePage>(wizard_page, "initializePage").create();
  // void cleanupPage();
  bind::void_member_function<QWizardPage, &QWizardPage::cleanupPage>(wizard_page, "cleanupPage").create();
  // bool validatePage();
  bind::member_function<QWizardPage, bool, &QWizardPage::validatePage>(wizard_page, "validatePage").create();
  // bool isComplete() const;
  bind::member_function<QWizardPage, bool, &QWizardPage::isComplete>(wizard_page, "isComplete").create();
  // int nextId() const;
  bind::member_function<QWizardPage, int, &QWizardPage::nextId>(wizard_page, "nextId").create();
  // void completeChanged();
  bind::signal<QWizardPage>(wizard_page, "completeChanged", "completeChanged()");

  bind::link(wizard_page, &QWizardPage::staticMetaObject);
}


void register_wizard_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_wizard_class(ns);
  register_wizard_page_class(ns);

  // QWizard::WizardOptions operator|(QWizard::WizardOption, QWizard::WizardOption);
  bind::op_bitor<QWizard::WizardOptions, QWizard::WizardOption, QWizard::WizardOption>(ns);
  // QWizard::WizardOptions operator|(QWizard::WizardOption, QWizard::WizardOptions);
  bind::op_bitor<QWizard::WizardOptions, QWizard::WizardOption, QWizard::WizardOptions>(ns);
  // QIncompatibleFlag operator|(QWizard::WizardOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QWizard::WizardOptions::enum_type, int);
}

