/*
** EPITECH PROJECT, 2024
** DinoGame
** File description:
** game_process
*/

#include "header.h"

void player_update(gamedata_t *game)
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

void move_cactus(cactus_t *cactus)
{
    sfTime time = sfClock_getElapsedTime(cactus->movement->clock);
    float ratio = time.microseconds / 10000;

    cactus->pos.x += cactus->movement->velocity.x * (ratio - cactus->movement->deltaTime);
    sfSprite_setPosition(cactus->sprite->sprite, cactus->pos);
    cactus->movement->deltaTime = time.microseconds / 10000;
}

void cactus_update(gamedata_t *game)
{
    cactus_t *tmp = game->cactus;

    while (tmp != NULL) {
        move_cactus(tmp);
        add_score_cactus(game, tmp);
        if (is_on_cactus(game, tmp))
            game->scene = S_OVER;
        if (tmp->pos.x < 0 - tmp->sprite->rect.width) {
            del_cactus(game, tmp);
            break;
        }
        tmp = tmp->next;
    }
}

void generate_new_cactuses(gamedata_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->spawnCactus);
    float seconds = sfTime_asSeconds(time);

    if (seconds > my_random(2, 5)) {
        add_cactus(game);
        sfClock_restart(game->spawnCactus);
    }
}

void game_process(gamedata_t *game)
{
    player_update(game);
    cactus_update(game);
    generate_new_cactuses(game);
    printf("Score: %d\n", game->score);
}
