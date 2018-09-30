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
  binder.add_fun<int, &QWidget::devType>("devType");
  // WId winId() const;
  /// TODO: WId winId() const;
  // void createWinId();
  binder.add_void_fun<&QWidget::createWinId>("createWinId");
  // WId internalWinId() const;
  /// TODO: WId internalWinId() const;
  // WId effectiveWinId() const;
  /// TODO: WId effectiveWinId() const;
  // QStyle * style() const;
  /// TODO: QStyle * style() const;
  // void setStyle(QStyle *);
  /// TODO: void setStyle(QStyle *);
  // bool isTopLevel() const;
  binder.add_fun<bool, &QWidget::isTopLevel>("isTopLevel");
  // bool isWindow() const;
  binder.add_fun<bool, &QWidget::isWindow>("isWindow");
  // bool isModal() const;
  binder.add_fun<bool, &QWidget::isModal>("isModal");
  // Qt::WindowModality windowModality() const;
  binder.add_fun<Qt::WindowModality, &QWidget::windowModality>("windowModality");
  // void setWindowModality(Qt::WindowModality);
  binder.add_void_fun<Qt::WindowModality, &QWidget::setWindowModality>("setWindowModality");
  // bool isEnabled() const;
  binder.add_fun<bool, &QWidget::isEnabled>("isEnabled");
  // bool isEnabledTo(const QWidget *) const;
  binder.add_fun<bool, const QWidget *, &QWidget::isEnabledTo>("isEnabledTo");
  // bool isEnabledToTLW() const;
  binder.add_fun<bool, &QWidget::isEnabledToTLW>("isEnabledToTLW");
  // void setEnabled(bool);
  binder.add_void_fun<bool, &QWidget::setEnabled>("setEnabled");
  // void setDisabled(bool);
  binder.add_void_fun<bool, &QWidget::setDisabled>("setDisabled");
  // void setWindowModified(bool);
  binder.add_void_fun<bool, &QWidget::setWindowModified>("setWindowModified");
  // QRect frameGeometry() const;
  binder.add_fun<QRect, &QWidget::frameGeometry>("frameGeometry");
  // const QRect & geometry() const;
  binder.add_fun<const QRect &, &QWidget::geometry>("geometry");
  // QRect normalGeometry() const;
  binder.add_fun<QRect, &QWidget::normalGeometry>("normalGeometry");
  // int x() const;
  binder.add_fun<int, &QWidget::x>("x");
  // int y() const;
  binder.add_fun<int, &QWidget::y>("y");
  // QPoint pos() const;
  binder.add_fun<QPoint, &QWidget::pos>("pos");
  // QSize frameSize() const;
  binder.add_fun<QSize, &QWidget::frameSize>("frameSize");
  // QSize size() const;
  binder.add_fun<QSize, &QWidget::size>("size");
  // int width() const;
  binder.add_fun<int, &QWidget::width>("width");
  // int height() const;
  binder.add_fun<int, &QWidget::height>("height");
  // QRect rect() const;
  binder.add_fun<QRect, &QWidget::rect>("rect");
  // QRect childrenRect() const;
  binder.add_fun<QRect, &QWidget::childrenRect>("childrenRect");
  // QRegion childrenRegion() const;
  binder.add_fun<QRegion, &QWidget::childrenRegion>("childrenRegion");
  // QSize minimumSize() const;
  binder.add_fun<QSize, &QWidget::minimumSize>("minimumSize");
  // QSize maximumSize() const;
  binder.add_fun<QSize, &QWidget::maximumSize>("maximumSize");
  // int minimumWidth() const;
  binder.add_fun<int, &QWidget::minimumWidth>("minimumWidth");
  // int minimumHeight() const;
  binder.add_fun<int, &QWidget::minimumHeight>("minimumHeight");
  // int maximumWidth() const;
  binder.add_fun<int, &QWidget::maximumWidth>("maximumWidth");
  // int maximumHeight() const;
  binder.add_fun<int, &QWidget::maximumHeight>("maximumHeight");
  // void setMinimumSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::setMinimumSize>("setMinimumSize");
  // void setMinimumSize(int, int);
  binder.add_void_fun<int, int, &QWidget::setMinimumSize>("setMinimumSize");
  // void setMaximumSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::setMaximumSize>("setMaximumSize");
  // void setMaximumSize(int, int);
  binder.add_void_fun<int, int, &QWidget::setMaximumSize>("setMaximumSize");
  // void setMinimumWidth(int);
  binder.add_void_fun<int, &QWidget::setMinimumWidth>("setMinimumWidth");
  // void setMinimumHeight(int);
  binder.add_void_fun<int, &QWidget::setMinimumHeight>("setMinimumHeight");
  // void setMaximumWidth(int);
  binder.add_void_fun<int, &QWidget::setMaximumWidth>("setMaximumWidth");
  // void setMaximumHeight(int);
  binder.add_void_fun<int, &QWidget::setMaximumHeight>("setMaximumHeight");
  // QSize sizeIncrement() const;
  binder.add_fun<QSize, &QWidget::sizeIncrement>("sizeIncrement");
  // void setSizeIncrement(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::setSizeIncrement>("setSizeIncrement");
  // void setSizeIncrement(int, int);
  binder.add_void_fun<int, int, &QWidget::setSizeIncrement>("setSizeIncrement");
  // QSize baseSize() const;
  binder.add_fun<QSize, &QWidget::baseSize>("baseSize");
  // void setBaseSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::setBaseSize>("setBaseSize");
  // void setBaseSize(int, int);
  binder.add_void_fun<int, int, &QWidget::setBaseSize>("setBaseSize");
  // void setFixedSize(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::setFixedSize>("setFixedSize");
  // void setFixedSize(int, int);
  binder.add_void_fun<int, int, &QWidget::setFixedSize>("setFixedSize");
  // void setFixedWidth(int);
  binder.add_void_fun<int, &QWidget::setFixedWidth>("setFixedWidth");
  // void setFixedHeight(int);
  binder.add_void_fun<int, &QWidget::setFixedHeight>("setFixedHeight");
  // QPoint mapToGlobal(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWidget::mapToGlobal>("mapToGlobal");
  // QPoint mapFromGlobal(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWidget::mapFromGlobal>("mapFromGlobal");
  // QPoint mapToParent(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWidget::mapToParent>("mapToParent");
  // QPoint mapFromParent(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QWidget::mapFromParent>("mapFromParent");
  // QPoint mapTo(const QWidget *, const QPoint &) const;
  binder.add_fun<QPoint, const QWidget *, const QPoint &, &QWidget::mapTo>("mapTo");
  // QPoint mapFrom(const QWidget *, const QPoint &) const;
  binder.add_fun<QPoint, const QWidget *, const QPoint &, &QWidget::mapFrom>("mapFrom");
  // QWidget * window() const;
  binder.add_fun<QWidget *, &QWidget::window>("window");
  // QWidget * nativeParentWidget() const;
  binder.add_fun<QWidget *, &QWidget::nativeParentWidget>("nativeParentWidget");
  // QWidget * topLevelWidget() const;
  binder.add_fun<QWidget *, &QWidget::topLevelWidget>("topLevelWidget");
  // const QPalette & palette() const;
  binder.add_fun<const QPalette &, &QWidget::palette>("palette");
  // void setPalette(const QPalette &);
  binder.add_void_fun<const QPalette &, &QWidget::setPalette>("setPalette");
  // void setBackgroundRole(QPalette::ColorRole);
  binder.add_void_fun<QPalette::ColorRole, &QWidget::setBackgroundRole>("setBackgroundRole");
  // QPalette::ColorRole backgroundRole() const;
  binder.add_fun<QPalette::ColorRole, &QWidget::backgroundRole>("backgroundRole");
  // void setForegroundRole(QPalette::ColorRole);
  binder.add_void_fun<QPalette::ColorRole, &QWidget::setForegroundRole>("setForegroundRole");
  // QPalette::ColorRole foregroundRole() const;
  binder.add_fun<QPalette::ColorRole, &QWidget::foregroundRole>("foregroundRole");
  // const QFont & font() const;
  binder.add_fun<const QFont &, &QWidget::font>("font");
  // void setFont(const QFont &);
  binder.add_void_fun<const QFont &, &QWidget::setFont>("setFont");
  // QFontMetrics fontMetrics() const;
  binder.add_fun<QFontMetrics, &QWidget::fontMetrics>("fontMetrics");
  // QFontInfo fontInfo() const;
  binder.add_fun<QFontInfo, &QWidget::fontInfo>("fontInfo");
  // QCursor cursor() const;
  binder.add_fun<QCursor, &QWidget::cursor>("cursor");
  // void setCursor(const QCursor &);
  binder.add_void_fun<const QCursor &, &QWidget::setCursor>("setCursor");
  // void unsetCursor();
  binder.add_void_fun<&QWidget::unsetCursor>("unsetCursor");
  // void setMouseTracking(bool);
  binder.add_void_fun<bool, &QWidget::setMouseTracking>("setMouseTracking");
  // bool hasMouseTracking() const;
  binder.add_fun<bool, &QWidget::hasMouseTracking>("hasMouseTracking");
  // bool underMouse() const;
  binder.add_fun<bool, &QWidget::underMouse>("underMouse");
  // void setTabletTracking(bool);
  binder.add_void_fun<bool, &QWidget::setTabletTracking>("setTabletTracking");
  // bool hasTabletTracking() const;
  binder.add_fun<bool, &QWidget::hasTabletTracking>("hasTabletTracking");
  // void setMask(const QBitmap &);
  binder.add_void_fun<const QBitmap &, &QWidget::setMask>("setMask");
  // void setMask(const QRegion &);
  binder.add_void_fun<const QRegion &, &QWidget::setMask>("setMask");
  // QRegion mask() const;
  binder.add_fun<QRegion, &QWidget::mask>("mask");
  // void clearMask();
  binder.add_void_fun<&QWidget::clearMask>("clearMask");
  // void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  /// TODO: void render(QPaintDevice *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  // void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  /// TODO: void render(QPainter *, const QPoint &, const QRegion &, QWidget::RenderFlags);
  // QPixmap grab(const QRect &);
  binder.add_fun<QPixmap, const QRect &, &QWidget::grab>("grab");
  // QGraphicsEffect * graphicsEffect() const;
  /// TODO: QGraphicsEffect * graphicsEffect() const;
  // void setGraphicsEffect(QGraphicsEffect *);
  /// TODO: void setGraphicsEffect(QGraphicsEffect *);
  // void grabGesture(Qt::GestureType, Qt::GestureFlags);
  /// TODO: void grabGesture(Qt::GestureType, Qt::GestureFlags);
  // void ungrabGesture(Qt::GestureType);
  binder.add_void_fun<Qt::GestureType, &QWidget::ungrabGesture>("ungrabGesture");
  // void setWindowTitle(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setWindowTitle>("setWindowTitle");
  // void setStyleSheet(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setStyleSheet>("setStyleSheet");
  // QString styleSheet() const;
  binder.add_fun<QString, &QWidget::styleSheet>("styleSheet");
  // QString windowTitle() const;
  binder.add_fun<QString, &QWidget::windowTitle>("windowTitle");
  // void setWindowIcon(const QIcon &);
  binder.add_void_fun<const QIcon &, &QWidget::setWindowIcon>("setWindowIcon");
  // QIcon windowIcon() const;
  binder.add_fun<QIcon, &QWidget::windowIcon>("windowIcon");
  // void setWindowIconText(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setWindowIconText>("setWindowIconText");
  // QString windowIconText() const;
  binder.add_fun<QString, &QWidget::windowIconText>("windowIconText");
  // void setWindowRole(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setWindowRole>("setWindowRole");
  // QString windowRole() const;
  binder.add_fun<QString, &QWidget::windowRole>("windowRole");
  // void setWindowFilePath(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setWindowFilePath>("setWindowFilePath");
  // QString windowFilePath() const;
  binder.add_fun<QString, &QWidget::windowFilePath>("windowFilePath");
  // void setWindowOpacity(qreal);
  binder.add_void_fun<qreal, &QWidget::setWindowOpacity>("setWindowOpacity");
  // qreal windowOpacity() const;
  binder.add_fun<qreal, &QWidget::windowOpacity>("windowOpacity");
  // bool isWindowModified() const;
  binder.add_fun<bool, &QWidget::isWindowModified>("isWindowModified");
  // void setToolTip(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setToolTip>("setToolTip");
  // QString toolTip() const;
  binder.add_fun<QString, &QWidget::toolTip>("toolTip");
  // void setToolTipDuration(int);
  binder.add_void_fun<int, &QWidget::setToolTipDuration>("setToolTipDuration");
  // int toolTipDuration() const;
  binder.add_fun<int, &QWidget::toolTipDuration>("toolTipDuration");
  // void setStatusTip(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setStatusTip>("setStatusTip");
  // QString statusTip() const;
  binder.add_fun<QString, &QWidget::statusTip>("statusTip");
  // void setWhatsThis(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setWhatsThis>("setWhatsThis");
  // QString whatsThis() const;
  binder.add_fun<QString, &QWidget::whatsThis>("whatsThis");
  // QString accessibleName() const;
  binder.add_fun<QString, &QWidget::accessibleName>("accessibleName");
  // void setAccessibleName(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setAccessibleName>("setAccessibleName");
  // QString accessibleDescription() const;
  binder.add_fun<QString, &QWidget::accessibleDescription>("accessibleDescription");
  // void setAccessibleDescription(const QString &);
  binder.add_void_fun<const QString &, &QWidget::setAccessibleDescription>("setAccessibleDescription");
  // void setLayoutDirection(Qt::LayoutDirection);
  binder.add_void_fun<Qt::LayoutDirection, &QWidget::setLayoutDirection>("setLayoutDirection");
  // Qt::LayoutDirection layoutDirection() const;
  binder.add_fun<Qt::LayoutDirection, &QWidget::layoutDirection>("layoutDirection");
  // void unsetLayoutDirection();
  binder.add_void_fun<&QWidget::unsetLayoutDirection>("unsetLayoutDirection");
  // void setLocale(const QLocale &);
  binder.add_void_fun<const QLocale &, &QWidget::setLocale>("setLocale");
  // QLocale locale() const;
  binder.add_fun<QLocale, &QWidget::locale>("locale");
  // void unsetLocale();
  binder.add_void_fun<&QWidget::unsetLocale>("unsetLocale");
  // bool isRightToLeft() const;
  binder.add_fun<bool, &QWidget::isRightToLeft>("isRightToLeft");
  // bool isLeftToRight() const;
  binder.add_fun<bool, &QWidget::isLeftToRight>("isLeftToRight");
  // void setFocus();
  binder.add_void_fun<&QWidget::setFocus>("setFocus");
  // bool isActiveWindow() const;
  binder.add_fun<bool, &QWidget::isActiveWindow>("isActiveWindow");
  // void activateWindow();
  binder.add_void_fun<&QWidget::activateWindow>("activateWindow");
  // void clearFocus();
  binder.add_void_fun<&QWidget::clearFocus>("clearFocus");
  // void setFocus(Qt::FocusReason);
  binder.add_void_fun<Qt::FocusReason, &QWidget::setFocus>("setFocus");
  // Qt::FocusPolicy focusPolicy() const;
  binder.add_fun<Qt::FocusPolicy, &QWidget::focusPolicy>("focusPolicy");
  // void setFocusPolicy(Qt::FocusPolicy);
  binder.add_void_fun<Qt::FocusPolicy, &QWidget::setFocusPolicy>("setFocusPolicy");
  // bool hasFocus() const;
  binder.add_fun<bool, &QWidget::hasFocus>("hasFocus");
  // static void setTabOrder(QWidget *, QWidget *);
  binder.add_static_void_fun<QWidget *, QWidget *, &QWidget::setTabOrder>("setTabOrder");
  // void setFocusProxy(QWidget *);
  binder.add_void_fun<QWidget *, &QWidget::setFocusProxy>("setFocusProxy");
  // QWidget * focusProxy() const;
  binder.add_fun<QWidget *, &QWidget::focusProxy>("focusProxy");
  // Qt::ContextMenuPolicy contextMenuPolicy() const;
  binder.add_fun<Qt::ContextMenuPolicy, &QWidget::contextMenuPolicy>("contextMenuPolicy");
  // void setContextMenuPolicy(Qt::ContextMenuPolicy);
  binder.add_void_fun<Qt::ContextMenuPolicy, &QWidget::setContextMenuPolicy>("setContextMenuPolicy");
  // void grabMouse();
  binder.add_void_fun<&QWidget::grabMouse>("grabMouse");
  // void grabMouse(const QCursor &);
  binder.add_void_fun<const QCursor &, &QWidget::grabMouse>("grabMouse");
  // void releaseMouse();
  binder.add_void_fun<&QWidget::releaseMouse>("releaseMouse");
  // void grabKeyboard();
  binder.add_void_fun<&QWidget::grabKeyboard>("grabKeyboard");
  // void releaseKeyboard();
  binder.add_void_fun<&QWidget::releaseKeyboard>("releaseKeyboard");
  // int grabShortcut(const QKeySequence &, Qt::ShortcutContext);
  binder.add_fun<int, const QKeySequence &, Qt::ShortcutContext, &QWidget::grabShortcut>("grabShortcut");
  // void releaseShortcut(int);
  binder.add_void_fun<int, &QWidget::releaseShortcut>("releaseShortcut");
  // void setShortcutEnabled(int, bool);
  binder.add_void_fun<int, bool, &QWidget::setShortcutEnabled>("setShortcutEnabled");
  // void setShortcutAutoRepeat(int, bool);
  binder.add_void_fun<int, bool, &QWidget::setShortcutAutoRepeat>("setShortcutAutoRepeat");
  // static QWidget * mouseGrabber();
  binder.add_static<QWidget *, &QWidget::mouseGrabber>("mouseGrabber");
  // static QWidget * keyboardGrabber();
  binder.add_static<QWidget *, &QWidget::keyboardGrabber>("keyboardGrabber");
  // bool updatesEnabled() const;
  binder.add_fun<bool, &QWidget::updatesEnabled>("updatesEnabled");
  // void setUpdatesEnabled(bool);
  binder.add_void_fun<bool, &QWidget::setUpdatesEnabled>("setUpdatesEnabled");
  // QGraphicsProxyWidget * graphicsProxyWidget() const;
  /// TODO: QGraphicsProxyWidget * graphicsProxyWidget() const;
  // void update();
  binder.add_void_fun<&QWidget::update>("update");
  // void repaint();
  binder.add_void_fun<&QWidget::repaint>("repaint");
  // void update(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QWidget::update>("update");
  // void update(const QRect &);
  binder.add_void_fun<const QRect &, &QWidget::update>("update");
  // void update(const QRegion &);
  binder.add_void_fun<const QRegion &, &QWidget::update>("update");
  // void repaint(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QWidget::repaint>("repaint");
  // void repaint(const QRect &);
  binder.add_void_fun<const QRect &, &QWidget::repaint>("repaint");
  // void repaint(const QRegion &);
  binder.add_void_fun<const QRegion &, &QWidget::repaint>("repaint");
  // void setVisible(bool);
  binder.add_void_fun<bool, &QWidget::setVisible>("setVisible");
  // void setHidden(bool);
  binder.add_void_fun<bool, &QWidget::setHidden>("setHidden");
  // void show();
  binder.add_void_fun<&QWidget::show>("show");
  // void hide();
  binder.add_void_fun<&QWidget::hide>("hide");
  // void showMinimized();
  binder.add_void_fun<&QWidget::showMinimized>("showMinimized");
  // void showMaximized();
  binder.add_void_fun<&QWidget::showMaximized>("showMaximized");
  // void showFullScreen();
  binder.add_void_fun<&QWidget::showFullScreen>("showFullScreen");
  // void showNormal();
  binder.add_void_fun<&QWidget::showNormal>("showNormal");
  // bool close();
  binder.add_fun<bool, &QWidget::close>("close");
  // void raise();
  binder.add_void_fun<&QWidget::raise>("raise");
  // void lower();
  binder.add_void_fun<&QWidget::lower>("lower");
  // void stackUnder(QWidget *);
  binder.add_void_fun<QWidget *, &QWidget::stackUnder>("stackUnder");
  // void move(int, int);
  binder.add_void_fun<int, int, &QWidget::move>("move");
  // void move(const QPoint &);
  binder.add_void_fun<const QPoint &, &QWidget::move>("move");
  // void resize(int, int);
  binder.add_void_fun<int, int, &QWidget::resize>("resize");
  // void resize(const QSize &);
  binder.add_void_fun<const QSize &, &QWidget::resize>("resize");
  // void setGeometry(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QWidget::setGeometry>("setGeometry");
  // void setGeometry(const QRect &);
  binder.add_void_fun<const QRect &, &QWidget::setGeometry>("setGeometry");
  // QByteArray saveGeometry() const;
  binder.add_fun<QByteArray, &QWidget::saveGeometry>("saveGeometry");
  // bool restoreGeometry(const QByteArray &);
  binder.add_fun<bool, const QByteArray &, &QWidget::restoreGeometry>("restoreGeometry");
  // void adjustSize();
  binder.add_void_fun<&QWidget::adjustSize>("adjustSize");
  // bool isVisible() const;
  binder.add_fun<bool, &QWidget::isVisible>("isVisible");
  // bool isVisibleTo(const QWidget *) const;
  binder.add_fun<bool, const QWidget *, &QWidget::isVisibleTo>("isVisibleTo");
  // bool isHidden() const;
  binder.add_fun<bool, &QWidget::isHidden>("isHidden");
  // bool isMinimized() const;
  binder.add_fun<bool, &QWidget::isMinimized>("isMinimized");
  // bool isMaximized() const;
  binder.add_fun<bool, &QWidget::isMaximized>("isMaximized");
  // bool isFullScreen() const;
  binder.add_fun<bool, &QWidget::isFullScreen>("isFullScreen");
  // Qt::WindowStates windowState() const;
  /// TODO: Qt::WindowStates windowState() const;
  // void setWindowState(Qt::WindowStates);
  /// TODO: void setWindowState(Qt::WindowStates);
  // void overrideWindowState(Qt::WindowStates);
  /// TODO: void overrideWindowState(Qt::WindowStates);
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QWidget::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QWidget::minimumSizeHint>("minimumSizeHint");
  // QSizePolicy sizePolicy() const;
  /// TODO: QSizePolicy sizePolicy() const;
  // void setSizePolicy(QSizePolicy);
  /// TODO: void setSizePolicy(QSizePolicy);
  // void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  /// TODO: void setSizePolicy(QSizePolicy::Policy, QSizePolicy::Policy);
  // int heightForWidth(int) const;
  binder.add_fun<int, int, &QWidget::heightForWidth>("heightForWidth");
  // bool hasHeightForWidth() const;
  binder.add_fun<bool, &QWidget::hasHeightForWidth>("hasHeightForWidth");
  // QRegion visibleRegion() const;
  binder.add_fun<QRegion, &QWidget::visibleRegion>("visibleRegion");
  // void setContentsMargins(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QWidget::setContentsMargins>("setContentsMargins");
  // void setContentsMargins(const QMargins &);
  binder.add_void_fun<const QMargins &, &QWidget::setContentsMargins>("setContentsMargins");
  // void getContentsMargins(int *, int *, int *, int *) const;
  /// TODO: void getContentsMargins(int *, int *, int *, int *) const;
  // QMargins contentsMargins() const;
  binder.add_fun<QMargins, &QWidget::contentsMargins>("contentsMargins");
  // QRect contentsRect() const;
  binder.add_fun<QRect, &QWidget::contentsRect>("contentsRect");
  // QLayout * layout() const;
  binder.add_fun<QLayout *, &QWidget::layout>("layout");
  // void setLayout(QLayout *);
  binder.add_void_fun<QLayout *, &QWidget::setLayout>("setLayout");
  // void updateGeometry();
  binder.add_void_fun<&QWidget::updateGeometry>("updateGeometry");
  // void setParent(QWidget *);
  binder.add_void_fun<QWidget *, &QWidget::setParent>("setParent");
  // void setParent(QWidget *, Qt::WindowFlags);
  /// TODO: void setParent(QWidget *, Qt::WindowFlags);
  // void scroll(int, int);
  binder.add_void_fun<int, int, &QWidget::scroll>("scroll");
  // void scroll(int, int, const QRect &);
  binder.add_void_fun<int, int, const QRect &, &QWidget::scroll>("scroll");
  // QWidget * focusWidget() const;
  binder.add_fun<QWidget *, &QWidget::focusWidget>("focusWidget");
  // QWidget * nextInFocusChain() const;
  binder.add_fun<QWidget *, &QWidget::nextInFocusChain>("nextInFocusChain");
  // QWidget * previousInFocusChain() const;
  binder.add_fun<QWidget *, &QWidget::previousInFocusChain>("previousInFocusChain");
  // bool acceptDrops() const;
  binder.add_fun<bool, &QWidget::acceptDrops>("acceptDrops");
  // void setAcceptDrops(bool);
  binder.add_void_fun<bool, &QWidget::setAcceptDrops>("setAcceptDrops");
  // void addAction(QAction *);
  binder.add_void_fun<QAction *, &QWidget::addAction>("addAction");
  // void addActions(QList<QAction *>);
  /// TODO: void addActions(QList<QAction *>);
  // void insertActions(QAction *, QList<QAction *>);
  /// TODO: void insertActions(QAction *, QList<QAction *>);
  // void insertAction(QAction *, QAction *);
  binder.add_void_fun<QAction *, QAction *, &QWidget::insertAction>("insertAction");
  // void removeAction(QAction *);
  binder.add_void_fun<QAction *, &QWidget::removeAction>("removeAction");
  // QList<QAction *> actions() const;
  /// TODO: QList<QAction *> actions() const;
  // QWidget * parentWidget() const;
  binder.add_fun<QWidget *, &QWidget::parentWidget>("parentWidget");
  // void setWindowFlags(Qt::WindowFlags);
  /// TODO: void setWindowFlags(Qt::WindowFlags);
  // Qt::WindowFlags windowFlags() const;
  /// TODO: Qt::WindowFlags windowFlags() const;
  // void setWindowFlag(Qt::WindowType, bool);
  binder.add_void_fun<Qt::WindowType, bool, &QWidget::setWindowFlag>("setWindowFlag");
  // void overrideWindowFlags(Qt::WindowFlags);
  /// TODO: void overrideWindowFlags(Qt::WindowFlags);
  // Qt::WindowType windowType() const;
  binder.add_fun<Qt::WindowType, &QWidget::windowType>("windowType");
  // static QWidget * find(WId);
  /// TODO: static QWidget * find(WId);
  // QWidget * childAt(int, int) const;
  binder.add_fun<QWidget *, int, int, &QWidget::childAt>("childAt");
  // QWidget * childAt(const QPoint &) const;
  binder.add_fun<QWidget *, const QPoint &, &QWidget::childAt>("childAt");
  // void setAttribute(Qt::WidgetAttribute, bool);
  binder.add_void_fun<Qt::WidgetAttribute, bool, &QWidget::setAttribute>("setAttribute");
  // bool testAttribute(Qt::WidgetAttribute) const;
  binder.add_fun<bool, Qt::WidgetAttribute, &QWidget::testAttribute>("testAttribute");
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // void ensurePolished() const;
  binder.add_const_void_fun<&QWidget::ensurePolished>("ensurePolished");
  // bool isAncestorOf(const QWidget *) const;
  binder.add_fun<bool, const QWidget *, &QWidget::isAncestorOf>("isAncestorOf");
  // bool autoFillBackground() const;
  binder.add_fun<bool, &QWidget::autoFillBackground>("autoFillBackground");
  // void setAutoFillBackground(bool);
  binder.add_void_fun<bool, &QWidget::setAutoFillBackground>("setAutoFillBackground");
  // QBackingStore * backingStore() const;
  /// TODO: QBackingStore * backingStore() const;
  // QWindow * windowHandle() const;
  binder.add_fun<QWindow *, &QWidget::windowHandle>("windowHandle");
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
  binder.add_fun<QVariant, Qt::InputMethodQuery, &QWidget::inputMethodQuery>("inputMethodQuery");
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

