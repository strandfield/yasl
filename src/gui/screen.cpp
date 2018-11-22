// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/screen.h"

#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>

static void register_screen_class(script::Namespace ns)
{
  using namespace script;

  Class screen = ns.newClass("Screen").setId(script::Type::QScreen)
    .setBase(script::Type::QObject).get();


  // ~QScreen();
  bind::destructor<QScreen>(screen).create();
  // QPlatformScreen * handle() const;
  /// TODO: QPlatformScreen * handle() const;
  // QString name() const;
  bind::member_function<QScreen, QString, &QScreen::name>(screen, "name").create();
  // QString manufacturer() const;
  bind::member_function<QScreen, QString, &QScreen::manufacturer>(screen, "manufacturer").create();
  // QString model() const;
  bind::member_function<QScreen, QString, &QScreen::model>(screen, "model").create();
  // QString serialNumber() const;
  bind::member_function<QScreen, QString, &QScreen::serialNumber>(screen, "serialNumber").create();
  // int depth() const;
  bind::member_function<QScreen, int, &QScreen::depth>(screen, "depth").create();
  // QSize size() const;
  bind::member_function<QScreen, QSize, &QScreen::size>(screen, "size").create();
  // QRect geometry() const;
  bind::member_function<QScreen, QRect, &QScreen::geometry>(screen, "geometry").create();
  // QSizeF physicalSize() const;
  bind::member_function<QScreen, QSizeF, &QScreen::physicalSize>(screen, "physicalSize").create();
  // qreal physicalDotsPerInchX() const;
  bind::member_function<QScreen, qreal, &QScreen::physicalDotsPerInchX>(screen, "physicalDotsPerInchX").create();
  // qreal physicalDotsPerInchY() const;
  bind::member_function<QScreen, qreal, &QScreen::physicalDotsPerInchY>(screen, "physicalDotsPerInchY").create();
  // qreal physicalDotsPerInch() const;
  bind::member_function<QScreen, qreal, &QScreen::physicalDotsPerInch>(screen, "physicalDotsPerInch").create();
  // qreal logicalDotsPerInchX() const;
  bind::member_function<QScreen, qreal, &QScreen::logicalDotsPerInchX>(screen, "logicalDotsPerInchX").create();
  // qreal logicalDotsPerInchY() const;
  bind::member_function<QScreen, qreal, &QScreen::logicalDotsPerInchY>(screen, "logicalDotsPerInchY").create();
  // qreal logicalDotsPerInch() const;
  bind::member_function<QScreen, qreal, &QScreen::logicalDotsPerInch>(screen, "logicalDotsPerInch").create();
  // qreal devicePixelRatio() const;
  bind::member_function<QScreen, qreal, &QScreen::devicePixelRatio>(screen, "devicePixelRatio").create();
  // QSize availableSize() const;
  bind::member_function<QScreen, QSize, &QScreen::availableSize>(screen, "availableSize").create();
  // QRect availableGeometry() const;
  bind::member_function<QScreen, QRect, &QScreen::availableGeometry>(screen, "availableGeometry").create();
  // QList<QScreen *> virtualSiblings() const;
  /// TODO: QList<QScreen *> virtualSiblings() const;
  // QSize virtualSize() const;
  bind::member_function<QScreen, QSize, &QScreen::virtualSize>(screen, "virtualSize").create();
  // QRect virtualGeometry() const;
  bind::member_function<QScreen, QRect, &QScreen::virtualGeometry>(screen, "virtualGeometry").create();
  // QSize availableVirtualSize() const;
  bind::member_function<QScreen, QSize, &QScreen::availableVirtualSize>(screen, "availableVirtualSize").create();
  // QRect availableVirtualGeometry() const;
  bind::member_function<QScreen, QRect, &QScreen::availableVirtualGeometry>(screen, "availableVirtualGeometry").create();
  // Qt::ScreenOrientation primaryOrientation() const;
  bind::member_function<QScreen, Qt::ScreenOrientation, &QScreen::primaryOrientation>(screen, "primaryOrientation").create();
  // Qt::ScreenOrientation orientation() const;
  bind::member_function<QScreen, Qt::ScreenOrientation, &QScreen::orientation>(screen, "orientation").create();
  // Qt::ScreenOrientation nativeOrientation() const;
  bind::member_function<QScreen, Qt::ScreenOrientation, &QScreen::nativeOrientation>(screen, "nativeOrientation").create();
  // Qt::ScreenOrientations orientationUpdateMask() const;
  /// TODO: Qt::ScreenOrientations orientationUpdateMask() const;
  // void setOrientationUpdateMask(Qt::ScreenOrientations);
  /// TODO: void setOrientationUpdateMask(Qt::ScreenOrientations);
  // int angleBetween(Qt::ScreenOrientation, Qt::ScreenOrientation) const;
  bind::member_function<QScreen, int, Qt::ScreenOrientation, Qt::ScreenOrientation, &QScreen::angleBetween>(screen, "angleBetween").create();
  // QTransform transformBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  bind::member_function<QScreen, QTransform, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::transformBetween>(screen, "transformBetween").create();
  // QRect mapBetween(Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &) const;
  bind::member_function<QScreen, QRect, Qt::ScreenOrientation, Qt::ScreenOrientation, const QRect &, &QScreen::mapBetween>(screen, "mapBetween").create();
  // bool isPortrait(Qt::ScreenOrientation) const;
  bind::member_function<QScreen, bool, Qt::ScreenOrientation, &QScreen::isPortrait>(screen, "isPortrait").create();
  // bool isLandscape(Qt::ScreenOrientation) const;
  bind::member_function<QScreen, bool, Qt::ScreenOrientation, &QScreen::isLandscape>(screen, "isLandscape").create();
  // QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: QPixmap grabWindow(WId, int, int, int, int);
  // qreal refreshRate() const;
  bind::member_function<QScreen, qreal, &QScreen::refreshRate>(screen, "refreshRate").create();
  // void geometryChanged(const QRect &);
  bind::void_member_function<QScreen, const QRect &, &QScreen::geometryChanged>(screen, "geometryChanged").create();
  // void availableGeometryChanged(const QRect &);
  bind::void_member_function<QScreen, const QRect &, &QScreen::availableGeometryChanged>(screen, "availableGeometryChanged").create();
  // void physicalSizeChanged(const QSizeF &);
  bind::void_member_function<QScreen, const QSizeF &, &QScreen::physicalSizeChanged>(screen, "physicalSizeChanged").create();
  // void physicalDotsPerInchChanged(qreal);
  bind::void_member_function<QScreen, qreal, &QScreen::physicalDotsPerInchChanged>(screen, "physicalDotsPerInchChanged").create();
  // void logicalDotsPerInchChanged(qreal);
  bind::void_member_function<QScreen, qreal, &QScreen::logicalDotsPerInchChanged>(screen, "logicalDotsPerInchChanged").create();
  // void virtualGeometryChanged(const QRect &);
  bind::void_member_function<QScreen, const QRect &, &QScreen::virtualGeometryChanged>(screen, "virtualGeometryChanged").create();
  // void primaryOrientationChanged(Qt::ScreenOrientation);
  bind::void_member_function<QScreen, Qt::ScreenOrientation, &QScreen::primaryOrientationChanged>(screen, "primaryOrientationChanged").create();
  // void orientationChanged(Qt::ScreenOrientation);
  bind::void_member_function<QScreen, Qt::ScreenOrientation, &QScreen::orientationChanged>(screen, "orientationChanged").create();
  // void refreshRateChanged(qreal);
  bind::void_member_function<QScreen, qreal, &QScreen::refreshRateChanged>(screen, "refreshRateChanged").create();

  bind::link(screen, &QScreen::staticMetaObject);
}


void register_screen_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_screen_class(ns);

  // QDebug operator<<(QDebug, const QScreen *);
  /// TODO: QDebug operator<<(QDebug, const QScreen *);
}

