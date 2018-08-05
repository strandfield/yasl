// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_MODULETREEWIDGET_H
#define YASL_META_MODULETREEWIDGET_H

#include <QTreeWidget>

#include "project.h"

class ModuleTreeWidget : public QTreeWidget
{
  Q_OBJECT
public:
  ModuleTreeWidget(const ProjectRef & pro);

  enum Role {
    ProjectNodeRole = Qt::UserRole + 66,
  };

  void setShowCheckboxes(bool visible);

  inline ProjectRef project() const { return mProject; }
  void setProject(const ProjectRef & pro);

  void fetchNewNodes();

protected:
  void keyPressEvent(QKeyEvent *e);

protected:
  void removeSelectedRows();

protected:
  void fillTreeWidget(const ProjectRef & pro);
  void fill(QTreeWidgetItem *parent, const NodeRef & node);
  QTreeWidgetItem* createItem(const NodeRef & node);
  void fetchNewNodes(QTreeWidgetItem *item);

protected Q_SLOTS:
  void updateItem(QTreeWidgetItem *item, int column);
  void updateCheckState(QTreeWidgetItem *item);
  void resizeColumnsAuto();

private:
  ProjectRef mProject;
  bool mShowCheckboxes;
};

#endif // YASL_META_MODULETREEWIDGET_H
