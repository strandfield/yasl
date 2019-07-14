// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_REGION_H
#define YASL_GUI_REGION_H

#include "yasl/common/types.h"

#include <QRegion>

namespace script {
template<> struct make_type_helper<QRegion> { inline static script::Type get() { return script::Type::QRegion; } };
template<> struct make_type_helper<QRegion::RegionType> { inline static script::Type get() { return script::Type::QRegionRegionType; } };
} // namespace script

#endif // YASL_GUI_REGION_H
