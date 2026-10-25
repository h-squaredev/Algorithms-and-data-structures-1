CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: ArvBin_app

ArvBin_app: main.o ArvBin.o
	$(CC) $(CFLAGS) -o ArvBin_app main.o ArvBin.o

main.o: main.c ArvBin.h
	$(CC) $(CFLAGS) -c main.c

arvore.o: ArvBin.c ArvBin.h
	$(CC) $(CFLAGS) -c ArvBin.c

clean:
	rm -f *.o ArvBin_app