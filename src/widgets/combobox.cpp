// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/combobox.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/core/variant.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/combobox.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_combo_box_insert_policy_enum(script::Class combo_box)
{
  using namespace script;

  Enum insert_policy = combo_box.Enum("InsertPolicy").setId(script::Type::QComboBoxInsertPolicy).get();

  insert_policy.addValue("NoInsert", QComboBox::NoInsert);
  insert_policy.addValue("InsertAtTop", QComboBox::InsertAtTop);
  insert_policy.addValue("InsertAtCurrent", QComboBox::InsertAtCurrent);
  insert_policy.addValue("InsertAtBottom", QComboBox::InsertAtBottom);
  insert_policy.addValue("InsertAfterCurrent", QComboBox::InsertAfterCurrent);
  insert_policy.addValue("InsertBeforeCurrent", QComboBox::InsertBeforeCurrent);
  insert_policy.addValue("InsertAlphabetically", QComboBox::InsertAlphabetically);
}


static void register_combo_box_size_adjust_policy_enum(script::Class combo_box)
{
  using namespace script;

  Enum size_adjust_policy = combo_box.Enum("SizeAdjustPolicy").setId(script::Type::QComboBoxSizeAdjustPolicy).get();

  size_adjust_policy.addValue("AdjustToContents", QComboBox::AdjustToContents);
  size_adjust_policy.addValue("AdjustToContentsOnFirstShow", QComboBox::AdjustToContentsOnFirstShow);
  size_adjust_policy.addValue("AdjustToMinimumContentsLength", QComboBox::AdjustToMinimumContentsLength);
  size_adjust_policy.addValue("AdjustToMinimumContentsLengthWithIcon", QComboBox::AdjustToMinimumContentsLengthWithIcon);
}


static void register_combo_box_class(script::Namespace ns)
{
  using namespace script;

  Class combo_box = ns.Class("ComboBox").setId(script::Type::QComboBox)
    .setBase(script::Type::QWidget).get();

  register_combo_box_insert_policy_enum(combo_box);
  register_combo_box_size_adjust_policy_enum(combo_box);
  binding::QClass<QComboBox> binder{ combo_box, &QComboBox::staticMetaObject };

  // QComboBox(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .addDefaultArgument(binding::default_argument(combo_box.engine(), (QWidget*)nullptr)).create();
  // ~QComboBox();
  binder.add_dtor();
  // int maxVisibleItems() const;
  binder.fun<int, &QComboBox::maxVisibleItems>("maxVisibleItems").create();
  // void setMaxVisibleItems(int);
  binder.void_fun<int, &QComboBox::setMaxVisibleItems>("setMaxVisibleItems").create();
  // int count() const;
  binder.fun<int, &QComboBox::count>("count").create();
  // void setMaxCount(int);
  binder.void_fun<int, &QComboBox::setMaxCount>("setMaxCount").create();
  // int maxCount() const;
  binder.fun<int, &QComboBox::maxCount>("maxCount").create();
  // bool autoCompletion() const;
  binder.fun<bool, &QComboBox::autoCompletion>("autoCompletion").create();
  // void setAutoCompletion(bool);
  binder.void_fun<bool, &QComboBox::setAutoCompletion>("setAutoCompletion").create();
  // Qt::CaseSensitivity autoCompletionCaseSensitivity() const;
  binder.fun<Qt::CaseSensitivity, &QComboBox::autoCompletionCaseSensitivity>("autoCompletionCaseSensitivity").create();
  // void setAutoCompletionCaseSensitivity(Qt::CaseSensitivity);
  binder.void_fun<Qt::CaseSensitivity, &QComboBox::setAutoCompletionCaseSensitivity>("setAutoCompletionCaseSensitivity").create();
  // bool duplicatesEnabled() const;
  binder.fun<bool, &QComboBox::duplicatesEnabled>("duplicatesEnabled").create();
  // void setDuplicatesEnabled(bool);
  binder.void_fun<bool, &QComboBox::setDuplicatesEnabled>("setDuplicatesEnabled").create();
  // void setFrame(bool);
  binder.void_fun<bool, &QComboBox::setFrame>("setFrame").create();
  // bool hasFrame() const;
  binder.fun<bool, &QComboBox::hasFrame>("hasFrame").create();
  // int findText(const QString &, Qt::MatchFlags) const;
  /// TODO: int findText(const QString &, Qt::MatchFlags) const;
  // int findData(const QVariant &, int, Qt::MatchFlags) const;
  /// TODO: int findData(const QVariant &, int, Qt::MatchFlags) const;
  // QComboBox::InsertPolicy insertPolicy() const;
  binder.fun<QComboBox::InsertPolicy, &QComboBox::insertPolicy>("insertPolicy").create();
  // void setInsertPolicy(QComboBox::InsertPolicy);
  binder.void_fun<QComboBox::InsertPolicy, &QComboBox::setInsertPolicy>("setInsertPolicy").create();
  // QComboBox::SizeAdjustPolicy sizeAdjustPolicy() const;
  binder.fun<QComboBox::SizeAdjustPolicy, &QComboBox::sizeAdjustPolicy>("sizeAdjustPolicy").create();
  // void setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy);
  binder.void_fun<QComboBox::SizeAdjustPolicy, &QComboBox::setSizeAdjustPolicy>("setSizeAdjustPolicy").create();
  // int minimumContentsLength() const;
  binder.fun<int, &QComboBox::minimumContentsLength>("minimumContentsLength").create();
  // void setMinimumContentsLength(int);
  binder.void_fun<int, &QComboBox::setMinimumContentsLength>("setMinimumContentsLength").create();
  // QSize iconSize() const;
  binder.fun<QSize, &QComboBox::iconSize>("iconSize").create();
  // void setIconSize(const QSize &);
  binder.void_fun<const QSize &, &QComboBox::setIconSize>("setIconSize").create();
  // bool isEditable() const;
  binder.fun<bool, &QComboBox::isEditable>("isEditable").create();
  // void setEditable(bool);
  binder.void_fun<bool, &QComboBox::setEditable>("setEditable").create();
  // void setLineEdit(QLineEdit *);
  /// TODO: void setLineEdit(QLineEdit *);
  // QLineEdit * lineEdit() const;
  /// TODO: QLineEdit * lineEdit() const;
  // void setValidator(const QValidator *);
  /// TODO: void setValidator(const QValidator *);
  // const QValidator * validator() const;
  /// TODO: const QValidator * validator() const;
  // void setCompleter(QCompleter *);
  /// TODO: void setCompleter(QCompleter *);
  // QCompleter * completer() const;
  /// TODO: QCompleter * completer() const;
  // QAbstractItemDelegate * itemDelegate() const;
  /// TODO: QAbstractItemDelegate * itemDelegate() const;
  // void setItemDelegate(QAbstractItemDelegate *);
  /// TODO: void setItemDelegate(QAbstractItemDelegate *);
  // QAbstractItemModel * model() const;
  /// TODO: QAbstractItemModel * model() const;
  // void setModel(QAbstractItemModel *);
  /// TODO: void setModel(QAbstractItemModel *);
  // QModelIndex rootModelIndex() const;
  /// TODO: QModelIndex rootModelIndex() const;
  // void setRootModelIndex(const QModelIndex &);
  /// TODO: void setRootModelIndex(const QModelIndex &);
  // int modelColumn() const;
  binder.fun<int, &QComboBox::modelColumn>("modelColumn").create();
  // void setModelColumn(int);
  binder.void_fun<int, &QComboBox::setModelColumn>("setModelColumn").create();
  // int currentIndex() const;
  binder.fun<int, &QComboBox::currentIndex>("currentIndex").create();
  // QString currentText() const;
  binder.fun<QString, &QComboBox::currentText>("currentText").create();
  // QVariant currentData(int) const;
  binder.fun<QVariant, int, &QComboBox::currentData>("currentData")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), int(Qt::UserRole))).create();
  // QString itemText(int) const;
  binder.fun<QString, int, &QComboBox::itemText>("itemText").create();
  // QIcon itemIcon(int) const;
  binder.fun<QIcon, int, &QComboBox::itemIcon>("itemIcon").create();
  // QVariant itemData(int, int) const;
  binder.fun<QVariant, int, int, &QComboBox::itemData>("itemData")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), int(Qt::UserRole))).create();
  // void addItem(const QString &, const QVariant &);
  binder.void_fun<const QString &, const QVariant &, &QComboBox::addItem>("addItem")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), QVariant())).create();
  // void addItem(const QIcon &, const QString &, const QVariant &);
  binder.void_fun<const QIcon &, const QString &, const QVariant &, &QComboBox::addItem>("addItem")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), QVariant())).create();
  // void addItems(const QStringList &);
  /// TODO: void addItems(const QStringList &);
  // void insertItem(int, const QString &, const QVariant &);
  binder.void_fun<int, const QString &, const QVariant &, &QComboBox::insertItem>("insertItem")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), QVariant())).create();
  // void insertItem(int, const QIcon &, const QString &, const QVariant &);
  binder.void_fun<int, const QIcon &, const QString &, const QVariant &, &QComboBox::insertItem>("insertItem")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), QVariant())).create();
  // void insertItems(int, const QStringList &);
  /// TODO: void insertItems(int, const QStringList &);
  // void insertSeparator(int);
  binder.void_fun<int, &QComboBox::insertSeparator>("insertSeparator").create();
  // void removeItem(int);
  binder.void_fun<int, &QComboBox::removeItem>("removeItem").create();
  // void setItemText(int, const QString &);
  binder.void_fun<int, const QString &, &QComboBox::setItemText>("setItemText").create();
  // void setItemIcon(int, const QIcon &);
  binder.void_fun<int, const QIcon &, &QComboBox::setItemIcon>("setItemIcon").create();
  // void setItemData(int, const QVariant &, int);
  binder.void_fun<int, const QVariant &, int, &QComboBox::setItemData>("setItemData")
    .addDefaultArgument(binding::default_argument(combo_box.engine(), int(Qt::UserRole))).create();
  // QAbstractItemView * view() const;
  /// TODO: QAbstractItemView * view() const;
  // void setView(QAbstractItemView *);
  /// TODO: void setView(QAbstractItemView *);
  // QSize sizeHint() const;
  binder.fun<QSize, &QComboBox::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QComboBox::minimumSizeHint>("minimumSizeHint").create();
  // void showPopup();
  binder.void_fun<&QComboBox::showPopup>("showPopup").create();
  // void hidePopup();
  binder.void_fun<&QComboBox::hidePopup>("hidePopup").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.fun<QVariant, Qt::InputMethodQuery, &QComboBox::inputMethodQuery>("inputMethodQuery").create();
  // QVariant inputMethodQuery(Qt::InputMethodQuery, const QVariant &) const;
  binder.fun<QVariant, Qt::InputMethodQuery, const QVariant &, &QComboBox::inputMethodQuery>("inputMethodQuery").create();
  // void clear();
  binder.void_fun<&QComboBox::clear>("clear").create();
  // void clearEditText();
  binder.void_fun<&QComboBox::clearEditText>("clearEditText").create();
  // void setEditText(const QString &);
  binder.void_fun<const QString &, &QComboBox::setEditText>("setEditText").create();
  // void setCurrentIndex(int);
  binder.void_fun<int, &QComboBox::setCurrentIndex>("setCurrentIndex").create();
  // void setCurrentText(const QString &);
  binder.void_fun<const QString &, &QComboBox::setCurrentText>("setCurrentText").create();
  // void editTextChanged(const QString &);
  binder.sigs().add<const QString &>("editTextChanged", "editTextChanged(const QString &)");
  // void activated(int);
  binder.sigs().add<int>("activated", "activated(int)");
  // void activated(const QString &);
  binder.sigs().add<const QString &>("activated", "activated(const QString &)");
  // void highlighted(int);
  binder.sigs().add<int>("highlighted", "highlighted(int)");
  // void highlighted(const QString &);
  binder.sigs().add<const QString &>("highlighted", "highlighted(const QString &)");
  // void currentIndexChanged(int);
  binder.sigs().add<int>("currentIndexChanged", "currentIndexChanged(int)");
  // void currentIndexChanged(const QString &);
  binder.sigs().add<const QString &>("currentIndexChanged", "currentIndexChanged(const QString &)");
  // void currentTextChanged(const QString &);
  binder.sigs().add<const QString &>("currentTextChanged", "currentTextChanged(const QString &)");

  combo_box.engine()->registerQtType(&QComboBox::staticMetaObject, combo_box.id());
}


void register_combobox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_combo_box_class(ns);
  binding::Namespace binder{ ns };

  // QComboBox& newComboBox(QWidget*);
  NewFunction(binder).add<QComboBox, QWidget*>("newComboBox");
}

