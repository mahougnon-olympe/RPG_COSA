/*
** EPITECH PROJECT, 2025
** the window opening function
** File description:
** window.c
*/

#include "../include/my_rpg.h"

void destroy(sfRenderWindow *window, sfSprite *back_image, sfSprite *perso)
{
    sfSprite_destroy(perso);
    sfSprite_destroy(back_image);
    sfRenderWindow_destroy(window);
}

void handle_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display(sfRenderWindow *window, sfSprite *back_image, sfEvent event,
    sfSprite *perso)
{
    handle_event(window, event);
    sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
    sfRenderWindow_drawSprite(window, back_image, NULL);
    sfRenderWindow_drawSprite(window, perso, NULL);
    sfRenderWindow_display(window);
}

int window(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    sfSprite *back_image = create_sprite1("media/tuto1.png");
    sfSprite *perso = create_sprite2("media/test.png");
    int frame = 0;
    int animation_framerate = 103;

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        display(window, back_image, event, perso);
        if (frame == 0)
            animate_sprite(perso, 8);
        frame = (frame + 1) % animation_framerate;
    }
    destroy(window, back_image, perso);
    return 0;
}
