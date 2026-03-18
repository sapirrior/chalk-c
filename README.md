# chalk-c

Terminal color and styling for C — a single header file inspired by the Node.js [chalk](https://github.com/chalk/chalk) library.

---

## Installation

Copy `src/chalk.h` into your project and include it.

```c
#include "chalk.h"
```

No build system, no dependencies, no linking required.

---

## Quick Start

```c
#include <stdio.h>
#include "chalk.h"

int main(void) {
    cprint(bold green, "Build succeeded.");
    cprint(bold red,   "Build failed.");

    printf(yellow "Warning: %s" reset "\n", "low memory");

    return 0;
}
```

---

## API

### Colors

| Foreground   | Background      | Bright FG          | Bright BG               |
|--------------|-----------------|--------------------|-------------------------|
| `black`      | `bg_black`      | `red_bright`       | `bg_red_bright`         |
| `red`        | `bg_red`        | `green_bright`     | `bg_green_bright`       |
| `green`      | `bg_green`      | `yellow_bright`    | `bg_yellow_bright`      |
| `yellow`     | `bg_yellow`     | `blue_bright`      | `bg_blue_bright`        |
| `blue`       | `bg_blue`       | `magenta_bright`   | `bg_magenta_bright`     |
| `magenta`    | `bg_magenta`    | `cyan_bright`      | `bg_cyan_bright`        |
| `cyan`       | `bg_cyan`       | `white_bright`     | `bg_white_bright`       |
| `white`      | `bg_white`      | `gray` / `grey`    |                         |

### Modifiers

| Name            | Shorthand |
|-----------------|-----------|
| `bold`          |           |
| `dim`           |           |
| `italic`        |           |
| `underline`     | `ul`      |
| `strikethrough` | `st`      |
| `inverse`       |           |
| `overline`      |           |
| `blink`         |           |
| `reset`         |           |

### Helper Macros

| Macro                     | Description                                          |
|---------------------------|------------------------------------------------------|
| `cprint(style, "text")`   | Print styled text with a newline. No `printf` needed.|
| `csprint(style, "text")`  | Styled string literal for use inside `printf`.       |
| `CHALK(style, "text")`    | Same as `csprint`, uppercase variant.                |

### Extended Color

```c
RGB(217, 119, 87)       // truecolor foreground
BG_RGB(30, 30, 30)      // truecolor background
ANSI256(196)            // 256-color foreground
BG_ANSI256(22)          // 256-color background
```

### Semantic Presets

| Macro            | Appearance            |
|------------------|-----------------------|
| `CHALK_ERROR`    | Bold red              |
| `CHALK_WARN`     | Bold yellow           |
| `CHALK_SUCCESS`  | Bold green            |
| `CHALK_INFO`     | Bold cyan             |
| `CHALK_CRITICAL` | Bold white on red bg  |
| `CHALK_DEBUG`    | Gray                  |
| `CHALK_TRACE`    | Dim cyan              |
| `CHALK_MUTED`    | Dim white             |
| `CHALK_HEADER`   | Bold magenta          |
| `CHALK_CODE`     | Yellow                |
| `CHALK_LINK`     | Underline blue        |
| `CHALK_SUBTLE`   | Gray                  |

---

## Chaining

Styles are plain string literals and concatenate naturally.

```c
cprint(bold underline cyan, "Section title");
printf(bg_blue white bold "  Status: OK  " reset "\n");
```

Colors can also be stored in variables.

```c
const char *color = green;
printf("%sOK%s\n", color, reset);
```

---

## Examples

See the [`examples/`](examples/) folder for runnable demonstrations.

---

## License

MIT
