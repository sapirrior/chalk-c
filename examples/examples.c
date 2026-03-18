/*
 * examples.c — chalk-c usage examples
 *
 * Compile:  gcc -Wall -o examples examples.c
 * Run:      ./examples
 */

#include <stdio.h>
#include "../src/chalk.h"

/* ── Helpers ──────────────────────────────────────────────────────────────── */

static void section(const char *title) {
    printf("\n" bold white "── %s " reset "\n", title);
}

/* ── 1. Basic foreground colors ───────────────────────────────────────────── */

static void ex_basic_colors(void) {
    section("Basic Foreground Colors");

    /* cprint(color, "text") is the simplest way to print a colored line.
     * It adds a newline and resets the style automatically. */

    cprint(black,   "black");
    cprint(red,     "red");
    cprint(green,   "green");
    cprint(yellow,  "yellow");
    cprint(blue,    "blue");
    cprint(magenta, "magenta");
    cprint(cyan,    "cyan");
    cprint(white,   "white");
    cprint(gray,    "gray  (same as grey)");
}

/* ── 2. Bright foreground colors ──────────────────────────────────────────── */

static void ex_bright_colors(void) {
    section("Bright Foreground Colors");

    /* Append _bright to any color name for a more vivid variant. */

    cprint(red_bright,     "red_bright");
    cprint(green_bright,   "green_bright");
    cprint(yellow_bright,  "yellow_bright");
    cprint(blue_bright,    "blue_bright");
    cprint(magenta_bright, "magenta_bright");
    cprint(cyan_bright,    "cyan_bright");
    cprint(white_bright,   "white_bright");
}

/* ── 3. Background colors ─────────────────────────────────────────────────── */

static void ex_backgrounds(void) {
    section("Background Colors");

    /* Prefix bg_ to any color for a background.
     * Combine with a foreground color for readable text. */

    cprint(bg_black   white, "bg_black   + white");
    cprint(bg_red     white, "bg_red     + white");
    cprint(bg_green   black, "bg_green   + black");
    cprint(bg_yellow  black, "bg_yellow  + black");
    cprint(bg_blue    white, "bg_blue    + white");
    cprint(bg_magenta white, "bg_magenta + white");
    cprint(bg_cyan    black, "bg_cyan    + black");
    cprint(bg_white   black, "bg_white   + black");

    printf("\n");
    cprint(bg_red_bright     white, "bg_red_bright");
    cprint(bg_green_bright   black, "bg_green_bright");
    cprint(bg_yellow_bright  black, "bg_yellow_bright");
    cprint(bg_blue_bright    white, "bg_blue_bright");
    cprint(bg_magenta_bright white, "bg_magenta_bright");
    cprint(bg_cyan_bright    black, "bg_cyan_bright");
    cprint(bg_white_bright   black, "bg_white_bright");
}

/* ── 4. Modifiers ─────────────────────────────────────────────────────────── */

static void ex_modifiers(void) {
    section("Modifiers");

    cprint(bold,          "bold");
    cprint(dim,           "dim");
    cprint(italic,        "italic");
    cprint(underline,     "underline  (alias: ul)");
    cprint(ul,            "ul         (alias: underline)");
    cprint(strikethrough, "strikethrough  (alias: st)");
    cprint(st,            "st             (alias: strikethrough)");
    cprint(inverse,       "inverse  — swaps fg and bg");
    cprint(overline,      "overline");
    cprint(blink,         "blink  (terminal support varies)");
}

/* ── 5. Chaining styles ───────────────────────────────────────────────────── */

static void ex_chaining(void) {
    section("Chaining Styles");

    /* String literal concatenation — just place macros side by side.
     * Order does not matter for color; put modifiers before the color. */

    cprint(bold red,              "bold red");
    cprint(bold green,            "bold green");
    cprint(bold yellow,           "bold yellow");
    cprint(dim cyan,              "dim cyan");
    cprint(italic magenta,        "italic magenta");
    cprint(ul blue,               "ul blue");
    cprint(bold ul white,         "bold ul white");
    cprint(bold st red,           "bold st red");
    cprint(bg_blue bold white,    "bg_blue bold white");
    cprint(bg_yellow bold black,  "bg_yellow bold black");
    cprint(bg_red bold ul white,  "bg_red bold ul white");
}

/* ── 6. Using printf directly ─────────────────────────────────────────────── */

static void ex_printf(void) {
    section("Using printf Directly");

    /* When you need format specifiers (%s, %d, etc.) use printf.
     * Always end with reset to avoid bleeding color into the next line. */

    const char *filename = "main.c";
    int         line     = 42;
    float       pct      = 98.6f;

    printf(red    "Error"   reset " in %s at line %d\n",  filename, line);
    printf(yellow "Warning" reset " — disk usage %.1f%%\n", pct);
    printf(green  "OK"      reset " — all tests passed\n");
    printf(cyan   "Info"    reset " — server started on port %d\n", 8080);

    /* csprint wraps a literal in a style without a newline.
     * Useful for coloring part of a larger printf. */

    printf("Status: " csprint(bold green, "running") " | PID: %d\n", 1234);
    printf("File:   " csprint(ul cyan, "src/main.c") " — %d lines\n", 320);
}

/* ── 7. Storing colors in variables ──────────────────────────────────────────*/

static void ex_variables(void) {
    section("Storing Colors in Variables");

    /* Colors are plain C strings — store them in const char * variables
     * and use them anywhere a string is valid. */

    const char *ok_color   = bold green;
    const char *err_color  = bold red;
    const char *info_color = cyan;

    printf("%sPASS%s test_parser\n",   ok_color,   reset);
    printf("%sPASS%s test_lexer\n",    ok_color,   reset);
    printf("%sFAIL%s test_codegen\n",  err_color,  reset);
    printf("%sINFO%s 3 of 4 passed\n", info_color, reset);

    /* You can also select colors at runtime. */

    int score = 72;
    const char *grade_color = (score >= 90) ? green :
                              (score >= 60) ? yellow : red;

    printf("Score: %s%d%s\n", grade_color, score, reset);
}

/* ── 8. Semantic presets ──────────────────────────────────────────────────── */

static void ex_presets(void) {
    section("Semantic Presets");

    /* Presets are pre-combined styles for common use cases.
     * Always follow with reset. */

    printf(CHALK_ERROR    " ERROR "    reset " — segmentation fault\n");
    printf(CHALK_WARN     " WARN  "    reset " — deprecated API used\n");
    printf(CHALK_SUCCESS  " OK    "    reset " — build completed\n");
    printf(CHALK_INFO     " INFO  "    reset " — loading config\n");
    printf(CHALK_DEBUG    " DEBUG "    reset " — entering main loop\n");
    printf(CHALK_TRACE    " TRACE "    reset " — malloc called\n");
    printf(CHALK_CRITICAL " CRITICAL " reset " — out of memory\n");
    printf(CHALK_MUTED    " MUTED "    reset " — skipping cache\n");
    printf(CHALK_HEADER   " HEADER "   reset " — section title\n");
    printf(CHALK_CODE     " CODE  "    reset " — inline code style\n");
    printf(CHALK_LINK     " LINK  "    reset " — https://example.com\n");
    printf(CHALK_SUBTLE   " SUBTLE"    reset " — minor annotation\n");
}

/* ── 9. Truecolor (RGB) ───────────────────────────────────────────────────── */

static void ex_truecolor(void) {
    section("Truecolor  RGB(r, g, b)");

    /* RGB() takes compile-time integer literals.
     * Requires a terminal with truecolor support (most modern terminals). */

    printf(RGB(217, 119,  87) "RGB(217, 119,  87) — brand orange" reset "\n");
    printf(RGB(  0, 200, 100) "RGB(  0, 200, 100) — mint green"   reset "\n");
    printf(RGB(100, 149, 237) "RGB(100, 149, 237) — cornflower"   reset "\n");
    printf(RGB(255, 215,   0) "RGB(255, 215,   0) — gold"         reset "\n");
    printf(RGB(147, 112, 219) "RGB(147, 112, 219) — medium purple" reset "\n");

    /* Truecolor background with foreground. */
    printf(BG_RGB( 30,  30,  30) RGB(217, 119, 87) bold
           "  BG_RGB(30,30,30) + RGB(217,119,87) + bold  " reset "\n");
}

/* ── 10. 256-color palette ────────────────────────────────────────────────── */

static void ex_256(void) {
    section("256-Color  ANSI256(n)");

    /* ANSI256() takes a compile-time integer 0–255.
     * More widely supported than truecolor. */

    printf(ANSI256(196) "ANSI256(196) — red"        reset "\n");
    printf(ANSI256( 46) "ANSI256( 46) — bright green" reset "\n");
    printf(ANSI256( 51) "ANSI256( 51) — aqua"        reset "\n");
    printf(ANSI256(226) "ANSI256(226) — yellow"      reset "\n");
    printf(ANSI256( 93) "ANSI256( 93) — purple"      reset "\n");
    printf(ANSI256(208) "ANSI256(208) — orange"      reset "\n");
    printf(ANSI256(240) "ANSI256(240) — dark gray"   reset "\n");

    /* Background 256-color. */
    printf(BG_ANSI256(22) white_bright
           "BG_ANSI256(22) — dark green bg" reset "\n");
}

/* ── 11. Advanced: explicit FG_ BG_ UPPER names ──────────────────────────── */

static void ex_advanced(void) {
    section("Advanced: Explicit UPPER Names");

    /* FG_ and BG_ prefixed names are available for users who want
     * unambiguous, explicit identifiers — identical values to the short ones. */

    printf(FG_RED    BOLD      "FG_RED + BOLD"               RESET "\n");
    printf(FG_CYAN   UNDERLINE "FG_CYAN + UNDERLINE"         RESET "\n");
    printf(BG_BLUE   FG_WHITE  BOLD "BG_BLUE + FG_WHITE + BOLD" RESET "\n");

    /* CHALK(style, "text") wraps in style + RESET as a string literal. */
    printf(CHALK(BOLD FG_MAGENTA, "CHALK(BOLD FG_MAGENTA, ...)") "\n");
    printf("Normal " CHALK(BOLD FG_YELLOW, "highlighted") " normal\n");
}

/* ── 12. Real-world: simple logger ───────────────────────────────────────────*/

static void ex_logger(void) {
    section("Real-World: Simple Logger");

    /* A minimal logger using presets and printf format strings. */

    #define LOG_ERROR(msg, ...)   printf(CHALK_ERROR   " ERR  " reset " " msg "\n", ##__VA_ARGS__)
    #define LOG_WARN(msg, ...)    printf(CHALK_WARN     " WARN " reset " " msg "\n", ##__VA_ARGS__)
    #define LOG_SUCCESS(msg, ...) printf(CHALK_SUCCESS  " OK   " reset " " msg "\n", ##__VA_ARGS__)
    #define LOG_INFO(msg, ...)    printf(CHALK_INFO     " INFO " reset " " msg "\n", ##__VA_ARGS__)
    #define LOG_DEBUG(msg, ...)   printf(CHALK_DEBUG    " DBG  " reset " " msg "\n", ##__VA_ARGS__)

    LOG_INFO("server starting on port %d", 3000);
    LOG_SUCCESS("connected to database");
    LOG_WARN("config file not found, using defaults");
    LOG_ERROR("failed to bind socket: %s", "address in use");
    LOG_DEBUG("event loop tick %d", 1);
}

/* ── 13. Real-world: progress-style output ────────────────────────────────── */

static void ex_progress(void) {
    section("Real-World: Build Output Style");

    const char *files[] = {
        "src/lexer.c", "src/parser.c", "src/codegen.c", "src/main.c"
    };
    int results[] = { 1, 1, 0, 1 };
    int n = 4, passed = 0;

    for (int i = 0; i < n; i++) {
        if (results[i]) {
            printf("  " green "✔" reset "  %s\n", files[i]);
            passed++;
        } else {
            printf("  " red "✘" reset "  %s\n", files[i]);
        }
    }

    printf("\n");
    if (passed == n)
        printf(bold green "All %d files compiled." reset "\n", n);
    else
        printf(bold red "%d error(s) — " reset "%d/%d succeeded.\n",
               n - passed, passed, n);
}

/* ── main ─────────────────────────────────────────────────────────────────── */

int main(void) {
    printf(bold cyan "chalk-c examples.c" reset "\n");

    ex_basic_colors();
    ex_bright_colors();
    ex_backgrounds();
    ex_modifiers();
    ex_chaining();
    ex_printf();
    ex_variables();
    ex_presets();
    ex_truecolor();
    ex_256();
    ex_advanced();
    ex_logger();
    ex_progress();

    printf("\n");
    return 0;
}
