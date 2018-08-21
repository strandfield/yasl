// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/icon.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/pixmap.h"

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
  binding::Class<QIcon> binder{ icon };

  // QIcon();
  binder.ctors().add_default();
  // QIcon(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // QIcon(const QIcon &);
  binder.ctors().add<const QIcon &>();
  // QIcon(QIcon &&);
  binder.ctors().add<QIcon &&>();
  // QIcon(const QString &);
  binder.ctors().add<const QString &>();
  // QIcon(QIconEngine *);
  /// TODO: QIcon(QIconEngine *);
  // ~QIcon();
  binder.add_dtor();
  // QIcon & operator=(const QIcon &);
  binder.operators().assign<const QIcon &>();
  // QIcon & operator=(QIcon &&);
  binder.operators().assign<QIcon &&>();
  // void swap(QIcon &);
  binder.add_void_fun<QIcon &, &QIcon::swap>("swap");
  // QPixmap pixmap(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(int, int, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, int, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(int, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  /// TODO: QPixmap pixmap(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  // QSize actualSize(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QSize, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>("actualSize");
  // QSize actualSize(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  /// TODO: QSize actualSize(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  // QString name() const;
  binder.add_fun<QString, &QIcon::name>("name");
  // void paint(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: void paint(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  // void paint(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: void paint(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  // bool isNull() const;
  binder.add_fun<bool, &QIcon::isNull>("isNull");
  // bool isDetached() const;
  binder.add_fun<bool, &QIcon::isDetached>("isDetached");
  // void detach();
  binder.add_void_fun<&QIcon::detach>("detach");
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // void addPixmap(const QPixmap &, QIcon::Mode, QIcon::State);
  binder.add_void_fun<const QPixmap &, QIcon::Mode, QIcon::State, &QIcon::addPixmap>("addPixmap");
  // void addFile(const QString &, const QSize &, QIcon::Mode, QIcon::State);
  binder.add_void_fun<const QString &, const QSize &, QIcon::Mode, QIcon::State, &QIcon::addFile>("addFile");
  // QList<QSize> availableSizes(QIcon::Mode, QIcon::State) const;
  /// TODO: QList<QSize> availableSizes(QIcon::Mode, QIcon::State) const;
  // void setIsMask(bool);
  binder.add_void_fun<bool, &QIcon::setIsMask>("setIsMask");
  // bool isMask() const;
  binder.add_fun<bool, &QIcon::isMask>("isMask");
  // static QIcon fromTheme(const QString &);
  binder.add_static<QIcon, const QString &, &QIcon::fromTheme>("fromTheme");
  // static QIcon fromTheme(const QString &, const QIcon &);
  binder.add_static<QIcon, const QString &, const QIcon &, &QIcon::fromTheme>("fromTheme");
  // static bool hasThemeIcon(const QString &);
  binder.add_static<bool, const QString &, &QIcon::hasThemeIcon>("hasThemeIcon");
  // static QStringList themeSearchPaths();
  /// TODO: static QStringList themeSearchPaths();
  // static void setThemeSearchPaths(const QStringList &);
  /// TODO: static void setThemeSearchPaths(const QStringList &);
  // static QString themeName();
  binder.add_static<QString, &QIcon::themeName>("themeName");
  // static void setThemeName(const QString &);
  binder.add_static_void_fun<const QString &, &QIcon::setThemeName>("setThemeName");
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
  binder.add_void_fun<QIcon &, QIcon &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QIcon &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QIcon &);
  // QDataStream & operator>>(QDataStream &, QIcon &);
  /// TODO: QDataStream & operator>>(QDataStream &, QIcon &);
  // QDebug operator<<(QDebug, const QIcon &);
  /// TODO: QDebug operator<<(QDebug, const QIcon &);
  // QString qt_findAtNxFile(const QString &, qreal, qreal *);
  /// TODO: QString qt_findAtNxFile(const QString &, qreal, qreal *);
}

