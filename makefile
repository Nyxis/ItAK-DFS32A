CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDES = -Iincludes
BIN = bin/jeu_de_cartes

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJ) $(BIN)
.PHONY: all clean