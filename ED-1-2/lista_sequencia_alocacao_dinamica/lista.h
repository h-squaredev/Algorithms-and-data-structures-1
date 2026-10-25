#ifndef LISTA_H
#define LISTA_H

/*
 * TAD Lista Sequencial com alocacao dinamica.
 *
 * Estrategia de crescimento: quando tamanho == capacidade e ha uma insercao,
 * a capacidade e DOBRADA (capacidade = capacidade * 2) com realloc().
 * Ex.: 4 -> 8 -> 16 -> 32 -> ...
 * Nao ha reducao automatica da capacidade na remocao.
 *
 * Convencao de retorno das funcoes que retornam int:
 *   lista_inserir / lista_remover: 1 = sucesso, 0 = operacao nao realizada
 *   lista_buscar: posicao (>= 0) se encontrado, -1 se nao encontrado
 *   lista_vazia: 1 = vazia, 0 = nao vazia
 */

#define CAPACIDADE_INICIAL 4

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

void lista_inicializar(Lista *l);

void lista_destruir(Lista *l);

int lista_inserir(Lista *l, int posicao, int valor);

int lista_remover(Lista *l, int posicao, int *valor);

int lista_buscar(const Lista *l, int valor);

void lista_imprimir(const Lista *l);

int lista_vazia(const Lista *l);

int lista_tamanho(const Lista *l);

int lista_capacidade(const Lista *l);

#endif
