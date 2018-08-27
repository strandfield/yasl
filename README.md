

# `Yasl` - A scripting language written in C++/Qt

`Yasl` is a small scripting language written using [libscript](https://github.com/RugessNome/libscript)
that provides a wrapper to the Qt framework, allowing you to create nice graphical user 
interfaces (GUI) or powerful console application.

**Note that the project is still at a very early stage. 
A lot of functionnalities of Qt are not yet exposed and there are currently 
no stability or performance guarantee.**

**!! Use at your own risk !!**


## Building and using the `Yasl`

Currently no binaries are provided. 

To build `Yasl`, you should start by cloning `libscript`:
```bash
git clone http://github.com/RugessNome/libscript.git
```

You can then clone this repository with the following Git command, 
```bash
git clone http://github.com/RugessNome/yasl.git
```
and finally  use CMake to generate project files for your favorite build system.

`Yasl` is built on top of `libscript`, and thus requires C++14 and the 
**filesystem TS**.

Both `Yasl` and `libscript` are distributed under the MIT license.
`Yasl` uses the Qt libraries, which are available either under the LGPL or 
under a commercial license.


## Examples

The `examples` folder contains some working scripts that can be run by passing them 
the `Yasl` executable.

For example,
```bash
yasl widget3.y
```

One can also run `Yasl` in interactive mode, in which case you will be able to enter a
series of commands.

Here is an example of an interactive session.
```bash
C:\>yasl
>>> 3 + 3
6
>>> print("Hello")
Hello
>>> :q
```

In the previous example, `:q` is a special command that ends the session.



## Features

All features from the `libscript` library are available in `Yasl`. 
You are invited to consult the project's repository [here](https://github.com/RugessNome/libscript) 
to learn more about it.

Not all classes from Qt are exposed yet, nor is there any plan to expose all of them.
You can get a rough idea of what is available and what is not by running `yasl-meta` 
and opening `meta/yasl.json`.
You can also generate an exhaustive and up to date list by building 
the `yasl-stats` tool, and executing this command:

```bash
yasl-stats -dump-tree 
```


## Documentation

Not available yet.

For the Qt classes, please check [doc.qt.io](http://doc.qt.io/).