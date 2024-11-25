CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INC = -Iinclude

all: jeu_de_cartes

jeu_de_cartes: $(OBJ)
	$(CC) $(CFLAGS) -o jeu_de_cartes $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) jeu_de_cartes

.PHONY: all clean
