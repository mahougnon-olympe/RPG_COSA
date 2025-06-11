/*
** EPITECH PROJECT, 2024
** my_rpg.h
** File description:
** all of prototypes
*/

#ifndef MY_RPG_H
    #define MY_RPG_H
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Window.h>
    #include <SFML/Window/Context.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <string.h>

struct epi {
    sfVideoMode m;
    sfTexture *epit;
    sfSprite *epi;
    sfVector2f e_pos;
    sfVector2f scale;
    sfVector2f org;
    sfClock *clock;
    sfTime time;
    float second;
};

typedef struct menu {
    sfTexture *pic;
    sfSprite *picture;
    sfVector2f sc;
    sfTexture *btn;
    sfSprite *button;
    sfVector2f bt_sc;
    sfVector2f bt_pos;
    sfVector2i ms_pos;
    sfTexture *mr;
    sfSprite *more;
    sfVector2f mr_sc;
    sfVector2f mr_pos;
    sfTexture *pm;
    sfSprite *pmore;
    sfVector2f pm_sc;
    sfTexture *sr;
    sfSprite *score;
    sfVector2f sr_sc;
    sfVector2f sr_pos;
} menu_t;

menu_t *init(void);
int the_window(void);
void handle_event(sfRenderWindow *window, sfEvent event);
struct epi *attribution1(void);
struct epi *attribution2(struct epi *pi);
struct epi *clock_handle(struct epi *pi);
void destroying(struct epi *pi, sfRenderWindow *window);
void next(menu_t *mn, sfRenderWindow* window, sfEvent event, struct epi *pi);
#endif /* MY_RPG_H */
