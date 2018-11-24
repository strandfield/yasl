// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_TYPETREEWIDGET_H
#define YASL_META_TYPETREEWIDGET_H

#include <QTreeWidget>

#include "project.h"

class Type;

class TypeTreeWidget : public QTreeWidget
{
  Q_OBJECT
public:
  TypeTreeWidget(const ProjectRef & pro);

  void fetchNewNodes();

  inline ProjectRef project() const { return mProject; }
  void setProject(const ProjectRef & pro);

protected:
  enum Columns {
    NameColumn = 0,
    RenameColumn,
    IdColumn,
    HeaderColumn,
    TagColumn,
    LinksColumn,
    MetatypeColumn,
  };

  QList<Type> & getTypeList(QTreeWidgetItem *item);
  Type & getType(QTreeWidgetItem *item);
  QString & getField(Type & t, int col);

protected:
  void keyPressEvent(QKeyEvent *e) override;

protected Q_SLOTS:
  void updateItem(QTreeWidgetItem *item, int col);

protected:
  void removeSelectedRows();
  void moveSelectedRow(int k);

protected:
  void fillTreeWidget(const ProjectRef & pro);
  void fill(QTreeWidgetItem *parent, const QList<Type> & types);
  QTreeWidgetItem* createItem(const Type & t);

private:
  ProjectRef mProject;
  QTreeWidgetItem *mFundamentalTypes;
  QTreeWidgetItem *mEnums;
  QTreeWidgetItem *mClasses;
};

#endif // YASL_META_TYPETREEWIDGET_H
