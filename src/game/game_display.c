/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** game_display
*/

#include "header.h"

void display_player(gamedata_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->player->sprite->sprite, NULL);
}

void game_display(gamedata_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    display_player(game);
    sfRenderWindow_display(game->window->window);
}
