/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** add_cactus
*/

#include "header.h"

void del_cactus(gamedata_t *game, cactus_t *cactus)
{
    cactus_t *tmp = game->cactus;

    if (tmp == cactus) {
        game->cactus = cactus->next;
        free(cactus);
        return;
    }
    while (tmp->next != cactus) {
        tmp = tmp->next;
    }
    tmp->next = cactus->next;
    free(cactus);
}

void add_cactus(gamedata_t *gamedata)
{
    cactus_t *new = malloc(sizeof(cactus_t));

    new->sprite = create_sprite("assets/SoloCactus.png", (sfIntRect){0, 0, 289, 500});
    new->givenPoint = false;
    new->pos = (sfVector2f){1920, GROUND_Y};
    sfSprite_setScale(new->sprite->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(new->sprite->sprite, new->pos);
    new->movement = create_movement();
    new->movement->velocity.x = -CACTUS_SPEED;
    new->next = gamedata->cactus;
    gamedata->cactus = new;
}
