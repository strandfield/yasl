// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DATASTREAM_H
#define YASL_CORE_DATASTREAM_H

#include "yasl/binding2/types.h"

#include <QDataStream>

namespace script { namespace bind {
template<> struct make_type_t<QDataStream> { inline static script::Type get() { return script::Type::QDataStream; } };
template<> struct make_type_t<QDataStream::ByteOrder> { inline static script::Type get() { return script::Type::QDataStreamByteOrder; } };
template<> struct make_type_t<QDataStream::FloatingPointPrecision> { inline static script::Type get() { return script::Type::QDataStreamFloatingPointPrecision; } };
template<> struct make_type_t<QDataStream::Status> { inline static script::Type get() { return script::Type::QDataStreamStatus; } };
template<> struct make_type_t<QDataStream::Version> { inline static script::Type get() { return script::Type::QDataStreamVersion; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_DATASTREAM_H
