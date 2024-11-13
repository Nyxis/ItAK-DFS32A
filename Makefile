# Nom de l'exécutable avec extension .exe
EXEC = jeu.exe

# Compilateur et options de compilation
# Le compilateur à utiliser (gcc dans ce cas)
CC = gcc
# Les options de compilation, ici :
# -Wall : Active tous les avertissements du compilateur.
# -Wextra : Active des avertissements supplémentaires.
# -g : Inclut des informations de débogage dans les fichiers compilés.
CFLAGS = -Wall -Wextra -g

# Fichiers sources
# Liste des fichiers source à compiler, ici les fichiers .c
SRCS = main.c carte.c jeu.c interface.c string.c

# Fichiers objets
# Transformation de la liste de fichiers sources (.c) en fichiers objets (.o)
OBJS = $(SRCS:.c=.o)

# Affiche les commandes disponibles
help:
	@echo "Options disponibles dans le Makefile :"
	@echo "  make build   : Compile le programme et génère l'exécutable $(EXEC)"
	@echo "  make run     : Compile puis exécute le programme"
	@echo "  make clean   : Supprime les fichiers objets et l'exécutable"
	@echo "  make all     : Nettoie, compile puis exécute le programme (équivalent à build + run)"
	@echo "  make help    : Affiche cette aide"

# Cible pour créer l'exécutable
# Cette cible dépend de l'exécutable $(EXEC). Elle génère l'exécutable si besoin.
build: $(EXEC)

# Règle pour créer l'exécutable
# La cible $(EXEC) (ici jeu.exe) dépend des fichiers objets $(OBJS).
# Si les fichiers objets sont à jour, cette règle crée l'exécutable.
# Utilisation de gcc avec les options $(CFLAGS) pour générer l'exécutable.
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Règle pour compiler les fichiers objets
# Cette règle compile chaque fichier source .c en fichier objet .o.
# Le nom du fichier cible est défini par %.o et %.c, où % correspond au nom du fichier sans extension.
# Cela est nécessaire car la compilation des fichiers source en objets permet de les lier ensuite pour créer l'exécutable.
# Si un fichier source n'a pas été modifié, il ne sera pas recompilé, ce qui accélère les constructions successives.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Règle de nettoyage
# Cette règle supprime les fichiers objets (.o) et l'exécutable (.exe).
clean:
	rm -f $(OBJS) $(EXEC)

# Règle pour exécuter le programme avec .exe
# Cette règle compile d'abord (si nécessaire) et exécute l'exécutable.
run: $(EXEC)
	./$(EXEC)

# Cible pour compiler et exécuter
# Cette règle combine plusieurs étapes : elle nettoie les anciens fichiers, compile et exécute le programme.
# L'ordre des étapes est : clean, build, run.
all: clean build run
