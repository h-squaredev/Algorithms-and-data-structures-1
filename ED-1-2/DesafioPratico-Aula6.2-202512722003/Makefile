CC = gcc
CFLAGS = -Wall -DDEBUG

all: app

# Regra para compilar o objeto aluno.o
aluno.o: aluno.c aluno.h
	$(CC) $(CFLAGS) -c aluno.c -o aluno.o

# Regra para gerar a biblioteca estática libaluno.a
libaluno.a: aluno.o
	ar rcs libaluno.a aluno.o

# Regra para compilar a main integrando os headers (-I.) e a biblioteca (-L. e -laluno)
app: main.c libaluno.a
	$(CC) $(CFLAGS) main.c -I. -L. -laluno -o app

clean:
	rm -f *.o *.a app