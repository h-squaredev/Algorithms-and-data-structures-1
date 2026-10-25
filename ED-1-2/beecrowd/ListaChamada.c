/*
colocou N pedaços de papel (valores) numerados de 1 até N dentro de um saquinho (vetor)
e sorteu um determinado numero K

 Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem alfabética,
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação necessária para o qsort ordenar as strings
int comparacao (const void *a, const void *b){
    return strcmp((const char *)a, (const char *)b);
}

int main(){
    int N, K;
    // Matriz para armazenar até 105 nomes com até 25 caracteres cada
    char nomes[101][21];

    // Lê a quantidade de alunos (N) e o número sorteado (K)
    if (scanf("%d %d", &N, &K) != 2) return 0;

    // Lê os nomes e armazena na matriz
    for(int i = 0; i < N; i++){
        scanf("%s", nomes[i]);
    }

    // Ordena a matriz alfabeticamente
    // Parâmetros: array, número de elementos, tamanho de cada linha, função de comparação
    qsort(nomes, N, sizeof(nomes[0]), comparacao);

    // Como o índice de arrays no C começa em 0, o K-ésimo aluno está na posição K - 1
    printf("%s\n", nomes[K - 1]);

    return 0;
}
