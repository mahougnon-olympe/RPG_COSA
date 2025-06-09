##
## EPITECH PROJECT, 2024
## my makefile
## File description:
## for the compilation
##

SRC	=	src/*.c

NAME	=	my_rpg

all	:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -g3

clean	:
	rm -rf *~
	rm -rf *#
	rm -rf src/*~
	rm -rf include/*~
	rm -rf src/*#
	rm -rf include/*#

fclean	:	clean
	rm -f a.out
	rm -f $(NAME)
	rm -f tests/*~
	rm -f for_tests/*~
	rm -f *.log
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit-tests

re	:	fclean all

.PHONY	:	all clean fclean re

codingstyle	:
	coding-style . .
	cat coding-style-reports.log
