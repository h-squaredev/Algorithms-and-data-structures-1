#include <stdio.h>
#include "ArvBin.h"

int main() {
    No* raiz = NULL;

    // Testando Insercao
    printf("Inserindo valores na arvore: 50, 30, 20, 40, 70, 60, 80\n");
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    // Testando Percursos
    printf("\nPercurso em Pre-ordem: ");
    pre_ordem(raiz);
    
    printf("\nPercurso em Ordem: ");
    ordem(raiz);
    
    printf("\nPercurso em Pos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Testando Altura e Impressao por Nivel
    printf("\nAltura da arvore: %d\n", altura(raiz));
    printf("Impressao por nivel: ");
    imprimir_por_nivel(raiz);
    printf("\n");

    // Testando Busca
    int valor_busca = 60;
    No* encontrado = buscar(raiz, valor_busca);
    if (encontrado)
        printf("\nValor %d encontrado na arvore!\n", encontrado->valor);
    else
        printf("\nValor %d NAO encontrado na arvore!\n", valor_busca);

    // Testando Remocao
    printf("\nRemovendo o valor 50 (Raiz com dois filhos)...\n");
    raiz = remover(raiz, 50);

    printf("Percurso em Ordem apos remocao: ");
    ordem(raiz);
    printf("\n");

    // Limpeza
    liberar_arvore(raiz);

    return 0;
}