// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/process.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/object.h"
#include "yasl/core/process.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_process_environment_class(script::Namespace ns)
{
  using namespace script;

  Class process_environment = ns.newClass("ProcessEnvironment").setId(script::Type::QProcessEnvironment).get();


  // QProcessEnvironment();
  bind::default_constructor<QProcessEnvironment>(process_environment).create();
  // QProcessEnvironment(const QProcessEnvironment &);
  bind::constructor<QProcessEnvironment, const QProcessEnvironment &>(process_environment).create();
  // ~QProcessEnvironment();
  bind::destructor<QProcessEnvironment>(process_environment).create();
  // QProcessEnvironment & operator=(QProcessEnvironment &&);
  bind::memop_assign<QProcessEnvironment, QProcessEnvironment &&>(process_environment);
  // QProcessEnvironment & operator=(const QProcessEnvironment &);
  bind::memop_assign<QProcessEnvironment, const QProcessEnvironment &>(process_environment);
  // void swap(QProcessEnvironment &);
  bind::void_member_function<QProcessEnvironment, QProcessEnvironment &, &QProcessEnvironment::swap>(process_environment, "swap").create();
  // bool operator==(const QProcessEnvironment &) const;
  bind::memop_eq<QProcessEnvironment, const QProcessEnvironment &>(process_environment);
  // bool operator!=(const QProcessEnvironment &) const;
  bind::memop_neq<QProcessEnvironment, const QProcessEnvironment &>(process_environment);
  // bool isEmpty() const;
  bind::member_function<QProcessEnvironment, bool, &QProcessEnvironment::isEmpty>(process_environment, "isEmpty").create();
  // void clear();
  bind::void_member_function<QProcessEnvironment, &QProcessEnvironment::clear>(process_environment, "clear").create();
  // bool contains(const QString &) const;
  bind::member_function<QProcessEnvironment, bool, const QString &, &QProcessEnvironment::contains>(process_environment, "contains").create();
  // void insert(const QString &, const QString &);
  bind::void_member_function<QProcessEnvironment, const QString &, const QString &, &QProcessEnvironment::insert>(process_environment, "insert").create();
  // void remove(const QString &);
  bind::void_member_function<QProcessEnvironment, const QString &, &QProcessEnvironment::remove>(process_environment, "remove").create();
  // QString value(const QString &, const QString &) const;
  bind::member_function<QProcessEnvironment, QString, const QString &, const QString &, &QProcessEnvironment::value>(process_environment, "value").create();
  // QStringList toStringList() const;
  /// TODO: QStringList toStringList() const;
  // QStringList keys() const;
  /// TODO: QStringList keys() const;
  // void insert(const QProcessEnvironment &);
  bind::void_member_function<QProcessEnvironment, const QProcessEnvironment &, &QProcessEnvironment::insert>(process_environment, "insert").create();
  // static QProcessEnvironment systemEnvironment();
  bind::static_member_function<QProcessEnvironment, QProcessEnvironment, &QProcessEnvironment::systemEnvironment>(process_environment, "systemEnvironment").create();
}


static void register_process_process_error_enum(script::Class process)
{
  using namespace script;

  Enum process_error = process.newEnum("ProcessError").setId(script::Type::QProcessProcessError).get();

  process_error.addValue("FailedToStart", QProcess::FailedToStart);
  process_error.addValue("Crashed", QProcess::Crashed);
  process_error.addValue("Timedout", QProcess::Timedout);
  process_error.addValue("ReadError", QProcess::ReadError);
  process_error.addValue("WriteError", QProcess::WriteError);
  process_error.addValue("UnknownError", QProcess::UnknownError);
}


static void register_process_process_state_enum(script::Class process)
{
  using namespace script;

  Enum process_state = process.newEnum("ProcessState").setId(script::Type::QProcessProcessState).get();

  process_state.addValue("NotRunning", QProcess::NotRunning);
  process_state.addValue("Starting", QProcess::Starting);
  process_state.addValue("Running", QProcess::Running);
}


static void register_process_process_channel_enum(script::Class process)
{
  using namespace script;

  Enum process_channel = process.newEnum("ProcessChannel").setId(script::Type::QProcessProcessChannel).get();

  process_channel.addValue("StandardOutput", QProcess::StandardOutput);
  process_channel.addValue("StandardError", QProcess::StandardError);
}


static void register_process_process_channel_mode_enum(script::Class process)
{
  using namespace script;

  Enum process_channel_mode = process.newEnum("ProcessChannelMode").setId(script::Type::QProcessProcessChannelMode).get();

  process_channel_mode.addValue("SeparateChannels", QProcess::SeparateChannels);
  process_channel_mode.addValue("MergedChannels", QProcess::MergedChannels);
  process_channel_mode.addValue("ForwardedChannels", QProcess::ForwardedChannels);
  process_channel_mode.addValue("ForwardedOutputChannel", QProcess::ForwardedOutputChannel);
  process_channel_mode.addValue("ForwardedErrorChannel", QProcess::ForwardedErrorChannel);
}


static void register_process_input_channel_mode_enum(script::Class process)
{
  using namespace script;

  Enum input_channel_mode = process.newEnum("InputChannelMode").setId(script::Type::QProcessInputChannelMode).get();

  input_channel_mode.addValue("ManagedInputChannel", QProcess::ManagedInputChannel);
  input_channel_mode.addValue("ForwardedInputChannel", QProcess::ForwardedInputChannel);
}


static void register_process_exit_status_enum(script::Class process)
{
  using namespace script;

  Enum exit_status = process.newEnum("ExitStatus").setId(script::Type::QProcessExitStatus).get();

  exit_status.addValue("NormalExit", QProcess::NormalExit);
  exit_status.addValue("CrashExit", QProcess::CrashExit);
}


static void register_process_class(script::Namespace ns)
{
  using namespace script;

  Class process = ns.newClass("Process").setId(script::Type::QProcess)
    .setBase(script::Type::QIODevice).get();

  register_process_process_error_enum(process);
  register_process_process_state_enum(process);
  register_process_process_channel_enum(process);
  register_process_process_channel_mode_enum(process);
  register_process_input_channel_mode_enum(process);
  register_process_exit_status_enum(process);

  // QProcess(QObject *);
  bind::constructor<QProcess, QObject *>(process)
    .apply(bind::default_arguments((QObject*) nullptr)).create();
  // ~QProcess();
  bind::destructor<QProcess>(process).create();
  // void start(const QString &, const QStringList &, QIODevice::OpenMode);
  /// TODO: void start(const QString &, const QStringList &, QIODevice::OpenMode);
  // void start(const QString &, QIODevice::OpenMode);
  bind::void_member_function<QProcess, const QString &, QIODevice::OpenMode, &QProcess::start>(process, "start")
    .apply(bind::default_arguments(QIODevice::OpenMode(QIODevice::ReadWrite))).create();
  // void start(QIODevice::OpenMode);
  bind::void_member_function<QProcess, QIODevice::OpenMode, &QProcess::start>(process, "start").create();
  // bool open(QIODevice::OpenMode);
  bind::member_function<QProcess, bool, QIODevice::OpenMode, &QProcess::open>(process, "open")
    .apply(bind::default_arguments(QIODevice::OpenMode(QIODevice::ReadWrite))).create();
  // QString program() const;
  bind::member_function<QProcess, QString, &QProcess::program>(process, "program").create();
  // void setProgram(const QString &);
  bind::void_member_function<QProcess, const QString &, &QProcess::setProgram>(process, "setProgram").create();
  // QStringList arguments() const;
  /// TODO: QStringList arguments() const;
  // void setArguments(const QStringList &);
  /// TODO: void setArguments(const QStringList &);
  // QProcess::ProcessChannelMode readChannelMode() const;
  bind::member_function<QProcess, QProcess::ProcessChannelMode, &QProcess::readChannelMode>(process, "readChannelMode").create();
  // void setReadChannelMode(QProcess::ProcessChannelMode);
  bind::void_member_function<QProcess, QProcess::ProcessChannelMode, &QProcess::setReadChannelMode>(process, "setReadChannelMode").create();
  // QProcess::ProcessChannelMode processChannelMode() const;
  bind::member_function<QProcess, QProcess::ProcessChannelMode, &QProcess::processChannelMode>(process, "processChannelMode").create();
  // void setProcessChannelMode(QProcess::ProcessChannelMode);
  bind::void_member_function<QProcess, QProcess::ProcessChannelMode, &QProcess::setProcessChannelMode>(process, "setProcessChannelMode").create();
  // QProcess::InputChannelMode inputChannelMode() const;
  bind::member_function<QProcess, QProcess::InputChannelMode, &QProcess::inputChannelMode>(process, "inputChannelMode").create();
  // void setInputChannelMode(QProcess::InputChannelMode);
  bind::void_member_function<QProcess, QProcess::InputChannelMode, &QProcess::setInputChannelMode>(process, "setInputChannelMode").create();
  // QProcess::ProcessChannel readChannel() const;
  bind::member_function<QProcess, QProcess::ProcessChannel, &QProcess::readChannel>(process, "readChannel").create();
  // void setReadChannel(QProcess::ProcessChannel);
  bind::void_member_function<QProcess, QProcess::ProcessChannel, &QProcess::setReadChannel>(process, "setReadChannel").create();
  // void closeReadChannel(QProcess::ProcessChannel);
  bind::void_member_function<QProcess, QProcess::ProcessChannel, &QProcess::closeReadChannel>(process, "closeReadChannel").create();
  // void closeWriteChannel();
  bind::void_member_function<QProcess, &QProcess::closeWriteChannel>(process, "closeWriteChannel").create();
  // void setStandardInputFile(const QString &);
  bind::void_member_function<QProcess, const QString &, &QProcess::setStandardInputFile>(process, "setStandardInputFile").create();
  // void setStandardOutputFile(const QString &, QIODevice::OpenMode);
  bind::void_member_function<QProcess, const QString &, QIODevice::OpenMode, &QProcess::setStandardOutputFile>(process, "setStandardOutputFile")
    .apply(bind::default_arguments(QIODevice::OpenMode(QIODevice::Truncate))).create();
  // void setStandardErrorFile(const QString &, QIODevice::OpenMode);
  bind::void_member_function<QProcess, const QString &, QIODevice::OpenMode, &QProcess::setStandardErrorFile>(process, "setStandardErrorFile")
    .apply(bind::default_arguments(QIODevice::OpenMode(QIODevice::Truncate))).create();
  // void setStandardOutputProcess(QProcess *);
  /// TODO: void setStandardOutputProcess(QProcess *);
  // QProcess::CreateProcessArgumentModifier createProcessArgumentsModifier() const;
  /// TODO: QProcess::CreateProcessArgumentModifier createProcessArgumentsModifier() const;
  // void setCreateProcessArgumentsModifier(QProcess::CreateProcessArgumentModifier);
  /// TODO: void setCreateProcessArgumentsModifier(QProcess::CreateProcessArgumentModifier);
  // QString workingDirectory() const;
  bind::member_function<QProcess, QString, &QProcess::workingDirectory>(process, "workingDirectory").create();
  // void setWorkingDirectory(const QString &);
  bind::void_member_function<QProcess, const QString &, &QProcess::setWorkingDirectory>(process, "setWorkingDirectory").create();
  // void setEnvironment(const QStringList &);
  /// TODO: void setEnvironment(const QStringList &);
  // QStringList environment() const;
  /// TODO: QStringList environment() const;
  // void setProcessEnvironment(const QProcessEnvironment &);
  bind::void_member_function<QProcess, const QProcessEnvironment &, &QProcess::setProcessEnvironment>(process, "setProcessEnvironment").create();
  // QProcessEnvironment processEnvironment() const;
  bind::member_function<QProcess, QProcessEnvironment, &QProcess::processEnvironment>(process, "processEnvironment").create();
  // QProcess::ProcessError error() const;
  bind::member_function<QProcess, QProcess::ProcessError, &QProcess::error>(process, "error").create();
  // QProcess::ProcessState state() const;
  bind::member_function<QProcess, QProcess::ProcessState, &QProcess::state>(process, "state").create();
  // Q_PID pid() const;
  /// TODO: Q_PID pid() const;
  // qint64 processId() const;
  /// TODO: qint64 processId() const;
  // bool waitForStarted(int);
  bind::member_function<QProcess, bool, int, &QProcess::waitForStarted>(process, "waitForStarted")
    .apply(bind::default_arguments(30000)).create();
  // bool waitForReadyRead(int);
  bind::member_function<QProcess, bool, int, &QProcess::waitForReadyRead>(process, "waitForReadyRead")
    .apply(bind::default_arguments(30000)).create();
  // bool waitForBytesWritten(int);
  bind::member_function<QProcess, bool, int, &QProcess::waitForBytesWritten>(process, "waitForBytesWritten")
    .apply(bind::default_arguments(30000)).create();
  // bool waitForFinished(int);
  bind::member_function<QProcess, bool, int, &QProcess::waitForFinished>(process, "waitForFinished")
    .apply(bind::default_arguments(30000)).create();
  // QByteArray readAllStandardOutput();
  bind::member_function<QProcess, QByteArray, &QProcess::readAllStandardOutput>(process, "readAllStandardOutput").create();
  // QByteArray readAllStandardError();
  bind::member_function<QProcess, QByteArray, &QProcess::readAllStandardError>(process, "readAllStandardError").create();
  // int exitCode() const;
  bind::member_function<QProcess, int, &QProcess::exitCode>(process, "exitCode").create();
  // QProcess::ExitStatus exitStatus() const;
  bind::member_function<QProcess, QProcess::ExitStatus, &QProcess::exitStatus>(process, "exitStatus").create();
  // qint64 bytesAvailable() const;
  /// TODO: qint64 bytesAvailable() const;
  // qint64 bytesToWrite() const;
  /// TODO: qint64 bytesToWrite() const;
  // bool isSequential() const;
  bind::member_function<QProcess, bool, &QProcess::isSequential>(process, "isSequential").create();
  // bool canReadLine() const;
  bind::member_function<QProcess, bool, &QProcess::canReadLine>(process, "canReadLine").create();
  // void close();
  bind::void_member_function<QProcess, &QProcess::close>(process, "close").create();
  // bool atEnd() const;
  bind::member_function<QProcess, bool, &QProcess::atEnd>(process, "atEnd").create();
  // static int execute(const QString &, const QStringList &);
  /// TODO: static int execute(const QString &, const QStringList &);
  // static int execute(const QString &);
  bind::static_member_function<QProcess, int, const QString &, &QProcess::execute>(process, "execute").create();
  // static bool startDetached(const QString &, const QStringList &, const QString &, qint64 *);
  /// TODO: static bool startDetached(const QString &, const QStringList &, const QString &, qint64 *);
  // static bool startDetached(const QString &, const QStringList &);
  /// TODO: static bool startDetached(const QString &, const QStringList &);
  // static bool startDetached(const QString &);
  bind::static_member_function<QProcess, bool, const QString &, &QProcess::startDetached>(process, "startDetached").create();
  // static QStringList systemEnvironment();
  /// TODO: static QStringList systemEnvironment();
  // static QString nullDevice();
  bind::static_member_function<QProcess, QString, &QProcess::nullDevice>(process, "nullDevice").create();
  // void terminate();
  bind::void_member_function<QProcess, &QProcess::terminate>(process, "terminate").create();
  // void kill();
  bind::void_member_function<QProcess, &QProcess::kill>(process, "kill").create();
  // void started(QProcess::QPrivateSignal);
  /// TODO: void started(QProcess::QPrivateSignal);
  // void finished(int);
  bind::signal<QProcess, int>(process, "finished", "finished(int)");
  // void finished(int, QProcess::ExitStatus);
  bind::signal<QProcess, int, QProcess::ExitStatus>(process, "finished", "finished(int,QProcess::ExitStatus)");
  // void error(QProcess::ProcessError);
  bind::void_member_function<QProcess, QProcess::ProcessError, &QProcess::error>(process, "error").create();
  // void errorOccurred(QProcess::ProcessError);
  bind::signal<QProcess, QProcess::ProcessError>(process, "errorOccurred", "errorOccurred(QProcess::ProcessError)");
  // void stateChanged(QProcess::ProcessState);
  bind::signal<QProcess, QProcess::ProcessState>(process, "stateChanged", "stateChanged(QProcess::ProcessState)");
  // void readyReadStandardOutput();
  bind::signal<QProcess>(process, "readyReadStandardOutput", "readyReadStandardOutput()");
  // void readyReadStandardError();
  bind::signal<QProcess>(process, "readyReadStandardError", "readyReadStandardError()");

  bind::link(process, &QProcess::staticMetaObject);
}


void register_process_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_process_environment_class(ns);
  register_process_class(ns);

  // void swap(QProcessEnvironment &, QProcessEnvironment &);
  bind::void_function<QProcessEnvironment &, QProcessEnvironment &, &swap>(ns, "swap").create();
}

