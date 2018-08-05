// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizards/importwizard.h"

#include "wizards/import/importpage.h"
#include "wizards/import/selectinputspage.h"
#include "wizards/import/startimportpage.h"

#include <QDebug>

ImportWizard::ImportWizard(ProjectRef pro)
  : mProject(pro)
{
  setWindowTitle("Import C++ symbols");

  mFields.importedSymbols = ProjectRef::create();

  this->pages.startProject = new StartImportPage();
  this->pages.selectInputs = new SelectInputsPage();
  this->pages.generate = new ImportPage();

  addPage(this->pages.startProject);
  addPage(this->pages.selectInputs);
  addPage(this->pages.generate);
}

ImportWizard::~ImportWizard()
{

}
