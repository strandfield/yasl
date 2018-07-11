// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GEN_PROJECT_H
#define YASL_GEN_PROJECT_H

#include <QMap>
#include <QSharedPointer>
#include <QStringList>

namespace gen
{

enum class NodeType
{
  Namespace,
  Class,
  Enum,
  EnumConstant,
  Function,
};

struct Node
{
  Node(const QString & n, Qt::CheckState c = Qt::Checked);
  virtual ~Node() = default;

  template<typename T>
  bool is() const
  {
    return dynamic_cast<const T*>(this) != nullptr;
  }

  template<typename T>
  T & as()
  {
    return *dynamic_cast<T*>(this);
  }

  virtual QString displayedName() const { return name; }

  QString name;
  Qt::CheckState checkState;
};
typedef QSharedPointer<Node> NodeRef;

struct EnumConstant : public Node
{
  EnumConstant(const QString & n);
  ~EnumConstant() = default;
};
typedef QSharedPointer<EnumConstant> EnumConstantRef;


struct Enum : public Node
{
  Enum(const QString & n);
  ~Enum() = default;
  QMap<QString, EnumConstantRef> values;
};
typedef QSharedPointer<Enum> EnumRef;

struct Function : public Node
{
  Function(const QString & n);
  ~Function() = default;

  QString returnType;
  QStringList parameters;
  bool isExplicit;
  bool isStatic;
  bool isConst;
  bool isDeleted;

  QString displayedName() const override;
};
typedef QSharedPointer<Function> FunctionRef;

struct Constructor : public Function
{
  Constructor(const QString & n);
  ~Constructor() = default;

  QString displayedName() const override;

};
typedef QSharedPointer<Constructor> ConstructorRef;

struct Class : public Node
{
  Class(const QString & n);
  ~Class() = default;

  QMap<QString, EnumRef> enums;
  QList<FunctionRef> functions;
  bool derivedFromQObject;

  bool isEmpty() const;

  ConstructorRef addConstructor(const QString & name);
  FunctionRef addFunction(const QString & name);
  EnumRef getEnum(const QString & name);

};
typedef QSharedPointer<Class> ClassRef;


struct Namespace : public Node
{
  Namespace();
  explicit Namespace(const QString & n);
  ~Namespace() = default;

  QMap<QString, QSharedPointer<Namespace>> namespaces;
  QMap<QString, ClassRef> classes;
  QMap<QString, EnumRef> enums;
  QList<FunctionRef> functions;

  QSharedPointer<Namespace> getNamespace(const QString & name);
  ClassRef getClass(const QString & name);
  EnumRef getEnum(const QString & name);

  FunctionRef addFunction(const QString & name);
};
typedef QSharedPointer<Namespace> NamespaceRef;


struct File : public Node
{
  File(const QString & p);

  QString path;
  int error;
  Namespace globalNamespace;
};
typedef QSharedPointer<File> FileRef;


} // namespace gen

class Project
{
public:

  typedef gen::File File;

  //bool load(const QString & filePath);
  //void save(const QString & filePath);

  void addFiles(const QStringList & files);

  QStringList includeDirs;
  QList<QSharedPointer<File>> files;
};

Q_DECLARE_METATYPE(QSharedPointer<gen::Node>);

#endif // YASL_GEN_PROJECT_H
