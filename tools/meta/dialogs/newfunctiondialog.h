// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_NEWFUNCTIONDIALOG_H
#define YASL_META_NEWFUNCTIONDIALOG_H

#include <QDialog>

#include "project/function.h"

class QComboBox;
class QLineEdit;

class NewFunctionDialog : public QDialog
{
  Q_OBJECT
public:
  NewFunctionDialog(QWidget *parent = nullptr);
  NewFunctionDialog(FunctionRef fun, QWidget *parent = nullptr);
  ~NewFunctionDialog() = default;

  const FunctionRef & function() const { return mFunction; }
  void sync();

private:
  void setup();

private:
  QLineEdit *mNameLineEdit;
  QLineEdit *mRenameLineEdit;
  QLineEdit *mReturnTypeLineEdit;
  QLineEdit *mParametersLineEdit;
  QLineEdit *mSpecifiersLineEdit;
  QComboBox *mBindingMethodComboBox;
  FunctionRef mFunction;
};

#endif // YASL_META_NEWFUNCTIONDIALOG_H
