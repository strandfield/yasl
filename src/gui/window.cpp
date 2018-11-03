// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/window.h"

#include "yasl/binding/default_arguments.h"
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
  binding::ClassBinder<QWindow> binder{ window, &QWindow::staticMetaObject };

  // QWindow(QScreen *);
  /// TODO: QWindow(QScreen *);
  // QWindow(QWindow *);
  binder.ctor<QWindow *>().create();
  // ~QWindow();
  binder.dtor().create();
  // void setSurfaceType(QSurface::SurfaceType);
  /// TODO: void setSurfaceType(QSurface::SurfaceType);
  // QSurface::SurfaceType surfaceType() const;
  /// TODO: QSurface::SurfaceType surfaceType() const;
  // bool isVisible() const;
  binder.fun<bool, &QWindow::isVisible>("isVisible").create();
  // QWindow::Visibility visibility() const;
  binder.fun<QWindow::Visibility, &QWindow::visibility>("visibility").create();
  // void setVisibility(QWindow::Visibility);
  binder.void_fun<QWindow::Visibility, &QWindow::setVisibility>("setVisibility").create();
  // void create();
  binder.void_fun<&QWindow::create>("create").create();
  // WId winId() const;
  /// TODO: WId winId() const;
  // QWindow * parent(QWindow::AncestorMode) const;
  binder.fun<QWindow *, QWindow::AncestorMode, &QWindow::parent>("parent").create();
  // QWindow * parent() const;
  binder.fun<QWindow *, &QWindow::parent>("parent").create();
  // void setParent(QWindow *);
  binder.void_fun<QWindow *, &QWindow::setParent>("setParent").create();
  // bool isTopLevel() const;
  binder.fun<bool, &QWindow::isTopLevel>("isTopLevel").create();
  // bool isModal() const;
  binder.fun<bool, &QWindow::isModal>("isModal").create();
  // Qt::WindowModality modality() const;
  binder.fun<Qt::WindowModality, &QWindow::modality>("modality").create();
  // void setModality(Qt::WindowModality);
  binder.void_fun<Qt::WindowModality, &QWindow::setModality>("setModality").create();
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
  binder.void_fun<Qt::WindowType, bool, &QWindow::setFlag>("setFlag")
    .apply(binding::default_arguments(true)).create();
  // Qt::WindowType type() const;
  binder.fun<Qt::WindowType, &QWindow::type>("type").create();
  // QString title() const;
  binder.fun<QString, &QWindow::title>("title").create();
  // void setOpacity(qreal);
  binder.void_fun<qreal, &QWindow::setOpacity>("setOpacity").create();
  // qreal opacity() const;
  binder.fun<qreal, &QWindow::opacity>("opacity").create();
  // void setMask(const QRegion &);
  binder.void_fun<const QRegion &, &QWindow::setMask>("setMask").create();
  // QRegion mask() const;
  binder.fun<QRegion, &QWindow::mask>("mask").create();
  // bool isActive() const;
  binder.fun<bool, &QWindow::isActive>("isActive").create();
  // void reportContentOrientationChange(Qt::ScreenOrientation);
  binder.void_fun<Qt::ScreenOrientation, &QWindow::reportContentOrientationChange>("reportContentOrientationChange").create();
  // Qt::ScreenOrientation contentOrientation() const;
  binder.fun<Qt::ScreenOrientation, &QWindow::contentOrientation>("contentOrientation").create();
  // qreal devicePixelRatio() const;
  binder.fun<qreal, &QWindow::devicePixelRatio>("devicePixelRatio").create();
  // Qt::WindowState windowState() const;
  binder.fun<Qt::WindowState, &QWindow::windowState>("windowState").create();
  // Qt::WindowStates windowStates() const;
  /// TODO: Qt::WindowStates windowStates() const;
  // void setWindowState(Qt::WindowState);
  binder.void_fun<Qt::WindowState, &QWindow::setWindowState>("setWindowState").create();
  // void setWindowStates(Qt::WindowStates);
  /// TODO: void setWindowStates(Qt::WindowStates);
  // void setTransientParent(QWindow *);
  binder.void_fun<QWindow *, &QWindow::setTransientParent>("setTransientParent").create();
  // QWindow * transientParent() const;
  binder.fun<QWindow *, &QWindow::transientParent>("transientParent").create();
  // bool isAncestorOf(const QWindow *, QWindow::AncestorMode) const;
  binder.fun<bool, const QWindow *, QWindow::AncestorMode, &QWindow::isAncestorOf>("isAncestorOf")
    .apply(binding::default_arguments(QWindow::IncludeTransients)).create();
  // bool isExposed() const;
  binder.fun<bool, &QWindow::isExposed>("isExposed").create();
  // int minimumWidth() const;
  binder.fun<int, &QWindow::minimumWidth>("minimumWidth").create();
  // int minimumHeight() const;
  binder.fun<int, &QWindow::minimumHeight>("minimumHeight").create();
  // int maximumWidth() const;
  binder.fun<int, &QWindow::maximumWidth>("maximumWidth").create();
  // int maximumHeight() const;
  binder.fun<int, &QWindow::maximumHeight>("maximumHeight").create();
  // QSize minimumSize() const;
  binder.fun<QSize, &QWindow::minimumSize>("minimumSize").create();
  // QSize maximumSize() const;
  binder.fun<QSize, &QWindow::maximumSize>("maximumSize").create();
  // QSize baseSize() const;
  binder.fun<QSize, &QWindow::baseSize>("baseSize").create();
  // QSize sizeIncrement() const;
  binder.fun<QSize, &QWindow::sizeIncrement>("sizeIncrement").create();
  // void setMinimumSize(const QSize &);
  binder.void_fun<const QSize &, &QWindow::setMinimumSize>("setMinimumSize").create();
  // void setMaximumSize(const QSize &);
  binder.void_fun<const QSize &, &QWindow::setMaximumSize>("setMaximumSize").create();
  // void setBaseSize(const QSize &);
  binder.void_fun<const QSize &, &QWindow::setBaseSize>("setBaseSize").create();
  // void setSizeIncrement(const QSize &);
  binder.void_fun<const QSize &, &QWindow::setSizeIncrement>("setSizeIncrement").create();
  // QRect geometry() const;
  binder.fun<QRect, &QWindow::geometry>("geometry").create();
  // QMargins frameMargins() const;
  binder.fun<QMargins, &QWindow::frameMargins>("frameMargins").create();
  // QRect frameGeometry() const;
  binder.fun<QRect, &QWindow::frameGeometry>("frameGeometry").create();
  // QPoint framePosition() const;
  binder.fun<QPoint, &QWindow::framePosition>("framePosition").create();
  // void setFramePosition(const QPoint &);
  binder.void_fun<const QPoint &, &QWindow::setFramePosition>("setFramePosition").create();
  // int width() const;
  binder.fun<int, &QWindow::width>("width").create();
  // int height() const;
  binder.fun<int, &QWindow::height>("height").create();
  // int x() const;
  binder.fun<int, &QWindow::x>("x").create();
  // int y() const;
  binder.fun<int, &QWindow::y>("y").create();
  // QSize size() const;
  binder.fun<QSize, &QWindow::size>("size").create();
  // QPoint position() const;
  binder.fun<QPoint, &QWindow::position>("position").create();
  // void setPosition(const QPoint &);
  binder.void_fun<const QPoint &, &QWindow::setPosition>("setPosition").create();
  // void setPosition(int, int);
  binder.void_fun<int, int, &QWindow::setPosition>("setPosition").create();
  // void resize(const QSize &);
  binder.void_fun<const QSize &, &QWindow::resize>("resize").create();
  // void resize(int, int);
  binder.void_fun<int, int, &QWindow::resize>("resize").create();
  // void setFilePath(const QString &);
  binder.void_fun<const QString &, &QWindow::setFilePath>("setFilePath").create();
  // QString filePath() const;
  binder.fun<QString, &QWindow::filePath>("filePath").create();
  // void setIcon(const QIcon &);
  binder.void_fun<const QIcon &, &QWindow::setIcon>("setIcon").create();
  // QIcon icon() const;
  binder.fun<QIcon, &QWindow::icon>("icon").create();
  // void destroy();
  binder.void_fun<&QWindow::destroy>("destroy").create();
  // QPlatformWindow * handle() const;
  /// TODO: QPlatformWindow * handle() const;
  // bool setKeyboardGrabEnabled(bool);
  binder.fun<bool, bool, &QWindow::setKeyboardGrabEnabled>("setKeyboardGrabEnabled").create();
  // bool setMouseGrabEnabled(bool);
  binder.fun<bool, bool, &QWindow::setMouseGrabEnabled>("setMouseGrabEnabled").create();
  // QScreen * screen() const;
  /// TODO: QScreen * screen() const;
  // void setScreen(QScreen *);
  /// TODO: void setScreen(QScreen *);
  // QAccessibleInterface * accessibleRoot() const;
  /// TODO: QAccessibleInterface * accessibleRoot() const;
  // QObject * focusObject() const;
  binder.fun<QObject *, &QWindow::focusObject>("focusObject").create();
  // QPoint mapToGlobal(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWindow::mapToGlobal>("mapToGlobal").create();
  // QPoint mapFromGlobal(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWindow::mapFromGlobal>("mapFromGlobal").create();
  // QCursor cursor() const;
  binder.fun<QCursor, &QWindow::cursor>("cursor").create();
  // void setCursor(const QCursor &);
  binder.void_fun<const QCursor &, &QWindow::setCursor>("setCursor").create();
  // void unsetCursor();
  binder.void_fun<&QWindow::unsetCursor>("unsetCursor").create();
  // static QWindow * fromWinId(WId);
  /// TODO: static QWindow * fromWinId(WId);
  // void setVulkanInstance(QVulkanInstance *);
  /// TODO: void setVulkanInstance(QVulkanInstance *);
  // QVulkanInstance * vulkanInstance() const;
  /// TODO: QVulkanInstance * vulkanInstance() const;
  // void requestActivate();
  binder.void_fun<&QWindow::requestActivate>("requestActivate").create();
  // void setVisible(bool);
  binder.void_fun<bool, &QWindow::setVisible>("setVisible").create();
  // void show();
  binder.void_fun<&QWindow::show>("show").create();
  // void hide();
  binder.void_fun<&QWindow::hide>("hide").create();
  // void showMinimized();
  binder.void_fun<&QWindow::showMinimized>("showMinimized").create();
  // void showMaximized();
  binder.void_fun<&QWindow::showMaximized>("showMaximized").create();
  // void showFullScreen();
  binder.void_fun<&QWindow::showFullScreen>("showFullScreen").create();
  // void showNormal();
  binder.void_fun<&QWindow::showNormal>("showNormal").create();
  // bool close();
  binder.fun<bool, &QWindow::close>("close").create();
  // void raise();
  binder.void_fun<&QWindow::raise>("raise").create();
  // void lower();
  binder.void_fun<&QWindow::lower>("lower").create();
  // void setTitle(const QString &);
  binder.void_fun<const QString &, &QWindow::setTitle>("setTitle").create();
  // void setX(int);
  binder.void_fun<int, &QWindow::setX>("setX").create();
  // void setY(int);
  binder.void_fun<int, &QWindow::setY>("setY").create();
  // void setWidth(int);
  binder.void_fun<int, &QWindow::setWidth>("setWidth").create();
  // void setHeight(int);
  binder.void_fun<int, &QWindow::setHeight>("setHeight").create();
  // void setGeometry(int, int, int, int);
  binder.void_fun<int, int, int, int, &QWindow::setGeometry>("setGeometry").create();
  // void setGeometry(const QRect &);
  binder.void_fun<const QRect &, &QWindow::setGeometry>("setGeometry").create();
  // void setMinimumWidth(int);
  binder.void_fun<int, &QWindow::setMinimumWidth>("setMinimumWidth").create();
  // void setMinimumHeight(int);
  binder.void_fun<int, &QWindow::setMinimumHeight>("setMinimumHeight").create();
  // void setMaximumWidth(int);
  binder.void_fun<int, &QWindow::setMaximumWidth>("setMaximumWidth").create();
  // void setMaximumHeight(int);
  binder.void_fun<int, &QWindow::setMaximumHeight>("setMaximumHeight").create();
  // void alert(int);
  binder.void_fun<int, &QWindow::alert>("alert").create();
  // void requestUpdate();
  binder.void_fun<&QWindow::requestUpdate>("requestUpdate").create();
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

