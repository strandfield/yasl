// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GEN_WIZARD_H
#define YASL_GEN_WIZARD_H

#include <QWizard>

#include "project.h"

#include <QJsonObject>

class GeneratePage;
class SelectInputsPage;
class StartProjectPage;

class Wizard : public QWizard
{
  Q_OBJECT
public:
  Wizard();
  ~Wizard();

  enum PageIds {
    StartProjectPageId = 0,
    SelectInputsPageId,
    GeneratePageId,
  };

  struct Fields
  {
    bool openExistingProject;
    QString existingProjectPath;
    QString databasePath;
    QStringList includeDirectories;
    QStringList fileList;
    QJsonObject database;
  };

  inline static Wizard * get(QWizard *w) { return static_cast<Wizard*>(w); }

  Fields & fields() { return mFields; }
  Project & project() { return mProject; }

  void setDatabasePath(const QString & path);
  void setDatabase(const QJsonObject & obj);
  void saveDatabase();
  QJsonObject & getDatabase();

private:
  struct
  {
    StartProjectPage *startProject;
    SelectInputsPage *selectInputs;
    GeneratePage *generate;
  } pages;

  Fields mFields;
  Project mProject;
};

#endif // YASL_GEN_WIZARD_H
