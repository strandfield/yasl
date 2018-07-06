// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WIDGET_H
#define YASL_GUI_WIDGET_H

#include "yasl/core/list.h"
#include "yasl/core/object.h"
#include "yasl/utils/ptr.h"

#include <script/namespace.h>

#include <QWidget>

void register_qwidget(script::Namespace n);
script::Type get_qwidget_type();
script::Type get_ref_qwidget_type();
script::Type get_ptr_qwidget_type();
script::Type get_qlist_qwidget_type();
void register_new_widget_template(script::Namespace n);
script::Value make_widget(QWidget *widget, script::Engine *e);

class Widget : public QWidget
{
  Q_OBJECT
public:
  Widget();

public:
  void QWidgetCloseEvent(QCloseEvent *e);
  void QWidgetEnterEvent(QEvent *e);
  void QWidgetHideEvent(QHideEvent *e);
  void QWidgetKeyPressEvent(QKeyEvent *e);
  void QWidgetKeyReleaseEvent(QKeyEvent *e);
  void QWidgetLeaveEvent(QEvent *e);
  void QWidgetMouseDoubleClickEvent(QMouseEvent *e);
  void QWidgetMouseMoveEvent(QMouseEvent *e);
  void QWidgetMousePressEvent(QMouseEvent *e);
  void QWidgetMouseReleaseEvent(QMouseEvent *e);
  void QWidgetMoveEvent(QMoveEvent *e);
  void QWidgetPaintEvent(QPaintEvent *e);
  void QWidgetResizeEvent(QResizeEvent *e);
  void QWidgetShowEvent(QShowEvent *e);
  void QWidgetWheelEvent(QWheelEvent *e);

private:
  script::Value self() const;

private:
  void closeEvent(QCloseEvent *e) override;
  void enterEvent(QEvent *e) override;
  void hideEvent(QHideEvent *e) override;
  void keyPressEvent(QKeyEvent *e) override;
  void keyReleaseEvent(QKeyEvent *e) override;
  void leaveEvent(QEvent *e) override;
  void mouseDoubleClickEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void mousePressEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;
  void moveEvent(QMoveEvent *e) override;
  void paintEvent(QPaintEvent *e) override;
  void resizeEvent(QResizeEvent *e) override;
  void showEvent(QShowEvent *e) override;
  void wheelEvent(QWheelEvent *e) override;

public:
  struct Callbacks
  {
    script::Function close;
    script::Function enter;
    script::Function hide;
    script::Function keyPress;
    script::Function keyRelease;
    script::Function leave;
    script::Function mouseDoubleClick;
    script::Function mouseMove;
    script::Function mousePress;
    script::Function mouseRelease;
    script::Function move;
    script::Function paint;
    script::Function resize;
    script::Function show;
    script::Function wheel;
  };
  Callbacks mCallbacks;
};


namespace binding
{

template<> struct make_type_t<QWidget*> { inline static script::Type get() { return get_ref_qwidget_type(); } };
template<> struct make_type_t<Widget*> { inline static script::Type get() { return get_ref_qwidget_type(); } };
template<> struct make_type_t<QList<QWidget*>> { inline static script::Type get() { return get_qlist_qwidget_type(); } };
template<> struct make_type_t<Ptr<QWidget*>> { inline static script::Type get() { return get_ptr_qwidget_type(); } };

template<> inline QWidget* value_cast<QWidget*>(const script::Value & val)
{
  return qobject_cast<QWidget*>(value_cast<QObject*>(val));
}

template<> inline Widget* value_cast<Widget*>(const script::Value & val)
{
  return qobject_cast<Widget*>(value_cast<QObject*>(val));
}

template<> inline script::Value make_value(QWidget *widget, script::Engine *e)
{
  return make_widget(widget, e);
}

} // namespace binding

#endif // YASL_GUI_WIDGET_H
