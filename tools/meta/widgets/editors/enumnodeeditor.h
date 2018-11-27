// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_ENUM_NODE_EDITOR_H
#define YASL_META_ENUM_NODE_EDITOR_H

#include "abstractnodeeditor.h"

#include "project/enum.h"

class QCheckBox;
class QLineEdit;

class EnumNodeEditor : public AbstractNodeEditor
{
  Q_OBJECT
public:
  EnumNodeEditor(const EnumRef & enm, QWidget *p = nullptr);
  ~EnumNodeEditor() = default;

  void write() override;
  void read(EnumRef enm);

  inline EnumRef getEnum() const { return qSharedPointerCast<Enum>(getNode()); }

private:
  QLineEdit *mVersion;
  QLineEdit *mName;
  QCheckBox *mToEnumClass;
  QCheckBox *mFromEnumClass;
};

#endif // YASL_META_ENUM_NODE_EDITOR_H
