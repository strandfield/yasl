// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/combobox.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

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

  Enum insert_policy = combo_box.newEnum("InsertPolicy").setId(script::Type::QComboBoxInsertPolicy).get();

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

  Enum size_adjust_policy = combo_box.newEnum("SizeAdjustPolicy").setId(script::Type::QComboBoxSizeAdjustPolicy).get();

  size_adjust_policy.addValue("AdjustToContents", QComboBox::AdjustToContents);
  size_adjust_policy.addValue("AdjustToContentsOnFirstShow", QComboBox::AdjustToContentsOnFirstShow);
  size_adjust_policy.addValue("AdjustToMinimumContentsLength", QComboBox::AdjustToMinimumContentsLength);
  size_adjust_policy.addValue("AdjustToMinimumContentsLengthWithIcon", QComboBox::AdjustToMinimumContentsLengthWithIcon);
}


static void register_combo_box_class(script::Namespace ns)
{
  using namespace script;

  Class combo_box = ns.newClass("ComboBox").setId(script::Type::QComboBox)
    .setBase(script::Type::QWidget).get();

  register_combo_box_insert_policy_enum(combo_box);
  register_combo_box_size_adjust_policy_enum(combo_box);

  // QComboBox(QWidget *);
  bind::constructor<QComboBox, QWidget *>(combo_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QComboBox();
  bind::destructor<QComboBox>(combo_box).create();
  // int maxVisibleItems() const;
  bind::member_function<QComboBox, int, &QComboBox::maxVisibleItems>(combo_box, "maxVisibleItems").create();
  // void setMaxVisibleItems(int);
  bind::void_member_function<QComboBox, int, &QComboBox::setMaxVisibleItems>(combo_box, "setMaxVisibleItems").create();
  // int count() const;
  bind::member_function<QComboBox, int, &QComboBox::count>(combo_box, "count").create();
  // void setMaxCount(int);
  bind::void_member_function<QComboBox, int, &QComboBox::setMaxCount>(combo_box, "setMaxCount").create();
  // int maxCount() const;
  bind::member_function<QComboBox, int, &QComboBox::maxCount>(combo_box, "maxCount").create();
  // bool autoCompletion() const;
  bind::member_function<QComboBox, bool, &QComboBox::autoCompletion>(combo_box, "autoCompletion").create();
  // void setAutoCompletion(bool);
  bind::void_member_function<QComboBox, bool, &QComboBox::setAutoCompletion>(combo_box, "setAutoCompletion").create();
  // Qt::CaseSensitivity autoCompletionCaseSensitivity() const;
  bind::member_function<QComboBox, Qt::CaseSensitivity, &QComboBox::autoCompletionCaseSensitivity>(combo_box, "autoCompletionCaseSensitivity").create();
  // void setAutoCompletionCaseSensitivity(Qt::CaseSensitivity);
  bind::void_member_function<QComboBox, Qt::CaseSensitivity, &QComboBox::setAutoCompletionCaseSensitivity>(combo_box, "setAutoCompletionCaseSensitivity").create();
  // bool duplicatesEnabled() const;
  bind::member_function<QComboBox, bool, &QComboBox::duplicatesEnabled>(combo_box, "duplicatesEnabled").create();
  // void setDuplicatesEnabled(bool);
  bind::void_member_function<QComboBox, bool, &QComboBox::setDuplicatesEnabled>(combo_box, "setDuplicatesEnabled").create();
  // void setFrame(bool);
  bind::void_member_function<QComboBox, bool, &QComboBox::setFrame>(combo_box, "setFrame").create();
  // bool hasFrame() const;
  bind::member_function<QComboBox, bool, &QComboBox::hasFrame>(combo_box, "hasFrame").create();
  // int findText(const QString &, Qt::MatchFlags) const;
  /// TODO: int findText(const QString &, Qt::MatchFlags) const;
  // int findData(const QVariant &, int, Qt::MatchFlags) const;
  /// TODO: int findData(const QVariant &, int, Qt::MatchFlags) const;
  // QComboBox::InsertPolicy insertPolicy() const;
  bind::member_function<QComboBox, QComboBox::InsertPolicy, &QComboBox::insertPolicy>(combo_box, "insertPolicy").create();
  // void setInsertPolicy(QComboBox::InsertPolicy);
  bind::void_member_function<QComboBox, QComboBox::InsertPolicy, &QComboBox::setInsertPolicy>(combo_box, "setInsertPolicy").create();
  // QComboBox::SizeAdjustPolicy sizeAdjustPolicy() const;
  bind::member_function<QComboBox, QComboBox::SizeAdjustPolicy, &QComboBox::sizeAdjustPolicy>(combo_box, "sizeAdjustPolicy").create();
  // void setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy);
  bind::void_member_function<QComboBox, QComboBox::SizeAdjustPolicy, &QComboBox::setSizeAdjustPolicy>(combo_box, "setSizeAdjustPolicy").create();
  // int minimumContentsLength() const;
  bind::member_function<QComboBox, int, &QComboBox::minimumContentsLength>(combo_box, "minimumContentsLength").create();
  // void setMinimumContentsLength(int);
  bind::void_member_function<QComboBox, int, &QComboBox::setMinimumContentsLength>(combo_box, "setMinimumContentsLength").create();
  // QSize iconSize() const;
  bind::member_function<QComboBox, QSize, &QComboBox::iconSize>(combo_box, "iconSize").create();
  // void setIconSize(const QSize &);
  bind::void_member_function<QComboBox, const QSize &, &QComboBox::setIconSize>(combo_box, "setIconSize").create();
  // bool isEditable() const;
  bind::member_function<QComboBox, bool, &QComboBox::isEditable>(combo_box, "isEditable").create();
  // void setEditable(bool);
  bind::void_member_function<QComboBox, bool, &QComboBox::setEditable>(combo_box, "setEditable").create();
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
  bind::member_function<QComboBox, int, &QComboBox::modelColumn>(combo_box, "modelColumn").create();
  // void setModelColumn(int);
  bind::void_member_function<QComboBox, int, &QComboBox::setModelColumn>(combo_box, "setModelColumn").create();
  // int currentIndex() const;
  bind::member_function<QComboBox, int, &QComboBox::currentIndex>(combo_box, "currentIndex").create();
  // QString currentText() const;
  bind::member_function<QComboBox, QString, &QComboBox::currentText>(combo_box, "currentText").create();
  // QVariant currentData(int) const;
  bind::member_function<QComboBox, QVariant, int, &QComboBox::currentData>(combo_box, "currentData")
    .apply(bind::default_arguments(int(Qt::UserRole))).create();
  // QString itemText(int) const;
  bind::member_function<QComboBox, QString, int, &QComboBox::itemText>(combo_box, "itemText").create();
  // QIcon itemIcon(int) const;
  bind::member_function<QComboBox, QIcon, int, &QComboBox::itemIcon>(combo_box, "itemIcon").create();
  // QVariant itemData(int, int) const;
  bind::member_function<QComboBox, QVariant, int, int, &QComboBox::itemData>(combo_box, "itemData")
    .apply(bind::default_arguments(int(Qt::UserRole))).create();
  // void addItem(const QString &, const QVariant &);
  bind::void_member_function<QComboBox, const QString &, const QVariant &, &QComboBox::addItem>(combo_box, "addItem")
    .apply(bind::default_arguments(QVariant())).create();
  // void addItem(const QIcon &, const QString &, const QVariant &);
  bind::void_member_function<QComboBox, const QIcon &, const QString &, const QVariant &, &QComboBox::addItem>(combo_box, "addItem")
    .apply(bind::default_arguments(QVariant())).create();
  // void addItems(const QStringList &);
  /// TODO: void addItems(const QStringList &);
  // void insertItem(int, const QString &, const QVariant &);
  bind::void_member_function<QComboBox, int, const QString &, const QVariant &, &QComboBox::insertItem>(combo_box, "insertItem")
    .apply(bind::default_arguments(QVariant())).create();
  // void insertItem(int, const QIcon &, const QString &, const QVariant &);
  bind::void_member_function<QComboBox, int, const QIcon &, const QString &, const QVariant &, &QComboBox::insertItem>(combo_box, "insertItem")
    .apply(bind::default_arguments(QVariant())).create();
  // void insertItems(int, const QStringList &);
  /// TODO: void insertItems(int, const QStringList &);
  // void insertSeparator(int);
  bind::void_member_function<QComboBox, int, &QComboBox::insertSeparator>(combo_box, "insertSeparator").create();
  // void removeItem(int);
  bind::void_member_function<QComboBox, int, &QComboBox::removeItem>(combo_box, "removeItem").create();
  // void setItemText(int, const QString &);
  bind::void_member_function<QComboBox, int, const QString &, &QComboBox::setItemText>(combo_box, "setItemText").create();
  // void setItemIcon(int, const QIcon &);
  bind::void_member_function<QComboBox, int, const QIcon &, &QComboBox::setItemIcon>(combo_box, "setItemIcon").create();
  // void setItemData(int, const QVariant &, int);
  bind::void_member_function<QComboBox, int, const QVariant &, int, &QComboBox::setItemData>(combo_box, "setItemData")
    .apply(bind::default_arguments(int(Qt::UserRole))).create();
  // QAbstractItemView * view() const;
  /// TODO: QAbstractItemView * view() const;
  // void setView(QAbstractItemView *);
  /// TODO: void setView(QAbstractItemView *);
  // QSize sizeHint() const;
  bind::member_function<QComboBox, QSize, &QComboBox::sizeHint>(combo_box, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QComboBox, QSize, &QComboBox::minimumSizeHint>(combo_box, "minimumSizeHint").create();
  // void showPopup();
  bind::void_member_function<QComboBox, &QComboBox::showPopup>(combo_box, "showPopup").create();
  // void hidePopup();
  bind::void_member_function<QComboBox, &QComboBox::hidePopup>(combo_box, "hidePopup").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  bind::member_function<QComboBox, QVariant, Qt::InputMethodQuery, &QComboBox::inputMethodQuery>(combo_box, "inputMethodQuery").create();
  // QVariant inputMethodQuery(Qt::InputMethodQuery, const QVariant &) const;
  bind::member_function<QComboBox, QVariant, Qt::InputMethodQuery, const QVariant &, &QComboBox::inputMethodQuery>(combo_box, "inputMethodQuery").create();
  // void clear();
  bind::void_member_function<QComboBox, &QComboBox::clear>(combo_box, "clear").create();
  // void clearEditText();
  bind::void_member_function<QComboBox, &QComboBox::clearEditText>(combo_box, "clearEditText").create();
  // void setEditText(const QString &);
  bind::void_member_function<QComboBox, const QString &, &QComboBox::setEditText>(combo_box, "setEditText").create();
  // void setCurrentIndex(int);
  bind::void_member_function<QComboBox, int, &QComboBox::setCurrentIndex>(combo_box, "setCurrentIndex").create();
  // void setCurrentText(const QString &);
  bind::void_member_function<QComboBox, const QString &, &QComboBox::setCurrentText>(combo_box, "setCurrentText").create();
  // void editTextChanged(const QString &);
  bind::signal<QComboBox, const QString &>(combo_box, "editTextChanged", "editTextChanged(const QString &)");
  // void activated(int);
  bind::signal<QComboBox, int>(combo_box, "activated", "activated(int)");
  // void activated(const QString &);
  bind::signal<QComboBox, const QString &>(combo_box, "activated", "activated(const QString &)");
  // void highlighted(int);
  bind::signal<QComboBox, int>(combo_box, "highlighted", "highlighted(int)");
  // void highlighted(const QString &);
  bind::signal<QComboBox, const QString &>(combo_box, "highlighted", "highlighted(const QString &)");
  // void currentIndexChanged(int);
  bind::signal<QComboBox, int>(combo_box, "currentIndexChanged", "currentIndexChanged(int)");
  // void currentIndexChanged(const QString &);
  bind::signal<QComboBox, const QString &>(combo_box, "currentIndexChanged", "currentIndexChanged(const QString &)");
  // void currentTextChanged(const QString &);
  bind::signal<QComboBox, const QString &>(combo_box, "currentTextChanged", "currentTextChanged(const QString &)");

  bind::link(combo_box, &QComboBox::staticMetaObject);
}


void register_combobox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_combo_box_class(ns);

  // QComboBox& newComboBox(QWidget*);
  bind::new_function<QComboBox, QWidget*>(ns, "newComboBox");
}

