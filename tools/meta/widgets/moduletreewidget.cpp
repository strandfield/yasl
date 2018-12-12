// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "moduletreewidget.h"

#include "dialogs/newfunctiondialog.h"

#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/function.h"
#include "project/module.h"
#include "project/namespace.h"
#include "project/statement.h"

#include "widgets/editors/classnodeeditor.h"
#include "widgets/editors/enumnodeeditor.h"
#include "widgets/editors/filenodeeditor.h"
#include "widgets/editors/functionnodeeditor.h"
#include "widgets/editors/namespacenodeeditor.h"

#include <QAction>
#include <QKeyEvent>
#include <QMenu>
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
      return new FunctionNodeEditor(qSharedPointerCast<Function>(node), parent);
    else if (node->is<File>() && index.column() == 0)
      return new FileNodeEditor(qSharedPointerCast<File>(node), parent);
    else if (node->is<Namespace>() && index.column() == 0)
      return new NamespaceNodeEditor(qSharedPointerCast<Namespace>(node), parent);
    else if (node->is<Class>() && index.column() == 0)
      return new ClassNodeEditor(qSharedPointerCast<Class>(node), parent);
    else if (node->is<Enum>() && index.column() == 0)
      return new EnumNodeEditor(qSharedPointerCast<Enum>(node), parent);
    return QStyledItemDelegate::createEditor(parent, option, index);
  }

  void setEditorData(QWidget *editor, const QModelIndex & index) const override
  {
    QTreeWidgetItem *item = static_cast<QTreeWidgetItem*>(index.internalPointer());
    NodeRef node = item->data(0, ModuleTreeWidget::ProjectNodeRole).value<NodeRef>();

    EnumNodeEditor *enmedit = qobject_cast<EnumNodeEditor*>(editor);
    FileNodeEditor *fileedit = qobject_cast<FileNodeEditor*>(editor);
    FunctionNodeEditor *funedit = qobject_cast<FunctionNodeEditor*>(editor);
    ClassNodeEditor *classedit = qobject_cast<ClassNodeEditor*>(editor);
    NamespaceNodeEditor *nsedit = qobject_cast<NamespaceNodeEditor*>(editor);
    if (funedit != nullptr)
    {
      funedit->read(qSharedPointerCast<Function>(node));
      return;
    }
    else if (fileedit != nullptr)
    {
      fileedit->read(qSharedPointerCast<File>(node));
      return;
    }
    else if (classedit != nullptr)
    {
      classedit->read(qSharedPointerCast<Class>(node));
      return;
    }
    else if (enmedit != nullptr)
    {
      enmedit->read(qSharedPointerCast<Enum>(node));
      return;
    }
    else if (nsedit != nullptr)
    {
      nsedit->read(qSharedPointerCast<Namespace>(node));
      return;
    }
    else
    {
      return QStyledItemDelegate::setEditorData(editor, index);
    }
  }

  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex & index) const override
  {
    QTreeWidgetItem *item = static_cast<QTreeWidgetItem*>(index.internalPointer());
    NodeRef node = item->data(0, ModuleTreeWidget::ProjectNodeRole).value<NodeRef>();

    AbstractNodeEditor *nodeedit = qobject_cast<AbstractNodeEditor*>(editor);
    if (nodeedit != nullptr)
    {
      nodeedit->write();
      item->setText(0, nodeedit->getNode()->display());
      return;
    }
    else
    {
      return QStyledItemDelegate::setModelData(editor, model, index);
    }
  }

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const override
  {
    editor->setGeometry(option.rect);
  }
};


ModuleTreeWidget::ModuleTreeWidget(const ProjectRef & pro)
  : mProject(pro)
  , mShowCheckboxes(true)
{
  setColumnCount(1);
  setHeaderHidden(true);
  setSelectionBehavior(QAbstractItemView::SelectRows);
  setSelectionMode(QAbstractItemView::ExtendedSelection);
  setItemDelegate(new ItemDelegate(this));
  setContextMenuPolicy(Qt::CustomContextMenu);

  createContextMenus();

  if(pro != nullptr)
    fillTreeWidget(pro);

  setShowCheckboxes(true);

  connect(this, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(updateItem(QTreeWidgetItem*, int)));
  connect(this, SIGNAL(collapsed(const QModelIndex&)), this, SLOT(resizeColumnsAuto()));
  connect(this, SIGNAL(expanded(const QModelIndex&)), this, SLOT(resizeColumnsAuto()));
  connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(displayContextMenu(const QPoint &)));
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
  else if (e->key() == Qt::Key_N && e->modifiers() == Qt::CTRL)
    processCtrlN();
  else if (e->key() == Qt::Key_E && e->modifiers() == Qt::CTRL)
    processCtrlE();
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

void ModuleTreeWidget::processCtrlE()
{
  const QList<QTreeWidgetItem*> selecteds = selectedItems();
  if (selecteds.size() != 1)
    return;

  QTreeWidgetItem *item = selecteds.first();

  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  if (!node->is<Function>())
    return;

  auto *dialog = new NewFunctionDialog(qSharedPointerCast<Function>(node), this);
  int result = dialog->exec();
  dialog->deleteLater();
  if (result != QDialog::Accepted)
    return;

  dialog->sync();

  refreshItem(item);
}

void ModuleTreeWidget::processCtrlN()
{
  const QList<QTreeWidgetItem*> selecteds = selectedItems();
  if (selecteds.size() != 1)
    return;

  QTreeWidgetItem *item = selecteds.first();

  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  if (!node->is<Class>() && !node->is<Namespace>())
    return;

  auto *dialog = new NewFunctionDialog(this);
  int result = dialog->exec();
  dialog->deleteLater();
  if (result != QDialog::Accepted)
    return;

  dialog->sync();

  if(node->is<Class>())
    node->as<Class>().elements.append(dialog->function());
  else if (node->is<Namespace>())
    node->as<Namespace>().elements.append(dialog->function());

  fetchNewNodes();
}

void ModuleTreeWidget::refreshItem(QTreeWidgetItem* item)
{
  NodeRef node = item->data(0, ProjectNodeRole).value<NodeRef>();
  if (node == nullptr)
    return;

  blockSignals(true);

  item->setText(0, node->display());

  blockSignals(false);
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

  for (int i(0); i < item->childCount(); ++i)
    fetchNewNodes(item->child(i));
}

void ModuleTreeWidget::fillTreeWidget(const ProjectRef & pro)
{
  clear();

  for (const auto & item : pro->modules)
    fill(invisibleRootItem(), item);
}

QTreeWidgetItem* ModuleTreeWidget::createItem(const NodeRef & node)
{
  QTreeWidgetItem *item = new QTreeWidgetItem(QStringList{ node->display() });
  item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEditable);
  item->setData(0, ProjectNodeRole, QVariant::fromValue<NodeRef>(node));

  if (node->is<Module>())
  {
    item->setIcon(0, QIcon(":/assets/namespace.png"));

    Module & m = node->as<Module>();
    for (const auto & n : m.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<File>())
  {
    item->setIcon(0, QIcon(":/assets/namespace.png"));
    File & f = node->as<File>();
    for (const auto & n : f.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Namespace>())
  {
    item->setIcon(0, QIcon(":/assets/namespace.png"));
    Namespace & ns = node->as<Namespace>();
    for (const auto & n : ns.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Class>())
  {
    item->setIcon(0, QIcon(":/assets/class.png"));
    Class & c = node->as<Class>();
    for (const auto & n : c.elements)
      item->addChild(createItem(n));
  }
  else if (node->is<Enum>())
  {
    item->setIcon(0, QIcon(":/assets/enum.png"));
    Enum & enm = node->as<Enum>();
    for (const auto & n : enm.enumerators)
      item->addChild(createItem(n));
  }
  else if (node->is<Enumerator>())
  {
    item->setIcon(0, QIcon(":/assets/enumerator.png"));
  }
  else if (node->is<Function>())
  {
    item->setIcon(0, QIcon(":/assets/func.png"));
  }
  else if (node->is<Statement>())
  {
    item->setIcon(0, QIcon(":/assets/statement.png"));
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

  if (node->is<Module>() || node->is<Statement>())
  {
    node->name = item->text(0);
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
  //for (int i(0); i < columnCount(); ++i)
  //  resizeColumnToContents(i);
}

void ModuleTreeWidget::displayContextMenu(const QPoint & p)
{
  QTreeWidgetItem *item = itemAt(p);
  if (item == nullptr)
    return;

  NodeRef node = getNode(item);
  if (node == nullptr)
    return;

  QMenu *menu = nullptr;

  if (node->is<Class>())
    menu = mClassMenu;
  else if (node->is<File>())
    menu = mFileNodeMenu;

  if (menu == nullptr)
    return;

  QAction *act = menu->exec(this->mapToGlobal(p));
  execAction(item, node, act);
}

NodeRef ModuleTreeWidget::getNode(QTreeWidgetItem *item)
{
  return item->data(0, ModuleTreeWidget::ProjectNodeRole).value<NodeRef>();
}

void ModuleTreeWidget::createContextMenus()
{
  mClassMenu = new QMenu(this);
  mFileNodeMenu = new QMenu(this);

  mAddCopyCtorAction = mClassMenu->addAction("Add copy constructor");
  mAddDestructorAction = mClassMenu->addAction("Add destructor");
  mAddAssignmentAction = mClassMenu->addAction("Add assignment");
  mSortClassMembersAction = mClassMenu->addAction("Sort");

  mAddStatementAction = mFileNodeMenu->addAction("Add statement");
}

void ModuleTreeWidget::execAction(QTreeWidgetItem *item, NodeRef node, QAction *act)
{
  if (node->is<Class>())
  {
    Class & cla = node->as<Class>();
    
    if (act == mAddCopyCtorAction)
    {
      ConstructorRef ctor = ConstructorRef::create(cla.name);
      ctor->parameters.append("const " + cla.name + " &");
      cla.elements.append(ctor);
    }
    else if (act == mAddDestructorAction)
    {
      DestructorRef dtor = DestructorRef::create("~" + cla.name);
      cla.elements.append(dtor);
    }
    else if (act == mAddAssignmentAction)
    {
      FunctionRef assign = FunctionRef::create("operator=");
      assign->returnType = cla.name + " &";
      assign->parameters.append("const " + cla.name + " &");
      cla.elements.append(assign);
    }
    else if (act == mSortClassMembersAction)
    {
      sort(cla.elements);
      while (item->childCount() > 0)
        item->removeChild(item->child(item->childCount() - 1));
      fetchNewNodes(item);
    }
  }
  else if (node->is<File>())
  {
    File & file = node->as<File>();
    if (act == mAddStatementAction)
    {
      auto stmt = StatementRef::create("(void) 0;");
      file.elements.append(stmt);
    }
  }

  fetchNewNodes(item);
}