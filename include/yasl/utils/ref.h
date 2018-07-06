// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_REF_H
#define YASL_UTILS_REF_H

namespace script
{
class Class;
class Engine;
class Namespace;
class Type;
class Value;
} // namespace script

class QObject;

void register_ref_template(script::Namespace ns);

script::Value make_ref(script::Engine *e, const script::Type & ref_type, QObject *value);
script::Class get_ref_type(script::Engine *e, const script::Type & object_type);


#endif // YASL_UTILS_REF_H
