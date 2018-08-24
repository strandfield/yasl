// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/screen.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>

static void register_screen_class(script::Namespace ns)
{
  using namespace script;

  Class screen = ns.Class("Screen").setId(script::Type::QScreen)
    .setBase(script::Type::QObject).get();

  binding::QClass<QScreen> binder{ screen, &QScreen::staticMetaObject };

  // ~QScreen();
  binder.add_dtor();
  // QPlatformScreen * handle() const;
  /// TODO: QPlatformScreen * handle() const;
  // QString name() const;
  binder.add_fun<QString, &QScreen::name>("name");
  // QString manufacturer() const;
  binder.add_fun<QString, &QScreen::manufacturer>("manufacturer");
  // QString model() const;
  binder.add_fun<QString, &QScreen::model>("model");
  // QString serialNumber() const;
  binder.add_fun<QString, &QScreen::serialNumber>("serialNumber");
  // int depth() const;
  binder.add_fun<int, &QScreen::depth>("depth");
  // QSize size() const;
  binder.add_fun<QSize, &QScreen::size>("size");
  // QRect geometry() const;
  binder.add_fun<QRect, &QScreen::geometry>("geometry");
  // QSizeF physicalSize() const;
  binder.add_fun<QSizeF, &QScreen::physicalSize>("physicalSize");
  // qreal physicalDotsPerInchX() const;
  binder.add_fun<qreal, &QScreen::physicalDotsPerInchX>("physicalDotsPerInchX");
  // qreal physicalDotsPerInchY() const;
  binder.add_fun<qreal, &QScreen::physicalDotsPerInchY>("physicalDotsPerInchY");
  // qreal physicalDotsPerInch() const;
  binder.add_fun<qreal, &QScreen::physicalDotsPerInch>("physicalDotsPerInch");
  // qreal logicalDotsPerInchX() const;
  binder.add_fun<qreal, &QScreen::logicalDotsPerInchX>("logicalDotsPerInchX");
  // qreal logicalDotsPerInchY() const;
  binder.add_fun<qreal, &QScreen::logicalDotsPerInchY>("logicalDotsPerInchY");
  // qreal logicalDotsPerInch() const;
  binder.add_fun<qreal, &QScreen::logicalDotsPerInch>("logicalDotsPerInch");
  // qreal devicePixelRatio() const;
  binder.add_fun<qreal, &QScreen::devicePixelRatio>("devicePixelRatio");
  // QSize availableSize() const;
  binder.add_fun<QSize, &QScreen::availableSize>("availableSize");
  // QRect availableGeometry() const;
  binder.add_fun<QRect, &QScreen::availableGeometry>("availableGeometry");
  // QList<QScreen *> virtualSiblings() const;
  /// TODO: QList<QScreen *> virtualSiblings() const;
  // QSize virtualSize() const;
  binder.add_fun<QSize, &QScreen::virtualSize>("virtualSize");
  // QRect virtualGeometry() const;
  binder.add_fun<QRect, &QScreen::virtualGeometry>("virtualGeometry");
  // QSize availableVirtualSize() const;
  binder.add_fun<QSize, &QScreen::availableVirtualSize>("availableVirtualSize");
  // QRect availableVirtualGeometry() const;
  binder.add_fun<QRect, &QScreen::availableVirtualGeometry>("availableVirtualGeometry");
  // Qt::ScreenOrientation primaryOrientation() const;
  binder.add_fun<Qt::ScreenOrientation, &QScreen::primaryOrientation>("primaryOrientation");
  // Qt::ScreenOrientation orientation() const;
  binder.add_fun<Qt::ScreenOrientation, &QScreen::orientation>("orientation");
  // Qt::ScreenOrientation nativeOrientation() const;
  binder.add_fun<Qt::ScreenOrientation, &QScreen::nativeOrientation>("nativeOrientation");
  // Qt::ScreenOrientations orientationUpdateMask() const;
  /// TODO: Qt::ScreenOrientations orientationUpdateMask() const;
  // void setOrientationUpdateMask(Qt::ScreenOrientations);
  /// TODO: void setOrientationUpdateMask(Qt::ScreenOrientations);
  // int angleBetween(Qt::ScreenOrientation, Qt::ScreenOrientation) const;
  binder.add_fun<int, Qt::ScreenOrientation, Qt::ScreenOrientation, &QScreen::angleBetween>("angleBetween");
  // QTransform transformBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  binder.add_fun<QTransform, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::transformBetween>("transformBetween");
  // QRect mapBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  binder.add_fun<QRect, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::mapBetween>("mapBetween");
  // bool isPortrait(Qt::ScreenOrientation) const;
  binder.add_fun<bool, Qt::ScreenOrientation, &QScreen::isPortrait>("isPortrait");
  // bool isLandscape(Qt::ScreenOrientation) const;
  binder.add_fun<bool, Qt::ScreenOrientation, &QScreen::isLandscape>("isLandscape");
  // QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: QPixmap grabWindow(WId, int, int, int, int);
  // qreal refreshRate() const;
  binder.add_fun<qreal, &QScreen::refreshRate>("refreshRate");
  // void geometryChanged(const QRect &);
  binder.add_void_fun<const QRect &, &QScreen::geometryChanged>("geometryChanged");
  // void availableGeometryChanged(const QRect &);
  binder.add_void_fun<const QRect &, &QScreen::availableGeometryChanged>("availableGeometryChanged");
  // void physicalSizeChanged(const QSizeF &);
  binder.add_void_fun<const QSizeF &, &QScreen::physicalSizeChanged>("physicalSizeChanged");
  // void physicalDotsPerInchChanged(qreal);
  binder.add_void_fun<qreal, &QScreen::physicalDotsPerInchChanged>("physicalDotsPerInchChanged");
  // void logicalDotsPerInchChanged(qreal);
  binder.add_void_fun<qreal, &QScreen::logicalDotsPerInchChanged>("logicalDotsPerInchChanged");
  // void virtualGeometryChanged(const QRect &);
  binder.add_void_fun<const QRect &, &QScreen::virtualGeometryChanged>("virtualGeometryChanged");
  // void primaryOrientationChanged(Qt::ScreenOrientation);
  binder.add_void_fun<Qt::ScreenOrientation, &QScreen::primaryOrientationChanged>("primaryOrientationChanged");
  // void orientationChanged(Qt::ScreenOrientation);
  binder.add_void_fun<Qt::ScreenOrientation, &QScreen::orientationChanged>("orientationChanged");
  // void refreshRateChanged(qreal);
  binder.add_void_fun<qreal, &QScreen::refreshRateChanged>("refreshRateChanged");

  screen.engine()->registerQtType(&QScreen::staticMetaObject, screen.id());
}


void register_screen_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_screen_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QScreen *);
  /// TODO: QDebug operator<<(QDebug, const QScreen *);
}

