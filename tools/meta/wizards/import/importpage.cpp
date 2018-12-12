// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizards/import/importpage.h"

#include "cppparser.h"

#include "widgets/moduletreewidget.h"
#include "wizards/importwizard.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QDebug>

ImportPage::ImportPage()
{
  setTitle("Select symbols to import");

  QVBoxLayout *l = new QVBoxLayout(this);

  QHBoxLayout *hl = new QHBoxLayout();
  l->addLayout(hl);
  hl->addWidget(new QLabel("Select the elements you want to process:"));
  hl->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

  selectionTreeWidget = new ModuleTreeWidget(nullptr);
  l->addWidget(selectionTreeWidget);
}


void ImportPage::cleanupPage()
{
  auto & fields = ImportWizard::get(wizard())->fields();
  fields.importedSymbols->types.classes.clear();
  fields.importedSymbols->types.enums.clear();
  fields.importedSymbols->modules.clear();

  selectionTreeWidget->clear();

  QWizardPage::cleanupPage();
}

void ImportPage::initializePage()
{
  auto & fields = ImportWizard::get(wizard())->fields(); 

  QStringList modules = fields.moduleName.split(".");
  ModuleRef m = fields.importedSymbols->get<Module>(modules.takeFirst());
  while (!modules.isEmpty())
  {
    m = m->get<Module>(modules.takeFirst());
  }

#ifdef YASL_META_HAS_LIBCLANG
  CppParser parser{ fields.importedSymbols };
  parser.setIncludeDirectories(fields.includeDirectories);
  parser.setVersion(fields.version);

  for (const auto & f : fields.fileList)
    parser.parse(f, m);
#endif // YASL_META_HAS_LIBCLANG

  selectionTreeWidget->setProject(fields.importedSymbols);
  selectionTreeWidget->setShowCheckboxes(true);
}

bool ImportPage::validatePage()
{
  auto & fields = ImportWizard::get(wizard())->fields();

  fields.importedSymbols->removeUncheckedSymbols();
  fields.importedSymbols->fetchTypes();

  ProjectRef pro = ImportWizard::get(wizard())->project();
  pro->importSymbols(fields.importedSymbols);

  return true;
}
