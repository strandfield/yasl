// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "filenodeeditor.h"

#include <QBoxLayout>
#include <QFontMetrics>
#include <QLineEdit>

FileNodeEditor::FileNodeEditor(const FileRef & f, QWidget *p)
  : AbstractNodeEditor(f, p)
{
  QFontMetrics fm{ font() };

  mName = new QLineEdit;
  mName->setPlaceholderText("name");
  mName->setFixedWidth(fm.width("name-name") + 8);

  mHIncludes = new QLineEdit();
  mHIncludes->setPlaceholderText("h-includes: <vector>,yasl/core/string.h");
  mHIncludes->setFixedWidth(fm.width("h-includes: <vector>,yasl/core/string.h") + 8);

  mCppIncludes = new QLineEdit();
  mCppIncludes->setPlaceholderText("cpp-includes: <vector>,yasl/core/string.h");
  mCppIncludes->setFixedWidth(fm.width("cpp-includes: <vector>,yasl/core/string.h") + 8);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(mName);
  layout->addWidget(mHIncludes);
  layout->addWidget(mCppIncludes);

  setAutoFillBackground(true);

  read(f);
}

void FileNodeEditor::write()
{
  auto mFile = getFile();

  mFile->name = mName->text();
  mFile->hincludes = mHIncludes->text().split(',', QString::SkipEmptyParts);
  mFile->cppincludes = mCppIncludes->text().split(',', QString::SkipEmptyParts);
}

void FileNodeEditor::read(FileRef f)
{
  setNode(f);

  mName->setText(f->name);
  mHIncludes->setText(f->hincludes.join(','));
  mCppIncludes->setText(f->cppincludes.join(','));
}

