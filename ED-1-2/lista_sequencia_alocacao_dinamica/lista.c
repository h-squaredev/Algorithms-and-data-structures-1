#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "lista.h"

/* Dobra a capacidade usando realloc. Retorna 1 em sucesso, 0 em falha.
 * Em caso de falha a lista original permanece intacta (usa ponteiro
 * temporario, evitando perder o bloco antigo e causar memory leak). */
static int lista_crescer(Lista *l){
    int nova_cap;
    int *novo;

    if(l->capacidade == 0){
        nova_cap = CAPACIDADE_INICIAL;
    } else {
        if(l->capacidade > INT_MAX / 2) return 0; // evitaria overflow
        nova_cap = l->capacidade * 2;
    }

    if((size_t)nova_cap > SIZE_MAX / sizeof(int)) return 0;

    novo = realloc(l->dados, (size_t)nova_cap * sizeof(int));
    if(novo == NULL) return 0; // falha: l->dados continua valido

    l->dados = novo;
    l->capacidade = nova_cap;
    return 1;
}

void lista_inicializar(Lista *l){
    if(l == NULL) return;

    l->tamanho = 0;
    l->dados = malloc(CAPACIDADE_INICIAL * sizeof(int));

    if(l->dados == NULL){
        l->capacidade = 0; // falha de alocacao: a 1a insercao tentara de novo
    } else {
        l->capacidade = CAPACIDADE_INICIAL;
    }
}

void lista_destruir(Lista *l){
    if(l == NULL) return;

    free(l->dados);
    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;
}

int lista_inserir(Lista *l, int posicao, int valor){
    if(l == NULL) return 0;

    // A posicao deve ser entre 0 e o tamanho atual (nao deixa buracos)
    if(posicao < 0 || posicao > l->tamanho) return 0;

    // Lista cheia: aumenta a capacidade automaticamente
    if(l->tamanho == l->capacidade){
        if(!lista_crescer(l)) return 0;
    }

    // Desloca os elementos para a direita
    for(int i = l->tamanho; i > posicao; i--){
        l->dados[i] = l->dados[i - 1];
    }

    l->dados[posicao] = valor;
    l->tamanho++;

    return 1;
}

int lista_remover(Lista *l, int posicao, int *valor){
    if(l == NULL || lista_vazia(l)) return 0;

    // Posicao valida: 0 ate tamanho - 1
    if(posicao < 0 || posicao >= l->tamanho) return 0;

    if(valor != NULL) *valor = l->dados[posicao];

    // Desloca os elementos posteriores para a esquerda
    for(int i = posicao; i < l->tamanho - 1; i++){
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
    return 1;
}

int lista_buscar(const Lista *l, int valor){
    if(l == NULL) return -1;

    for(int i = 0; i < l->tamanho; i++){
        if(l->dados[i] == valor) return i;
    }
    return -1; // nao encontrado
}

void lista_imprimir(const Lista *l){
    if(l == NULL) return;

    for(int i = 0; i < l->tamanho; i++){
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int lista_vazia(const Lista *l){
    return (l == NULL || l->tamanho == 0) ? 1 : 0;
}

int lista_tamanho(const Lista *l){
    return (l == NULL) ? 0 : l->tamanho;
}

int lista_capacidade(const Lista *l){
    return (l == NULL) ? 0 : l->capacidade;
}
