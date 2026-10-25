#include <stdio.h>

#define TAM 8

int vetor[TAM] = { 90, 70, 50, 30, 80, 60, 40, 20 };

void shellSort(){
    int i, j, ax;
    int gap = TAM /2;

    while (gap > 0){
        for (i = gap; i < TAM; i++){
            ax = vetor[i];
            j = i;

            while (j >= gap && vetor[j - gap] > ax){
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor[j] = ax;
        }
        gap = gap / 2;
    }
}

int main(){
    int k;
    shellSort();

    printf("Vetor ordenado:\n");
    for (k = 0; k < TAM; k++){
        printf("%d ", vetor[k]);
    }
    printf("\n");

    return 0;
    
} 