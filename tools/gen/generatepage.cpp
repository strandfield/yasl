// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "generatepage.h"

#include "generator.h"
#include "wizard.h"

#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <QDebug>

GeneratePage::GeneratePage()
{
  setTitle("Generate binding");

  QVBoxLayout *l = new QVBoxLayout(this);

  QHBoxLayout *hl = new QHBoxLayout();
  l->addLayout(hl);
  hl->addWidget(new QLabel("Select the elements you want to process:"));
  hl->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
  importSettingsButton = new QPushButton("Import from project");
  importSettingsButton->setEnabled(false);
  hl->addWidget(importSettingsButton);

  selectionTreeWidget = new QTreeWidget();
  selectionTreeWidget->setColumnCount(2);
  selectionTreeWidget->setHeaderLabels(QStringList{ QString{ "Symbol" }, "Macro" });
  l->addWidget(selectionTreeWidget);

  connect(selectionTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem *, int)), this, SLOT(updateItem(QTreeWidgetItem*, int)));
}


void GeneratePage::cleanupPage()
{
  Project & pro = Wizard::get(wizard())->project();
  pro.includeDirs.clear();
  pro.files.clear();

  selectionTreeWidget->clear();

  QWizardPage::cleanupPage();
}

void GeneratePage::initializePage()
{
  auto & fields = Wizard::get(wizard())->fields();

  Project & pro = Wizard::get(wizard())->project();
  pro.includeDirs = fields.includeDirectories;
  pro.addFiles(fields.fileList);
  
  for(const auto & n : pro.files)
    fillTreeWidget(selectionTreeWidget->invisibleRootItem(), n);
}

bool GeneratePage::validatePage()
{
  Project & pro = Wizard::get(wizard())->project();

  Generator gen{ Wizard::get(wizard())->getDatabase() };
  gen.generate(pro);

  Wizard::get(wizard())->saveDatabase();

  auto result = QMessageBox::information(this, "Generation completed", "Do you want to exit ?", QMessageBox::Yes, QMessageBox::No);

  return result == QMessageBox::Yes;
}

void GeneratePage::fillTreeWidget(QTreeWidgetItem *parent, gen::NodeRef node)
{
  QTreeWidgetItem *item = new QTreeWidgetItem(QStringList{ node->displayedName() });
  item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
  item->setCheckState(0, node->checkState);
  item->setData(0, ProjectNodeRole, QVariant::fromValue<QSharedPointer<gen::Node>>(node));

  if (node->is<gen::File>())
  {
    item->setIcon(0, QIcon(":/assets/namespace.png"));

    gen::FileRef file = qSharedPointerCast<gen::File>(node);

    for (const auto & n : file->globalNamespace.enums)
      fillTreeWidget(item, n);

    for (const auto & f : file->globalNamespace.functions)
      fillTreeWidget(item, f);
    
    for (const auto & n : file->globalNamespace.classes)
      fillTreeWidget(item, n);

    for (const auto & n : file->globalNamespace.namespaces)
      fillTreeWidget(item, n);
  }
  else if (node->is<gen::Namespace>())
  {
    item->setIcon(0, QIcon(":/assets/namespace.png"));

    gen::NamespaceRef ns = qSharedPointerCast<gen::Namespace>(node);

    for (const auto & n : ns->enums)
      fillTreeWidget(item, n);

    for (const auto & f : ns->functions)
      fillTreeWidget(item, f);

    for (const auto & n : ns->classes)
      fillTreeWidget(item, n);
  }
  else if (node->is<gen::Class>())
  {
    item->setIcon(0, QIcon(":/assets/class.png"));

    gen::ClassRef cla = qSharedPointerCast<gen::Class>(node);

    for (const auto & n : cla->enums)
      fillTreeWidget(item, n);

    for (const auto & f : cla->functions)
      fillTreeWidget(item, f);
  }
  else if (node->is<gen::Function>() || node->is<gen::Constructor>())
  {
    item->setIcon(0, QIcon(":/assets/func.png"));
    item->setCheckState(1, node->as<gen::Function>().useBindingMacros ? Qt::Checked : Qt::Unchecked);
  }
  else if (node->is<gen::Enum>())
  {
    item->setIcon(0, QIcon(":/assets/enum.png"));

    gen::EnumRef e = qSharedPointerCast<gen::Enum>(node);
    for (const auto & n : e->values)
      fillTreeWidget(item, n);
  }
  else if (node->is<gen::EnumConstant>())
  {
    item->setIcon(0, QIcon(":/assets/enumerator.png"));
  }

  parent->addChild(item);
}

void GeneratePage::updateItem(QTreeWidgetItem *item, int column)
{
  gen::NodeRef node = item->data(0, ProjectNodeRole).value<gen::NodeRef>();
  if (node == nullptr)
    return;

  node->checkState = item->checkState(0);
  
  if (node->is<gen::Function>())
  {
    node->as<gen::Function>().useBindingMacros = item->checkState(1) == Qt::Checked;
  }

  updateCheckState(item);
}

void GeneratePage::updateCheckState(QTreeWidgetItem *item)
{
  auto root = selectionTreeWidget->invisibleRootItem();
  if (item->parent() != root && item->parent() != nullptr)
  {
    if (item->parent()->childCount() == 1)
      item->parent()->setCheckState(0, item->checkState(0));
    else
    {
      bool one_checked = false;
      bool one_unchecked = false;
      for (int i(0); i < item->parent()->childCount(); ++i)
      {
        if (item->parent()->child(i)->checkState(0) == Qt::Checked)
          one_checked = true;
        else if (item->parent()->child(i)->checkState(0) == Qt::Unchecked)
          one_unchecked = true;
        else if (item->parent()->child(i)->checkState(0) == Qt::PartiallyChecked)
        {
          one_checked = true, one_unchecked = true;
          break;
        }
      }

      if (one_checked && one_unchecked)
        item->parent()->setCheckState(0, Qt::PartiallyChecked);
      else if (one_checked)
        item->parent()->setCheckState(0, Qt::Checked);
      else
        item->parent()->setCheckState(0, Qt::Unchecked);

    }
  }

  if (item->checkState(0) == Qt::Unchecked)
  {
    for (int i(0); i < item->childCount(); ++i)
      item->child(i)->setCheckState(0, Qt::Unchecked);
  }
  else if (item->checkState(0) == Qt::Checked)
  {
    for (int i(0); i < item->childCount(); ++i)
      item->child(i)->setCheckState(0, Qt::Checked);
  }
}