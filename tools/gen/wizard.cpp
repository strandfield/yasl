// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizard.h"

#include "generatepage.h"
#include "selectinputspage.h"
#include "startprojectpage.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>

Wizard::Wizard()
{
  setWindowTitle("Yasl Binding Generator");

  this->pages.startProject = new StartProjectPage();
  this->pages.selectInputs = new SelectInputsPage();
  this->pages.generate = new GeneratePage();

  addPage(this->pages.startProject);
  addPage(this->pages.selectInputs);
  addPage(this->pages.generate);
}

Wizard::~Wizard()
{

}

void Wizard::setDatabasePath(const QString & path)
{
  mFields.databasePath = path;

  QFile file{ path };
  if (!file.exists() || !file.open(QIODevice::ReadOnly))
  {
    auto & db = getDatabase();
    db["headers"] = QJsonObject();
    return;
  }
  
  QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
  mFields.database = doc.object();
  file.close();
}

void Wizard::setDatabase(const QJsonObject & obj)
{
  mFields.database = obj;
}

void Wizard::saveDatabase()
{
  if (mFields.databasePath.isEmpty())
    return;

  QFile file{ mFields.databasePath };
  if (!file.open(QIODevice::WriteOnly))
  {
    qDebug() << "Could not save database";
    return;
  }

  file.write(QJsonDocument{ mFields.database }.toJson());
  file.close();
}

QJsonObject & Wizard::getDatabase()
{
  return mFields.database;
}
