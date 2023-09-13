# wx_gl_cube_tutorial

Modern OpenGL App (Core Profile) with wxWidgets as the UI Framework for displaying a simple 3D cube. 

![Cube](/cube.png)

## How this works

This app searches for the wxWidgets library using `FindPackage`. If not found, it downloads the library source from GitHub, compiles it, and links it with the main project. 

The super build pattern with `ExternalProject_Add` is used to achieve this.

## Requirements

This works on Windows, Mac, and Linux. You'll need `cmake` and a C++ compiler (tested on `clang`, `gcc`, and MSVC).

Linux builds require the GTK3 library and headers installed in the system. You can install them on Ubuntu using:

```sh
sudo apt install libgtk-3-dev
```

OpenGL tutorials require OpenGL development package on Linux (Windows and Mac should work out of the box):

```sh
sudo apt install libglu1-mesa-dev
```

## Building

To build the project, use:

```bash
cmake -S. -Bbuild
cmake --build build
```

This will create a directory named `build` and create all build artifacts there. The main executable can be found in the `build/subprojects/Build/wx_gl_cube_tutorial_core` folder.

---
Check out the blog for more! [www.justdevtutorials.com](https://www.justdevtutorials.com)
---

