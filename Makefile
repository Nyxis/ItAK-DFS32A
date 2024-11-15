# Executable name with .exe extension
EXEC = jeu.exe

# Compiler and compilation options
# The compiler to use (gcc in this case)
CC = gcc
# The compilation options, here:
# -Wall: Enables all compiler warnings.
# -Wextra: Enables additional warnings.
# -g: Include debugging information in compiled files.
CFLAGS = -Wall -Wextra -g

# Source files
# List of source files to compile, here the .c files
SRCS = main.c carte.c jeu.c interface.c string.c

# Object files
# Transformation of the list of source files (.c) into object files (.o)
OBJS = $(SRCS:.c=.o)

# Shows available commands
help:
	@echo "Options disponibles dans le Makefile :"
	@echo "  make build   : Compile le programme et génère l'exécutable $(EXEC)"
	@echo "  make run     : Compile puis exécute le programme"
	@echo "  make clean   : Supprime les fichiers objets et l'exécutable"
	@echo "  make all     : Nettoie, compile puis exécute le programme (équivalent à build + run)"
	@echo "  make help    : Affiche cette aide"

# Target to create the executable
# This target depends on the $(EXEC) executable. It generates the executable if necessary.
build: $(EXEC)

# Rule to create the executable
# The $(EXEC) target (here game.exe) depends on the $(OBJS) object files.
# If the object files are up to date, this rule creates the executable.
# Using gcc with $(CFLAGS) options to generate the executable.
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule for compiling object files
# This rule compiles each .c source file into an .o object file.
# The target file name is defined by %.o and %.c, where % is the file name without extension.
# This is necessary because compiling the source files into objects allows them to then be linked to create the executable.
# If a source file has not been modified, it will not be recompiled, speeding up successive builds.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Cleaning rule
# This rule removes object files (.o) and executable (.exe).
clean:
	rm -f $(OBJS) $(EXEC)

# Rule to run the program with .exe
# This rule first compiles (if necessary) and runs the executable.
run: $(EXEC)
	./$(EXEC)

# Target to compile and run
# This rule combines several steps: it cleans old files, compiles and runs the program.
# The order of steps is: clean, build, run.
all: clean build run
