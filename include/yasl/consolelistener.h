// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CONSOLE_LISTENER_H
#define YASL_CONSOLE_LISTENER_H

#include <QObject>

class ConsoleListener : public QObject
{
  Q_OBJECT
public:
  ConsoleListener();
  ~ConsoleListener();

  static int ListenEvent;
  static int ExitEvent;

  static void registerEventTypes();

protected:
  bool event(QEvent *e) override;

Q_SIGNALS:
  void commandReceived(QString str);
};

#endif // YASL_CONSOLE_LISTENER_H
