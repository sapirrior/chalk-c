/*
 * examples.cpp — chalk-c usage examples (C++)
 *
 * Compile:  g++ -Wall -std=c++17 -o examples_cpp examples.cpp
 * Run:      ./examples_cpp
 *
 * chalk.h works in C++ without any changes.
 * String literal macros concatenate naturally with std::cout.
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "../src/chalk.h"

/* ── Helpers ──────────────────────────────────────────────────────────────── */

static void section(const std::string &title) {
    std::cout << "\n" << bold << white << "── " << title << " " << reset << "\n";
}

/* ── 1. Basic foreground colors ───────────────────────────────────────────── */

static void ex_basic_colors() {
    section("Basic Foreground Colors");

    /* cprint works identically in C++ — it calls printf internally. */

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

static void ex_bright_colors() {
    section("Bright Foreground Colors");

    cprint(red_bright,     "red_bright");
    cprint(green_bright,   "green_bright");
    cprint(yellow_bright,  "yellow_bright");
    cprint(blue_bright,    "blue_bright");
    cprint(magenta_bright, "magenta_bright");
    cprint(cyan_bright,    "cyan_bright");
    cprint(white_bright,   "white_bright");
}

/* ── 3. Background colors ─────────────────────────────────────────────────── */

static void ex_backgrounds() {
    section("Background Colors");

    cprint(bg_black   white, "bg_black   + white");
    cprint(bg_red     white, "bg_red     + white");
    cprint(bg_green   black, "bg_green   + black");
    cprint(bg_yellow  black, "bg_yellow  + black");
    cprint(bg_blue    white, "bg_blue    + white");
    cprint(bg_magenta white, "bg_magenta + white");
    cprint(bg_cyan    black, "bg_cyan    + black");
    cprint(bg_white   black, "bg_white   + black");

    std::cout << "\n";
    cprint(bg_red_bright     white, "bg_red_bright");
    cprint(bg_green_bright   black, "bg_green_bright");
    cprint(bg_blue_bright    white, "bg_blue_bright");
    cprint(bg_magenta_bright white, "bg_magenta_bright");
    cprint(bg_cyan_bright    black, "bg_cyan_bright");
}

/* ── 4. Modifiers ─────────────────────────────────────────────────────────── */

static void ex_modifiers() {
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
}

/* ── 5. Chaining styles ───────────────────────────────────────────────────── */

static void ex_chaining() {
    section("Chaining Styles");

    cprint(bold red,             "bold red");
    cprint(bold green,           "bold green");
    cprint(dim cyan,             "dim cyan");
    cprint(italic magenta,       "italic magenta");
    cprint(ul blue,              "ul blue");
    cprint(bold ul white,        "bold ul white");
    cprint(bg_blue bold white,   "bg_blue bold white");
    cprint(bg_yellow bold black, "bg_yellow bold black");
    cprint(bg_red bold ul white, "bg_red bold ul white");
}

/* ── 6. Using std::cout ───────────────────────────────────────────────────── */

static void ex_cout() {
    section("Using std::cout");

    /* Macros are plain C string literals — they stream directly into cout. */

    std::cout << red    << "Error"   << reset << " in main.cpp at line 42\n";
    std::cout << yellow << "Warning" << reset << " — deprecated API used\n";
    std::cout << green  << "OK"      << reset << " — all checks passed\n";
    std::cout << cyan   << "Info"    << reset << " — server running\n";

    /* Mix styled and unstyled parts in a single line. */
    std::cout << "Build: " << bold << green << "SUCCESS" << reset
              << " (" << cyan << "4 targets" << reset << ")\n";

    std::cout << "File:  " << ul << blue << "src/main.cpp" << reset
              << " — 320 lines\n";
}

/* ── 7. Storing colors in std::string variables ───────────────────────────── */

static void ex_string_variables() {
    section("Storing Colors in std::string");

    /* Colors are C strings — assign to std::string and stream normally. */

    std::string ok    = std::string(bold) + green;
    std::string err   = std::string(bold) + red;
    std::string info  = cyan;
    std::string rst   = reset;

    std::cout << ok   << "PASS" << rst << " test_parser\n";
    std::cout << ok   << "PASS" << rst << " test_lexer\n";
    std::cout << err  << "FAIL" << rst << " test_codegen\n";
    std::cout << info << "INFO" << rst << " 2 of 3 passed\n";

    /* Select color at runtime based on a value. */
    int score = 54;
    const char *grade = (score >= 90) ? green :
                        (score >= 60) ? yellow : red;

    std::cout << "Score: " << grade << score << reset << "\n";
}

/* ── 8. Semantic presets ──────────────────────────────────────────────────── */

static void ex_presets() {
    section("Semantic Presets");

    std::cout << CHALK_ERROR    << " ERROR "    << reset << " — null pointer dereference\n";
    std::cout << CHALK_WARN     << " WARN  "    << reset << " — deprecated function called\n";
    std::cout << CHALK_SUCCESS  << " OK    "    << reset << " — build completed in 1.2s\n";
    std::cout << CHALK_INFO     << " INFO  "    << reset << " — loading configuration\n";
    std::cout << CHALK_DEBUG    << " DEBUG "    << reset << " — entering parse_expr()\n";
    std::cout << CHALK_TRACE    << " TRACE "    << reset << " — alloc 64 bytes at 0x7f3a\n";
    std::cout << CHALK_CRITICAL << " CRITICAL " << reset << " — stack overflow detected\n";
    std::cout << CHALK_MUTED    << " MUTED "    << reset << " — cache miss, skipping\n";
    std::cout << CHALK_HEADER   << " HEADER "   << reset << " — section title style\n";
    std::cout << CHALK_CODE     << " CODE  "    << reset << " — inline identifier style\n";
    std::cout << CHALK_LINK     << " LINK  "    << reset << " — https://example.com\n";
}

/* ── 9. Truecolor (RGB) ───────────────────────────────────────────────────── */

static void ex_truecolor() {
    section("Truecolor  RGB(r, g, b)");

    std::cout << RGB(217, 119,  87) << "RGB(217, 119,  87) — brand orange"  << reset << "\n";
    std::cout << RGB(  0, 200, 100) << "RGB(  0, 200, 100) — mint green"    << reset << "\n";
    std::cout << RGB(100, 149, 237) << "RGB(100, 149, 237) — cornflower"    << reset << "\n";
    std::cout << RGB(255, 215,   0) << "RGB(255, 215,   0) — gold"          << reset << "\n";
    std::cout << RGB(147, 112, 219) << "RGB(147, 112, 219) — medium purple" << reset << "\n";

    std::cout << BG_RGB(30, 30, 30) << RGB(217, 119, 87) << bold
              << "  BG_RGB dark + RGB orange + bold  " << reset << "\n";
}

/* ── 10. 256-color palette ────────────────────────────────────────────────── */

static void ex_256() {
    section("256-Color  ANSI256(n)");

    std::cout << ANSI256(196) << "ANSI256(196) — red"          << reset << "\n";
    std::cout << ANSI256( 46) << "ANSI256( 46) — bright green" << reset << "\n";
    std::cout << ANSI256( 51) << "ANSI256( 51) — aqua"         << reset << "\n";
    std::cout << ANSI256(226) << "ANSI256(226) — yellow"       << reset << "\n";
    std::cout << ANSI256( 93) << "ANSI256( 93) — purple"       << reset << "\n";
    std::cout << ANSI256(208) << "ANSI256(208) — orange"       << reset << "\n";
    std::cout << ANSI256(240) << "ANSI256(240) — dark gray"    << reset << "\n";

    std::cout << BG_ANSI256(22) << white_bright
              << "BG_ANSI256(22) — dark green bg" << reset << "\n";
}

/* ── 11. Advanced: explicit UPPER names ──────────────────────────────────── */

static void ex_advanced() {
    section("Advanced: Explicit UPPER Names");

    std::cout << FG_RED   << BOLD      << "FG_RED + BOLD"               << RESET << "\n";
    std::cout << FG_CYAN  << UNDERLINE << "FG_CYAN + UNDERLINE"         << RESET << "\n";
    std::cout << BG_BLUE  << FG_WHITE  << BOLD << "BG_BLUE FG_WHITE BOLD" << RESET << "\n";

    /* CHALK macro works in C++ too — produces a string literal. */
    std::cout << CHALK(BOLD FG_MAGENTA, "CHALK(BOLD FG_MAGENTA, ...)") << "\n";
    std::cout << "Normal " << CHALK(BOLD FG_YELLOW, "highlighted") << " normal\n";
}

/* ── 12. Real-world: C++ logger class ────────────────────────────────────── */

static void ex_logger() {
    section("Real-World: Simple C++ Logger");

    struct Logger {
        static void error(const std::string &msg) {
            std::cout << CHALK_ERROR   << " ERR  " << reset << " " << msg << "\n";
        }
        static void warn(const std::string &msg) {
            std::cout << CHALK_WARN    << " WARN " << reset << " " << msg << "\n";
        }
        static void ok(const std::string &msg) {
            std::cout << CHALK_SUCCESS << " OK   " << reset << " " << msg << "\n";
        }
        static void info(const std::string &msg) {
            std::cout << CHALK_INFO    << " INFO " << reset << " " << msg << "\n";
        }
        static void debug(const std::string &msg) {
            std::cout << CHALK_DEBUG   << " DBG  " << reset << " " << msg << "\n";
        }
    };

    Logger::info("server starting on port 3000");
    Logger::ok("connected to database");
    Logger::warn("config file not found, using defaults");
    Logger::error("failed to bind socket: address in use");
    Logger::debug("event loop tick 1");
}

/* ── 13. Real-world: build output ────────────────────────────────────────── */

static void ex_build_output() {
    section("Real-World: Build Output Style");

    const char *files[] = {
        "src/lexer.cpp", "src/parser.cpp", "src/codegen.cpp", "src/main.cpp"
    };
    const bool ok[] = { true, true, false, true };
    const int  n    = 4;

    int passed = 0;
    for (int i = 0; i < n; i++) {
        if (ok[i]) {
            std::cout << "  " << green << "\xe2\x9c\x94" << reset << "  " << files[i] << "\n";
            ++passed;
        } else {
            std::cout << "  " << red << "\xe2\x9c\x98" << reset << "  " << files[i] << "\n";
        }
    }

    std::cout << "\n";
    if (passed == n)
        std::cout << bold << green << "All " << n << " files compiled." << reset << "\n";
    else
        std::cout << bold << red << (n - passed) << " error(s) \xe2\x80\x94 "
                  << reset << passed << "/" << n << " succeeded.\n";
}
/* ── main ─────────────────────────────────────────────────────────────────── */

int main() {
    std::cout << bold << cyan << "chalk-c examples.cpp" << reset << "\n";

    ex_basic_colors();
    ex_bright_colors();
    ex_backgrounds();
    ex_modifiers();
    ex_chaining();
    ex_cout();
    ex_string_variables();
    ex_presets();
    ex_truecolor();
    ex_256();
    ex_advanced();
    ex_logger();
    ex_build_output();

    std::cout << "\n";
    return 0;
}
