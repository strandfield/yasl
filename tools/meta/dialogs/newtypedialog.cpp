// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "dialogs/newtypedialog.h"

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

NewTypeDialog::NewTypeDialog(QWidget *parent)
  : QDialog(parent)
{
  mTypeCategoryComboBox = new QComboBox();
  mTypeCategoryComboBox->addItem("Fundamental");
  mTypeCategoryComboBox->addItem("Enum");
  mTypeCategoryComboBox->addItem("Class");

  mNameLineEdit = new QLineEdit();
  mIdLineEdit = new QLineEdit();
  mRenameLineEdit = new QLineEdit();
  mHeaderLineEdit = new QLineEdit();
  mTagLineEdit = new QLineEdit();
  mLinksLineEdit = new QLineEdit();

  auto *form = new QFormLayout();
  form->addRow("Category:", mTypeCategoryComboBox);
  form->addRow("C++ type:", mNameLineEdit);
  form->addRow("Rename:", mRenameLineEdit);
  form->addRow("Id:", mIdLineEdit);
  form->addRow("Header:", mHeaderLineEdit);
  form->addRow("Tag:", mTagLineEdit);
  form->addRow("Links:", mLinksLineEdit);

  auto *okButton = new QPushButton("OK");
  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

  auto *layout = new QVBoxLayout(this);
  layout->addLayout(form);
  layout->addWidget(okButton, 0, Qt::AlignCenter);
}

Type::Category NewTypeDialog::getCategory() const
{
  if (mTypeCategoryComboBox->currentIndex() == 0)
    return Type::FundamentalType;
  else if (mTypeCategoryComboBox->currentIndex() == 1)
    return Type::EnumType;
  return Type::ClassType;
}

Type NewTypeDialog::getType() const
{
  Type ret{ mNameLineEdit->text(), mIdLineEdit->text() };
  ret.header = mHeaderLineEdit->text();
  ret.rename = mRenameLineEdit->text();
  ret.tag = mTagLineEdit->text();
  ret.links = mLinksLineEdit->text();
  return ret;
}