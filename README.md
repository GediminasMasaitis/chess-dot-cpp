# Chess.cpp

Chess.cpp is a C++ chess engine made from scratch. It uses a lot of common chess engine tecniques used many other engines, with a little bit of original ideas sprinkled in.

* Version 1: Using an evaluation smilar to [CPW engine](https://github.com/nescitus/cpw-engine) but adapted for bitboards, incrementally building up search features. Final ELO ~2680
* Version 2: Using a handcrafted evaluation optimised by [Texel tuning](https://github.com/AndyGrant/Ethereal/blob/master/Tuning.pdf). Enabled multithreaded search with lazy SMP. Final ELO ~2930 1CPU, ~3000 4CPU, ~3040 12CPU
* Version 3: Using a NNUE evaluation trained on self-generated data. Final ELO not measured since it will be equivalent to version 4, which whill be properly tested on CCRL.

For more details on each version see [changelog.md](changelog.md)

## Building

There are two ways of building the engine - Makefile and CMake.
CMake build has been primarily used only for debugging, but is confirmed to work for MSVC compiler. Makefile build has been only tested on Linux, and Windows running MinGW. Further instructions will only focus on the Makefile build.

Requirements:
* git
* gcc compiler
* In case of Windows: mingw with it's binaries available in PATH

For each of the builds, the binary will be generated in the `src/ChessDotCpp` directory.

### Release (performance) build
```
cd src/ChessDotCpp
make pgo INCBIN=1
```

### Release (performance) classical (non-NNUE) build
```
cd src/ChessDotCpp
make pgo INCBIN=1 CLASSICAL=1
```

### Selecting build archtecture
You can specify a build architecture for your engine, otherwhise it will default to `popcnt`, which is very slow on bidern hardwares. For more information about CPU architectures: https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html, search "march".

Foe example if you want to target AVX2:
```
cd src/ChessDotCpp
make pgo INCBIN=1 ARCH=avx2
```

## Special thanks
* [**Chess Programing Wiki**](https://www.chessprogramming.org) for teaching the basics and later on some more complex topics.
* [**Engine Programming Discord**](https://discord.gg/invite/YctB2p4) for answering many (often dumb) questions I had along the way.
* [**Luecx**](https://github.com/Luecx) for giving me endless tips regarding data generation and NNUE training, and for writing a NNUE trainer [CudAD](https://github.com/Luecx/CudAD) which I used to train my NNUE networks.
* [**Ciekce**](https://github.com/Ciekce) for helping me set up my engine to be cross-platform.
