
/*
** EPITECH PROJECT, 2025
** dialogues
** File description:
** create and display the dialogues
*/

#include "../../include/my_rpg.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <sys/stat.h>


char *readfile(char *file)
{
    int nb = 0;
    int fd = open(file, O_RDONLY);
    char *content;
    struct stat s;

    stat(file, &s);
    content = malloc(sizeof(char) * (s.st_size + 1));
    if (!content)
        return NULL;
    nb = read(fd, content, s.st_size);
    content[s.st_size] = '\0';
    close(fd);
    return content;
}

sfText *create_text(char *file, struct dl *dlg)
{
    sfFont *font = sfFont_createFromFile("ressources/dialogues/Namaku.ttf");
    char *buffer = readfile(file);

    if (!font)
        return NULL;
    dlg->clock = sfClock_create();
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfWhite);
    sfText_setString(text, buffer);
    sfVector2f position = {500, 950};
    sfText_setPosition(text, position);
    return text;
}

void play_music(char *musicfile)
{
    sfMusic *music = sfMusic_createFromFile(musicfile);

    if (!music)
        return;
    sfMusic_play(music);
}

float duree(sfClock *clock) {
    sfTime duree = sfClock_getElapsedTime(clock);
    return sfTime_asSeconds(duree);
}