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
    sfRenderWindow_setFramerateLimit(game->window->window, FRAMERATE);
    sfRenderWindow_setView(game->window->window, game->window->view);
}

void fill_player(gamedata_t *game)
{
    game->player = malloc(sizeof(player_t) * 1);
    game->player->sprite = create_sprite("assets/dino.png",
        (sfIntRect){0, 0, 512, 512});
    game->player->movement = create_movement();
    game->player->animation = create_animation();
    game->player->pos = (sfVector2f){500, 0};
    sfSprite_setPosition(game->player->sprite->sprite, game->player->pos);
    sfSprite_setScale(game->player->sprite->sprite, (sfVector2f){0.5, 0.5});
    game->player->jumping = false;
}

void fill_gamedata(gamedata_t *game)
{
    fill_window(game);
    fill_player(game);
    // fill_background(game);
    game->scene = S_GAME;
    game->score = 0;
    game->sfx = NULL;
}
