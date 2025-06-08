/*
** EPITECH PROJECT, 2025
** the window opening function
** File description:
** window.c
*/

#include "../include/my_rpg.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
