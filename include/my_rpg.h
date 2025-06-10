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
    sfTexture *t_bacgrd;
    sfSprite *bacgrd;
    sfVector2f e_pos;
    sfVector2f scale;
    sfVector2f org;
    sfClock *clock;
    sfTime time;
    float second;
};
struct dl {
    sfVideoMode t_m;
    sfTexture *t_fond;
    sfSprite *fond;
    sfVector2f scale;
    sfClock *clock;
    sfTime time;
    float duree;
    float second;
    sfText *txt1;
};
void play_music(char *musicfile);
float duree(sfClock *clock);
sfText *create_text(char *file, struct dl *dlg);
char *readfile(char *file);
int window(void);
#endif /* MY_RPG_H */
