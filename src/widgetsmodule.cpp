// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE


#include <script/engine.h>
#include <script/module.h>
#include <script/namespace.h>

void register_widget_file(script::Namespace n); // defined in widget.cpp
void register_frame_file(script::Namespace n); // defined in frame.cpp
void register_label_file(script::Namespace n); // defined in label.cpp
void register_abstractbutton_file(script::Namespace n); // defined in abstractbutton.cpp
void register_pushbutton_file(script::Namespace n); // defined in pushbutton.cpp
void register_tabwidget_file(script::Namespace n); // defined in tabwidget.cpp

// Start of non-generated code
void register_newwidget_file(script::Namespace n); // defined in newwidget.cpp
void register_newpushbutton_file(script::Namespace n); // defined in newpushbutton.cpp
// End of non-generated code

void load_widgets_module(script::Module widgets)
{
  // Start of non-generated code
  widgets.engine()->getModule("gui").load();
  // End of non-generated code

  register_widget_file(widgets.root());
  register_frame_file(widgets.root());
  register_label_file(widgets.root());
  register_abstractbutton_file(widgets.root());
  register_pushbutton_file(widgets.root());
  register_tabwidget_file(widgets.root());

  // Start of non-generated code
  register_newwidget_file(widgets.root());
  register_newpushbutton_file(widgets.root());
  // End of non-generated code
}

void cleanup_widgets_module(script::Module gui)
{
  (void) gui;
}

void register_widgets_module(script::Engine *e)
{
  script::Module widgets = e->newModule("widgets", load_widgets_module, cleanup_widgets_module);
}

