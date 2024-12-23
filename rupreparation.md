# Preparation for all my courses at Rutgers

If you are here, you are presumably taking one of my courses. All
require various software tools. This single file contains a number of
packages. You may not need to install them all, which ones you need
depend on the course. Please check with the syllabus of your course.

## Learning Developer Skills

Many courses will require using a standard Unix set of tools. This can be typing shell commands, or using build tools such as make, cmake, etc.
Of course if you are taking a course involving high-performance coding you will need to know C/C++, or possibly Rust going forward.
If you doubt your knowledge and feel unprepared, here are some resources to help you.

* [Curate Unix Commands (by Ritchie Cahill and Dov Kruger)](https://github.com/LinuxCrashCourse/LinuxCrashCourse)
* [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
* [GNU Make Tutorial](https://makefiletutorial.com/)
* [Git Tutorial](https://git-scm.com/book/en/v2)
* Resources from my C++ Course
  - [A C++ self-test that you can compile and run](https://github.com/StevensDeptECE/CPE553-CPP/blob/master/selftest/languagesummaryquiz.cc)
  - [A set of C++ bugs from easy to extremely hard](https://github.com/StevensDeptECE/CPE553-CPP/tree/master/BUGS)
  - [The notes from my C++ course summarizing each topic succinctly](https://github.com/StevensDeptECE/CPE553-CPP/blob/master/C%2B%2B_coursenotes_2022F.pdf)
* [Rust Tutorial](https://doc.rust-lang.org/book/title-page.html)

## VSCode

Microsoft VSCode is mostly open source (not fully). It has a huge variety of plugins. As a general text editor and Integrated Development Environment (IDE) it has a number of advantages and disadvantages.

* Plugins to format and syntax-check many programming languages
* Excellent support for Markdown documents like this including a previewer
* You can edit with multiple people across a network. This helps working with partners in class, you don't have to be collocated.
* Codeium plugin provides rudimentary AI help, not as good as others

* The [download link](https://code.visualstudio.com/download)
* [Windows script to install recommended plugins](https://github.com/RU-ECE/DovKrugerCourses/blob/main/files/vscodeinstructions/install_extensions_locally.bat)
* [Linux script to install recommended plugins](https://github.com/RU-ECE/DovKrugerCourses/blob/main/files/vscodeinstructions/install_extensions_locally.sh)

## Cursor

Much more sophisticated AI fork of VSCode. It's basically vscode, but with an AI plugin that uses a number of engines and directly pastes in code for you

* control-L lets you ask the AI questions about the code (you can specify which files it should look at)
* control-K lets you ask it to write code in the current edit buffer. But usually just typing in the buffer is enough it will complete anything you start.

Using an AI can make you far more productive, but as a student it is
critical to develop your own knowledge too, not just let the AI do the
thinking for you. If you have the AI do your homework, it may not be
correct, and you may not learn anything. On the other hand, you must learn to use the AI in order to be more productive.

[Cursor download](https://www.cursor.com/)

## Windows: WSL

If you are coding in windows and I require linux tools, one of the easiest ways to do this is Windows Subsystem for Linux (WSL). This is essentially a complete Linux running under windows. It's running under a "lightweight hypervisor, not technically a full virtual machine." I have not investigated, but it works well.

WSL2 can be used to develop in a linux environment on a windows machine, including graphics. This is quite useful, as all other attempts to port linux tools to windows involve weird little issues.

[WSL INSTALL](https://learn.microsoft.com/en-us/windows/wsl/install)

Since WSL is Ubuntu Linux under windows, anything you install can follow instructions for Ubuntu. There may be some weird problems with graphics since WSL is operating in some kind of virtual machine under windows, but it should mostly work.

## Windows: MSYS2

An alternative to a full linux install is MSYS2. This installs a linux shell and compatability libraries in windows. You can build programs with g++ and all other linux compilers, and the resulting code runs in windows with some dlls. This is much smaller than WSL, and the resulting code can be packaged up and given to anyone with windows, but the compatability layer has some interesting problems. Multithreaded programs won't work right. Sockets is using windows sockets so tehere is a compatability problem.

If you get MSYS2, then packages are install with pacman.
To find out all package names containing a string:

```bash
pacman -Ss | grep g++
```

The following list are packages I recommend installing:

```bash
pacman -S mingw64-?? [TBD]
pacman -S gdb cgdb make cmake
```

You will have to add /mingw64/bin to your path to get all the 64-bit binaries to be available

TODO: instructions on adding /mingw64/bin to path. Same for linux and Mac

## MacOSX

Apple does not play well with others. They support clang++ which is
close to g++, and for text programming, Apple is a flavor of unix, but
for anything graphical, they just don't support
anything. Specifically, Apple deprecated OpenGL, so they stopped
supporting any new versions and it will stop working some day. And
they promised to support Vulkan and then reneged.

So if you are building a C++ program to write files, everything is fine.
But if your code involves graphics, there is no good high performance solution.
There are ported gaming libraries (SDL2).

## g++

For anyone developing C++, this is the portable standard. The clang++ compiler is more research-oriented, usually has more language features earlier, and has a back end that is completely different (llvm). The two compilers are effectively almost identical but if using clang++ you will debug with lldb, and this is different.

Mac uses clang++, it is difficult and complicated to install g++ so not covered here.

For windows or linux, we are going to assume g++ which has better
low-level support for assembler.

```bash
sudo apt install g++
```

## gdb and cgdb

If you program, you will need to debug. gdb is the low level debugger
for g++, and most graphical debuggers seem to use it as the underlying
engine, just providing a front end. The graphical front end can be
important. It makes it a lot easier to use and makes debugging more
efficient.  But if you ever debug a low-end computer, like a raspberry
pi with very little RAM, gdb will usually work in text mode when
nothing else will.

```bash
sudo apt install gdb # on ubuntu and popos linux
sudo apt install cgdb # Better and worse than gdb
```

gdb has one notable annoying problem. Every time the program prints,
it ruins the format of the screen, and you have to type control-L to
refresh to see the correct current screen, but that wipes out the
output that scrolled data. There is a different debugger, cgdb with
improved graphics, fixing the annoying refresh bug but with different low-level commands
so good for C/C++ code, not as good for looking at assembly-level.

Also, cgdb has screen problems of its own on some linuxes. Try it and see if it works for you.

```bash
sudo apt isntall cgdb
```

## OpenGL and windowing libraries

OpenGL is the portable way to write 3D graphics using the power of
your graphics card. Except for Apple who cooperate with no one, and except
for the fact the OpenGL never tried to manage windows. So while OpenGL will draw graphics, you also need a library that will open a window. And there are many competing versions.

```bash
sudo apt install libopengl-dev libglfw3-dev freeglut3-dev
```

From the above you can see that one of the biggest problems is
figuring out the name of the package you want to install. They are
getting better about this. Most development libraries start with lib
and and with -dev but not all, and "freeglut3" is an example of stupid
naming that persists.

## Vulkan

Vulkan is the new OpenGL. It's a bit more complicated to use, but it's the future.
Supported on all major platforms except for Apple which initially supported it but then reneged.

Vulkan is a low-level API, so you can't just use it like OpenGL. You need to write a lot more code.
The advantage is that it can be much more efficient. For example, if you just want to draw in 2d,
or you want to write code running on the GPU, Vulkan provides complete control over the pipeline.

## NVIDIA CUDA

## AMD ROCm HIP


## Image Libraries

My favorite is google webp, which is about 30% better compression than
jpeg, a lot better than png, and .webp always compresses better than
either. Also this library can write png and jpeg files I think.

```bash
sudo apt install libwebp-dev
```

## OpenCV

## Icarus Verilog

Icarus verilog is not a full commercial package, but it's so much simpler than Xilinx that for teaching the language I find it very useful. Also, Xilinx is the leader, but it doesn't work on Mac, so if you have a Mac, try icarus.

On windows, you will have to add icarus verilog to the path
TBD: windows path tutorial 

[Icarus verilog download]

I recommend working exclusively in system verilog, the most recent standard is 2012.

```bash
iverilog -g2012 yourfilename.sv
```

## Installing Java

Java is slowly dying, but if you count all the derivative languages
(Kotlin, Julia, Clojure) the JVM is a major force. It's a little less
efficient than C++ but for situations where performance isn't the
first priority it has major portability advantages.

On windows, just install Oracle's java compiler. Be aware that Oracle
has rapacious licensing practices, which is one very good reason why
Java is dying. But for personal use it's free.

For linux, just use openjdk. Java bills itself as "write once, run anywhere" but that isn't quite true. The problem is there have been some incompatabilities in versions. There are old programs that only run in JDK1.8, and there are new programs that only run in JDK17 or newer.

The good news is, that's only two versions, and you could always install both. For class, I would recommand JDK17 or better by default:

```bash
sudo apt install openjdk-17
```

## Intellij

Visual Code is such a good general IDE and free that it has hurt the
market for IDEs in general, but as a general tool it will always be
worse than a specific one. Jetbrains, a company in Prague makes the
best IDEs for C++, Java and Python. They all run the same codebase,
written in Java.  The Java one is called Intellij, and it is free for
educational or personal use.

I recommend it highly, you can just build a project, add code and
debug it.  It's a bit more complicated to do that in vscode. Make no
mistake, going beyond that, the tool is wildly complicated. Building a
program in Java and deploying it is a serious devops issue. See tools
here like ant and mvn.


