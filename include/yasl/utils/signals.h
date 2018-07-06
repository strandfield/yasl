// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_SIGNALS_H
#define YASL_UTILS_SIGNALS_H

#include <script/function.h>
#include <script/userdata.h>

#include <QMap>
#include <QObject>

struct SignalTableClassData;
struct SignalTableEntry;

struct SignalMapper : public QObject
{
  Q_OBJECT
private:
  QObject * receiver;
  script::Function slot;

public:
  static SignalMapper * make(QObject *sender, const script::Function & signal, QObject *receiver, const script::Function & slot);

  static SignalTableEntry get_signal_entry(const script::Function & sig);
  static void register_signal(script::Class & c, const QMetaObject *meta, const script::Function & sig, const std::string & signature);

protected:
  SignalMapper(QObject *obj, script::Function target_slot);

  static std::shared_ptr<SignalTableClassData> get_table(script::Class & c);

protected Q_SLOTS:
  void activate();
  void activate(bool);
  void activate(int);
  void activate(int, qint64);
  void activate(const QString &);
  void activate(qint64);

private:
  void invoke(const script::Function & slot, const script::Value & receiver, std::initializer_list<script::Value> && args);
};

struct SignalTableEntry
{
  SignalTableEntry();
  SignalTableEntry(int sig, int slot);

  int signal_index; // signal index of the sender's Class
  int slot_index; // slot index of SignalMapper
};

bool operator<(const script::Function & lhs, const script::Function & rhs);
typedef QMap<script::Function, SignalTableEntry> SignalTable; // stored in the sender's class

struct SignalTableClassData : public script::UserData
{
  SignalTableClassData() = default;
  ~SignalTableClassData() = default;

  SignalTable table;
};


void emit_signal(const script::Value & object, const script::Function & sig, const std::vector<script::Value> & args);
void emit_signal(const std::vector<script::Value> & args); // first arg is the object, second is the signal
// the rest are the signal's args.

namespace callbacks
{

script::Value emit_callback(script::FunctionCall *c);
script::Value signal_callback(script::FunctionCall *c); // just call the emit function with the callee and the args

} // namespace callbacks



#endif // YASL_UTILS_SIGNALS_H
