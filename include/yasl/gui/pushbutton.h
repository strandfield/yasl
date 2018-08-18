// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PUSH_BUTTON_H
#define YASL_GUI_PUSH_BUTTON_H

#include "yasl/gui/widget.h"

#include <QPushButton>

namespace binding
{

//template<> struct storage_type<QAbstractButton> { typedef QAbstractButton* type; };
//template<> inline QAbstractButton* get<QAbstractButton>(const script::Value & val) { return qobject_cast<QAbstractButton*>(val.toQObject()); }
static_assert(std::is_same<binding::storage_type<QAbstractButton>::type, QAbstractButton*>::value, "QAbstractButton must be stored as QAbstractButton*");

//template<> struct storage_type<QPushButton> { typedef QPushButton* type; };
//template<> inline QPushButton* get<QPushButton>(const script::Value & val) { return qobject_cast<QPushButton*>(val.toQObject()); }

static_assert(std::is_same<binding::storage_type<QPushButton>::type, QPushButton*>::value, "QPushButton must be stored as QPushButton*");

} // namespace binding

#endif // YASL_GUI_PUSH_BUTTON_H
