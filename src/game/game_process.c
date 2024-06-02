/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** game_process
*/

#include "header.h"

void game_process(gamedata_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->player->movement->clock);
    float ratio = time.microseconds / 100000;

    game->player->movement->velocity.y += GRAVITY * (ratio - game->player->movement->deltaTime);
    if (game->player->movement->velocity.y > MAX_JUMP_SPEED)
        game->player->movement->velocity.y = MAX_JUMP_SPEED;
    if (game->player->movement->velocity.y < -MAX_JUMP_SPEED)
        game->player->movement->velocity.y = -MAX_JUMP_SPEED;
    game->player->pos.y += game->player->movement->velocity.y;
    if (game->player->pos.y > GROUND_Y) {
        game->player->pos.y = GROUND_Y;
        game->player->movement->velocity.y = 0;
        game->player->jumping = false;
    }
    sfSprite_setPosition(game->player->sprite->sprite, game->player->pos);
    game->player->movement->deltaTime = time.microseconds / 100000;
}
