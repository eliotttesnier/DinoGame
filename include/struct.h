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
    sfVector2f velocity;
    sfClock *clock;
    float deltaTime;
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

typedef struct player_s {
    sprite_t *sprite;
    movement_t *movement;
    animation_t *animation;
    sfVector2f pos;
    bool jumping;
} player_t;

typedef struct background_s {
    sprite_t *backOne;
    sprite_t *backTwo;
    sprite_t *frontOne;
    sprite_t *frontTwo;
} background_t;

typedef struct cactus_s {
    sprite_t *sprite;
    movement_t *movement;
    sfVector2f pos;
    bool givenPoint;
    struct cactus_s *next;
} cactus_t;

typedef struct gamedata_s {
    struct window_s *window;
    struct sfx_s *sfx;
    enum scene_e scene;
    struct player_s *player;
    struct cactus_s *cactus;
    struct background_s *background;
    int max_score;
    int score;
} gamedata_t;
