// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_PROCESS_H
#define YASL_CORE_PROCESS_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QProcess>

namespace script { namespace bind {
template<> struct make_type_t<QProcess> { inline static script::Type get() { return script::Type::QProcess; } };
template<> struct tag_resolver<QProcess> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QProcess::ExitStatus> { inline static script::Type get() { return script::Type::QProcessExitStatus; } };
template<> struct make_type_t<QProcess::InputChannelMode> { inline static script::Type get() { return script::Type::QProcessInputChannelMode; } };
template<> struct make_type_t<QProcess::ProcessChannel> { inline static script::Type get() { return script::Type::QProcessProcessChannel; } };
template<> struct make_type_t<QProcess::ProcessChannelMode> { inline static script::Type get() { return script::Type::QProcessProcessChannelMode; } };
template<> struct make_type_t<QProcess::ProcessError> { inline static script::Type get() { return script::Type::QProcessProcessError; } };
template<> struct make_type_t<QProcess::ProcessState> { inline static script::Type get() { return script::Type::QProcessProcessState; } };
template<> struct make_type_t<QProcessEnvironment> { inline static script::Type get() { return script::Type::QProcessEnvironment; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_PROCESS_H
