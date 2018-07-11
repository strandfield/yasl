// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GEN_STARTPROJECTPAGE_H
#define YASL_GEN_STARTPROJECTPAGE_H

#include <QWizardPage>

class StartProjectPage_DatabaseGroupBox;
class StartProjectPage_TypeGroupBox;
class StartProjectPage_OpenExistingProjectGroupBox;
class StartProjectPage_NewProjectGroupBox;

class StartProjectPage : public QWizardPage
{
  Q_OBJECT
public:
  StartProjectPage();

protected:
  bool isComplete() const override;
  int nextId() const override;
  bool validatePage() override;

private Q_SLOTS:
  void openExistingProject();
  void addIncludeDir();
  void removeIncludeDir();

private:
  typedef StartProjectPage_DatabaseGroupBox DatabaseGroupBox;
  typedef StartProjectPage_TypeGroupBox TypeGroupBox;
  typedef StartProjectPage_OpenExistingProjectGroupBox OpenExistingProjectGroupBox;
  typedef StartProjectPage_NewProjectGroupBox NewProjectGroupBox;

  DatabaseGroupBox *mDatabaseGroupBox;
  TypeGroupBox *mProjectTypeGroupBox;
  OpenExistingProjectGroupBox *mOpenExistingProjectGroupBox;
  NewProjectGroupBox *mNewProjectGroupBox;
};

#endif // YASL_GEN_STARTPROJECTPAGE_H
