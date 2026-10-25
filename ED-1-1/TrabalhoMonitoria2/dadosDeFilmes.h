#ifndef DADOSDEFILMES_H
#define DADOSDEFILMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRUTURA DE DADOS para armazenar os dados de um filme
typedef struct Filme {
    char titulo [255];
    int ano;
    char genero[100];
    char diretor[100];
    float rating;
}Filme;


//Prototipos das FUNCOES DE ARQUIVO (carregarDados)
//ler arquivo CSV e retornar um array de filmes
Filme* carregarDados(const char* nomeArquivo, int* numFilmes); //"numFilmes" eh um ponteiro que armazena total de filmes carregados


//Prototipos das FUNCOES DE ORDENACAO
void quickSort(Filme* arr, int inicio, int fim, int criterio); 
void heapSort(Filme* arr, int n, int criterio);                //criterio: 1-titulo, 2-ano, 3-genero, 4-diretor, 5-rating
void mergeSort(Filme* arr, int inicio, int fim, int criterio);


//Prototipo das FUNCOES DE INTERFACE / SAIDA
void imprimirTop10(Filme* arr);


#endif