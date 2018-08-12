// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/widget.h"

#include "yasl/binding/qclass.h"
#include "yasl/core/size.h"
#include "yasl/utils/ref.h"

#include "yasl/core/listspecializations.h"

#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/namespace.h>

void register_qwidget(script::Namespace n)
{
  using namespace script;

  Class qobject_class = n.engine()->getClass(script::Type::QObject);

  Class qwidget_class = n.Class("Widget").setId(Type::QWidget).setBase(qobject_class).get();
  Type widget_type = qwidget_class.id();

  register_ref_specialization(n.engine(), Type::QWidget, Type::QWidgetStar);
  register_ptr_specialization<QWidget*>(n.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQWidget);
  register_list_specialization<QWidget*>(n.engine(), Type::QListQWidget);

  auto widget = binding::QClass<QWidget>{ qwidget_class, &QWidget::staticMetaObject };
  widget.add_dtor();

  // QWidget * parentWidget() const
  widget.add_fun<QWidget*, &QWidget::parentWidget>("parentWidget");
  widget.add_void_fun<QWidget*, &QWidget::setParent>("setParent");

  /* Public member functions */

  // bool acceptDrops() const;
  widget.add_fun<bool, &QWidget::acceptDrops>("acceptDrops");
  // QString accessibleDescription() const;
  widget.add_fun<QString, &QWidget::accessibleDescription>("accessibleDescription");
  // QString accessibleName() const;
  widget.add_fun<QString, &QWidget::accessibleName>("accessibleName");
  // QList<QAction *> actions() const;
  // void activateWindow();
  widget.add_void_fun<&QWidget::activateWindow>("activateWindow");
  // void addAction(QAction *action);
  /// widget.add_void_fun<QAction*, &QWidget::addAction>("addAction");
  // void addActions(QList<QAction *> actions);
  // void adjustSize();
  widget.add_void_fun<&QWidget::adjustSize>("adjustSize");
  // bool autoFillBackground() const;
  widget.add_fun<bool, &QWidget::autoFillBackground>("autoFillBackground");
  // QPalette::ColorRole backgroundRole() const;
  // QBackingStore * backingStore() const;
  // QSize baseSize() const;
  widget.add_fun<QSize, &QWidget::baseSize>("baseSize");
  // QWidget * childAt(int x, int y) const;
  // QWidget * childAt(const QPoint &p) const;
  // QRect childrenRect() const;
  // QRegion childrenRegion() const;
  // void clearFocus();
  widget.add_void_fun<&QWidget::clearFocus>("clearFocus");
  // void clearMask();
  widget.add_void_fun<&QWidget::clearMask>("clearMask");
  // QMargins contentsMargins() const;
  // QRect contentsRect() const;
  // Qt::ContextMenuPolicy contextMenuPolicy() const;
  // QCursor cursor() const;
  // WId effectiveWinId() const;
  // void ensurePolished() const;
  ///widget.add_void_fun<&QWidget::ensurePolished>("ensurePolished");
  // Qt::FocusPolicy focusPolicy() const;
  // QWidget * focusProxy() const;
  // QWidget * focusWidget() const;
  // const QFont & font() const;
  // QFontInfo fontInfo() const;
  // QFontMetrics fontMetrics() const;
  // QPalette::ColorRole foregroundRole() const;
  // QRect frameGeometry() const;
  // QSize frameSize() const;
  widget.add_fun<QSize, &QWidget::baseSize>("baseSize");
  // const QRect & geometry() const;
  // void getContentsMargins(int *left, int *top, int *right, int *bottom) const;
  // QPixmap grab(const QRect &rectangle = QRect(QPoint(0, 0), QSize(-1, -1)));
  // void grabGesture(Qt::GestureType gesture, Qt::GestureFlags flags = ...);
  // void grabKeyboard();
  widget.add_void_fun<&QWidget::grabKeyboard>("grabKeyboard");
  // void grabMouse();
  widget.add_void_fun<&QWidget::grabMouse>("grabMouse");
  // void grabMouse(const QCursor &cursor);
  // int grabShortcut(const QKeySequence &key, Qt::ShortcutContext context = Qt::WindowShortcut);
  // QGraphicsEffect * graphicsEffect() const;
  // QGraphicsProxyWidget * graphicsProxyWidget() const;
  // bool hasEditFocus() const;
  ///widget.add_fun<bool, &QWidget::hasEditFocus>("hasEditFocus");
  // bool hasFocus() const;
  widget.add_fun<bool, &QWidget::hasFocus>("hasFocus");
  // virtual bool hasHeightForWidth() const;
  widget.add_fun<bool, &QWidget::hasHeightForWidth>("hasHeightForWidth");
  // bool hasMouseTracking() const;
  widget.add_fun<bool, &QWidget::hasMouseTracking>("hasMouseTracking");
  // bool hasTabletTracking() const;
  widget.add_fun<bool, &QWidget::hasTabletTracking>("hasTabletTracking");
  // int height() const;
  widget.add_fun<int, &QWidget::height>("height");
  // virtual int heightForWidth(int w) const;
  // Qt::InputMethodHints inputMethodHints() const;
  // virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const;
  // void insertAction(QAction *before, QAction *action);
  // void insertActions(QAction *before, QList<QAction *> actions);
  // bool isActiveWindow() const;
  widget.add_fun<bool, &QWidget::isActiveWindow>("isActiveWindow");
  // bool isAncestorOf(const QWidget *child) const;
  // bool isEnabled() const;
  widget.add_fun<bool, &QWidget::isEnabled>("isEnabled");
  // bool isEnabledTo(const QWidget *ancestor) const;
  // bool isFullScreen() const;
  widget.add_fun<bool, &QWidget::isFullScreen>("isFullScreen");
  // bool isHidden() const;
  widget.add_fun<bool, &QWidget::isHidden>("isHidden");
  // bool isMaximized() const;
  widget.add_fun<bool, &QWidget::isMaximized>("isMaximized");
  // bool isMinimized() const;
  widget.add_fun<bool, &QWidget::isMinimized>("isMinimized");
  // bool isModal() const;
  widget.add_fun<bool, &QWidget::isModal>("isModal");
  // bool isVisible() const;
  widget.add_fun<bool, &QWidget::isVisible>("isVisible");
  // bool isVisibleTo(const QWidget *ancestor) const;
  // bool isWindow() const;
  widget.add_fun<bool, &QWidget::isWindow>("isWindow");
  // bool isWindowModified() const;
  widget.add_fun<bool, &QWidget::isWindowModified>("isWindowModified");
  // QLayout * layout() const;
  // Qt::LayoutDirection layoutDirection() const;
  // QLocale locale() const;
  // QPoint mapFrom(const QWidget *parent, const QPoint &pos) const;
  // QPoint mapFromGlobal(const QPoint &pos) const;
  // QPoint mapFromParent(const QPoint &pos) const;
  // QPoint mapTo(const QWidget *parent, const QPoint &pos) const;
  // QPoint mapToGlobal(const QPoint &pos) const;
  // QPoint mapToParent(const QPoint &pos) const;
  // QRegion mask() const;
  // int maximumHeight() const;
  widget.add_fun<int, &QWidget::maximumHeight>("maximumHeight");
  // QSize maximumSize() const;
  widget.add_fun<QSize, &QWidget::maximumSize>("maximumSize");
  // int maximumWidth() const;
  widget.add_fun<int, &QWidget::maximumWidth>("maximumWidth");
  // int minimumHeight() const;
  widget.add_fun<int, &QWidget::minimumHeight>("minimumHeight");
  // QSize minimumSize() const;
  widget.add_fun<QSize, &QWidget::minimumSize>("minimumSize");
  // virtual QSize minimumSizeHint() const;
  // int minimumWidth() const;
  widget.add_fun<int, &QWidget::minimumWidth>("minimumWidth");
  // void move(const QPoint &);
  // void move(int x, int y);
  // QWidget * nativeParentWidget() const;
  // QWidget * nextInFocusChain() const;
  // QRect normalGeometry() const;
  // void overrideWindowFlags(Qt::WindowFlags flags);
  // const QPalette & palette() const;
  // QWidget * parentWidget() const;
  // QPoint pos() const;
  // QWidget * previousInFocusChain() const;
  // QRect rect() const;
  // void releaseKeyboard();
  widget.add_void_fun<&QWidget::releaseKeyboard>("releaseKeyboard");
  // void releaseMouse();
  widget.add_void_fun<&QWidget::releaseMouse>("releaseMouse");
  // void releaseShortcut(int id);
  // void removeAction(QAction *action);
  // void render(QPaintDevice *target, const QPoint &targetOffset = QPoint(), const QRegion &sourceRegion = QRegion(), QWidget::RenderFlags renderFlags = ...);
  // void render(QPainter *painter, const QPoint &targetOffset = QPoint(), const QRegion &sourceRegion = QRegion(), QWidget::RenderFlags renderFlags = ...);
  // void repaint(int x, int y, int w, int h);
  widget.add_void_fun<int, int, int, int, &QWidget::repaint>("repaint");
  // void repaint(const QRect &rect);
  // void repaint(const QRegion &rgn);
  // void resize(const QSize &);
  widget.add_void_fun<const QSize &, &QWidget::resize>("resize");
  // void resize(int w, int h);
  widget.add_void_fun<int, int, &QWidget::resize>("resize");
  // bool restoreGeometry(const QByteArray &geometry);
  // QByteArray saveGeometry() const;
  // void scroll(int dx, int dy);
  // void scroll(int dx, int dy, const QRect &r);
  // void setAcceptDrops(bool on);
  // void setAccessibleDescription(const QString &description);
  // void setAccessibleName(const QString &name);
  // void setAttribute(Qt::WidgetAttribute attribute, bool on = true);
  // void setAutoFillBackground(bool enabled);
  // void setBackgroundRole(QPalette::ColorRole role);
  // void setBaseSize(const QSize &);
  // void setBaseSize(int basew, int baseh);
  // void setContentsMargins(int left, int top, int right, int bottom);
  // void setContentsMargins(const QMargins &margins);
  // void setContextMenuPolicy(Qt::ContextMenuPolicy policy);
  // void setCursor(const QCursor &);
  // void setEditFocus(bool enable);
  // void setFixedHeight(int h);
  // void setFixedSize(const QSize &s);
  // void setFixedSize(int w, int h);
  // void setFixedWidth(int w);
  // void setFocus(Qt::FocusReason reason);
  // void setFocusPolicy(Qt::FocusPolicy policy);
  // void setFocusProxy(QWidget *w);
  // void setFont(const QFont &);
  // void setForegroundRole(QPalette::ColorRole role);
  // void setGeometry(const QRect &);
  // void setGeometry(int x, int y, int w, int h);
  // void setGraphicsEffect(QGraphicsEffect *effect);
  // void setInputMethodHints(Qt::InputMethodHints hints);
  // void setLayout(QLayout *layout);
  // void setLayoutDirection(Qt::LayoutDirection direction);
  // void setLocale(const QLocale &locale);
  // void setMask(const QBitmap &bitmap);
  // void setMask(const QRegion &region);
  // void setMaximumHeight(int maxh);
  // void setMaximumSize(const QSize &);
  // void setMaximumSize(int maxw, int maxh);
  // void setMaximumWidth(int maxw);
  // void setMinimumHeight(int minh);
  // void setMinimumSize(const QSize &);
  // void setMinimumSize(int minw, int minh);
  // void setMinimumWidth(int minw);
  // void setMouseTracking(bool enable);
  // void setPalette(const QPalette &);
  // void setParent(QWidget *parent);
  // void setParent(QWidget *parent, Qt::WindowFlags f);
  // void setShortcutAutoRepeat(int id, bool enable = true);
  // void setShortcutEnabled(int id, bool enable = true);
  // void setSizeIncrement(const QSize &);
  // void setSizeIncrement(int w, int h);
  // void setSizePolicy(QSizePolicy);
  // void setSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical);
  // void setStatusTip(const QString &);
  // void setStyle(QStyle *style);
  // void setTabletTracking(bool enable);
  // void setToolTip(const QString &);
  // void setToolTipDuration(int msec);
  // void setUpdatesEnabled(bool enable);
  // void setWhatsThis(const QString &);
  // void setWindowFilePath(const QString &filePath);
  // void setWindowFlag(Qt::WindowType flag, bool on = true);
  // void setWindowFlags(Qt::WindowFlags type);
  // void setWindowIcon(const QIcon &icon);
  // void setWindowModality(Qt::WindowModality windowModality);
  // void setWindowOpacity(qreal level);
  // void setWindowRole(const QString &role);
  // void setWindowState(Qt::WindowStates windowState);
  // void setupUi(QWidget *widget);
  // QSize size() const;
  widget.add_fun<QSize, &QWidget::size>("size");
  // virtual QSize sizeHint() const;
  widget.add_fun<QSize, &QWidget::sizeHint>("sizeHint");
  // QSize sizeIncrement() const;
  widget.add_fun<QSize, &QWidget::sizeIncrement>("sizeIncrement");
  // QSizePolicy sizePolicy() const;
  // void stackUnder(QWidget *w);
  // QString statusTip() const;
  widget.add_fun<QString, &QWidget::statusTip>("statusTip");
  // QStyle * style() const;
  // QString styleSheet() const;
  widget.add_fun<QString, &QWidget::styleSheet>("styleSheet");
  // bool testAttribute(Qt::WidgetAttribute attribute) const;
  // QString toolTip() const;
  widget.add_fun<QString, &QWidget::toolTip>("toolTip");
  // int toolTipDuration() const;
  widget.add_fun<int, &QWidget::toolTipDuration>("toolTipDuration");
  // bool underMouse() const;
  widget.add_fun<bool, &QWidget::underMouse>("underMouse");
  // void ungrabGesture(Qt::GestureType gesture);
  // void unsetCursor();
  widget.add_void_fun<&QWidget::unsetCursor>("unsetCursor");
  // void unsetLayoutDirection();
  widget.add_void_fun<&QWidget::unsetLayoutDirection>("unsetLayoutDirection");
  // void unsetLocale();
  widget.add_void_fun<&QWidget::unsetLocale>("unsetLocale");
  // void update(int x, int y, int w, int h);
  widget.add_void_fun<int, int, int, int, &QWidget::update>("update");
  // void update(const QRect &rect);
  // void update(const QRegion &rgn);
  // void updateGeometry();
  widget.add_void_fun<&QWidget::updateGeometry>("updateGeometry");
  // bool updatesEnabled() const;
  widget.add_fun<bool, &QWidget::updatesEnabled>("updatesEnabled");
  // QRegion visibleRegion() const;
  // QString whatsThis() const;
  widget.add_fun<QString, &QWidget::whatsThis>("whatsThis");
  // int width() const;
  widget.add_fun<int, &QWidget::width>("width");
  // WId winId() const;
  // QWidget * window() const;
  // QString windowFilePath() const;
  widget.add_fun<QString, &QWidget::windowFilePath>("windowFilePath");
  // Qt::WindowFlags windowFlags() const;
  // QWindow * windowHandle() const;
  // QIcon windowIcon() const;
  // Qt::WindowModality windowModality() const;
  // qreal windowOpacity() const;
  // QString windowRole() const;
  widget.add_fun<QString, &QWidget::windowRole>("windowRole");
  // Qt::WindowStates windowState() const;
  // QString windowTitle() const;
  widget.add_fun<QString, &QWidget::windowTitle>("windowTitle");
  // Qt::WindowType windowType() const;
  // int x() const;
  widget.add_fun<int, &QWidget::x>("x");
  // int y() const;
  widget.add_fun<int, &QWidget::y>("y");

  /* Slots */

  // void close();
  widget.add_fun<bool, &QWidget::close>("close");
  // void hide();
  widget.add_void_fun<&QWidget::hide>("hide");
  // void lower();
  widget.add_void_fun<&QWidget::lower>("lower");
  // void raise();
  widget.add_void_fun<&QWidget::raise>("raise");
  // void repaint();
  widget.add_void_fun<&QWidget::repaint>("repaint");
  // void setDisabled(bool disable);
  widget.add_void_fun<bool, &QWidget::setDisabled>("setDisabled");
  // void setEnabled(bool);
  widget.add_void_fun<bool, &QWidget::setEnabled>("setEnabled");
  // void setFocus();
  widget.add_void_fun<&QWidget::setFocus>("setFocus");
  // void setHidden(bool hidden);
  widget.add_void_fun<bool, &QWidget::setHidden>("setHidden");
  // void setStyleSheet(const QString &styleSheet);
  widget.add_void_fun<const QString &, &QWidget::setStyleSheet>("setStyleSheet");
  // virtual void setVisible(bool visible);
  widget.add_void_fun<bool, &QWidget::setVisible>("setVisible");
  // void setWindowModified(bool);
  widget.add_void_fun<bool, &QWidget::setWindowModified>("setWindowModified");
  // void setWindowTitle(const QString &);
  widget.add_void_fun<const QString &, &QWidget::setWindowTitle>("setWindowTitle");
  // void show();
  widget.add_void_fun<&QWidget::show>("show");
  // void showFullScreen();
  widget.add_void_fun<&QWidget::showFullScreen>("showFullScreen");
  // void showMaximized();
  widget.add_void_fun<&QWidget::showMaximized>("showMaximized");
  // void showMinimized();
  widget.add_void_fun<&QWidget::showMinimized>("showMinimized");
  // void showNormal();
  widget.add_void_fun<&QWidget::showNormal>("showNormal");
  // void update();
  widget.add_void_fun<&QWidget::update>("update");

  /* Signals */
  // void customContextMenuRequested(const QPoint &pos);
  //widget.sigs().add<const QPoint &>("customContextMenuRequested", Q_SIGNAL("customContextMenuRequested(const QPoint &)"));
  // void windowIconChanged(const QIcon &icon);
  //widget.sigs().add<const QIcon &>("windowIconChanged", Q_SIGNAL("windowIconChanged(const QIcon &)"));
  // void windowTitleChanged(const QString &title);
  widget.sigs().add<const QString &>("windowTitleChanged", "windowTitleChanged(const QString &)");

  n.engine()->registerQtType(&QWidget::staticMetaObject, widget_type);
}

script::Value make_widget(QWidget *widget, script::Engine *e)
{
  return make_ref(e, script::Type::QWidgetStar, widget);
}
