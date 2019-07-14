// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_REF_H
#define YASL_COMMONS_REF_H

#include <script/types.h>
#include <script/classtemplatenativebackend.h>

namespace script
{
class Class;
class Engine;
class Namespace;
class Type;
class Value;
} // namespace script

class QObject;

namespace script
{

void register_ref_template(script::Namespace ns);

script::Class register_ref_specialization(script::Engine *e, script::Type object_type, script::Type::BuiltInType type_id);
script::Value make_ref(script::Engine *e, const script::Type & ref_type, QObject *value);
script::Class get_ref_type(script::Engine *e, const script::Type & object_type);

class RefTemplate : public ClassTemplateNativeBackend
{
  Class instantiate(ClassTemplateInstanceBuilder& builder) override;
};

} // namespace script

#endif // YASL_COMMONS_REF_H
