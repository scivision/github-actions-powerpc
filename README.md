# GitHub Actions PowerPC

GitHub Actions CI example workflow for PowerPC using QEMU.

Uses [GitHub Actions](https://github.com/uraimo/run-on-arch-action) to setup QEMU enviornment, cache, install packages, and run tests.

We use CMake to build a C program using PowerPC instructions that would fail on default GitHub Actions x86 arch.
