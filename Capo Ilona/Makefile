##
## 
## Makefile
## File description:
## Makefile
##

SRC	=	carte_set.c\
		game.c\
		gameplay.c\
		joueur_set.c\
		show.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mygame

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f $(OBJ) *~

fclean:	clean
		rm -f $(NAME)

re:	all clean
