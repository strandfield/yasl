// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "startprojectpage.h"

#include "wizard.h"

#include <QFile>
#include <QFileDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

class StartProjectPage_DatabaseGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartProjectPage_DatabaseGroupBox()
  {
    this->setTitle("Database");

    QHBoxLayout *l = new QHBoxLayout(this);

    databasePathLineEdit = new QLineEdit("gendb.json");
    openDatabaseButton = new QPushButton("Open");

    l->addWidget(new QLabel("Database path:"));
    l->addWidget(databasePathLineEdit);
    l->addWidget(openDatabaseButton);

    connect(openDatabaseButton, SIGNAL(clicked()), this, SLOT(openDatabase()));
  }

protected slots:
  void openDatabase()
  {
    QString path = QFileDialog::getOpenFileName(this, "Open database");
    if (path.isEmpty())
      return;
    databasePathLineEdit->setText(path);
  }

public:
  QLineEdit* databasePathLineEdit;
  QPushButton* openDatabaseButton;
};

class StartProjectPage_TypeGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartProjectPage_TypeGroupBox()
  {
    this->setTitle("Type");

    QHBoxLayout *l = new QHBoxLayout(this);

    openExistingProjectRadioButton = new QRadioButton("Open existing project");
    newProjectRadioButton = new QRadioButton("New project");

    l->addWidget(openExistingProjectRadioButton);
    l->addWidget(newProjectRadioButton);
    l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
  }

public:
  QRadioButton* openExistingProjectRadioButton;
  QRadioButton* newProjectRadioButton;
};


class StartProjectPage_OpenExistingProjectGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartProjectPage_OpenExistingProjectGroupBox()
  {
    this->setTitle("Open existing project");

    QHBoxLayout *l = new QHBoxLayout(this);

    l->addWidget(new QLabel("Path:"));

    projectPathLineEdit = new QLineEdit();
    l->addWidget(projectPathLineEdit);

    openProjectButton = new QPushButton("Open");
    l->addWidget(openProjectButton);
  }

public:
  QLineEdit * projectPathLineEdit;
  QPushButton* openProjectButton;
};

class StartProjectPage_NewProjectGroupBox : public QGroupBox
{
  Q_OBJECT
public:
  StartProjectPage_NewProjectGroupBox()
  {
    this->setTitle("New project");

    QVBoxLayout *l = new QVBoxLayout(this);

    l->addWidget(new QLabel("Include directories:"));

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
  QPushButton * addIncludeDirButton;
  QPushButton *removeIncludeDirButton;
  QListWidget* includeDirectoriesListWidget;
};


StartProjectPage::StartProjectPage()
{
  setTitle("Open or create a project");

  auto *l = new QVBoxLayout(this);

  mDatabaseGroupBox = new DatabaseGroupBox();
  l->addWidget(mDatabaseGroupBox);
 
  mProjectTypeGroupBox = new TypeGroupBox();
  l->addWidget(mProjectTypeGroupBox);

  mOpenExistingProjectGroupBox = new OpenExistingProjectGroupBox();
  l->addWidget(mOpenExistingProjectGroupBox);

  mNewProjectGroupBox = new NewProjectGroupBox();
  l->addWidget(mNewProjectGroupBox);


  connect(mProjectTypeGroupBox->openExistingProjectRadioButton, SIGNAL(toggled(bool)), mOpenExistingProjectGroupBox, SLOT(setEnabled(bool)));
  connect(mProjectTypeGroupBox->newProjectRadioButton, SIGNAL(toggled(bool)), mNewProjectGroupBox, SLOT(setEnabled(bool)));

  mProjectTypeGroupBox->openExistingProjectRadioButton->setEnabled(false);
  mOpenExistingProjectGroupBox->setEnabled(false);
  mProjectTypeGroupBox->newProjectRadioButton->setChecked(true);

  mNewProjectGroupBox->removeIncludeDirButton->setEnabled(false);

  connect(mOpenExistingProjectGroupBox->openProjectButton, SIGNAL(clicked()), this, SLOT(openExistingProject()));
  connect(mNewProjectGroupBox->addIncludeDirButton, SIGNAL(clicked()), this, SLOT(addIncludeDir()));
  connect(mNewProjectGroupBox->removeIncludeDirButton, SIGNAL(clicked()), this, SLOT(removeIncludeDir()));

  connect(mProjectTypeGroupBox->openExistingProjectRadioButton, SIGNAL(toggled(bool)), this, SIGNAL(completeChanged()));
  connect(mProjectTypeGroupBox->newProjectRadioButton, SIGNAL(toggled(bool)), this, SIGNAL(completeChanged()));

  connect(mOpenExistingProjectGroupBox->projectPathLineEdit, SIGNAL(textChanged(const QString &)), this, SIGNAL(completeChanged()));
}

bool StartProjectPage::isComplete() const
{
  if (mProjectTypeGroupBox->openExistingProjectRadioButton->isChecked())
  {
    const QString & path = mOpenExistingProjectGroupBox->projectPathLineEdit->text();
    return !path.isEmpty() && QFile::exists(path);
  }

  return mNewProjectGroupBox->includeDirectoriesListWidget->count() > 0;
}

int StartProjectPage::nextId() const
{
  if (mProjectTypeGroupBox->openExistingProjectRadioButton->isChecked())
    return Wizard::GeneratePageId;
  return Wizard::SelectInputsPageId;
}

bool StartProjectPage::validatePage()
{
  Wizard::Fields & fields = Wizard::get(wizard())->fields();

  fields.openExistingProject = mProjectTypeGroupBox->openExistingProjectRadioButton->isChecked();
  fields.existingProjectPath = mOpenExistingProjectGroupBox->projectPathLineEdit->text();

  fields.includeDirectories = mNewProjectGroupBox->getIncludeDirectories();

  Wizard::get(wizard())->setDatabasePath(mDatabaseGroupBox->databasePathLineEdit->text());

  return isComplete();
}

void StartProjectPage::openExistingProject()
{
  QString path = QFileDialog::getOpenFileName(this, "Open existing project", QString(), "*.json");
  if (path.isEmpty())
    return;

  mOpenExistingProjectGroupBox->projectPathLineEdit->setText(path);

  Q_EMIT completeChanged();
}

void StartProjectPage::addIncludeDir()
{
  QString path = QFileDialog::getExistingDirectory(this, "Open include directory");
  if (path.isEmpty())
    return;

  mNewProjectGroupBox->includeDirectoriesListWidget->addItem(path);
  mNewProjectGroupBox->removeIncludeDirButton->setEnabled(true);

  Q_EMIT completeChanged();
}

void StartProjectPage::removeIncludeDir()
{
  auto selected_items = mNewProjectGroupBox->includeDirectoriesListWidget->selectedItems();
  for (auto item : selected_items)
    delete mNewProjectGroupBox->includeDirectoriesListWidget->takeItem(mNewProjectGroupBox->includeDirectoriesListWidget->row(item));

  if (mNewProjectGroupBox->includeDirectoriesListWidget->count() == 0)
    mNewProjectGroupBox->removeIncludeDirButton->setEnabled(false);

  Q_EMIT completeChanged();
}

#include "startprojectpage.moc"