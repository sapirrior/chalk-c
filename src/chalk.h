#ifndef CHALK_H
#define CHALK_H

/*
 * chalk.h — Terminal colors for C
 *
 * QUICKSTART (beginners):
 *
 *   #include "chalk.h"
 *
 *   cprint(red, "Hello!");                        // red text, newline
 *   cprint(bold green, "Done.");                  // bold green
 *   cprint(bg_blue white, "Highlighted");         // white on blue bg
 *
 *   printf(red "Error: %s" reset "\n", msg);      // inside printf
 *   printf(csprint(yellow, "Warning") "\n");      // wrapped shorthand
 *
 *   const char *c = green;                        // store a color
 *   printf("%sOK%s\n", c, reset);
 *
 * ADVANCED:
 *
 *   printf(FG_RED BOLD "text" RESET "\n");        // explicit prefixed names
 *   printf(RGB(217,119,87) "orange" RESET "\n");  // truecolor
 *   printf(ANSI256(196) "red256" RESET "\n");     // 256-color
 *   printf(CHALK(BOLD FG_CYAN, "styled") "\n");   // compose macro
 */

/* ── Reset ────────────────────────────────────────────────────────────────── */
#define reset         "\033[0m"
#define RESET         "\033[0m"

/* ── Modifiers (short) ────────────────────────────────────────────────────── */
#define bold          "\033[1m"
#define dim           "\033[2m"
#define italic        "\033[3m"
#define ul            "\033[4m"   /* underline shorthand */
#define underline     "\033[4m"
#define blink         "\033[5m"
#define inverse       "\033[7m"
#define hidden        "\033[8m"
#define st            "\033[9m"   /* strikethrough shorthand */
#define strikethrough "\033[9m"
#define overline      "\033[53m"

/* ── Modifiers (UPPER — same values, for advanced users) ─────────────────── */
#define BOLD          "\033[1m"
#define DIM           "\033[2m"
#define ITALIC        "\033[3m"
#define UNDERLINE     "\033[4m"
#define BLINK         "\033[5m"
#define RAPID_BLINK   "\033[6m"
#define INVERSE       "\033[7m"
#define HIDDEN        "\033[8m"
#define STRIKETHROUGH "\033[9m"
#define OVERLINE      "\033[53m"

/* ── Foreground colors (short, beginner-friendly) ────────────────────────── */
#define black         "\033[30m"
#define red           "\033[31m"
#define green         "\033[32m"
#define yellow        "\033[33m"
#define blue          "\033[34m"
#define magenta       "\033[35m"
#define cyan          "\033[36m"
#define white         "\033[37m"
#define gray          "\033[90m"
#define grey          "\033[90m"

/* ── Bright foreground (short) ───────────────────────────────────────────── */
#define red_bright     "\033[91m"
#define green_bright   "\033[92m"
#define yellow_bright  "\033[93m"
#define blue_bright    "\033[94m"
#define magenta_bright "\033[95m"
#define cyan_bright    "\033[96m"
#define white_bright   "\033[97m"

/* ── Background colors (short) ───────────────────────────────────────────── */
#define bg_black      "\033[40m"
#define bg_red        "\033[41m"
#define bg_green      "\033[42m"
#define bg_yellow     "\033[43m"
#define bg_blue       "\033[44m"
#define bg_magenta    "\033[45m"
#define bg_cyan       "\033[46m"
#define bg_white      "\033[47m"

/* ── Bright background (short) ───────────────────────────────────────────── */
#define bg_red_bright     "\033[101m"
#define bg_green_bright   "\033[102m"
#define bg_yellow_bright  "\033[103m"
#define bg_blue_bright    "\033[104m"
#define bg_magenta_bright "\033[105m"
#define bg_cyan_bright    "\033[106m"
#define bg_white_bright   "\033[107m"

/* ── Foreground (UPPER — explicit, for advanced users) ───────────────────── */
#define FG_BLACK      "\033[30m"
#define FG_RED        "\033[31m"
#define FG_GREEN      "\033[32m"
#define FG_YELLOW     "\033[33m"
#define FG_BLUE       "\033[34m"
#define FG_MAGENTA    "\033[35m"
#define FG_CYAN       "\033[36m"
#define FG_WHITE      "\033[37m"
#define FG_DEFAULT    "\033[39m"

#define FG_GRAY            "\033[90m"
#define FG_GREY            "\033[90m"
#define FG_BLACK_BRIGHT    "\033[90m"
#define FG_RED_BRIGHT      "\033[91m"
#define FG_GREEN_BRIGHT    "\033[92m"
#define FG_YELLOW_BRIGHT   "\033[93m"
#define FG_BLUE_BRIGHT     "\033[94m"
#define FG_MAGENTA_BRIGHT  "\033[95m"
#define FG_CYAN_BRIGHT     "\033[96m"
#define FG_WHITE_BRIGHT    "\033[97m"

/* ── Background (UPPER) ──────────────────────────────────────────────────── */
#define BG_BLACK      "\033[40m"
#define BG_RED        "\033[41m"
#define BG_GREEN      "\033[42m"
#define BG_YELLOW     "\033[43m"
#define BG_BLUE       "\033[44m"
#define BG_MAGENTA    "\033[45m"
#define BG_CYAN       "\033[46m"
#define BG_WHITE      "\033[47m"
#define BG_DEFAULT    "\033[49m"

#define BG_BLACK_BRIGHT    "\033[100m"
#define BG_RED_BRIGHT      "\033[101m"
#define BG_GREEN_BRIGHT    "\033[102m"
#define BG_YELLOW_BRIGHT   "\033[103m"
#define BG_BLUE_BRIGHT     "\033[104m"
#define BG_MAGENTA_BRIGHT  "\033[105m"
#define BG_CYAN_BRIGHT     "\033[106m"
#define BG_WHITE_BRIGHT    "\033[107m"

/* ── Truecolor ───────────────────────────────────────────────────────────── */
#define RGB(r,g,b)         "\033[38;2;" #r ";" #g ";" #b "m"
#define BG_RGB(r,g,b)      "\033[48;2;" #r ";" #g ";" #b "m"

/* ── 256-color ───────────────────────────────────────────────────────────── */
#define ANSI256(n)         "\033[38;5;" #n "m"
#define BG_ANSI256(n)      "\033[48;5;" #n "m"

/* ── Semantic presets ────────────────────────────────────────────────────── */
#define CHALK_ERROR        "\033[1;31m"
#define CHALK_WARN         "\033[1;33m"
#define CHALK_SUCCESS      "\033[1;32m"
#define CHALK_INFO         "\033[1;36m"
#define CHALK_MUTED        "\033[2;37m"
#define CHALK_HEADER       "\033[1;35m"
#define CHALK_CODE         "\033[0;33m"
#define CHALK_LINK         "\033[4;34m"
#define CHALK_SUBTLE       "\033[90m"
#define CHALK_CRITICAL     "\033[1;37;41m"
#define CHALK_DEBUG        "\033[0;90m"
#define CHALK_TRACE        "\033[2;36m"

/* ── Helper macros ───────────────────────────────────────────────────────── */

/* CHALK(style, "text") — styled string literal, no newline, no printf needed  */
/* use inside printf: printf(CHALK(bold red, "hi") "\n");                       */
#define CHALK(style, text)        style text RESET

/* csprint(style, "text") — alias of CHALK, more beginner-readable name        */
#define csprint(style, text)      style text RESET

/* cprint(style, "text") — prints styled text with newline, no printf needed   */
#define cprint(style, text)       printf(style text RESET "\n")

#endif
