/**
 * @file fila_enc.h
 * @author Ivairton
 * @brief Fila com encadeamento
 * @version 0.1
 * @date 2025-11-10
 * 
 */

#ifndef __FILA_ENC_H__
#define __FILE_ENC_H__

#include<stdio.h>
#include<stdlib.h>

// Definicao do noh
struct est_no_fila {
    int valor;
    struct est_no_fila *prox;
};
typedef struct est_no_fila tipo_no_fila;

// Prototipo das funcoes
int insere_fila_enc(tipo_no_fila **fila, int valor);
int remove_fila_enc(tipo_no_fila **fila);
void imprime_fila_enc(tipo_no_fila *fila);

// Fim do arquivo
#endif