// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GEN_GENERATOR_H
#define YASL_GEN_GENERATOR_H

#include "project.h"

#include <QSet>
#include <QStack>

class QJsonObject;
class QTextStream;

class Generator
{
public:
  Generator(QJsonObject & db);

  void generate(Project & p);

private:
  static QString to_snake_case(const QString & camelCaseName);
  inline const QString & currentFileName() const { return mCurrentFileName; }

  enum OperatorSymbol {
    Invalid = 0,
    Assign,
    Eq,
    Neq,
    Less,
    Leq,
    Greater,
    Geq,
    Plus,
    UnaryPlus,
    Add,
    Minus,
    UnaryMinus,
    Sub,
    Mul,
    Div,
    Modulo,
    AddAssign,
    SubAssign,
    MulAssign,
    DivAssign,
    And,
    Or,
    AndAssign,
    OrAssign,
    Subscript,
    FunctionCall,
    PlusPlus,
    PreIncrement,
    PostIncrement,
    MinusMinus,
    PreDecrement,
    PostDecrement,
    LeftShift,
    RightShift,
    LeftShiftAssign,
    RightShiftAssign,
    Xor,
    XorAssign,
    BitwiseNot,
  };

  static OperatorSymbol getOperatorSymbol(const QString & str);

private:
  void generate(gen::FileRef file);
  void generate(QTextStream & out, gen::FileRef file);
  void generate(QTextStream & out, gen::ClassRef cla);
  void generate(QTextStream & out, gen::FunctionRef fun);
  void generateWithTemplates(QTextStream & out, gen::FunctionRef fun);
  void generateWithMacros(QTextStream & out, gen::FunctionRef fun);
  void generateOperator(QTextStream & out, gen::FunctionRef fun, OperatorSymbol op);
  void generate(QTextStream & out, gen::EnumRef enm);
  void generate(QTextStream & out, gen::NamespaceRef ns);

private:
  void fetchHeaderList(QSet<QString> & headers, gen::NodeRef node);
  void getHeader(QSet<QString> & headers, QString type) const;
  void registerHeader(const QString & type);

private:
  void fetchGeneratedTypes(QStringList & types, gen::NodeRef node);
  void generateHeader(gen::FileRef file);

private:
  void writeCopyrightMessage(QTextStream & out);

  QString prefix() const;
  QString enclosingEntity() const; // returns Namespace or Class
  QString enclosingName() const;
  QString enclosing_snake_name() const; // returns 'ns' if no enclosing, or the enclosing namespace/class name
  QString nameQualification() const;
  bool isMember() const;

private:
  QJsonObject& mDatabase;
  QString mCurrentFileName;
  QStack<gen::NodeRef> mProcessingStack;
};

#endif // YASL_GEN_GENERATOR_H
