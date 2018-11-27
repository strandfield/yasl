// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_NAMESPACE_NODE_EDITOR_H
#define YASL_META_NAMESPACE_NODE_EDITOR_H

#include "abstractnodeeditor.h"

#include "project/namespace.h"

class QCheckBox;
class QLineEdit;

class NamespaceNodeEditor : public AbstractNodeEditor
{
  Q_OBJECT
public:
  NamespaceNodeEditor(const NamespaceRef & ns, QWidget *p = nullptr);
  ~NamespaceNodeEditor() = default;

  void write() override;
  void read(NamespaceRef ns);

  inline NamespaceRef getNamespace() const { return qSharedPointerCast<Namespace>(getNode()); }

private:
  QLineEdit *mName;
};

#endif // YASL_META_NAMESPACE_NODE_EDITOR_H
