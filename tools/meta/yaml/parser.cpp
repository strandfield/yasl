// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yaml/parser.h"

namespace yaml
{

Parser::Parser()
  : stream(nullptr)
  , currentindent(0)
{

}

yaml::Value Parser::parse(QTextStream & textstream)
{
  done = false;
  this->stream = &textstream;
  if (!hasNext())
    return yaml::Value{};

  getNext();
  return parseValue(0);
}


bool Parser::hasNext() const
{
  return !this->stream->atEnd();
}

QString Parser::getNext()
{
  currentline = this->stream->readLine();
  while (currentline.size() > 0 && currentline.back().isSpace())
    currentline.chop(1);
  currentindent = computeIndent(currentline);
  return currentline;
}

void Parser::nextOrDone()
{
  if (hasNext())
  {
    getNext();
  }
  else
  {
    done = true;
    currentindent = -1;
  }
}
yaml::Value Parser::parseValue(const int indent)
{
  if (currentline.at(currentindent * 2) == '-')
  {
    // Parse list
    yaml::Array result{};

    do
    {
      Q_ASSERT(currentline.at(currentindent * 2) == '-');

      currentline[currentindent * 2] = ' ';
      currentindent += 1;
      yaml::Value elem = parseValue(indent + 1);
      result.underlyingList().append(elem);

    } while (currentindent == indent);

    return result;
  }
  else if (currentline.at(currentindent * 2) == '{')
  {
    // Inline object
    yaml::Value ret = parseObject(currentline.mid(currentindent * 2).trimmed());
    nextOrDone();
    return ret;
  }
  else if (currentline.at(currentindent * 2) == '[')
  {
    // Inline array
    yaml::Value ret = parseArray(currentline.mid(currentindent * 2).trimmed());
    nextOrDone();
    return ret;
  }

  int colon = readPropertyName(currentline, currentindent);
  if (colon != -1)
  {
    // Parse object
    yaml::Object result{};

    do
    {
      int colon = readPropertyName(currentline, currentindent);
      QString property_name = currentline.mid(currentindent * 2, colon - currentindent * 2);
      yaml::Value property_value;

      if (currentline.endsWith(':'))
      {
        getNext();
        property_value = parseValue(indent + 1);
      }
      else if (currentline.endsWith('}') && currentline.at(colon + 2) == '{')
      {
        // name: {...}
        const int opening_brace = currentline.indexOf('{', colon);
        QString subobject = currentline.mid(opening_brace);
        property_value = parseObject(subobject);

        nextOrDone();
      }
      else if (currentline.endsWith(']') && currentline.at(colon + 2) == '[')
      {
        // name: [...]
        const int opening_bracket = currentline.indexOf('[', colon);
        QString subarray = currentline.mid(opening_bracket);
        property_value = parseArray(subarray);

        nextOrDone();
      }
      else
      {
         // name: value
        property_value = parseString(currentline.mid(colon + 1));
        nextOrDone();
      }

      result[property_name] = property_value;

    } while (currentindent == indent);

    return result;
  }
  else
  {
    // Parse string
    auto ret = parseString(currentline.mid(currentindent));
    nextOrDone();
    return ret;
  }
}

QStringList Parser::extractFields(const QString & str)
{
  QStringList result;

  int begin = 0;
  int it = 0;

  bool inside_quotes = false;

  while (it != str.length())
  {
    QChar c = str.at(it);
    if (c == ',' && !inside_quotes)
    {
      result << str.mid(begin, it - begin);
      begin = it + 1;
    }
    else if (c == '"')
    {
      inside_quotes = !inside_quotes;
    }

    ++it;
  }

  Q_ASSERT(!inside_quotes);
  result << str.mid(begin, it - begin);
  return result;
}

yaml::Object Parser::parseObject(QString str)
{
  // Remove '}'
  str.chop(1);
  // Remove '{'
  str = str.mid(1);

  yaml::Object result{};

  QStringList fields = extractFields(str);

  for (QString f : fields)
  {
    f = f.trimmed();
    const int colon = f.indexOf(':');
    QString property_name = f.mid(0, colon);
    yaml::Value property_value = parseString(f.mid(colon + 2));

    result[property_name] = property_value;
  }

  return result;
}

yaml::Array Parser::parseArray(QString str)
{
  // Remove ']'
  str.chop(1);
  // Remove '['
  str = str.mid(1);

  yaml::Array result{};

  QStringList fields = extractFields(str);

  for (QString f : fields)
  {
    f = f.trimmed();
    result.underlyingList().append(parseString(f));
  }

  return result;
}

yaml::Value Parser::parseString(QString str)
{
  str = str.trimmed();

  if (str.endsWith('"'))
  {
    str.chop(1);
    str = str.mid(1);
  }

  return yaml::Value{ str };
}

int Parser::computeIndent(const QString & str)
{
  int i = 0;
  while (i < str.length() && str.at(i).isSpace())
    ++i;
  return i / 2;
}

int Parser::readPropertyName(const QString & str, int indent)
{
  int i = 2 * indent;
  while (i < str.length() && (str.at(i).isLetter() || str.at(i).isDigit()))
    ++i;

  if (i == str.length() || str.at(i) != ':')
    return -1;
  return i;
}

} // namespace yaml
