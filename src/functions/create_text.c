/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** create text
*/

#include "header.h"

text_t *create_text(char *path)
{
    text_t *new = malloc(sizeof(text_t));

    new->font = sfFont_createFromFile(path);
    if (new->font == NULL)
        exit(84);
    new->text = sfText_create();
    if (new->text == NULL)
        exit(84);
    sfText_setFont(new->text, new->font);
    sfText_setString(new->text, "");
    return new;
}
