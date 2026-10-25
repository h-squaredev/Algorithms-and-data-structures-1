#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dadosDeFilmes.h"

int main() {
    int totalFilmes = 0;
    
    //carragar os dados do arquivo CSV para a memoria
    printf("Carregando base de dados...\n");
    Filme* meusFilmes = carregarDados("BaseDeDados/filmes.csv", &totalFilmes);

    // Verificacao de segurança
    if (meusFilmes == NULL) {
        printf("Falha ao iniciar o programa.\n");
        return 1;
    }

    printf("Sucesso! %d filmes carregados na memoria.\n\n", totalFilmes);

    // Variaveis para o Menu
    int opcaoCriterio = 0;
    int opcaoMetodo = 0;

    //Interface do Usuario
    printf("--- SISTEMA DE ORDENACAO DE FILMES ---\n");
    printf("Escolha o criterio de ordenacao:\n");
    printf("1. Titulo\n");
    printf("2. Ano\n");
    printf("3. Avaliacao (Rating)\n");
    printf("Sua escolha: ");
    scanf("%d", &opcaoCriterio);

    printf("\nEscolha o metodo de ordenacao:\n");
    printf("1. Quick Sort\n");
    printf("2. Heap Sort\n");
    printf("3. Merge Sort\n");
    printf("Sua escolha: ");
    scanf("%d", &opcaoMetodo);

    //Preparando o Cronometro
    clock_t inicioTempo, fimTempo;
    double tempoGasto;

    // Chamada dos Algoritmos baseada na escolha do usuario
    printf("\nIniciando ordenacao...\n");
    inicioTempo = clock(); // Dispara o cronometro

    switch (opcaoMetodo) {
        case 1:
            // Quick Sort: usa (inicio, fim)
            quickSort(meusFilmes, 0, totalFilmes - 1, opcaoCriterio);
            break;
        case 2:
            // Heap Sort: usa (tamanho total n)
            heapSort(meusFilmes, totalFilmes, opcaoCriterio);
            break;
        case 3:
            // Merge Sort: usa (inicio, fim)
            mergeSort(meusFilmes, 0, totalFilmes - 1, opcaoCriterio);
            break;
        default:
            printf("Opcao de metodo invalida!\n");
            free(meusFilmes);
            return 1;
    }


    fimTempo = clock(); // Para o cronometro
    tempoGasto = ((double) (fimTempo - inicioTempo)) / CLOCKS_PER_SEC;

    // 5. Exibição dos Resultados
    printf("Ordenacao concluida em %f segundos.\n\n", tempoGasto);
    
    printf("--- TOP 10 FILMES ---\n");
    imprimirTop10(meusFilmes);

    // Limpeza de Memoria
    free(meusFilmes);

    return 0;
}