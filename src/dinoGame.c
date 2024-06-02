/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** dinoGame
*/

#include "header.h"

const scene_loop_t scene_arr[3] = {
    start_loop,
    game_loop,
    over_loop,
};

void execute_scene_loop(gamedata_t *gamedata, sfEvent *event)
{
    scene_arr[gamedata->scene](gamedata, event);
}

int dinoGame(void)
{
    gamedata_t *gamedata = malloc(sizeof(gamedata_t));
    sfEvent event;

    fill_gamedata(gamedata);
    while (sfRenderWindow_isOpen(gamedata->window->window)) {
        execute_scene_loop(gamedata, &event);
    }
    return 0;
}
