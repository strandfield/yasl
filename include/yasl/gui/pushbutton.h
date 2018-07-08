// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PUSH_BUTTON_H
#define YASL_GUI_PUSH_BUTTON_H

#include "yasl/gui/widget.h"

#include <QPushButton>

void register_qpushbutton(script::Namespace n);

namespace binding
{

template<> inline QAbstractButton* value_cast<QAbstractButton*>(const script::Value & val)
{
  return qobject_cast<QAbstractButton*>(value_cast<QObject*>(val));
}

template<> inline QPushButton* value_cast<QPushButton*>(const script::Value & val)
{
  return qobject_cast<QPushButton*>(value_cast<QObject*>(val));
}


} // namespace binding

#endif // YASL_GUI_PUSH_BUTTON_H
