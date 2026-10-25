#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

// Funcao auxiliar para criar um novo no
No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Insercao em Arvore BinAria de Busca
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

// Busca de um valor
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}

// Percurso em Pre-ordem (Raiz, Esquerda, Direita)
void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

// Percurso em Ordem / Em-ordem (Esquerda, Raiz, Direita)
void ordem(No* raiz) {
    if (raiz != NULL) {
        ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        ordem(raiz->direita);
    }
}

// Percurso em Pos-ordem (Esquerda, Direita, Raiz)
void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Calcula a altura da Arvore
int altura(No* raiz) {
    if (raiz == NULL) return -1; // -1 para que a raiz sozinha tenha altura 0

    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);

    if (alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;
}

// Funcao auxiliar para imprimir um nivel especifico
void imprimir_nivel_atual(No* raiz, int nivel) {
    if (raiz == NULL) return;
    if (nivel == 0)
        printf("%d ", raiz->valor);
    else if (nivel > 0) {
        imprimir_nivel_atual(raiz->esquerda, nivel - 1);
        imprimir_nivel_atual(raiz->direita, nivel - 1);
    }
}

// Impressao em largura (Por nivel)
void imprimir_por_nivel(No* raiz) {
    int h = altura(raiz);
    for (int i = 0; i <= h; i++) {
        imprimir_nivel_atual(raiz, i);
    }
}

// Funcao auxiliar para encontrar o menor valor de uma subArvore
No* encontrar_minimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// Remocao de um no
No* remover(No* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        // Caso 1 e 2: No sem filhos ou com 1 filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: No com 2 filhos
        No* temp = encontrar_minimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// Libera toda a memoria da Arvore
void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}