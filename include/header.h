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

#define FRAMERATE 160
#define GROUND_Y 700
#define GRAVITY 2
#define JUMP_HEIGHT 12
#define MAX_JUMP_SPEED 12
#define CACTUS_SPEED 10

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
char **str_to_array(char *line, char *ban);
text_t *create_text(char *path);
movement_t *create_movement(void);
animation_t *create_animation(void);
void add_score_cactus(gamedata_t *gamedata, cactus_t *cactus);
void add_cactus(gamedata_t *game);
void del_cactus(gamedata_t *game, cactus_t *cactus);
bool is_on_cactus(gamedata_t *game, cactus_t *cactus);

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
