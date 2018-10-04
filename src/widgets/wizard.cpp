// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/wizard.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
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

  Enum wizard_button = wizard.Enum("WizardButton").setId(script::Type::QWizardWizardButton).get();

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

  Enum wizard_pixmap = wizard.Enum("WizardPixmap").setId(script::Type::QWizardWizardPixmap).get();

  wizard_pixmap.addValue("WatermarkPixmap", QWizard::WatermarkPixmap);
  wizard_pixmap.addValue("LogoPixmap", QWizard::LogoPixmap);
  wizard_pixmap.addValue("BannerPixmap", QWizard::BannerPixmap);
  wizard_pixmap.addValue("BackgroundPixmap", QWizard::BackgroundPixmap);
  wizard_pixmap.addValue("NPixmaps", QWizard::NPixmaps);
}


static void register_wizard_wizard_style_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_style = wizard.Enum("WizardStyle").setId(script::Type::QWizardWizardStyle).get();

  wizard_style.addValue("ClassicStyle", QWizard::ClassicStyle);
  wizard_style.addValue("ModernStyle", QWizard::ModernStyle);
  wizard_style.addValue("MacStyle", QWizard::MacStyle);
  wizard_style.addValue("AeroStyle", QWizard::AeroStyle);
  wizard_style.addValue("NStyles", QWizard::NStyles);
}


static void register_wizard_wizard_option_enum(script::Class wizard)
{
  using namespace script;

  Enum wizard_option = wizard.Enum("WizardOption").setId(script::Type::QWizardWizardOption).get();

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
  wizard_option.addValue("NoCancelButtonOnLastPage", QWizard::NoCancelButtonOnLastPage);
}


static void register_wizard_class(script::Namespace ns)
{
  using namespace script;

  Class wizard = ns.Class("Wizard").setId(script::Type::QWizard)
    .setBase(script::Type::QDialog).get();

  register_wizard_wizard_button_enum(wizard);
  register_wizard_wizard_pixmap_enum(wizard);
  register_wizard_wizard_style_enum(wizard);
  register_wizard_wizard_option_enum(wizard);
  binding::QClass<QWizard> binder{ wizard, &QWizard::staticMetaObject };

  // QWizard(QWidget *, Qt::WindowFlags);
  /// TODO: QWizard(QWidget *, Qt::WindowFlags);
  // ~QWizard();
  binder.add_dtor();
  // int addPage(QWizardPage *);
  /// TODO: int addPage(QWizardPage *);
  // void setPage(int, QWizardPage *);
  /// TODO: void setPage(int, QWizardPage *);
  // void removePage(int);
  binder.add_void_fun<int, &QWizard::removePage>("removePage");
  // QWizardPage * page(int) const;
  /// TODO: QWizardPage * page(int) const;
  // bool hasVisitedPage(int) const;
  binder.add_fun<bool, int, &QWizard::hasVisitedPage>("hasVisitedPage");
  // QList<int> visitedPages() const;
  /// TODO: QList<int> visitedPages() const;
  // QList<int> pageIds() const;
  /// TODO: QList<int> pageIds() const;
  // void setStartId(int);
  binder.add_void_fun<int, &QWizard::setStartId>("setStartId");
  // int startId() const;
  binder.add_fun<int, &QWizard::startId>("startId");
  // QWizardPage * currentPage() const;
  /// TODO: QWizardPage * currentPage() const;
  // int currentId() const;
  binder.add_fun<int, &QWizard::currentId>("currentId");
  // bool validateCurrentPage();
  binder.add_fun<bool, &QWizard::validateCurrentPage>("validateCurrentPage");
  // int nextId() const;
  binder.add_fun<int, &QWizard::nextId>("nextId");
  // void setField(const QString &, const QVariant &);
  binder.add_void_fun<const QString &, const QVariant &, &QWizard::setField>("setField");
  // QVariant field(const QString &) const;
  binder.add_fun<QVariant, const QString &, &QWizard::field>("field");
  // void setWizardStyle(QWizard::WizardStyle);
  binder.add_void_fun<QWizard::WizardStyle, &QWizard::setWizardStyle>("setWizardStyle");
  // QWizard::WizardStyle wizardStyle() const;
  binder.add_fun<QWizard::WizardStyle, &QWizard::wizardStyle>("wizardStyle");
  // void setOption(QWizard::WizardOption, bool);
  binder.add_void_fun<QWizard::WizardOption, bool, &QWizard::setOption>("setOption");
  // bool testOption(QWizard::WizardOption) const;
  binder.add_fun<bool, QWizard::WizardOption, &QWizard::testOption>("testOption");
  // void setOptions(QWizard::WizardOptions);
  binder.add_void_fun<QWizard::WizardOptions, &QWizard::setOptions>("setOptions");
  // QWizard::WizardOptions options() const;
  binder.add_fun<QWizard::WizardOptions, &QWizard::options>("options");
  // void setButtonText(QWizard::WizardButton, const QString &);
  binder.add_void_fun<QWizard::WizardButton, const QString &, &QWizard::setButtonText>("setButtonText");
  // QString buttonText(QWizard::WizardButton) const;
  binder.add_fun<QString, QWizard::WizardButton, &QWizard::buttonText>("buttonText");
  // void setButtonLayout(const QList<QWizard::WizardButton> &);
  /// TODO: void setButtonLayout(const QList<QWizard::WizardButton> &);
  // void setButton(QWizard::WizardButton, QAbstractButton *);
  /// TODO: void setButton(QWizard::WizardButton, QAbstractButton *);
  // QAbstractButton * button(QWizard::WizardButton) const;
  /// TODO: QAbstractButton * button(QWizard::WizardButton) const;
  // void setTitleFormat(Qt::TextFormat);
  binder.add_void_fun<Qt::TextFormat, &QWizard::setTitleFormat>("setTitleFormat");
  // Qt::TextFormat titleFormat() const;
  binder.add_fun<Qt::TextFormat, &QWizard::titleFormat>("titleFormat");
  // void setSubTitleFormat(Qt::TextFormat);
  binder.add_void_fun<Qt::TextFormat, &QWizard::setSubTitleFormat>("setSubTitleFormat");
  // Qt::TextFormat subTitleFormat() const;
  binder.add_fun<Qt::TextFormat, &QWizard::subTitleFormat>("subTitleFormat");
  // void setPixmap(QWizard::WizardPixmap, const QPixmap &);
  binder.add_void_fun<QWizard::WizardPixmap, const QPixmap &, &QWizard::setPixmap>("setPixmap");
  // QPixmap pixmap(QWizard::WizardPixmap) const;
  binder.add_fun<QPixmap, QWizard::WizardPixmap, &QWizard::pixmap>("pixmap");
  // void setSideWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QWizard::setSideWidget>("setSideWidget");
  // QWidget * sideWidget() const;
  binder.add_fun<QWidget *, &QWizard::sideWidget>("sideWidget");
  // void setDefaultProperty(const char *, const char *, const char *);
  /// TODO: void setDefaultProperty(const char *, const char *, const char *);
  // void setVisible(bool);
  binder.add_void_fun<bool, &QWizard::setVisible>("setVisible");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QWizard::sizeHint>("sizeHint");
  // void currentIdChanged(int);
  binder.sigs().add<int>("currentIdChanged", "currentIdChanged(int)");
  // void helpRequested();
  binder.sigs().add("helpRequested", "helpRequested()");
  // void customButtonClicked(int);
  binder.sigs().add<int>("customButtonClicked", "customButtonClicked(int)");
  // void pageAdded(int);
  binder.sigs().add<int>("pageAdded", "pageAdded(int)");
  // void pageRemoved(int);
  binder.sigs().add<int>("pageRemoved", "pageRemoved(int)");
  // void back();
  binder.add_void_fun<&QWizard::back>("back");
  // void next();
  binder.add_void_fun<&QWizard::next>("next");
  // void restart();
  binder.add_void_fun<&QWizard::restart>("restart");

  wizard.engine()->registerQtType(&QWizard::staticMetaObject, wizard.id());
}


static void register_wizard_page_class(script::Namespace ns)
{
  using namespace script;

  Class wizard_page = ns.Class("WizardPage").setId(script::Type::QWizardPage)
    .setBase(script::Type::QWidget).get();

  binding::QClass<QWizardPage> binder{ wizard_page, &QWizardPage::staticMetaObject };

  // QWizardPage(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QWizardPage();
  binder.add_dtor();
  // void setTitle(const QString &);
  binder.add_void_fun<const QString &, &QWizardPage::setTitle>("setTitle");
  // QString title() const;
  binder.add_fun<QString, &QWizardPage::title>("title");
  // void setSubTitle(const QString &);
  binder.add_void_fun<const QString &, &QWizardPage::setSubTitle>("setSubTitle");
  // QString subTitle() const;
  binder.add_fun<QString, &QWizardPage::subTitle>("subTitle");
  // void setPixmap(QWizard::WizardPixmap, const QPixmap &);
  binder.add_void_fun<QWizard::WizardPixmap, const QPixmap &, &QWizardPage::setPixmap>("setPixmap");
  // QPixmap pixmap(QWizard::WizardPixmap) const;
  binder.add_fun<QPixmap, QWizard::WizardPixmap, &QWizardPage::pixmap>("pixmap");
  // void setFinalPage(bool);
  binder.add_void_fun<bool, &QWizardPage::setFinalPage>("setFinalPage");
  // bool isFinalPage() const;
  binder.add_fun<bool, &QWizardPage::isFinalPage>("isFinalPage");
  // void setCommitPage(bool);
  binder.add_void_fun<bool, &QWizardPage::setCommitPage>("setCommitPage");
  // bool isCommitPage() const;
  binder.add_fun<bool, &QWizardPage::isCommitPage>("isCommitPage");
  // void setButtonText(QWizard::WizardButton, const QString &);
  binder.add_void_fun<QWizard::WizardButton, const QString &, &QWizardPage::setButtonText>("setButtonText");
  // QString buttonText(QWizard::WizardButton) const;
  binder.add_fun<QString, QWizard::WizardButton, &QWizardPage::buttonText>("buttonText");
  // void initializePage();
  binder.add_void_fun<&QWizardPage::initializePage>("initializePage");
  // void cleanupPage();
  binder.add_void_fun<&QWizardPage::cleanupPage>("cleanupPage");
  // bool validatePage();
  binder.add_fun<bool, &QWizardPage::validatePage>("validatePage");
  // bool isComplete() const;
  binder.add_fun<bool, &QWizardPage::isComplete>("isComplete");
  // int nextId() const;
  binder.add_fun<int, &QWizardPage::nextId>("nextId");
  // void completeChanged();
  binder.sigs().add("completeChanged", "completeChanged()");

  wizard_page.engine()->registerQtType(&QWizardPage::staticMetaObject, wizard_page.id());
}


void register_wizard_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_wizard_class(ns);
  register_wizard_page_class(ns);
  binding::Namespace binder{ ns };

  // QWizard::WizardOptions operator|(QWizard::WizardOption, QWizard::WizardOption);
  binder.operators().or<QWizard::WizardOptions, QWizard::WizardOption, QWizard::WizardOption>();
  // QWizard::WizardOptions operator|(QWizard::WizardOption, QWizard::WizardOptions);
  binder.operators().or<QWizard::WizardOptions, QWizard::WizardOption, QWizard::WizardOptions>();
  // QIncompatibleFlag operator|(QWizard::WizardOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QWizard::WizardOptions::enum_type, int);
}

