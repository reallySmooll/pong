# pong
Pong clone in C++ with custom SDL wrapper.

## How To Build
### Dependencies
To build pong, you'll need a couple dependencies first:

> [!TIP]
> If you're using Arch Linux, you can install the packages as their named in this list.

> [!NOTE]
> Packages marked with a `bd` inside of parentheses `(bd)` are part of the `base-devel` package on Arch Linux which is probably already installed on your system.

> [!NOTE]
> Packages marked with a `wb` inside of parentheses `(wb)` are for cross-compilation from Linux to Windows. If you're on Linux and don't plan to play the game on Windows, you can skip these.

- cmake
- gcc (bd)
- make (bd)
- sdl2
- sdl2_image
- sdl2_mixer
- sdl2_ttf
- mingw-w64-binutils (wb)
- mingw-w64-crt (wb)
- mingw-w64-gcc (wb)
- mingw-w64-headers (wb)
- mingw-w64-winpthreads (wb)

### Building (Release Configuration)
To build the project all you need to do is run this command (inside the root of the project):

```bash
$ mkdir build
$ cmake -S . -B build
$ cmake --build build -j4
```

And that's it, now you can play pong!

### Building (Debug Configuration)
The above commands were to build pong using the `Release` configuration which optimizes the program so it's as fast as possible while sacrificing some disk space (not a lot) and removes debug symbols.

If you'd like to build pong to debug it (for some reason) you can run these commands:

```bash
$ mkdir build
$ cmake -S . -B build -DBUILD_TYPE=true
$ cmake --build build -j4
```

And that's it. Pong will be now built using the `Debug` configuration.

### Building (Windows)
If (for some reason) you'd like to cross-compile pong from Linux to Windows, you can do so by running the following commands:

```bash
$ mkdir build
$ cmake -S . -B build (-DBUILD_TYPE=true if you want to build with the `Debug` configuration) -DCMAKE_TOOLCHAIN_FILE=./toolchains/toolchain-x86_64-w64-mingw32.cmake
$ cmake --build build -j4
```

And now you've got a Windows binary of pong compiled from Linux!
