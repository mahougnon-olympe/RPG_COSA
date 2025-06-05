/*
** EPITECH PROJECT, 2025
** the window opening function
** File description:
** window.c
*/

#include "../include/my_rpg.h"

static void handle_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

struct epi *attribution1(sfVideoMode mode)
{
    struct epi *picture = malloc(sizeof(struct epi));

    if (!picture)
        exit(84);
    picture->e_pos.x = mode.width / 2;
    picture->e_pos.y = mode.height / 2 - 50;
    picture->scale.x = 0.1;
    picture->scale.y = 0.1;
    picture->org.x = 785.5;
    picture->org.y = 196;
    picture->clock = sfClock_create();
    return picture;
}

struct epi *attribution2(struct epi *pi)
{
    pi->epit = sfTexture_createFromFile("ressources/epitech.png", NULL);
    if (!pi->epit)
        exit(84);
    pi->epi = sfSprite_create();
    sfSprite_setTexture(pi->epi, pi->epit, sfTrue);
    sfSprite_setOrigin(pi->epi, pi->org);
    sfSprite_setPosition(pi->epi, pi->e_pos);
    return pi;
}

struct epi *clock_handle(struct epi *pi)
{
    pi->time = sfClock_getElapsedTime(pi->clock);
    pi->second = pi->time.microseconds / 1000000.0;
    if (pi->second > 0.01) {
        if (pi->scale.x < 1 && pi->scale.y < 1) {
        pi->scale.x += 0.001;
        pi->scale.y += 0.001;
        }
        sfClock_restart(pi->clock);
    }
    return pi;
}

void destroying(struct epi *pi, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfSprite_destroy(pi->epi);
    sfTexture_destroy(pi->epit);
    free(pi);
}

int window(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {1900, 1080, 32};
    struct epi *pi = attribution1(mode);

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    pi = attribution2(pi);
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event);
        pi = clock_handle(pi);
        sfSprite_setScale(pi->epi, pi->scale);
        sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
        sfRenderWindow_drawSprite(window, pi->epi, NULL);
        sfRenderWindow_display(window);
    }
    destroying(pi, window);
    return 0;
}
