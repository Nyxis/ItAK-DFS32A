CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include -I./src
LDFLAGS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/hello_world.exe

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OBJ_DIR)/model $(OBJ_DIR)/view $(OBJ_DIR)/controller

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean directories