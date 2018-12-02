// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/consolelistener.h"

#include <QEvent>
#include <QThread>

#include <iostream>

int ConsoleListener::ListenEvent = 0;
int ConsoleListener::ExitEvent = 0;

ConsoleListener::ConsoleListener()
{

}

ConsoleListener::~ConsoleListener()
{

}

void ConsoleListener::registerEventTypes()
{
  ListenEvent = QEvent::registerEventType();
  ExitEvent = QEvent::registerEventType();
}

bool ConsoleListener::event(QEvent *e)
{
  if (e->type() == ListenEvent)
  {
    std::cout << ">>> " << std::flush;

    std::string command;
    std::getline(std::cin, command);
    
    Q_EMIT commandReceived(QString::fromStdString(command));

    return true;
  }
  else if(e->type() == ExitEvent)
  {
    thread()->exit();
    return true;
  }
  else
  {
    return QObject::event(e);
  }
}
