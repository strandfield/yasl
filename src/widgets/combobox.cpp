// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/combobox.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
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
  binder.ctors().add<QWidget *>();
  // ~QComboBox();
  binder.add_dtor();
  // int maxVisibleItems() const;
  binder.add_fun<int, &QComboBox::maxVisibleItems>("maxVisibleItems");
  // void setMaxVisibleItems(int);
  binder.add_void_fun<int, &QComboBox::setMaxVisibleItems>("setMaxVisibleItems");
  // int count() const;
  binder.add_fun<int, &QComboBox::count>("count");
  // void setMaxCount(int);
  binder.add_void_fun<int, &QComboBox::setMaxCount>("setMaxCount");
  // int maxCount() const;
  binder.add_fun<int, &QComboBox::maxCount>("maxCount");
  // bool autoCompletion() const;
  binder.add_fun<bool, &QComboBox::autoCompletion>("autoCompletion");
  // void setAutoCompletion(bool);
  binder.add_void_fun<bool, &QComboBox::setAutoCompletion>("setAutoCompletion");
  // Qt::CaseSensitivity autoCompletionCaseSensitivity() const;
  binder.add_fun<Qt::CaseSensitivity, &QComboBox::autoCompletionCaseSensitivity>("autoCompletionCaseSensitivity");
  // void setAutoCompletionCaseSensitivity(Qt::CaseSensitivity);
  binder.add_void_fun<Qt::CaseSensitivity, &QComboBox::setAutoCompletionCaseSensitivity>("setAutoCompletionCaseSensitivity");
  // bool duplicatesEnabled() const;
  binder.add_fun<bool, &QComboBox::duplicatesEnabled>("duplicatesEnabled");
  // void setDuplicatesEnabled(bool);
  binder.add_void_fun<bool, &QComboBox::setDuplicatesEnabled>("setDuplicatesEnabled");
  // void setFrame(bool);
  binder.add_void_fun<bool, &QComboBox::setFrame>("setFrame");
  // bool hasFrame() const;
  binder.add_fun<bool, &QComboBox::hasFrame>("hasFrame");
  // int findText(const QString &, Qt::MatchFlags) const;
  /// TODO: int findText(const QString &, Qt::MatchFlags) const;
  // int findData(const QVariant &, int, Qt::MatchFlags) const;
  /// TODO: int findData(const QVariant &, int, Qt::MatchFlags) const;
  // QComboBox::InsertPolicy insertPolicy() const;
  binder.add_fun<QComboBox::InsertPolicy, &QComboBox::insertPolicy>("insertPolicy");
  // void setInsertPolicy(QComboBox::InsertPolicy);
  binder.add_void_fun<QComboBox::InsertPolicy, &QComboBox::setInsertPolicy>("setInsertPolicy");
  // QComboBox::SizeAdjustPolicy sizeAdjustPolicy() const;
  binder.add_fun<QComboBox::SizeAdjustPolicy, &QComboBox::sizeAdjustPolicy>("sizeAdjustPolicy");
  // void setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy);
  binder.add_void_fun<QComboBox::SizeAdjustPolicy, &QComboBox::setSizeAdjustPolicy>("setSizeAdjustPolicy");
  // int minimumContentsLength() const;
  binder.add_fun<int, &QComboBox::minimumContentsLength>("minimumContentsLength");
  // void setMinimumContentsLength(int);
  binder.add_void_fun<int, &QComboBox::setMinimumContentsLength>("setMinimumContentsLength");
  // QSize iconSize() const;
  binder.add_fun<QSize, &QComboBox::iconSize>("iconSize");
  // void setIconSize(const QSize &);
  binder.add_void_fun<const QSize &, &QComboBox::setIconSize>("setIconSize");
  // bool isEditable() const;
  binder.add_fun<bool, &QComboBox::isEditable>("isEditable");
  // void setEditable(bool);
  binder.add_void_fun<bool, &QComboBox::setEditable>("setEditable");
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
  binder.add_fun<int, &QComboBox::modelColumn>("modelColumn");
  // void setModelColumn(int);
  binder.add_void_fun<int, &QComboBox::setModelColumn>("setModelColumn");
  // int currentIndex() const;
  binder.add_fun<int, &QComboBox::currentIndex>("currentIndex");
  // QString currentText() const;
  binder.add_fun<QString, &QComboBox::currentText>("currentText");
  // QVariant currentData(int) const;
  binder.add_fun<QVariant, int, &QComboBox::currentData>("currentData");
  // QString itemText(int) const;
  binder.add_fun<QString, int, &QComboBox::itemText>("itemText");
  // QIcon itemIcon(int) const;
  binder.add_fun<QIcon, int, &QComboBox::itemIcon>("itemIcon");
  // QVariant itemData(int, int) const;
  binder.add_fun<QVariant, int, int, &QComboBox::itemData>("itemData");
  // void addItem(const QString &, const QVariant &);
  binder.add_void_fun<const QString &, const QVariant &, &QComboBox::addItem>("addItem");
  // void addItem(const QIcon &, const QString &, const QVariant &);
  binder.add_void_fun<const QIcon &, const QString &, const QVariant &, &QComboBox::addItem>("addItem");
  // void addItems(const QStringList &);
  /// TODO: void addItems(const QStringList &);
  // void insertItem(int, const QString &, const QVariant &);
  binder.add_void_fun<int, const QString &, const QVariant &, &QComboBox::insertItem>("insertItem");
  // void insertItem(int, const QIcon &, const QString &, const QVariant &);
  binder.add_void_fun<int, const QIcon &, const QString &, const QVariant &, &QComboBox::insertItem>("insertItem");
  // void insertItems(int, const QStringList &);
  /// TODO: void insertItems(int, const QStringList &);
  // void insertSeparator(int);
  binder.add_void_fun<int, &QComboBox::insertSeparator>("insertSeparator");
  // void removeItem(int);
  binder.add_void_fun<int, &QComboBox::removeItem>("removeItem");
  // void setItemText(int, const QString &);
  binder.add_void_fun<int, const QString &, &QComboBox::setItemText>("setItemText");
  // void setItemIcon(int, const QIcon &);
  binder.add_void_fun<int, const QIcon &, &QComboBox::setItemIcon>("setItemIcon");
  // void setItemData(int, const QVariant &, int);
  binder.add_void_fun<int, const QVariant &, int, &QComboBox::setItemData>("setItemData");
  // QAbstractItemView * view() const;
  /// TODO: QAbstractItemView * view() const;
  // void setView(QAbstractItemView *);
  /// TODO: void setView(QAbstractItemView *);
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QComboBox::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QComboBox::minimumSizeHint>("minimumSizeHint");
  // void showPopup();
  binder.add_void_fun<&QComboBox::showPopup>("showPopup");
  // void hidePopup();
  binder.add_void_fun<&QComboBox::hidePopup>("hidePopup");
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.add_fun<QVariant, Qt::InputMethodQuery, &QComboBox::inputMethodQuery>("inputMethodQuery");
  // QVariant inputMethodQuery(Qt::InputMethodQuery, const QVariant &) const;
  binder.add_fun<QVariant, Qt::InputMethodQuery, const QVariant &, &QComboBox::inputMethodQuery>("inputMethodQuery");
  // void clear();
  binder.add_void_fun<&QComboBox::clear>("clear");
  // void clearEditText();
  binder.add_void_fun<&QComboBox::clearEditText>("clearEditText");
  // void setEditText(const QString &);
  binder.add_void_fun<const QString &, &QComboBox::setEditText>("setEditText");
  // void setCurrentIndex(int);
  binder.add_void_fun<int, &QComboBox::setCurrentIndex>("setCurrentIndex");
  // void setCurrentText(const QString &);
  binder.add_void_fun<const QString &, &QComboBox::setCurrentText>("setCurrentText");
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

}

