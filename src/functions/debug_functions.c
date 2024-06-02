/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** debug_functions
*/

#include "header.h"

void print_flag(void)
{
    printf(ANSI_COLOR_RED "POINT" ANSI_COLOR_RESET "\n");
}

void print_entryflag(void)
{
    printf(ANSI_COLOR_RED "ENTRY_POINT" ANSI_COLOR_RESET "\n");
}

void print_exitflag(void)
{
    printf(ANSI_COLOR_RED "EXIT_POINT" ANSI_COLOR_RESET "\n");
}
