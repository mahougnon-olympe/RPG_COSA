/*
** EPITECH PROJECT, 2025
** the window opening function
** File description:
** window.c
*/

#include "../include/my_rpg.h"

sfSprite *create_sprite1(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *create_sprite2(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {0, 4 * 85, 50, 102};
    sfVector2f scale = {2, 2};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, area);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void animate_sprite(sfSprite *sprite, int frame_count)
{
    sfIntRect area = sfSprite_getTextureRect(sprite);

    area.left = (area.left + 50);
    if (area.left >= frame_count * 50)
        area.left = 0;
    sfSprite_setTextureRect(sprite, area);
}
