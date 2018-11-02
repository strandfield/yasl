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

  Class process_environment = ns.Class("ProcessEnvironment").setId(script::Type::QProcessEnvironment).get();

  binding::Class<QProcessEnvironment> binder{ process_environment };

  // QProcessEnvironment();
  binder.ctors().add_default();
  // QProcessEnvironment(const QProcessEnvironment &);
  binder.ctors().ctor<const QProcessEnvironment &>().create();
  // ~QProcessEnvironment();
  binder.add_dtor();
  // QProcessEnvironment & operator=(QProcessEnvironment &&);
  binder.operators().assign<QProcessEnvironment &&>();
  // QProcessEnvironment & operator=(const QProcessEnvironment &);
  binder.operators().assign<const QProcessEnvironment &>();
  // void swap(QProcessEnvironment &);
  binder.void_fun<QProcessEnvironment &, &QProcessEnvironment::swap>("swap").create();
  // bool operator==(const QProcessEnvironment &) const;
  binder.operators().eq<const QProcessEnvironment &>();
  // bool operator!=(const QProcessEnvironment &) const;
  binder.operators().neq<const QProcessEnvironment &>();
  // bool isEmpty() const;
  binder.fun<bool, &QProcessEnvironment::isEmpty>("isEmpty").create();
  // void clear();
  binder.void_fun<&QProcessEnvironment::clear>("clear").create();
  // bool contains(const QString &) const;
  binder.fun<bool, const QString &, &QProcessEnvironment::contains>("contains").create();
  // void insert(const QString &, const QString &);
  binder.void_fun<const QString &, const QString &, &QProcessEnvironment::insert>("insert").create();
  // void remove(const QString &);
  binder.void_fun<const QString &, &QProcessEnvironment::remove>("remove").create();
  // QString value(const QString &, const QString &) const;
  binder.fun<QString, const QString &, const QString &, &QProcessEnvironment::value>("value").create();
  // QStringList toStringList() const;
  /// TODO: QStringList toStringList() const;
  // QStringList keys() const;
  /// TODO: QStringList keys() const;
  // void insert(const QProcessEnvironment &);
  binder.void_fun<const QProcessEnvironment &, &QProcessEnvironment::insert>("insert").create();
  // static QProcessEnvironment systemEnvironment();
  binder.static_fun<QProcessEnvironment, &QProcessEnvironment::systemEnvironment>("systemEnvironment").create();
}


static void register_process_process_error_enum(script::Class process)
{
  using namespace script;

  Enum process_error = process.Enum("ProcessError").setId(script::Type::QProcessProcessError).get();

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

  Enum process_state = process.Enum("ProcessState").setId(script::Type::QProcessProcessState).get();

  process_state.addValue("NotRunning", QProcess::NotRunning);
  process_state.addValue("Starting", QProcess::Starting);
  process_state.addValue("Running", QProcess::Running);
}


static void register_process_process_channel_enum(script::Class process)
{
  using namespace script;

  Enum process_channel = process.Enum("ProcessChannel").setId(script::Type::QProcessProcessChannel).get();

  process_channel.addValue("StandardOutput", QProcess::StandardOutput);
  process_channel.addValue("StandardError", QProcess::StandardError);
}


static void register_process_process_channel_mode_enum(script::Class process)
{
  using namespace script;

  Enum process_channel_mode = process.Enum("ProcessChannelMode").setId(script::Type::QProcessProcessChannelMode).get();

  process_channel_mode.addValue("SeparateChannels", QProcess::SeparateChannels);
  process_channel_mode.addValue("MergedChannels", QProcess::MergedChannels);
  process_channel_mode.addValue("ForwardedChannels", QProcess::ForwardedChannels);
  process_channel_mode.addValue("ForwardedOutputChannel", QProcess::ForwardedOutputChannel);
  process_channel_mode.addValue("ForwardedErrorChannel", QProcess::ForwardedErrorChannel);
}


static void register_process_input_channel_mode_enum(script::Class process)
{
  using namespace script;

  Enum input_channel_mode = process.Enum("InputChannelMode").setId(script::Type::QProcessInputChannelMode).get();

  input_channel_mode.addValue("ManagedInputChannel", QProcess::ManagedInputChannel);
  input_channel_mode.addValue("ForwardedInputChannel", QProcess::ForwardedInputChannel);
}


static void register_process_exit_status_enum(script::Class process)
{
  using namespace script;

  Enum exit_status = process.Enum("ExitStatus").setId(script::Type::QProcessExitStatus).get();

  exit_status.addValue("NormalExit", QProcess::NormalExit);
  exit_status.addValue("CrashExit", QProcess::CrashExit);
}


static void register_process_class(script::Namespace ns)
{
  using namespace script;

  Class process = ns.Class("Process").setId(script::Type::QProcess)
    .setBase(script::Type::QIODevice).get();

  register_process_process_error_enum(process);
  register_process_process_state_enum(process);
  register_process_process_channel_enum(process);
  register_process_process_channel_mode_enum(process);
  register_process_input_channel_mode_enum(process);
  register_process_exit_status_enum(process);
  binding::QClass<QProcess> binder{ process, &QProcess::staticMetaObject };

  // QProcess(QObject *);
  binder.ctors().ctor<QObject *>()
    .apply(binding::default_arguments((QObject*) nullptr)).create();
  // ~QProcess();
  binder.add_dtor();
  // void start(const QString &, const QStringList &, QIODevice::OpenMode);
  /// TODO: void start(const QString &, const QStringList &, QIODevice::OpenMode);
  // void start(const QString &, QIODevice::OpenMode);
  binder.void_fun<const QString &, QIODevice::OpenMode, &QProcess::start>("start")
    .apply(binding::default_arguments(QIODevice::OpenMode(QIODevice::ReadWrite))).create();
  // void start(QIODevice::OpenMode);
  binder.void_fun<QIODevice::OpenMode, &QProcess::start>("start").create();
  // bool startDetached(qint64 *);
  /// TODO: bool startDetached(qint64 *);
  // bool open(QIODevice::OpenMode);
  binder.fun<bool, QIODevice::OpenMode, &QProcess::open>("open")
    .apply(binding::default_arguments(QIODevice::OpenMode(QIODevice::ReadWrite))).create();
  // QString program() const;
  binder.fun<QString, &QProcess::program>("program").create();
  // void setProgram(const QString &);
  binder.void_fun<const QString &, &QProcess::setProgram>("setProgram").create();
  // QStringList arguments() const;
  /// TODO: QStringList arguments() const;
  // void setArguments(const QStringList &);
  /// TODO: void setArguments(const QStringList &);
  // QProcess::ProcessChannelMode readChannelMode() const;
  binder.fun<QProcess::ProcessChannelMode, &QProcess::readChannelMode>("readChannelMode").create();
  // void setReadChannelMode(QProcess::ProcessChannelMode);
  binder.void_fun<QProcess::ProcessChannelMode, &QProcess::setReadChannelMode>("setReadChannelMode").create();
  // QProcess::ProcessChannelMode processChannelMode() const;
  binder.fun<QProcess::ProcessChannelMode, &QProcess::processChannelMode>("processChannelMode").create();
  // void setProcessChannelMode(QProcess::ProcessChannelMode);
  binder.void_fun<QProcess::ProcessChannelMode, &QProcess::setProcessChannelMode>("setProcessChannelMode").create();
  // QProcess::InputChannelMode inputChannelMode() const;
  binder.fun<QProcess::InputChannelMode, &QProcess::inputChannelMode>("inputChannelMode").create();
  // void setInputChannelMode(QProcess::InputChannelMode);
  binder.void_fun<QProcess::InputChannelMode, &QProcess::setInputChannelMode>("setInputChannelMode").create();
  // QProcess::ProcessChannel readChannel() const;
  binder.fun<QProcess::ProcessChannel, &QProcess::readChannel>("readChannel").create();
  // void setReadChannel(QProcess::ProcessChannel);
  binder.void_fun<QProcess::ProcessChannel, &QProcess::setReadChannel>("setReadChannel").create();
  // void closeReadChannel(QProcess::ProcessChannel);
  binder.void_fun<QProcess::ProcessChannel, &QProcess::closeReadChannel>("closeReadChannel").create();
  // void closeWriteChannel();
  binder.void_fun<&QProcess::closeWriteChannel>("closeWriteChannel").create();
  // void setStandardInputFile(const QString &);
  binder.void_fun<const QString &, &QProcess::setStandardInputFile>("setStandardInputFile").create();
  // void setStandardOutputFile(const QString &, QIODevice::OpenMode);
  binder.void_fun<const QString &, QIODevice::OpenMode, &QProcess::setStandardOutputFile>("setStandardOutputFile")
    .apply(binding::default_arguments(QIODevice::OpenMode(QIODevice::Truncate))).create();
  // void setStandardErrorFile(const QString &, QIODevice::OpenMode);
  binder.void_fun<const QString &, QIODevice::OpenMode, &QProcess::setStandardErrorFile>("setStandardErrorFile")
    .apply(binding::default_arguments(QIODevice::OpenMode(QIODevice::Truncate))).create();
  // void setStandardOutputProcess(QProcess *);
  /// TODO: void setStandardOutputProcess(QProcess *);
  // QString nativeArguments() const;
  binder.fun<QString, &QProcess::nativeArguments>("nativeArguments").create();
  // void setNativeArguments(const QString &);
  binder.void_fun<const QString &, &QProcess::setNativeArguments>("setNativeArguments").create();
  // QProcess::CreateProcessArgumentModifier createProcessArgumentsModifier() const;
  /// TODO: QProcess::CreateProcessArgumentModifier createProcessArgumentsModifier() const;
  // void setCreateProcessArgumentsModifier(QProcess::CreateProcessArgumentModifier);
  /// TODO: void setCreateProcessArgumentsModifier(QProcess::CreateProcessArgumentModifier);
  // QString workingDirectory() const;
  binder.fun<QString, &QProcess::workingDirectory>("workingDirectory").create();
  // void setWorkingDirectory(const QString &);
  binder.void_fun<const QString &, &QProcess::setWorkingDirectory>("setWorkingDirectory").create();
  // void setEnvironment(const QStringList &);
  /// TODO: void setEnvironment(const QStringList &);
  // QStringList environment() const;
  /// TODO: QStringList environment() const;
  // void setProcessEnvironment(const QProcessEnvironment &);
  binder.void_fun<const QProcessEnvironment &, &QProcess::setProcessEnvironment>("setProcessEnvironment").create();
  // QProcessEnvironment processEnvironment() const;
  binder.fun<QProcessEnvironment, &QProcess::processEnvironment>("processEnvironment").create();
  // QProcess::ProcessError error() const;
  binder.fun<QProcess::ProcessError, &QProcess::error>("error").create();
  // QProcess::ProcessState state() const;
  binder.fun<QProcess::ProcessState, &QProcess::state>("state").create();
  // Q_PID pid() const;
  /// TODO: Q_PID pid() const;
  // qint64 processId() const;
  /// TODO: qint64 processId() const;
  // bool waitForStarted(int);
  binder.fun<bool, int, &QProcess::waitForStarted>("waitForStarted")
    .apply(binding::default_arguments(30000)).create();
  // bool waitForReadyRead(int);
  binder.fun<bool, int, &QProcess::waitForReadyRead>("waitForReadyRead")
    .apply(binding::default_arguments(30000)).create();
  // bool waitForBytesWritten(int);
  binder.fun<bool, int, &QProcess::waitForBytesWritten>("waitForBytesWritten")
    .apply(binding::default_arguments(30000)).create();
  // bool waitForFinished(int);
  binder.fun<bool, int, &QProcess::waitForFinished>("waitForFinished")
    .apply(binding::default_arguments(30000)).create();
  // QByteArray readAllStandardOutput();
  binder.fun<QByteArray, &QProcess::readAllStandardOutput>("readAllStandardOutput").create();
  // QByteArray readAllStandardError();
  binder.fun<QByteArray, &QProcess::readAllStandardError>("readAllStandardError").create();
  // int exitCode() const;
  binder.fun<int, &QProcess::exitCode>("exitCode").create();
  // QProcess::ExitStatus exitStatus() const;
  binder.fun<QProcess::ExitStatus, &QProcess::exitStatus>("exitStatus").create();
  // qint64 bytesAvailable() const;
  /// TODO: qint64 bytesAvailable() const;
  // qint64 bytesToWrite() const;
  /// TODO: qint64 bytesToWrite() const;
  // bool isSequential() const;
  binder.fun<bool, &QProcess::isSequential>("isSequential").create();
  // bool canReadLine() const;
  binder.fun<bool, &QProcess::canReadLine>("canReadLine").create();
  // void close();
  binder.void_fun<&QProcess::close>("close").create();
  // bool atEnd() const;
  binder.fun<bool, &QProcess::atEnd>("atEnd").create();
  // static int execute(const QString &, const QStringList &);
  /// TODO: static int execute(const QString &, const QStringList &);
  // static int execute(const QString &);
  binder.static_fun<int, const QString &, &QProcess::execute>("execute").create();
  // static bool startDetached(const QString &, const QStringList &, const QString &, qint64 *);
  /// TODO: static bool startDetached(const QString &, const QStringList &, const QString &, qint64 *);
  // static bool startDetached(const QString &, const QStringList &);
  /// TODO: static bool startDetached(const QString &, const QStringList &);
  // static bool startDetached(const QString &);
  binder.static_fun<bool, const QString &, &QProcess::startDetached>("startDetached").create();
  // static QStringList systemEnvironment();
  /// TODO: static QStringList systemEnvironment();
  // static QString nullDevice();
  binder.static_fun<QString, &QProcess::nullDevice>("nullDevice").create();
  // void terminate();
  binder.void_fun<&QProcess::terminate>("terminate").create();
  // void kill();
  binder.void_fun<&QProcess::kill>("kill").create();
  // void started(QProcess::QPrivateSignal);
  /// TODO: void started(QProcess::QPrivateSignal);
  // void finished(int);
  binder.sigs().add<int>("finished", "finished(int)");
  // void finished(int, QProcess::ExitStatus);
  binder.sigs().add<int, QProcess::ExitStatus>("finished", "finished(int,QProcess::ExitStatus)");
  // void error(QProcess::ProcessError);
  binder.void_fun<QProcess::ProcessError, &QProcess::error>("error").create();
  // void errorOccurred(QProcess::ProcessError);
  binder.sigs().add<QProcess::ProcessError>("errorOccurred", "errorOccurred(QProcess::ProcessError)");
  // void stateChanged(QProcess::ProcessState);
  binder.sigs().add<QProcess::ProcessState>("stateChanged", "stateChanged(QProcess::ProcessState)");
  // void readyReadStandardOutput();
  binder.sigs().add("readyReadStandardOutput", "readyReadStandardOutput()");
  // void readyReadStandardError();
  binder.sigs().add("readyReadStandardError", "readyReadStandardError()");

  process.engine()->registerQtType(&QProcess::staticMetaObject, process.id());
}


void register_process_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_process_environment_class(ns);
  register_process_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QProcessEnvironment &, QProcessEnvironment &);
  binder.void_fun<QProcessEnvironment &, QProcessEnvironment &, &swap>("swap").create();
}

