# Playground for C application
## Description 
The project allows you to play in C with different toolchain. Scope is only the main.c file with Makefile based buildsystem. Project points to Training-C git submodule which contains custom C library, sorted by topics. 

## Branches
master branch contains main.c template file and can be easily derived and used in several branches (e.g branch test/singly-linked-list where the main is a special testbench to test functions from Training-C/src/linked-list.c)

dev branch contains template with a file to parse.

## Build
### Use the native toolchain
Here the command to build the application :

```toto@toto$ make native```

...And to clean :

```toto@toto$ make clean```

After build complete, all artifact can be found under the out/ directory. 

### Use specific toolchain
Let's take an example with the arm-none-eabi v12.3 toolchain :

Before work on the project, you might set the environnment variables and binary toolchain in the path, by using such a shell script : 

```
#!/bin/sh

ARCH=arm
CROSS_COMPILE=arm-none-eabi-

PATH=$PATH:$HOME/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin
export ARCH CROSS_COMPILE PATH
cd playground
```
You will have to source this env :
```source set_env.sh```

After that, Makefile can use the toolchain gcc path to build your project.
The ARM core can be choosen in the makefile.conf configuration file. 

```toto@toto$ make arm```

```toto@toto$ make clean```

## Run & debug
Go under out directory and type for run :

```toto@toto$ ./main```

To debug using GDB, type:

```toto@toto$ gdb main```

## Code coverage
After running or debugging the application, .gcno & .gcda files could be used for code coverage. To achieve that and directly produce HTML output files, you can use the bash script in the project root directory :

```./code_coverage.sh```

Artifact do not have the same name depending on the target it was built for. So you might follow the CLI configuration to produce the coverage reports.

