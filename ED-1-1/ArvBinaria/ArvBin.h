#ifndef ARVORE_H
#define ARVORE_H

// Estrutura do no da arvore binaria
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Prototipos das funcoes principais
No* inserir(No* raiz, int valor);
No* remover(No* raiz, int valor);
No* buscar(No* raiz, int valor);

// Funcoes de percurso
void pre_ordem(No* raiz);
void ordem(No* raiz);
void pos_ordem(No* raiz);

// Funcoes extras solicitadas
int altura(No* raiz);
void imprimir_por_nivel(No* raiz);

// Funcao auxiliar para liberar a memoria no final
void liberar_arvore(No* raiz);

#endif