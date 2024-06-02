/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rpg_macro
*/

#pragma once

#include "header.h"

#define X_TOS(x, rx) ((x * rx) / 1920)
#define Y_TOS(y, ry) ((y * ry) / 1080)
#define ABS(i) (i < 0 ? i * -1 : i)
#define IS_NEG(i) (i < 0 ? 1 : 0)
#define VEC(x, y) ((sfVector2f){x, y})
#define IS_LCASE(c) (c >= 'a' && c <= 'z' ? 1 : 0)
#define IS_UCASE(c) (c >= 'A' && c <= 'Z' ? 1 : 0)
#define IS_LETTER(c) (IS_LCASE(c) == 1 || IS_UCASE(c) == 1 ? 1 : 0)
