// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "abstractnodeeditor.h"

AbstractNodeEditor::AbstractNodeEditor(NodeRef n, QWidget *p)
  : QWidget(p)
  , mNode(n)
{

}
