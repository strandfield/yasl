// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/widget.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/listspecializations.h"
#include "yasl/utils/ref.h"

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

  Enum render_flag = widget.Enum("RenderFlag").setId(script::Type::QWidgetRenderFlag).get();

  render_flag.addValue("DrawWindowBackground", QWidget::DrawWindowBackground);
  render_flag.addValue("DrawChildren", QWidget::DrawChildren);
  render_flag.addValue("IgnoreMask", QWidget::IgnoreMask);
}


static void register_widget_class(script::Namespace ns)
{
  using namespace script;

  Class widget = ns.Class("Widget").setId(script::Type::QWidget)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(widget.engine(), script::Type::QWidget, script::Type::QWidgetStar);
  register_ptr_specialization<QWidget*>(widget.engine()->getTemplate(Engine::PtrTemplate), script::Type::PtrQWidget);
  register_list_specialization<QWidget*>(widget.engine(), script::Type::QListQWidget);
  register_widget_render_flag_enum(widget);
  binding::QClass<QWidget> binder{ widget, &QWidget::staticMetaObject };

  // QWidget(QWidget *, Qt::WindowFlags);
  /// TODO: QWidget(QWidget *, Qt::WindowFlags);
  // ~QWidget();
  binder.add_dtor();
  // int devType() const;
  binder.fun<int, &QWidget::devType>("devType").create();
  // WId winId() const;
  /// TODO: WId winId() const;
  // void createWinId();
  binder.void_fun<&QWidget::createWinId>("createWinId").create();
  // WId internalWinId() const;
  /// TODO: WId internalWinId() const;
  // WId effectiveWinId() const;
  /// TODO: WId effectiveWinId() const;
  // QStyle * style() const;
  /// TODO: QStyle * style() const;
  // void setStyle(QStyle *);
  /// TODO: void setStyle(QStyle *);
  // bool isTopLevel() const;
  binder.fun<bool, &QWidget::isTopLevel>("isTopLevel").create();
  // bool isWindow() const;
  binder.fun<bool, &QWidget::isWindow>("isWindow").create();
  // bool isModal() const;
  binder.fun<bool, &QWidget::isModal>("isModal").create();
  // Qt::WindowModality windowModality() const;
  binder.fun<Qt::WindowModality, &QWidget::windowModality>("windowModality").create();
  // void setWindowModality(Qt::WindowModality);
  binder.void_fun<Qt::WindowModality, &QWidget::setWindowModality>("setWindowModality").create();
  // bool isEnabled() const;
  binder.fun<bool, &QWidget::isEnabled>("isEnabled").create();
  // bool isEnabledTo(const QWidget *) const;
  binder.fun<bool, const QWidget *, &QWidget::isEnabledTo>("isEnabledTo").create();
  // bool isEnabledToTLW() const;
  binder.fun<bool, &QWidget::isEnabledToTLW>("isEnabledToTLW").create();
  // void setEnabled(bool);
  binder.void_fun<bool, &QWidget::setEnabled>("setEnabled").create();
  // void setDisabled(bool);
  binder.void_fun<bool, &QWidget::setDisabled>("setDisabled").create();
  // void setWindowModified(bool);
  binder.void_fun<bool, &QWidget::setWindowModified>("setWindowModified").create();
  // QRect frameGeometry() const;
  binder.fun<QRect, &QWidget::frameGeometry>("frameGeometry").create();
  // const QRect & geometry() const;
  binder.fun<const QRect &, &QWidget::geometry>("geometry").create();
  // QRect normalGeometry() const;
  binder.fun<QRect, &QWidget::normalGeometry>("normalGeometry").create();
  // int x() const;
  binder.fun<int, &QWidget::x>("x").create();
  // int y() const;
  binder.fun<int, &QWidget::y>("y").create();
  // QPoint pos() const;
  binder.fun<QPoint, &QWidget::pos>("pos").create();
  // QSize frameSize() const;
  binder.fun<QSize, &QWidget::frameSize>("frameSize").create();
  // QSize size() const;
  binder.fun<QSize, &QWidget::size>("size").create();
  // int width() const;
  binder.fun<int, &QWidget::width>("width").create();
  // int height() const;
  binder.fun<int, &QWidget::height>("height").create();
  // QRect rect() const;
  binder.fun<QRect, &QWidget::rect>("rect").create();
  // QRect childrenRect() const;
  binder.fun<QRect, &QWidget::childrenRect>("childrenRect").create();
  // QRegion childrenRegion() const;
  binder.fun<QRegion, &QWidget::childrenRegion>("childrenRegion").create();
  // QSize minimumSize() const;
  binder.fun<QSize, &QWidget::minimumSize>("minimumSize").create();
  // QSize maximumSize() const;
  binder.fun<QSize, &QWidget::maximumSize>("maximumSize").create();
  // int minimumWidth() const;
  binder.fun<int, &QWidget::minimumWidth>("minimumWidth").create();
  // int minimumHeight() const;
  binder.fun<int, &QWidget::minimumHeight>("minimumHeight").create();
  // int maximumWidth() const;
  binder.fun<int, &QWidget::maximumWidth>("maximumWidth").create();
  // int maximumHeight() const;
  binder.fun<int, &QWidget::maximumHeight>("maximumHeight").create();
  // void setMinimumSize(const QSize &);
  binder.void_fun<const QSize &, &QWidget::setMinimumSize>("setMinimumSize").create();
  // void setMinimumSize(int, int);
  binder.void_fun<int, int, &QWidget::setMinimumSize>("setMinimumSize").create();
  // void setMaximumSize(const QSize &);
  binder.void_fun<const QSize &, &QWidget::setMaximumSize>("setMaximumSize").create();
  // void setMaximumSize(int, int);
  binder.void_fun<int, int, &QWidget::setMaximumSize>("setMaximumSize").create();
  // void setMinimumWidth(int);
  binder.void_fun<int, &QWidget::setMinimumWidth>("setMinimumWidth").create();
  // void setMinimumHeight(int);
  binder.void_fun<int, &QWidget::setMinimumHeight>("setMinimumHeight").create();
  // void setMaximumWidth(int);
  binder.void_fun<int, &QWidget::setMaximumWidth>("setMaximumWidth").create();
  // void setMaximumHeight(int);
  binder.void_fun<int, &QWidget::setMaximumHeight>("setMaximumHeight").create();
  // QSize sizeIncrement() const;
  binder.fun<QSize, &QWidget::sizeIncrement>("sizeIncrement").create();
  // void setSizeIncrement(const QSize &);
  binder.void_fun<const QSize &, &QWidget::setSizeIncrement>("setSizeIncrement").create();
  // void setSizeIncrement(int, int);
  binder.void_fun<int, int, &QWidget::setSizeIncrement>("setSizeIncrement").create();
  // QSize baseSize() const;
  binder.fun<QSize, &QWidget::baseSize>("baseSize").create();
  // void setBaseSize(const QSize &);
  binder.void_fun<const QSize &, &QWidget::setBaseSize>("setBaseSize").create();
  // void setBaseSize(int, int);
  binder.void_fun<int, int, &QWidget::setBaseSize>("setBaseSize").create();
  // void setFixedSize(const QSize &);
  binder.void_fun<const QSize &, &QWidget::setFixedSize>("setFixedSize").create();
  // void setFixedSize(int, int);
  binder.void_fun<int, int, &QWidget::setFixedSize>("setFixedSize").create();
  // void setFixedWidth(int);
  binder.void_fun<int, &QWidget::setFixedWidth>("setFixedWidth").create();
  // void setFixedHeight(int);
  binder.void_fun<int, &QWidget::setFixedHeight>("setFixedHeight").create();
  // QPoint mapToGlobal(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWidget::mapToGlobal>("mapToGlobal").create();
  // QPoint mapFromGlobal(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWidget::mapFromGlobal>("mapFromGlobal").create();
  // QPoint mapToParent(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWidget::mapToParent>("mapToParent").create();
  // QPoint mapFromParent(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QWidget::mapFromParent>("mapFromParent").create();
  // QPoint mapTo(const QWidget *, const QPoint &) const;
  binder.fun<QPoint, const QWidget *, const QPoint &, &QWidget::mapTo>("mapTo").create();
  // QPoint mapFrom(const QWidget *, const QPoint &) const;
  binder.fun<QPoint, const QWidget *, const QPoint &, &QWidget::mapFrom>("mapFrom").create();
  // QWidget * window() const;
  binder.fun<QWidget *, &QWidget::window>("window").create();
  // QWidget * nativeParentWidget() const;
  binder.fun<QWidget *, &QWidget::nativeParentWidget>("nativeParentWidget").create();
  // QWidget * topLevelWidget() const;
  binder.fun<QWidget *, &QWidget::topLevelWidget>("topLevelWidget").create();
  // const QPalette & palette() const;
  binder.fun<const QPalette &, &QWidget::palette>("palette").create();
  // void setPalette(const QPalette &);
  binder.void_fun<const QPalette &, &QWidget::setPalette>("setPalette").create();
  // void setBackgroundRole(QPalette::ColorRole);
  binder.void_fun<QPalette::ColorRole, &QWidget::setBackgroundRole>("setBackgroundRole").create();
  // QPalette::ColorRole backgroundRole() const;
  binder.fun<QPalette::ColorRole, &QWidget::backgroundRole>("backgroundRole").create();
  // void setForegroundRole(QPalette::ColorRole);
  binder.void_fun<QPalette::ColorRole, &QWidget::setForegroundRole>("setForegroundRole").create();
  // QPalette::ColorRole foregroundRole() const;
  binder.fun<QPalette::ColorRole, &QWidget::foregroundRole>("foregroundRole").create();
  // const QFont & font() const;
  binder.fun<const QFont &, &QWidget::font>("font").create();
  // void setFont(const QFont &);
  binder.void_fun<const QFont &, &QWidget::setFont>("setFont").create();
  // QFontMetrics fontMetrics() const;
  binder.fun<QFontMetrics, &QWidget::fontMetrics>("fontMetrics").create();
  // QFontInfo fontInfo() const;
  binder.fun<QFontInfo, &QWidget::fontInfo>("fontInfo").create();
  // QCursor cursor() const;
  binder.fun<QCursor, &QWidget::cursor>("cursor").create();
  // void setCursor(const QCursor &);
  binder.void_fun<const QCursor &, &QWidget::setCursor>("setCursor").create();
  // void unsetCursor();
  binder.void_fun<&QWidget::unsetCursor>("unsetCursor").create();
  // void setMouseTracking(bool);
  binder.void_fun<bool, &QWidget::setMouseTracking>("setMouseTracking").create();
  // bool hasMouseTracking() const;
  binder.fun<bool, &QWidget::hasMouseTracking>("hasMouseTracking").create();
  // bool underMouse() const;
  binder.fun<bool, &QWidget::underMouse>("underMouse").create();
  // void setTabletTracking(bool);
  binder.void_fun<bool, &QWidget::setTabletTracking>("setTabletTracking").create();
  // bool hasTabletTracking() const;
  binder.fun<bool, &QWidget::hasTabletTracking>("hasTabletTracking").create();
  // void setMask(const QBitmap &);
  binder.void_fun<const QBitmap &, &QWidget::setMask>("setMask").create();
  // void setMask(const QRegion &);
  binder.void_fun<const QRegion &, &QWidget::setMask>("setMask").create();
  // QRegion mask() const;
  binder.fun<QRegion, &QWidget::mask>("mask").create();
  // void clearMask();
  binder.void_fun<&QWidget::clearMask>("clearMask").create();
  // void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  /// TODO: void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  // void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  /// TODO: void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  // QPixmap grab(const QRect &);
  binder.fun<QPixmap, const QRect &, &QWidget::grab>("grab").create();
  // QGraphicsEffect * graphicsEffect() const;
  /// TODO: QGraphicsEffect * graphicsEffect() const;
  // void setGraphicsEffect(QGraphicsEffect *);
  /// TODO: void setGraphicsEffect(QGraphicsEffect *);
  // void grabGesture(Qt::GestureType, Qt::GestureFlags);
  /// TODO: void grabGesture(Qt::GestureType, Qt::GestureFlags);
  // void ungrabGesture(Qt::GestureType);
  binder.void_fun<Qt::GestureType, &QWidget::ungrabGesture>("ungrabGesture").create();
  // void setWindowTitle(const QString &);
  binder.void_fun<const QString &, &QWidget::setWindowTitle>("setWindowTitle").create();
  // void setStyleSheet(const QString &);
  binder.void_fun<const QString &, &QWidget::setStyleSheet>("setStyleSheet").create();
  // QString styleSheet() const;
  binder.fun<QString, &QWidget::styleSheet>("styleSheet").create();
  // QString windowTitle() const;
  binder.fun<QString, &QWidget::windowTitle>("windowTitle").create();
  // void setWindowIcon(const QIcon &);
  binder.void_fun<const QIcon &, &QWidget::setWindowIcon>("setWindowIcon").create();
  // QIcon windowIcon() const;
  binder.fun<QIcon, &QWidget::windowIcon>("windowIcon").create();
  // void setWindowIconText(const QString &);
  binder.void_fun<const QString &, &QWidget::setWindowIconText>("setWindowIconText").create();
  // QString windowIconText() const;
  binder.fun<QString, &QWidget::windowIconText>("windowIconText").create();
  // void setWindowRole(const QString &);
  binder.void_fun<const QString &, &QWidget::setWindowRole>("setWindowRole").create();
  // QString windowRole() const;
  binder.fun<QString, &QWidget::windowRole>("windowRole").create();
  // void setWindowFilePath(const QString &);
  binder.void_fun<const QString &, &QWidget::setWindowFilePath>("setWindowFilePath").create();
  // QString windowFilePath() const;
  binder.fun<QString, &QWidget::windowFilePath>("windowFilePath").create();
  // void setWindowOpacity(qreal);
  binder.void_fun<qreal, &QWidget::setWindowOpacity>("setWindowOpacity").create();
  // qreal windowOpacity() const;
  binder.fun<qreal, &QWidget::windowOpacity>("windowOpacity").create();
  // bool isWindowModified() const;
  binder.fun<bool, &QWidget::isWindowModified>("isWindowModified").create();
  // void setToolTip(const QString &);
  binder.void_fun<const QString &, &QWidget::setToolTip>("setToolTip").create();
  // QString toolTip() const;
  binder.fun<QString, &QWidget::toolTip>("toolTip").create();
  // void setToolTipDuration(int);
  binder.void_fun<int, &QWidget::setToolTipDuration>("setToolTipDuration").create();
  // int toolTipDuration() const;
  binder.fun<int, &QWidget::toolTipDuration>("toolTipDuration").create();
  // void setStatusTip(const QString &);
  binder.void_fun<const QString &, &QWidget::setStatusTip>("setStatusTip").create();
  // QString statusTip() const;
  binder.fun<QString, &QWidget::statusTip>("statusTip").create();
  // void setWhatsThis(const QString &);
  binder.void_fun<const QString &, &QWidget::setWhatsThis>("setWhatsThis").create();
  // QString whatsThis() const;
  binder.fun<QString, &QWidget::whatsThis>("whatsThis").create();
  // QString accessibleName() const;
  binder.fun<QString, &QWidget::accessibleName>("accessibleName").create();
  // void setAccessibleName(const QString &);
  binder.void_fun<const QString &, &QWidget::setAccessibleName>("setAccessibleName").create();
  // QString accessibleDescription() const;
  binder.fun<QString, &QWidget::accessibleDescription>("accessibleDescription").create();
  // void setAccessibleDescription(const QString &);
  binder.void_fun<const QString &, &QWidget::setAccessibleDescription>("setAccessibleDescription").create();
  // void setLayoutDirection(Qt::LayoutDirection);
  binder.void_fun<Qt::LayoutDirection, &QWidget::setLayoutDirection>("setLayoutDirection").create();
  // Qt::LayoutDirection layoutDirection() const;
  binder.fun<Qt::LayoutDirection, &QWidget::layoutDirection>("layoutDirection").create();
  // void unsetLayoutDirection();
  binder.void_fun<&QWidget::unsetLayoutDirection>("unsetLayoutDirection").create();
  // void setLocale(const QLocale &);
  binder.void_fun<const QLocale &, &QWidget::setLocale>("setLocale").create();
  // QLocale locale() const;
  binder.fun<QLocale, &QWidget::locale>("locale").create();
  // void unsetLocale();
  binder.void_fun<&QWidget::unsetLocale>("unsetLocale").create();
  // bool isRightToLeft() const;
  binder.fun<bool, &QWidget::isRightToLeft>("isRightToLeft").create();
  // bool isLeftToRight() const;
  binder.fun<bool, &QWidget::isLeftToRight>("isLeftToRight").create();
  // void setFocus();
  binder.void_fun<&QWidget::setFocus>("setFocus").create();
  // bool isActiveWindow() const;
  binder.fun<bool, &QWidget::isActiveWindow>("isActiveWindow").create();
  // void activateWindow();
  binder.void_fun<&QWidget::activateWindow>("activateWindow").create();
  // void clearFocus();
  binder.void_fun<&QWidget::clearFocus>("clearFocus").create();
  // void setFocus(Qt::FocusReason);
  binder.void_fun<Qt::FocusReason, &QWidget::setFocus>("setFocus").create();
  // Qt::FocusPolicy focusPolicy() const;
  binder.fun<Qt::FocusPolicy, &QWidget::focusPolicy>("focusPolicy").create();
  // void setFocusPolicy(Qt::FocusPolicy);
  binder.void_fun<Qt::FocusPolicy, &QWidget::setFocusPolicy>("setFocusPolicy").create();
  // bool hasFocus() const;
  binder.fun<bool, &QWidget::hasFocus>("hasFocus").create();
  // static void setTabOrder(QWidget *, QWidget *);
  binder.static_void_fun<QWidget *, QWidget *, &QWidget::setTabOrder>("setTabOrder").create();
  // void setFocusProxy(QWidget *);
  binder.void_fun<QWidget *, &QWidget::setFocusProxy>("setFocusProxy").create();
  // QWidget * focusProxy() const;
  binder.fun<QWidget *, &QWidget::focusProxy>("focusProxy").create();
  // Qt::ContextMenuPolicy contextMenuPolicy() const;
  binder.fun<Qt::ContextMenuPolicy, &QWidget::contextMenuPolicy>("contextMenuPolicy").create();
  // void setContextMenuPolicy(Qt::ContextMenuPolicy);
  binder.void_fun<Qt::ContextMenuPolicy, &QWidget::setContextMenuPolicy>("setContextMenuPolicy").create();
  // void grabMouse();
  binder.void_fun<&QWidget::grabMouse>("grabMouse").create();
  // void grabMouse(const QCursor &);
  binder.void_fun<const QCursor &, &QWidget::grabMouse>("grabMouse").create();
  // void releaseMouse();
  binder.void_fun<&QWidget::releaseMouse>("releaseMouse").create();
  // void grabKeyboard();
  binder.void_fun<&QWidget::grabKeyboard>("grabKeyboard").create();
  // void releaseKeyboard();
  binder.void_fun<&QWidget::releaseKeyboard>("releaseKeyboard").create();
  // int grabShortcut(const QKeySequence &, Qt::ShortcutContext);
  binder.fun<int, const QKeySequence &, Qt::ShortcutContext, &QWidget::grabShortcut>("grabShortcut").create();
  // void releaseShortcut(int);
  binder.void_fun<int, &QWidget::releaseShortcut>("releaseShortcut").create();
  // void setShortcutEnabled(int, bool);
  binder.void_fun<int, bool, &QWidget::setShortcutEnabled>("setShortcutEnabled").create();
  // void setShortcutAutoRepeat(int, bool);
  binder.void_fun<int, bool, &QWidget::setShortcutAutoRepeat>("setShortcutAutoRepeat").create();
  // static QWidget * mouseGrabber();
  binder.static_fun<QWidget *, &QWidget::mouseGrabber>("mouseGrabber").create();
  // static QWidget * keyboardGrabber();
  binder.static_fun<QWidget *, &QWidget::keyboardGrabber>("keyboardGrabber").create();
  // bool updatesEnabled() const;
  binder.fun<bool, &QWidget::updatesEnabled>("updatesEnabled").create();
  // void setUpdatesEnabled(bool);
  binder.void_fun<bool, &QWidget::setUpdatesEnabled>("setUpdatesEnabled").create();
  // QGraphicsProxyWidget * graphicsProxyWidget() const;
  /// TODO: QGraphicsProxyWidget * graphicsProxyWidget() const;
  // void update();
  binder.void_fun<&QWidget::update>("update").create();
  // void repaint();
  binder.void_fun<&QWidget::repaint>("repaint").create();
  // void update(int, int, int, int);
  binder.void_fun<int, int, int, int, &QWidget::update>("update").create();
  // void update(const QRect &);
  binder.void_fun<const QRect &, &QWidget::update>("update").create();
  // void update(const QRegion &);
  binder.void_fun<const QRegion &, &QWidget::update>("update").create();
  // void repaint(int, int, int, int);
  binder.void_fun<int, int, int, int, &QWidget::repaint>("repaint").create();
  // void repaint(const QRect &);
  binder.void_fun<const QRect &, &QWidget::repaint>("repaint").create();
  // void repaint(const QRegion &);
  binder.void_fun<const QRegion &, &QWidget::repaint>("repaint").create();
  // void setVisible(bool);
  binder.void_fun<bool, &QWidget::setVisible>("setVisible").create();
  // void setHidden(bool);
  binder.void_fun<bool, &QWidget::setHidden>("setHidden").create();
  // void show();
  binder.void_fun<&QWidget::show>("show").create();
  // void hide();
  binder.void_fun<&QWidget::hide>("hide").create();
  // void showMinimized();
  binder.void_fun<&QWidget::showMinimized>("showMinimized").create();
  // void showMaximized();
  binder.void_fun<&QWidget::showMaximized>("showMaximized").create();
  // void showFullScreen();
  binder.void_fun<&QWidget::showFullScreen>("showFullScreen").create();
  // void showNormal();
  binder.void_fun<&QWidget::showNormal>("showNormal").create();
  // bool close();
  binder.fun<bool, &QWidget::close>("close").create();
  // void raise();
  binder.void_fun<&QWidget::raise>("raise").create();
  // void lower();
  binder.void_fun<&QWidget::lower>("lower").create();
  // void stackUnder(QWidget *);
  binder.void_fun<QWidget *, &QWidget::stackUnder>("stackUnder").create();
  // void move(int, int);
  binder.void_fun<int, int, &QWidget::move>("move").create();
  // void move(const QPoint &);
  binder.void_fun<const QPoint &, &QWidget::move>("move").create();
  // void resize(int, int);
  binder.void_fun<int, int, &QWidget::resize>("resize").create();
  // void resize(const QSize &);
  binder.void_fun<const QSize &, &QWidget::resize>("resize").create();
  // void setGeometry(int, int, int, int);
  binder.void_fun<int, int, int, int, &QWidget::setGeometry>("setGeometry").create();
  // void setGeometry(const QRect &);
  binder.void_fun<const QRect &, &QWidget::setGeometry>("setGeometry").create();
  // QByteArray saveGeometry() const;
  binder.fun<QByteArray, &QWidget::saveGeometry>("saveGeometry").create();
  // bool restoreGeometry(const QByteArray &);
  binder.fun<bool, const QByteArray &, &QWidget::restoreGeometry>("restoreGeometry").create();
  // void adjustSize();
  binder.void_fun<&QWidget::adjustSize>("adjustSize").create();
  // bool isVisible() const;
  binder.fun<bool, &QWidget::isVisible>("isVisible").create();
  // bool isVisibleTo(const QWidget *) const;
  binder.fun<bool, const QWidget *, &QWidget::isVisibleTo>("isVisibleTo").create();
  // bool isHidden() const;
  binder.fun<bool, &QWidget::isHidden>("isHidden").create();
  // bool isMinimized() const;
  binder.fun<bool, &QWidget::isMinimized>("isMinimized").create();
  // bool isMaximized() const;
  binder.fun<bool, &QWidget::isMaximized>("isMaximized").create();
  // bool isFullScreen() const;
  binder.fun<bool, &QWidget::isFullScreen>("isFullScreen").create();
  // Qt::WindowStates windowState() const;
  /// TODO: Qt::WindowStates windowState() const;
  // void setWindowState(Qt::WindowStates);
  /// TODO: void setWindowState(Qt::WindowStates);
  // void overrideWindowState(Qt::WindowStates);
  /// TODO: void overrideWindowState(Qt::WindowStates);
  // QSize sizeHint() const;
  binder.fun<QSize, &QWidget::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QWidget::minimumSizeHint>("minimumSizeHint").create();
  // QSizePolicy sizePolicy() const;
  /// TODO: QSizePolicy sizePolicy() const;
  // void setSizePolicy(QSizePolicy);
  /// TODO: void setSizePolicy(QSizePolicy);
  // void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  /// TODO: void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  // int heightForWidth(int) const;
  binder.fun<int, int, &QWidget::heightForWidth>("heightForWidth").create();
  // bool hasHeightForWidth() const;
  binder.fun<bool, &QWidget::hasHeightForWidth>("hasHeightForWidth").create();
  // QRegion visibleRegion() const;
  binder.fun<QRegion, &QWidget::visibleRegion>("visibleRegion").create();
  // void setContentsMargins(int, int, int, int);
  binder.void_fun<int, int, int, int, &QWidget::setContentsMargins>("setContentsMargins").create();
  // void setContentsMargins(const QMargins &);
  binder.void_fun<const QMargins &, &QWidget::setContentsMargins>("setContentsMargins").create();
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  binder.fun<QMargins, &QWidget::contentsMargins>("contentsMargins").create();
  // QRect contentsRect() const;
  binder.fun<QRect, &QWidget::contentsRect>("contentsRect").create();
  // QLayout * layout() const;
  binder.fun<QLayout *, &QWidget::layout>("layout").create();
  // void setLayout(QLayout *);
  binder.void_fun<QLayout *, &QWidget::setLayout>("setLayout").create();
  // void updateGeometry();
  binder.void_fun<&QWidget::updateGeometry>("updateGeometry").create();
  // void setParent(QWidget *);
  binder.void_fun<QWidget *, &QWidget::setParent>("setParent").create();
  // void setParent(QWidget *, Qt::WindowFlags);
  /// TODO: void setParent(QWidget *, Qt::WindowFlags);
  // void scroll(int, int);
  binder.void_fun<int, int, &QWidget::scroll>("scroll").create();
  // void scroll(int, int, const QRect &);
  binder.void_fun<int, int, const QRect &, &QWidget::scroll>("scroll").create();
  // QWidget * focusWidget() const;
  binder.fun<QWidget *, &QWidget::focusWidget>("focusWidget").create();
  // QWidget * nextInFocusChain() const;
  binder.fun<QWidget *, &QWidget::nextInFocusChain>("nextInFocusChain").create();
  // QWidget * previousInFocusChain() const;
  binder.fun<QWidget *, &QWidget::previousInFocusChain>("previousInFocusChain").create();
  // bool acceptDrops() const;
  binder.fun<bool, &QWidget::acceptDrops>("acceptDrops").create();
  // void setAcceptDrops(bool);
  binder.void_fun<bool, &QWidget::setAcceptDrops>("setAcceptDrops").create();
  // void addAction(QAction *);
  binder.void_fun<QAction *, &QWidget::addAction>("addAction").create();
  // void addActions(QList<QAction *>);
  /// TODO: void addActions(QList<QAction *>);
  // void insertActions(QAction *, QList<QAction *>);
  /// TODO: void insertActions(QAction *, QList<QAction *>);
  // void insertAction(QAction *, QAction *);
  binder.void_fun<QAction *, QAction *, &QWidget::insertAction>("insertAction").create();
  // void removeAction(QAction *);
  binder.void_fun<QAction *, &QWidget::removeAction>("removeAction").create();
  // QList<QAction *> actions() const;
  /// TODO: QList<QAction *> actions() const;
  // QWidget * parentWidget() const;
  binder.fun<QWidget *, &QWidget::parentWidget>("parentWidget").create();
  // void setWindowFlags(Qt::WindowFlags);
  /// TODO: void setWindowFlags(Qt::WindowFlags);
  // Qt::WindowFlags windowFlags() const;
  /// TODO: Qt::WindowFlags windowFlags() const;
  // void setWindowFlag(Qt::WindowType, bool);
  binder.void_fun<Qt::WindowType, bool, &QWidget::setWindowFlag>("setWindowFlag").create();
  // void overrideWindowFlags(Qt::WindowFlags);
  /// TODO: void overrideWindowFlags(Qt::WindowFlags);
  // Qt::WindowType windowType() const;
  binder.fun<Qt::WindowType, &QWidget::windowType>("windowType").create();
  // static QWidget * find(WId);
  /// TODO: static QWidget * find(WId);
  // QWidget * childAt(int, int) const;
  binder.fun<QWidget *, int, int, &QWidget::childAt>("childAt").create();
  // QWidget * childAt(const QPoint &) const;
  binder.fun<QWidget *, const QPoint &, &QWidget::childAt>("childAt").create();
  // void setAttribute(Qt::WidgetAttribute, bool);
  binder.void_fun<Qt::WidgetAttribute, bool, &QWidget::setAttribute>("setAttribute").create();
  // bool testAttribute(Qt::WidgetAttribute) const;
  binder.fun<bool, Qt::WidgetAttribute, &QWidget::testAttribute>("testAttribute").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // void ensurePolished() const;
  binder.const_void_fun<&QWidget::ensurePolished>("ensurePolished").create();
  // bool isAncestorOf(const QWidget *) const;
  binder.fun<bool, const QWidget *, &QWidget::isAncestorOf>("isAncestorOf").create();
  // bool autoFillBackground() const;
  binder.fun<bool, &QWidget::autoFillBackground>("autoFillBackground").create();
  // void setAutoFillBackground(bool);
  binder.void_fun<bool, &QWidget::setAutoFillBackground>("setAutoFillBackground").create();
  // QBackingStore * backingStore() const;
  /// TODO: QBackingStore * backingStore() const;
  // QWindow * windowHandle() const;
  binder.fun<QWindow *, &QWidget::windowHandle>("windowHandle").create();
  // static QWidget * createWindowContainer(QWindow *, QWidget *, Qt::WindowFlags);
  /// TODO: static QWidget * createWindowContainer(QWindow *, QWidget *, Qt::WindowFlags);
  // void windowTitleChanged(const QString &);
  binder.sigs().add<const QString &>("windowTitleChanged", "windowTitleChanged(const QString &)");
  // void windowIconChanged(const QIcon &);
  binder.sigs().add<const QIcon &>("windowIconChanged", "windowIconChanged(const QIcon &)");
  // void windowIconTextChanged(const QString &);
  binder.sigs().add<const QString &>("windowIconTextChanged", "windowIconTextChanged(const QString &)");
  // void customContextMenuRequested(const QPoint &);
  binder.sigs().add<const QPoint &>("customContextMenuRequested", "customContextMenuRequested(const QPoint &)");
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.fun<QVariant, Qt::InputMethodQuery, &QWidget::inputMethodQuery>("inputMethodQuery").create();
  // Qt::InputMethodHints inputMethodHints() const;
  /// TODO: Qt::InputMethodHints inputMethodHints() const;
  // void setInputMethodHints(Qt::InputMethodHints);
  /// TODO: void setInputMethodHints(Qt::InputMethodHints);

  widget.engine()->registerQtType(&QWidget::staticMetaObject, widget.id());
}


void register_widget_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_widget_class(ns);
  binding::Namespace binder{ ns };

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

