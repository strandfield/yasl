// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/widget.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/common/listspecializations.h"
#include "yasl/common/ref.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/enums.h"
#include "yasl/core/locale.h"
#include "yasl/core/margins.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/core/variant.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/cursor.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"
#include "yasl/gui/fontmetrics.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/keysequence.h"
#include "yasl/gui/palette.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/region.h"
#include "yasl/gui/window.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_widget_render_flag_enum(script::Class widget)
{
  using namespace script;

  Enum render_flag = widget.newEnum("RenderFlag").setId(script::Type::QWidgetRenderFlag).get();

  render_flag.addValue("DrawWindowBackground", QWidget::DrawWindowBackground);
  render_flag.addValue("DrawChildren", QWidget::DrawChildren);
  render_flag.addValue("IgnoreMask", QWidget::IgnoreMask);
}


static void register_widget_class(script::Namespace ns)
{
  using namespace script;

  Class widget = ns.newClass("Widget").setId(script::Type::QWidget)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(widget.engine(), script::Type::QWidget, script::Type::QWidgetStar);
  register_proxy_specialization<QWidget*>(widget.engine()->getTemplate(Engine::ProxyTemplate), script::Type::ProxyQWidget);
  register_list_specialization<QWidget*>(widget.engine(), script::Type::QListQWidget);
  register_widget_render_flag_enum(widget);

  // QWidget(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: QWidget(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // ~QWidget();
  bind::destructor<QWidget>(widget).create();
  // int devType() const;
  bind::member_function<QWidget, int, &QWidget::devType>(widget, "devType").create();
  // WId winId() const;
  /// TODO: WId winId() const;
  // void createWinId();
  bind::void_member_function<QWidget, &QWidget::createWinId>(widget, "createWinId").create();
  // WId internalWinId() const;
  /// TODO: WId internalWinId() const;
  // WId effectiveWinId() const;
  /// TODO: WId effectiveWinId() const;
  // QStyle * style() const;
  /// TODO: QStyle * style() const;
  // void setStyle(QStyle *);
  /// TODO: void setStyle(QStyle *);
  // bool isTopLevel() const;
  bind::member_function<QWidget, bool, &QWidget::isTopLevel>(widget, "isTopLevel").create();
  // bool isWindow() const;
  bind::member_function<QWidget, bool, &QWidget::isWindow>(widget, "isWindow").create();
  // bool isModal() const;
  bind::member_function<QWidget, bool, &QWidget::isModal>(widget, "isModal").create();
  // Qt::WindowModality windowModality() const;
  bind::member_function<QWidget, Qt::WindowModality, &QWidget::windowModality>(widget, "windowModality").create();
  // void setWindowModality(Qt::WindowModality);
  bind::void_member_function<QWidget, Qt::WindowModality, &QWidget::setWindowModality>(widget, "setWindowModality").create();
  // bool isEnabled() const;
  bind::member_function<QWidget, bool, &QWidget::isEnabled>(widget, "isEnabled").create();
  // bool isEnabledTo(const QWidget *) const;
  bind::member_function<QWidget, bool, const QWidget *, &QWidget::isEnabledTo>(widget, "isEnabledTo").create();
  // bool isEnabledToTLW() const;
  bind::member_function<QWidget, bool, &QWidget::isEnabledToTLW>(widget, "isEnabledToTLW").create();
  // void setEnabled(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setEnabled>(widget, "setEnabled").create();
  // void setDisabled(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setDisabled>(widget, "setDisabled").create();
  // void setWindowModified(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setWindowModified>(widget, "setWindowModified").create();
  // QRect frameGeometry() const;
  bind::member_function<QWidget, QRect, &QWidget::frameGeometry>(widget, "frameGeometry").create();
  // const QRect & geometry() const;
  bind::member_function<QWidget, const QRect &, &QWidget::geometry>(widget, "geometry").create();
  // QRect normalGeometry() const;
  bind::member_function<QWidget, QRect, &QWidget::normalGeometry>(widget, "normalGeometry").create();
  // int x() const;
  bind::member_function<QWidget, int, &QWidget::x>(widget, "x").create();
  // int y() const;
  bind::member_function<QWidget, int, &QWidget::y>(widget, "y").create();
  // QPoint pos() const;
  bind::member_function<QWidget, QPoint, &QWidget::pos>(widget, "pos").create();
  // QSize frameSize() const;
  bind::member_function<QWidget, QSize, &QWidget::frameSize>(widget, "frameSize").create();
  // QSize size() const;
  bind::member_function<QWidget, QSize, &QWidget::size>(widget, "size").create();
  // int width() const;
  bind::member_function<QWidget, int, &QWidget::width>(widget, "width").create();
  // int height() const;
  bind::member_function<QWidget, int, &QWidget::height>(widget, "height").create();
  // QRect rect() const;
  bind::member_function<QWidget, QRect, &QWidget::rect>(widget, "rect").create();
  // QRect childrenRect() const;
  bind::member_function<QWidget, QRect, &QWidget::childrenRect>(widget, "childrenRect").create();
  // QRegion childrenRegion() const;
  bind::member_function<QWidget, QRegion, &QWidget::childrenRegion>(widget, "childrenRegion").create();
  // QSize minimumSize() const;
  bind::member_function<QWidget, QSize, &QWidget::minimumSize>(widget, "minimumSize").create();
  // QSize maximumSize() const;
  bind::member_function<QWidget, QSize, &QWidget::maximumSize>(widget, "maximumSize").create();
  // int minimumWidth() const;
  bind::member_function<QWidget, int, &QWidget::minimumWidth>(widget, "minimumWidth").create();
  // int minimumHeight() const;
  bind::member_function<QWidget, int, &QWidget::minimumHeight>(widget, "minimumHeight").create();
  // int maximumWidth() const;
  bind::member_function<QWidget, int, &QWidget::maximumWidth>(widget, "maximumWidth").create();
  // int maximumHeight() const;
  bind::member_function<QWidget, int, &QWidget::maximumHeight>(widget, "maximumHeight").create();
  // void setMinimumSize(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::setMinimumSize>(widget, "setMinimumSize").create();
  // void setMinimumSize(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::setMinimumSize>(widget, "setMinimumSize").create();
  // void setMaximumSize(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::setMaximumSize>(widget, "setMaximumSize").create();
  // void setMaximumSize(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::setMaximumSize>(widget, "setMaximumSize").create();
  // void setMinimumWidth(int);
  bind::void_member_function<QWidget, int, &QWidget::setMinimumWidth>(widget, "setMinimumWidth").create();
  // void setMinimumHeight(int);
  bind::void_member_function<QWidget, int, &QWidget::setMinimumHeight>(widget, "setMinimumHeight").create();
  // void setMaximumWidth(int);
  bind::void_member_function<QWidget, int, &QWidget::setMaximumWidth>(widget, "setMaximumWidth").create();
  // void setMaximumHeight(int);
  bind::void_member_function<QWidget, int, &QWidget::setMaximumHeight>(widget, "setMaximumHeight").create();
  // QSize sizeIncrement() const;
  bind::member_function<QWidget, QSize, &QWidget::sizeIncrement>(widget, "sizeIncrement").create();
  // void setSizeIncrement(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::setSizeIncrement>(widget, "setSizeIncrement").create();
  // void setSizeIncrement(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::setSizeIncrement>(widget, "setSizeIncrement").create();
  // QSize baseSize() const;
  bind::member_function<QWidget, QSize, &QWidget::baseSize>(widget, "baseSize").create();
  // void setBaseSize(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::setBaseSize>(widget, "setBaseSize").create();
  // void setBaseSize(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::setBaseSize>(widget, "setBaseSize").create();
  // void setFixedSize(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::setFixedSize>(widget, "setFixedSize").create();
  // void setFixedSize(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::setFixedSize>(widget, "setFixedSize").create();
  // void setFixedWidth(int);
  bind::void_member_function<QWidget, int, &QWidget::setFixedWidth>(widget, "setFixedWidth").create();
  // void setFixedHeight(int);
  bind::void_member_function<QWidget, int, &QWidget::setFixedHeight>(widget, "setFixedHeight").create();
  // QPoint mapToGlobal(const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QPoint &, &QWidget::mapToGlobal>(widget, "mapToGlobal").create();
  // QPoint mapFromGlobal(const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QPoint &, &QWidget::mapFromGlobal>(widget, "mapFromGlobal").create();
  // QPoint mapToParent(const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QPoint &, &QWidget::mapToParent>(widget, "mapToParent").create();
  // QPoint mapFromParent(const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QPoint &, &QWidget::mapFromParent>(widget, "mapFromParent").create();
  // QPoint mapTo(const QWidget *, const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QWidget *, const QPoint &, &QWidget::mapTo>(widget, "mapTo").create();
  // QPoint mapFrom(const QWidget *, const QPoint &) const;
  bind::member_function<QWidget, QPoint, const QWidget *, const QPoint &, &QWidget::mapFrom>(widget, "mapFrom").create();
  // QWidget * window() const;
  bind::member_function<QWidget, QWidget *, &QWidget::window>(widget, "window").create();
  // QWidget * nativeParentWidget() const;
  bind::member_function<QWidget, QWidget *, &QWidget::nativeParentWidget>(widget, "nativeParentWidget").create();
  // QWidget * topLevelWidget() const;
  bind::member_function<QWidget, QWidget *, &QWidget::topLevelWidget>(widget, "topLevelWidget").create();
  // const QPalette & palette() const;
  bind::member_function<QWidget, const QPalette &, &QWidget::palette>(widget, "palette").create();
  // void setPalette(const QPalette &);
  bind::void_member_function<QWidget, const QPalette &, &QWidget::setPalette>(widget, "setPalette").create();
  // void setBackgroundRole(QPalette::ColorRole);
  bind::void_member_function<QWidget, QPalette::ColorRole, &QWidget::setBackgroundRole>(widget, "setBackgroundRole").create();
  // QPalette::ColorRole backgroundRole() const;
  bind::member_function<QWidget, QPalette::ColorRole, &QWidget::backgroundRole>(widget, "backgroundRole").create();
  // void setForegroundRole(QPalette::ColorRole);
  bind::void_member_function<QWidget, QPalette::ColorRole, &QWidget::setForegroundRole>(widget, "setForegroundRole").create();
  // QPalette::ColorRole foregroundRole() const;
  bind::member_function<QWidget, QPalette::ColorRole, &QWidget::foregroundRole>(widget, "foregroundRole").create();
  // const QFont & font() const;
  bind::member_function<QWidget, const QFont &, &QWidget::font>(widget, "font").create();
  // void setFont(const QFont &);
  bind::void_member_function<QWidget, const QFont &, &QWidget::setFont>(widget, "setFont").create();
  // QFontMetrics fontMetrics() const;
  bind::member_function<QWidget, QFontMetrics, &QWidget::fontMetrics>(widget, "fontMetrics").create();
  // QFontInfo fontInfo() const;
  bind::member_function<QWidget, QFontInfo, &QWidget::fontInfo>(widget, "fontInfo").create();
  // QCursor cursor() const;
  bind::member_function<QWidget, QCursor, &QWidget::cursor>(widget, "cursor").create();
  // void setCursor(const QCursor &);
  bind::void_member_function<QWidget, const QCursor &, &QWidget::setCursor>(widget, "setCursor").create();
  // void unsetCursor();
  bind::void_member_function<QWidget, &QWidget::unsetCursor>(widget, "unsetCursor").create();
  // void setMouseTracking(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setMouseTracking>(widget, "setMouseTracking").create();
  // bool hasMouseTracking() const;
  bind::member_function<QWidget, bool, &QWidget::hasMouseTracking>(widget, "hasMouseTracking").create();
  // bool underMouse() const;
  bind::member_function<QWidget, bool, &QWidget::underMouse>(widget, "underMouse").create();
  // void setTabletTracking(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setTabletTracking>(widget, "setTabletTracking").create();
  // bool hasTabletTracking() const;
  bind::member_function<QWidget, bool, &QWidget::hasTabletTracking>(widget, "hasTabletTracking").create();
  // void setMask(const QBitmap &);
  bind::void_member_function<QWidget, const QBitmap &, &QWidget::setMask>(widget, "setMask").create();
  // void setMask(const QRegion &);
  bind::void_member_function<QWidget, const QRegion &, &QWidget::setMask>(widget, "setMask").create();
  // QRegion mask() const;
  bind::member_function<QWidget, QRegion, &QWidget::mask>(widget, "mask").create();
  // void clearMask();
  bind::void_member_function<QWidget, &QWidget::clearMask>(widget, "clearMask").create();
  // void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  /// TODO: void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  // void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags = QWidget::RenderFlags(QWidget::DrawWindowBackground | QWidget::DrawChildren));
  /// TODO: void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags = QWidget::RenderFlags(QWidget::DrawWindowBackground | QWidget::DrawChildren));
  // QPixmap grab(const QRect & = QRect(QPoint(0, 0), QSize(-1, -1)));
  bind::member_function<QWidget, QPixmap, const QRect &, &QWidget::grab>(widget, "grab")
    .apply(bind::default_arguments(QRect(QPoint(0, 0), QSize(-1, -1)))).create();
  // QGraphicsEffect * graphicsEffect() const;
  /// TODO: QGraphicsEffect * graphicsEffect() const;
  // void setGraphicsEffect(QGraphicsEffect *);
  /// TODO: void setGraphicsEffect(QGraphicsEffect *);
  // void grabGesture(Qt::GestureType, Qt::GestureFlags = Qt::GestureFlags());
  /// TODO: void grabGesture(Qt::GestureType, Qt::GestureFlags = Qt::GestureFlags());
  // void ungrabGesture(Qt::GestureType);
  bind::void_member_function<QWidget, Qt::GestureType, &QWidget::ungrabGesture>(widget, "ungrabGesture").create();
  // void setWindowTitle(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setWindowTitle>(widget, "setWindowTitle").create();
  // void setStyleSheet(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setStyleSheet>(widget, "setStyleSheet").create();
  // QString styleSheet() const;
  bind::member_function<QWidget, QString, &QWidget::styleSheet>(widget, "styleSheet").create();
  // QString windowTitle() const;
  bind::member_function<QWidget, QString, &QWidget::windowTitle>(widget, "windowTitle").create();
  // void setWindowIcon(const QIcon &);
  bind::void_member_function<QWidget, const QIcon &, &QWidget::setWindowIcon>(widget, "setWindowIcon").create();
  // QIcon windowIcon() const;
  bind::member_function<QWidget, QIcon, &QWidget::windowIcon>(widget, "windowIcon").create();
  // void setWindowIconText(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setWindowIconText>(widget, "setWindowIconText").create();
  // QString windowIconText() const;
  bind::member_function<QWidget, QString, &QWidget::windowIconText>(widget, "windowIconText").create();
  // void setWindowRole(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setWindowRole>(widget, "setWindowRole").create();
  // QString windowRole() const;
  bind::member_function<QWidget, QString, &QWidget::windowRole>(widget, "windowRole").create();
  // void setWindowFilePath(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setWindowFilePath>(widget, "setWindowFilePath").create();
  // QString windowFilePath() const;
  bind::member_function<QWidget, QString, &QWidget::windowFilePath>(widget, "windowFilePath").create();
  // void setWindowOpacity(qreal);
  bind::void_member_function<QWidget, qreal, &QWidget::setWindowOpacity>(widget, "setWindowOpacity").create();
  // qreal windowOpacity() const;
  bind::member_function<QWidget, qreal, &QWidget::windowOpacity>(widget, "windowOpacity").create();
  // bool isWindowModified() const;
  bind::member_function<QWidget, bool, &QWidget::isWindowModified>(widget, "isWindowModified").create();
  // void setToolTip(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setToolTip>(widget, "setToolTip").create();
  // QString toolTip() const;
  bind::member_function<QWidget, QString, &QWidget::toolTip>(widget, "toolTip").create();
  // void setToolTipDuration(int);
  bind::void_member_function<QWidget, int, &QWidget::setToolTipDuration>(widget, "setToolTipDuration").create();
  // int toolTipDuration() const;
  bind::member_function<QWidget, int, &QWidget::toolTipDuration>(widget, "toolTipDuration").create();
  // void setStatusTip(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setStatusTip>(widget, "setStatusTip").create();
  // QString statusTip() const;
  bind::member_function<QWidget, QString, &QWidget::statusTip>(widget, "statusTip").create();
  // void setWhatsThis(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setWhatsThis>(widget, "setWhatsThis").create();
  // QString whatsThis() const;
  bind::member_function<QWidget, QString, &QWidget::whatsThis>(widget, "whatsThis").create();
  // QString accessibleName() const;
  bind::member_function<QWidget, QString, &QWidget::accessibleName>(widget, "accessibleName").create();
  // void setAccessibleName(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setAccessibleName>(widget, "setAccessibleName").create();
  // QString accessibleDescription() const;
  bind::member_function<QWidget, QString, &QWidget::accessibleDescription>(widget, "accessibleDescription").create();
  // void setAccessibleDescription(const QString &);
  bind::void_member_function<QWidget, const QString &, &QWidget::setAccessibleDescription>(widget, "setAccessibleDescription").create();
  // void setLayoutDirection(Qt::LayoutDirection);
  bind::void_member_function<QWidget, Qt::LayoutDirection, &QWidget::setLayoutDirection>(widget, "setLayoutDirection").create();
  // Qt::LayoutDirection layoutDirection() const;
  bind::member_function<QWidget, Qt::LayoutDirection, &QWidget::layoutDirection>(widget, "layoutDirection").create();
  // void unsetLayoutDirection();
  bind::void_member_function<QWidget, &QWidget::unsetLayoutDirection>(widget, "unsetLayoutDirection").create();
  // void setLocale(const QLocale &);
  bind::void_member_function<QWidget, const QLocale &, &QWidget::setLocale>(widget, "setLocale").create();
  // QLocale locale() const;
  bind::member_function<QWidget, QLocale, &QWidget::locale>(widget, "locale").create();
  // void unsetLocale();
  bind::void_member_function<QWidget, &QWidget::unsetLocale>(widget, "unsetLocale").create();
  // bool isRightToLeft() const;
  bind::member_function<QWidget, bool, &QWidget::isRightToLeft>(widget, "isRightToLeft").create();
  // bool isLeftToRight() const;
  bind::member_function<QWidget, bool, &QWidget::isLeftToRight>(widget, "isLeftToRight").create();
  // void setFocus();
  bind::void_member_function<QWidget, &QWidget::setFocus>(widget, "setFocus").create();
  // bool isActiveWindow() const;
  bind::member_function<QWidget, bool, &QWidget::isActiveWindow>(widget, "isActiveWindow").create();
  // void activateWindow();
  bind::void_member_function<QWidget, &QWidget::activateWindow>(widget, "activateWindow").create();
  // void clearFocus();
  bind::void_member_function<QWidget, &QWidget::clearFocus>(widget, "clearFocus").create();
  // void setFocus(Qt::FocusReason);
  bind::void_member_function<QWidget, Qt::FocusReason, &QWidget::setFocus>(widget, "setFocus").create();
  // Qt::FocusPolicy focusPolicy() const;
  bind::member_function<QWidget, Qt::FocusPolicy, &QWidget::focusPolicy>(widget, "focusPolicy").create();
  // void setFocusPolicy(Qt::FocusPolicy);
  bind::void_member_function<QWidget, Qt::FocusPolicy, &QWidget::setFocusPolicy>(widget, "setFocusPolicy").create();
  // bool hasFocus() const;
  bind::member_function<QWidget, bool, &QWidget::hasFocus>(widget, "hasFocus").create();
  // static void setTabOrder(QWidget *, QWidget *);
  bind::static_void_member_function<QWidget, QWidget *, QWidget *, &QWidget::setTabOrder>(widget, "setTabOrder").create();
  // void setFocusProxy(QWidget *);
  bind::void_member_function<QWidget, QWidget *, &QWidget::setFocusProxy>(widget, "setFocusProxy").create();
  // QWidget * focusProxy() const;
  bind::member_function<QWidget, QWidget *, &QWidget::focusProxy>(widget, "focusProxy").create();
  // Qt::ContextMenuPolicy contextMenuPolicy() const;
  bind::member_function<QWidget, Qt::ContextMenuPolicy, &QWidget::contextMenuPolicy>(widget, "contextMenuPolicy").create();
  // void setContextMenuPolicy(Qt::ContextMenuPolicy);
  bind::void_member_function<QWidget, Qt::ContextMenuPolicy, &QWidget::setContextMenuPolicy>(widget, "setContextMenuPolicy").create();
  // void grabMouse();
  bind::void_member_function<QWidget, &QWidget::grabMouse>(widget, "grabMouse").create();
  // void grabMouse(const QCursor &);
  bind::void_member_function<QWidget, const QCursor &, &QWidget::grabMouse>(widget, "grabMouse").create();
  // void releaseMouse();
  bind::void_member_function<QWidget, &QWidget::releaseMouse>(widget, "releaseMouse").create();
  // void grabKeyboard();
  bind::void_member_function<QWidget, &QWidget::grabKeyboard>(widget, "grabKeyboard").create();
  // void releaseKeyboard();
  bind::void_member_function<QWidget, &QWidget::releaseKeyboard>(widget, "releaseKeyboard").create();
  // int grabShortcut(const QKeySequence &, Qt::ShortcutContext = Qt::WindowShortcut);
  bind::member_function<QWidget, int, const QKeySequence &, Qt::ShortcutContext, &QWidget::grabShortcut>(widget, "grabShortcut")
    .apply(bind::default_arguments(Qt::WindowShortcut)).create();
  // void releaseShortcut(int);
  bind::void_member_function<QWidget, int, &QWidget::releaseShortcut>(widget, "releaseShortcut").create();
  // void setShortcutEnabled(int, bool = true);
  bind::void_member_function<QWidget, int, bool, &QWidget::setShortcutEnabled>(widget, "setShortcutEnabled")
    .apply(bind::default_arguments(true)).create();
  // void setShortcutAutoRepeat(int, bool = true);
  bind::void_member_function<QWidget, int, bool, &QWidget::setShortcutAutoRepeat>(widget, "setShortcutAutoRepeat")
    .apply(bind::default_arguments(true)).create();
  // static QWidget * mouseGrabber();
  bind::static_member_function<QWidget, QWidget *, &QWidget::mouseGrabber>(widget, "mouseGrabber").create();
  // static QWidget * keyboardGrabber();
  bind::static_member_function<QWidget, QWidget *, &QWidget::keyboardGrabber>(widget, "keyboardGrabber").create();
  // bool updatesEnabled() const;
  bind::member_function<QWidget, bool, &QWidget::updatesEnabled>(widget, "updatesEnabled").create();
  // void setUpdatesEnabled(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setUpdatesEnabled>(widget, "setUpdatesEnabled").create();
  // QGraphicsProxyWidget * graphicsProxyWidget() const;
  /// TODO: QGraphicsProxyWidget * graphicsProxyWidget() const;
  // void update();
  bind::void_member_function<QWidget, &QWidget::update>(widget, "update").create();
  // void repaint();
  bind::void_member_function<QWidget, &QWidget::repaint>(widget, "repaint").create();
  // void update(int, int, int, int);
  bind::void_member_function<QWidget, int, int, int, int, &QWidget::update>(widget, "update").create();
  // void update(const QRect &);
  bind::void_member_function<QWidget, const QRect &, &QWidget::update>(widget, "update").create();
  // void update(const QRegion &);
  bind::void_member_function<QWidget, const QRegion &, &QWidget::update>(widget, "update").create();
  // void repaint(int, int, int, int);
  bind::void_member_function<QWidget, int, int, int, int, &QWidget::repaint>(widget, "repaint").create();
  // void repaint(const QRect &);
  bind::void_member_function<QWidget, const QRect &, &QWidget::repaint>(widget, "repaint").create();
  // void repaint(const QRegion &);
  bind::void_member_function<QWidget, const QRegion &, &QWidget::repaint>(widget, "repaint").create();
  // void setVisible(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setVisible>(widget, "setVisible").create();
  // void setHidden(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setHidden>(widget, "setHidden").create();
  // void show();
  bind::void_member_function<QWidget, &QWidget::show>(widget, "show").create();
  // void hide();
  bind::void_member_function<QWidget, &QWidget::hide>(widget, "hide").create();
  // void showMinimized();
  bind::void_member_function<QWidget, &QWidget::showMinimized>(widget, "showMinimized").create();
  // void showMaximized();
  bind::void_member_function<QWidget, &QWidget::showMaximized>(widget, "showMaximized").create();
  // void showFullScreen();
  bind::void_member_function<QWidget, &QWidget::showFullScreen>(widget, "showFullScreen").create();
  // void showNormal();
  bind::void_member_function<QWidget, &QWidget::showNormal>(widget, "showNormal").create();
  // bool close();
  bind::member_function<QWidget, bool, &QWidget::close>(widget, "close").create();
  // void raise();
  bind::void_member_function<QWidget, &QWidget::raise>(widget, "raise").create();
  // void lower();
  bind::void_member_function<QWidget, &QWidget::lower>(widget, "lower").create();
  // void stackUnder(QWidget *);
  bind::void_member_function<QWidget, QWidget *, &QWidget::stackUnder>(widget, "stackUnder").create();
  // void move(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::move>(widget, "move").create();
  // void move(const QPoint &);
  bind::void_member_function<QWidget, const QPoint &, &QWidget::move>(widget, "move").create();
  // void resize(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::resize>(widget, "resize").create();
  // void resize(const QSize &);
  bind::void_member_function<QWidget, const QSize &, &QWidget::resize>(widget, "resize").create();
  // void setGeometry(int, int, int, int);
  bind::void_member_function<QWidget, int, int, int, int, &QWidget::setGeometry>(widget, "setGeometry").create();
  // void setGeometry(const QRect &);
  bind::void_member_function<QWidget, const QRect &, &QWidget::setGeometry>(widget, "setGeometry").create();
  // QByteArray saveGeometry() const;
  bind::member_function<QWidget, QByteArray, &QWidget::saveGeometry>(widget, "saveGeometry").create();
  // bool restoreGeometry(const QByteArray &);
  bind::member_function<QWidget, bool, const QByteArray &, &QWidget::restoreGeometry>(widget, "restoreGeometry").create();
  // void adjustSize();
  bind::void_member_function<QWidget, &QWidget::adjustSize>(widget, "adjustSize").create();
  // bool isVisible() const;
  bind::member_function<QWidget, bool, &QWidget::isVisible>(widget, "isVisible").create();
  // bool isVisibleTo(const QWidget *) const;
  bind::member_function<QWidget, bool, const QWidget *, &QWidget::isVisibleTo>(widget, "isVisibleTo").create();
  // bool isHidden() const;
  bind::member_function<QWidget, bool, &QWidget::isHidden>(widget, "isHidden").create();
  // bool isMinimized() const;
  bind::member_function<QWidget, bool, &QWidget::isMinimized>(widget, "isMinimized").create();
  // bool isMaximized() const;
  bind::member_function<QWidget, bool, &QWidget::isMaximized>(widget, "isMaximized").create();
  // bool isFullScreen() const;
  bind::member_function<QWidget, bool, &QWidget::isFullScreen>(widget, "isFullScreen").create();
  // Qt::WindowStates windowState() const;
  /// TODO: Qt::WindowStates windowState() const;
  // void setWindowState(Qt::WindowStates);
  /// TODO: void setWindowState(Qt::WindowStates);
  // void overrideWindowState(Qt::WindowStates);
  /// TODO: void overrideWindowState(Qt::WindowStates);
  // QSize sizeHint() const;
  bind::member_function<QWidget, QSize, &QWidget::sizeHint>(widget, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QWidget, QSize, &QWidget::minimumSizeHint>(widget, "minimumSizeHint").create();
  // QSizePolicy sizePolicy() const;
  /// TODO: QSizePolicy sizePolicy() const;
  // void setSizePolicy(QSizePolicy);
  /// TODO: void setSizePolicy(QSizePolicy);
  // void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  /// TODO: void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  // int heightForWidth(int) const;
  bind::member_function<QWidget, int, int, &QWidget::heightForWidth>(widget, "heightForWidth").create();
  // bool hasHeightForWidth() const;
  bind::member_function<QWidget, bool, &QWidget::hasHeightForWidth>(widget, "hasHeightForWidth").create();
  // QRegion visibleRegion() const;
  bind::member_function<QWidget, QRegion, &QWidget::visibleRegion>(widget, "visibleRegion").create();
  // void setContentsMargins(int, int, int, int);
  bind::void_member_function<QWidget, int, int, int, int, &QWidget::setContentsMargins>(widget, "setContentsMargins").create();
  // void setContentsMargins(const QMargins &);
  bind::void_member_function<QWidget, const QMargins &, &QWidget::setContentsMargins>(widget, "setContentsMargins").create();
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  bind::member_function<QWidget, QMargins, &QWidget::contentsMargins>(widget, "contentsMargins").create();
  // QRect contentsRect() const;
  bind::member_function<QWidget, QRect, &QWidget::contentsRect>(widget, "contentsRect").create();
  // QLayout * layout() const;
  bind::member_function<QWidget, QLayout *, &QWidget::layout>(widget, "layout").create();
  // void setLayout(QLayout *);
  bind::void_member_function<QWidget, QLayout *, &QWidget::setLayout>(widget, "setLayout").create();
  // void updateGeometry();
  bind::void_member_function<QWidget, &QWidget::updateGeometry>(widget, "updateGeometry").create();
  // void setParent(QWidget *);
  bind::void_member_function<QWidget, QWidget *, &QWidget::setParent>(widget, "setParent").create();
  // void setParent(QWidget *, Qt::WindowFlags);
  /// TODO: void setParent(QWidget *, Qt::WindowFlags);
  // void scroll(int, int);
  bind::void_member_function<QWidget, int, int, &QWidget::scroll>(widget, "scroll").create();
  // void scroll(int, int, const QRect &);
  bind::void_member_function<QWidget, int, int, const QRect &, &QWidget::scroll>(widget, "scroll").create();
  // QWidget * focusWidget() const;
  bind::member_function<QWidget, QWidget *, &QWidget::focusWidget>(widget, "focusWidget").create();
  // QWidget * nextInFocusChain() const;
  bind::member_function<QWidget, QWidget *, &QWidget::nextInFocusChain>(widget, "nextInFocusChain").create();
  // QWidget * previousInFocusChain() const;
  bind::member_function<QWidget, QWidget *, &QWidget::previousInFocusChain>(widget, "previousInFocusChain").create();
  // bool acceptDrops() const;
  bind::member_function<QWidget, bool, &QWidget::acceptDrops>(widget, "acceptDrops").create();
  // void setAcceptDrops(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setAcceptDrops>(widget, "setAcceptDrops").create();
  // void addAction(QAction *);
  bind::void_member_function<QWidget, QAction *, &QWidget::addAction>(widget, "addAction").create();
  // void addActions(QList<QAction *>);
  /// TODO: void addActions(QList<QAction *>);
  // void insertActions(QAction *, QList<QAction *>);
  /// TODO: void insertActions(QAction *, QList<QAction *>);
  // void insertAction(QAction *, QAction *);
  bind::void_member_function<QWidget, QAction *, QAction *, &QWidget::insertAction>(widget, "insertAction").create();
  // void removeAction(QAction *);
  bind::void_member_function<QWidget, QAction *, &QWidget::removeAction>(widget, "removeAction").create();
  // QList<QAction *> actions() const;
  /// TODO: QList<QAction *> actions() const;
  // QWidget * parentWidget() const;
  bind::member_function<QWidget, QWidget *, &QWidget::parentWidget>(widget, "parentWidget").create();
  // void setWindowFlags(Qt::WindowFlags);
  /// TODO: void setWindowFlags(Qt::WindowFlags);
  // Qt::WindowFlags windowFlags() const;
  /// TODO: Qt::WindowFlags windowFlags() const;
  // void setWindowFlag(Qt::WindowType, bool = true);
  bind::void_member_function<QWidget, Qt::WindowType, bool, &QWidget::setWindowFlag>(widget, "setWindowFlag")
    .apply(bind::default_arguments(true)).create();
  // void overrideWindowFlags(Qt::WindowFlags);
  /// TODO: void overrideWindowFlags(Qt::WindowFlags);
  // Qt::WindowType windowType() const;
  bind::member_function<QWidget, Qt::WindowType, &QWidget::windowType>(widget, "windowType").create();
  // static QWidget * find(WId);
  /// TODO: static QWidget * find(WId);
  // QWidget * childAt(int, int) const;
  bind::member_function<QWidget, QWidget *, int, int, &QWidget::childAt>(widget, "childAt").create();
  // QWidget * childAt(const QPoint &) const;
  bind::member_function<QWidget, QWidget *, const QPoint &, &QWidget::childAt>(widget, "childAt").create();
  // void setAttribute(Qt::WidgetAttribute, bool = true);
  bind::void_member_function<QWidget, Qt::WidgetAttribute, bool, &QWidget::setAttribute>(widget, "setAttribute")
    .apply(bind::default_arguments(true)).create();
  // bool testAttribute(Qt::WidgetAttribute) const;
  bind::member_function<QWidget, bool, Qt::WidgetAttribute, &QWidget::testAttribute>(widget, "testAttribute").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // void ensurePolished() const;
  bind::const_void_member_function<QWidget, &QWidget::ensurePolished>(widget, "ensurePolished").create();
  // bool isAncestorOf(const QWidget *) const;
  bind::member_function<QWidget, bool, const QWidget *, &QWidget::isAncestorOf>(widget, "isAncestorOf").create();
  // bool autoFillBackground() const;
  bind::member_function<QWidget, bool, &QWidget::autoFillBackground>(widget, "autoFillBackground").create();
  // void setAutoFillBackground(bool);
  bind::void_member_function<QWidget, bool, &QWidget::setAutoFillBackground>(widget, "setAutoFillBackground").create();
  // QBackingStore * backingStore() const;
  /// TODO: QBackingStore * backingStore() const;
  // QWindow * windowHandle() const;
  bind::member_function<QWidget, QWindow *, &QWidget::windowHandle>(widget, "windowHandle").create();
  // static QWidget * createWindowContainer(QWindow *, QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: static QWidget * createWindowContainer(QWindow *, QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // void windowTitleChanged(const QString &);
  bind::signal<QWidget, const QString &>(widget, "windowTitleChanged", "windowTitleChanged(const QString &)");
  // void windowIconChanged(const QIcon &);
  bind::signal<QWidget, const QIcon &>(widget, "windowIconChanged", "windowIconChanged(const QIcon &)");
  // void windowIconTextChanged(const QString &);
  bind::signal<QWidget, const QString &>(widget, "windowIconTextChanged", "windowIconTextChanged(const QString &)");
  // void customContextMenuRequested(const QPoint &);
  bind::signal<QWidget, const QPoint &>(widget, "customContextMenuRequested", "customContextMenuRequested(const QPoint &)");
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  bind::member_function<QWidget, QVariant, Qt::InputMethodQuery, &QWidget::inputMethodQuery>(widget, "inputMethodQuery").create();
  // Qt::InputMethodHints inputMethodHints() const;
  /// TODO: Qt::InputMethodHints inputMethodHints() const;
  // void setInputMethodHints(Qt::InputMethodHints);
  /// TODO: void setInputMethodHints(Qt::InputMethodHints);

  bind::link(widget, &QWidget::staticMetaObject);
}


void register_widget_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_widget_class(ns);

  // QFlags<QWidget::RenderFlags::enum_type> operator|(QWidget::RenderFlags::enum_type, QWidget::RenderFlags::enum_type);
  /// TODO: QFlags<QWidget::RenderFlags::enum_type> operator|(QWidget::RenderFlags::enum_type, QWidget::RenderFlags::enum_type);
  // QFlags<QWidget::RenderFlags::enum_type> operator|(QWidget::RenderFlags::enum_type, QFlags<QWidget::RenderFlags::enum_type>);
  /// TODO: QFlags<QWidget::RenderFlags::enum_type> operator|(QWidget::RenderFlags::enum_type, QFlags<QWidget::RenderFlags::enum_type>);
  // QIncompatibleFlag operator|(QWidget::RenderFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QWidget::RenderFlags::enum_type, int);
  // QDebug operator<<(QDebug, const QWidget *);
  /// TODO: QDebug operator<<(QDebug, const QWidget *);
  void register_newwidget_file(script::Namespace n); // defined in newwidget.cpp
  register_newwidget_file(widgets);
}

