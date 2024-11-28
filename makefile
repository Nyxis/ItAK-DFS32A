TARGET = hello_world.exe

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Iincludes

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

HEADERS = $(wildcard $(INCLUDE_DIR)/**/*.h)

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

dist-clean: clean

.PHONY: all clean dist-clean