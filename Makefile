CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)
TARGET = game

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)