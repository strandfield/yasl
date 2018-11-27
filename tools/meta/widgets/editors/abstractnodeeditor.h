// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_ABSTRACT_NODE_EDITOR_H
#define YASL_META_ABSTRACT_NODE_EDITOR_H

#include <QWidget>

#include "project/node.h"

class AbstractNodeEditor : public QWidget
{
  Q_OBJECT
public:
  AbstractNodeEditor(NodeRef n, QWidget *p = nullptr);
  ~AbstractNodeEditor() = default;

  virtual void write() = 0;

  inline NodeRef getNode() const { return mNode; }

protected:
  inline void setNode(const NodeRef & n) { mNode = n; }

private:
  NodeRef mNode;
};

#endif // YASL_META_ABSTRACT_NODE_EDITOR_H
