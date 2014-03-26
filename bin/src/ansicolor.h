#ifndef __ANSICOLOR_H__
#define __ANSICOLOR_H__

// Includes //
#include <stdio.h>

// Definitions //
#define ANSI_RESET         "\e[0m"
#define ANSI_BOLD_ON       "\e[1m"
#define ANSI_BOLD_OFF      "\e[22m"

#define ANSI_FG_BLACK      "\e[30m"
#define ANSI_FG_RED        "\e[31m"
#define ANSI_FG_GREEN      "\e[32m"
#define ANSI_FG_YELLOW     "\e[33m"
#define ANSI_FG_BLUE       "\e[34m"
#define ANSI_FG_MAGENTA    "\e[35m"
#define ANSI_FG_CYAN       "\e[36m"
#define ANSI_FG_WHITE      "\e[37m"
#define ANSI_FG_DEFAULT    "\e[39m"

#define ANSI_BG_BLACK      "\e[40m"
#define ANSI_BG_RED        "\e[41m"
#define ANSI_BG_GREEN      "\e[42m"
#define ANSI_BG_YELLOW     "\e[43m"
#define ANSI_BG_BLUE       "\e[44m"
#define ANSI_BG_MAGENTA    "\e[45m"
#define ANSI_BG_CYAN       "\e[46m"
#define ANSI_BG_WHITE      "\e[47m"
#define ANSI_BG_DEFAULT    "\e[49m"

#endif // __ANSICOLOR_H__
