// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "namespacenodeeditor.h"

#include <QBoxLayout>
#include <QFontMetrics>
#include <QLineEdit>

NamespaceNodeEditor::NamespaceNodeEditor(const NamespaceRef & ns, QWidget *p)
  : AbstractNodeEditor(ns, p)
{
  QFontMetrics fm{ font() };

  mName = new QLineEdit();
  mName->setPlaceholderText("name[->rename]");

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(mName);

  setAutoFillBackground(true);

  read(ns);
}

void NamespaceNodeEditor::write()
{
  auto ns = getNamespace();

  ns->name = mName->text();
  const int index = ns->name.indexOf("->");
  if (index != -1)
  {
    ns->rename = ns->name.mid(index + 2);
    ns->name.chop(ns->name.size() - index);
  }
}

void NamespaceNodeEditor::read(NamespaceRef ns)
{
  setNode(ns);

  mName->setText(ns->name + (ns->rename.isEmpty() ? QString() : ("->" + ns->rename)));
}
