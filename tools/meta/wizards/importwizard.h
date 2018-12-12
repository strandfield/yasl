// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_IMPORTWIZARD_H
#define YASL_META_IMPORTWIZARD_H

#include <QWizard>

#include "project.h"

class ImportPage;
class SelectInputsPage;
class StartImportPage;

class ImportWizard : public QWizard
{
  Q_OBJECT
public:
  ImportWizard(ProjectRef pro);
  ~ImportWizard();

  enum PageIds {
    StartImportPageId = 0,
    SelectInputsPageId,
    FinalizeImportPageId,
  };

  struct Fields
  {
    QStringList includeDirectories;
    QString moduleName;
    QStringList fileList;
    QtVersion version;
    ProjectRef importedSymbols;
  };

  inline static ImportWizard * get(QWizard *w) { return static_cast<ImportWizard*>(w); }

  Fields & fields() { return mFields; }
  ProjectRef & project() { return mProject; }

private:
  struct
  {
    StartImportPage *startProject;
    SelectInputsPage *selectInputs;
    ImportPage *generate;
  } pages;

  Fields mFields;
  ProjectRef mProject;
};

#endif // YASL_METAWIZARD_H
