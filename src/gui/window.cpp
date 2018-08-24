// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/window.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/utils/ref.h"

#include "yasl/core/enums.h"
#include "yasl/core/margins.h"
#include "yasl/core/object.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/cursor.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/region.h"
#include "yasl/gui/window.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_window_visibility_enum(script::Class window)
{
  using namespace script;

  Enum visibility = window.Enum("Visibility").setId(script::Type::QWindowVisibility).get();

  visibility.addValue("Hidden", QWindow::Hidden);
  visibility.addValue("AutomaticVisibility", QWindow::AutomaticVisibility);
  visibility.addValue("Windowed", QWindow::Windowed);
  visibility.addValue("Minimized", QWindow::Minimized);
  visibility.addValue("Maximized", QWindow::Maximized);
  visibility.addValue("FullScreen", QWindow::FullScreen);
}


static void register_window_ancestor_mode_enum(script::Class window)
{
  using namespace script;

  Enum ancestor_mode = window.Enum("AncestorMode").setId(script::Type::QWindowAncestorMode).get();

  ancestor_mode.addValue("ExcludeTransients", QWindow::ExcludeTransients);
  ancestor_mode.addValue("IncludeTransients", QWindow::IncludeTransients);
}


static void register_window_class(script::Namespace ns)
{
  using namespace script;

  Class window = ns.Class("Window").setId(script::Type::QWindow)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(window.engine(), script::Type::QWindow, script::Type::QWindowStar);
  register_window_visibility_enum(window);
  register_window_ancestor_mode_enum(window);
  binding::QClass<QWindow> binder{ window, &QWindow::staticMetaObject };

  // QWindow(QScreen *);
  /// TODO: QWindow(QScreen *);
  // QWindow(QWindow *);
  binder.ctors().add<QWindow *>();
  // ~QWindow();
  binder.add_dtor();
  // void setSurfaceType(QSurface::SurfaceType);
  /// TODO: void setSurfaceType(QSurface::SurfaceType);
  // QSurface::SurfaceType surfaceType() const;
  /// TODO: QSurface::SurfaceType surfaceType() const;
  // bool isVisible() const;
  binder.add_fun<bool, &QWindow::isVisible>("isVisible");
  // QWindow::Visibility visibility() const;
  binder.add_fun<QWindow::Visibility, &QWindow::visibility>("visibility");
  // void setVisibility(QWindow::Visibility);
  binder.add_void_fun<QWindow::Visibility, &QWindow::setVisibility>("setVisibility");
  // void create();
  binder.add_void_fun<&QWindow::create>("create");
  // WId winId() const;
  /// TODO: WId winId() const;
  // QWindow * parent(QWindow::AncestorMode) const;
  binder.add_fun<QWindow *, QWindow::AncestorMode, &QWindow::parent>("parent");
  // QWindow * parent() const;
  binder.add_fun<QWindow *, &QWindow::parent>("parent");
  // void setParent(QWindow *);
  binder.add_void_fun<QWindow *, &QWindow::setParent>("setParent");
  // bool isTopLevel() const;
  binder.add_fun<bool, &QWindow::isTopLevel>("isTopLevel");
  // bool isModal() const;
  binder.add_fun<bool, &QWindow::isModal>("isModal");
  // Qt::WindowModality modality() const;
  binder.add_fun<Qt::WindowModality, &QWindow::modality>("modality");
  // void setModality(Qt::WindowModality);
  binder.add_void_fun<Qt::WindowModality, &QWindow::setModality>("setModality");
  // void setFormat(const QSurfaceFormat &);
  /// TODO: void setFormat(const QSurfaceFormat &);
  // QSurfaceFormat format() const;
  /// TODO: QSurfaceFormat format() const;
  // QSurfaceFormat requestedFormat() const;
  /// TODO: QSurfaceFormat requestedFormat() const;
  // void setFlags(Qt::WindowFlags);
  /// TODO: void setFlags(Qt::WindowFlags);
  // Qt::WindowFlags flags() const;
  /// TODO: Qt::WindowFlags flags() const;
  // void setFlag(Qt::WindowType, bool);
  binder.add_void_fun<Qt::WindowType, bool, &QWindow::setFlag>("setFlag");
  // Qt::WindowType type() const;
  binder.add_fun<Qt::WindowType, &QWindow::type>("type");
  // QString title() const;
  binder.add_fun<QString, &QWindow::title>("title");
  // void setOpacity(qreal);
  binder.add_void_fun<qreal, &QWindow::setOpacity>("setOpacity");
  // qreal opacity() const;
  binder.add_fun<qreal, &QWindow::opacity>("opacity");
  // void setMask(const QRegion &);
  binder.add_void_fun<const QRegion &, &QWindow::setMask>("setMask");
  // QRegion mask() const;
  binder.add_fun<QRegion, &QWindow::mask>("mask");
  // bool isActive() const;
  binder.add_fun<bool, &QWindow::isActive>("isActive");
  // void reportContentOrientationChange(Qt::ScreenOrientation);
  binder.add_void_fun<Qt::ScreenOrientation, &QWindow::reportContentOrientationChange>("reportContentOrientationChange");
  // Qt::ScreenOrientation contentOrientation() const;
  binder.add_fun<Qt::ScreenOrientation, &QWindow::contentOrientation>("contentOrientation");
  // qreal devicePixelRatio() const;
  binder.add_fun<qreal, &QWindow::devicePixelRatio>("devicePixelRatio");
  // Qt::WindowState windowState() const;
  binder.add_fun<Qt::WindowState, &QWindow::windowState>("windowState");
  // Qt::WindowStates windowStates() const;
  /// TODO: Qt::WindowStates windowStates() const;
  // void setWindowState(Qt::WindowState);
  binder.add_void_fun<Qt::WindowState, &QWindow::setWindowState>("setWindowState");
  // void setWindowStates(Qt::WindowStates);
  /// TODO: void setWindowStates(Qt::WindowStates);
  // void setTransientParent(QWindow *);
  binder.add_void_fun<QWindow *, &QWindow::setTransientParent>("setTransientParent");
  // QWindow * transientParent() const;
  binder.add_fun<QWindow *, &QWindow::transientParent>("transientParent");
  // bool isAncestorOf(const QWindow *, QWindow::AncestorMode) const;
  binder.add_fun<bool, const QWindow *, QWindow::AncestorMode, &QWindow::isAncestorOf>("isAncestorOf");
  // bool isExposed() const;
  binder.add_fun<bool, &QWindow::isExposed>("isExposed");
  // int minimumWidth() const;
  binder.add_fun<int, &QWindow::minimumWidth>("minimumWidth");
  // int minimumHeight() const;
  binder.add_fun<int, &QWindow::minimumHeight>("minimumHeight");
  // int maximumWidth() const;
  binder.add_fun<int, &QWindow::maximumWidth>("maximumWidth");
  // int maximumHeight() const;
  binder.add_fun<int, &QWindow::maximumHeight>("maximumHeight");
  // QSize minimumSize() const;
  binder.add_fun<QSize, &QWindow::minimumSize>("minimumSize");
  // QSize maximumSize() const;
  binder.add_fun<QSize, &QWindow::maximumSize>("maximumSize");
  // QSize baseSize() const;
  binder.add_fun<QSize, &QWindow::baseSize>("baseSize");
  // QSize sizeIncrement() const;
  binder.add_fun<QSize, &QWindow::sizeIncrement>("sizeIncrement");
  // void setMinimumSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWindow::setMinimumSize>("setMinimumSize");
  // void setMaximumSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWindow::setMaximumSize>("setMaximumSize");
  // void setBaseSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWindow::setBaseSize>("setBaseSize");
  // void setSizeIncrement(const QSize &);
  binder.add_void_fun<const QSize &, &QWindow::setSizeIncrement>("setSizeIncrement");
  // QRect geometry() const;
  binder.add_fun<QRect, &QWindow::geometry>("geometry");
  // QMargins frameMargins() const;
  binder.add_fun<QMargins, &QWindow::frameMargins>("frameMargins");
  // QRect frameGeometry() const;
  binder.add_fun<QRect, &QWindow::frameGeometry>("frameGeometry");
  // QPoint framePosition() const;
  binder.add_fun<QPoint, &QWindow::framePosition>("framePosition");
  // void setFramePosition(const QPoint &);
  binder.add_void_fun<const QPoint &, &QWindow::setFramePosition>("setFramePosition");
  // int width() const;
  binder.add_fun<int, &QWindow::width>("width");
  // int height() const;
  binder.add_fun<int, &QWindow::height>("height");
  // int x() const;
  binder.add_fun<int, &QWindow::x>("x");
  // int y() const;
  binder.add_fun<int, &QWindow::y>("y");
  // QSize size() const;
  binder.add_fun<QSize, &QWindow::size>("size");
  // QPoint position() const;
  binder.add_fun<QPoint, &QWindow::position>("position");
  // void setPosition(const QPoint &);
  binder.add_void_fun<const QPoint &, &QWindow::setPosition>("setPosition");
  // void setPosition(int, int);
  binder.add_void_fun<int, int, &QWindow::setPosition>("setPosition");
  // void resize(const QSize &);
  binder.add_void_fun<const QSize &, &QWindow::resize>("resize");
  // void resize(int, int);
  binder.add_void_fun<int, int, &QWindow::resize>("resize");
  // void setFilePath(const QString &);
  binder.add_void_fun<const QString &, &QWindow::setFilePath>("setFilePath");
  // QString filePath() const;
  binder.add_fun<QString, &QWindow::filePath>("filePath");
  // void setIcon(const QIcon &);
  binder.add_void_fun<const QIcon &, &QWindow::setIcon>("setIcon");
  // QIcon icon() const;
  binder.add_fun<QIcon, &QWindow::icon>("icon");
  // void destroy();
  binder.add_void_fun<&QWindow::destroy>("destroy");
  // QPlatformWindow * handle() const;
  /// TODO: QPlatformWindow * handle() const;
  // bool setKeyboardGrabEnabled(bool);
  binder.add_fun<bool, bool, &QWindow::setKeyboardGrabEnabled>("setKeyboardGrabEnabled");
  // bool setMouseGrabEnabled(bool);
  binder.add_fun<bool, bool, &QWindow::setMouseGrabEnabled>("setMouseGrabEnabled");
  // QScreen * screen() const;
  /// TODO: QScreen * screen() const;
  // void setScreen(QScreen *);
  /// TODO: void setScreen(QScreen *);
  // QAccessibleInterface * accessibleRoot() const;
  /// TODO: QAccessibleInterface * accessibleRoot() const;
  // QObject * focusObject() const;
  binder.add_fun<QObject *, &QWindow::focusObject>("focusObject");
  // QPoint mapToGlobal(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWindow::mapToGlobal>("mapToGlobal");
  // QPoint mapFromGlobal(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWindow::mapFromGlobal>("mapFromGlobal");
  // QCursor cursor() const;
  binder.add_fun<QCursor, &QWindow::cursor>("cursor");
  // void setCursor(const QCursor &);
  binder.add_void_fun<const QCursor &, &QWindow::setCursor>("setCursor");
  // void unsetCursor();
  binder.add_void_fun<&QWindow::unsetCursor>("unsetCursor");
  // static QWindow * fromWinId(WId);
  /// TODO: static QWindow * fromWinId(WId);
  // void setVulkanInstance(QVulkanInstance *);
  /// TODO: void setVulkanInstance(QVulkanInstance *);
  // QVulkanInstance * vulkanInstance() const;
  /// TODO: QVulkanInstance * vulkanInstance() const;
  // void requestActivate();
  binder.add_void_fun<&QWindow::requestActivate>("requestActivate");
  // void setVisible(bool);
  binder.add_void_fun<bool, &QWindow::setVisible>("setVisible");
  // void show();
  binder.add_void_fun<&QWindow::show>("show");
  // void hide();
  binder.add_void_fun<&QWindow::hide>("hide");
  // void showMinimized();
  binder.add_void_fun<&QWindow::showMinimized>("showMinimized");
  // void showMaximized();
  binder.add_void_fun<&QWindow::showMaximized>("showMaximized");
  // void showFullScreen();
  binder.add_void_fun<&QWindow::showFullScreen>("showFullScreen");
  // void showNormal();
  binder.add_void_fun<&QWindow::showNormal>("showNormal");
  // bool close();
  binder.add_fun<bool, &QWindow::close>("close");
  // void raise();
  binder.add_void_fun<&QWindow::raise>("raise");
  // void lower();
  binder.add_void_fun<&QWindow::lower>("lower");
  // void setTitle(const QString &);
  binder.add_void_fun<const QString &, &QWindow::setTitle>("setTitle");
  // void setX(int);
  binder.add_void_fun<int, &QWindow::setX>("setX");
  // void setY(int);
  binder.add_void_fun<int, &QWindow::setY>("setY");
  // void setWidth(int);
  binder.add_void_fun<int, &QWindow::setWidth>("setWidth");
  // void setHeight(int);
  binder.add_void_fun<int, &QWindow::setHeight>("setHeight");
  // void setGeometry(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QWindow::setGeometry>("setGeometry");
  // void setGeometry(const QRect &);
  binder.add_void_fun<const QRect &, &QWindow::setGeometry>("setGeometry");
  // void setMinimumWidth(int);
  binder.add_void_fun<int, &QWindow::setMinimumWidth>("setMinimumWidth");
  // void setMinimumHeight(int);
  binder.add_void_fun<int, &QWindow::setMinimumHeight>("setMinimumHeight");
  // void setMaximumWidth(int);
  binder.add_void_fun<int, &QWindow::setMaximumWidth>("setMaximumWidth");
  // void setMaximumHeight(int);
  binder.add_void_fun<int, &QWindow::setMaximumHeight>("setMaximumHeight");
  // void alert(int);
  binder.add_void_fun<int, &QWindow::alert>("alert");
  // void requestUpdate();
  binder.add_void_fun<&QWindow::requestUpdate>("requestUpdate");
  // void modalityChanged(Qt::WindowModality);
  binder.sigs().add<Qt::WindowModality>("modalityChanged", "modalityChanged(Qt::WindowModality)");
  // void windowStateChanged(Qt::WindowState);
  binder.sigs().add<Qt::WindowState>("windowStateChanged", "windowStateChanged(Qt::WindowState)");
  // void windowTitleChanged(const QString &);
  binder.sigs().add<const QString &>("windowTitleChanged", "windowTitleChanged(const QString &)");
  // void xChanged(int);
  binder.sigs().add<int>("xChanged", "xChanged(int)");
  // void yChanged(int);
  binder.sigs().add<int>("yChanged", "yChanged(int)");
  // void widthChanged(int);
  binder.sigs().add<int>("widthChanged", "widthChanged(int)");
  // void heightChanged(int);
  binder.sigs().add<int>("heightChanged", "heightChanged(int)");
  // void minimumWidthChanged(int);
  binder.sigs().add<int>("minimumWidthChanged", "minimumWidthChanged(int)");
  // void minimumHeightChanged(int);
  binder.sigs().add<int>("minimumHeightChanged", "minimumHeightChanged(int)");
  // void maximumWidthChanged(int);
  binder.sigs().add<int>("maximumWidthChanged", "maximumWidthChanged(int)");
  // void maximumHeightChanged(int);
  binder.sigs().add<int>("maximumHeightChanged", "maximumHeightChanged(int)");
  // void visibleChanged(bool);
  binder.sigs().add<bool>("visibleChanged", "visibleChanged(bool)");
  // void visibilityChanged(QWindow::Visibility);
  binder.sigs().add<QWindow::Visibility>("visibilityChanged", "visibilityChanged(QWindow::Visibility)");
  // void activeChanged();
  binder.sigs().add("activeChanged", "activeChanged()");
  // void contentOrientationChanged(Qt::ScreenOrientation);
  binder.sigs().add<Qt::ScreenOrientation>("contentOrientationChanged", "contentOrientationChanged(Qt::ScreenOrientation)");
  // void focusObjectChanged(QObject *);
  binder.sigs().add<QObject *>("focusObjectChanged", "focusObjectChanged(QObject *)");
  // void opacityChanged(qreal);
  binder.sigs().add<qreal>("opacityChanged", "opacityChanged(qreal)");

  window.engine()->registerQtType(&QWindow::staticMetaObject, window.id());
}


void register_window_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_window_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QWindow *);
  /// TODO: QDebug operator<<(QDebug, const QWindow *);
}

