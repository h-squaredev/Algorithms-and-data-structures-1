#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 10

typedef struct {
    int dados[CAPACIDADE];
    int tamanho;
} Lista;

void lista_inicializar(Lista *l);

int lista_inserir(Lista *l, int posicao, int valor);

int lista_remover(Lista *l, int posicao, int *valor);

int lista_buscar(const Lista *l, int valor);

void lista_imprimir(const Lista *l);

int lista_vazia(const Lista *l);

int lista_cheia(const Lista *l);

int lista_tamanho(const Lista *l);

#endif