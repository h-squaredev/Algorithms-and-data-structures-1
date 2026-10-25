/**
 * @file ordenacao.h
 * @author Ivairton
 * @brief Metodos de ordenacao
 * @version 0.1
 * @date 2025-11-24
 */

#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include "lista.h"

void bobbleSort(tipo_lista*);
void shellSort(tipo_lista*);
void insertSort(tipo_lista*);
void mergeSort(tipo_lista*);
void mergeSort_broken(tipo_lista*, int, int);
void mergeSort_merge(tipo_lista*, int, int);

#endif //__ORDENACAO_H__