// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/application.h"

#include "script/sourcefile.h"

#include <iostream>

int main(int argc, char *argv[])
{
  Application app(argc, argv);

  if (app.arguments().size() <= 1) 
  {
    app.startInteractiveSession();
    return app.exec();
  }
  else 
  {
    script::SourceFile src{ app.arguments().at(1).toLocal8Bit().data() };
    int ret = app.runScript(src);
    if (ret == 0 && app.runEventLoop())
      return app.exec();
    return ret;
  }
}