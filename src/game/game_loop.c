/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** game_loop
*/

#include "header.h"

void game_loop(gamedata_t *gamedata, sfEvent *event)
{
    game_event(gamedata, event);
    game_process(gamedata);
    game_display(gamedata);
}
