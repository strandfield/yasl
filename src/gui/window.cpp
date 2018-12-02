// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/window.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/common/ref.h"

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

#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
static void register_window_visibility_enum(script::Class window)
{
  using namespace script;

  Enum visibility = window.newEnum("Visibility").setId(script::Type::QWindowVisibility).get();

  visibility.addValue("Hidden", QWindow::Hidden);
  visibility.addValue("AutomaticVisibility", QWindow::AutomaticVisibility);
  visibility.addValue("Windowed", QWindow::Windowed);
  visibility.addValue("Minimized", QWindow::Minimized);
  visibility.addValue("Maximized", QWindow::Maximized);
  visibility.addValue("FullScreen", QWindow::FullScreen);
}
#endif


static void register_window_ancestor_mode_enum(script::Class window)
{
  using namespace script;

  Enum ancestor_mode = window.newEnum("AncestorMode").setId(script::Type::QWindowAncestorMode).get();

  ancestor_mode.addValue("ExcludeTransients", QWindow::ExcludeTransients);
  ancestor_mode.addValue("IncludeTransients", QWindow::IncludeTransients);
}


static void register_window_class(script::Namespace ns)
{
  using namespace script;

  Class window = ns.newClass("Window").setId(script::Type::QWindow)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(window.engine(), script::Type::QWindow, script::Type::QWindowStar);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  register_window_visibility_enum(window);
#endif
  register_window_ancestor_mode_enum(window);

  // QWindow(QScreen * = (QScreen*)nullptr);
  /// TODO: QWindow(QScreen * = (QScreen*)nullptr);
  // QWindow(QWindow *);
  bind::constructor<QWindow, QWindow *>(window).create();
  // ~QWindow();
  bind::destructor<QWindow>(window).create();
  // void setSurfaceType(QSurface::SurfaceType);
  /// TODO: void setSurfaceType(QSurface::SurfaceType);
  // QSurface::SurfaceType surfaceType() const;
  /// TODO: QSurface::SurfaceType surfaceType() const;
  // bool isVisible() const;
  bind::member_function<QWindow, bool, &QWindow::isVisible>(window, "isVisible").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QWindow::Visibility visibility() const;
  bind::member_function<QWindow, QWindow::Visibility, &QWindow::visibility>(window, "visibility").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void setVisibility(QWindow::Visibility);
  bind::void_member_function<QWindow, QWindow::Visibility, &QWindow::setVisibility>(window, "setVisibility").create();
#endif
  // void create();
  bind::void_member_function<QWindow, &QWindow::create>(window, "create").create();
  // WId winId() const;
  /// TODO: WId winId() const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  // QWindow * parent(QWindow::AncestorMode) const;
  bind::member_function<QWindow, QWindow *, QWindow::AncestorMode, &QWindow::parent>(window, "parent").create();
#endif
  // QWindow * parent() const;
  bind::member_function<QWindow, QWindow *, &QWindow::parent>(window, "parent").create();
  // void setParent(QWindow *);
  bind::void_member_function<QWindow, QWindow *, &QWindow::setParent>(window, "setParent").create();
  // bool isTopLevel() const;
  bind::member_function<QWindow, bool, &QWindow::isTopLevel>(window, "isTopLevel").create();
  // bool isModal() const;
  bind::member_function<QWindow, bool, &QWindow::isModal>(window, "isModal").create();
  // Qt::WindowModality modality() const;
  bind::member_function<QWindow, Qt::WindowModality, &QWindow::modality>(window, "modality").create();
  // void setModality(Qt::WindowModality);
  bind::void_member_function<QWindow, Qt::WindowModality, &QWindow::setModality>(window, "setModality").create();
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
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  // void setFlag(Qt::WindowType, bool = true);
  bind::void_member_function<QWindow, Qt::WindowType, bool, &QWindow::setFlag>(window, "setFlag")
    .apply(bind::default_arguments(true)).create();
#endif
  // Qt::WindowType type() const;
  bind::member_function<QWindow, Qt::WindowType, &QWindow::type>(window, "type").create();
  // QString title() const;
  bind::member_function<QWindow, QString, &QWindow::title>(window, "title").create();
  // void setOpacity(qreal);
  bind::void_member_function<QWindow, qreal, &QWindow::setOpacity>(window, "setOpacity").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // qreal opacity() const;
  bind::member_function<QWindow, qreal, &QWindow::opacity>(window, "opacity").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void setMask(const QRegion &);
  bind::void_member_function<QWindow, const QRegion &, &QWindow::setMask>(window, "setMask").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QRegion mask() const;
  bind::member_function<QWindow, QRegion, &QWindow::mask>(window, "mask").create();
#endif
  // bool isActive() const;
  bind::member_function<QWindow, bool, &QWindow::isActive>(window, "isActive").create();
  // void reportContentOrientationChange(Qt::ScreenOrientation);
  bind::void_member_function<QWindow, Qt::ScreenOrientation, &QWindow::reportContentOrientationChange>(window, "reportContentOrientationChange").create();
  // Qt::ScreenOrientation contentOrientation() const;
  bind::member_function<QWindow, Qt::ScreenOrientation, &QWindow::contentOrientation>(window, "contentOrientation").create();
  // qreal devicePixelRatio() const;
  bind::member_function<QWindow, qreal, &QWindow::devicePixelRatio>(window, "devicePixelRatio").create();
  // Qt::WindowState windowState() const;
  bind::member_function<QWindow, Qt::WindowState, &QWindow::windowState>(window, "windowState").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // Qt::WindowStates windowStates() const;
  /// TODO: Qt::WindowStates windowStates() const;
#endif
  // void setWindowState(Qt::WindowState);
  bind::void_member_function<QWindow, Qt::WindowState, &QWindow::setWindowState>(window, "setWindowState").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // void setWindowStates(Qt::WindowStates);
  /// TODO: void setWindowStates(Qt::WindowStates);
#endif
  // void setTransientParent(QWindow *);
  bind::void_member_function<QWindow, QWindow *, &QWindow::setTransientParent>(window, "setTransientParent").create();
  // QWindow * transientParent() const;
  bind::member_function<QWindow, QWindow *, &QWindow::transientParent>(window, "transientParent").create();
  // bool isAncestorOf(const QWindow *, QWindow::AncestorMode = QWindow::IncludeTransients) const;
  bind::member_function<QWindow, bool, const QWindow *, QWindow::AncestorMode, &QWindow::isAncestorOf>(window, "isAncestorOf")
    .apply(bind::default_arguments(QWindow::IncludeTransients)).create();
  // bool isExposed() const;
  bind::member_function<QWindow, bool, &QWindow::isExposed>(window, "isExposed").create();
  // int minimumWidth() const;
  bind::member_function<QWindow, int, &QWindow::minimumWidth>(window, "minimumWidth").create();
  // int minimumHeight() const;
  bind::member_function<QWindow, int, &QWindow::minimumHeight>(window, "minimumHeight").create();
  // int maximumWidth() const;
  bind::member_function<QWindow, int, &QWindow::maximumWidth>(window, "maximumWidth").create();
  // int maximumHeight() const;
  bind::member_function<QWindow, int, &QWindow::maximumHeight>(window, "maximumHeight").create();
  // QSize minimumSize() const;
  bind::member_function<QWindow, QSize, &QWindow::minimumSize>(window, "minimumSize").create();
  // QSize maximumSize() const;
  bind::member_function<QWindow, QSize, &QWindow::maximumSize>(window, "maximumSize").create();
  // QSize baseSize() const;
  bind::member_function<QWindow, QSize, &QWindow::baseSize>(window, "baseSize").create();
  // QSize sizeIncrement() const;
  bind::member_function<QWindow, QSize, &QWindow::sizeIncrement>(window, "sizeIncrement").create();
  // void setMinimumSize(const QSize &);
  bind::void_member_function<QWindow, const QSize &, &QWindow::setMinimumSize>(window, "setMinimumSize").create();
  // void setMaximumSize(const QSize &);
  bind::void_member_function<QWindow, const QSize &, &QWindow::setMaximumSize>(window, "setMaximumSize").create();
  // void setBaseSize(const QSize &);
  bind::void_member_function<QWindow, const QSize &, &QWindow::setBaseSize>(window, "setBaseSize").create();
  // void setSizeIncrement(const QSize &);
  bind::void_member_function<QWindow, const QSize &, &QWindow::setSizeIncrement>(window, "setSizeIncrement").create();
  // QRect geometry() const;
  bind::member_function<QWindow, QRect, &QWindow::geometry>(window, "geometry").create();
  // QMargins frameMargins() const;
  bind::member_function<QWindow, QMargins, &QWindow::frameMargins>(window, "frameMargins").create();
  // QRect frameGeometry() const;
  bind::member_function<QWindow, QRect, &QWindow::frameGeometry>(window, "frameGeometry").create();
  // QPoint framePosition() const;
  bind::member_function<QWindow, QPoint, &QWindow::framePosition>(window, "framePosition").create();
  // void setFramePosition(const QPoint &);
  bind::void_member_function<QWindow, const QPoint &, &QWindow::setFramePosition>(window, "setFramePosition").create();
  // int width() const;
  bind::member_function<QWindow, int, &QWindow::width>(window, "width").create();
  // int height() const;
  bind::member_function<QWindow, int, &QWindow::height>(window, "height").create();
  // int x() const;
  bind::member_function<QWindow, int, &QWindow::x>(window, "x").create();
  // int y() const;
  bind::member_function<QWindow, int, &QWindow::y>(window, "y").create();
  // QSize size() const;
  bind::member_function<QWindow, QSize, &QWindow::size>(window, "size").create();
  // QPoint position() const;
  bind::member_function<QWindow, QPoint, &QWindow::position>(window, "position").create();
  // void setPosition(const QPoint &);
  bind::void_member_function<QWindow, const QPoint &, &QWindow::setPosition>(window, "setPosition").create();
  // void setPosition(int, int);
  bind::void_member_function<QWindow, int, int, &QWindow::setPosition>(window, "setPosition").create();
  // void resize(const QSize &);
  bind::void_member_function<QWindow, const QSize &, &QWindow::resize>(window, "resize").create();
  // void resize(int, int);
  bind::void_member_function<QWindow, int, int, &QWindow::resize>(window, "resize").create();
  // void setFilePath(const QString &);
  bind::void_member_function<QWindow, const QString &, &QWindow::setFilePath>(window, "setFilePath").create();
  // QString filePath() const;
  bind::member_function<QWindow, QString, &QWindow::filePath>(window, "filePath").create();
  // void setIcon(const QIcon &);
  bind::void_member_function<QWindow, const QIcon &, &QWindow::setIcon>(window, "setIcon").create();
  // QIcon icon() const;
  bind::member_function<QWindow, QIcon, &QWindow::icon>(window, "icon").create();
  // void destroy();
  bind::void_member_function<QWindow, &QWindow::destroy>(window, "destroy").create();
  // QPlatformWindow * handle() const;
  /// TODO: QPlatformWindow * handle() const;
  // bool setKeyboardGrabEnabled(bool);
  bind::member_function<QWindow, bool, bool, &QWindow::setKeyboardGrabEnabled>(window, "setKeyboardGrabEnabled").create();
  // bool setMouseGrabEnabled(bool);
  bind::member_function<QWindow, bool, bool, &QWindow::setMouseGrabEnabled>(window, "setMouseGrabEnabled").create();
  // QScreen * screen() const;
  /// TODO: QScreen * screen() const;
  // void setScreen(QScreen *);
  /// TODO: void setScreen(QScreen *);
  // QAccessibleInterface * accessibleRoot() const;
  /// TODO: QAccessibleInterface * accessibleRoot() const;
  // QObject * focusObject() const;
  bind::member_function<QWindow, QObject *, &QWindow::focusObject>(window, "focusObject").create();
  // QPoint mapToGlobal(const QPoint &) const;
  bind::member_function<QWindow, QPoint, const QPoint &, &QWindow::mapToGlobal>(window, "mapToGlobal").create();
  // QPoint mapFromGlobal(const QPoint &) const;
  bind::member_function<QWindow, QPoint, const QPoint &, &QWindow::mapFromGlobal>(window, "mapFromGlobal").create();
  // QCursor cursor() const;
  bind::member_function<QWindow, QCursor, &QWindow::cursor>(window, "cursor").create();
  // void setCursor(const QCursor &);
  bind::void_member_function<QWindow, const QCursor &, &QWindow::setCursor>(window, "setCursor").create();
  // void unsetCursor();
  bind::void_member_function<QWindow, &QWindow::unsetCursor>(window, "unsetCursor").create();
  // static QWindow * fromWinId(WId);
  /// TODO: static QWindow * fromWinId(WId);
  // void setVulkanInstance(QVulkanInstance *);
  /// TODO: void setVulkanInstance(QVulkanInstance *);
  // QVulkanInstance * vulkanInstance() const;
  /// TODO: QVulkanInstance * vulkanInstance() const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void requestActivate();
  bind::void_member_function<QWindow, &QWindow::requestActivate>(window, "requestActivate").create();
#endif
  // void setVisible(bool);
  bind::void_member_function<QWindow, bool, &QWindow::setVisible>(window, "setVisible").create();
  // void show();
  bind::void_member_function<QWindow, &QWindow::show>(window, "show").create();
  // void hide();
  bind::void_member_function<QWindow, &QWindow::hide>(window, "hide").create();
  // void showMinimized();
  bind::void_member_function<QWindow, &QWindow::showMinimized>(window, "showMinimized").create();
  // void showMaximized();
  bind::void_member_function<QWindow, &QWindow::showMaximized>(window, "showMaximized").create();
  // void showFullScreen();
  bind::void_member_function<QWindow, &QWindow::showFullScreen>(window, "showFullScreen").create();
  // void showNormal();
  bind::void_member_function<QWindow, &QWindow::showNormal>(window, "showNormal").create();
  // bool close();
  bind::member_function<QWindow, bool, &QWindow::close>(window, "close").create();
  // void raise();
  bind::void_member_function<QWindow, &QWindow::raise>(window, "raise").create();
  // void lower();
  bind::void_member_function<QWindow, &QWindow::lower>(window, "lower").create();
  // void setTitle(const QString &);
  bind::void_member_function<QWindow, const QString &, &QWindow::setTitle>(window, "setTitle").create();
  // void setX(int);
  bind::void_member_function<QWindow, int, &QWindow::setX>(window, "setX").create();
  // void setY(int);
  bind::void_member_function<QWindow, int, &QWindow::setY>(window, "setY").create();
  // void setWidth(int);
  bind::void_member_function<QWindow, int, &QWindow::setWidth>(window, "setWidth").create();
  // void setHeight(int);
  bind::void_member_function<QWindow, int, &QWindow::setHeight>(window, "setHeight").create();
  // void setGeometry(int, int, int, int);
  bind::void_member_function<QWindow, int, int, int, int, &QWindow::setGeometry>(window, "setGeometry").create();
  // void setGeometry(const QRect &);
  bind::void_member_function<QWindow, const QRect &, &QWindow::setGeometry>(window, "setGeometry").create();
  // void setMinimumWidth(int);
  bind::void_member_function<QWindow, int, &QWindow::setMinimumWidth>(window, "setMinimumWidth").create();
  // void setMinimumHeight(int);
  bind::void_member_function<QWindow, int, &QWindow::setMinimumHeight>(window, "setMinimumHeight").create();
  // void setMaximumWidth(int);
  bind::void_member_function<QWindow, int, &QWindow::setMaximumWidth>(window, "setMaximumWidth").create();
  // void setMaximumHeight(int);
  bind::void_member_function<QWindow, int, &QWindow::setMaximumHeight>(window, "setMaximumHeight").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void alert(int);
  bind::void_member_function<QWindow, int, &QWindow::alert>(window, "alert").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // void requestUpdate();
  bind::void_member_function<QWindow, &QWindow::requestUpdate>(window, "requestUpdate").create();
#endif
  // void modalityChanged(Qt::WindowModality);
  bind::signal<QWindow, Qt::WindowModality>(window, "modalityChanged", "modalityChanged(Qt::WindowModality)");
  // void windowStateChanged(Qt::WindowState);
  bind::signal<QWindow, Qt::WindowState>(window, "windowStateChanged", "windowStateChanged(Qt::WindowState)");
  // void windowTitleChanged(const QString &);
  bind::signal<QWindow, const QString &>(window, "windowTitleChanged", "windowTitleChanged(const QString &)");
  // void xChanged(int);
  bind::signal<QWindow, int>(window, "xChanged", "xChanged(int)");
  // void yChanged(int);
  bind::signal<QWindow, int>(window, "yChanged", "yChanged(int)");
  // void widthChanged(int);
  bind::signal<QWindow, int>(window, "widthChanged", "widthChanged(int)");
  // void heightChanged(int);
  bind::signal<QWindow, int>(window, "heightChanged", "heightChanged(int)");
  // void minimumWidthChanged(int);
  bind::signal<QWindow, int>(window, "minimumWidthChanged", "minimumWidthChanged(int)");
  // void minimumHeightChanged(int);
  bind::signal<QWindow, int>(window, "minimumHeightChanged", "minimumHeightChanged(int)");
  // void maximumWidthChanged(int);
  bind::signal<QWindow, int>(window, "maximumWidthChanged", "maximumWidthChanged(int)");
  // void maximumHeightChanged(int);
  bind::signal<QWindow, int>(window, "maximumHeightChanged", "maximumHeightChanged(int)");
  // void visibleChanged(bool);
  bind::signal<QWindow, bool>(window, "visibleChanged", "visibleChanged(bool)");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void visibilityChanged(QWindow::Visibility);
  bind::signal<QWindow, QWindow::Visibility>(window, "visibilityChanged", "visibilityChanged(QWindow::Visibility)");
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void activeChanged();
  bind::signal<QWindow>(window, "activeChanged", "activeChanged()");
#endif
  // void contentOrientationChanged(Qt::ScreenOrientation);
  bind::signal<QWindow, Qt::ScreenOrientation>(window, "contentOrientationChanged", "contentOrientationChanged(Qt::ScreenOrientation)");
  // void focusObjectChanged(QObject *);
  bind::signal<QWindow, QObject *>(window, "focusObjectChanged", "focusObjectChanged(QObject *)");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // void opacityChanged(qreal);
  bind::signal<QWindow, qreal>(window, "opacityChanged", "opacityChanged(qreal)");
#endif

  bind::link(window, &QWindow::staticMetaObject);
}


void register_window_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_window_class(ns);

  // QDebug operator<<(QDebug, const QWindow *);
  /// TODO: QDebug operator<<(QDebug, const QWindow *);
}

