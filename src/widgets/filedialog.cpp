// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/filedialog.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
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

  Enum view_mode = file_dialog.Enum("ViewMode").setId(script::Type::QFileDialogViewMode).get();

  view_mode.addValue("Detail", QFileDialog::Detail);
  view_mode.addValue("List", QFileDialog::List);
}


static void register_file_dialog_file_mode_enum(script::Class file_dialog)
{
  using namespace script;

  Enum file_mode = file_dialog.Enum("FileMode").setId(script::Type::QFileDialogFileMode).get();

  file_mode.addValue("AnyFile", QFileDialog::AnyFile);
  file_mode.addValue("ExistingFile", QFileDialog::ExistingFile);
  file_mode.addValue("Directory", QFileDialog::Directory);
  file_mode.addValue("ExistingFiles", QFileDialog::ExistingFiles);
  file_mode.addValue("DirectoryOnly", QFileDialog::DirectoryOnly);
}


static void register_file_dialog_accept_mode_enum(script::Class file_dialog)
{
  using namespace script;

  Enum accept_mode = file_dialog.Enum("AcceptMode").setId(script::Type::QFileDialogAcceptMode).get();

  accept_mode.addValue("AcceptOpen", QFileDialog::AcceptOpen);
  accept_mode.addValue("AcceptSave", QFileDialog::AcceptSave);
}


static void register_file_dialog_dialog_label_enum(script::Class file_dialog)
{
  using namespace script;

  Enum dialog_label = file_dialog.Enum("DialogLabel").setId(script::Type::QFileDialogDialogLabel).get();

  dialog_label.addValue("LookIn", QFileDialog::LookIn);
  dialog_label.addValue("FileName", QFileDialog::FileName);
  dialog_label.addValue("FileType", QFileDialog::FileType);
  dialog_label.addValue("Accept", QFileDialog::Accept);
  dialog_label.addValue("Reject", QFileDialog::Reject);
}


static void register_file_dialog_option_enum(script::Class file_dialog)
{
  using namespace script;

  Enum option = file_dialog.Enum("Option").setId(script::Type::QFileDialogOption).get();

  register_qflags_type<QFileDialog::Option>(file_dialog, "Options", script::Type::QFileDialogOptions);
  option.addValue("ShowDirsOnly", QFileDialog::ShowDirsOnly);
  option.addValue("DontResolveSymlinks", QFileDialog::DontResolveSymlinks);
  option.addValue("DontConfirmOverwrite", QFileDialog::DontConfirmOverwrite);
  option.addValue("DontUseSheet", QFileDialog::DontUseSheet);
  option.addValue("DontUseNativeDialog", QFileDialog::DontUseNativeDialog);
  option.addValue("ReadOnly", QFileDialog::ReadOnly);
  option.addValue("HideNameFilterDetails", QFileDialog::HideNameFilterDetails);
  option.addValue("DontUseCustomDirectoryIcons", QFileDialog::DontUseCustomDirectoryIcons);
}


static void register_file_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class file_dialog = ns.Class("FileDialog").setId(script::Type::QFileDialog)
    .setBase(script::Type::QDialog).get();

  register_file_dialog_view_mode_enum(file_dialog);
  register_file_dialog_file_mode_enum(file_dialog);
  register_file_dialog_accept_mode_enum(file_dialog);
  register_file_dialog_dialog_label_enum(file_dialog);
  register_file_dialog_option_enum(file_dialog);
  binding::QClass<QFileDialog> binder{ file_dialog, &QFileDialog::staticMetaObject };

  // QFileDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QFileDialog(QWidget *, Qt::WindowFlags);
  // QFileDialog(QWidget *, const QString &, const QString &, const QString &);
  binder.ctors().add<QWidget *, const QString &, const QString &, const QString &>();
  // ~QFileDialog();
  binder.add_dtor();
  // void setDirectory(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::setDirectory>("setDirectory");
  // void setDirectory(const QDir &);
  binder.add_void_fun<const QDir &, &QFileDialog::setDirectory>("setDirectory");
  // QDir directory() const;
  binder.add_fun<QDir, &QFileDialog::directory>("directory");
  // void setDirectoryUrl(const QUrl &);
  binder.add_void_fun<const QUrl &, &QFileDialog::setDirectoryUrl>("setDirectoryUrl");
  // QUrl directoryUrl() const;
  binder.add_fun<QUrl, &QFileDialog::directoryUrl>("directoryUrl");
  // void selectFile(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::selectFile>("selectFile");
  // QStringList selectedFiles() const;
  /// TODO: QStringList selectedFiles() const;
  // void selectUrl(const QUrl &);
  binder.add_void_fun<const QUrl &, &QFileDialog::selectUrl>("selectUrl");
  // QList<QUrl> selectedUrls() const;
  /// TODO: QList<QUrl> selectedUrls() const;
  // void setNameFilterDetailsVisible(bool);
  binder.add_void_fun<bool, &QFileDialog::setNameFilterDetailsVisible>("setNameFilterDetailsVisible");
  // bool isNameFilterDetailsVisible() const;
  binder.add_fun<bool, &QFileDialog::isNameFilterDetailsVisible>("isNameFilterDetailsVisible");
  // void setNameFilter(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::setNameFilter>("setNameFilter");
  // void setNameFilters(const QStringList &);
  /// TODO: void setNameFilters(const QStringList &);
  // QStringList nameFilters() const;
  /// TODO: QStringList nameFilters() const;
  // void selectNameFilter(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::selectNameFilter>("selectNameFilter");
  // QString selectedMimeTypeFilter() const;
  binder.add_fun<QString, &QFileDialog::selectedMimeTypeFilter>("selectedMimeTypeFilter");
  // QString selectedNameFilter() const;
  binder.add_fun<QString, &QFileDialog::selectedNameFilter>("selectedNameFilter");
  // void setMimeTypeFilters(const QStringList &);
  /// TODO: void setMimeTypeFilters(const QStringList &);
  // QStringList mimeTypeFilters() const;
  /// TODO: QStringList mimeTypeFilters() const;
  // void selectMimeTypeFilter(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::selectMimeTypeFilter>("selectMimeTypeFilter");
  // QDir::Filters filter() const;
  binder.add_fun<QDir::Filters, &QFileDialog::filter>("filter");
  // void setFilter(QDir::Filters);
  binder.add_void_fun<QDir::Filters, &QFileDialog::setFilter>("setFilter");
  // void setViewMode(QFileDialog::ViewMode);
  binder.add_void_fun<QFileDialog::ViewMode, &QFileDialog::setViewMode>("setViewMode");
  // QFileDialog::ViewMode viewMode() const;
  binder.add_fun<QFileDialog::ViewMode, &QFileDialog::viewMode>("viewMode");
  // void setFileMode(QFileDialog::FileMode);
  binder.add_void_fun<QFileDialog::FileMode, &QFileDialog::setFileMode>("setFileMode");
  // QFileDialog::FileMode fileMode() const;
  binder.add_fun<QFileDialog::FileMode, &QFileDialog::fileMode>("fileMode");
  // void setAcceptMode(QFileDialog::AcceptMode);
  binder.add_void_fun<QFileDialog::AcceptMode, &QFileDialog::setAcceptMode>("setAcceptMode");
  // QFileDialog::AcceptMode acceptMode() const;
  binder.add_fun<QFileDialog::AcceptMode, &QFileDialog::acceptMode>("acceptMode");
  // void setReadOnly(bool);
  binder.add_void_fun<bool, &QFileDialog::setReadOnly>("setReadOnly");
  // bool isReadOnly() const;
  binder.add_fun<bool, &QFileDialog::isReadOnly>("isReadOnly");
  // void setResolveSymlinks(bool);
  binder.add_void_fun<bool, &QFileDialog::setResolveSymlinks>("setResolveSymlinks");
  // bool resolveSymlinks() const;
  binder.add_fun<bool, &QFileDialog::resolveSymlinks>("resolveSymlinks");
  // void setSidebarUrls(const QList<QUrl> &);
  /// TODO: void setSidebarUrls(const QList<QUrl> &);
  // QList<QUrl> sidebarUrls() const;
  /// TODO: QList<QUrl> sidebarUrls() const;
  // QByteArray saveState() const;
  binder.add_fun<QByteArray, &QFileDialog::saveState>("saveState");
  // bool restoreState(const QByteArray &);
  binder.add_fun<bool, const QByteArray &, &QFileDialog::restoreState>("restoreState");
  // void setConfirmOverwrite(bool);
  binder.add_void_fun<bool, &QFileDialog::setConfirmOverwrite>("setConfirmOverwrite");
  // bool confirmOverwrite() const;
  binder.add_fun<bool, &QFileDialog::confirmOverwrite>("confirmOverwrite");
  // void setDefaultSuffix(const QString &);
  binder.add_void_fun<const QString &, &QFileDialog::setDefaultSuffix>("setDefaultSuffix");
  // QString defaultSuffix() const;
  binder.add_fun<QString, &QFileDialog::defaultSuffix>("defaultSuffix");
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
  binder.add_void_fun<QFileDialog::DialogLabel, const QString &, &QFileDialog::setLabelText>("setLabelText");
  // QString labelText(QFileDialog::DialogLabel) const;
  binder.add_fun<QString, QFileDialog::DialogLabel, &QFileDialog::labelText>("labelText");
  // void setSupportedSchemes(const QStringList &);
  /// TODO: void setSupportedSchemes(const QStringList &);
  // QStringList supportedSchemes() const;
  /// TODO: QStringList supportedSchemes() const;
  // void setProxyModel(QAbstractProxyModel *);
  /// TODO: void setProxyModel(QAbstractProxyModel *);
  // QAbstractProxyModel * proxyModel() const;
  /// TODO: QAbstractProxyModel * proxyModel() const;
  // void setOption(QFileDialog::Option, bool);
  binder.add_void_fun<QFileDialog::Option, bool, &QFileDialog::setOption>("setOption");
  // bool testOption(QFileDialog::Option) const;
  binder.add_fun<bool, QFileDialog::Option, &QFileDialog::testOption>("testOption");
  // void setOptions(QFileDialog::Options);
  binder.add_void_fun<QFileDialog::Options, &QFileDialog::setOptions>("setOptions");
  // QFileDialog::Options options() const;
  binder.add_fun<QFileDialog::Options, &QFileDialog::options>("options");
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  binder.add_void_fun<bool, &QFileDialog::setVisible>("setVisible");
  // void fileSelected(const QString &);
  binder.sigs().add<const QString &>("fileSelected", "fileSelected(const QString &)");
  // void currentChanged(const QString &);
  binder.sigs().add<const QString &>("currentChanged", "currentChanged(const QString &)");
  // void directoryEntered(const QString &);
  binder.sigs().add<const QString &>("directoryEntered", "directoryEntered(const QString &)");
  // void filterSelected(const QString &);
  binder.sigs().add<const QString &>("filterSelected", "filterSelected(const QString &)");
  // static QString getOpenFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QString getOpenFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  // static QUrl getOpenFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getOpenFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  // static QString getSaveFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QString getSaveFileName(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  // static QUrl getSaveFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getSaveFileUrl(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  // static QString getExistingDirectory(QWidget *, const QString &, const QString &, QFileDialog::Options);
  binder.add_static<QString, QWidget *, const QString &, const QString &, QFileDialog::Options, &QFileDialog::getExistingDirectory>("getExistingDirectory");
  // static QUrl getExistingDirectoryUrl(QWidget *, const QString &, const QUrl &, QFileDialog::Options, const QStringList &);
  /// TODO: static QUrl getExistingDirectoryUrl(QWidget *, const QString &, const QUrl &, QFileDialog::Options, const QStringList &);
  // static QStringList getOpenFileNames(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  /// TODO: static QStringList getOpenFileNames(QWidget *, const QString &, const QString &, const QString &, QString *, QFileDialog::Options);
  // static QList<QUrl> getOpenFileUrls(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);
  /// TODO: static QList<QUrl> getOpenFileUrls(QWidget *, const QString &, const QUrl &, const QString &, QString *, QFileDialog::Options, const QStringList &);

  file_dialog.engine()->registerQtType(&QFileDialog::staticMetaObject, file_dialog.id());
}


void register_filedialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_file_dialog_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFileDialog::Options::enum_type);
  /// TODO: QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFileDialog::Options::enum_type);
  // QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFlags<QFileDialog::Options::enum_type>);
  /// TODO: QFlags<QFileDialog::Options::enum_type> operator|(QFileDialog::Options::enum_type, QFlags<QFileDialog::Options::enum_type>);
  // QIncompatibleFlag operator|(QFileDialog::Options::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFileDialog::Options::enum_type, int);
}

