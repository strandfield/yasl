// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_FILE_NODE_EDITOR_H
#define YASL_META_FILE_NODE_EDITOR_H

#include "abstractnodeeditor.h"

#include "project/file.h"

class QLineEdit;

class FileNodeEditor : public AbstractNodeEditor
{
  Q_OBJECT
public:
  FileNodeEditor(const FileRef & f, QWidget *p = nullptr);
  ~FileNodeEditor() = default;

  void write() override;
  void read(FileRef f);

  inline FileRef getFile() const { return qSharedPointerCast<File>(getNode()); }

private:
  QLineEdit *mName;
  QLineEdit *mHIncludes;
  QLineEdit *mCppIncludes;
};

#endif // YASL_META_FILE_NODE_EDITOR_H
