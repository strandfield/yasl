// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_MAINWINDOW_H
#define YASL_META_MAINWINDOW_H

#include <QMainWindow>

#include "project.h"

class ModuleTreeWidget;
class TypeTreeWidget;

class QSettings;
class QTabWidget;

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow();
  ~MainWindow() = default;

protected Q_SLOTS:
  void openProject();
  void saveProject();
  void createNewType();
  void importCpp();
  void generateBinding();

protected:
  void showEvent(QShowEvent *e);
  void closeEvent(QCloseEvent *e);

private:
  ProjectRef mProject;
  QSettings *mSettings;

  QTabWidget *mTabWidget;
  TypeTreeWidget *mTypeTreeWidget;
  ModuleTreeWidget *mModuleTreeWidget;
};

#endif // YASL_META_MAINWINDOW_H
