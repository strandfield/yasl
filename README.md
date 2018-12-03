

# `Yasl` - A scripting language written in C++/Qt

[![Build Status](https://api.travis-ci.org/RugessNome/yasl.svg?branch=master)](https://travis-ci.org/RugessNome/yasl)

`Yasl` is a small scripting language written using [libscript](https://github.com/RugessNome/libscript)
that provides a wrapper to the Qt framework, allowing you to create nice graphical user 
interfaces (GUI) or powerful console application.

**Note:** the project is still under development, use at your own risk.

## Building `Yasl`

Currently no binaries are provided, you need to clone and build the project yourself.

`Yasl` uses `libscript`, but it is included as a submodule so you don't need 
to clone it separetely, just take care to add `--recursive` when cloning.
```bash
git clone --recursive http://github.com/RugessNome/yasl.git
```

Then, you can generate the project files for your favorite build system 
using CMake.

```bash
mkdir build && cd build
cmake ..
```

Note that for this step to work, CMake needs to find a Qt 5 installation on your 
computer. 
On some system, you might need to modify the PATH or use `CMAKE_PREFIX_PATH` to 
point to the location of `qmake`.

Both `Yasl` and `libscript` are distributed under the MIT license.
The Qt framework is available either under the LGPL or under a commercial license.


## Using `Yasl`

Much like Python, `Yasl` can work two different ways: you can run a single script 
or have an interactive session.

The `examples` folder contains some scripts that you can try. 
Just move to this folder and type:

```bash
yasl locale2.y
```

This will run the script `locale2.y`.
On my computer, this prints:

```
First day of the week is: lundi
Second month of the year is: février
You are probably living in France
Your language: français
```

That should give you a decent hint at how my computer is configured. :wink:

`Yasl` also offers an interactive mode in which you can input a series of 
commands and see their output.
Interactive mode is launched when you don't provide an input file:

```bash
yasl
```

In such mode, a prompt appears, informing you that Yasl is listening.

```bash
>>>
```

We can start with really basic commands.

```bash
>>> 3+3
6
>>> "Hello".length()
5
>>> 1.0 / 2.0
0.5
>>> a = 5
5
>>> a + 2
7
```

These are really simple commands. If you got bored, you may type `:q` or 
call the function `App::exit()` to exit the program.

The function `App::loadModule()` is used to load a module and make all
the names it defines available in the interactive session.

```bash
>>> App::loadModule("widgets")
>>> l = newLabel("Hello World!", Ref<Widget>())
Label@0390E2F8
>>> l.show()
>>> 
```

This loads the "widgets" module and creates a QLabel that displays "Hello World!"

![Picture: Hello World](https://raw.githubusercontent.com/RugessNome/yasl/master/doc/assets/label-hello-world.png)


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

## Code-generation

A significant part of the code is generated.
A dedicated tool, called `yasl-meta`, was developed to manage which functions 
of the Qt framework are available.
This tool can work with `libclang` to import C++ code.

![Picture: Yasl meta](https://raw.githubusercontent.com/RugessNome/yasl/master/doc/assets/yasl-meta.png)
