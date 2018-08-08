// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "moduletreewidget.h"

#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/function.h"
#include "project/module.h"
#include "project/namespace.h"

#include <QKeyEvent>
#include <QStyledItemDelegate>

class ItemDelegate : public QStyledItemDelegate
{
public:
  ItemDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

  virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
  {
    QTreeWidgetItem *item = static_cast<QTreeWidgetItem*>(index.internalPointer());
    NodeRef node = item->data(0, ModuleTreeWidget::ProjectNodeRole).value<NodeRef>();
    if (node->is<Function>() && index.column() == 0)
      return nullptr;
    return QStyledItemDelegate::createEditor(parent, option, index);
  }

};


ModuleTreeWidget::ModuleTreeWidget(const ProjectRef & pro)
  : mProject(pro)
  , mShowCheckboxes(false)
{
  setColumnCount(6);
  setHeaderHidden(false);
  clearHeaders();
  setSelectionBehavior(QAbstractItemView::SelectRows);
  setSelectionMode(QAbstractItemView::ExtendedSelection);
  setItemDelegate(new ItemDelegate(this));

  if(pro != nullptr)
    fillTreeWidget(pro);

  setShowCheckboxes(true);

  connect(this, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(updateItem(QTreeWidgetItem*, int)));
  connect(this, SIGNAL(collapsed(const QModelIndex&)), this, SLOT(resizeColumnsAuto()));
  connect(this, SIGNAL(expanded(const QModelIndex&)), this, SLOT(resizeColumnsAuto()));
  connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(updateHeaders(QTreeWidgetItem*, int)));
  connect(this, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(clearHeaders()));
}

static void handle_checkboxes(QTreeWidgetItem *item, bool on)
{
  NodeRef node = item->data(0, ModuleTreeWidget::ProjectNodeRole).value<NodeRef>();
 
  if (on)
  {
    item->setCheckState(0, node->checkState);
    item->setData(0, Qt::ForegroundRole, QVariant());
  }
  else
  {
    item->setData(0, Qt::CheckStateRole, QVariant());
    if (node->checkState == Qt::Unchecked)
      item->setData(0, Qt::ForegroundRole, QVariant::fromValue(QBrush(Qt::gray)));
    else
      item->setData(0, Qt::ForegroundRole, QVariant::fromValue(QBrush(Qt::black)));
  }

  for (int i(0); i < item->childCount(); ++i)
    handle_checkboxes(item->child(i), on);
}

void ModuleTreeWidget::setShowCheckboxes(bool visible)
{
  for (int i(0); i < topLevelItemCount(); ++i)
    handle_checkboxes(topLevelItem(i), visible);
}

void ModuleTreeWidget::setProject(const ProjectRef & pro)
{
  mProject = pro;
  fillTreeWidget(pro);
}

void ModuleTreeWidget::fetchNewNodes()
{
  for (int i(0); i < topLevelItemCount(); ++i)
    fetchNewNodes(topLevelItem(i));

  for (int i(topLevelItemCount()); i < mProject->modules.size(); ++i)
    addTopLevelItem(createItem(mProject->modules.at(i)));
}


void ModuleTreeWidget::keyPressEvent(QKeyEvent *e)
{
  if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace)
    removeSelectedRows();
  else if ((e->key() == Qt::Key_Up || e->key() == Qt::Key_Down) && e->modifiers() == Qt::CTRL)
    moveSelectedRow(e->key());
  else
    QTreeWidget::keyPressEvent(e);
}

void ModuleTreeWidget::removeSelectedRows()
{
  const QList<QTreeWidgetItem*> selecteds = selectedItems();
  for (auto item : selecteds)
  {
    QTreeWidgetItem *parent = item->parent();
    if (parent == nullptr)
      parent = invisibleRootItem();

    const int item_index = parent->indexOfChild(item);
    
    NodeRef node = parent->data(0, ProjectNodeRole).value<NodeRef>();
    if (node == nullptr)
    {
      mProject->modules.removeAt(item_index);
    }
    else if (node->is<Namespace>())
    {
      Namespace & ns = node->as<Namespace>();
      ns.elements.removeAt(item_index);
    }
    else if (node->is<Module>())
    {
      Module & mod = node->as<Module>();
      mod.elements.removeAt(item_index);
    }
    else if (node->is<Class>())
    {
      Class & cla = node->as<Class>();
      cla.elements.removeAt(item_index);
    }
    else if (node->is<Enum>())
    {
      Enum & enm = node->as<Enum>();
      enm.enumerators.removeAt(item_index);
    }

    parent->removeChild(item);
  }
}

void ModuleTreeWidget::moveSelectedRow(int k)
{
  const QList<QTreeWidgetItem*> selecteds = selectedItems();
  if (selecteds.size() != 1)
    return;

  QTreeWidgetItem *item = selecteds.first();
  QTreeWidgetItem *parent = item->parent();
  const int item_index = parent->indexOfChild(item);

  if (item_index == 0 && k == Qt::Key_Up)
    return;
  else if (item_index == parent->childCount() - 1 && k == Qt::Key_Down)
    return;

  NodeRef node = parent->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  if (k == Qt::Key_Up)
  {
    if (node->is<Class>())
      node->as<Class>().elements.swap(item_index, item_index - 1);
    else if (node->is<Namespace>())
      node->as<Namespace>().elements.swap(item_index, item_index - 1);
    else if (node->is<Module>())
      node->as<Module>().elements.swap(item_index, item_index - 1);
    else if (node->is<Enum>())
      node->as<Enum>().enumerators.swap(item_index, item_index - 1);
    else
      throw std::runtime_error{ "ModuleTreeWidget::moveSelectedRow : Not implemented" };

    QTreeWidgetItem *sibling = parent->takeChild(item_index - 1);
    parent->insertChild(item_index, sibling);
  }
  else if (k == Qt::Key_Down)
  {
    if (node->is<Class>())
      node->as<Class>().elements.swap(item_index, item_index + 1);
    else if (node->is<Namespace>())
      node->as<Namespace>().elements.swap(item_index, item_index + 1);
    else if (node->is<Module>())
      node->as<Module>().elements.swap(item_index, item_index + 1);
    else if (node->is<Enum>())
      node->as<Enum>().enumerators.swap(item_index, item_index + 1);
    else
      throw std::runtime_error{ "ModuleTreeWidget::moveSelectedRow : Not implemented" };

    QTreeWidgetItem *sibling = parent->takeChild(item_index + 1);
    parent->insertChild(item_index, sibling);
  }
}

void ModuleTreeWidget::fetchNewNodes(QTreeWidgetItem *item)
{
  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  if (node->is<Module>())
  {
    Module & m = node->as<Module>();

    for (int i(item->childCount()); i < m.elements.size(); ++i)
      item->addChild(createItem(m.elements.at(i)));
  }
  else if (node->is<File>())
  {
    File & f = node->as<File>();

    for (int i(item->childCount()); i < f.elements.size(); ++i)
      item->addChild(createItem(f.elements.at(i)));
  }
  else if (node->is<Namespace>())
  {
    Namespace & ns = node->as<Namespace>();

    for (int i(item->childCount()); i < ns.elements.size(); ++i)
      item->addChild(createItem(ns.elements.at(i)));
  }
  else if (node->is<Class>())
  {
    Class & c = node->as<Class>();

    for (int i(item->childCount()); i < c.elements.size(); ++i)
      item->addChild(createItem(c.elements.at(i)));
  }
  else if (node->is<Enum>())
  {
    Enum & e = node->as<Enum>();

    for (int i(item->childCount()); i < e.enumerators.size(); ++i)
      item->addChild(createItem(e.enumerators.at(i)));
  }
}

void ModuleTreeWidget::fillTreeWidget(const ProjectRef & pro)
{
  clear();

  for (const auto & item : pro->modules)
    fill(invisibleRootItem(), item);
}

QTreeWidgetItem* ModuleTreeWidget::createItem(const NodeRef & node)
{
  QTreeWidgetItem *item = new QTreeWidgetItem(QStringList{ node->displayedName() });
  item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
  item->setData(0, ProjectNodeRole, QVariant::fromValue<NodeRef>(node));

  if (node->is<Module>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/namespace.png"));

    Module & m = node->as<Module>();
    for (const auto & n : m.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<File>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/namespace.png"));
    File & f = node->as<File>();
    for (const auto & n : f.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Namespace>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/namespace.png"));
    Namespace & ns = node->as<Namespace>();
    for (const auto & n : ns.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Class>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/class.png"));
    Class & c = node->as<Class>();
    for (const auto & n : c.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Enum>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/enum.png"));
    auto e = qSharedPointerCast<Enum>(node);
    for (const auto & n : e->enumerators)
      item->addChild(createItem(n));
  }
  else if (node->is<Enumerator>())
  {
    item->setIcon(0, QIcon(":/assets/enumerator.png"));
  }
  else if (node->is<Function>())
  {
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    item->setIcon(0, QIcon(":/assets/func.png"));
    item->setText(1, Function::serialize(node->as<Function>().bindingMethod));
    item->setText(2, node->as<Function>().rename);
  }

  handle_checkboxes(item, mShowCheckboxes);
  return item;
}

void ModuleTreeWidget::fill(QTreeWidgetItem *parent, const NodeRef & node)
{
  QTreeWidgetItem *item = createItem(node);
  parent->addChild(item);
}


void ModuleTreeWidget::updateItem(QTreeWidgetItem *item, int column)
{
  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  node->checkState = item->checkState(0);

  if (node->is<Namespace>() || node->is<Module>() || node->is<Class>() || node->is<Enum>())
  {
    node->name = item->text(0);
  }

  if (node->is<Function>())
  {
    node->as<Function>().bindingMethod = Function::deserialize<Function::BindingMethod>(item->text(1));
    node->as<Function>().rename = item->text(2);
  }

  updateCheckState(item);
}

void ModuleTreeWidget::updateCheckState(QTreeWidgetItem *item)
{
  auto root = invisibleRootItem();
  if (item->parent() != root && item->parent() != nullptr)
  {
    if (item->parent()->childCount() == 1)
      item->parent()->setCheckState(0, item->checkState(0));
    else
    {
      bool one_checked = false;
      bool one_unchecked = false;
      for (int i(0); i < item->parent()->childCount(); ++i)
      {
        if (item->parent()->child(i)->checkState(0) == Qt::Checked)
          one_checked = true;
        else if (item->parent()->child(i)->checkState(0) == Qt::Unchecked)
          one_unchecked = true;
        else if (item->parent()->child(i)->checkState(0) == Qt::PartiallyChecked)
        {
          one_checked = true, one_unchecked = true;
          break;
        }
      }

      if (one_checked && one_unchecked)
        item->parent()->setCheckState(0, Qt::PartiallyChecked);
      else if (one_checked)
        item->parent()->setCheckState(0, Qt::Checked);
      else
        item->parent()->setCheckState(0, Qt::Unchecked);

    }
  }

  if (item->checkState(0) == Qt::Unchecked)
  {
    for (int i(0); i < item->childCount(); ++i)
      item->child(i)->setCheckState(0, Qt::Unchecked);
  }
  else if (item->checkState(0) == Qt::Checked)
  {
    for (int i(0); i < item->childCount(); ++i)
      item->child(i)->setCheckState(0, Qt::Checked);
  }
}

void ModuleTreeWidget::resizeColumnsAuto()
{
  for (int i(0); i < columnCount(); ++i)
    resizeColumnToContents(i);
}

void ModuleTreeWidget::updateHeaders(QTreeWidgetItem *item, int column)
{
  if (item == nullptr)
    return clearHeaders();

  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (item == nullptr)
    return clearHeaders();

  if (node->is<Function>())
  {
    setHeaderLabels(QStringList() << "Function" << "binding" << "rename" << "" << "" << "");
  }
  else if (node->is<Class>())
  {
    setHeaderLabels(QStringList() << "Name" << "" << "" << "" << "" << "");
  }
  else if (node->is<Enum>())
  {
    setHeaderLabels(QStringList() << "Name" << "" << "" << "" << "" << "");
  }
  else if (node->is<Module>())
  {
    setHeaderLabels(QStringList() << "Name" << "" << "" << "" << "" << "");
  }
  else if (node->is<File>())
  {
    setHeaderLabels(QStringList() << "Name" << "" << "" << "" << "" << "");
  }
}

void ModuleTreeWidget::clearHeaders()
{
  setHeaderLabels(QStringList() << "" << "" << "" << "" << "" << "");
}