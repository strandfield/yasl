// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_SIGNAL_UTILS_H
#define YASL_COMMONS_SIGNAL_UTILS_H

#include <script/function.h>
#include <script/userdata.h>

#include <QMap>
#include <QObject>

namespace script
{
inline bool operator<(const script::Function & lhs, const script::Function & rhs) { return lhs.impl() < rhs.impl(); }
}

namespace yasl
{

struct SignalTableEntry
{
  SignalTableEntry();
  SignalTableEntry(int sig, int mapper, int slot);

  int signal_index; // signal index of the sender's Class
  int mapper_index; // index of the SignalMapper
  int slot_index; // slot index of the SignalMapper
};

typedef QMap<script::Function, SignalTableEntry> SignalTable; // stored in the sender's class

struct SignalTableClassData : public script::UserData
{
  SignalTableClassData() = default;
  ~SignalTableClassData() = default;

  SignalTable table;
};


class SignalMapper : public QObject
{
  Q_OBJECT
private:
  QObject* receiver_;
  script::Function slot_;

protected:
  SignalMapper();
  SignalMapper(QObject *obj, const script::Function & target_slot);

public:
  inline QObject* receiver() const { return receiver_; }
  inline const script::Function & slot() const { return slot_; }
  inline script::Engine* engine() const { return slot_.engine(); }

  virtual SignalMapper* clone(QObject *obj, const script::Function & target_slot) const = 0;
  int slotIndex(const QMetaMethod & signal) const;

  static QList<QPointer<SignalMapper>> & mappers();
  static void registerMapper(SignalMapper* mapper);
  
  template<typename T>
  static void registerMapper() { registerMapper(new T); }

  static std::pair<int, int> getMapperAndSlotIndex(const QMetaMethod & signal);

protected:
  void invoke(std::initializer_list<script::Value> && args);
};

std::shared_ptr<script::UserData> createSignalTable();
std::shared_ptr<SignalTableClassData> getSignalTable(script::Class & c);
SignalTableEntry getSignalTableEntry(const script::Function & sig);
void registerSignal(script::Class & c, const QMetaObject *meta, const script::Function & sig, const std::string & signature);

bool connect(const script::Value & sender, const script::Function & sig, const script::Value & receiver, const script::Function & slot);
bool connect(const script::Value & sender, const std::string & signal, const script::Value & receiver, const std::string & slot);

void emitSignal(const script::Value & object, const script::Function & sig, const script::Value *begin, const script::Value *end);

void registerSignalUtils(script::Namespace core);

} // namespace yasl

#endif // YASL_COMMONS_SIGNAL_UTILS_H
