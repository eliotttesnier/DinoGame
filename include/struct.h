/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** struct_header
*/

#pragma once

#include "header.h"

typedef struct window_s {
    sfRenderWindow *window;
    sfView *view;
    sfVideoMode resolution;
    sfBool fullscreen;
    sfUint8 *icon;
} window_t;

typedef struct sprite_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    char *str;
} text_t;

typedef struct movement_s {
    sfVector2f direction;
    sfClock *clock;
} movement_t;

typedef struct animation_s {
    sfClock *clock;
} animation_t;

typedef enum scene_e {
    S_START_MENU = 0,
    S_GAME,
    S_OVER,
} scene_t;

#define NB_SFX 1

typedef enum sfx_e {
    SFX = 0,
} sfx_enum_t;

typedef struct sfx_s {
    sfMusic *sounds[NB_SFX];
} sfx_t;

typedef struct gamedata_s {
    struct window_s *window;
    struct sfx_s *sfx;
    enum scene_e scene;
    int max_score;
    int score;
} gamedata_t;
