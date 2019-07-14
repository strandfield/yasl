// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_PAIR_H
#define YASL_COMMONS_PAIR_H

#include "yasl/common/types.h"

#include <script/classtemplatenativebackend.h>

#include <QPair>

namespace script
{

class PairTemplate : public ClassTemplateNativeBackend
{
  Class instantiate(ClassTemplateInstanceBuilder& builder) override;
};

} // namespace script

#endif // YASL_COMMONS_PAIR_H
