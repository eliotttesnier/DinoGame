/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** is_on_cactus
*/

#include "header.h"

bool is_on_cactus(gamedata_t *game, cactus_t *cactus)
{
    sfFloatRect dino = sfSprite_getGlobalBounds(game->player->sprite->sprite);
    sfFloatRect cac = sfSprite_getGlobalBounds(cactus->sprite->sprite);

    if (sfFloatRect_intersects(&dino, &cac, NULL))
        return (true);
    return (false);
}
