// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_FUNCTION_NODE_EDITOR_H
#define YASL_META_FUNCTION_NODE_EDITOR_H

#include "abstractnodeeditor.h"

#include "project/function.h"

class QComboBox;
class QLineEdit;

class FunctionNodeEditor : public AbstractNodeEditor
{
  Q_OBJECT
public:
  FunctionNodeEditor(const FunctionRef & func, QWidget *p = nullptr);
  ~FunctionNodeEditor() = default;

  void write() override;
  void read(FunctionRef fun);

  inline FunctionRef getFunction() const { return qSharedPointerCast<Function>(getNode()); }

private:
  QLineEdit *mVersion;
  QComboBox *mBindingMethod;
  QLineEdit *mReturnType;
  QLineEdit *mName;
  QLineEdit *mParameters;
  QLineEdit *mSpecifiers;
};

#endif // YASL_META_FUNCTION_NODE_EDITOR_H
