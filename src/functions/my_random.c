/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** my_random
*/

#include "header.h"
#include <stdlib.h>
#include <time.h>

int my_random(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1) + min);
}
