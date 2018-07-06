// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_MODULE_H
#define YASL_GUI_MODULE_H

namespace script
{
class Engine;
class Namespace;
} // namespace script

void register_gui_module(script::Engine *e);

#endif // YASL_GUI_MODULE_H
