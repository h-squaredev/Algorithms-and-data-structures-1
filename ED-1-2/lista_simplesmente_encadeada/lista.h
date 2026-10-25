#ifndef LISTA_H
#define LISTA_H

/*
 * TAD Lista Simplesmente Encadeada de inteiros.
 *
 * Cada elemento fica em um no alocado com malloc(); o encadeamento e feito
 * por ponteiros. Nao ha capacidade maxima nem uso de vetores/realloc.
 * Posicoes comecam em 0.
 *
 * Convencao de retorno das funcoes que retornam int:
 *   lista_inserir / lista_remover:
 *       1 = sucesso
 *       0 = erro (posicao invalida, lista vazia, ponteiro NULL ou falha de malloc)
 *   lista_buscar:
 *       posicao (>= 0) se encontrado, -1 se nao encontrado
 *   lista_vazia:
 *       1 = vazia, 0 = nao vazia
 *   lista_tamanho:
 *       quantidade de elementos
 */

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

void lista_inicializar(Lista *l);
void lista_destruir(Lista *l);

int lista_inserir(Lista *l, int posicao, int valor);
int lista_remover(Lista *l, int posicao, int *valor);

int lista_buscar(const Lista *l, int valor);

void lista_imprimir(const Lista *l);

int lista_vazia(const Lista *l);
int lista_tamanho(const Lista *l);

#endif
