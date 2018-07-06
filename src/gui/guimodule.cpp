// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/guimodule.h"

#include "yasl/gui/closeevent.h"
#include "yasl/gui/hideevent.h"
#include "yasl/gui/keyevent.h"
#include "yasl/gui/mouseevent.h"
#include "yasl/gui/moveevent.h"
#include "yasl/gui/pushbutton.h"
#include "yasl/gui/resizeevent.h"
#include "yasl/gui/showevent.h"
#include "yasl/gui/widget.h"
#include "yasl/gui/wheelevent.h"

#include <script/module.h>


void load_gui_module(script::Module gui)
{
  gui.engine()->getModule("core").load();

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