/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** game_event
*/

#include "header.h"

void game_event(gamedata_t *gamedata, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(gamedata->window->window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(gamedata->window->window);
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace
            && !gamedata->player->jumping) {
            gamedata->player->movement->velocity.y = -JUMP_HEIGHT;
            gamedata->player->jumping = true;
        }
    }
}
