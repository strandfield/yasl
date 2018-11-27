// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "functionnodeeditor.h"

#include <QBoxLayout>
#include <QComboBox>
#include <QFontMetrics>
#include <QLineEdit>

FunctionNodeEditor::FunctionNodeEditor(const FunctionRef & func, QWidget *p)
  : AbstractNodeEditor(func, p)
{
  QFontMetrics fm{ font() };

  mVersion = new QLineEdit;
  mVersion->setPlaceholderText("version");
  mVersion->setFixedWidth(fm.width("version") + 8);

  mBindingMethod = new QComboBox();
  for (int i(Function::FirstBindingMethod); i <= Function::LastBindingMethod; ++i)
    mBindingMethod->addItem(Function::serialize(static_cast<Function::BindingMethod>(i)));

  mReturnType = new QLineEdit();
  mReturnType->setPlaceholderText("return-type");
  mReturnType->setFixedWidth(fm.width("return-type") + 8);

  mName = new QLineEdit();
  mName->setPlaceholderText("name[->rename]");
  mName->setFixedWidth(fm.width("name[->rename]") + 8);

  mParameters = new QLineEdit;
  mParameters->setPlaceholderText("param1[=value1];...");

  mSpecifiers = new QLineEdit;
  mSpecifiers->setPlaceholderText("const,static,...");
  mSpecifiers->setFixedWidth(fm.width("const,static,...") + 8);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(mVersion);
  layout->addWidget(mBindingMethod);
  layout->addWidget(mReturnType);
  layout->addWidget(mName);
  layout->addWidget(mParameters);
  layout->addWidget(mSpecifiers);

  setAutoFillBackground(true);

  read(func);
}

void FunctionNodeEditor::write()
{
  auto mFunction = getFunction();

  mFunction->version = QtVersion::fromString(mVersion->text());
  mFunction->bindingMethod = static_cast<Function::BindingMethod>(mBindingMethod->currentIndex() + Function::FirstBindingMethod);
  mFunction->returnType = mReturnType->text();
  mFunction->name = mName->text();
  if (mFunction->name.indexOf("->") != -1)
  {
    const int index = mFunction->name.indexOf("->");
    mFunction->rename = mFunction->name.mid(index + 2);
    mFunction->name.chop(mFunction->name.size() - index);
  }

  QStringList params = mParameters->text().split(';');
  QStringList defaultargs;
  for (int i(params.size() - 1); i >= 0; --i)
  {
    const int index = params.at(i).indexOf("=");
    if (index == -1)
      break;
    defaultargs.push_back(params.at(i).mid(index + 1));
    params[i] = params[i].mid(0, index);
  }
  mFunction->parameters = params;
  mFunction->defaultArguments = defaultargs;

  mFunction->setSpecifiers(mSpecifiers->text().split(','));
}

void FunctionNodeEditor::read(FunctionRef fun)
{
  setNode(fun);

  mVersion->setText(fun->version.toString());
  mBindingMethod->setCurrentIndex(fun->bindingMethod - Function::FirstBindingMethod);
  mReturnType->setText(fun->returnType);
  mName->setText(fun->name + (fun->rename.isEmpty() ? QString() : (QString("->") + fun->rename)));

  QStringList params = fun->parameters;
  for (int i(0); i < fun->defaultArguments.size(); ++i)
    params[params.size() - i - 1] += "=" + fun->defaultArguments.at(i);
  mParameters->setText(params.join(";"));

  mSpecifiers->setText(fun->getSpecifiers().join(','));
}

