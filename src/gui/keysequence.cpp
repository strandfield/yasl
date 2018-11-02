// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/keysequence.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/gui/keysequence.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_key_sequence_standard_key_enum(script::Class key_sequence)
{
  using namespace script;

  Enum standard_key = key_sequence.Enum("StandardKey").setId(script::Type::QKeySequenceStandardKey).get();

  standard_key.addValue("UnknownKey", QKeySequence::UnknownKey);
  standard_key.addValue("HelpContents", QKeySequence::HelpContents);
  standard_key.addValue("WhatsThis", QKeySequence::WhatsThis);
  standard_key.addValue("Open", QKeySequence::Open);
  standard_key.addValue("Close", QKeySequence::Close);
  standard_key.addValue("Save", QKeySequence::Save);
  standard_key.addValue("New", QKeySequence::New);
  standard_key.addValue("Delete", QKeySequence::Delete);
  standard_key.addValue("Cut", QKeySequence::Cut);
  standard_key.addValue("Copy", QKeySequence::Copy);
  standard_key.addValue("Paste", QKeySequence::Paste);
  standard_key.addValue("Undo", QKeySequence::Undo);
  standard_key.addValue("Redo", QKeySequence::Redo);
  standard_key.addValue("Back", QKeySequence::Back);
  standard_key.addValue("Forward", QKeySequence::Forward);
  standard_key.addValue("Refresh", QKeySequence::Refresh);
  standard_key.addValue("ZoomIn", QKeySequence::ZoomIn);
  standard_key.addValue("ZoomOut", QKeySequence::ZoomOut);
  standard_key.addValue("Print", QKeySequence::Print);
  standard_key.addValue("AddTab", QKeySequence::AddTab);
  standard_key.addValue("NextChild", QKeySequence::NextChild);
  standard_key.addValue("PreviousChild", QKeySequence::PreviousChild);
  standard_key.addValue("Find", QKeySequence::Find);
  standard_key.addValue("FindNext", QKeySequence::FindNext);
  standard_key.addValue("FindPrevious", QKeySequence::FindPrevious);
  standard_key.addValue("Replace", QKeySequence::Replace);
  standard_key.addValue("SelectAll", QKeySequence::SelectAll);
  standard_key.addValue("Bold", QKeySequence::Bold);
  standard_key.addValue("Italic", QKeySequence::Italic);
  standard_key.addValue("Underline", QKeySequence::Underline);
  standard_key.addValue("MoveToNextChar", QKeySequence::MoveToNextChar);
  standard_key.addValue("MoveToPreviousChar", QKeySequence::MoveToPreviousChar);
  standard_key.addValue("MoveToNextWord", QKeySequence::MoveToNextWord);
  standard_key.addValue("MoveToPreviousWord", QKeySequence::MoveToPreviousWord);
  standard_key.addValue("MoveToNextLine", QKeySequence::MoveToNextLine);
  standard_key.addValue("MoveToPreviousLine", QKeySequence::MoveToPreviousLine);
  standard_key.addValue("MoveToNextPage", QKeySequence::MoveToNextPage);
  standard_key.addValue("MoveToPreviousPage", QKeySequence::MoveToPreviousPage);
  standard_key.addValue("MoveToStartOfLine", QKeySequence::MoveToStartOfLine);
  standard_key.addValue("MoveToEndOfLine", QKeySequence::MoveToEndOfLine);
  standard_key.addValue("MoveToStartOfBlock", QKeySequence::MoveToStartOfBlock);
  standard_key.addValue("MoveToEndOfBlock", QKeySequence::MoveToEndOfBlock);
  standard_key.addValue("MoveToStartOfDocument", QKeySequence::MoveToStartOfDocument);
  standard_key.addValue("MoveToEndOfDocument", QKeySequence::MoveToEndOfDocument);
  standard_key.addValue("SelectNextChar", QKeySequence::SelectNextChar);
  standard_key.addValue("SelectPreviousChar", QKeySequence::SelectPreviousChar);
  standard_key.addValue("SelectNextWord", QKeySequence::SelectNextWord);
  standard_key.addValue("SelectPreviousWord", QKeySequence::SelectPreviousWord);
  standard_key.addValue("SelectNextLine", QKeySequence::SelectNextLine);
  standard_key.addValue("SelectPreviousLine", QKeySequence::SelectPreviousLine);
  standard_key.addValue("SelectNextPage", QKeySequence::SelectNextPage);
  standard_key.addValue("SelectPreviousPage", QKeySequence::SelectPreviousPage);
  standard_key.addValue("SelectStartOfLine", QKeySequence::SelectStartOfLine);
  standard_key.addValue("SelectEndOfLine", QKeySequence::SelectEndOfLine);
  standard_key.addValue("SelectStartOfBlock", QKeySequence::SelectStartOfBlock);
  standard_key.addValue("SelectEndOfBlock", QKeySequence::SelectEndOfBlock);
  standard_key.addValue("SelectStartOfDocument", QKeySequence::SelectStartOfDocument);
  standard_key.addValue("SelectEndOfDocument", QKeySequence::SelectEndOfDocument);
  standard_key.addValue("DeleteStartOfWord", QKeySequence::DeleteStartOfWord);
  standard_key.addValue("DeleteEndOfWord", QKeySequence::DeleteEndOfWord);
  standard_key.addValue("DeleteEndOfLine", QKeySequence::DeleteEndOfLine);
  standard_key.addValue("InsertParagraphSeparator", QKeySequence::InsertParagraphSeparator);
  standard_key.addValue("InsertLineSeparator", QKeySequence::InsertLineSeparator);
  standard_key.addValue("SaveAs", QKeySequence::SaveAs);
  standard_key.addValue("Preferences", QKeySequence::Preferences);
  standard_key.addValue("Quit", QKeySequence::Quit);
  standard_key.addValue("FullScreen", QKeySequence::FullScreen);
  standard_key.addValue("Deselect", QKeySequence::Deselect);
  standard_key.addValue("DeleteCompleteLine", QKeySequence::DeleteCompleteLine);
  standard_key.addValue("Backspace", QKeySequence::Backspace);
  standard_key.addValue("Cancel", QKeySequence::Cancel);
}


static void register_key_sequence_sequence_format_enum(script::Class key_sequence)
{
  using namespace script;

  Enum sequence_format = key_sequence.Enum("SequenceFormat").setId(script::Type::QKeySequenceSequenceFormat).get();

  sequence_format.addValue("NativeText", QKeySequence::NativeText);
  sequence_format.addValue("PortableText", QKeySequence::PortableText);
}


static void register_key_sequence_sequence_match_enum(script::Class key_sequence)
{
  using namespace script;

  Enum sequence_match = key_sequence.Enum("SequenceMatch").setId(script::Type::QKeySequenceSequenceMatch).get();

  sequence_match.addValue("NoMatch", QKeySequence::NoMatch);
  sequence_match.addValue("PartialMatch", QKeySequence::PartialMatch);
  sequence_match.addValue("ExactMatch", QKeySequence::ExactMatch);
}


static void register_key_sequence_class(script::Namespace ns)
{
  using namespace script;

  Class key_sequence = ns.Class("KeySequence").setId(script::Type::QKeySequence).get();

  register_key_sequence_standard_key_enum(key_sequence);
  register_key_sequence_sequence_format_enum(key_sequence);
  register_key_sequence_sequence_match_enum(key_sequence);
  binding::Class<QKeySequence> binder{ key_sequence };

  // QKeySequence();
  binder.ctors().add_default();
  // QKeySequence(const QString &, QKeySequence::SequenceFormat);
  binder.ctors().ctor<const QString &, QKeySequence::SequenceFormat>()
    .apply(binding::default_arguments(QKeySequence::NativeText)).create();
  // QKeySequence(int, int, int, int);
  binder.ctors().ctor<int, int, int, int>()
    .apply(binding::default_arguments(0, 0, 0)).create();
  // QKeySequence(const QKeySequence &);
  binder.ctors().ctor<const QKeySequence &>().create();
  // QKeySequence(QKeySequence::StandardKey);
  binder.ctors().ctor<QKeySequence::StandardKey>().create();
  // ~QKeySequence();
  binder.add_dtor();
  // int count() const;
  binder.fun<int, &QKeySequence::count>("count").create();
  // bool isEmpty() const;
  binder.fun<bool, &QKeySequence::isEmpty>("isEmpty").create();
  // QString toString(QKeySequence::SequenceFormat) const;
  binder.fun<QString, QKeySequence::SequenceFormat, &QKeySequence::toString>("toString")
    .apply(binding::default_arguments(QKeySequence::PortableText)).create();
  // static QKeySequence fromString(const QString &, QKeySequence::SequenceFormat);
  binder.static_fun<QKeySequence, const QString &, QKeySequence::SequenceFormat, &QKeySequence::fromString>("fromString")
    .apply(binding::default_arguments(QKeySequence::PortableText)).create();
  // static QList<QKeySequence> listFromString(const QString &, QKeySequence::SequenceFormat);
  /// TODO: static QList<QKeySequence> listFromString(const QString &, QKeySequence::SequenceFormat);
  // static QString listToString(const QList<QKeySequence> &, QKeySequence::SequenceFormat);
  /// TODO: static QString listToString(const QList<QKeySequence> &, QKeySequence::SequenceFormat);
  // QKeySequence::SequenceMatch matches(const QKeySequence &) const;
  binder.fun<QKeySequence::SequenceMatch, const QKeySequence &, &QKeySequence::matches>("matches").create();
  // static QKeySequence mnemonic(const QString &);
  binder.static_fun<QKeySequence, const QString &, &QKeySequence::mnemonic>("mnemonic").create();
  // static QList<QKeySequence> keyBindings(QKeySequence::StandardKey);
  /// TODO: static QList<QKeySequence> keyBindings(QKeySequence::StandardKey);
  // int operator[](uint) const;
  binder.operators().const_subscript<int, uint>();
  // QKeySequence & operator=(const QKeySequence &);
  binder.operators().assign<const QKeySequence &>();
  // QKeySequence & operator=(QKeySequence &&);
  binder.operators().assign<QKeySequence &&>();
  // void swap(QKeySequence &);
  binder.void_fun<QKeySequence &, &QKeySequence::swap>("swap").create();
  // bool operator==(const QKeySequence &) const;
  binder.operators().eq<const QKeySequence &>();
  // bool operator!=(const QKeySequence &) const;
  binder.operators().neq<const QKeySequence &>();
  // bool operator<(const QKeySequence &) const;
  binder.operators().less<const QKeySequence &>();
  // bool operator>(const QKeySequence &) const;
  binder.operators().greater<const QKeySequence &>();
  // bool operator<=(const QKeySequence &) const;
  binder.operators().leq<const QKeySequence &>();
  // bool operator>=(const QKeySequence &) const;
  binder.operators().geq<const QKeySequence &>();
  // bool isDetached() const;
  binder.fun<bool, &QKeySequence::isDetached>("isDetached").create();
  // QKeySequence::DataPtr & data_ptr();
  /// TODO: QKeySequence::DataPtr & data_ptr();
}


void register_keysequence_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_key_sequence_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QKeySequence &);
  binder.operators().put_to<QDataStream &, const QKeySequence &>();
  // QDataStream & operator>>(QDataStream &, QKeySequence &);
  binder.operators().read_from<QDataStream &, QKeySequence &>();
  // uint qHash(const QKeySequence &, uint);
  binder.fun<uint, const QKeySequence &, uint, &qHash>("qHash").create();
  // void swap(QKeySequence &, QKeySequence &);
  binder.void_fun<QKeySequence &, QKeySequence &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QKeySequence &);
  /// TODO: QDebug operator<<(QDebug, const QKeySequence &);
}

