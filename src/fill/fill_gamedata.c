/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** fill_gamedata
*/

#include "header.h"

void fill_window(gamedata_t *game)
{
    game->window = malloc(sizeof(window_t) * 1);
    game->window->fullscreen = false;
    game->window->resolution = (sfVideoMode){1920, 1080, 32};
    game->window->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    game->window->window = sfRenderWindow_create(game->window->resolution,
        "DinoGame", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(game->window->window, 60);
    sfRenderWindow_setView(game->window->window, game->window->view);
}

void fill_gamedata(gamedata_t *game)
{
    fill_window(game);
    game->scene = S_START_MENU;
    game->score = 0;
    game->sfx = NULL;
}
