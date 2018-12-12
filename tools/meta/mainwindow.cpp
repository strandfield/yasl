// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "mainwindow.h"

#include "generator.h"

#include "dialogs/newtypedialog.h"

#include "widgets/moduletreewidget.h"
#include "widgets/typetreewidget.h"

#include "wizards/importwizard.h"

#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSettings>
#include <QTabWidget>

MainWindow::MainWindow()
{
  mSettings = new QSettings("settings.ini", QSettings::IniFormat, this);

  if (mSettings->contains("lastproject"))
  {
    mProject = Project::load(mSettings->value("lastproject").toString());
    if (mProject == nullptr)
      mSettings->remove("lastproject");
  }
  
  if(mProject == nullptr)
    mProject = ProjectRef::create();

  mTabWidget = new QTabWidget();

  mTypeTreeWidget = new TypeTreeWidget(mProject);
  mModuleTreeWidget = new ModuleTreeWidget(mProject);

  mTabWidget->addTab(mTypeTreeWidget, "Types");
  mTabWidget->addTab(mModuleTreeWidget, "Modules");

  setCentralWidget(mTabWidget);

  menuBar()->addAction("Open", this, SLOT(openProject()));
  menuBar()->addAction("Save", this, SLOT(saveProject()));
  menuBar()->addAction("New type", this, SLOT(createNewType()));
#ifdef YASL_META_HAS_LIBCLANG
  menuBar()->addAction("Import", this, SLOT(importCpp()));
#endif // YASL_META_HAS_LIBCLANG
  menuBar()->addAction("Generate", this, SLOT(generateBinding()));
}

void MainWindow::openProject()
{
  QString path = QFileDialog::getOpenFileName(this, "Open project", QString(), QString("Meta project (*.json *.yaml)"));
  if (path.isEmpty())
    return;

  mProject = Project::load(path);
  if (mProject == nullptr)
  {
    QMessageBox::information(this, "Open project", "Failed to open project", QMessageBox::Ok);
    return;
  }

  mSettings->setValue("lastproject", path);

  mTypeTreeWidget->setProject(mProject);
  mModuleTreeWidget->setProject(mProject);
}

void MainWindow::saveProject()
{
  QString path = mSettings->value("lastproject").toString();
  if (path.isEmpty())
    path = QFileDialog::getSaveFileName(this, "Save", QString(), QString("Meta project (*.json)"));

  if (path.isEmpty())
    return;

  mProject->save(path);
  mSettings->setValue("lastproject", path);
}

void MainWindow::createNewType()
{
  auto *dialog = new NewTypeDialog(this);
  int result = dialog->exec();
  dialog->deleteLater();
  if (result != QDialog::Accepted)
    return;

  Type t = dialog->getType();
  Type::Category cat = dialog->getCategory();

  if (cat == Type::FundamentalType)
    mProject->types.fundamentals.append(t);
  else if (cat == Type::EnumType)
    mProject->types.enums.append(t);
  else if (cat == Type::ClassType)
    mProject->types.classes.append(t);

  mTypeTreeWidget->fetchNewNodes();
}

void MainWindow::importCpp()
{
  auto *wizard = new ImportWizard(mProject);
  wizard->exec();
  wizard->deleteLater();

  mTypeTreeWidget->fetchNewNodes();
  mModuleTreeWidget->fetchNewNodes();
}

void MainWindow::generateBinding()
{
  saveProject();

  QString path = mSettings->value("generatedir").toString();
  if (path.isEmpty())
    path = QFileDialog::getExistingDirectory(this, "Save directory");
  
  if (path.isEmpty())
    return;

  mSettings->setValue("generatedir", path);

  QProgressDialog progress("Generating files...", "Abort", 0, mProject->fileCount(), this);
  progress.setWindowTitle("Binding generation");
  progress.setWindowModality(Qt::WindowModal);
  progress.setMinimumDuration(2000);

  Generator gen{ path };
  gen.setProgressCallback([&progress](const QString & filename) -> bool {
    progress.setValue(progress.value() + 1);
    return !progress.wasCanceled();
  });
  gen.generate(mProject);
}

void MainWindow::showEvent(QShowEvent *e)
{
  if (mSettings->contains("geometry"))
    restoreGeometry(mSettings->value("geometry").toByteArray());

  if (mSettings->contains("windowState"))
    restoreState(mSettings->value("windowState").toByteArray());

  QMainWindow::showEvent(e);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
  mSettings->setValue("geometry", saveGeometry());
  mSettings->setValue("windowState", saveState());
  QMainWindow::closeEvent(e);
}