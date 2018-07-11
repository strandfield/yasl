// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "wizard.h"

#include <QApplication>

#include <QIcon>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Wizard w;
  w.show();
  w.setWindowIcon(QIcon(":/assets/func.png"));

  return app.exec();
}