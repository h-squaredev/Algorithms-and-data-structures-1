#ifndef DINAMICA_H
#define DINAMICA_H

//Feito pelo PH

#include<stdlib.h>
#include<stdio.h>

//------estrutura comum------//
typedef struct no{
    int valor;
    struct no *prox;
}no;

//------estrutura dupla------//
typedef struct noDuplo{
    int valor;
    struct noDuplo *noProx;
    struct noDuplo *noAnt;
}noDuplo;

//------prototipo das funções------//
void inserirSimples(no **lp, int valor, int posicao, int total);
void removerSimples(no *lp);

void inserirDupla(noDuplo **lp, int valor, int posicao);
void removerDupla(noDuplo *lp);



#endif 