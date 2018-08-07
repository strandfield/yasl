// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_FUNCTION_H
#define YASL_META_FUNCTION_H

#include "project/node.h"

class Function : public Node
{
public:
  enum BindingMethod{
    AutoBinding,
    TemplateBinding,
    MacroBinding,
    SignalBinding,
  };

public:
  QString rename;
  QString returnType;
  QStringList parameters;
  bool isExplicit;
  bool isStatic;
  bool isConst;
  bool isDeleted;
  BindingMethod bindingMethod;

public:
  Function(const QString & n, Qt::CheckState c = Qt::Checked);
  ~Function() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }

  QString displayedName() const override;

  inline static QString serialize(BindingMethod bm)
  {
    switch (bm)
    {
    case Function::AutoBinding:
      break;
    case Function::TemplateBinding:
      return "templates";
      break;
    case Function::MacroBinding:
      return "macros";
      break;
    case Function::SignalBinding:
      return "signals";
      break;
    default:
      break;
    }

    return "auto";
  }

  template<typename T>
  static T deserialize(const QString & str);

  template<>
  static BindingMethod deserialize<BindingMethod>(const QString & str)
  {
    if (str == "templates")
      return TemplateBinding;
    else if (str == "macros")
      return MacroBinding;
    else if (str == "signals")
      return SignalBinding;
    return AutoBinding;
  }
};
typedef QSharedPointer<Function> FunctionRef;


struct Constructor : public Function
{
  Constructor(const QString & n, Qt::CheckState cs = Qt::Checked);
  ~Constructor() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }

  QString displayedName() const override;

};
typedef QSharedPointer<Constructor> ConstructorRef;

struct Destructor : public Function
{
  Destructor(const QString & n, Qt::CheckState cs = Qt::Checked);
  ~Destructor() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }

  QString displayedName() const override;

};
typedef QSharedPointer<Destructor> DestructorRef;


namespace json
{
Function::BindingMethod readBindingMethod(const QJsonObject & obj);
void writeBindingMethod(QJsonObject &obj, Function::BindingMethod bm);
}

#endif // YASL_META_FUNCTION_H
