/**
 * @file alg10.h
 * @author Ivairton
 * @brief Implementacao da estrutura LISTA
 * @version 0.1
 * @date 2025-11-05
 */

// Definição de biblioteca
#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>

// Definicao de constante
#define N 1100

// Definicao da estrutura
struct est_lista {
    int lista[N];
    int contador;
};
typedef struct est_lista tipo_lista;


// Prototipo das funcoes
int insereInicioLista(tipo_lista *, int);
int insereFimLista(tipo_lista *, int);
int inserePosLista(tipo_lista *, int, int); // 2o parametro eh o valor, 3o param eh a posicao

int removeInicioLista(tipo_lista *);
int removeFimLista(tipo_lista *);
int removePosLista(tipo_lista *);

int buscaValorLista(tipo_lista, int);
int retornaValorPosicaoLista(tipo_lista, int);
int atualizaValorPosicaoLista(tipo_lista *, int, int); // Parametros inteiros sao Valor e posicao
int quantidadeValoresLista(tipo_lista);
int listaVazia(tipo_lista);
int listaCheia(tipo_lista);
void imprimeLista(tipo_lista);

#endif