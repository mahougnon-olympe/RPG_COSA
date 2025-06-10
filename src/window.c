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

struct epi *attribution1(void)
{
    struct epi *picture = malloc(sizeof(struct epi));

    if (!picture)
        exit(84);
    picture->m.width = 1900;
    picture->m.height = 1080;
    picture->m.bitsPerPixel = 32;
    picture->e_pos.x = picture->m.width / 2;
    picture->e_pos.y = picture->m.height / 2 - 50;
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
    pi->t_bacgrd = sfTexture_createFromFile("ressources/COSAM.png", NULL);
    if (!pi->epit)
        exit(84);
    pi->epi = sfSprite_create();
    pi->bacgrd = sfSprite_create();
    sfSprite_setTexture(pi->epi, pi->epit, sfTrue);
    sfSprite_setOrigin(pi->epi, pi->org);
    sfSprite_setPosition(pi->epi, pi->e_pos);
    sfSprite_setTexture(pi->bacgrd, pi->t_bacgrd, sfTrue);
    sfSprite_setScale(pi->bacgrd, (sfVector2f){3.8, 2.16});
    return pi;
}

struct epi *clock_handle(struct epi *pi)
{
    pi->time = sfClock_getElapsedTime(pi->clock);
    pi->second = pi->time.microseconds / 1000000.0;
    if (pi->second > 0.01) {
        if (pi->scale.x < 1 && pi->scale.y < 1) {
        pi->scale.x += 0.00175;
        pi->scale.y += 0.00175;
        }
        sfClock_restart(pi->clock);
    }
    return pi;
}

void destroying(struct epi *pi, struct dl *dlg,sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfSprite_destroy(pi->epi);
    sfTexture_destroy(pi->epit);
    sfText_destroy(dlg->txt1);
    free(pi);
    free(dlg);
}

int window(void)
{
    int i = 1;
    sfRenderWindow *window;
    sfEvent event;
    struct epi *pi = attribution1();
    struct dl *dlg = malloc(sizeof(struct dl));
    sfMusic *e_mus = sfMusic_createFromFile("ressources/m/riser.ogg");
    sfBool music_played = sfFalse;

    window = sfRenderWindow_create(pi->m, "My_RPG", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    pi = attribution2(pi);
    sfMusic_play(e_mus);
    dlg->txt1 = create_text("ressources/dialogues/texte1.txt", dlg);
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event);
        pi = clock_handle(pi);
        sfSprite_setScale(pi->epi, pi->scale);
        sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
        if (pi->scale.x < 1 && pi->scale.y < 1) {
           sfRenderWindow_drawSprite(window, pi->epi, NULL);
        }
        if (!(pi->scale.x < 1 && pi->scale.y < 1)) {
           sfRenderWindow_drawSprite(window, pi->bacgrd, NULL);
           sfRenderWindow_drawText(window, dlg->txt1, NULL);           
        }
        if (sfMusic_getStatus((const sfMusic *) e_mus) == sfStopped && i == 1)
            music_played = sfTrue;
        if (music_played == sfTrue) {
            play_music("ressources/dialogues/Bienvenue.mp3");
            music_played = sfFalse;
            i = 0;
        }
        sfRenderWindow_display(window);
    }
    destroying(pi, dlg, window);
    return 0;
}