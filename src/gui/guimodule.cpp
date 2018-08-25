// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/guimodule.h"

#include <script/engine.h>
#include <script/module.h>
#include <script/namespace.h>

void register_bitmap_file(script::Namespace n); // defined in bitmap.cpp
void register_brush_file(script::Namespace n); // defined in brush.cpp
void register_clipboard_file(script::Namespace n); // defined in clipboard.cpp
void register_color_file(script::Namespace n); // defined in color.cpp
void register_cursor_file(script::Namespace n); // defined in cursor.cpp
void register_font_file(script::Namespace n); // defined in font.cpp
void register_fontdatabase_file(script::Namespace n); // defined in fontdatabase.cpp
void register_fontinfo_file(script::Namespace n); // defined in fontinfo.cpp
void register_fontmetrics_file(script::Namespace n); // defined in fontmetrics.cpp
void register_glyphrun_file(script::Namespace n); // defined in glyphrun.cpp
void register_icon_file(script::Namespace n); // defined in icon.cpp
void register_image_file(script::Namespace n); // defined in image.cpp
void register_keysequence_file(script::Namespace n); // defined in keysequence.cpp
void register_painter_file(script::Namespace n); // defined in painter.cpp
void register_painterpath_file(script::Namespace n); // defined in painterpath.cpp
void register_palette_file(script::Namespace n); // defined in palette.cpp
void register_pen_file(script::Namespace n); // defined in pen.cpp
void register_picture_file(script::Namespace n); // defined in picture.cpp
void register_pixelformat_file(script::Namespace n); // defined in pixelformat.cpp
void register_pixmap_file(script::Namespace n); // defined in pixmap.cpp
void register_quaternion_file(script::Namespace n); // defined in quaternion.cpp
void register_region_file(script::Namespace n); // defined in region.cpp
void register_screen_file(script::Namespace n); // defined in screen.cpp
void register_statictext_file(script::Namespace n); // defined in statictext.cpp
void register_textoption_file(script::Namespace n); // defined in textoption.cpp
void register_transform_file(script::Namespace n); // defined in transform.cpp
void register_validator_file(script::Namespace n); // defined in validator.cpp
void register_vector2d_file(script::Namespace n); // defined in vector2d.cpp
void register_vector3d_file(script::Namespace n); // defined in vector3d.cpp
void register_vector4d_file(script::Namespace n); // defined in vector4d.cpp
void register_window_file(script::Namespace n); // defined in window.cpp

void register_guievent_file(script::Namespace n); // defined in guievent.cpp

void register_widget_file(script::Namespace n); // defined in widget.cpp
void register_abstractbutton_file(script::Namespace n); // defined in abstractbutton.cpp
void register_pushbutton_file(script::Namespace n); // defined in pushbutton.cpp

void register_newwidget_file(script::Namespace n); // defined in newwidget.cpp
void register_newpushbutton_file(script::Namespace n); // defined in newpushbutton.cpp

void load_gui_module(script::Module gui)
{
  gui.engine()->getModule("core").load();

  register_bitmap_file(gui.root());
  register_brush_file(gui.root());
  register_clipboard_file(gui.root());
  register_color_file(gui.root());
  register_cursor_file(gui.root());
  register_font_file(gui.root());
  register_fontdatabase_file(gui.root());
  register_fontinfo_file(gui.root());
  register_fontmetrics_file(gui.root());
  register_glyphrun_file(gui.root());
  register_icon_file(gui.root());
  register_image_file(gui.root());
  register_keysequence_file(gui.root());
  register_painter_file(gui.root());
  register_painterpath_file(gui.root());
  register_palette_file(gui.root());
  register_pen_file(gui.root());
  register_picture_file(gui.root());
  register_pixelformat_file(gui.root());
  register_pixmap_file(gui.root());
  register_quaternion_file(gui.root());
  register_region_file(gui.root());
  register_screen_file(gui.root());
  register_statictext_file(gui.root());
  register_textoption_file(gui.root());
  register_transform_file(gui.root());
  register_validator_file(gui.root());
  register_vector2d_file(gui.root());
  register_vector3d_file(gui.root());
  register_vector4d_file(gui.root());
  register_window_file(gui.root());

  // Event classes
  register_guievent_file(gui.root());

  register_widget_file(gui.root());
  register_abstractbutton_file(gui.root());
  register_pushbutton_file(gui.root());

  register_newwidget_file(gui.root());
  register_newpushbutton_file(gui.root());
}

void cleanup_gui_module(script::Module gui)
{
  (void) gui;
}

void register_gui_module(script::Engine *e)
{
  script::Module gui = e->newModule("gui", load_gui_module, cleanup_gui_module);
}