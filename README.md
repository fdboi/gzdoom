# GZDoom on OpenGL ES 3.2

A port of GZDoom targeting RG351P devices specifically.

## Building
### Overview

First we'll compile for the host system. GZDoom is generating sources during build. We need to build the executables to do this later during the target system build.

GZDoom uses the [ZMusic](https://github.com/coelckers/ZMusic) library for sound. We'll need this as well.

We'll use [Ninja](https://ninja-build.org/), but plain old make would probably work too.

### Compile ZMusic for host:

```
cd ZMusic
mkdir build_host; cd build_host
cmake -G Ninja
ninja
sudo ninja install
```


### Compile GZDoom for **host** system:

```
cd gzdoom
mkdir build_host; cd build_host
cmake .. -G Ninja
ninja
```
### Setting up the [351ELEC](https://github.com/fewtarius/351ELEC) toolchain:

* Run `make world` if not done already.
* Change `ELEC_PATH` in [setup_toolchain.sh](setup_toolchain.sh) to your 351ELEC repo.
* Source the script in your shell: `. setup_toolchain.sh`
* `echo $CC` should now return aarch64 gcc.
* Don't use normal cmake, `$CMAKE` has `CMAKE_TOOLCHAIN_FILE` set.


### Compile ZMusic for target system:

Make sure to get the `CMAKE_INSTALL_PREFIX` right or you'll be in pain.

```
cd ZMusic
mkdir build_target; cd build_target
$CMAKE .. -G Ninja -DCMAKE_INSTALL_PREFIX=/home/user/gits/351ELEC/build.351ELEC-RG351P.aarch64-dev/toolchain/aarch64-libreelec-linux-gnueabi/sysroot/usr/ -DCMAKE_BUILD_TYPE=Release
ninja
ninja install
```

You should now have release libraries for ZMusic installed in the toolchain.

### Compile GZDoom for target system:


```
cd gzdoom
mkdir build_target; cd build_target
$CMAKE .. -G Ninja -DCMAKE_POLICY_DEFAULT_CMP0058=NEW -DIMPORT_EXECUTABLES=../build_host/ImportExecutables.cmake -DCMAKE_BUILD_TYPE=RELEASE
ninja
```


## Running

Copy files to device:

`gzdoom`, `fm_banks`, `soundfonts`, `*.pk3` files from `gzdoom/build_target`

and the ZMusic library: `$CMAKE_INSTALL_PREFIX/lib/libzmusic.so*`

You'll also need a Doom WAD. Place all these in the same folder.

Joysticks work out of the box. Buttons need to be configured.

Then do `LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./gzdoom`

Use `-file <file>` to load additional mods. IWADs can be chosen in the prompt on startup or with `-iwad <file>`

Will take a while to load due to shader compilation.

If EmuStation gets in the way, do: `systemctl stop emustation`

Config path: `~/.config/gzdoom/`


---

Original README below:

---

# Welcome to GZDoom!

[![Build Status](https://github.com/coelckers/gzdoom/workflows/Continuous%20Integration/badge.svg)](https://github.com/coelckers/gzdoom/actions?query=workflow%3A%22Continuous+Integration%22)

## GZDoom is a modder-friendly OpenGL and Vulkan source port based on the DOOM engine

Copyright (c) 1998-2019 ZDoom + GZDoom teams, and contributors

Doom Source (c) 1997 id Software, Raven Software, and contributors

Please see license files for individual contributor licenses

Special thanks to Coraline of the 3DGE team for allowing us to use her README.md as a template for this one.

### Licensed under the GPL v3
##### https://www.gnu.org/licenses/quick-guide-gplv3.en.html
---

## How to build GZDoom

To build GZDoom, please see the [wiki](https://zdoom.org/wiki/) and see the "Programmer's Corner" on the bottom-right corner of the page to build for your platform.

