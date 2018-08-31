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

  Enum shape = frame.Enum("Shape").setId(script::Type::QFrameShape).get();

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

  Enum shadow = frame.Enum("Shadow").setId(script::Type::QFrameShadow).get();

  shadow.addValue("Plain", QFrame::Plain);
  shadow.addValue("Raised", QFrame::Raised);
  shadow.addValue("Sunken", QFrame::Sunken);
}


static void register_frame_style_mask_enum(script::Class frame)
{
  using namespace script;

  Enum style_mask = frame.Enum("StyleMask").setId(script::Type::QFrameStyleMask).get();

  style_mask.addValue("Shadow_Mask", QFrame::Shadow_Mask);
  style_mask.addValue("Shape_Mask", QFrame::Shape_Mask);
}


static void register_frame_class(script::Namespace ns)
{
  using namespace script;

  Class frame = ns.Class("Frame").setId(script::Type::QFrame)
    .setBase(script::Type::QWidget).get();

  register_frame_shape_enum(frame);
  register_frame_shadow_enum(frame);
  register_frame_style_mask_enum(frame);
  binding::QClass<QFrame> binder{ frame, &QFrame::staticMetaObject };

  // QFrame(QWidget *, Qt::WindowFlags);
  /// TODO: QFrame(QWidget *, Qt::WindowFlags);
  // ~QFrame();
  binder.add_dtor();
  // int frameStyle() const;
  binder.add_fun<int, &QFrame::frameStyle>("frameStyle");
  // void setFrameStyle(int);
  binder.add_void_fun<int, &QFrame::setFrameStyle>("setFrameStyle");
  // int frameWidth() const;
  binder.add_fun<int, &QFrame::frameWidth>("frameWidth");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QFrame::sizeHint>("sizeHint");
  // QFrame::Shape frameShape() const;
  binder.add_fun<QFrame::Shape, &QFrame::frameShape>("frameShape");
  // void setFrameShape(QFrame::Shape);
  binder.add_void_fun<QFrame::Shape, &QFrame::setFrameShape>("setFrameShape");
  // QFrame::Shadow frameShadow() const;
  binder.add_fun<QFrame::Shadow, &QFrame::frameShadow>("frameShadow");
  // void setFrameShadow(QFrame::Shadow);
  binder.add_void_fun<QFrame::Shadow, &QFrame::setFrameShadow>("setFrameShadow");
  // int lineWidth() const;
  binder.add_fun<int, &QFrame::lineWidth>("lineWidth");
  // void setLineWidth(int);
  binder.add_void_fun<int, &QFrame::setLineWidth>("setLineWidth");
  // int midLineWidth() const;
  binder.add_fun<int, &QFrame::midLineWidth>("midLineWidth");
  // void setMidLineWidth(int);
  binder.add_void_fun<int, &QFrame::setMidLineWidth>("setMidLineWidth");
  // QRect frameRect() const;
  binder.add_fun<QRect, &QFrame::frameRect>("frameRect");
  // void setFrameRect(const QRect &);
  binder.add_void_fun<const QRect &, &QFrame::setFrameRect>("setFrameRect");

  frame.engine()->registerQtType(&QFrame::staticMetaObject, frame.id());
}


void register_frame_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_frame_class(ns);
  binding::Namespace binder{ ns };

}

