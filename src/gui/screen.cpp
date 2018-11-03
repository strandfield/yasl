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

  binding::ClassBinder<QScreen> binder{ screen, &QScreen::staticMetaObject };

  // ~QScreen();
  binder.dtor().create();
  // QPlatformScreen * handle() const;
  /// TODO: QPlatformScreen * handle() const;
  // QString name() const;
  binder.fun<QString, &QScreen::name>("name").create();
  // QString manufacturer() const;
  binder.fun<QString, &QScreen::manufacturer>("manufacturer").create();
  // QString model() const;
  binder.fun<QString, &QScreen::model>("model").create();
  // QString serialNumber() const;
  binder.fun<QString, &QScreen::serialNumber>("serialNumber").create();
  // int depth() const;
  binder.fun<int, &QScreen::depth>("depth").create();
  // QSize size() const;
  binder.fun<QSize, &QScreen::size>("size").create();
  // QRect geometry() const;
  binder.fun<QRect, &QScreen::geometry>("geometry").create();
  // QSizeF physicalSize() const;
  binder.fun<QSizeF, &QScreen::physicalSize>("physicalSize").create();
  // qreal physicalDotsPerInchX() const;
  binder.fun<qreal, &QScreen::physicalDotsPerInchX>("physicalDotsPerInchX").create();
  // qreal physicalDotsPerInchY() const;
  binder.fun<qreal, &QScreen::physicalDotsPerInchY>("physicalDotsPerInchY").create();
  // qreal physicalDotsPerInch() const;
  binder.fun<qreal, &QScreen::physicalDotsPerInch>("physicalDotsPerInch").create();
  // qreal logicalDotsPerInchX() const;
  binder.fun<qreal, &QScreen::logicalDotsPerInchX>("logicalDotsPerInchX").create();
  // qreal logicalDotsPerInchY() const;
  binder.fun<qreal, &QScreen::logicalDotsPerInchY>("logicalDotsPerInchY").create();
  // qreal logicalDotsPerInch() const;
  binder.fun<qreal, &QScreen::logicalDotsPerInch>("logicalDotsPerInch").create();
  // qreal devicePixelRatio() const;
  binder.fun<qreal, &QScreen::devicePixelRatio>("devicePixelRatio").create();
  // QSize availableSize() const;
  binder.fun<QSize, &QScreen::availableSize>("availableSize").create();
  // QRect availableGeometry() const;
  binder.fun<QRect, &QScreen::availableGeometry>("availableGeometry").create();
  // QList<QScreen *> virtualSiblings() const;
  /// TODO: QList<QScreen *> virtualSiblings() const;
  // QSize virtualSize() const;
  binder.fun<QSize, &QScreen::virtualSize>("virtualSize").create();
  // QRect virtualGeometry() const;
  binder.fun<QRect, &QScreen::virtualGeometry>("virtualGeometry").create();
  // QSize availableVirtualSize() const;
  binder.fun<QSize, &QScreen::availableVirtualSize>("availableVirtualSize").create();
  // QRect availableVirtualGeometry() const;
  binder.fun<QRect, &QScreen::availableVirtualGeometry>("availableVirtualGeometry").create();
  // Qt::ScreenOrientation primaryOrientation() const;
  binder.fun<Qt::ScreenOrientation, &QScreen::primaryOrientation>("primaryOrientation").create();
  // Qt::ScreenOrientation orientation() const;
  binder.fun<Qt::ScreenOrientation, &QScreen::orientation>("orientation").create();
  // Qt::ScreenOrientation nativeOrientation() const;
  binder.fun<Qt::ScreenOrientation, &QScreen::nativeOrientation>("nativeOrientation").create();
  // Qt::ScreenOrientations orientationUpdateMask() const;
  /// TODO: Qt::ScreenOrientations orientationUpdateMask() const;
  // void setOrientationUpdateMask(Qt::ScreenOrientations);
  /// TODO: void setOrientationUpdateMask(Qt::ScreenOrientations);
  // int angleBetween(Qt::ScreenOrientation, Qt::ScreenOrientation) const;
  binder.fun<int, Qt::ScreenOrientation, Qt::ScreenOrientation, &QScreen::angleBetween>("angleBetween").create();
  // QTransform transformBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  binder.fun<QTransform, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::transformBetween>("transformBetween").create();
  // QRect mapBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  binder.fun<QRect, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::mapBetween>("mapBetween").create();
  // bool isPortrait(Qt::ScreenOrientation) const;
  binder.fun<bool, Qt::ScreenOrientation, &QScreen::isPortrait>("isPortrait").create();
  // bool isLandscape(Qt::ScreenOrientation) const;
  binder.fun<bool, Qt::ScreenOrientation, &QScreen::isLandscape>("isLandscape").create();
  // QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: QPixmap grabWindow(WId, int, int, int, int);
  // qreal refreshRate() const;
  binder.fun<qreal, &QScreen::refreshRate>("refreshRate").create();
  // void geometryChanged(const QRect &);
  binder.void_fun<const QRect &, &QScreen::geometryChanged>("geometryChanged").create();
  // void availableGeometryChanged(const QRect &);
  binder.void_fun<const QRect &, &QScreen::availableGeometryChanged>("availableGeometryChanged").create();
  // void physicalSizeChanged(const QSizeF &);
  binder.void_fun<const QSizeF &, &QScreen::physicalSizeChanged>("physicalSizeChanged").create();
  // void physicalDotsPerInchChanged(qreal);
  binder.void_fun<qreal, &QScreen::physicalDotsPerInchChanged>("physicalDotsPerInchChanged").create();
  // void logicalDotsPerInchChanged(qreal);
  binder.void_fun<qreal, &QScreen::logicalDotsPerInchChanged>("logicalDotsPerInchChanged").create();
  // void virtualGeometryChanged(const QRect &);
  binder.void_fun<const QRect &, &QScreen::virtualGeometryChanged>("virtualGeometryChanged").create();
  // void primaryOrientationChanged(Qt::ScreenOrientation);
  binder.void_fun<Qt::ScreenOrientation, &QScreen::primaryOrientationChanged>("primaryOrientationChanged").create();
  // void orientationChanged(Qt::ScreenOrientation);
  binder.void_fun<Qt::ScreenOrientation, &QScreen::orientationChanged>("orientationChanged").create();
  // void refreshRateChanged(qreal);
  binder.void_fun<qreal, &QScreen::refreshRateChanged>("refreshRateChanged").create();

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

