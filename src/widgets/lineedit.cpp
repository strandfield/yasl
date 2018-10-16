// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/lineedit.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/margins.h"
#include "yasl/core/point.h"
#include "yasl/core/size.h"
#include "yasl/core/variant.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/lineedit.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_line_edit_action_position_enum(script::Class line_edit)
{
  using namespace script;

  Enum action_position = line_edit.Enum("ActionPosition").setId(script::Type::QLineEditActionPosition).get();

  action_position.addValue("LeadingPosition", QLineEdit::LeadingPosition);
  action_position.addValue("TrailingPosition", QLineEdit::TrailingPosition);
}


static void register_line_edit_echo_mode_enum(script::Class line_edit)
{
  using namespace script;

  Enum echo_mode = line_edit.Enum("EchoMode").setId(script::Type::QLineEditEchoMode).get();

  echo_mode.addValue("Normal", QLineEdit::Normal);
  echo_mode.addValue("NoEcho", QLineEdit::NoEcho);
  echo_mode.addValue("Password", QLineEdit::Password);
  echo_mode.addValue("PasswordEchoOnEdit", QLineEdit::PasswordEchoOnEdit);
}


static void register_line_edit_class(script::Namespace ns)
{
  using namespace script;

  Class line_edit = ns.Class("LineEdit").setId(script::Type::QLineEdit)
    .setBase(script::Type::QWidget).get();

  register_line_edit_action_position_enum(line_edit);
  register_line_edit_echo_mode_enum(line_edit);
  binding::QClass<QLineEdit> binder{ line_edit, &QLineEdit::staticMetaObject };

  // QLineEdit(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // QLineEdit(const QString &, QWidget *);
  binder.ctors().ctor<const QString &, QWidget *>().create();
  // ~QLineEdit();
  binder.add_dtor();
  // QString text() const;
  binder.fun<QString, &QLineEdit::text>("text").create();
  // QString displayText() const;
  binder.fun<QString, &QLineEdit::displayText>("displayText").create();
  // QString placeholderText() const;
  binder.fun<QString, &QLineEdit::placeholderText>("placeholderText").create();
  // void setPlaceholderText(const QString &);
  binder.void_fun<const QString &, &QLineEdit::setPlaceholderText>("setPlaceholderText").create();
  // int maxLength() const;
  binder.fun<int, &QLineEdit::maxLength>("maxLength").create();
  // void setMaxLength(int);
  binder.void_fun<int, &QLineEdit::setMaxLength>("setMaxLength").create();
  // void setFrame(bool);
  binder.void_fun<bool, &QLineEdit::setFrame>("setFrame").create();
  // bool hasFrame() const;
  binder.fun<bool, &QLineEdit::hasFrame>("hasFrame").create();
  // void setClearButtonEnabled(bool);
  binder.void_fun<bool, &QLineEdit::setClearButtonEnabled>("setClearButtonEnabled").create();
  // bool isClearButtonEnabled() const;
  binder.fun<bool, &QLineEdit::isClearButtonEnabled>("isClearButtonEnabled").create();
  // QLineEdit::EchoMode echoMode() const;
  binder.fun<QLineEdit::EchoMode, &QLineEdit::echoMode>("echoMode").create();
  // void setEchoMode(QLineEdit::EchoMode);
  binder.void_fun<QLineEdit::EchoMode, &QLineEdit::setEchoMode>("setEchoMode").create();
  // bool isReadOnly() const;
  binder.fun<bool, &QLineEdit::isReadOnly>("isReadOnly").create();
  // void setReadOnly(bool);
  binder.void_fun<bool, &QLineEdit::setReadOnly>("setReadOnly").create();
  // void setValidator(const QValidator *);
  /// TODO: void setValidator(const QValidator *);
  // const QValidator * validator() const;
  /// TODO: const QValidator * validator() const;
  // void setCompleter(QCompleter *);
  /// TODO: void setCompleter(QCompleter *);
  // QCompleter * completer() const;
  /// TODO: QCompleter * completer() const;
  // QSize sizeHint() const;
  binder.fun<QSize, &QLineEdit::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QLineEdit::minimumSizeHint>("minimumSizeHint").create();
  // int cursorPosition() const;
  binder.fun<int, &QLineEdit::cursorPosition>("cursorPosition").create();
  // void setCursorPosition(int);
  binder.void_fun<int, &QLineEdit::setCursorPosition>("setCursorPosition").create();
  // int cursorPositionAt(const QPoint &);
  binder.fun<int, const QPoint &, &QLineEdit::cursorPositionAt>("cursorPositionAt").create();
  // void setAlignment(Qt::Alignment);
  binder.void_fun<Qt::Alignment, &QLineEdit::setAlignment>("setAlignment").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QLineEdit::alignment>("alignment").create();
  // void cursorForward(bool, int);
  binder.void_fun<bool, int, &QLineEdit::cursorForward>("cursorForward").create();
  // void cursorBackward(bool, int);
  binder.void_fun<bool, int, &QLineEdit::cursorBackward>("cursorBackward").create();
  // void cursorWordForward(bool);
  binder.void_fun<bool, &QLineEdit::cursorWordForward>("cursorWordForward").create();
  // void cursorWordBackward(bool);
  binder.void_fun<bool, &QLineEdit::cursorWordBackward>("cursorWordBackward").create();
  // void backspace();
  binder.void_fun<&QLineEdit::backspace>("backspace").create();
  // void del();
  binder.void_fun<&QLineEdit::del>("del").create();
  // void home(bool);
  binder.void_fun<bool, &QLineEdit::home>("home").create();
  // void end(bool);
  binder.void_fun<bool, &QLineEdit::end>("end").create();
  // bool isModified() const;
  binder.fun<bool, &QLineEdit::isModified>("isModified").create();
  // void setModified(bool);
  binder.void_fun<bool, &QLineEdit::setModified>("setModified").create();
  // void setSelection(int, int);
  binder.void_fun<int, int, &QLineEdit::setSelection>("setSelection").create();
  // bool hasSelectedText() const;
  binder.fun<bool, &QLineEdit::hasSelectedText>("hasSelectedText").create();
  // QString selectedText() const;
  binder.fun<QString, &QLineEdit::selectedText>("selectedText").create();
  // int selectionStart() const;
  binder.fun<int, &QLineEdit::selectionStart>("selectionStart").create();
  // int selectionEnd() const;
  binder.fun<int, &QLineEdit::selectionEnd>("selectionEnd").create();
  // int selectionLength() const;
  binder.fun<int, &QLineEdit::selectionLength>("selectionLength").create();
  // bool isUndoAvailable() const;
  binder.fun<bool, &QLineEdit::isUndoAvailable>("isUndoAvailable").create();
  // bool isRedoAvailable() const;
  binder.fun<bool, &QLineEdit::isRedoAvailable>("isRedoAvailable").create();
  // void setDragEnabled(bool);
  binder.void_fun<bool, &QLineEdit::setDragEnabled>("setDragEnabled").create();
  // bool dragEnabled() const;
  binder.fun<bool, &QLineEdit::dragEnabled>("dragEnabled").create();
  // void setCursorMoveStyle(Qt::CursorMoveStyle);
  binder.void_fun<Qt::CursorMoveStyle, &QLineEdit::setCursorMoveStyle>("setCursorMoveStyle").create();
  // Qt::CursorMoveStyle cursorMoveStyle() const;
  binder.fun<Qt::CursorMoveStyle, &QLineEdit::cursorMoveStyle>("cursorMoveStyle").create();
  // QString inputMask() const;
  binder.fun<QString, &QLineEdit::inputMask>("inputMask").create();
  // void setInputMask(const QString &);
  binder.void_fun<const QString &, &QLineEdit::setInputMask>("setInputMask").create();
  // bool hasAcceptableInput() const;
  binder.fun<bool, &QLineEdit::hasAcceptableInput>("hasAcceptableInput").create();
  // void setTextMargins(int, int, int, int);
  binder.void_fun<int, int, int, int, &QLineEdit::setTextMargins>("setTextMargins").create();
  // void setTextMargins(const QMargins &);
  binder.void_fun<const QMargins &, &QLineEdit::setTextMargins>("setTextMargins").create();
  // void getTextMargins(int *, int *, int *, int *) const;
  /// TODO: void getTextMargins(int *, int *, int *, int *) const;
  // QMargins textMargins() const;
  binder.fun<QMargins, &QLineEdit::textMargins>("textMargins").create();
  // void addAction(QAction *, QLineEdit::ActionPosition);
  binder.void_fun<QAction *, QLineEdit::ActionPosition, &QLineEdit::addAction>("addAction").create();
  // QAction * addAction(const QIcon &, QLineEdit::ActionPosition);
  binder.fun<QAction *, const QIcon &, QLineEdit::ActionPosition, &QLineEdit::addAction>("addAction").create();
  // void setText(const QString &);
  binder.void_fun<const QString &, &QLineEdit::setText>("setText").create();
  // void clear();
  binder.void_fun<&QLineEdit::clear>("clear").create();
  // void selectAll();
  binder.void_fun<&QLineEdit::selectAll>("selectAll").create();
  // void undo();
  binder.void_fun<&QLineEdit::undo>("undo").create();
  // void redo();
  binder.void_fun<&QLineEdit::redo>("redo").create();
  // void cut();
  binder.void_fun<&QLineEdit::cut>("cut").create();
  // void copy() const;
  binder.const_void_fun<&QLineEdit::copy>("copy").create();
  // void paste();
  binder.void_fun<&QLineEdit::paste>("paste").create();
  // void deselect();
  binder.void_fun<&QLineEdit::deselect>("deselect").create();
  // void insert(const QString &);
  binder.void_fun<const QString &, &QLineEdit::insert>("insert").create();
  // QMenu * createStandardContextMenu();
  binder.fun<QMenu *, &QLineEdit::createStandardContextMenu>("createStandardContextMenu").create();
  // void textChanged(const QString &);
  binder.sigs().add<const QString &>("textChanged", "textChanged(const QString &)");
  // void textEdited(const QString &);
  binder.sigs().add<const QString &>("textEdited", "textEdited(const QString &)");
  // void cursorPositionChanged(int, int);
  binder.sigs().add<int, int>("cursorPositionChanged", "cursorPositionChanged(int,int)");
  // void returnPressed();
  binder.sigs().add("returnPressed", "returnPressed()");
  // void editingFinished();
  binder.sigs().add("editingFinished", "editingFinished()");
  // void selectionChanged();
  binder.sigs().add("selectionChanged", "selectionChanged()");
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  binder.fun<QVariant, Qt::InputMethodQuery, &QLineEdit::inputMethodQuery>("inputMethodQuery").create();
  // QVariant inputMethodQuery(Qt::InputMethodQuery, QVariant) const;
  binder.fun<QVariant, Qt::InputMethodQuery, QVariant, &QLineEdit::inputMethodQuery>("inputMethodQuery").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);

  line_edit.engine()->registerQtType(&QLineEdit::staticMetaObject, line_edit.id());
}


void register_lineedit_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_line_edit_class(ns);
  binding::Namespace binder{ ns };

  // QLineEdit& newLineEdit(QWidget*);
  NewFunction(binder).add<QLineEdit, QWidget*>("newLineEdit");
  // QLineEdit& newLineEdit(const QString &, QWidget*);
  NewFunction(binder).add<QLineEdit, const QString &, QWidget*>("newLineEdit");
}

