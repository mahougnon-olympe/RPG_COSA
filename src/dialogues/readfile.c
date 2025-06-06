/*
** EPITECH PROJECT, 2025
** read file
** File description:
** recup buffer
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

/*char *readfile(char *file)
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
}*/
