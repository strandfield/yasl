// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

int va_toInt(const QVariant & self)
{
  return self.toInt();
}

float va_toFloat(const QVariant & self)
{
  return self.toFloat();
}

double va_toDouble(const QVariant & self)
{
  return self.toDouble();
}