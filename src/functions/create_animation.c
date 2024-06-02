/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** create_animation
*/

#include "header.h"

animation_t *create_animation()
{
    animation_t *animation = malloc(sizeof(animation_t) * 1);

    animation->clock = sfClock_create();
    return (animation);
}
