/*
** EPITECH PROJECT, 2025
** the window opening function
** File description:
** window.c
*/

#include "../include/my_rpg.h"

void handle_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display(sfRenderWindow *window, sfSprite *back_image, sfEvent event)
{
    handle_event(window, event);
    sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
    sfRenderWindow_drawSprite(window, back_image, NULL);
    sfRenderWindow_display(window);
}

void destroy(sfRenderWindow *window, sfSprite *back_image,
    sfTexture *txt_bi)
{
    sfSprite_destroy(back_image);
    sfTexture_destroy(txt_bi);
    sfRenderWindow_destroy(window);
}

int window(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *txt_bi = sfTexture_createFromFile("media/combat1.png", NULL);
    sfSprite *back_image = sfSprite_create();
    sfVector2f scale_bi = {1.85, 1.85};

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    sfSprite_setTexture(back_image, txt_bi, sfTrue);
    sfSprite_setScale(back_image, scale_bi);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        display(window, back_image, event);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
