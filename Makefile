##
## EPITECH PROJECT, 2024
## my makefile
## File description:
## for the compilation
##

SRC =   src/main.c\
	src/window.c\
	src/dialogues/*.c\

all :
	gcc -o my_rpg $(SRC) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -g3

clean :
	rm -rf *~
	rm -rf *#
	rm -rf src/*~
	rm -rf include/*~
	rm -rf src/*#
	rm -rf include/*#

fclean : clean
	rm -rf a.out
	rm -rf my_rpg

re : fclean all
