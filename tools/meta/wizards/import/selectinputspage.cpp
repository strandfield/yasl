// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizards/import/selectinputspage.h"

#include "wizards/importwizard.h"

#include <QDir>
#include <QFileInfo>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <QDebug>

SelectInputsPage::SelectInputsPage()
{
  setTitle("Select source files");

  QVBoxLayout *l = new QVBoxLayout(this);

  sourceTreeWidget = new QTreeWidget();
  sourceTreeWidget->setColumnCount(2);
  sourceTreeWidget->setColumnHidden(1, true);
  sourceTreeWidget->setHeaderLabels(QStringList{ QString{"Name"}, QString{"Absolute path"} });
  l->addWidget(sourceTreeWidget);

  unselectAllButton = new QPushButton("Unselect all");
  l->addWidget(unselectAllButton, 0, Qt::AlignRight);

  connect(unselectAllButton, SIGNAL(clicked()), this, SLOT(unselectAll()));

}

void SelectInputsPage::initializePage()
{
  auto & fields = ImportWizard::get(wizard())->fields();

  for (const auto & dir : fields.includeDirectories)
  {
    fetchFiles(sourceTreeWidget->invisibleRootItem(), dir);
  }
}

bool SelectInputsPage::validatePage()
{
  auto & fields = ImportWizard::get(wizard())->fields();

  fields.fileList.clear();
  getSelectedFiles(fields.fileList, sourceTreeWidget->invisibleRootItem());

  return true;
}

void SelectInputsPage::unselectAll()
{
  unselectAll(sourceTreeWidget->invisibleRootItem());
}

void SelectInputsPage::unselectAll(QTreeWidgetItem *item)
{
  item->setCheckState(0, Qt::Unchecked);
  for (int i(0); i < item->childCount(); ++i)
    unselectAll(item->child(i));
}

void SelectInputsPage::getSelectedFiles(QStringList & result, QTreeWidgetItem *item)
{
  if (item->childCount() > 0)
  {
    for (int i(0); i < item->childCount(); ++i)
      getSelectedFiles(result, item->child(i));
  }
  else
  {
    if (item->checkState(0) == Qt::Checked)
      result.push_back(item->text(1));
  }
}

int SelectInputsPage::fetchFiles(QTreeWidgetItem *parent, const QString & dirpath)
{
  QDir dir{ dirpath };
  QFileInfoList files = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name);

  int num = 0;
  for (const auto & f : files)
  {
    if (f.isDir())
    {
      QTreeWidgetItem *dir_item = new QTreeWidgetItem(QStringList{ f.fileName(), f.absoluteFilePath() });
      dir_item->setFlags(dir_item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
      int n = fetchFiles(dir_item, f.absoluteFilePath());
      if (n == 0)
        delete dir_item;
      else
        parent->addChild(dir_item);
    }
    else
    {
      if (f.suffix() == "h")
      {
        num += 1;
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList{ f.fileName(), f.absoluteFilePath() });
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(0, Qt::Checked);
        parent->addChild(item);
      }
    }
  }

  return num;
}
