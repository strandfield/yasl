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
    FirstBindingMethod = 0,
    AutoBinding = FirstBindingMethod,
    MacroBinding,
    SignalBinding,
    ChainableBinding,
    ReferenceBinding,
    StaticVoidBinding,
    ConstVoidBinding,
    VoidBinding,
    StaticBinding,
    SimpleBinding,
    ConstructorBinding,
    DestructorBinding,
    OperatorBinding,
    FreeFunctionBinding,
    FreeFunctionAsStaticBinding,
    LastBindingMethod = FreeFunctionAsStaticBinding,
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
    case Function::MacroBinding:
      return "macros";
    case Function::SignalBinding:
      return "signals";
    case Function::ChainableBinding:
      return "chainable";
    case Function::ReferenceBinding:
      return "reference";
    case Function::StaticVoidBinding:
      return "static-void";
    case Function::ConstVoidBinding:
      return "const-void";
    case Function::VoidBinding:
      return "void";
    case Function::StaticBinding:
      return "static";
    case Function::SimpleBinding:
      return "simple";
    case Function::ConstructorBinding:
      return "ctor";
    case Function::DestructorBinding:
      return "dtor";
    case Function::OperatorBinding:
      return "op";
    case Function::FreeFunctionBinding:
      return "free";
    case Function::FreeFunctionAsStaticBinding:
      return "freestatic";
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
    if (str == "macros")
      return MacroBinding;
    else if (str == "signals")
      return SignalBinding;
    else if (str == "chainable")
      return ChainableBinding;
    else if (str == "reference")
      return ReferenceBinding;
    else if (str == "static-void")
      return StaticVoidBinding;
    else if (str == "const-void")
      return ConstVoidBinding;
    else if (str == "void")
      return VoidBinding;
    else if (str == "static")
      return StaticBinding;
    else if (str == "simple")
      return SimpleBinding;
    else if (str == "ctor")
      return ConstructorBinding;
    else if (str == "dtor")
      return DestructorBinding;
    else if (str == "op")
      return OperatorBinding;
    else if (str == "free")
      return FreeFunctionBinding;
    else if (str == "freestatic")
      return FreeFunctionAsStaticBinding;
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
