// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/widget.h"

#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"
#include "yasl/core/size.h"
#include "yasl/gui/closeevent.h"
#include "yasl/gui/hideevent.h"
#include "yasl/gui/keyevent.h"
#include "yasl/gui/mouseevent.h"
#include "yasl/gui/moveevent.h"
#include "yasl/gui/paintevent.h"
#include "yasl/gui/resizeevent.h"
#include "yasl/gui/showevent.h"
#include "yasl/gui/wheelevent.h"
#include "yasl/utils/ref.h"

#include <script/classbuilder.h>
#include <script/classtemplate.h>
#include <script/conversions.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/interpreter/executioncontext.h>
#include <script/overloadresolution.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>
#include <script/userdata.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <QWidget>

void register_new_widget_template(script::Namespace n);

namespace callbacks
{

static script::Value widget_ctor(script::FunctionCall *c)
{
  script::Value self = c->thisObject();
  Widget *obj = new Widget();
  c->engine()->bind(self, obj);
  return self;
}

static script::Value new_widget(script::FunctionCall *c)
{
  using namespace script;
  Type widget_type = c->callee().returnType().baseType();
  Value v = c->engine()->construct(widget_type, {});
  return v;
}


static script::Value new_widget_window_title(script::FunctionCall *c)
{
  using namespace script;
  Type widget_type = c->callee().returnType().baseType();
  Value v = c->engine()->uninitialized(widget_type);
  QWidget *widget = new QWidget;
  widget->setWindowTitle(binding::value_cast<QString>(c->arg(0)));
  v.impl()->set_qobject(widget);
  c->engine()->bind(v, widget);
  v.impl()->type = v.impl()->type.withoutFlag(Type::UninitializedFlag);
  return v;
}

static script::Value close_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetCloseEvent(binding::value_cast<QCloseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value enter_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetEnterEvent(binding::value_cast<QEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value hide_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetHideEvent(binding::value_cast<QHideEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value key_press_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetKeyPressEvent(binding::value_cast<QKeyEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value key_release_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetKeyReleaseEvent(binding::value_cast<QKeyEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value leave_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetLeaveEvent(binding::value_cast<QEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_double_click_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseDoubleClickEvent(binding::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_move_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseMoveEvent(binding::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_press_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetMousePressEvent(binding::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value mouse_release_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetMouseReleaseEvent(binding::value_cast<QMouseEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value move_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetMoveEvent(binding::value_cast<QMoveEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value paint_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetPaintEvent(binding::value_cast<QPaintEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value resize_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetResizeEvent(binding::value_cast<QResizeEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value show_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetShowEvent(binding::value_cast<QShowEvent*>(c->arg(1)));
  return script::Value::Void;
}

static script::Value wheel_event(script::FunctionCall *c)
{
  Widget *self = binding::value_cast<Widget*>(c->arg(0));
  self->QWidgetWheelEvent(binding::value_cast<QWheelEvent*>(c->arg(1)));
  return script::Value::Void;
}

} // namespace callbacks

void register_qwidget(script::Namespace n)
{
  using namespace script;

  Class qobject_class = n.engine()->getClass(script::Type::QObject);

  Class qwidget_class = n.Class("Widget").setId(Type::QWidget).setBase(qobject_class).get();
  Type widget_type = qwidget_class.id();

  register_ref_specialization(n.engine(), Type::QWidget, Type::QWidgetStar);
  register_ptr_specialization<QWidget*>(n.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQWidget);
  register_list_specialization<QWidget*>(n.engine()->getTemplate(Engine::ListTemplate), Type::QListQWidget);

  auto widget = binding::QClass<QWidget>{ qwidget_class };
  qwidget_class.Constructor(callbacks::widget_ctor).create();
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
  binding::QSignal qwidget_signals{ qwidget_class, &QWidget::staticMetaObject };
  // void customContextMenuRequested(const QPoint &pos);
  //qwidget_signals.add<const QPoint &>("customContextMenuRequested", Q_SIGNAL("customContextMenuRequested(const QPoint &)"));
  // void windowIconChanged(const QIcon &icon);
  //qwidget_signals.add<const QIcon &>("windowIconChanged", Q_SIGNAL("windowIconChanged(const QIcon &)"));
  // void windowTitleChanged(const QString &title);
  qwidget_signals.add<const QString &>("windowTitleChanged", "windowTitleChanged(const QString &)");

  /* Events */
  qwidget_class.Method("closeEvent", callbacks::close_event)
    .setProtected()
    .params(binding::make_type<QCloseEvent &>())
    .create();

  qwidget_class.Method("enterEvent", callbacks::enter_event)
    .setProtected()
    .params(binding::make_type<QEvent &>())
    .create();

  qwidget_class.Method("hideEvent", callbacks::hide_event)
    .setProtected()
    .params(binding::make_type<QHideEvent &>())
    .create();

  qwidget_class.Method("keyPressEvent", callbacks::key_press_event)
    .setProtected()
    .params(binding::make_type<QKeyEvent &>())
    .create();

  qwidget_class.Method("keyReleaseEvent", callbacks::key_release_event)
    .setProtected()
    .params(binding::make_type<QKeyEvent &>())
    .create();

  qwidget_class.Method("leaveEvent", callbacks::leave_event)
    .setProtected()
    .params(binding::make_type<QEvent &>())
    .create();

  qwidget_class.Method("mouseDoubleClickEvent", callbacks::mouse_double_click_event)
    .setProtected()
    .params(binding::make_type<QMouseEvent &>())
    .create();

  qwidget_class.Method("mouseMoveEvent", callbacks::mouse_move_event)
    .setProtected()
    .params(binding::make_type<QMouseEvent &>())
    .create();

  qwidget_class.Method("mousePressEvent", callbacks::mouse_press_event)
    .setProtected()
    .params(binding::make_type<QMouseEvent &>())
    .create();

  qwidget_class.Method("mouseReleaseEvent", callbacks::mouse_release_event)
    .setProtected()
    .params(binding::make_type<QMouseEvent &>())
    .create();

  qwidget_class.Method("moveEvent", callbacks::mouse_move_event)
    .setProtected()
    .params(binding::make_type<QMoveEvent &>())
    .create();

  qwidget_class.Method("paintEvent", callbacks::paint_event)
    .setProtected()
    .params(binding::make_type<QPaintEvent &>())
    .create();

  qwidget_class.Method("resizeEvent", callbacks::resize_event)
    .setProtected()
    .params(binding::make_type<QResizeEvent &>())
    .create();

  qwidget_class.Method("showEvent", callbacks::show_event)
    .setProtected()
    .params(binding::make_type<QShowEvent &>())
    .create();

  qwidget_class.Method("wheelEvent", callbacks::wheel_event)
    .setProtected()
    .params(binding::make_type<QWheelEvent &>())
    .create();

  /* Non-members */

  n.Function("newWidget", callbacks::new_widget)
    .returns(Type::ref(widget_type))
    .create();

  n.Function("newWidget", callbacks::new_widget_window_title)
    .returns(Type::ref(widget_type))
    .params(Type::cref(Type::String))
    .create();

  register_new_widget_template(n);

  n.engine()->registerQtType(&QWidget::staticMetaObject, widget_type);
  n.engine()->registerQtType(&Widget::staticMetaObject, widget_type);
}


void new_widget_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & new_widget, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() != 1)
    return deduc.fail();

  std::vector<TemplateArgument> args;
  for (const auto & t : itypes)
  {
    if (t.isConst())
      args.push_back(TemplateArgument{ Type::cref(t.baseType()) });
    else
      args.push_back(TemplateArgument{ Type::ref(t.baseType()) });
  }

  deduc.record_deduction(1, TemplateArgument{ std::move(args) });
}

void new_widget_substitute(script::FunctionBuilder & builder, script::FunctionTemplate new_widget, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  builder.returns(Type::ref(targs.front().type));

  for (const auto & p : targs.back().pack->args())
  {
    builder.addParam(p.type);
  }
}


class NewWidgetTemplateData : public script::UserData
{
public:
  ~NewWidgetTemplateData() = default;

  script::Function target;
  std::vector<script::ConversionSequence> conversions;
  std::vector<script::Type> types;
  Widget::Callbacks callbacks;
};

namespace callbacks
{

static script::Value new_widget_template(script::FunctionCall *c)
{
  using namespace script;
  auto data = std::static_pointer_cast<NewWidgetTemplateData>(c->callee().data());
  std::vector<Value> args{ c->args().begin(), c->args().end() };
  c->engine()->applyConversions(args, data->types, data->conversions);
  Value widget = c->engine()->invoke(data->target, args);
  binding::value_cast<Widget*>(widget)->mCallbacks = data->callbacks;
  return widget;
}

} // namespace callbacks

void assign_callback(script::Function & callback, const script::Function & candidate, const std::string & name, const script::Type & param_type)
{
  if (candidate.returnType() != script::Type::Void || candidate.prototype().count() != 2 || candidate.parameter(1) != param_type)
    return;

  if (candidate.name() == name)
    callback = candidate;
}

void fill_callbacks(Widget::Callbacks & cbs, const script::Class & c)
{
  using namespace script;

  if (c.id() == Type::QWidget)
    return;

  for (const auto & f : c.memberFunctions())
  {
    assign_callback(cbs.close, f, "closeEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.enter, f, "enterEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.hide, f, "hideEvent", Type::ref(script::Type::QHideEvent));
    assign_callback(cbs.keyPress, f, "keyPressEvent", Type::ref(script::Type::QKeyEvent));
    assign_callback(cbs.keyRelease, f, "keyReleaseEvent", Type::ref(script::Type::QKeyEvent));
    assign_callback(cbs.leave, f, "leaveEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.mouseDoubleClick, f, "mouseDoubleClickEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mouseMove, f, "mouseMoveEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mousePress, f, "mousePressEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.mouseRelease, f, "mouseReleaseEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.move, f, "mouseReleaseEvent", Type::ref(script::Type::QMouseEvent));
    assign_callback(cbs.paint, f, "paintEvent", Type::ref(script::Type::QPaintEvent));
    assign_callback(cbs.resize, f, "resizeEvent", Type::ref(script::Type::QResizeEvent));
    assign_callback(cbs.show, f, "showEvent", Type::ref(script::Type::QEvent));
    assign_callback(cbs.wheel, f, "wheelEvent", Type::ref(script::Type::QWheelEvent));
  }

  fill_callbacks(cbs, c.parent());
}

std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> new_widget_instantitate(script::FunctionTemplate new_widget, script::Function instance)
{
  using namespace script;

  auto data = std::make_shared<NewWidgetTemplateData>();

  Class target_type = new_widget.engine()->getClass(instance.returnType());
  
  std::vector<Type> types = instance.prototype().parameters();
  
  OverloadResolution resol = OverloadResolution::New(new_widget.engine());
  if (!resol.process(target_type.constructors(), types))
    throw TemplateInstantiationError{ "newWidget() : Could not find valid constructor" };

  data->target = resol.selectedOverload();
  data->conversions = resol.conversionSequence();
  data->types = data->target.prototype().parameters();

  fill_callbacks(data->callbacks, target_type);

  return { callbacks::new_widget_template, data };
}

void register_new_widget_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params;
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, TemplateParameter::ParameterPack{}, "Args" });

  FunctionTemplate new_widget = Symbol{ n }.FunctionTemplate("newWidget")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .deduce(new_widget_deduce).substitute(new_widget_substitute).instantiate(new_widget_instantitate)
    .get();
}

script::Value make_widget(QWidget *widget, script::Engine *e)
{
  return make_ref(e, script::Type::QWidgetStar, widget);
}

Widget::Widget()
{

}

void Widget::QWidgetCloseEvent(QCloseEvent *e)
{
  return QWidget::closeEvent(e);
}

void Widget::QWidgetEnterEvent(QEvent *e)
{
  return QWidget::enterEvent(e);
}

void Widget::QWidgetHideEvent(QHideEvent *e)
{
  return QWidget::hideEvent(e);
}

void Widget::QWidgetKeyPressEvent(QKeyEvent *e)
{
  return QWidget::keyPressEvent(e);
}

void Widget::QWidgetKeyReleaseEvent(QKeyEvent *e)
{
  return QWidget::keyReleaseEvent(e);
}

void Widget::QWidgetLeaveEvent(QEvent *e)
{
  return QWidget::leaveEvent(e);
}

void Widget::QWidgetMouseDoubleClickEvent(QMouseEvent *e)
{
  return QWidget::mouseDoubleClickEvent(e);
}

void Widget::QWidgetMouseMoveEvent(QMouseEvent *e)
{
  return QWidget::mouseMoveEvent(e);
}

void Widget::QWidgetMousePressEvent(QMouseEvent *e)
{
  return QWidget::mousePressEvent(e);
}

void Widget::QWidgetMouseReleaseEvent(QMouseEvent *e)
{
  return QWidget::mouseReleaseEvent(e);
}

void Widget::QWidgetMoveEvent(QMoveEvent *e)
{
  return QWidget::moveEvent(e);
}

void Widget::QWidgetPaintEvent(QPaintEvent *e)
{
  return QWidget::paintEvent(e);
}

void Widget::QWidgetResizeEvent(QResizeEvent *e)
{
  return QWidget::resizeEvent(e);
}

void Widget::QWidgetShowEvent(QShowEvent *e)
{
  return QWidget::showEvent(e);
}

void Widget::QWidgetWheelEvent(QWheelEvent *e)
{
  return QWidget::wheelEvent(e);
}

script::Value Widget::self() const
{
  return this->property("_yasl_data_").value<binding::BindingData>().value;
}

void Widget::closeEvent(QCloseEvent *e)
{
  if (mCallbacks.close.isNull())
    return QWidget::closeEvent(e);

  script::Engine *engine = mCallbacks.close.engine();
  script::Value val = make_event(e, binding::make_type<QCloseEvent>(), engine);
  engine->invoke(mCallbacks.close, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::enterEvent(QEvent *e)
{
  if (mCallbacks.enter.isNull())
    return QWidget::enterEvent(e);

  script::Engine *engine = mCallbacks.enter.engine();
  script::Value val = make_event(e, binding::make_type<QEvent>(), engine);
  engine->invoke(mCallbacks.enter, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::hideEvent(QHideEvent *e)
{
  if (mCallbacks.hide.isNull())
    return QWidget::hideEvent(e);

  script::Engine *engine = mCallbacks.hide.engine();
  script::Value val = make_event(e, binding::make_type<QHideEvent>(), engine);
  engine->invoke(mCallbacks.hide, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
  if (mCallbacks.keyPress.isNull())
    return QWidget::keyPressEvent(e);

  script::Engine *engine = mCallbacks.keyPress.engine();
  script::Value val = make_event(e, binding::make_type<QKeyEvent>(), engine);
  engine->invoke(mCallbacks.keyPress, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
  if (mCallbacks.keyRelease.isNull())
    return QWidget::keyReleaseEvent(e);

  script::Engine *engine = mCallbacks.keyRelease.engine();
  script::Value val = make_event(e, binding::make_type<QKeyEvent>(), engine);
  engine->invoke(mCallbacks.keyRelease, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::leaveEvent(QEvent *e)
{
  if (mCallbacks.leave.isNull())
    return QWidget::leaveEvent(e);

  script::Engine *engine = mCallbacks.leave.engine();
  script::Value val = make_event(e, binding::make_type<QEvent>(), engine);
  engine->invoke(mCallbacks.leave, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseDoubleClick.isNull())
    return QWidget::mouseDoubleClickEvent(e);

  script::Engine *engine = mCallbacks.mouseDoubleClick.engine();
  script::Value val = make_event(e, binding::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseDoubleClick, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseMove.isNull())
    return QWidget::mouseMoveEvent(e);

  script::Engine *engine = mCallbacks.mouseMove.engine();
  script::Value val = make_event(e, binding::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseMove, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
  if (mCallbacks.mousePress.isNull())
    return QWidget::mousePressEvent(e);

  script::Engine *engine = mCallbacks.mousePress.engine();
  script::Value val = make_event(e, binding::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mousePress, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
  if (mCallbacks.mouseRelease.isNull())
    return QWidget::mouseReleaseEvent(e);

  script::Engine *engine = mCallbacks.mouseRelease.engine();
  script::Value val = make_event(e, binding::make_type<QMouseEvent>(), engine);
  engine->invoke(mCallbacks.mouseRelease, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::moveEvent(QMoveEvent *e)
{
  if (mCallbacks.move.isNull())
    return QWidget::moveEvent(e);

  script::Engine *engine = mCallbacks.move.engine();
  script::Value val = make_event(e, binding::make_type<QMoveEvent>(), engine);
  engine->invoke(mCallbacks.move, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::paintEvent(QPaintEvent *e)
{
  if (mCallbacks.paint.isNull())
    return QWidget::paintEvent(e);

  script::Engine *engine = mCallbacks.paint.engine();
  script::Value val = make_event(e, binding::make_type<QPaintEvent>(), engine);
  engine->invoke(mCallbacks.paint, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::resizeEvent(QResizeEvent *e)
{
  if (mCallbacks.resize.isNull())
    return QWidget::resizeEvent(e);

  script::Engine *engine = mCallbacks.resize.engine();
  script::Value val = make_event(e, binding::make_type<QResizeEvent>(), engine);
  engine->invoke(mCallbacks.resize, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::showEvent(QShowEvent *e)
{
  if (mCallbacks.show.isNull())
    return QWidget::showEvent(e);

  script::Engine *engine = mCallbacks.show.engine();
  script::Value val = make_event(e, binding::make_type<QShowEvent>(), engine);
  engine->invoke(mCallbacks.show, { self(), val });
  clear_event(val);
  engine->destroy(val);
}

void Widget::wheelEvent(QWheelEvent *e)
{
  if (mCallbacks.wheel.isNull())
    return QWidget::wheelEvent(e);

  script::Engine *engine = mCallbacks.wheel.engine();
  script::Value val = make_event(e, binding::make_type<QWheelEvent>(), engine);
  engine->invoke(mCallbacks.wheel, { self(), val });
  clear_event(val);
  engine->destroy(val);
}
