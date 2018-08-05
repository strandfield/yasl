// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_IMPORTPAGE_H
#define YASL_META_IMPORTPAGE_H

#include <QWizardPage>

#include "project.h"

class ModuleTreeWidget;

class ImportPage : public QWizardPage
{
  Q_OBJECT
public:
  ImportPage();

protected:
  void cleanupPage() override;
  void initializePage() override;
  bool validatePage() override;

private:
  ModuleTreeWidget *selectionTreeWidget;
};

#endif // YASL_META_IMPORTPAGE_H
