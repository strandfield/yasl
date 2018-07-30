// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/guimodule.h"

#include <script/engine.h>
#include <script/module.h>
#include <script/namespace.h>

void register_bitmap_file(script::Namespace n); // defined in bitmap.cpp
void register_color_file(script::Namespace n); // defined in color.cpp
void register_cursor_file(script::Namespace n); // defined in cursor.cpp
void register_icon_file(script::Namespace n); // defined in icon.cpp
void register_image_file(script::Namespace n); // defined in image.cpp
void register_painterpath_file(script::Namespace n); // defined in painterpath.cpp
void register_pixmap_file(script::Namespace n); // defined in pixmap.cpp
void register_region_file(script::Namespace n); // defined in region.cpp
void register_transform_file(script::Namespace n); // defined in transform.cpp
void register_qcloseevent(script::Namespace n); // defined in closeevent.cpp
void register_qhideevent(script::Namespace n); // defined in hideevent.cpp
void register_qkeyevent(script::Namespace n); // defined in keyevent.cpp
void register_qmouseevent(script::Namespace n); // defined in mouseevent.cpp
void register_qmoveevent(script::Namespace n); // defined in moveevent.cpp
void register_qpaintevent(script::Namespace n); // defined in paintevent.cpp
void register_qpushbutton(script::Namespace n); // defined in pushbutton.cpp
void register_qresizeevent(script::Namespace n); // defined in resizeevent.cpp
void register_qshowevent(script::Namespace n); // defined in showevent.cpp
void register_qwheelevent(script::Namespace n); // defined in wheelevent.cpp
void register_qwidget(script::Namespace n); // defined in widget.cpp

void load_gui_module(script::Module gui)
{
  gui.engine()->getModule("core").load();

  register_bitmap_file(gui.root());
  register_color_file(gui.root());
  register_cursor_file(gui.root());
  register_icon_file(gui.root());
  register_image_file(gui.root());
  register_painterpath_file(gui.root());
  register_pixmap_file(gui.root());
  register_region_file(gui.root());
  register_transform_file(gui.root());

  // Event classes
  register_qcloseevent(gui.root());
  register_qhideevent(gui.root());
  register_qkeyevent(gui.root());
  register_qmouseevent(gui.root());
  register_qmoveevent(gui.root());
  register_qresizeevent(gui.root());
  register_qshowevent(gui.root());
  register_qwheelevent(gui.root());

  register_qwidget(gui.root());
  register_qpushbutton(gui.root());
}

void cleanup_gui_module(script::Module gui)
{
  (void) gui;
}

void register_gui_module(script::Engine *e)
{
  script::Module gui = e->newModule("gui", load_gui_module, cleanup_gui_module);
}