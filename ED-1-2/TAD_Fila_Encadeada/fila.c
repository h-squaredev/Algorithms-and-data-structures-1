#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void fila_inicializar(Fila *f) {
    if (f == NULL) return;
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void fila_destruir(Fila *f) {
    if (f == NULL) return;
    No *atual = f->inicio;
    while (atual != NULL) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int fila_enfileirar(Fila *f, int valor) {
    if (f == NULL) return 0;

    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim == NULL) {          /* fila vazia: novo e inicio e fim */
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
    f->tamanho++;
    return 1;
}

int fila_desenfileirar(Fila *f, int *valor) {
    if (f == NULL || valor == NULL || f->inicio == NULL) return 0;

    No *removido = f->inicio;
    *valor = removido->valor;
    f->inicio = removido->proximo;

    if (f->inicio == NULL)         /* removeu o ultimo: fim tambem vira NULL */
        f->fim = NULL;

    free(removido);
    f->tamanho--;
    return 1;
}

int fila_frente(const Fila *f, int *valor) {
    if (f == NULL || valor == NULL || f->inicio == NULL) return 0;
    *valor = f->inicio->valor;
    return 1;
}

void fila_imprimir(const Fila *f) {
    if (f == NULL) {
        printf("Fila invalida (NULL)\n");
        return;
    }
    printf("Fila (tamanho=%d): [", f->tamanho);
    for (const No *p = f->inicio; p != NULL; p = p->proximo) {
        printf("%d", p->valor);
        if (p->proximo != NULL) printf(" -> ");
    }
    printf("]\n");
}

int fila_vazia(const Fila *f) {
    return f == NULL || f->inicio == NULL;
}

int fila_tamanho(const Fila *f) {
    return f == NULL ? 0 : f->tamanho;
}
