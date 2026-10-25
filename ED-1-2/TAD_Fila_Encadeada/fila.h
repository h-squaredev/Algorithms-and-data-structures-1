#ifndef FILA_H
#define FILA_H

/* TAD Fila de inteiros (FIFO) com lista simplesmente encadeada. */

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;   /* primeiro elemento (proximo a ser removido) */
    No *fim;      /* ultimo elemento (onde se insere)           */
    int tamanho;  /* quantidade de elementos armazenados        */
} Fila;

/* Deixa a fila vazia e pronta para uso (inicio = fim = NULL, tamanho = 0).
 * Se f == NULL, nao faz nada. */
void fila_inicializar(Fila *f);

/* Libera todos os nos e deixa a fila vazia (reutilizavel).
 * Se f == NULL, nao faz nada. */
void fila_destruir(Fila *f);

/* Insere valor no final da fila.
 * Retorna 1 em caso de sucesso;
 *         0 se f == NULL ou se a alocacao falhar (fila inalterada). */
int fila_enfileirar(Fila *f, int valor);

/* Remove o primeiro elemento e o guarda em *valor.
 * Retorna 1 em caso de sucesso;
 *         0 se f == NULL, valor == NULL ou a fila estiver vazia
 *         (fila e *valor inalterados). */
int fila_desenfileirar(Fila *f, int *valor);

/* Consulta o primeiro elemento SEM remove-lo, guardando-o em *valor.
 * Retorna 1 em caso de sucesso;
 *         0 se f == NULL, valor == NULL ou a fila estiver vazia. */
int fila_frente(const Fila *f, int *valor);

/* Imprime os elementos na ordem FIFO (do inicio para o fim). */
void fila_imprimir(const Fila *f);

/* Retorna 1 se a fila estiver vazia (ou f == NULL); 0 caso contrario. */
int fila_vazia(const Fila *f);

/* Retorna a quantidade de elementos (0 se f == NULL). */
int fila_tamanho(const Fila *f);

#endif
