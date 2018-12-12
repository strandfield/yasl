// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizards/import/startimportpage.h"

#include "wizards/importwizard.h"

#include <QFile>
#include <QFileDialog>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

class StartImportPage_IncludeDirsGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartImportPage_IncludeDirsGroupBox()
  {
    this->setTitle("Include directories");

    QVBoxLayout *l = new QVBoxLayout(this);

    QHBoxLayout *hl = new QHBoxLayout();
    l->addLayout(hl);

    includeDirectoriesListWidget = new QListWidget();
    hl->addWidget(includeDirectoriesListWidget);
    QVBoxLayout *vl = new QVBoxLayout();
    hl->addLayout(vl);
    addIncludeDirButton = new QPushButton("Add");
    removeIncludeDirButton = new QPushButton("Remove");
    vl->addWidget(addIncludeDirButton);
    vl->addWidget(removeIncludeDirButton);
    vl->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
  }

  QStringList getIncludeDirectories() const
  {
    QStringList result;
    for (int i(0); i < includeDirectoriesListWidget->count(); ++i)
      result.append(includeDirectoriesListWidget->item(i)->text());
    return result;
  }

public:
  QPushButton *addIncludeDirButton;
  QPushButton *removeIncludeDirButton;
  QListWidget *includeDirectoriesListWidget;
};


class StartImportPage_PropertiesGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartImportPage_PropertiesGroupBox()
  {
    this->setTitle("Properties");

    auto *l = new QFormLayout(this);

    mModuleNameLineEdit = new QLineEdit();
    mVersionLineEdit = new QLineEdit();
    
    l->addRow("Module name: ", mModuleNameLineEdit);
    l->addRow("Version: ", mVersionLineEdit);
  }


public:
  QLineEdit *mModuleNameLineEdit;
  QLineEdit *mVersionLineEdit;
};


StartImportPage::StartImportPage()
{
  setTitle("Select include directories");

  auto *l = new QVBoxLayout(this);

  mIncludeDirsGroupBox = new IncludeDirsGroupBox();
  l->addWidget(mIncludeDirsGroupBox);

  mPropertiesGroupBox = new PropertiesGroupBox();
  l->addWidget(mPropertiesGroupBox);

  mIncludeDirsGroupBox->removeIncludeDirButton->setEnabled(false);

  connect(mIncludeDirsGroupBox->addIncludeDirButton, SIGNAL(clicked()), this, SLOT(addIncludeDir()));
  connect(mIncludeDirsGroupBox->removeIncludeDirButton, SIGNAL(clicked()), this, SLOT(removeIncludeDir()));
  connect(mPropertiesGroupBox->mModuleNameLineEdit, SIGNAL(textChanged(const QString &)), this, SIGNAL(completeChanged()));
}

bool StartImportPage::isComplete() const
{
  return mIncludeDirsGroupBox->includeDirectoriesListWidget->count() > 0 
    && !mPropertiesGroupBox->mModuleNameLineEdit->text().isEmpty();
}

int StartImportPage::nextId() const
{
  return ImportWizard::SelectInputsPageId;
}

bool StartImportPage::validatePage()
{
  ImportWizard::Fields & fields = ImportWizard::get(wizard())->fields();

  fields.includeDirectories = mIncludeDirsGroupBox->getIncludeDirectories();
  fields.moduleName = mPropertiesGroupBox->mModuleNameLineEdit->text();
  fields.version = QtVersion::fromString(mPropertiesGroupBox->mVersionLineEdit->text());

  return isComplete();
}

void StartImportPage::addIncludeDir()
{
  QString path = QFileDialog::getExistingDirectory(this, "Open include directory");
  if (path.isEmpty())
    return;

  mIncludeDirsGroupBox->includeDirectoriesListWidget->addItem(path);
  mIncludeDirsGroupBox->removeIncludeDirButton->setEnabled(true);

  Q_EMIT completeChanged();
}

void StartImportPage::removeIncludeDir()
{
  auto selected_items = mIncludeDirsGroupBox->includeDirectoriesListWidget->selectedItems();
  for (auto item : selected_items)
    delete mIncludeDirsGroupBox->includeDirectoriesListWidget->takeItem(mIncludeDirsGroupBox->includeDirectoriesListWidget->row(item));

  if (mIncludeDirsGroupBox->includeDirectoriesListWidget->count() == 0)
    mIncludeDirsGroupBox->removeIncludeDirButton->setEnabled(false);

  Q_EMIT completeChanged();
}

#include "startimportpage.moc"