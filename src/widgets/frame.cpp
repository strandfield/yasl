// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/frame.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

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

  // QFrame(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: QFrame(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // ~QFrame();
  bind::destructor<QFrame>(frame).create();
  // int frameStyle() const;
  bind::member_function<QFrame, int, &QFrame::frameStyle>(frame, "frameStyle").create();
  // void setFrameStyle(int);
  bind::void_member_function<QFrame, int, &QFrame::setFrameStyle>(frame, "setFrameStyle").create();
  // int frameWidth() const;
  bind::member_function<QFrame, int, &QFrame::frameWidth>(frame, "frameWidth").create();
  // QSize sizeHint() const;
  bind::member_function<QFrame, QSize, &QFrame::sizeHint>(frame, "sizeHint").create();
  // QFrame::Shape frameShape() const;
  bind::member_function<QFrame, QFrame::Shape, &QFrame::frameShape>(frame, "frameShape").create();
  // void setFrameShape(QFrame::Shape);
  bind::void_member_function<QFrame, QFrame::Shape, &QFrame::setFrameShape>(frame, "setFrameShape").create();
  // QFrame::Shadow frameShadow() const;
  bind::member_function<QFrame, QFrame::Shadow, &QFrame::frameShadow>(frame, "frameShadow").create();
  // void setFrameShadow(QFrame::Shadow);
  bind::void_member_function<QFrame, QFrame::Shadow, &QFrame::setFrameShadow>(frame, "setFrameShadow").create();
  // int lineWidth() const;
  bind::member_function<QFrame, int, &QFrame::lineWidth>(frame, "lineWidth").create();
  // void setLineWidth(int);
  bind::void_member_function<QFrame, int, &QFrame::setLineWidth>(frame, "setLineWidth").create();
  // int midLineWidth() const;
  bind::member_function<QFrame, int, &QFrame::midLineWidth>(frame, "midLineWidth").create();
  // void setMidLineWidth(int);
  bind::void_member_function<QFrame, int, &QFrame::setMidLineWidth>(frame, "setMidLineWidth").create();
  // QRect frameRect() const;
  bind::member_function<QFrame, QRect, &QFrame::frameRect>(frame, "frameRect").create();
  // void setFrameRect(const QRect &);
  bind::void_member_function<QFrame, const QRect &, &QFrame::setFrameRect>(frame, "setFrameRect").create();

  bind::link(frame, &QFrame::staticMetaObject);
}


void register_frame_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_frame_class(ns);

}
