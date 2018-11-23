// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/lineedit.h"

#include "yasl/binding/default_arguments.h"
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

  Enum action_position = line_edit.newEnum("ActionPosition").setId(script::Type::QLineEditActionPosition).get();

  action_position.addValue("LeadingPosition", QLineEdit::LeadingPosition);
  action_position.addValue("TrailingPosition", QLineEdit::TrailingPosition);
}


static void register_line_edit_echo_mode_enum(script::Class line_edit)
{
  using namespace script;

  Enum echo_mode = line_edit.newEnum("EchoMode").setId(script::Type::QLineEditEchoMode).get();

  echo_mode.addValue("Normal", QLineEdit::Normal);
  echo_mode.addValue("NoEcho", QLineEdit::NoEcho);
  echo_mode.addValue("Password", QLineEdit::Password);
  echo_mode.addValue("PasswordEchoOnEdit", QLineEdit::PasswordEchoOnEdit);
}


static void register_line_edit_class(script::Namespace ns)
{
  using namespace script;

  Class line_edit = ns.newClass("LineEdit").setId(script::Type::QLineEdit)
    .setBase(script::Type::QWidget).get();

  register_line_edit_action_position_enum(line_edit);
  register_line_edit_echo_mode_enum(line_edit);

  // QLineEdit(QWidget *);
  bind::constructor<QLineEdit, QWidget *>(line_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QLineEdit(const QString &, QWidget *);
  bind::constructor<QLineEdit, const QString &, QWidget *>(line_edit)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QLineEdit();
  bind::destructor<QLineEdit>(line_edit).create();
  // QString text() const;
  bind::member_function<QLineEdit, QString, &QLineEdit::text>(line_edit, "text").create();
  // QString displayText() const;
  bind::member_function<QLineEdit, QString, &QLineEdit::displayText>(line_edit, "displayText").create();
  // QString placeholderText() const;
  bind::member_function<QLineEdit, QString, &QLineEdit::placeholderText>(line_edit, "placeholderText").create();
  // void setPlaceholderText(const QString &);
  bind::void_member_function<QLineEdit, const QString &, &QLineEdit::setPlaceholderText>(line_edit, "setPlaceholderText").create();
  // int maxLength() const;
  bind::member_function<QLineEdit, int, &QLineEdit::maxLength>(line_edit, "maxLength").create();
  // void setMaxLength(int);
  bind::void_member_function<QLineEdit, int, &QLineEdit::setMaxLength>(line_edit, "setMaxLength").create();
  // void setFrame(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::setFrame>(line_edit, "setFrame").create();
  // bool hasFrame() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::hasFrame>(line_edit, "hasFrame").create();
  // void setClearButtonEnabled(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::setClearButtonEnabled>(line_edit, "setClearButtonEnabled").create();
  // bool isClearButtonEnabled() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::isClearButtonEnabled>(line_edit, "isClearButtonEnabled").create();
  // QLineEdit::EchoMode echoMode() const;
  bind::member_function<QLineEdit, QLineEdit::EchoMode, &QLineEdit::echoMode>(line_edit, "echoMode").create();
  // void setEchoMode(QLineEdit::EchoMode);
  bind::void_member_function<QLineEdit, QLineEdit::EchoMode, &QLineEdit::setEchoMode>(line_edit, "setEchoMode").create();
  // bool isReadOnly() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::isReadOnly>(line_edit, "isReadOnly").create();
  // void setReadOnly(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::setReadOnly>(line_edit, "setReadOnly").create();
  // void setValidator(const QValidator *);
  /// TODO: void setValidator(const QValidator *);
  // const QValidator * validator() const;
  /// TODO: const QValidator * validator() const;
  // void setCompleter(QCompleter *);
  /// TODO: void setCompleter(QCompleter *);
  // QCompleter * completer() const;
  /// TODO: QCompleter * completer() const;
  // QSize sizeHint() const;
  bind::member_function<QLineEdit, QSize, &QLineEdit::sizeHint>(line_edit, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QLineEdit, QSize, &QLineEdit::minimumSizeHint>(line_edit, "minimumSizeHint").create();
  // int cursorPosition() const;
  bind::member_function<QLineEdit, int, &QLineEdit::cursorPosition>(line_edit, "cursorPosition").create();
  // void setCursorPosition(int);
  bind::void_member_function<QLineEdit, int, &QLineEdit::setCursorPosition>(line_edit, "setCursorPosition").create();
  // int cursorPositionAt(const QPoint &);
  bind::member_function<QLineEdit, int, const QPoint &, &QLineEdit::cursorPositionAt>(line_edit, "cursorPositionAt").create();
  // void setAlignment(Qt::Alignment);
  bind::void_member_function<QLineEdit, Qt::Alignment, &QLineEdit::setAlignment>(line_edit, "setAlignment").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QLineEdit, Qt::Alignment, &QLineEdit::alignment>(line_edit, "alignment").create();
  // void cursorForward(bool, int);
  bind::void_member_function<QLineEdit, bool, int, &QLineEdit::cursorForward>(line_edit, "cursorForward")
    .apply(bind::default_arguments(1)).create();
  // void cursorBackward(bool, int);
  bind::void_member_function<QLineEdit, bool, int, &QLineEdit::cursorBackward>(line_edit, "cursorBackward")
    .apply(bind::default_arguments(1)).create();
  // void cursorWordForward(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::cursorWordForward>(line_edit, "cursorWordForward").create();
  // void cursorWordBackward(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::cursorWordBackward>(line_edit, "cursorWordBackward").create();
  // void backspace();
  bind::void_member_function<QLineEdit, &QLineEdit::backspace>(line_edit, "backspace").create();
  // void del();
  bind::void_member_function<QLineEdit, &QLineEdit::del>(line_edit, "del").create();
  // void home(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::home>(line_edit, "home").create();
  // void end(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::end>(line_edit, "end").create();
  // bool isModified() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::isModified>(line_edit, "isModified").create();
  // void setModified(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::setModified>(line_edit, "setModified").create();
  // void setSelection(int, int);
  bind::void_member_function<QLineEdit, int, int, &QLineEdit::setSelection>(line_edit, "setSelection").create();
  // bool hasSelectedText() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::hasSelectedText>(line_edit, "hasSelectedText").create();
  // QString selectedText() const;
  bind::member_function<QLineEdit, QString, &QLineEdit::selectedText>(line_edit, "selectedText").create();
  // int selectionStart() const;
  bind::member_function<QLineEdit, int, &QLineEdit::selectionStart>(line_edit, "selectionStart").create();
  // bool isUndoAvailable() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::isUndoAvailable>(line_edit, "isUndoAvailable").create();
  // bool isRedoAvailable() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::isRedoAvailable>(line_edit, "isRedoAvailable").create();
  // void setDragEnabled(bool);
  bind::void_member_function<QLineEdit, bool, &QLineEdit::setDragEnabled>(line_edit, "setDragEnabled").create();
  // bool dragEnabled() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::dragEnabled>(line_edit, "dragEnabled").create();
  // void setCursorMoveStyle(Qt::CursorMoveStyle);
  bind::void_member_function<QLineEdit, Qt::CursorMoveStyle, &QLineEdit::setCursorMoveStyle>(line_edit, "setCursorMoveStyle").create();
  // Qt::CursorMoveStyle cursorMoveStyle() const;
  bind::member_function<QLineEdit, Qt::CursorMoveStyle, &QLineEdit::cursorMoveStyle>(line_edit, "cursorMoveStyle").create();
  // QString inputMask() const;
  bind::member_function<QLineEdit, QString, &QLineEdit::inputMask>(line_edit, "inputMask").create();
  // void setInputMask(const QString &);
  bind::void_member_function<QLineEdit, const QString &, &QLineEdit::setInputMask>(line_edit, "setInputMask").create();
  // bool hasAcceptableInput() const;
  bind::member_function<QLineEdit, bool, &QLineEdit::hasAcceptableInput>(line_edit, "hasAcceptableInput").create();
  // void setTextMargins(int, int, int, int);
  bind::void_member_function<QLineEdit, int, int, int, int, &QLineEdit::setTextMargins>(line_edit, "setTextMargins").create();
  // void setTextMargins(const QMargins &);
  bind::void_member_function<QLineEdit, const QMargins &, &QLineEdit::setTextMargins>(line_edit, "setTextMargins").create();
  // void getTextMargins(int *, int *, int *, int *) const;
  /// TODO: void getTextMargins(int *, int *, int *, int *) const;
  // QMargins textMargins() const;
  bind::member_function<QLineEdit, QMargins, &QLineEdit::textMargins>(line_edit, "textMargins").create();
  // void addAction(QAction *, QLineEdit::ActionPosition);
  bind::void_member_function<QLineEdit, QAction *, QLineEdit::ActionPosition, &QLineEdit::addAction>(line_edit, "addAction").create();
  // QAction * addAction(const QIcon &, QLineEdit::ActionPosition);
  bind::member_function<QLineEdit, QAction *, const QIcon &, QLineEdit::ActionPosition, &QLineEdit::addAction>(line_edit, "addAction").create();
  // void setText(const QString &);
  bind::void_member_function<QLineEdit, const QString &, &QLineEdit::setText>(line_edit, "setText").create();
  // void clear();
  bind::void_member_function<QLineEdit, &QLineEdit::clear>(line_edit, "clear").create();
  // void selectAll();
  bind::void_member_function<QLineEdit, &QLineEdit::selectAll>(line_edit, "selectAll").create();
  // void undo();
  bind::void_member_function<QLineEdit, &QLineEdit::undo>(line_edit, "undo").create();
  // void redo();
  bind::void_member_function<QLineEdit, &QLineEdit::redo>(line_edit, "redo").create();
  // void cut();
  bind::void_member_function<QLineEdit, &QLineEdit::cut>(line_edit, "cut").create();
  // void copy() const;
  bind::const_void_member_function<QLineEdit, &QLineEdit::copy>(line_edit, "copy").create();
  // void paste();
  bind::void_member_function<QLineEdit, &QLineEdit::paste>(line_edit, "paste").create();
  // void deselect();
  bind::void_member_function<QLineEdit, &QLineEdit::deselect>(line_edit, "deselect").create();
  // void insert(const QString &);
  bind::void_member_function<QLineEdit, const QString &, &QLineEdit::insert>(line_edit, "insert").create();
  // QMenu * createStandardContextMenu();
  bind::member_function<QLineEdit, QMenu *, &QLineEdit::createStandardContextMenu>(line_edit, "createStandardContextMenu").create();
  // void textChanged(const QString &);
  bind::signal<QLineEdit, const QString &>(line_edit, "textChanged", "textChanged(const QString &)");
  // void textEdited(const QString &);
  bind::signal<QLineEdit, const QString &>(line_edit, "textEdited", "textEdited(const QString &)");
  // void cursorPositionChanged(int, int);
  bind::signal<QLineEdit, int, int>(line_edit, "cursorPositionChanged", "cursorPositionChanged(int,int)");
  // void returnPressed();
  bind::signal<QLineEdit>(line_edit, "returnPressed", "returnPressed()");
  // void editingFinished();
  bind::signal<QLineEdit>(line_edit, "editingFinished", "editingFinished()");
  // void selectionChanged();
  bind::signal<QLineEdit>(line_edit, "selectionChanged", "selectionChanged()");
  // QVariant inputMethodQuery(Qt::InputMethodQuery) const;
  bind::member_function<QLineEdit, QVariant, Qt::InputMethodQuery, &QLineEdit::inputMethodQuery>(line_edit, "inputMethodQuery").create();
  // QVariant inputMethodQuery(Qt::InputMethodQuery, QVariant) const;
  bind::member_function<QLineEdit, QVariant, Qt::InputMethodQuery, QVariant, &QLineEdit::inputMethodQuery>(line_edit, "inputMethodQuery").create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);

  bind::link(line_edit, &QLineEdit::staticMetaObject);
}


void register_lineedit_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_line_edit_class(ns);

  // QLineEdit& newLineEdit(QWidget*);
  bind::new_function<QLineEdit, QWidget*>(ns, "newLineEdit");
  // QLineEdit& newLineEdit(const QString &, QWidget*);
  bind::new_function<QLineEdit, const QString &, QWidget*>(ns, "newLineEdit");
}

