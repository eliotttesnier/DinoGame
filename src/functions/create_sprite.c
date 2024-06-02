/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** create_sprite
*/

#include "header.h"

sprite_t *create_sprite(char *path, sfIntRect rect)
{
    sprite_t *new = malloc(sizeof(sprite_t) * 1);

    new->rect = rect;
    new->texture = sfTexture_createFromFile(path, NULL);
    if (new->texture == NULL)
        exit(84);
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    return (new);
}

sfTexture *create_texture(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (texture == NULL)
        exit(84);
    return (texture);
}
