// Cabeçalho para lista estática
#ifndef ESTATICA_H
#define ESTATICA_H

//Feito pelo HH

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int dados[MAX];
    int quantidade;
} ListaEstatica;

// Prototipos das funcoes
void inicializaLista (ListaEstatica *lst);
void insereInicioEstatica (ListaEstatica *lst, int valor);
void insereFimEstatica (ListaEstatica *lst, int valor);
void inserePosicaoEstatica (ListaEstatica *lst, int valor, int pos);
int removeInicioEstatica (ListaEstatica *lst);
int removeFimEstatica (ListaEstatica *lst);
int removePosicaoEstatica (ListaEstatica *lst, int pos);

#endif