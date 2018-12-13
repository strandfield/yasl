// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/icon.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/size.h"
#include "yasl/core/string.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/window.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_icon_mode_enum(script::Class icon)
{
  using namespace script;

  Enum mode = icon.newEnum("Mode").setId(script::Type::QIconMode).get();

  mode.addValue("Normal", QIcon::Normal);
  mode.addValue("Disabled", QIcon::Disabled);
  mode.addValue("Active", QIcon::Active);
  mode.addValue("Selected", QIcon::Selected);
}


static void register_icon_state_enum(script::Class icon)
{
  using namespace script;

  Enum state = icon.newEnum("State").setId(script::Type::QIconState).get();

  state.addValue("On", QIcon::On);
  state.addValue("Off", QIcon::Off);
}


static void register_icon_class(script::Namespace ns)
{
  using namespace script;

  Class icon = ns.newClass("Icon").setId(script::Type::QIcon).get();

  register_icon_mode_enum(icon);
  register_icon_state_enum(icon);

  // QIcon();
  bind::default_constructor<QIcon>(icon).create();
  // QIcon(const QPixmap &);
  bind::constructor<QIcon, const QPixmap &>(icon).create();
  // QIcon(const QIcon &);
  bind::constructor<QIcon, const QIcon &>(icon).create();
  // QIcon(QIcon &&);
  bind::constructor<QIcon, QIcon &&>(icon).create();
  // QIcon(const QString &);
  bind::constructor<QIcon, const QString &>(icon).create();
  // QIcon(QIconEngine *);
  /// TODO: QIcon(QIconEngine *);
  // ~QIcon();
  bind::destructor<QIcon>(icon).create();
  // QIcon & operator=(const QIcon &);
  bind::memop_assign<QIcon, const QIcon &>(icon);
  // QIcon & operator=(QIcon &&);
  bind::memop_assign<QIcon, QIcon &&>(icon);
  // void swap(QIcon &);
  bind::void_member_function<QIcon, QIcon &, &QIcon::swap>(icon, "swap").create();
  // QPixmap pixmap(const QSize &, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QPixmap, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>(icon, "pixmap")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QPixmap pixmap(int, int, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QPixmap, int, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>(icon, "pixmap")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QPixmap pixmap(int, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QPixmap, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>(icon, "pixmap")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QPixmap pixmap(QWindow *, const QSize &, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QPixmap, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>(icon, "pixmap")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
#endif
  // QSize actualSize(const QSize &, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QSize, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>(icon, "actualSize")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // QSize actualSize(QWindow *, const QSize &, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  bind::member_function<QIcon, QSize, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>(icon, "actualSize")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
#endif
  // QString name() const;
  bind::member_function<QIcon, QString, &QIcon::name>(icon, "name").create();
  // void paint(QPainter *, const QRect &, Qt::Alignment = Qt::Alignment(Qt::AlignCenter), QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  /// TODO: void paint(QPainter *, const QRect &, Qt::Alignment = Qt::Alignment(Qt::AlignCenter), QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  // void paint(QPainter *, int, int, int, int, Qt::Alignment = Qt::Alignment(Qt::AlignCenter), QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  /// TODO: void paint(QPainter *, int, int, int, int, Qt::Alignment = Qt::Alignment(Qt::AlignCenter), QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  // bool isNull() const;
  bind::member_function<QIcon, bool, &QIcon::isNull>(icon, "isNull").create();
  // bool isDetached() const;
  bind::member_function<QIcon, bool, &QIcon::isDetached>(icon, "isDetached").create();
  // void detach();
  bind::void_member_function<QIcon, &QIcon::detach>(icon, "detach").create();
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // void addPixmap(const QPixmap &, QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off);
  bind::void_member_function<QIcon, const QPixmap &, QIcon::Mode, QIcon::State, &QIcon::addPixmap>(icon, "addPixmap")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // void addFile(const QString &, const QSize & = QSize(), QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off);
  bind::void_member_function<QIcon, const QString &, const QSize &, QIcon::Mode, QIcon::State, &QIcon::addFile>(icon, "addFile")
    .apply(bind::default_arguments(QIcon::Off, QIcon::Normal, QSize())).create();
  // QList<QSize> availableSizes(QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
  /// TODO: QList<QSize> availableSizes(QIcon::Mode = QIcon::Normal, QIcon::State = QIcon::Off) const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // void setIsMask(bool);
  bind::void_member_function<QIcon, bool, &QIcon::setIsMask>(icon, "setIsMask").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // bool isMask() const;
  bind::member_function<QIcon, bool, &QIcon::isMask>(icon, "isMask").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // static QIcon fromTheme(const QString &);
  bind::static_member_function<QIcon, QIcon, const QString &, &QIcon::fromTheme>(icon, "fromTheme").create();
#endif
  // static QIcon fromTheme(const QString &, const QIcon &);
  bind::static_member_function<QIcon, QIcon, const QString &, const QIcon &, &QIcon::fromTheme>(icon, "fromTheme").create();
  // static bool hasThemeIcon(const QString &);
  bind::static_member_function<QIcon, bool, const QString &, &QIcon::hasThemeIcon>(icon, "hasThemeIcon").create();
  // static QStringList themeSearchPaths();
  bind::static_member_function<QIcon, QStringList, &QIcon::themeSearchPaths>(icon, "themeSearchPaths").create();
  // static void setThemeSearchPaths(const QStringList &);
  bind::static_void_member_function<QIcon, const QStringList &, &QIcon::setThemeSearchPaths>(icon, "setThemeSearchPaths").create();
  // static QString themeName();
  bind::static_member_function<QIcon, QString, &QIcon::themeName>(icon, "themeName").create();
  // static void setThemeName(const QString &);
  bind::static_void_member_function<QIcon, const QString &, &QIcon::setThemeName>(icon, "setThemeName").create();
  // QIcon::DataPtr & data_ptr();
  /// TODO: QIcon::DataPtr & data_ptr();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QIcon, QMetaType::QIcon>>();
}


void register_icon_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_icon_class(ns);

  // QDataStream & operator<<(QDataStream &, const QIcon &);
  bind::op_put_to<QDataStream &, const QIcon &>(ns);
  // QDataStream & operator>>(QDataStream &, QIcon &);
  bind::op_read_from<QDataStream &, QIcon &>(ns);
  // QDebug operator<<(QDebug, const QIcon &);
  /// TODO: QDebug operator<<(QDebug, const QIcon &);
  // QString qt_findAtNxFile(const QString &, qreal, qreal *);
  /// TODO: QString qt_findAtNxFile(const QString &, qreal, qreal *);
}
