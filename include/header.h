/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rpg_header
*/

#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include "math.h"

#include "debug_header.h"
#include "macro.h"
#include "struct.h"

#define ATTACK_SPEED_ENY 1.5
#define INV_SIZE 32
#define FRAMERATE 160
#define SPEED 7500 * 1.75

typedef void (*scene_loop_t)(gamedata_t *gamedata, sfEvent *event);

//Game
int dinoGame(void);

//Filling
void fill_gamedata(gamedata_t *game);

//scene loops
void start_loop(gamedata_t *gamedata, sfEvent *event);
void game_loop(gamedata_t *gamedata, sfEvent *event);
void over_loop(gamedata_t *gamedata, sfEvent *event);

//events
void start_event(gamedata_t *game, sfEvent *event);
void game_event(gamedata_t *game, sfEvent *event);
void over_event(gamedata_t *game, sfEvent *event);

//displays
void start_display(gamedata_t *game);
void game_display(gamedata_t *game);
void over_display(gamedata_t *game);

//process
void start_process(gamedata_t *game);
void game_process(gamedata_t *game);
void over_process(gamedata_t *game);

//animations

//Collisions

//Functions
sfVector2f get_pixcoord(gamedata_t *game);
bool is_on_sprite(sprite_t *sprite, sfVector2f pix);
char *my_itoa(int nbr);
int my_nbrlen(int nbr);
int my_random(int min, int max);
text_t *create_text(char *path);
char **str_to_array(char *line, char *ban);

//save
void save(gamedata_t *game);

//load

//free
void free_game(gamedata_t *game);

//sprite creation
sprite_t *create_sprite(char *path, sfIntRect rect);
sfTexture *create_texture(char *path);

//SFX
void play_sfx(gamedata_t *game, sfx_enum_t sfx);
