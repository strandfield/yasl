// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/icon.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/window.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_icon_mode_enum(script::Class icon)
{
  using namespace script;

  Enum mode = icon.Enum("Mode").setId(script::Type::QIconMode).get();

  mode.addValue("Normal", QIcon::Normal);
  mode.addValue("Disabled", QIcon::Disabled);
  mode.addValue("Active", QIcon::Active);
  mode.addValue("Selected", QIcon::Selected);
}


static void register_icon_state_enum(script::Class icon)
{
  using namespace script;

  Enum state = icon.Enum("State").setId(script::Type::QIconState).get();

  state.addValue("On", QIcon::On);
  state.addValue("Off", QIcon::Off);
}


static void register_icon_class(script::Namespace ns)
{
  using namespace script;

  Class icon = ns.Class("Icon").setId(script::Type::QIcon).get();

  register_icon_mode_enum(icon);
  register_icon_state_enum(icon);
  binding::ClassBinder<QIcon> binder{ icon };

  // QIcon();
  binder.default_ctor().create();
  // QIcon(const QPixmap &);
  binder.ctor<const QPixmap &>().create();
  // QIcon(const QIcon &);
  binder.ctor<const QIcon &>().create();
  // QIcon(QIcon &&);
  binder.ctor<QIcon &&>().create();
  // QIcon(const QString &);
  binder.ctor<const QString &>().create();
  // QIcon(QIconEngine *);
  /// TODO: QIcon(QIconEngine *);
  // ~QIcon();
  binder.dtor().create();
  // QIcon & operator=(const QIcon &);
  binder.operators().assign<const QIcon &>();
  // QIcon & operator=(QIcon &&);
  binder.operators().assign<QIcon &&>();
  // void swap(QIcon &);
  binder.void_fun<QIcon &, &QIcon::swap>("swap").create();
  // QPixmap pixmap(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.fun<QPixmap, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QPixmap pixmap(int, int, QIcon::Mode, QIcon::State) const;
  binder.fun<QPixmap, int, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QPixmap pixmap(int, QIcon::Mode, QIcon::State) const;
  binder.fun<QPixmap, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QPixmap pixmap(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  binder.fun<QPixmap, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QSize actualSize(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.fun<QSize, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>("actualSize")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QSize actualSize(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  binder.fun<QSize, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>("actualSize")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // QString name() const;
  binder.fun<QString, &QIcon::name>("name").create();
  // void paint(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: void paint(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  // void paint(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: void paint(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  // bool isNull() const;
  binder.fun<bool, &QIcon::isNull>("isNull").create();
  // bool isDetached() const;
  binder.fun<bool, &QIcon::isDetached>("isDetached").create();
  // void detach();
  binder.void_fun<&QIcon::detach>("detach").create();
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // void addPixmap(const QPixmap &, QIcon::Mode, QIcon::State);
  binder.void_fun<const QPixmap &, QIcon::Mode, QIcon::State, &QIcon::addPixmap>("addPixmap")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal)).create();
  // void addFile(const QString &, const QSize &, QIcon::Mode, QIcon::State);
  binder.void_fun<const QString &, const QSize &, QIcon::Mode, QIcon::State, &QIcon::addFile>("addFile")
    .apply(binding::default_arguments(QIcon::Off, QIcon::Normal, QSize())).create();
  // QList<QSize> availableSizes(QIcon::Mode, QIcon::State) const;
  /// TODO: QList<QSize> availableSizes(QIcon::Mode, QIcon::State) const;
  // void setIsMask(bool);
  binder.void_fun<bool, &QIcon::setIsMask>("setIsMask").create();
  // bool isMask() const;
  binder.fun<bool, &QIcon::isMask>("isMask").create();
  // static QIcon fromTheme(const QString &);
  binder.static_fun<QIcon, const QString &, &QIcon::fromTheme>("fromTheme").create();
  // static QIcon fromTheme(const QString &, const QIcon &);
  binder.static_fun<QIcon, const QString &, const QIcon &, &QIcon::fromTheme>("fromTheme").create();
  // static bool hasThemeIcon(const QString &);
  binder.static_fun<bool, const QString &, &QIcon::hasThemeIcon>("hasThemeIcon").create();
  // static QStringList themeSearchPaths();
  /// TODO: static QStringList themeSearchPaths();
  // static void setThemeSearchPaths(const QStringList &);
  /// TODO: static void setThemeSearchPaths(const QStringList &);
  // static QString themeName();
  binder.static_fun<QString, &QIcon::themeName>("themeName").create();
  // static void setThemeName(const QString &);
  binder.static_void_fun<const QString &, &QIcon::setThemeName>("setThemeName").create();
  // QIcon::DataPtr & data_ptr();
  /// TODO: QIcon::DataPtr & data_ptr();
}


void register_icon_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_icon_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QIcon &, QIcon &);
  binder.void_fun<QIcon &, QIcon &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QIcon &);
  binder.operators().put_to<QDataStream &, const QIcon &>();
  // QDataStream & operator>>(QDataStream &, QIcon &);
  binder.operators().read_from<QDataStream &, QIcon &>();
  // QDebug operator<<(QDebug, const QIcon &);
  /// TODO: QDebug operator<<(QDebug, const QIcon &);
  // QString qt_findAtNxFile(const QString &, qreal, qreal *);
  /// TODO: QString qt_findAtNxFile(const QString &, qreal, qreal *);
}

