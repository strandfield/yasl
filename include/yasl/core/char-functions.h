// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

QChar::Category qchar_category(uint c)
{
  return QChar::category(c);
}

QChar::Direction qchar_direction(uint c)
{
  return QChar::direction(c);
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 3, 0)
QChar::JoiningType qchar_joiningType(uint c)
{
  return QChar::joiningType(c);
}
#endif

QChar::Joining qchar_joining(uint c)
{
  return QChar::joining(c);
}

unsigned char qchar_combiningClass(uint ucs4)
{
  return QChar::combiningClass(ucs4);
}

uint qchar_mirroredChar(uint ucs4)
{
  return QChar::mirroredChar(ucs4);
}

bool qchar_hasMirrored(uint ucs4)
{
  return QChar::hasMirrored(ucs4);
}

QString qchar_decomposition(uint ucs4)
{
  return QChar::decomposition(ucs4);
}

QChar::Decomposition qchar_decompositionTag(uint ucs4)
{
  return QChar::decompositionTag(ucs4);
}

int qchar_digitValue(uint ucs4)
{
  return QChar::digitValue(ucs4);
}

uint qchar_toLower(uint ucs4)
{
  return QChar::toLower(ucs4);
}

uint qchar_toUpper(uint ucs4)
{
  return QChar::toUpper(ucs4);
}

uint qchar_toTitleCase(uint ucs4)
{
  return QChar::toTitleCase(ucs4);
}

uint qchar_toCaseFolded(uint ucs4)
{
  return QChar::toCaseFolded(ucs4);
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
QChar::Script qchar_script(uint ucs4)
{
  return QChar::script(ucs4);
}
#endif

QChar::UnicodeVersion qchar_unicodeVersion(uint ucs4)
{
  return QChar::unicodeVersion(ucs4);
}

QChar::UnicodeVersion qchar_currentUnicodeVersion()
{
  return QChar::currentUnicodeVersion();
}

bool qchar_isPrint(uint ucs4)
{
  return QChar::isPrint(ucs4);
}

bool qchar_isMark(uint ucs4)
{
  return QChar::isMark(ucs4);
}

bool qchar_isPunct(uint ucs4)
{
  return QChar::isPunct(ucs4);
}

bool qchar_isSymbol(uint ucs4)
{
  return QChar::isSymbol(ucs4);
}
