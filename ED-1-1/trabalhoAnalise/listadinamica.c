#include<stdlib.h>
#include<stdio.h>
#include "dinamica.h"

//Feito pelo PH

//------Inserção na lista dinamica simples------//

void inserirSimples(no **lp, int valor, int posicao, int total){
    no *novo =  (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = NULL;

    if (posicao == 0){
        novo->prox = *lp;
        *lp = novo;
        return; // serve para retornar direto, como ja encontramos a posição que queriamos, não precisamos continuar na funcao
    }

    no *atual = *lp;
    int i = 0;
    while (atual->prox != NULL && i < posicao - 1){
        atual = atual->prox;
        i++;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
    
}

//------Inserção na lista dinamica dupla------//

void inserirDupla(noDuplo **lp, int valor, int posicao){
    noDuplo *novo = (noDuplo*)malloc(sizeof(noDuplo));
    novo->valor = valor;
    novo->noProx = NULL;
    novo->noAnt = NULL;

    if (posicao == 0){
        novo->noProx = *lp;
        if (*lp != NULL){
            (*lp)->noAnt = novo;

        }
    *lp = novo;
    return;
    }

    noDuplo *atual = *lp;
    int i = 0;

    while(atual->noProx != NULL && i < posicao - 1){
        atual = atual->noProx;
        i++;
    }

    novo->noProx = atual->noProx;
    novo->noAnt = atual;

    if(atual->noProx != NULL){
        atual->noProx->noAnt = novo;
    }
    atual->noProx = novo;
}

//------Remoção da lista simples------//

void removerSimples(no *lp) {
    no *atual = lp;
    while (atual != NULL) {
        no *temporario = atual;
        atual = atual->prox;
        free(temporario); 
    }
}

//------Remoção da lista Dupla------//

void removerDupla(noDuplo *lp) {
    noDuplo *atual = lp;
    while (atual != NULL) {
        noDuplo *temporario = atual;
        atual = atual->noProx;
        free(temporario);
    }
}
