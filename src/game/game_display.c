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

void display_cactus(gamedata_t *game)
{
    cactus_t *tmp = game->cactus;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(game->window->window, tmp->sprite->sprite, NULL);
        tmp = tmp->next;
    }
}

void game_display(gamedata_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    display_cactus(game);
    display_player(game);
    sfRenderWindow_display(game->window->window);
}
