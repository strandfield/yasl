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
void register_checkbox_file(script::Namespace n); // defined in checkbox.cpp
void register_pushbutton_file(script::Namespace n); // defined in pushbutton.cpp
void register_tabwidget_file(script::Namespace n); // defined in tabwidget.cpp
void register_lineedit_file(script::Namespace n); // defined in lineedit.cpp
void register_groupbox_file(script::Namespace n); // defined in groupbox.cpp
void register_combobox_file(script::Namespace n); // defined in combobox.cpp
void register_fontcombobox_file(script::Namespace n); // defined in fontcombobox.cpp
void register_abstractslider_file(script::Namespace n); // defined in abstractslider.cpp
void register_slider_file(script::Namespace n); // defined in slider.cpp
void register_scrollbar_file(script::Namespace n); // defined in scrollbar.cpp
void register_dial_file(script::Namespace n); // defined in dial.cpp
void register_abstractspinbox_file(script::Namespace n); // defined in abstractspinbox.cpp
void register_spinbox_file(script::Namespace n); // defined in spinbox.cpp
void register_datetimeedit_file(script::Namespace n); // defined in datetimeedit.cpp
void register_radiobutton_file(script::Namespace n); // defined in radiobutton.cpp
void register_toolbutton_file(script::Namespace n); // defined in toolbutton.cpp
void register_action_file(script::Namespace n); // defined in action.cpp
void register_menu_file(script::Namespace n); // defined in menu.cpp
void register_layout_file(script::Namespace n); // defined in layout.cpp
void register_boxlayout_file(script::Namespace n); // defined in boxlayout.cpp
void register_formlayout_file(script::Namespace n); // defined in formlayout.cpp
void register_gridlayout_file(script::Namespace n); // defined in gridlayout.cpp
void register_stackedlayout_file(script::Namespace n); // defined in stackedlayout.cpp
void register_dialog_file(script::Namespace n); // defined in dialog.cpp
void register_messagebox_file(script::Namespace n); // defined in messagebox.cpp
void register_filedialog_file(script::Namespace n); // defined in filedialog.cpp
void register_errormessage_file(script::Namespace n); // defined in errormessage.cpp
void register_colordialog_file(script::Namespace n); // defined in colordialog.cpp
void register_fontdialog_file(script::Namespace n); // defined in fontdialog.cpp
void register_inputdialog_file(script::Namespace n); // defined in inputdialog.cpp
void register_progressdialog_file(script::Namespace n); // defined in progressdialog.cpp
void register_wizard_file(script::Namespace n); // defined in wizard.cpp
void register_toolbar_file(script::Namespace n); // defined in toolbar.cpp

void load_widgets_module(script::Module widgets)
{
  // Start of non-generated code
  widgets.engine()->getModule("gui").load();
  // End of non-generated code

  register_widget_file(widgets.root());
  register_action_file(widgets.root());
  register_frame_file(widgets.root());
  register_label_file(widgets.root());
  register_abstractbutton_file(widgets.root());
  register_checkbox_file(widgets.root());
  register_pushbutton_file(widgets.root());
  register_radiobutton_file(widgets.root());
  register_toolbutton_file(widgets.root());
  register_tabwidget_file(widgets.root());
  register_lineedit_file(widgets.root());
  register_groupbox_file(widgets.root());
  register_combobox_file(widgets.root());
  register_fontcombobox_file(widgets.root());
  register_abstractslider_file(widgets.root());
  register_dial_file(widgets.root());
  register_scrollbar_file(widgets.root());
  register_slider_file(widgets.root());
  register_abstractspinbox_file(widgets.root());
  register_spinbox_file(widgets.root());
  register_datetimeedit_file(widgets.root());
  register_menu_file(widgets.root());
  register_layout_file(widgets.root());
  register_boxlayout_file(widgets.root());
  register_formlayout_file(widgets.root());
  register_gridlayout_file(widgets.root());
  register_stackedlayout_file(widgets.root());
  register_dialog_file(widgets.root());
  register_messagebox_file(widgets.root());
  register_filedialog_file(widgets.root());
  register_errormessage_file(widgets.root());
  register_colordialog_file(widgets.root());
  register_fontdialog_file(widgets.root());
  register_inputdialog_file(widgets.root());
  register_progressdialog_file(widgets.root());
  register_wizard_file(widgets.root());
  register_toolbar_file(widgets.root());
}

void cleanup_widgets_module(script::Module gui)
{
  (void) gui;
}

void register_widgets_module(script::Engine *e)
{
  script::Module widgets = e->newModule("widgets", load_widgets_module, cleanup_widgets_module);
}

