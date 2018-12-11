// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/filedialog.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/core/flags.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/dir.h"
#include "yasl/core/object.h"
#include "yasl/core/url.h"
#include "yasl/widgets/filedialog.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_file_dialog_view_mode_enum(script::Class file_dialog)
{
  using namespace script;

  Enum view_mode = file_dialog.newEnum("ViewMode").setId(script::Type::QFileDialogViewMode).get();

  view_mode.addValue("Detail", QFileDialog::Detail);
  view_mode.addValue("List", QFileDialog::List);
}


static void register_file_dialog_file_mode_enum(script::Class file_dialog)
{
  using namespace script;

  Enum file_mode = file_dialog.newEnum("FileMode").setId(script::Type::QFileDialogFileMode).get();

  file_mode.addValue("AnyFile", QFileDialog::AnyFile);
  file_mode.addValue("ExistingFile", QFileDialog::ExistingFile);
  file_mode.addValue("Directory", QFileDialog::Directory);
  file_mode.addValue("ExistingFiles", QFileDialog::ExistingFiles);
  file_mode.addValue("DirectoryOnly", QFileDialog::DirectoryOnly);
}


static void register_file_dialog_accept_mode_enum(script::Class file_dialog)
{
  using namespace script;

  Enum accept_mode = file_dialog.newEnum("AcceptMode").setId(script::Type::QFileDialogAcceptMode).get();

  accept_mode.addValue("AcceptOpen", QFileDialog::AcceptOpen);
  accept_mode.addValue("AcceptSave", QFileDialog::AcceptSave);
}


static void register_file_dialog_dialog_label_enum(script::Class file_dialog)
{
  using namespace script;

  Enum dialog_label = file_dialog.newEnum("DialogLabel").setId(script::Type::QFileDialogDialogLabel).get();

  dialog_label.addValue("LookIn", QFileDialog::LookIn);
  dialog_label.addValue("FileName", QFileDialog::FileName);
  dialog_label.addValue("FileType", QFileDialog::FileType);
  dialog_label.addValue("Accept", QFileDialog::Accept);
  dialog_label.addValue("Reject", QFileDialog::Reject);
}


static void register_file_dialog_option_enum(script::Class file_dialog)
{
  using namespace script;

  Enum option = file_dialog.newEnum("Option").setId(script::Type::QFileDialogOption).get();

  register_qflags_type<QFileDialog::Option>(file_dialog, "Options", script::Type::QFileDialogOptions);

  option.addValue("ShowDirsOnly", QFileDialog::ShowDirsOnly);
  option.addValue("DontResolveSymlinks", QFileDialog::DontResolveSymlinks);
  option.addValue("DontConfirmOverwrite", QFileDialog::DontConfirmOverwrite);
  option.addValue("DontUseSheet", QFileDialog::DontUseSheet);
  option.addValue("DontUseNativeDialog", QFileDialog::DontUseNativeDialog);
  option.addValue("ReadOnly", QFileDialog::ReadOnly);
  option.addValue("HideNameFilterDetails", QFileDialog::HideNameFilterDetails);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  option.addValue("DontUseCustomDirectoryIcons", QFileDialog::DontUseCustomDirectoryIcons);
#endif
}


static void register_file_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class file_dialog = ns.newClass("FileDialog").setId(script::Type::QFileDialog)
    .setBase(script::Type::QDialog).get();

  register_file_dialog_view_mode_enum(file_dialog);
  register_file_dialog_file_mode_enum(file_dialog);
  register_file_dialog_accept_mode_enum(file_dialog);
  register_file_dialog_dialog_label_enum(file_dialog);
  register_file_dialog_option_enum(file_dialog);

  // QFileDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QFileDialog(QWidget *, Qt::WindowFlags);
  // QFileDialog(QWidget *, const QString &, const QString &, const QString &);
  bind::constructor<QFileDialog, QWidget *, const QString &, const QString &, const QString &>(file_dialog).create();
  // ~QFileDialog();
  bind::destructor<QFileDialog>(file_dialog).create();
  // void setDirectory(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::setDirectory>(file_dialog, "setDirectory").create();
  // void setDirectory(const QDir &);
  bind::void_member_function<QFileDialog, const QDir &, &QFileDialog::setDirectory>(file_dialog, "setDirectory").create();
  // QDir directory() const;
  bind::member_function<QFileDialog, QDir, &QFileDialog::directory>(file_dialog, "directory").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void setDirectoryUrl(const QUrl &);
  bind::void_member_function<QFileDialog, const QUrl &, &QFileDialog::setDirectoryUrl>(file_dialog, "setDirectoryUrl").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QUrl directoryUrl() const;
  bind::member_function<QFileDialog, QUrl, &QFileDialog::directoryUrl>(file_dialog, "directoryUrl").create();
#endif
  // void selectFile(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::selectFile>(file_dialog, "selectFile").create();
  // QStringList selectedFiles() const;
  /// TODO: QStringList selectedFiles() const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void selectUrl(const QUrl &);
  bind::void_member_function<QFileDialog, const QUrl &, &QFileDialog::selectUrl>(file_dialog, "selectUrl").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QList<QUrl> selectedUrls() const;
  /// TODO: QList<QUrl> selectedUrls() const;
#endif
  // void setNameFilterDetailsVisible(bool);
  bind::void_member_function<QFileDialog, bool, &QFileDialog::setNameFilterDetailsVisible>(file_dialog, "setNameFilterDetailsVisible").create();
  // bool isNameFilterDetailsVisible() const;
  bind::member_function<QFileDialog, bool, &QFileDialog::isNameFilterDetailsVisible>(file_dialog, "isNameFilterDetailsVisible").create();
  // void setNameFilter(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::setNameFilter>(file_dialog, "setNameFilter").create();
  // void setNameFilters(const QStringList &);
  /// TODO: void setNameFilters(const QStringList &);
  // QStringList nameFilters() const;
  /// TODO: QStringList nameFilters() const;
  // void selectNameFilter(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::selectNameFilter>(file_dialog, "selectNameFilter").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  // QString selectedMimeTypeFilter() const;
  bind::member_function<QFileDialog, QString, &QFileDialog::selectedMimeTypeFilter>(file_dialog, "selectedMimeTypeFilter").create();
#endif
  // QString selectedNameFilter() const;
  bind::member_function<QFileDialog, QString, &QFileDialog::selectedNameFilter>(file_dialog, "selectedNameFilter").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void setMimeTypeFilters(const QStringList &);
  /// TODO: void setMimeTypeFilters(const QStringList &);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QStringList mimeTypeFilters() const;
  /// TODO: QStringList mimeTypeFilters() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void selectMimeTypeFilter(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::selectMimeTypeFilter>(file_dialog, "selectMimeTypeFilter").create();
#endif
  // QDir::Filters filter() const;
  bind::member_function<QFileDialog, QDir::Filters, &QFileDialog::filter>(file_dialog, "filter").create();
  // void setFilter(QDir::Filters);
  bind::void_member_function<QFileDialog, QDir::Filters, &QFileDialog::setFilter>(file_dialog, "setFilter").create();
  // void setViewMode(QFileDialog::ViewMode);
  bind::void_member_function<QFileDialog, QFileDialog::ViewMode, &QFileDialog::setViewMode>(file_dialog, "setViewMode").create();
  // QFileDialog::ViewMode viewMode() const;
  bind::member_function<QFileDialog, QFileDialog::ViewMode, &QFileDialog::viewMode>(file_dialog, "viewMode").create();
  // void setFileMode(QFileDialog::FileMode);
  bind::void_member_function<QFileDialog, QFileDialog::FileMode, &QFileDialog::setFileMode>(file_dialog, "setFileMode").create();
  // QFileDialog::FileMode fileMode() const;
  bind::member_function<QFileDialog, QFileDialog::FileMode, &QFileDialog::fileMode>(file_dialog, "fileMode").create();
  // void setAcceptMode(QFileDialog::AcceptMode);
  bind::void_member_function<QFileDialog, QFileDialog::AcceptMode, &QFileDialog::setAcceptMode>(file_dialog, "setAcceptMode").create();
  // QFileDialog::AcceptMode acceptMode() const;
  bind::member_function<QFileDialog, QFileDialog::AcceptMode, &QFileDialog::acceptMode>(file_dialog, "acceptMode").create();
  // void setReadOnly(bool);
  bind::void_member_function<QFileDialog, bool, &QFileDialog::setReadOnly>(file_dialog, "setReadOnly").create();
  // bool isReadOnly() const;
  bind::member_function<QFileDialog, bool, &QFileDialog::isReadOnly>(file_dialog, "isReadOnly").create();
  // void setResolveSymlinks(bool);
  bind::void_member_function<QFileDialog, bool, &QFileDialog::setResolveSymlinks>(file_dialog, "setResolveSymlinks").create();
  // bool resolveSymlinks() const;
  bind::member_function<QFileDialog, bool, &QFileDialog::resolveSymlinks>(file_dialog, "resolveSymlinks").create();
  // void setSidebarUrls(const QList<QUrl> &);
  /// TODO: void setSidebarUrls(const QList<QUrl> &);
  // QList<QUrl> sidebarUrls() const;
  /// TODO: QList<QUrl> sidebarUrls() const;
  // QByteArray saveState() const;
  bind::member_function<QFileDialog, QByteArray, &QFileDialog::saveState>(file_dialog, "saveState").create();
  // bool restoreState(const QByteArray &);
  bind::member_function<QFileDialog, bool, const QByteArray &, &QFileDialog::restoreState>(file_dialog, "restoreState").create();
  // void setConfirmOverwrite(bool);
  bind::void_member_function<QFileDialog, bool, &QFileDialog::setConfirmOverwrite>(file_dialog, "setConfirmOverwrite").create();
  // bool confirmOverwrite() const;
  bind::member_function<QFileDialog, bool, &QFileDialog::confirmOverwrite>(file_dialog, "confirmOverwrite").create();
  // void setDefaultSuffix(const QString &);
  bind::void_member_function<QFileDialog, const QString &, &QFileDialog::setDefaultSuffix>(file_dialog, "setDefaultSuffix").create();
  // QString defaultSuffix() const;
  bind::member_function<QFileDialog, QString, &QFileDialog::defaultSuffix>(file_dialog, "defaultSuffix").create();
  // void setHistory(const QStringList &);
  /// TODO: void setHistory(const QStringList &);
  // QStringList history() const;
  /// TODO: QStringList history() const;
  // void setItemDelegate(QAbstractItemDelegate *);
  /// TODO: void setItemDelegate(QAbstractItemDelegate *);
  // QAbstractItemDelegate * itemDelegate() const;
  /// TODO: QAbstractItemDelegate * itemDelegate() const;
  // void setIconProvider(QFileIconProvider *);
  /// TODO: void setIconProvider(QFileIconProvider *);
  // QFileIconProvider * iconProvider() const;
  /// TODO: QFileIconProvider * iconProvider() const;
  // void setLabelText(QFileDialog::DialogLabel, const QString &);
  bind::void_member_function<QFileDialog, QFileDialog::DialogLabel, const QString &, &QFileDialog::setLabelText>(file_dialog, "setLabelText").create();
  // QString labelText(QFileDialog::DialogLabel) const;
  bind::member_function<QFileDialog, QString, QFileDialog::DialogLabel, &QFileDialog::labelText>(file_dialog, "labelText").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // void setSupportedSchemes(const QStringList &);
  /// TODO: void setSupportedSchemes(const QStringList &);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // QStringList supportedSchemes() const;
  /// TODO: QStringList supportedSchemes() const;
#endif
  // void setProxyModel(QAbstractProxyModel *);
  /// TODO: void setProxyModel(QAbstractProxyModel *);
  // QAbstractProxyModel * proxyModel() const;
  /// TODO: QAbstractProxyModel * proxyModel() const;
  // void setOption(QFileDialog::Option, bool);
  bind::void_member_function<QFileDialog, QFileDialog::Option, bool, &QFileDialog::setOption>(file_dialog, "setOption").create();
  // bool testOption(QFileDialog::Option) const;
  bind::member_function<QFileDialog, bool, QFileDialog::Option, &QFileDialog::testOption>(file_dialog, "testOption").create();
  // void setOptions(QFileDialog::Options);
  bind::void_member_function<QFileDialog, QFileDialog::Options, &QFileDialog::setOptions>(file_dialog, "setOptions").create();
  // QFileDialog::Options options() const;
  bind::member_function<QFileDialog, QFileDialog::Options, &QFileDialog::options>(file_dialog, "options").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  bind::void_member_function<QFileDialog, bool, &QFileDialog::setVisible>(file_dialog, "setVisible").create();
  // void fileSelected(const QString &);
  bind::signal<QFileDialog, const QString &>(file_dialog, "fileSelected", "fileSelected(const QString &)");
  // void currentChanged(const QString &);
  bind::signal<QFileDialog, const QString &>(file_dialog, "currentChanged", "currentChanged(const QString &)");
  // void directoryEntered(const QString &);
  bind::signal<QFileDialog, const QString &>(file_dialog, "directoryEntered", "directoryEntered(const QString &)");
  // void filterSelected(const QString &);
  bind::signal<QFileDialog, const QString &>(file_dialog, "filterSelected", "filterSelected(const QString &)");
  // static QString getOpenFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QString getOpenFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QUrl getOpenFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getOpenFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
#endif
  // static QString getSaveFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QString getSaveFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QUrl getSaveFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getSaveFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
#endif
  // static QString getExistingDirectory(QWidget *, const QString &, const QString &, QFileDialog::Options);
  bind::static_member_function<QFileDialog, QString, QWidget *, const QString &, const QString &, QFileDialog::Options, &QFileDialog::getExistingDirectory>(file_dialog, "getExistingDirectory").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QUrl getExistingDirectoryUrl(QWidget *, const QString &, const QUrl &, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getExistingDirectoryUrl(QWidget *, const QString &, const QUrl &, QFileDialog::Options, const QStringList &);
#endif
  // static QStringList getOpenFileNames(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QStringList getOpenFileNames(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QList<QUrl> getOpenFileUrls(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QList<QUrl> getOpenFileUrls(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
#endif

  bind::link(file_dialog, &QFileDialog::staticMetaObject);
}


void register_filedialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_file_dialog_class(ns);

  // QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFileDialog::Options::enum_type);
  /// TODO: QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFileDialog::Options::enum_type);
  // QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFlags<QFileDialog::Options::enum_type>);
  /// TODO: QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFlags<QFileDialog::Options::enum_type>);
  // QIncompatibleFlag operator|(QFileDialog::Options::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFileDialog::Options::enum_type, int);
}
