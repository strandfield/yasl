// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/coremodule.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/enums.h"
#include "yasl/core/event.h"
#include "yasl/core/date.h"
#include "yasl/core/datetime.h"
#include "yasl/core/file.h"
#include "yasl/core/list.h"
#include "yasl/core/locale.h"
#include "yasl/core/margins.h"
#include "yasl/core/object.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/core/time.h"
#include "yasl/core/timezone.h"
#include "yasl/utils/ptr.h"

#include <script/module.h>

void register_stringlist_class(script::Namespace n); // defined in string.cpp

void load_core_module(script::Module core)
{
  register_ptr_template(core.root());
  register_qlist_template(core.root());

  register_stringlist_class(core.root());

  register_core_enums(core.root());
  register_qevent(core.root());
  register_qpoint(core.root());
  register_qmargins(core.root());
  register_qsize(core.root());
  register_qrect(core.root());
  register_date_class(core.root());
  register_time_class(core.root());
  register_timezone_class(core.root());
  register_datetime_class(core.root());
  register_locale_class(core.root());
  register_qbytearray(core.root());
  register_qobject(core.root());
  register_iodevice_class(core.root());
  register_filedevice_class(core.root());
  register_file_class(core.root());
}

void cleanup_core_module(script::Module core)
{
  (void) core;
}

void register_core_module(script::Engine *e)
{
  script::Module core = e->newModule("core", load_core_module, cleanup_core_module);
}