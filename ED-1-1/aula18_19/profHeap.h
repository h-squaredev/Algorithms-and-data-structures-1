/**
 * UFMT - Ciencia da Computacao
 * Estrutura de Dados
 * Prof. Ivairton
 * 
 * Implementacao da estrutura Heap
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

//Definicao de constante
#define N_HEAP 50

//Definicao da estrutura do heap
struct est_heap {
    int vet_heap[N_HEAP];
    int contador;
};
typedef struct est_heap tipo_heap;

//Prototipo das funcoes
void inicializaHeap(tipo_heap*);
int indPai(int);
int indFEsq(int);
int indFDir(int);
int insereHeap(tipo_heap*, int);
int removeHeap(tipo_heap*);
void sobeHeap(tipo_heap*, int);
void desceHeap(tipo_heap*, int);
void imprimeHeap(tipo_heap*);

#endif //HEAP_H