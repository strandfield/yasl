// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_STARTIMPORTPAGE_H
#define YASL_META_STARTIMPORTPAGE_H

#include <QWizardPage>

class StartImportPage_IncludeDirsGroupBox;
class StartImportPage_PropertiesGroupBox;

class StartImportPage : public QWizardPage
{
  Q_OBJECT
public:
  StartImportPage();

protected:
  bool isComplete() const override;
  int nextId() const override;
  bool validatePage() override;

private Q_SLOTS:
  void addIncludeDir();
  void removeIncludeDir();

private:
  typedef StartImportPage_IncludeDirsGroupBox IncludeDirsGroupBox;
  typedef StartImportPage_PropertiesGroupBox PropertiesGroupBox;

  IncludeDirsGroupBox *mIncludeDirsGroupBox;
  PropertiesGroupBox *mPropertiesGroupBox;
};

#endif // YASL_META_STARTIMPORTPAGE_H
