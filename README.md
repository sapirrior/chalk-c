# chalk-c

A lightweight, zero-dependency, header-only library for intuitive terminal coloring and styling in C. Inspired by JavaScript's Chalk.

## Installation

`chalk-c` is a header-only library. There is no need to compile separate source files or configure linkers.

1. Download `src/chalk.h`.
2. Place it in your project directory.
3. Include it in your C file: `#include "chalk.h"`

## Quickstart

The easiest way to use `chalk-c` is through the beginner-friendly `cprint` (prints with a newline) and `csprint` (styled string) macros.

```c
#include <stdio.h>
#include "chalk.h"

int main() {
    // Basic colored print with automatic newline and reset
    cprint(bold green, "✓ System initialized successfully.");

    // Inline styling within a standard printf
    printf("Status: %s\n", csprint(italic yellow, "Warning"));

    return 0;
}
