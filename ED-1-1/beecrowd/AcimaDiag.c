#include <stdio.h>

int main() {
    char tipo;
    // Declaração da matriz 12x12
    double M[12][12];
    double soma = 0.0;
    int i, j;
    // Variável para contar quantos elementos estão acima da diagonal.
    // O total é sempre 66 (144 elementos - 12 na diagonal) / 2 = 66.
    const int num_elementos = 66; 

    // 1. Ler o caractere de operação ('S' ou 'M')
    // É recomendado usar " %c" para ignorar espaços em branco e novas linhas antes do char.
    if (scanf(" %c", &tipo) != 1) return 1;

    // 2. Loop principal para ler e calcular a soma
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            // Ler o elemento da matriz
            if (scanf("%lf", &M[i][j]) != 1) return 1;

            // Condição: Se a COLUNA (j) é MAIOR que a LINHA (i), 
            // o elemento está acima da diagonal principal.
            if (j > i) {
                soma += M[i][j];
            }
        }
    }

    // 3. Imprimir o resultado
    if (tipo == 'S') {
        // Se for Soma ('S')
        printf("%.1lf\n", soma);
    } else if (tipo == 'M') {
        // Se for Média ('M')
        double media = soma / num_elementos;
        printf("%.1lf\n", media);
    }

    return 0;
}