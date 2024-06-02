/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** is_cactus_behind
*/

#include "header.h"

void add_score_cactus(gamedata_t *gamedata, cactus_t *cactus)
{
    if (cactus->givenPoint)
        return;
    if (cactus->pos.x + cactus->sprite->rect.width < gamedata->player->pos.x) {
        gamedata->score += 1;
        cactus->givenPoint = true;
    }
}
