#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lista_inicializar(Lista *l){
    if(l == NULL) return;

    l->inicio = NULL;
    l->tamanho = 0;
}

void lista_destruir(Lista *l){
    if(l == NULL) return;

    No *atual = l->inicio;
    while(atual != NULL){
        No *prox = atual->proximo; // guarda o proximo ANTES do free
        free(atual);
        atual = prox;
    }

    l->inicio = NULL;
    l->tamanho = 0;
}

int lista_inserir(Lista *l, int posicao, int valor){
    if(l == NULL) return 0;

    // Posicao valida: 0 ate tamanho (tamanho = inserir no final)
    if(posicao < 0 || posicao > l->tamanho) return 0;

    No *novo = malloc(sizeof(No));
    if(novo == NULL) return 0; // falha de alocacao: lista permanece intacta

    novo->valor = valor;

    if(posicao == 0){
        // Insercao no inicio (tambem cobre lista vazia)
        novo->proximo = l->inicio;
        l->inicio = novo;
    } else {
        // Anda ate o no anterior a posicao desejada
        No *anterior = l->inicio;
        for(int i = 0; i < posicao - 1; i++){
            anterior = anterior->proximo;
        }
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    l->tamanho++;
    return 1;
}

int lista_remover(Lista *l, int posicao, int *valor){
    if(l == NULL || lista_vazia(l)) return 0;

    // Posicao valida: 0 ate tamanho - 1
    if(posicao < 0 || posicao >= l->tamanho) return 0;

    No *removido;

    if(posicao == 0){
        removido = l->inicio;
        l->inicio = removido->proximo;
    } else {
        No *anterior = l->inicio;
        for(int i = 0; i < posicao - 1; i++){
            anterior = anterior->proximo;
        }
        removido = anterior->proximo;
        anterior->proximo = removido->proximo;
    }

    if(valor != NULL) *valor = removido->valor;

    free(removido);
    l->tamanho--;
    return 1;
}

int lista_buscar(const Lista *l, int valor){
    if(l == NULL) return -1;

    int pos = 0;
    for(const No *atual = l->inicio; atual != NULL; atual = atual->proximo){
        if(atual->valor == valor) return pos;
        pos++;
    }
    return -1; // nao encontrado
}

void lista_imprimir(const Lista *l){
    if(l == NULL) return;

    for(const No *atual = l->inicio; atual != NULL; atual = atual->proximo){
        printf("[%d] -> ", atual->valor);
    }
    printf("NULL\n");
}

int lista_vazia(const Lista *l){
    return (l == NULL || l->inicio == NULL) ? 1 : 0;
}

int lista_tamanho(const Lista *l){
    return (l == NULL) ? 0 : l->tamanho;
}
