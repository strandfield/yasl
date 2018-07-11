// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GEN_GENERATEPAGE_H
#define YASL_GEN_GENERATEPAGE_H

#include <QWizardPage>

#include "project.h"

class QPushButton;
class QTreeWidget;
class QTreeWidgetItem;

class GeneratePage : public QWizardPage
{
  Q_OBJECT
public:
  GeneratePage();

protected:
  void cleanupPage() override;
  void initializePage() override;
  bool validatePage() override;

  enum Role {
    ProjectNodeRole = Qt::UserRole + 66,
  };

  void fillTreeWidget(QTreeWidgetItem *parent, gen::NodeRef node);

protected Q_SLOTS:
  void updateItem(QTreeWidgetItem *item, int column);

protected:
  void updateCheckState(QTreeWidgetItem *item);

private:
  QPushButton *importSettingsButton;
  QTreeWidget *selectionTreeWidget;
};

#endif // YASL_GEN_GENERATEPAGE_H
