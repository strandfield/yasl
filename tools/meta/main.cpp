// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "mainwindow.h"

#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/function.h"
#include "project/module.h"
#include "project/namespace.h"

#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Node::registerDeserializer(Class::staticTypeCode, Class::fromJson);
  Node::registerDeserializer(Enum::staticTypeCode, Enum::fromJson);
  Node::registerDeserializer(File::staticTypeCode, File::fromJson);
  Node::registerDeserializer(Function::staticTypeCode, Function::fromJson);
  Node::registerDeserializer(Constructor::staticTypeCode, Constructor::fromJson);
  Node::registerDeserializer(Destructor::staticTypeCode, Destructor::fromJson);
  Node::registerDeserializer(Module::staticTypeCode, Module::fromJson);
  Node::registerDeserializer(Namespace::staticTypeCode, Namespace::fromJson);

  ProjectRef pro = Project::load("yasl.json");
  if (pro == nullptr)
  {
    qDebug() << "Could not load project";
    return 1;
  }

  MainWindow w;
  w.show();

  return app.exec();
}