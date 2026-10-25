#include "estatica.h"
#include<stdlib.h>
#include<stdio.h>
//Feito pelo HH

//Implementacao das funcoes da lista ESTATICA:

//Cria uma LISTA estatica vazia
void inicializaLista (ListaEstatica *lst) {
    lst->quantidade = 0;
}

//Insere um elemento no INICIO da LISTA estatica
void insereInicioEstatica (ListaEstatica *lst , int valor) {
    if (lst->quantidade >= MAX) {
        printf("[ERRO] Lista cheia! nao eh possivel inserir novo elemento.\n");
        return;
    } else {
        int i;
        for (i = lst->quantidade; i > 0; i--) {
            lst->dados[i] = lst->dados[i - 1];
        }
        lst->dados[0] = valor;
        lst->quantidade++;
    }

}

//Insere um elemento no FIM da LISTA estatica
void insereFimEstatica (ListaEstatica *lst, int valor) {
    if (lst->quantidade >= MAX) {
        printf("[ERRO] Lista cheia! nao eh possivel inserir novo elemento.\n");
        return;
    } else {
        if (lst->quantidade < MAX) {
            lst->dados[lst->quantidade++] = valor;
        }
    }
}

//INSERE um elemento em uma POSICAO especifica da LISTA
void inserePosicaoEstatica (ListaEstatica *lst, int valor, int pos){
    if (lst->quantidade >= MAX) {
        printf("[ERRO] Lista cheia! nao eh possivel inserir novo elemento.\n");
        return;
    } else {
        if ((pos >= 0) && (pos <= lst->quantidade)) {
            int i;
            for(i = lst->quantidade-1; i >= pos; i--) {
                lst->dados[i+1] = lst->dados[i];
            }
            lst->dados[i+1] = valor;
            lst->quantidade++;
        }
        
        }

}

//REMOVE um elemento do INICIO da LISTA estatica
int removeInicioEstatica (ListaEstatica *lst) {
    if (lst->quantidade == 0) {
        printf("[ERRO] Lista vazia! nao eh possivel remover elemento.\n");
        return -1; // Valor de erro
    } else {
        int valorRemovido, i;
        valorRemovido = lst->dados[0];
        //desloca os elementos para a esquerda
        for (i = 0; i < lst->quantidade - 1; i++) {
            lst->dados[i] = lst->dados[i + 1];
        }
        lst->quantidade--;
        return valorRemovido;
    }
}

//REMOVE um elemento do FIM da LISTA estatica
int removeFimEstatica (ListaEstatica *lst) {
    if (lst->quantidade == 0) {
        printf("[ERRO] Lista vazia! nao eh possivel remover elemento.\n");
        return -1; // Valor de erro
    } else {
        return lst->dados[--lst->quantidade];
    }
}

//REMOVE um elemento de uma POSICAO especifica da LISTA estatica
int removePosicaoEstatica (ListaEstatica *lst, int pos) {
    if (lst->quantidade == 0) {
        printf("[ERRO] Lista vazia! nao eh possivel remover elemento.\n");
        return -1; // Valor de erro
    } else {
        if ((pos < 0) || (pos >= lst->quantidade)) {
            printf("[ERRO] Posicao invalida! nao eh possivel remover elemento.\n");
            return -1; // Valor de erro
        } else {
            int valorRemovido, i;
            valorRemovido = lst->dados[pos];
            //desloca os elementos para a esquerda
            for (i = pos; i < lst->quantidade - 1; i++) {
                lst->dados[i] = lst->dados[i + 1];
            }
            lst->quantidade--;
            return valorRemovido;
        }
    }
}