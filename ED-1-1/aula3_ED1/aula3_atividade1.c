#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main () {
    int matriz[TAM][TAM], maiorval[TAM], linha, coluna;

    for (linha = 0; linha < TAM; linha++) {
        for (coluna = 0; coluna < TAM; coluna++) {
             printf("Digite o valor para a matriz: \t");
             scanf("%d ", &matriz[linha][coluna]);
        }
        
    }
    for (linha = 0; linha < TAM; linha++) {
        maiorval[linha] = matriz[linha][0];
        for (coluna = 0; coluna < TAM; coluna++) {
            if (matriz[linha][coluna] > maiorval[linha]) {
                maiorval[linha] = matriz[linha][coluna];
            }
        }
        printf("O maior valor da linha %d eh: %d \n", linha + 1, maiorval[linha]);
    
    }

return 1;
}