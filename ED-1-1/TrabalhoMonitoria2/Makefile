# Nome do compilador
CC = gcc

# Flags de compilação (mostra todos os avisos e permite debug)
CFLAGS = -Wall -g

# Nome do arquivo executável final
TARGET = programa

# Arquivos objeto (
OBJS = main.o dadosDeFilmes.o

# Regra principal: o que fazer quando digitar apenas 'make'
all: $(TARGET)

# Como "juntar" os pedaços para criar o programa final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Como compilar o main.c
main.o: main.c dadosDeFilmes.h
	$(CC) $(CFLAGS) -c main.c

# Como compilar as funções do dadosDeFilmes.c
dadosDeFilmes.o: dadosDeFilmes.c dadosDeFilmes.h
	$(CC) $(CFLAGS) -c dadosDeFilmes.c

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra bônus: compila e já roda o programa de uma vez
run: $(TARGET)
	./$(TARGET)