// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/lineedit.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
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
  binder.ctors().add<QWidget *>();
  // QLineEdit(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // ~QLineEdit();
  binder.add_dtor();
  // QString text() const;
  binder.add_fun<QString, &QLineEdit::text>("text");
  // QString displayText() const;
  binder.add_fun<QString, &QLineEdit::displayText>("displayText");
  // QString placeholderText() const;
  binder.add_fun<QString, &QLineEdit::placeholderText>("placeholderText");
  // void setPlaceholderText(const QString &);
  binder.add_void_fun<const QString &, &QLineEdit::setPlaceholderText>("setPlaceholderText");
  // int maxLength() const;
  binder.add_fun<int, &QLineEdit::maxLength>("maxLength");
  // void setMaxLength(int);
  binder.add_void_fun<int, &QLineEdit::setMaxLength>("setMaxLength");
  // void setFrame(bool);
  binder.add_void_fun<bool, &QLineEdit::setFrame>("setFrame");
  // bool hasFrame() const;
  binder.add_fun<bool, &QLineEdit::hasFrame>("hasFrame");
  // void setClearButtonEnabled(bool);
  binder.add_void_fun<bool, &QLineEdit::setClearButtonEnabled>("setClearButtonEnabled");
  // bool isClearButtonEnabled() const;
  binder.add_fun<bool, &QLineEdit::isClearButtonEnabled>("isClearButtonEnabled");
  // QLineEdit::EchoMode echoMode() const;
  binder.add_fun<QLineEdit::EchoMode, &QLineEdit::echoMode>("echoMode");
  // void setEchoMode(QLineEdit::EchoMode);
  binder.add_void_fun<QLineEdit::EchoMode, &QLineEdit::setEchoMode>("setEchoMode");
  // bool isReadOnly() const;
  binder.add_fun<bool, &QLineEdit::isReadOnly>("isReadOnly");
  // void setReadOnly(bool);
  binder.add_void_fun<bool, &QLineEdit::setReadOnly>("setReadOnly");
  // void setValidator(const QValidator *);
  /// TODO: void setValidator(const QValidator *);
  // const QValidator * validator() const;
  /// TODO: const QValidator * validator() const;
  // void setCompleter(QCompleter *);
  /// TODO: void setCompleter(QCompleter *);
  // QCompleter * completer() const;
  /// TODO: QCompleter * completer() const;
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QLineEdit::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QLineEdit::minimumSizeHint>("minimumSizeHint");
  // int cursorPosition() const;
  binder.add_fun<int, &QLineEdit::cursorPosition>("cursorPosition");
  // void setCursorPosition(int);
  binder.add_void_fun<int, &QLineEdit::setCursorPosition>("setCursorPosition");
  // int cursorPositionAt(const QPoint &);
  binder.add_fun<int, const QPoint &, &QLineEdit::cursorPositionAt>("cursorPositionAt");
  // void setAlignment(Qt::Alignment);
  /// TODO: void setAlignment(Qt::Alignment);
  // Qt::Alignment alignment() const;
  /// TODO: Qt::Alignment alignment() const;
  // void cursorForward(bool, int);
  binder.add_void_fun<bool, int, &QLineEdit::cursorForward>("cursorForward");
  // void cursorBackward(bool, int);
  binder.add_void_fun<bool, int, &QLineEdit::cursorBackward>("cursorBackward");
  // void cursorWordForward(bool);
  binder.add_void_fun<bool, &QLineEdit::cursorWordForward>("cursorWordForward");
  // void cursorWordBackward(bool);
  binder.add_void_fun<bool, &QLineEdit::cursorWordBackward>("cursorWordBackward");
  // void backspace();
  binder.add_void_fun<&QLineEdit::backspace>("backspace");
  // void del();
  binder.add_void_fun<&QLineEdit::del>("del");
  // void home(bool);
  binder.add_void_fun<bool, &QLineEdit::home>("home");
  // void end(bool);
  binder.add_void_fun<bool, &QLineEdit::end>("end");
  // bool isModified() const;
  binder.add_fun<bool, &QLineEdit::isModified>("isModified");
  // void setModified(bool);
  binder.add_void_fun<bool, &QLineEdit::setModified>("setModified");
  // void setSelection(int, int);
  binder.add_void_fun<int, int, &QLineEdit::setSelection>("setSelection");
  // bool hasSelectedText() const;
  binder.add_fun<bool, &QLineEdit::hasSelectedText>("hasSelectedText");
  // QString selectedText() const;
  binder.add_fun<QString, &QLineEdit::selectedText>("selectedText");
  // int selectionStart() const;
  binder.add_fun<int, &QLineEdit::selectionStart>("selectionStart");
  // int selectionEnd() const;
  binder.add_fun<int, &QLineEdit::selectionEnd>("selectionEnd");
  // int selectionLength() const;
  binder.add_fun<int, &QLineEdit::selectionLength>("selectionLength");
  // bool isUndoAvailable() const;
  binder.add_fun<bool, &QLineEdit::isUndoAvailable>("isUndoAvailable");
  // bool isRedoAvailable() const;
  binder.add_fun<bool, &QLineEdit::isRedoAvailable>("isRedoAvailable");
  // void setDragEnabled(bool);
  binder.add_void_fun<bool, &QLineEdit::setDragEnabled>("setDragEnabled");
  // bool dragEnabled() const;
  binder.add_fun<bool, &QLineEdit::dragEnabled>("dragEnabled");
  // void setCursorMoveStyle(Qt::CursorMoveStyle);
  binder.add_void_fun<Qt::CursorMoveStyle, &QLineEdit::setCursorMoveStyle>("setCursorMoveStyle");
  // Qt::CursorMoveStyle cursorMoveStyle() const;
  binder.add_fun<Qt::CursorMoveStyle, &QLineEdit::cursorMoveStyle>("cursorMoveStyle");
  // QString inputMask() const;
  binder.add_fun<QString, &QLineEdit::inputMask>("inputMask");
  // void setInputMask(const QString &);
  binder.add_void_fun<const QString &, &QLineEdit::setInputMask>("setInputMask");
  // bool hasAcceptableInput() const;
  binder.add_fun<bool, &QLineEdit::hasAcceptableInput>("hasAcceptableInput");
  // void setTextMargins(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QLineEdit::setTextMargins>("setTextMargins");
  // void setTextMargins(const QMargins &);
  binder.add_void_fun<const QMargins &, &QLineEdit::setTextMargins>("setTextMargins");
  // void getTextMargins(int *, int *, int *, int *) const;
  /// TODO: void getTextMargins(int *, int *, int *, int *) const;
  // QMargins textMargins() const;
  binder.add_fun<QMargins, &QLineEdit::textMargins>("textMargins");
  // void addAction(QAction *, QLineEdit::ActionPosition);
  binder.add_void_fun<QAction *, QLineEdit::ActionPosition, &QLineEdit::addAction>("addAction");
  // QAction * addAction(const QIcon &, QLineEdit::ActionPosition);
  binder.add_fun<QAction *, const QIcon &, QLineEdit::ActionPosition, &QLineEdit::addAction>("addAction");
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QLineEdit::setText>("setText");
  // void clear();
  binder.add_void_fun<&QLineEdit::clear>("clear");
  // void selectAll();
  binder.add_void_fun<&QLineEdit::selectAll>("selectAll");
  // void undo();
  binder.add_void_fun<&QLineEdit::undo>("undo");
  // void redo();
  binder.add_void_fun<&QLineEdit::redo>("redo");
  // void cut();
  binder.add_void_fun<&QLineEdit::cut>("cut");
  // void copy() const;
  binder.add_const_void_fun<&QLineEdit::copy>("copy");
  // void paste();
  binder.add_void_fun<&QLineEdit::paste>("paste");
  // void deselect();
  binder.add_void_fun<&QLineEdit::deselect>("deselect");
  // void insert(const QString &);
  binder.add_void_fun<const QString &, &QLineEdit::insert>("insert");
  // QMenu * createStandardContextMenu();
  binder.add_fun<QMenu *, &QLineEdit::createStandardContextMenu>("createStandardContextMenu");
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
  binder.add_fun<QVariant, Qt::InputMethodQuery, &QLineEdit::inputMethodQuery>("inputMethodQuery");
  // QVariant inputMethodQuery(Qt::InputMethodQuery, QVariant) const;
  binder.add_fun<QVariant, Qt::InputMethodQuery, QVariant, &QLineEdit::inputMethodQuery>("inputMethodQuery");
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

}

