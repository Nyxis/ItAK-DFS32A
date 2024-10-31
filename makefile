CC = gcc
CFLAGS = -I include -Wall -Wextra
OBJ = src/main.o src/joueur.o src/carte.o

all: jeu

jeu: $(OBJ)
	$(CC) -o jeu $(OBJ)

src/main.o: src/main.c include/joueur.h include/carte.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/joueur.o: src/joueur.c include/joueur.h include/carte.h
	$(CC) $(CFLAGS) -c src/joueur.c -o src/joueur.o

src/carte.o: src/carte.c include/carte.h
	$(CC) $(CFLAGS) -c src/carte.c -o src/carte.o

clean:
	rm -f src/*.o jeu
