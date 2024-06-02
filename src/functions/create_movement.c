/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** crate_movement
*/

#include "header.h"

movement_t *create_movement()
{
    movement_t *movement = malloc(sizeof(movement_t) * 1);

    movement->clock = sfClock_create();
    movement->deltaTime = 0;
    movement->velocity = (sfVector2f){0, 0};
    return (movement);
}
