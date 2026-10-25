CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic

all: programa

programa: lista.c main.c
	$(CC) $(CFLAGS) lista.c main.c -o programa

clean:
	rm -f programa