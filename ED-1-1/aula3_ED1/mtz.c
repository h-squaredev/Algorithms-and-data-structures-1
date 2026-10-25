#include <stdio.h>

#define L 3
#define C 4

// Inicializa matriz
int main() {

    int linha, coluna;
    int mtz[L][C];

    for (linha=0; linha < L; linha++){
        for (coluna=0; coluna < C; coluna++){
            mtz[linha][coluna] = 0;

        }

    }

    // Imprime a Matriz
    for (linha=0; linha < L; linha++){
        printf("[ ");
        for (coluna=0; coluna <C; coluna++) {
            printf("%d ", mtz[linha][coluna]);
        }
          printf("]\n");
    }

    return 1;
}