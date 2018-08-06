// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/screen.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"

#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"

#include "yasl/gui/pixmap.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_screen_class(script::Namespace ns)
{
  using namespace script;

  Class screen = ns.Class("Screen").setId(script::Type::QScreen)
    .setBase(script::Type::QObject).get();

  binding::QClass<QScreen> binder{ screen, &QScreen::staticMetaObject };

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
  binder.add_fun<QList<QScreen *>, &QScreen::virtualSiblings>("virtualSiblings");
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
  binder.add_fun<Qt::ScreenOrientations, &QScreen::orientationUpdateMask>("orientationUpdateMask");
  // void setOrientationUpdateMask(Qt::ScreenOrientations);
  binder.add_void_fun<Qt::ScreenOrientations, &QScreen::setOrientationUpdateMask>("setOrientationUpdateMask");
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
  binder.add_fun<QPixmap, WId, int, int, int, int, &QScreen::grabWindow>("grabWindow");
  // qreal refreshRate() const;
  binder.add_fun<qreal, &QScreen::refreshRate>("refreshRate");
  
  /* Signals */
  // void geometryChanged(const QRect &);
  binder.sigs().add<const QRect &>("geometryChanged", "geometryChanged(const QRect &)");
  // void availableGeometryChanged(const QRect &);
  binder.sigs().add<const QRect &>("availableGeometryChanged", "availableGeometryChanged(const QRect &)");
  // void physicalSizeChanged(const QSizeF &);
  /// TODO: binder.sigs().add<const QSizeF &>("physicalSizeChanged", "physicalSizeChanged(const QSizeF &)");
  // void physicalDotsPerInchChanged(qreal);
  binder.sigs().add<qreal>("physicalDotsPerInchChanged", "physicalDotsPerInchChanged(qreal)");
  // void logicalDotsPerInchChanged(qreal);
  binder.sigs().add<qreal>("logicalDotsPerInchChanged", "logicalDotsPerInchChanged(qreal)");
  // void virtualGeometryChanged(const QRect &);
  binder.sigs().add<const QRect &>("virtualGeometryChanged", "virtualGeometryChanged(const QRect &)");
  // void primaryOrientationChanged(Qt::ScreenOrientation);
  binder.sigs().add<Qt::ScreenOrientation>("primaryOrientationChanged", "primaryOrientationChanged(Qt::ScreenOrientation)");
  // void orientationChanged(Qt::ScreenOrientation);
  binder.sigs().add<Qt::ScreenOrientation>("orientationChanged", "orientationChanged(Qt::ScreenOrientation)");
  // void refreshRateChanged(qreal);
  binder.sigs().add<qreal>("refreshRateChanged", "refreshRateChanged(qreal)");


  ns.engine()->registerQtType(&QScreen::staticMetaObject, screen.id());
}

void register_screen_file(script::Namespace root)
{
  using namespace script;

  register_screen_class(root);
  binding::Namespace binder{ root };

  // QDebug operator<<(QDebug, const QScreen *);
  binder.operators().left_shift<QDebug, QDebug, const QScreen *>();
}

