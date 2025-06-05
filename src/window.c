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

int window(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {800, 600, 32};

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event);
        sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
