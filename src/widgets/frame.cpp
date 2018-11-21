// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/frame.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/widgets/frame.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_frame_shape_enum(script::Class frame)
{
  using namespace script;

  Enum shape = frame.newEnum("Shape").setId(script::Type::QFrameShape).get();

  shape.addValue("NoFrame", QFrame::NoFrame);
  shape.addValue("Box", QFrame::Box);
  shape.addValue("Panel", QFrame::Panel);
  shape.addValue("WinPanel", QFrame::WinPanel);
  shape.addValue("HLine", QFrame::HLine);
  shape.addValue("VLine", QFrame::VLine);
  shape.addValue("StyledPanel", QFrame::StyledPanel);
}


static void register_frame_shadow_enum(script::Class frame)
{
  using namespace script;

  Enum shadow = frame.newEnum("Shadow").setId(script::Type::QFrameShadow).get();

  shadow.addValue("Plain", QFrame::Plain);
  shadow.addValue("Raised", QFrame::Raised);
  shadow.addValue("Sunken", QFrame::Sunken);
}


static void register_frame_style_mask_enum(script::Class frame)
{
  using namespace script;

  Enum style_mask = frame.newEnum("StyleMask").setId(script::Type::QFrameStyleMask).get();

  style_mask.addValue("Shadow_Mask", QFrame::Shadow_Mask);
  style_mask.addValue("Shape_Mask", QFrame::Shape_Mask);
}


static void register_frame_class(script::Namespace ns)
{
  using namespace script;

  Class frame = ns.newClass("Frame").setId(script::Type::QFrame)
    .setBase(script::Type::QWidget).get();

  register_frame_shape_enum(frame);
  register_frame_shadow_enum(frame);
  register_frame_style_mask_enum(frame);
  binding::ClassBinder<QFrame> binder{ frame, &QFrame::staticMetaObject };

  // QFrame(QWidget *, Qt::WindowFlags);
  /// TODO: QFrame(QWidget *, Qt::WindowFlags);
  // ~QFrame();
  binder.dtor().create();
  // int frameStyle() const;
  binder.fun<int, &QFrame::frameStyle>("frameStyle").create();
  // void setFrameStyle(int);
  binder.void_fun<int, &QFrame::setFrameStyle>("setFrameStyle").create();
  // int frameWidth() const;
  binder.fun<int, &QFrame::frameWidth>("frameWidth").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QFrame::sizeHint>("sizeHint").create();
  // QFrame::Shape frameShape() const;
  binder.fun<QFrame::Shape, &QFrame::frameShape>("frameShape").create();
  // void setFrameShape(QFrame::Shape);
  binder.void_fun<QFrame::Shape, &QFrame::setFrameShape>("setFrameShape").create();
  // QFrame::Shadow frameShadow() const;
  binder.fun<QFrame::Shadow, &QFrame::frameShadow>("frameShadow").create();
  // void setFrameShadow(QFrame::Shadow);
  binder.void_fun<QFrame::Shadow, &QFrame::setFrameShadow>("setFrameShadow").create();
  // int lineWidth() const;
  binder.fun<int, &QFrame::lineWidth>("lineWidth").create();
  // void setLineWidth(int);
  binder.void_fun<int, &QFrame::setLineWidth>("setLineWidth").create();
  // int midLineWidth() const;
  binder.fun<int, &QFrame::midLineWidth>("midLineWidth").create();
  // void setMidLineWidth(int);
  binder.void_fun<int, &QFrame::setMidLineWidth>("setMidLineWidth").create();
  // QRect frameRect() const;
  binder.fun<QRect, &QFrame::frameRect>("frameRect").create();
  // void setFrameRect(const QRect &);
  binder.void_fun<const QRect &, &QFrame::setFrameRect>("setFrameRect").create();

  frame.engine()->registerQtType(&QFrame::staticMetaObject, frame.id());
}


void register_frame_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_frame_class(ns);
  binding::Namespace binder{ ns };

}

