.PHONY: help build clean

help:
	@echo "Options disponibles :"
	@echo "  build  - Compile l'application et la lance"
	@echo "  clean  - Supprime les fichiers compilés"

build:
	gcc -o binary main.c && ./binary

clean:
	rm -f binary
