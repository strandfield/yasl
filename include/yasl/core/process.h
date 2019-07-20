// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_PROCESS_H
#define YASL_CORE_PROCESS_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QProcess>

namespace script {
template<> struct make_type_helper<QProcess> { inline static script::Type get() { return script::Type::QProcess; } };
namespace details { template<> struct tag_resolver<QProcess> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QProcess::ExitStatus> { inline static script::Type get() { return script::Type::QProcessExitStatus; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<QProcess::InputChannelMode> { inline static script::Type get() { return script::Type::QProcessInputChannelMode; } };
#endif
template<> struct make_type_helper<QProcess::ProcessChannel> { inline static script::Type get() { return script::Type::QProcessProcessChannel; } };
template<> struct make_type_helper<QProcess::ProcessChannelMode> { inline static script::Type get() { return script::Type::QProcessProcessChannelMode; } };
template<> struct make_type_helper<QProcess::ProcessError> { inline static script::Type get() { return script::Type::QProcessProcessError; } };
template<> struct make_type_helper<QProcess::ProcessState> { inline static script::Type get() { return script::Type::QProcessProcessState; } };
template<> struct make_type_helper<QProcessEnvironment> { inline static script::Type get() { return script::Type::QProcessEnvironment; } };
} // namespace script

#endif // YASL_CORE_PROCESS_H
