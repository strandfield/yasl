// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE


#include <script/engine.h>
#include <script/module.h>
#include <script/namespace.h>

void register_bytearray_file(script::Namespace n); // defined in bytearray.cpp
void register_char__file(script::Namespace n); // defined in char.cpp
void register_enums_file(script::Namespace n); // defined in enums.cpp
void register_point_file(script::Namespace n); // defined in point.cpp
void register_size_file(script::Namespace n); // defined in size.cpp
void register_rect_file(script::Namespace n); // defined in rect.cpp
void register_margins_file(script::Namespace n); // defined in margins.cpp
void register_datetime_file(script::Namespace n); // defined in datetime.cpp
void register_dir_file(script::Namespace n); // defined in dir.cpp
void register_fileinfo_file(script::Namespace n); // defined in fileinfo.cpp
void register_line_file(script::Namespace n); // defined in line.cpp
void register_url_file(script::Namespace n); // defined in url.cpp
void register_urlquery_file(script::Namespace n); // defined in urlquery.cpp
void register_timezone_file(script::Namespace n); // defined in timezone.cpp
void register_locale_file(script::Namespace n); // defined in locale.cpp
void register_object_file(script::Namespace n); // defined in object.cpp
void register_uuid_file(script::Namespace n); // defined in uuid.cpp
void register_variant_file(script::Namespace n); // defined in variant.cpp
void register_regularexpression_file(script::Namespace n); // defined in regularexpression.cpp
void register_settings_file(script::Namespace n); // defined in settings.cpp
void register_timer_file(script::Namespace n); // defined in timer.cpp
void register_iodevice_file(script::Namespace n); // defined in iodevice.cpp
void register_filedevice_file(script::Namespace n); // defined in filedevice.cpp
void register_file_file(script::Namespace n); // defined in file.cpp
void register_event_file(script::Namespace n); // defined in event.cpp
void register_jsonvalue_file(script::Namespace n); // defined in jsonvalue.cpp
void register_jsonarray_file(script::Namespace n); // defined in jsonarray.cpp
void register_jsonobject_file(script::Namespace n); // defined in jsonobject.cpp
void register_jsondocument_file(script::Namespace n); // defined in jsondocument.cpp
void register_elapsedtimer_file(script::Namespace n); // defined in elapsedtimer.cpp
void register_process_file(script::Namespace n); // defined in process.cpp

// Start of non-generated code
void register_ptr_template(script::Namespace n); // defined in ptr.cpp
void register_vector_template(script::Namespace n); // defined in vector.cpp
void register_qlist_template(script::Namespace n); // defined in list.cpp
void register_newobject_file(script::Namespace n); // defined in newobject.cpp
void register_signals_file(script::Namespace n); // defined in signals.cpp
void register_stringlist_class(script::Namespace n); // defined in string.cpp
// End of non-generated code

void load_core_module(script::Module core)
{
  // Start of non-generated code
  register_ptr_template(core.root());
  register_qlist_template(core.root());
  register_vector_template(core.root());
  register_stringlist_class(core.root());
  // End of non-generated code

  register_bytearray_file(core.root());
  register_char__file(core.root());
  register_enums_file(core.root());
  register_point_file(core.root());
  register_size_file(core.root());
  register_rect_file(core.root());
  register_margins_file(core.root());
  register_datetime_file(core.root());
  register_dir_file(core.root());
  register_fileinfo_file(core.root());
  register_line_file(core.root());
  register_url_file(core.root());
  register_urlquery_file(core.root());
  register_timezone_file(core.root());
  register_locale_file(core.root());
  register_object_file(core.root());
  register_uuid_file(core.root());
  register_variant_file(core.root());
  register_regularexpression_file(core.root());
  register_settings_file(core.root());
  register_timer_file(core.root());
  register_iodevice_file(core.root());
  register_filedevice_file(core.root());
  register_file_file(core.root());
  register_event_file(core.root());
  register_jsonvalue_file(core.root());
  register_jsonarray_file(core.root());
  register_jsonobject_file(core.root());
  register_jsondocument_file(core.root());
  register_elapsedtimer_file(core.root());
  register_process_file(core.root());

  // Start of non-generated code
  register_newobject_file(core.root());
  register_signals_file(core.root());
  // End of non-generated code
}

void cleanup_core_module(script::Module core)
{
  (void) core;
}

void register_core_module(script::Engine *e)
{
  script::Module gui = e->newModule("core", load_core_module, cleanup_core_module);
}

