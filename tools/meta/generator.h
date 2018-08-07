// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_GENERATOR_H
#define YASL_META_GENERATOR_H

#include <QObject>

#include "project.h"
#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/function.h"

#include <QSet>
#include <QStack>

class HeaderFile;
class SourceFile;

class QTextStream;

class Generator : public QObject
{
  Q_OBJECT
public:
  Generator(const QString & dir, QObject *parent = nullptr);

  void generate(const ProjectRef & pro);

  inline const ProjectRef & project() const { return mProject; }

  struct TypeInfo : Type
  {
    TypeInfo() = default;
    TypeInfo(const Type & t);
  };

Q_SIGNALS:
  void generated(const FileRef & file);

private:
  static const QString endl;

  static const QString ClassBinderInclude;
  static const QString EnumBinderInclude;
  static const QString NamespaceBinderInclude;
  static const QString ClassBuilderInclude;
  static const QString EnumBuilderInclude;

private:
  static QString to_snake_case(const QString & camelCaseName);

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
  void generate(ModuleRef mod);
  void generate(FileRef file);
  QString generate(FunctionRef fun);
  QString generateWithTemplates(FunctionRef fun);
  QString generateWithMacros(FunctionRef fun);
  QString generateSignal(FunctionRef fun);
  QString generateOperator(FunctionRef fun, OperatorSymbol op);
  void generate(ClassRef cla);
  void generate(EnumRef enm);
  void generate(NamespaceRef ns);
  void generate(NodeRef n);

  QString fparam(FunctionRef fun, int n);
  QString fparam(const QString & p);
  QString fparams(const QStringList & params);
  QString fparams(const FunctionRef fun);

private:
  QString prefix() const;
  QString enclosingEntity() const; // returns Namespace or Class
  QString enclosingName() const;
  QString enclosing_snake_name() const; // returns 'ns' if no enclosing, or the enclosing namespace/class name
  QString nameQualification() const;
  QString removeQualification(QString name) const;
  bool isMember() const;

  HeaderFile & currentHeader();
  SourceFile & currentSource();
  QString currentHeaderDirectory();
  QString currentSourceDirectory();

  void recordGeneratedEnum(const QString & name);
  void recordGeneratedClass(const QString & name);
  void generateInjectedTypeList();

private:
  struct UnsupportedType { QString name; };

  void buildTypeInfo();
  TypeInfo & typeinfo(const QString & t);

private:
  friend class StateGuard;
  ProjectRef mProject;
  QMap<QString, TypeInfo> mTypeInfos;

  QString mRootDirectory;
  QStack<NodeRef> mProcessingStack;
  QString mCurrentModule;
  HeaderFile *mCurrentHeader;
  SourceFile *mCurrentSource;

  struct GeneratedTypes
  {
    QMap<QString, QSet<QString>> enums;
    QMap<QString, QSet<QString>> classes;
  };
  GeneratedTypes mGeneratedTypes;
};

#endif // YASL_META_GENERATOR_H
