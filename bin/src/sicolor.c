/**************************************************\
* Display ANSI Color Schemes with Space Invaders   *
* Inspired by a bash script by pfh and lolilolicon *
* Sam Stuewe (C) 2014 Licensed under the terms of  *
* the GNU Public License version 2                 *
\**************************************************/

// Includes //
#include <stdio.h>
#include "ansicolor.h"

// Main Function //
int main (void) {

    /* Top Row Invaders */
    printf(ANSI_FG_BLACK   "  ▀▄   ▄▀   " 
           ANSI_FG_RED	   "  ▄▄▄████▄▄▄  " 
           ANSI_FG_GREEN   "   ▄██▄   " 
           ANSI_FG_YELLOW  "   ▀▄   ▄▀   " 
           ANSI_FG_BLUE	   "  ▄▄▄████▄▄▄  " 
           ANSI_FG_MAGENTA "   ▄██▄   " 
           ANSI_FG_CYAN	   "   ▀▄   ▄▀   \n");

    printf(ANSI_FG_BLACK   " ▄█▀███▀█▄  " 
           ANSI_FG_RED	   " ███▀▀██▀▀███ " 
           ANSI_FG_GREEN   " ▄█▀██▀█▄ " 
           ANSI_FG_YELLOW  "  ▄█▀███▀█▄  " 
           ANSI_FG_BLUE	   " ███▀▀██▀▀███ " 
           ANSI_FG_MAGENTA " ▄█▀██▀█▄ " 
           ANSI_FG_CYAN	   "  ▄█▀███▀█▄  \n");

    printf(ANSI_FG_BLACK   "█▀███████▀█ " 
           ANSI_FG_RED	   " ▀▀███▀▀███▀▀ " 
           ANSI_FG_GREEN   " ▀█▀██▀█▀ " 
           ANSI_FG_YELLOW  " █▀███████▀█ " 
           ANSI_FG_BLUE	   " ▀▀███▀▀███▀▀ " 
           ANSI_FG_MAGENTA " ▀█▀██▀█▀ " 
           ANSI_FG_CYAN	   " █▀███████▀█ \n");

    printf(ANSI_FG_BLACK   "▀ ▀▄▄ ▄▄▀ ▀ "
           ANSI_FG_RED	   "  ▀█▄ ▀▀ ▄█▀  "
           ANSI_FG_GREEN   " ▀▄    ▄▀ " 
           ANSI_FG_YELLOW  " ▀ ▀▄▄ ▄▄▀ ▀ " 
           ANSI_FG_BLUE	   "  ▀█▄ ▀▀ ▄█▀  " 
           ANSI_FG_MAGENTA " ▀▄    ▄▀ " 
           ANSI_FG_CYAN	   " ▀ ▀▄▄ ▄▄▀ ▀ \n");

    printf("\n" ANSI_BOLD_ON);

    /* Bottom Row Invaders */
    printf(ANSI_FG_BLACK   "▄ ▀▄   ▄▀ ▄ " 
           ANSI_FG_RED	   "  ▄▄▄████▄▄▄  " 
           ANSI_FG_GREEN   "   ▄██▄   " 
           ANSI_FG_YELLOW  " ▄ ▀▄   ▄▀ ▄ " 
           ANSI_FG_BLUE	   "  ▄▄▄████▄▄▄  " 
           ANSI_FG_MAGENTA "   ▄██▄   " 
           ANSI_FG_CYAN	   " ▄ ▀▄   ▄▀ ▄ \n" );

    printf(ANSI_FG_BLACK   "█▄█▀███▀█▄█ " 
           ANSI_FG_RED	   " ███▀▀██▀▀███ " 
           ANSI_FG_GREEN   " ▄█▀██▀█▄ " 
           ANSI_FG_YELLOW  " █▄█▀███▀█▄█ " 
           ANSI_FG_BLUE	   " ███▀▀██▀▀███ " 
           ANSI_FG_MAGENTA " ▄█▀██▀█▄ " 
           ANSI_FG_CYAN	   " █▄█▀███▀█▄█ \n" );

    printf(ANSI_FG_BLACK   "▀█████████▀ " 
           ANSI_FG_RED	   " ▀▀▀██▀▀██▀▀▀ " 
           ANSI_FG_GREEN   " ▀▀█▀▀█▀▀ " 
           ANSI_FG_YELLOW  " ▀█████████▀ " 
           ANSI_FG_BLUE	   " ▀▀▀██▀▀██▀▀▀ " 
           ANSI_FG_MAGENTA " ▀▀█▀▀█▀▀ " 
           ANSI_FG_CYAN	   " ▀█████████▀ \n" );

    printf(ANSI_FG_BLACK   " ▄▀     ▀▄  "
           ANSI_FG_RED	   " ▄▄▀▀ ▀▀ ▀▀▄▄ "
           ANSI_FG_GREEN   " ▄▀▄▀▀▄▀▄ " 
           ANSI_FG_YELLOW  "  ▄▀     ▀▄  " 
           ANSI_FG_BLUE	   " ▄▄▀▀ ▀▀ ▀▀▄▄ " 
           ANSI_FG_MAGENTA " ▄▀▄▀▀▄▀▄ " 
           ANSI_FG_CYAN	   "  ▄▀     ▀▄  \n" );

    printf(ANSI_RESET "\n");

    /* Defender's Tank */
    printf("\t\t\t\t\t  ▌\n\n");
    printf("\t\t\t\t\t▌\n\n");
    printf("\t\t\t\t      ▄█▄\n");
    printf("\t\t\t\t  ▄█████████▄\n");
    printf("\t\t\t\t  ▀▀▀▀▀▀▀▀▀▀▀\n");

    return 0;
}

// vim: set ts=4 sw=4 et: