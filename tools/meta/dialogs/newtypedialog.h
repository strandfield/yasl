// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_NEWTYPEDIALOG_H
#define YASL_META_NEWTYPEDIALOG_H

#include <QDialog>

#include "project/type.h"

class QComboBox;
class QLineEdit;

class NewTypeDialog : public QDialog
{
  Q_OBJECT
public:
  NewTypeDialog(QWidget *parent = nullptr);
  ~NewTypeDialog() = default;

  Type::Category getCategory() const;
  Type getType() const;

private:
  QComboBox *mTypeCategoryComboBox;
  QLineEdit *mNameLineEdit;
  QLineEdit *mIdLineEdit;
  QLineEdit *mRenameLineEdit;
  QLineEdit *mHeaderLineEdit;
  QLineEdit *mTagLineEdit;
  QLineEdit *mLinksLineEdit;
};

#endif // YASL_META_NEWTYPEDIALOG_H
